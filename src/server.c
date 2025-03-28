#include "server.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int create_server_socket(void) {
    int server_fd;
    int opt = 1;

    // Step 1: Defining socket
    // AF_INET = IPv4, SOCK_STREAM = TCP, 0 = IP
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed.\n");
        exit(EXIT_FAILURE);
    }

    // Step 2: Setting socket options
    // level = SOL_SOCKET; optname = SO_REUSEADDR | SO_REUSEPORT; optval = &opt; optlen = sizeof(opt)
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Step 3: Binding socket 
    /*
        Define the server address
        sin_family = AF_INET (IPv4)
        s_adrr = INADDR_ANY (take any address in)
        sin_port = htons(PORT) (convert PORT to network byte order)
    */
    struct sockaddr_in address; 
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binds the socket here
    if(bind(server_fd, &address, sizeof(address)) < 0){
        perror("bind failed.\n");
        exit(EXIT_FAILURE);
    }

    // Step 4: Listening
    if(listen(server_fd, 3) < 3) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    return server_fd;
}

int accept_client(int server_fd, struct sockaddr_in *address, socklen_t *addrlen) {
    // Step 5: Accepting the server
    int new_socket = accept(server_fd, (struct sockaddr *)address, addrlen);

    if (new_socket < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    return new_socket;
}

void handle_client(int client_fd) {
    char buffer[BUFFER_SIZE] = {0};
    char *hello = "Hello from the server\n";
    
    ssize_t valread = read(client_fd, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);
    send(client_fd, hello, strlen(hello), 0);
    printf("Hello message sent.\n");
    
    close(client_fd);
}