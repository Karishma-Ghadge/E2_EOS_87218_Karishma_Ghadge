#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

struct input {
int start;
int end;
int sum;
};

struct output {
int res;
};

void* result(void *param)
{
struct input *ip=(struct input *)param;
struct output *op=(struct output *)malloc(sizeof(struct output));
ip->sum=0;
int i;
for(i=ip->start;i<=ip->end;i++) {
ip->sum=ip->sum + i;
}
op->res=ip->sum;
return op;
}

int main() 
{
pthread_t th;
struct input in;
struct output *out;
printf("enter the start number \n");
scanf("%d",&in.start);
printf("enter the end number \n");
scanf("%d",&in.end);

pthread_create(&th,NULL,result,&in);

pthread_join(th,(void**)&out);
printf("res= %d\n",out->res);

printf("press enter to exit..\n");
free(out);
getchar();
return 0;
}

