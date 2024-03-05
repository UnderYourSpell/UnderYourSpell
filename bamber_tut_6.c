/*
Moro Bamber 
Tutorial 6
*/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

//uses a pointer to count to increment a variable in memory that
//each thread has access to, there is no race condition because each
//thread is created then has a second before the next one is created
int count = 1;
int *p = &count;


void *displayNum(int* p){
	printf("%d, thread id: %lu\n",count,pthread_self());
	(*p)++;
}

int main() {
	pthread_t tid[10];
	for(int i = 0; i < 10; i++){
		pthread_create(&tid[i], NULL, &displayNum,p);
		//pthread_join(tid[i], NULL);
		sleep(1);
	}
	for (int i = 0; i < 10; i++) {
        	pthread_join(tid[i], NULL);
    	}
	return 0;
}
