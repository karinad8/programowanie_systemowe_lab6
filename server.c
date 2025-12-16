#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "server.h"

void server_loop(int write_fd, int read_fd) {
	char str[50];
	char str2[50];

	while(1) {
		printf("Enter text: ");
		scanf("%s", str);
		write(write_fd, str, strlen(str) + 1);
		if(strcmp(str, "exit") == 0) {
			write(write_fd, str, strlen(str + 1));
			break;
		}
		read(read_fd, str2, sizeof(str2));
		printf("SERVER: received from  worker: %s\n", str2);
  	}
}
