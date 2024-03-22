
import socket, sys, argparse, struct, time

serverParser = argparse.ArgumentParser(description='Server IP, Port and Logfile')
serverParser.add_argument('-s','--sit',required=True,help='Server IP')
serverParser.add_argument('-p','--port',required=True,help='Port Number',type=int)
serverParser.add_argument('-l','--log',required=True,help='Logfile location')

info = serverParser.parse_args()
logfile = open(info.log, "a")

header_struct = struct.pack('i i i', 17, 0, 5)
msg_struct = struct.pack('5s',"Hello".encode())
command_on_header = struct.pack('i i i', 17, 1, 7)
command_off_header = struct.pack('i i i', 17, 2, 8)
command_on_msg = struct.pack('7s', "LIGHTON".encode())
command_off_msg = struct.pack('8s', "LIGHTOFF".encode())

#CREATING SOCKET OBJECT

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#CONNECTING

server_address = (info.sit, info.port)
print("Connecting to...", server_address)
sock.connect(server_address)

print("Yay! connected to...", server_address)

try:

    #SENDING PACKET HEADER

    sock.sendall(header_struct)
    print("Sent Packet Header!")

    #SENDING MESSAGE TO SERVER

    sock.sendall(msg_struct)
    print("Sent Message!")

    ver_reply = sock.recv(1024)
    ver_reply = ver_reply.decode()
    print(ver_reply)

    #CHECKING IF VERSION IS CORRECT
    
    if ver_reply == 'VERSION MATCH!':

        #SENDING COMMAND PACKET
        
        sock.sendall(command_on_header)
        sock.sendall(command_on_msg)

        #RECEIVING AND LOGGING FEEDBACK
    
        command_on_reply = sock.recv(1024)
        print(command_on_reply.decode())
        logfile.write(command_on_reply.decode())

        #SENDING COMMAND PACKET

        sock.sendall(command_off_header)
        sock.sendall(command_off_msg)

        #RECEIVING AND LOGGING FEEDBACK

        command_off_reply = sock.recv(1024)
        print(command_off_reply.decode())
        logfile.write(command_off_reply.decode())

        #CLOSING SOCKET
        
        print("Closing Socket.")
        sock.close()

        
    else:
        logfile.write(ver_reply)


except KeyboardInterrupt:
    logfile.close()
    sock.close()
