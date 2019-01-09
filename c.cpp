// Data Structures Final

#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include<unistd.h>
#include <arpa/inet.h>
#include<iostream>
using namespace std;
#define PORT 8080
int main(int argc, char const *argv[])
{
struct sockaddr_in address;
int sock = 0 ;
struct sockaddr_in serv_addr;
char *hello = "ps "; // command to send option as of noew it is ps "it can be set to command line al    so"
char buffer[1024] = {0};
if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
{
cout<<"\n Socket creation error \n";
return -1;
}
memset(&serv_addr, '0', sizeof(serv_addr));
serv_addr.sin_family = AF_INET;
serv_addr.sin_port = htons(PORT);
// Convert IPv4 and IPv6 addresses from text to binary form
if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
{
cout<<"\nInvalid address/ Address not supported \n";
return -1;
}
if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
{
cout<<"\nConnection Failed \n";
return -1;
}
send(sock , hello , strlen(hello) , 0 );
// sending command
cout<<"Client: message sent\n";
// reading command
read( sock , buffer, 1024);
cout<<"Client output:\n"<<buffer<<endl;
return 0;
}
