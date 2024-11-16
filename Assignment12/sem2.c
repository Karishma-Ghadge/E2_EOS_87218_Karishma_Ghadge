#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/sem.h>
#include<signal.h>
#include<string.h>

#define SEM_KEY 0X4321
int semid;

union semun {
int val;
struct semid_ds *buff;
unsigned short *array;
struct seminfo *__buff;
};

void sigint_handler(int sig) {
int s;
semctl(semid,0,IPC_RMID);
waitpid(-1,&s,0);
_exit(1);
}

void sigchld_handler(int sig)
{
int s;
waitpid(-1,&s,0);
}



int main()
{
int ret,i;
struct sigaction sa;
union semun su;
struct sembuf ops[1];


memset(&sa,0,sizeof(sa));
sa.sa_handler=sigint_handler;

ret=sigaction(SIGINT,&sa,NULL);
//semid=semget(SEM_KEY,2,IPC_CREAT|0600);


//create a semaphore with single counter
semid=semget(SEM_KEY,2,IPC_CREAT| 0600);

unsigned short init_cnts[]={1,0};
su.array=init_cnts;

//INITIALIZE SEMA COUNTER =0
//su.val=0;
ret=semctl(semid,0,SETALL,su);
if(ret < 0) {
perror("failed");
}
ret=fork();

if(ret==0)
{
char *str="SUNBEAM\n";
while(1)
{
ops[0].sem_num=0;
ops[0].sem_op=-1;
ops[0].sem_flg=0;
ret=semop(semid,ops,1);
for(i=0;str[i]!='\0';i++)
{
write(1,&str[i],1);
sleep(1);
}

ops[0].sem_num=1;
ops[0].sem_op=+1;
ops[0].sem_flg=0;
ret=semop(semid,ops,1);
//_exit(0);
}
}

else
{
while(1) {
ops[0].sem_num=1;
ops[0].sem_op=-1;
ops[0].sem_flg=0;
ret=semop(semid,ops,1);
char *str="INFOTECH\n";
for(i=0;str[i]!=0;i++)
{
write(1,&str[i],1);
sleep(1);
}
//write(1,&str[i],1
ops[0].sem_num=0;
ops[0].sem_op=+1;
ops[0].sem_flg=0;

ret=semop(semid,ops,1);

}


//destroy
//semctl(semid,0,IPC_RMID);

}
return 0;

}


























