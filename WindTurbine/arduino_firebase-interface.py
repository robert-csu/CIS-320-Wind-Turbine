import serial
import firebase_admin
from firebase_admin import credentials, db
import datetime

import time;

cred = credentials.Certificate("serviceAccountKey.json")
firebase_admin.initialize_app(cred, {"databaseURL": "https://windturbine-111c8-default-rtdb.firebaseio.com/"})
ref = db.reference("WindTurbine/latest")
ref_history = db.reference("WindTurbine/history")

arduino = serial.Serial('/dev/ttyUSB0', 9600)


while True:
    line = arduino.readline().decode().strip()
    ldr = str(line)
    for i in range(1, 1024):
        ldr = (i)
        ref.set({"ldr": ldr, "timeStamp": str(datetime.datetime.now())})
        ref_history.push({"ldr": ldr, "timestamp": str(datetime.datetime.now())})
        time.sleep(0.5)
