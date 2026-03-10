import serial
import firebase_admin
from firebase_admin import credentials, db
import datetime

cred = credentials.Certificate("serviceAccountKey.json")
firebase_admin.initialize_app(cred, {"databaseURL": "https://windturbine-111c8-default-rtdb.firebaseio.com/"})
ref = db.reference("WindTurbine/latest")

arduino = serial.Serial('/dev/ttyACM0', 9600)


while True:
    line = arduino.readline().decode().strip()
    ldr = str(line)
    ref.set({"LDR": ldr, "timeStamp": str(datetime.datetime.now())})