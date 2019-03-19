#include <commons.h>

struct client_info
{
	int cfd;
	int cid;
};

void command_pwd();
void command_cd();
void command_ls();
void command_get();
void command_put();
void command_mkdir();
void command_rget();