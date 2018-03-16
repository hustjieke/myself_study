#include <iostream>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    struct hostent *he;
    char hostname[20] = {0};

    gethostname(hostname,sizeof(hostname));
    he = gethostbyname(hostname);
    printf("hostname=%s\n",hostname);
    std::string strIP(inet_ntoa(*(struct in_addr*)(he->h_addr)));
    printf("%s\n",inet_ntoa(*(struct in_addr*)(he->h_addr)));
    std::cout << "strIP: " << strIP << std::endl;
}
