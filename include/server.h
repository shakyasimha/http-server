#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function prototypes
int create_server_socket(void);
int accept_client(int server_fd, struct sockaddr_in *address, socklen_t *addrlen);
void handle_client(int client_fd);


#endif 