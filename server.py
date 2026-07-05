import paho.mqtt.client as mqtt
import pandas as pd
import os
from datetime import datetime

BROKER = "broker.hivemq.com"
TOPIC = "Registernumber"

CSV_FILE = "sensor_data.csv"

# إنشاء الملف إذا لم يكن موجودًا
if not os.path.exists(CSV_FILE):
    pd.DataFrame(columns=[
        "Time",
        "Temperature",
        "Humidity",
        "Gas",
        "Motion",
        "Light",
        "Distance"
    ]).to_csv(CSV_FILE, index=False)

def on_connect(client, userdata, flags, rc):
    print("MQTT Connected:", rc)
    client.subscribe(TOPIC)
    print("Subscribed to:", TOPIC)

def on_message(client, userdata, msg):
    try:
        data = msg.payload.decode()
        print("Received:", data)

        values = data.split(",")

        if len(values) != 6:
            print("Invalid Data")
            return

        row = {
            "Time": datetime.now().strftime("%Y-%m-%d %H:%M:%S"),
            "Temperature": float(values[0]),
            "Humidity": float(values[1]),
            "Gas": int(values[2]),
            "Motion": int(values[3]),
            "Light": int(values[4]),
            "Distance": float(values[5]),
        }

        pd.DataFrame([row]).to_csv(
            CSV_FILE,
            mode="a",
            header=False,
            index=False
        )

        print("Saved ✔")

    except Exception as e:
        print(e)

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect(BROKER,1883,60)

print("Waiting for data...")

client.loop_forever()