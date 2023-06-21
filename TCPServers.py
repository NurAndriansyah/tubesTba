import socket
import sys # In order to terminate the program

#Membuat socket TCP
serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#Server address dan port
serverHost = '127.0.0.1'
serverPort = 8080
#Mengikat socket ke alamat dan port tertentu
serverSocket.bind((serverHost, serverPort))
#Menerima koneksi dari client
serverSocket.listen(1)
print(f"Server berjalan di {serverHost}:{serverPort}")

while True:
    #Menerima koneksi dari client
    connectionSocket, addr = serverSocket.accept()
    try:
        #Menerima message dari client
        message = connectionSocket.recv(1024).decode() 
        filename = message.split()[1] #mengambil path file yang diminta client
        f = open(filename[1:]) #membuka file
        outputdata = f.read() #membaca file 
        f.close() #menutup file
        
        #Mengirim HTTP header ke socket
        response = "HTTP/1.1 200 OK\r\n"
        response += "Content-Type: text/html\r\n"
        response += "\r\n"
        response += outputdata 
        
        #Mengirim response message ke client      
        connectionSocket.sendall(response.encode())
        connectionSocket.close()
        print(f"Koneksi diterima dari {addr}")
    
    except IOError:
        #Membuat response message jika file tidak sesuai
        response = "HTTP/1.1 404 Not Found\r\n\r\n"
        response += "<html><head></head><body><h1>404 Not Found</h1></body></html>\r\n"
        
        #Mengirim response message ke client
        connectionSocket.sendall(response.encode())
        connectionSocket.close()
        print(f"File '{filename[1:]}' tidak ditemukan")
       
serverSocket.close()
sys.exit() #Terminate the program after sending the corresponding data