#include <commons.h>

void printpacket(struct packet* p)
{
	printf("conid = %d\n", p->conid);
	printf("type = %d\n", p->type);
	printf("comid = %d\n", p->comid);
	printf("datalen = %d\n", p->datalen);
	printf("buffer = %s\n", p->buffer);
}