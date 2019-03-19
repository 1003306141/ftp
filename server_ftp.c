#include <server_ftp.h>

int main()
{
	int cfd,sfd;
	struct sockaddr_in serv_addr;

	sfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&serv_addr, 0 , sizeof(struct sockaddr_in));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(CONTROLPORT);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(sfd, (struct sockaddr*)&serv_addr, sizeof(struct sockaddr_in));

	listen(sfd, 32);

	printf("FTP Server started up at Port : %d. Waiting for client(s)...\n",CONTROLPORT);

	while(1)
	{
		cfd = accept(sfd, NULL, NULL);
		printf("Client connect!\n");
		struct client_info* ci;
		ci->cfd = cfd;
		ci->cid = 100;
		serv_client(ci);
	}

	close(sfd);
	printf("Done.\n");
	fflush(stdout);
	return 0;
}


void* serv_client(void* info)
{
	struct client_info* ci = (struct client_info*)info;
	struct packet* data = (struct packet*)malloc(sizeof(struct packet));
	int cfd = ci->cfd;
	int ret;

	while(1)
	{
		if( (ret = recv(cfd, data, sizeof(struct packet), 0)) == 0)
		{
			fprintf(stderr,"client closed/terminated.closing connection.\n");
			break;
		}

		if(data->type == TERM)
			break;
		if(data->type == REQU)
		{
			switch(data->comid)
			{
				case PWD:
				{
					printf("recv pwd command\n");
				}break;
				case CD:
				{
					printf("recv cd command\n");
				}break;
				case MKDIR:
				{
					printf("rece mkdir command\n");
				}break;
			}

		}else
		{
			fprintf(stderr,"unknow type!\n");
			break;
		}
	}

	close(cfd);
	fflush(stdout);
}
