// Producer-Consumer problem using semaphore

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define N 5
#define BUFSIZE 1
#define PERMS 0666

int *buffer;
int nextp = 0, nextc = 0;
int mutex, full, empty;

void producer() {
	int data;
	if (nextp == N)
		nextp = 0;
	printf("Enter data for producer to produce: ");
	scanf("%d", (buffer + nextp));
	nextp++;
}

void consumer() {
	int g;
	if (nextc == N)
		nextc = 0;
	g = *(buffer + nextc++);
	printf("Consumer consumes data %d\n", g);
}

void sem_op(int id, int value) {
	struct sembuf op;
	int v;
	op.sem_num = 0;
	op.sem_op = value;
	op.sem_flg = SEM_UNDO;
	if ((v = semop(id, &op, 1)) < 0)
		printf("Error Executing Semop Instruction\n");
}



void sem_create(int semid, int initval) {
	int semval;
	union semun {
		int val;
		struct semid_ds *buf;
		unsigned short *array;
	} s;

	s.val = initval;
	if ((semval = semctl(semid, 0, SETVAL, s)) < 0)
		printf("Error in executing semctl");
}

void sem_wait(int id) {
	int value = -1;
	sem_op(id, value);
}

void sem_signal(int id) {
	int value = 1;
	sem_op(id, value);
}

int main() {
	int shmid, i;
	pid_t pid;
	
	if ((shmid = shmget(1000, BUFSIZE, IPC_CREAT | PERMS)) < 0) {
		printf("Unable to create shared memory\n");
		return -1;
	}

	if ((buffer = (int *) shmat(shmid, (char *) 0, 0)) == (int *) -1) {
		printf("Shared Memory allocation error\n");
		exit(1);
	}

	if ((mutex = semget(IPC_PRIVATE, 1, PERMS | IPC_CREAT)) == -1) {
		printf("Can't create mutex semaphore\n");
		exit(1);
	}

	if ((empty = semget(IPC_PRIVATE, 1, PERMS | IPC_CREAT)) == -1) {
		printf("Can't create empty semaphore\n");
		exit(1);
	}

	if ((full = semget(IPC_PRIVATE, 1, PERMS | IPC_CREAT)) == -1) {
		printf("Can't create full semaphore\n");
		exit(1);
	}

	sem_create(mutex, 1);
	sem_create(empty, N);
	sem_create(full, 0);


	if ((pid = fork()) < 0) {
		printf("Error in process creation");
		exit(1);
	} else if (pid > 0) {
		for (i = 0; i < N; i++) {
			sem_wait(empty);
			sem_wait(mutex);
			producer();
			sem_signal(mutex);
			sem_signal(full);
		}
	} else if (pid == 0) {
		for (i = 0; i < N; i++) {
			sem_wait(full);
			sem_wait(mutex);
			consumer();
			sem_signal(mutex);
			sem_signal(empty);
		}
		printf("\n");
	}
}






