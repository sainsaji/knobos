import socket

# Set up server socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_host = '0.0.0.0'  # Listen on the ESP32's IP address
server_port = 8080             # Choose any available port
server_socket.bind((server_host, server_port))
server_socket.listen(1)

print(f"Server listening on {server_host}:{server_port}")
import ctypes

def lock_windows():
    ctypes.windll.user32.LockWorkStation()

while True:
    # Accept incoming connection
    client_socket, client_address = server_socket.accept()
    print(f"Connection from {client_address}")

    # Receive data from client
    data = client_socket.recv(1024).decode('utf-8')
    if data:
        print(f"Received data: {data}")
    if data=="Lock":
        lock_windows()


    # Close connection with client
    client_socket.close()
