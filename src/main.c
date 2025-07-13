#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h> 

#define PORT    8080
#define BACKLOG 5

int main() {
  // Defining socket addresses here 
  struct sockaddr_in address; 
  address.sin_family = AF_INET; 
  address.sin_addr.s_addr = INADDR_ANY; 
  address.s_port = htons(PORT);

  /*
   * For sockets, the following order should be kept in mind.
   *
   * 1 - create a socket with socket() 
   * 2 - bind the socket with addresses using bind()
   * 3 - socket listens to the client using listen() 
   * 4 - socket will accept requests using accept()
   * 5 - read() and write()
   * 6 - close()
   * */

  // 1. Defining socket here 
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);  // AF_INET = ipv4, SOCK_STREAM = TCP/IP 
  
  // 2. Binding the socket to the address 
  bind(socket_fd, (struct sockaddr_in*)$address, sizeof(address));

  // 3. Listening to the HTTP server 
  listen(socket_fd, backlog);

  // 4. while-loop for running the read-write cycle
  while(1) {
    
  }

  return 0;
}
