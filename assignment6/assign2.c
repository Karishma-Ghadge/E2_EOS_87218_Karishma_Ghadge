#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int p1,p2,p3,s;
	p1=fork();

	if(p1==-1)
	{
		printf("fork() failed");
		_exit(0);
	}
	if(p1==0)
	{
		p2=fork();
		if(p2==-1)
		{
			printf("fork() failed");
			_exit(0);
		}
		if(p2==0)
		{
			p3=fork();
			if(p3==-1)
			{
				printf("fork() failed");
				_exit(0);
			}
			if(p3==0)
			{
				printf("process 3: %d\n",getpid());
				printf("process 3 finished\n");
				_exit(0);
			}
			sleep(5);
		}
		else
		{
			wait(&s);
			printf("child exit status: %d\n",WEXITSTATUS(s));
			printf("process 2: %d\n",getpid());
			printf("process 2 finished\n");
			_exit(0);
		}
		sleep(5);
	}
	else
	{
		wait(&s);
		printf("process 1: %d\n",getpid());
		printf("process 1 finished\n");
		_exit(0);
	}
	sleep(5);
	return 0;
}
