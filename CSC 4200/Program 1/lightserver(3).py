
import socket, sys, argparse, struct

serverParser = argparse.ArgumentParser(description='Port and Logfile')
serverParser.add_argument('-p','--port',required=True,help='Port Number',type=int)
serverParser.add_argument('-l','--log',required=True,help='Logfile location')

info = serverParser.parse_args()
logfile = open(info.log, "a")

ver = 17
msg_type = 0
msg_len = 0
header_unp = struct.Struct('i i i')
message_unp = struct.Struct('8s')

#CREATING SOCKET
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#BINDING
server_address_object = (socket.gethostname(), info.port)
print("Address = ", server_address_object)
sock.bind(server_address_object)

#LISTENING
sock.listen(1)

#CONNECTING

print("Waiting to hear from a client.....")
conn_obj, client_address = sock.accept()

print("Yay! Heard from a client, address is:", client_address)
logfile.write("Received connection from <" + str(client_address) + "> ")

while True:
    try:
        #RECEIVING PACKET HEADER

        packet_header = conn_obj.recv(header_unp.size)
        version, msg_type, msg_len = struct.unpack('i i i', packet_header)
        print("Received packet header! ", packet_header.decode())

        #RECEIVING MESSAGE FROM CLIENT

        mess_1_pack = conn_obj.recv(message_unp.size)

        print("Received new Message from client!")
        mess_1 = struct.unpack(str(msg_len)+'s', mess_1_pack)
        print("Version: ", version)
        print("Message Type: ", msg_type)
        print("Message Length: ", msg_len)
        print("Message: ", mess_1_pack.decode())
            
        #CHECKING VERSION

        if version == ver:
            msg = b'VERSION MATCH!'
            conn_obj.sendall(msg)

            #CHECKING MESSAGE TYPE

            if msg_type == 1:

                #LIGHTON
                
                new_msg_on = b'SUCCESS'
                logfile.write("EXECUTING SUPPORTED COMMAND: LIGHTON")
                conn_obj.sendall(new_msg_on)
                continue

            elif msg_type == 2:

                #LIGHTOFF

                new_msg_off = b'SUCCESS'
                logfile.write("EXECUTING SUPPORTED COMMAND: LIGHTOFF")
                conn_obj.sendall(new_msg_off)
                print("Closing Socket.")
                logfile.close()
                sock.close()
                break

            else:
                print("UNSUPPORTED COMMAND")
                logfile.write("UNSUPPORTED COMMAND")
                continue

    
        else:
            msg = b'VERSION MISMATCH!'
            conn_obj.sendall(msg)
            logfile.write("ERROR: INCORRECT VERSION!")
            continue


    except KeyboardInterrupt:
        logfile.close()
        sock.close()
