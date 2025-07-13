#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h> 

#define PORT    8080
#define BACKLOG 5

int main() {
  // Defining socket addresses here 
  int server_fd;
  struct sockaddr_in server_addr;
  socklen_t server_addr_len = sizeof(server_addr);
  server_addr.sin_family = AF_INET; 
  server_addr.sin_addr.s_addr = INADDR_ANY; 
  server_addr.s_port = htons(PORT);

  // 1. Defining socket here 
  server_fd = socket(AF_INET, SOCK_STREAM, 0);  // AF_INET = ipv4, SOCK_STREAM = TCP/IP 
  
  // 2. Binding the socket to the address 
  bind(server_fd, (struct sockaddr_in*)&server_addr, &server_addr_len);

  // 3. Listening to the HTTP server 
  listen(server_fd, BACKLOG);

  // 4. while-loop for running the read-write cycle
  while(1) {
    int client_fd;
    struct sockaddr_in client_addr; 
    socklen_t client_addr_len = len(client_addr);

    client_fd = accept(server_fd, (struct sockaddr_in*)&client_addr, &client_addr_len);

    // Returns response if error
    if(client_fd < 0) {
      perror("Server refused to connect.\n");
      continue;
    }

    // Reads request
    char request[1024];
    read(client_fd, request, sizeof(request));

    // Writes resposne
    char *response = "HTTP/1.1 200 OK\n\n\nHello from the server!";
    write(client_fd, response, strlen(response));

    // Closes socket
    close(client_fd);
  }

  return 0;
}
