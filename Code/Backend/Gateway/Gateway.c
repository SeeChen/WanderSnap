#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#define PORT 80
#define BACKLOG 10
#define BUFFER_SIZE 1024

// If you can't run it in Windows, try it on WSL (Windows Subsystem for Linux).
// This code is the entry point for all HTTP requests.
int main () {

    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket < 0) {
        
        perror("Error opening socket");
        exit(1);
    }
}