#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t chpid = fork();
	int status;
    if (-1 == chpid) 
        perror("fork fail");
    else if (0 == chpid) // 子进程返回 0
	{
        printf("I'm child process:pid = %d\n", getpid());
		printf("child ppid=%d\n",getppid());
	}
    else
{ // 父进程返回子进程 PID
		waitpid(chpid,&status,0);
        printf("I'm parent process:pid = %d\n", getpid());
		printf("parent ppid=%d\n",getppid());
		printf("I'm parent process，fork return is: %d\n", chpid);
		printf("child process exited with status %d\n",status);
}

    return 0;
}
