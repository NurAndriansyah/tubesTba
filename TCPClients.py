import socket

#Server address dan port dari server
serverHost = '127.0.0.1'
serverPort = 8080

#Membuat socket TCP
clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#Melakukan koneksi ke server
clientSocket.connect((serverHost, serverPort))

#Menentukan nama file
filename = 'index.html'
#Menyiapkan HTTP request message
request = f"GET /{filename} HTTP/1.1\r\nHost: {serverHost}:{serverPort}\r\n\r\n"
#Mengirim request message ke server
clientSocket.send(request.encode())

#Menampilkan response dari server
response = clientSocket.recv(4096)
print(response.decode())

clientSocket.close()
