#ifndef COMMONS_H
#define COMMONS_H

#include <arpa/inet.h>

#include <netinet/in.h>

#include <sys/types.h>

#include <sys/socket.h>

#include <errno.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#define CONTROLPORT 7777
#define DATAPORT CONTROLPORT+1


#define BUFLEN 504//512-8-504
struct packet
{
	short int conid;//connect id
	short int type;//command type
	short int comid;//command ID
	short int datalen;//data len
	char buf[BUFLEN]//data
};

void printpacket(struct packet*);


enum TYPE
{
	REQU,
	DONE,
	INFO,
	TERM,
	DATA,
	EOT
};

enum COMMAND
{
	LS,
	CD,
	PWD,
	MKDIR
};





#endif