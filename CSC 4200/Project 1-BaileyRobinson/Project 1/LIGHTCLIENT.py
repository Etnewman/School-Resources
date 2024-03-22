import socket
import struct
import argparse

parser = argparse.ArgumentParser(description='Client')
parser.add_argument('-s', type=str, required=True, help='Server IP')
parser.add_argument('-p', type=int, required=True, help="Port")
parser.add_argument('-l', type=str, required=True, help="log file")
args = parser.parse_args()

log = open(args.l, 'a')

v, t, l = 0, 0, 0
socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

IP_ADDR = args.s
PORT = args.p
SERVER_ADDR = (IP_ADDR, PORT)

socket.connect(SERVER_ADDR)
print("Connected to server on {}".format(SERVER_ADDR))
log.write("Connected to server on {}".format(SERVER_ADDR) + "\n")

msg = "HELLO"
data = struct.pack('>III', 17, 0, len(msg)) + msg.encode()
print("Sending Hello")
log.write("Sending Hello\n")
socket.sendall(data)

recvData = socket.recv(struct.calcsize('>III'))
v, t, l = struct.unpack('>III', recvData)
print("Received Data: Version: Version: ", v, "Type: ", t, "Length: ", l)
log.write("Received Data: Version: " + str(v) + " Type: " + str(t) + " Length: " + str(l) + "\n")
recvData = socket.recv(l)
recvMsg = recvData.decode()
print("Message Received: ", recvMsg)
log.write("Message Recieved: " + str(recvMsg) + "\n")

print("Sending Command")
log.write("Sending Command\n")
msg = "LIGHTON"
data = struct.pack('>III', 17, 1, len(msg)) + msg.encode()
socket.sendall(data)

recvData = socket.recv(struct.calcsize('>III'))
v, t, l = struct.unpack('>III', recvData)
recvData = socket.recv(l)
recvMsg = recvData.decode()
print("Received Data: Version: ", v, "Type: ", t, "Length: ", l)
log.write("Received Data: Version: " + str(v) + " Type: " + str(t) + " Length: " + str(l) + "\n")
print("Message Received: ", recvMsg)
log.write("Message Recieved: " + str(recvMsg) + "\n") 

print("Sending Command")
log.write("Sending Command\n")
msg = "LIGHTOFF"
data = struct.pack('>III', 17, 2, len(msg)) + msg.encode()
socket.sendall(data)

recvData = socket.recv(struct.calcsize('>III'))
v, t, l = struct.unpack('>III', recvData)
recvData = socket.recv(l)
recvMsg = recvData.decode()
print("Received Data: Version: ", v, "Type: ", t, "Length: ", l)
log.write("Received Data: Version: " + str(v) + " Type: " + str(t) + " Length: " + str(l) + "\n")
print("Message Received: ", recvMsg)
log.write("Message Recieved: " + str(recvMsg) + "\n") 

msg = "DISCONNECT"
data = struct.pack('>III', 17, 3, len(msg)) + msg.encode()
socket.sendall(data)
print("Closing socket")
log.write("Closing Socket\n")
socket.close()



