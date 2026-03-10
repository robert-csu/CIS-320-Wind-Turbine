import serial
import firebase_admin
from firebase_admin import credentials, db
import datetime

cred = credentials.Certificate("serviceAccountKey.json")
firebase_admin.initialize_app(cred, {"databaseURL": "https://windturbine-111c8-default-rtdb.firebaseio.com/"})

latest_ref = db.reference("WindTurbine/latest")
history_ref = db.reference("WindTurbine/history")

arduino = serial.Serial('/dev/ttyACM0', 9600)

while True:
    if arduino.in_waiting > 0:
        line = arduino.readline().decode('utf-8', errors='ignore').strip()
        if line and len(line) > 0:
            try:
                ldr = float(line)
                latest_ref.set({"LDR": ldr, "timeStamp": str(datetime.datetime.now())})
                history_ref.push({"LDR": ldr, "timeStamp": str(datetime.datetime.now())})
                print(f"Sent to Firebase: LDR={ldr}")
            except ValueError:
                continue