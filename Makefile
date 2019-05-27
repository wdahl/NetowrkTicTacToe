all: client server

client: p4client.c
		gcc -o p4client p4client.c

server: p4server.c
		gcc -o p4server p4server.c	