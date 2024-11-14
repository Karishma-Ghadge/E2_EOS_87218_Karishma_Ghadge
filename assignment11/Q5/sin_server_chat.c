#include<stdio.h>
#include<unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>

#define SERV_ADDR   "172.18.6.212"
#define SERV_PORT   2808

int main()
{
	int ret,serv_fd,cli_fd;
	struct sockaddr_in serv_addr,cli_addr;
	socklen_t socklen = sizeof(cli_addr);
	char msg[512];

	serv_fd = socket(AF_INET,SOCK_STREAM,0);
	if(serv_fd==-1)
	{
		perror("creation failed");
		_exit(1);
	}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERV_PORT);
	inet_aton(SERV_ADDR,&serv_addr.sin_addr);
	ret = bind(serv_fd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	if(ret==-1)
	{
		perror("bind() failed");
		_exit(1);
	}

	listen(serv_fd,5);

	cli_fd = accept(serv_fd,(struct sockaddr*)&cli_addr,&socklen);
	if(cli_fd==-1)
	{
		perror("accept() failed");
		_exit(1);
	}

	do
	{
		read(cli_fd,msg,sizeof(msg));
		printf("client msg received: %s\n",msg);
		printf("server send msg: ");
		gets(msg);
		write(cli_fd,msg,strlen(msg)+1);
	}while(strcmp(msg,"bye")!=0);

	close(cli_fd);

	shutdown(serv_fd,SHUT_RDWR);

return 0;
}
