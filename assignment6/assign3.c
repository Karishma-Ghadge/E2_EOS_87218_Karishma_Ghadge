#include<stdio.h>
#include<unistd.h>

int main()
{
	int ret,cnt=0;

	while(1)
	{
		ret=fork();
		if(ret==-1)
		{
			printf("fork() failed at %d count\n",cnt);
			_exit(0);
		}
		else
		{
			cnt++;
			if(ret==0)
			{
				_exit(0);
			}
		}
	}
	return 0;
}
