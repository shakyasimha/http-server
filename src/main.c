#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>  // For read(), write(), close()

#define PORT    8080
#define BACKLOG 5

int main() {
    // Defining socket addresses here 
    int server_fd;
    struct sockaddr_in server_addr;
    
    // Creating socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket creation failed");
        return 1;
    }

    // Configure server address
    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = INADDR_ANY; 
    server_addr.sin_port = htons(PORT);
    memset(server_addr.sin_zero, '\0', sizeof(server_addr.sin_zero));  // Zero padding

    // Binding the socket to the address
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(server_fd);
        return 1;
    }

    // Listening to the HTTP server
    if (listen(server_fd, BACKLOG) < 0) {
        perror("listen failed");
        close(server_fd);
        return 1;
    }

    printf("Server listening on port %d...\n", PORT);

    // while-loop for running the read-write cycle
    while(1) {
        int client_fd;
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_fd < 0) {
            perror("accept failed");
            continue;
        }

        // Reads request
        char request[1024] = {0};
        ssize_t bytes_read = read(client_fd, request, sizeof(request));
        if (bytes_read < 0) {
            perror("read failed");
            close(client_fd);
            continue;
        }

        // Writes response
        char *response = "HTTP/1.1 200 OK\r\n"
                         "Content-Type: text/plain\r\n"
                         "\r\n"
                         "Hello from the server!";
        write(client_fd, response, strlen(response));

        // Closes socket
        close(client_fd);
    }

    close(server_fd);
    return 0;
}