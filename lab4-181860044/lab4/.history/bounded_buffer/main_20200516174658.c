#include "lib.h"
#include "types.h"
#define BUFFER_SIZE 5

int main(void) {
	// TODO in lab4
	printf("bounded_buffer\n");
	int ret = 0;
	int n = BUFFER_SIZE; //buffer size
	sem_t mutex, fullBuffers, emptyBuffers;
	ret = sem_init(&mutex, 1);
	if(ret == -1){
		printf("Init semaphone error!\n");  
		return -1;  
	}
	ret = sem_init(&fullBuffers, 0);
	if(ret == -1){
		printf("Init semaphone error!\n");  
		return -1;  
	}
	ret = sem_init(&emptyBuffers, n);
	if(ret == -1){
		printf("Init semaphone error!\n");  
		return -1;  
	}

	for(int i = 0; i < 4; ++i){ //To get five process by fork, one consumer(pid = 1) and four producers(pid = 2~5)
		ret = fork();
		if(ret == -1){
			printf("Fork error!\n");  
			return -1;  
		}
		if(ret == 0){ //Child process
			break;
		}
	}
	//printf("pid %d: hello world\n",getpid());
	if(getpid() == 1){  //consumer process
		sem_wait(&fullBuffers);
		sem_wait(&mutex);
		printf("Consumer : consume\n");
		sleep(128);
		sem_post(&mutex);
		sem_post(&emptyBuffers);
	}
	else if(getpid()>1 && getpid()<6){ //producer process
		sem_wait(&emptyBuffers);
		sem_wait(&mutex);
		int id = getpid() - 1;  //producer id, 1~4
		printf("Producer %d: produce\n", id);
		sleep(128);
		sem_post(&mutex);
		sem_post(&fullBuffers);
	}
	

	sem_destroy(&mutex);
	sem_destroy(&fullBuffers);
	sem_destroy(&emptyBuffers);
	while(1);
	exit();
	return 0;
}
