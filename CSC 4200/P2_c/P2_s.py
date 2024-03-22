import binascii
import socket
import struct
import sys
import argparse, time

#how tcp works, send a packet & OS handles this stuff
#difference btwn UDP & TCP: UDP no guarantee packet will make it to other side
#UDP doesn't give any info about the packet - i.e. send a word one letter at a time assume rcvr gets it in order
#networks are unreliable, packets can drop, or arrive out of order...
#UDP isn't extra, but TCP has flags because its a reliable protocol - rcvd in order

def create_packet(sequence_number, ack_number, ack, syn, fin, m_s): #pass multiple arguments to a function that are named, name of arg becomes key in dictionary
	padding = ('s'*29).encode("utf-8") #create an array of x that is 29 long, 28 bytes of nothing..struct wants seq of bytes not string
	data = struct.pack('!I', sequence_number) #pack the version
	data += struct.pack('!I', ack_number) #pack the version
	data += struct.pack('!{0}s'.format(len(padding)), padding) #pack the version
	data += struct.pack("!c", ack.encode()) #pack the length of string
	data += struct.pack("!c", syn.encode()) #pack the length of string
	data += struct.pack("!c", fin.encode()) #pack the length of string
	#data += struct.pack("{0}s".format(len(data)),data)
	data += m_s #pack the data already in bytes
	return data

def arg_parse_server():
	serverParser = argparse.ArgumentParser(description='Server IP, Port and Logfile')
	serverParser.add_argument('-p','--port',required=True,help='Port Number',type=int)
	serverParser.add_argument('-l','--log',required=True,help='Logfile Location')
	serverParser.add_argument('-w','--web',required=True,help='Webpage domain')

	info = serverParser.parse_args()
	return info


def run_command(command):
	return 0

class packet(object): #every method in class takes the self arg which is an instance of the class
	def __init__ (self, data):
		#pass in packet data, data[0:4] only get first 4 bytes
		self.sequence_number = struct.unpack('!I', data[0:4])[0] #pull stuff into the packet to pull it out, index 0th element - pulls first thing out of the list
		self.ack_number = struct.unpack('!I', data[4:8])[0] #need byte 4-8 to move thru data
		#29 bytes of useless padding
		#ack flag is 8+29 = 37th byte
		#or self.ack, self.syn, self.fin = struct.unpack("!ccc", data[37:40])
		self.ack = struct.unpack("!c", data[37:38])[0] #ack is 1 byte
		self.syn = struct.unpack("!c", data[38:39])[0]
		self.fin = struct.unpack("!c", data[39:40])[0] #after 40th byte is the real data
		self.data = data[40:]

	def __str__ (self):
		return "sequence_number = {}, ack_number = {}, ack = {}, syn = {}, fin = {}".format(self.sequence_number, self.ack_number, self.ack, self.syn, self.fin)

