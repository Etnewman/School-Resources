import argparse
import socket
import struct
import threading
import sys


parser = argparse.ArgumentParser(description='Host Server')
parser.add_argument('-p', type=int, required=True, help='Port')
parser.add_argument('-l', type=str, required=True, help='logFile')
args = parser.parse_args()

log_file = open(args.l, 'a')






def connHandler(conn, addr):
    count = 0
    notDone = True
    #conn, addr = socket.accept()
    print("Connected to (IP, PORT): ", addr, PORT)
    log_file.write("Connected to (IP, PORT): " + str(addr) + str(PORT) + "\n")
    #add logfile
    #while notDone:
    recvData = conn.recv(struct.calcsize('>III'))

    v, t, l= struct.unpack('>III', recvData)

    print("Received Data: Version: ", v, "Type: ", t, "Length: ", l)
    log_file.write("Received Data: Version: " + str(v) + " Type: " + str(t) + " Length: " + str(l) + "\n")

    recvData = conn.recv(l)
    recvMsg = recvData.decode()

    if v != 17:
        print("Version Mismatch")
        log_file.write("Version Mismatch\n")
    else:
        print("Version Accepted")
        log_file.write("Version Accepted\n")
        if t == 0:
            print("Message Recieved: ", recvMsg)
            log_file.write("Message Received: " + str(recvMsg) + "\n")
            msg = "HELLO"
            data = struct.pack('>III', 17, 0, len(msg)) + msg.encode()
            print("Sending HELLO packet")
            log_file.write("Sending HELLO packet\n")
            conn.sendall(data) 


    while count < 2:

        recvData = conn.recv(struct.calcsize('>III'))
        v, t, l = struct.unpack('>III', recvData)
        print("Received Data: Version: ", v,"Type: ", t,"Length: ", l)
        log_file.write("Received Data: Version: " + str(v) + " Type: " + str(t) + " Length: " + str(l) + "\n")
        recvData = conn.recv(l)
        recvMsg = recvData.decode()
        if v != 17:
            print("Version Mismatch")
            log_file.write("Version Mismatch\n")
            count = 2
        else:
            print("Version Accepted")
            log_file.write("Version Accepted\n")
            if t == 1:
                msg = "SUCCESS"
                data = struct.pack('>III', 17, 1, len(msg)) + msg.encode()
                conn.sendall(data)
                print("Executing Supported Command: ", recvMsg)
                log_file.write("Executing Supported Command: " + str(recvMsg) + "\n")
                count = count + 1
            elif t == 2:
                msg = "SUCCESS"
                data = struct.pack('>III', 17, 2, len(msg)) + msg.encode()
                conn.sendall(data)
                print("Executing Supported Command: ", recvMsg)
                log_file.write("Executing Supported Command: " + str(recvMsg) + "\n")
                count = count + 1
            else:
                print("Unsupported Command")
                log_file.write("Unsupported Command\n")
                continue

    recvData = conn.recv(struct.calcsize('>III'))
    v, t, l = struct.unpack('>III', recvData)
    recvData = conn.recv(l)
    recvMsg = recvData.decode()

    if recvMsg == "DISCONNECT":
        conn.close()

if __name__ == '__main__':
    count = 0
    notDone = True
    conn = True
    print("Hello")
    IP_ADDR = 'localhost'
    PORT = args.p
    SERVER_ADDR = (IP_ADDR, PORT)
    v = 0
    t = 0
    l = 0

    socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    socket.bind(SERVER_ADDR)
    socket.listen(1)
    print("Listening for connection on: {}".format(SERVER_ADDR))
    log_file.write("Listening for connection on: {}".format(SERVER_ADDR) + "\n")

    while conn == True:
        connection, address = socket.accept()
        thread = threading.Thread(target=connHandler, args=(connection, address))
        thread.start()



        #sys.exit()
        #conn == False
   
        



