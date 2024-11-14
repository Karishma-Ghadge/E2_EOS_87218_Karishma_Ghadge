#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() 
{
    int signal_num, pid;

    printf("Enter the signal number : \n");
    scanf("%d", &signal_num);

    printf("Enter process ID : \n");
    scanf("%d", &pid);

    if(kill == 0) 
	{
        perror("KILL ERROR!\n");

        return 1;
    }

    printf("Signal %d sent to process %d\n", signal_num, pid);

    return 0;

}
