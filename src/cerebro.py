#ejecutar source robot_env/bin/activate para probar el robot

import socket
import time
import numpy as np
from brainflow.board_shim import BoardShim, BrainFlowInputParams, BoardIds

#CONFIGURACIÓN DE RED
ESP32_IP = "192.168.1.81"  #IP del robot
UDP_PORT = 4242
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# CONFIGURACIÓN DEL SENSOR 
params = BrainFlowInputParams()
board_id = BoardIds.SYNTHETIC_BOARD
board = BoardShim(board_id, params)

try:
    board.prepare_session()
    board.start_stream()
    print(f"Conectado al cerebro. Transmitiendo a {ESP32_IP}:{UDP_PORT}...")

    while True:
        time.sleep(2) 
        
        data = board.get_current_board_data(256)
        estado_mental = np.random.choice([0, 1, 2])
        
        mensaje = str(estado_mental).encode('utf-8')
        sock.sendto(mensaje, (ESP32_IP, UDP_PORT))
        
        print(f"Señal enviada al robot: {estado_mental}")
        
except KeyboardInterrupt:
    print("\nDesconectando red neuronal...")
finally:
    board.stop_stream()
    board.release_session()