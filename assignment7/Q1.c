#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int i, pid1, pid2, pid3, s1, s2, s3, s;
	int cnt=0;
    pid1 = fork();
	cnt++;
    if(pid1 == 0) { // child 1
        for(i=1; i<=3; i++) {
            printf("child1: %d and count=%d\n", i,cnt);
            sleep(1);
        }
        _exit(3);
    }

    // parent continues
    pid2 = fork();
	cnt++;
    if(pid2 == 0) { // child 2
        for(i=1; i<=3; i++) {
            printf("child2: %dand count=%d\n", i,cnt);
            sleep(1);
        }
        _exit(7);
    }

    // parent continues
    pid3 = fork();
	cnt++;
    if(pid3 == 0) { // child 3
        for(i=1; i<=3; i++) {
            printf("child3: %d and count=%d\n", i,cnt);
            sleep(1);
        }
        _exit(9);
    }

    // parent continues
    for(i=1; i<=3; i++) {
        printf("parent: %d\n", i);
        sleep(1);
    }

    //waitpid(pid1, &s1, 0);
    //waitpid(pid2, &s2, 0);
    //waitpid(pid3, &s3, 0);

    while(waitpid(-1, &s, 0) > 0)
        printf("child exit status: %d\n", WEXITSTATUS(s));
    return 0;
}
