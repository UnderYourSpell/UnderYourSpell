//tut4_2

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t process = getppid(); //process is bash process
    printf("This is the bash process ID %d\n",process);
    char pid_str[20];
    sprintf(pid_str,"%d",process);

    //from here we fork
    pid_t f_pid = fork();
    //now we are forked, the child will have f_pid = 0
    if(f_pid != 0){
        //parent
        //we are in the parent branch
        pid_t parentPID = getpid();
        printf("The parent process ID is %d\n",parentPID);

    }
    else{
        
        //in a child branch
        pid_t childPID = getpid();

        printf("This is the child process, with ID %d\n",childPID);
        //now here we must call execvp() function
        //must call it in this process
        //pid_t ppid = getppid();
        char toCall[20];
        sprintf(toCall,"%d",getppid());
        printf("ppid: %d\n",getppid());

        char *args[] = {"pstree","-p",toCall,NULL};
        execvp("pstree",args);
        
    }


}
