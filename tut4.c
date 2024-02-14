//tut4_2
/*
Moro Bamber
Tutorial 4 Part 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t process = getppid(); //process is bash process
    
    pid_t parent = getpid(); //this process - will be partent
    printf("The process ID is %d\n",parent);
    printf("This parent process ID is %d\n",process);

    //redundant code but I don't want to mess with this any more
    char pid_str[20];
    sprintf(pid_str,"%d",process);

    //from here we fork
    printf("This process is upgraded to parent, with id %d\n",parent);
    pid_t f_pid = fork();
    //now we are forked, the child will have f_pid = 0
    if(f_pid != 0){
        //parent
        //we are in the parent branch
        pid_t parentPID = getpid();
        printf("The parent process ID is %d\n",parentPID);
        wait(NULL); //must wait for the child process to finish in
        //order for this process to be shown in the pstree
    }
    else{
        printf("The child's process ID is %d\n",getpid());
        //in a child branch
        pid_t childPID = getpid();
        printf("This is the child process, with ID %d\n",childPID);
        char toCall[20];
        sprintf(toCall,"%d",process); //make the PID we'd like to see the tree of a string

        char *args[] = {"pstree","-p",toCall,NULL}; //execvp arugments
        execvp("pstree",args);
        
    }


}
