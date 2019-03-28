#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>



#define SERV_PORT	8000	//服务器端的端口
#define LISTENQ		12	//连接请求队列的最大长度
#define INVALID_USERINFO	'n'	//用户信息无效
#define VALID_USERINFO	'y'		//用户信息有效

#define MAX_MSG_SIZE	256

//void init_server(void);

int main(int argc,char **argv)
{
	int sock_fd,client_fd;
	struct sockaddr_in server_addr,client_addr;
	char recv_message[MAX_MSG_SIZE];
	//struct sockaddr_in
	sock_fd = socket(AF_INET,SOCK_STREAM,0);
	if(sock_fd < 0){
		fprintf(stderr,"Bind Error:%s\n",strerror(errno));
		exit(1);
	}
	socklen_t addrlen = sizeof(struct sockaddr_in);
	bzero(&server_addr,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
					//inet_addr(INADDR_ANY);
	server_addr.sin_port = htons(SERV_PORT);
	if(-1 == bind(sock_fd,(struct sockaddr *)&server_addr,
			sizeof(server_addr))){
		fprintf(stderr,"Bind Error:%s\n",strerror(errno));
		exit(1);
	}
	if(listen(sock_fd,LISTENQ) < 0){
		fprintf(stderr,"Listen Error:%s\n",strerror(errno));
		close(sock_fd);
		exit(1);
	}

	client_fd = accept(sock_fd,(struct sockaddr*)&client_addr,&addrlen);
	if(0 > client_fd){
		fprintf(stderr,"Accept Error:%s\n",strerror(errno));
	}else {
		while(1){
			recv(client_fd,recv_message,(size_t)MAX_MSG_SIZE,0);
			printf("client:%s",recv_message);
			printf("server:");
			fgets(recv_message,MAX_MSG_SIZE,stdin);
			if(strcmp(recv_message,"exit()\n") == 0)break;
			send(client_fd,recv_message,sizeof(recv_message),0);
		}
		close(client_fd);
	}
	close(sock_fd);
	return 0;
}





	


/*
void init_server(void)
{
	int optval;
	int flag;
	int ret;
	int sock_fd,conn_fd;
	pit_t pid;
	socklen_t cli_len;
	struct sockaddr_in cli_addr,serv_addr;
	char recv_buf[BUFSIZE];

	pthread_attr_t a;			
	pthread_attr_init(&a);
	pthread_attr_setdetachstate(&a,PTHREAD_CREATE_DETACHED);

	sock_fd = socket(AF_INET,SOCK_STREAM,0);
	if(sock_fd<0){
		//my_err("socket",__LINE__);
	}

	optval = 1;
	if(setsockopt(sock_fd,SOL_SOCKET,SO_REUSEADDR,(void *)&optval,sizeof(int))<0){
		//my_err("setsocket",__LINE__);
	}
	return sock_fd;


}
*/
