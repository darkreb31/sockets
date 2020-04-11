#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

void main()
{
    // First we have to create a socket
    int network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Then we have to specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(4444);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    // Now check if there is an error
    if (connection_status == -1)
    {
        printf("There was an error making a connection to the socket. \nMake sure the server is running. \n");
        exit(0);
    }

    // Receive data from the server 
    char server_response[512];
    recv(network_socket, &server_response, sizeof(server_response), 0);

    // Print out the response of the server
    printf("The server sent the data - %s \n",server_response);

    // Close the socket
    close(network_socket);
    

}