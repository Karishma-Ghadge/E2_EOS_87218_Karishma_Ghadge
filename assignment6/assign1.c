#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int ret,i,s;

	for(i=1;i<=5;i++)
	{
		ret=fork();
		if(ret==-1)
		{
			printf("fork() failed\n");
			_exit(0);
		}
		else if(ret==0)
		{
			printf("child start\n");
			printf("child: count: %d pid:%d\n",i,getpid());
			printf("child end\n");
			_exit(0);
		}
		sleep(5);
	}
	for(i=1;i<=5;i++)
	{
		wait(&s);
		printf("child exit status: %d\n",WEXITSTATUS(s));
	}
	printf("program ended\n");
	return 0;
}
