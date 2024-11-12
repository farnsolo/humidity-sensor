import socket

host = "172.28.91.42"
port = 8080

# Wont close socket
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
    sock.bind((host, port))
    sock.listen(5)
    
    while True:
        conn, addr = sock.accept()
        print(str(addr))