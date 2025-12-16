#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "worker.h"

void worker_loop(int read_fd, int write_fd) {
	char str[50];

	while(1) {
		read(read_fd, str, sizeof(str));

		if (strcmp(str, "exit") == 0)
		return;

		str[0] = 'X';
		write(write_fd, str, strlen(str) + 1);
		}
}
