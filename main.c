#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include "server.h"
#include "worker.h"
#include <fcntl.h>

#define FIFO1 "server_to_worker"
#define FIFO2 "worker_to_server"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("usage: %s server and worker\n", argv[0]);
		return 1;
	}

	if (strcmp(argv[1], "server") == 0) {
		mkfifo(FIFO1, 0666);
		mkfifo(FIFO2, 0666);

		int write_fd = open(FIFO1, O_WRONLY);
		int read_fd = open (FIFO2, O_RDONLY);

		printf("server: working\n");
		server_loop(write_fd, read_fd);

		close(write_fd);
		close(read_fd);

		unlink(FIFO1);
		unlink(FIFO2);

		printf("server: done\n");
	}
	else if (strcmp(argv[1], "worker") == 0) {
		int read_fd = open(FIFO1, O_RDONLY);
                int write_fd = open(FIFO2, O_WRONLY);

		printf("worker: working\n");
		worker_loop(read_fd, write_fd);

		close(read_fd);
		close(write_fd);
		printf("worker: done\n");
	}
	else {
		printf("Error:invalid argument");
		return 1;
	}
	return 0;
}
