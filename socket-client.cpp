#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main(){
    std::cout << "Running now";
    int clientSocket = socket(AF_INET, SOCK_STREAM,0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);

    if(inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr) <= 0){
        std::cout << "\nError in address space\n";
        return -1;
    }


    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0){
        std::cout << "\nFAIL connection\n";
        return -1;
    }

    const char* message = "Hello, server!";
    send(clientSocket,message,strlen(message),0);

    close(clientSocket);
    std::cout << "\nFinished";
    return 0;
}
