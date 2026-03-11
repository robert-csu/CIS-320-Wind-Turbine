import serial
import firebase_admin
from firebase_admin import credentials, db
import datetime
import time

cred = credentials.Certificate("serviceAccountKey.json")
firebase_admin.initialize_app(cred, {"databaseURL": "https://windturbine-111c8-default-rtdb.firebaseio.com/"})

latest_ref = db.reference("WindTurbine/latest")
history_ref = db.reference("WindTurbine/history")

arduino = serial.Serial('/dev/ttyACM0', 9600)

last_latest_write  = 0
last_history_write = 0

while True:
    if arduino.in_waiting > 0:
        line = arduino.readline().decode('utf-8', errors='ignore').strip()
        if line and len(line) > 0:
            try:
                ldr = float(line)
                now = time.time()
                timestamp = str(datetime.datetime.now())

                if now - last_latest_write >= 1:
                    last_latest_write = now
                    latest_ref.set({"LDR": ldr, "timeStamp": timestamp})
                    print(f"Latest updated: LDR={ldr}")

                if now - last_history_write >= 60:
                    last_history_write = now
                    history_ref.push({"LDR": ldr, "timeStamp": timestamp})
                    print(f"History saved: LDR={ldr}")

            except ValueError:
                continue