#three-way handshake for server
def threeWayHandshake(sock):
	data, addr = sock.recvfrom(len(create_packet(sequence_number=0, ack_number=0, ack = 'Y', syn = 'N', fin = 'N', m_s = "".encode()))) #use anytime rcvd data without a packet
	syn_packet = packet(data)
	if syn_packet.sequence_number != 12345:
		#syn_packet is the object containing the syn_number
		raise Exception("Seq Num was wrong: {}".format(syn_packet)) #abort program if wrong num
	if syn_packet.ack_number != 0:
		raise Exception("Ack Num was wrong: {}".format(syn_packet))
		#check the flags
	if syn_packet.ack != b'N':
		raise Exception("Ack flag was wrong: {}".format(syn_packet))
	if syn_packet.syn != b'Y':
		raise Exception("Syn flag was wrong: {}".format(syn_packet))
	if syn_packet.fin != b'N':
		raise Exception("Fin flag was wrong: {}".format(syn_packet))

	print(syn_packet) #print the first connection server to client
	ack_packet = create_packet(sequence_number=100, ack_number=12346, ack = 'Y', syn = 'Y', fin = 'N', m_s = "".encode())
	sock.sendto(ack_packet,addr) #send packet to client with addr it rcvs packet from
	print(packet(ack_packet))

	data, addr = sock.recvfrom(len(create_packet(sequence_number=0, ack_number=0, ack = 'Y', syn = 'N', fin = 'N', m_s = "".encode())))
	client_ack_packet = packet(data) #convert to bytes to check seq number
	if client_ack_packet.sequence_number != 12346:
		#syn_packet is the object containing the syn_number
		raise Exception("Seq Num was wrong: {}".format(client_ack_packet)) #abort program if wrong num
	if client_ack_packet.ack_number != 101:
		raise Exception("Ack Num was wrong: {}".format(client_ack_packet))
		#check the flags
	if client_ack_packet.ack != b'Y':
		raise Exception("Ack flag was wrong: {}".format(client_ack_packet))
	if client_ack_packet.syn != b'N':
		raise Exception("Syn flag was wrong: {}".format(client_ack_packet))
	if client_ack_packet.fin != b'N':
		raise Exception("Fin flag was wrong: {}".format(client_ack_packet))

	print(client_ack_packet)
	print ("Done with 3-Way-Handshake")

	return 101, client_ack_packet.sequence_number

if __name__=='__main__': #built-in variable indicating the name of the file & how its being run
#run py as a script or a module/ import another file for the code
#if to check if py is being run as a script - tells python its being run as a command
#tells its not being imported as a module line 21-47 is run
	#create a TCP/IP socket
	info = arg_parse_server() #info.port, info.log, info.web
	logfile = open(info.log, "a")
	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	#sock.bind(('localhost', 30001))
	sock.bind(("", info.port))
	#sock.listen(5) #backlog
	recv_buf = []
	FIN_SET = 0
	#test = packet(create_packet(sequence_number=12, ack_number=5, ack = 'Y', syn = 'N', fin = 'N', m_s = "".encode()))
	#print(test)
	#port = int(input("Enter port num: "))
	#if 1 >= port >= 65535:
	#	print ("Invalid Port")

	sequence_number, ack_number = threeWayHandshake(sock)

	#print("Ack num: ", ack_number) debug line

	with open('recv_file', 'wb') as w:
		while True:
		#UDP Connectionless protocol: everytime a packet is sent its unrelated to anything else
		#TCP Every packet sent btwn known to be part of connection
		#UDP server rcvs 4 packets & client 1, connection 1 diff client for his connection, 3rd back to client 1, 4th random client
		#How to make sure packets are related: inspect UDP addr on 45
			data, address = sock.recvfrom(1024) #create a packet with nothing in it
			print("Received connection from (IP, PORT): ", address)

			#check if fin is true so we break out of loop
			data_packet = packet(data) #change to byte
			if data_packet.fin == b'Y':
				break #out of loop send fin|ack later...


			if data_packet.sequence_number != ack_number:
				raise Exception("Wrong number: {} expected {}".format(data_packet, ack_number))
			#updata ack number
			string = data_packet.__str__()
			logfile.write("RECV: " + string + "\n")
			ack_number = ack_number + len(data_packet.data) #update ack by however much data client sent

			#create a reply packet
			ack_packet = create_packet(sequence_number=sequence_number, ack_number=ack_number, ack = 'Y', syn = 'N', fin = 'N', m_s = "".encode())
			sock.sendto(ack_packet, address) #send to client
			sequence_number = sequence_number + 1
			first = packet(ack_packet)
			string = first.__str__()
			logfile.write("SEND: " + string + "\n")
			print(first)
			#first = packet(data) #creates packet object frm above class
			#print(first)
			#3-way handshake: client sends mssg, server sends mssg back, client ack connection


			try:
				w.write(data_packet.data)
				print('Writing data')
			except socket.timeout:
				sock.close()
				print("File downloaded")
			#if FIN_SET:
			#	break
