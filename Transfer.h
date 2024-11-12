#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

class Transfer
{
  public:
     myClass()
     {
       clientSocket = socket(AF_INET, SOCK_STREAM,0);
       
       serverAddress.sin_family = AF_INET;
       serverAddress.sin_port = htons(8080);
       
       if (inet_pton(AF_INET,"172.28.91.42", &serverAddress.sin_addr) <= 0)
       {
         return -1;
       }
     }
     
     void send(float humidity, float temp)
     {
       if (connect(clientSocket, (struct sockaddr*)&serverAddress,sizeof(serverAddress)) < 0)
       {
         return -1;
       }
       const char* dataH;
       const char* dataT;
       int convert = snprinf(dataH. sizeof dataH. "%f", humidity);
     }
}
