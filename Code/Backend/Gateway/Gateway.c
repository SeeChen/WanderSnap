#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#define PORT 1063
#define BACKLOG 10
#define BUFFER_SIZE 1024

// If you can't run it in Windows, try it on WSL (Windows Subsystem for Linux).
// This code is the entry point for all HTTP requests.

void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    bytes_read = read(client_socket, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        perror("Error reading from socket");
        close(client_socket);
        return;
    }

    buffer[bytes_read] = '\0';

    printf("Received request:\n%s\n", buffer);

    const char *response_header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    const char *response_body = "<html><body><h1>Hello, World!</h1></body></html>";

    write(client_socket, response_header, strlen(response_header));
    write(client_socket, response_body, strlen(response_body));

    close(client_socket);
}


int main () {

    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket < 0) {
        
        perror("Error opening socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        close(server_socket);
        exit(1);
    }

    if (listen(server_socket, BACKLOG) < 0) {
        perror("Error listening on socket");
        close(server_socket);
        exit(1);
    }

    printf("Server is listening on port: %d\n", PORT);

    while (1) {
        
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket < 0) {
            perror("Error accepting connection");
            continue;
        }

        
        handle_request(client_socket);
    }

    close(server_socket);

    return 0;
}