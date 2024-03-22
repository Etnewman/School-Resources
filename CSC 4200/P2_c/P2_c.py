import binascii
import socket
import struct
import sys
import urllib.request
#import server code to client to reuse create packet
import argparse, time


# Create a TCP/IP socket
def create_packet_client(sequence_number, ack_number, ack, syn, fin, m_s): #pass multiple arguments to a function that are named, name of arg becomes key in dictionary
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

def arg_parse():
	serverParser = argparse.ArgumentParser(description='Server IP, Port and Logfile')
	serverParser.add_argument('-s','--sit',required=True,help='Server IP')
	serverParser.add_argument('-p','--port',required=True,help='Port Number',type=int)
	serverParser.add_argument('-l','--log',required=True,help='Logfile Location')

	info = serverParser.parse_args()
	return info

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

def get_webpage(page):
	with urllib.request.urlopen(page) as response, open("test", 'w') as w:
	   html = response.read()
	   w.write(html.decode())
	return html

def threeWayHandshake(socket, server_address):
	syn_packet = create_packet_client(sequence_number=12345, ack_number=0, ack = 'N', syn = 'Y', fin = 'N', m_s = b"")#empty byte string
	socket.sendto(syn_packet, server_address)
	print(packet(syn_packet))
	#wait for server to send acknowledgement of syn packet
	data, address = socket.recvfrom(len(create_packet_client(sequence_number=0, ack_number=0, ack = 'Y', syn = 'N', fin = 'N', m_s = "".encode())))
	ack_packet = packet(data) #convert data rcvd from server into packet then check flags
	if ack_packet.ack_number != 12346:
		#ack_packet is the object containing the ack_number
		raise Exception("Ack Num was wrong: {}".format(ack_packet)) #abort program if wrong num
	#check the flags
	if ack_packet.ack != b'Y':
		raise Exception("Ack flag was wrong: {}".format(ack_packet))
	if ack_packet.syn != b'Y':
		raise Exception("Syn flag was wrong: {}".format(ack_packet))
	if ack_packet.fin != b'N':
		raise Exception("Fin flag was wrong: {}".format(ack_packet))

	print(ack_packet)
	#send 2nd packet from client to server
	client_ack_packet = create_packet_client(sequence_number=12346, ack_number = ack_packet.sequence_number + 1, ack = 'Y', syn = 'N', fin = 'N', m_s = b"")
	#3-way handshake is done

	#sendthe client 2nd packet
	socket.sendto(client_ack_packet,server_address)

	return 12346, ack_packet.sequence_number + 1 #starting seq & ack packet number to send data to the server

if __name__=='__main__':
	info = arg_parse()
	logfile = open(info.log, "a")
	server_address = (info.sit, info.port)
	#3-way handshake then send webpage
	#code modified by taken from https://docs.python.org/3/library/stdtypes.html#file.read for line 60-68
	webpage = get_webpage("https://www.python.org")
	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	buf = 512
	r =  open('test', 'rb')
	total_read = 0
	data_size = len(webpage)
	#data = r.read(buf)
	#total_read += 512
	#p2s call that packet to start 3-way handshake
	#send_data = P2_s.create_packet(sequence_number=100, ack_number=0, ack = 'Y', syn = 'N', fin = 'N', m_s = data)
	#print(P2_s.packet(send_data)) #test debug
	#sock.sendto(send_data,server_address)


	#track seq & ack
	sequence_number, ack_number = threeWayHandshake(sock, server_address)

	#sends the webpage 512 bytes at time
	while (total_read < data_size):
		data = r.read(buf)
		data_length = len(data) #store length of data being sent
		sendPacket = create_packet_client(sequence_number=sequence_number, ack_number=ack_number, ack = 'N', syn = 'N', fin = 'N', m_s = data)
		#sending packet to server
		sp = packet(sendPacket)
		string = sp.__str__()
		sock.sendto(sendPacket, server_address)
		logfile.write("SEND: " + string + "\n")
		#rcv ack from server
		data, _ = sock.recvfrom(len(create_packet_client(sequence_number=0, ack_number=0, ack = 'Y', syn = 'N', fin = 'N', m_s = "".encode()))) #_ means null
		#create packet frm data
		ack_packet = packet(data)
		string = ack_packet.__str__()
		logfile.write("RECV: " + string + "\n")

		#check the flags
		if ack_packet.ack != b'Y':
			raise Exception("Ack flag was wrong: {}".format(ack_packet))
		if ack_packet.syn != b'N':
			raise Exception("Syn flag was wrong: {}".format(ack_packet))
		if ack_packet.fin != b'N':
			raise Exception("Fin flag was wrong: {}".format(ack_packet))
		#server acknowledgement of data by
		if ack_packet.ack_number != sequence_number + data_length: #set by server to client
			raise Exception ("Wrong number: {}".format(ack_packet))

		ack_number = ack_packet.sequence_number + 1 #update ack num used by client, client acknowledge server data with his ack num
		sequence_number = sequence_number + data_length #update seq number

		print(packet(sendPacket))
		if ack_packet.sequence_number == 101:
			print ("Done with 3-Way-Handshake")

		#if (sock.sendto(data, server_address)):
		#	send_data = P2_s.create_packet(sequence_number=101, ack_number=0, ack = 'Y', syn = 'N', fin = 'N', m_s = data)
		#	data = r.read(buf)
		total_read += data_length

	#send a finish packet
	fin_packet = create_packet_client(sequence_number=sequence_number, ack_number=ack_number, ack = 'N', syn = 'N', fin = 'Y', m_s = b"")
	sock.sendto(fin_packet, server_address)
	#send fin packet & server sends back...
	print("Send fin|ack:")
	print(packet(fin_packet))
	print("FIN|ACK...done...shutdown connection...content written to output file")


	sock.close()
	r.close()
	#need server & client to send data to take it apart
