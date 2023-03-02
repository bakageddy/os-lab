#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSIZE 27

int main() {
	int shmid;
	key_t key = 2013;
	char *shm, *s;

	if ((shmid = shmget(key, SHMSIZE, 0666)) < 0) {
		printf("Server not started\n");
		exit(1);
	}

	printf("Accessing shared memory id: %d\n", shmid);
	if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
		perror("shmat");
		exit(1);
	}

	printf("Shared memory contents:\n");
	for (s = shm;*s != '\0'; s++)
		putchar(*s);
	putchar('\n');
	*shm = '*';

	return 0;
}
