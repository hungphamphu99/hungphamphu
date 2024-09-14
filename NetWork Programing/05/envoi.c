#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>  // Include for close()

int main() {
    const int TTL = 64;
    char buffer[250], nom[100];
    struct sockaddr_in to;
    struct ip_mreq multiaddr;
    int m;

    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    multiaddr.imr_multiaddr.s_addr = htonl(0xe1000001);
    multiaddr.imr_interface.s_addr = htonl(INADDR_ANY);

    setsockopt(sock, IPPROTO_IP, IP_MULTICAST_TTL, &TTL, sizeof(TTL));

    to.sin_family = AF_INET;
    to.sin_addr.s_addr = htonl(0xe1000001);
    to.sin_port = htons(2008);

    printf("Enter your name:");
    scanf("%s", nom);

    strcat(nom, ":");
    strcpy(buffer, nom);
    m = strlen(nom);

    while (1) {
        buffer[m] = '\n';
        while (buffer[m] == '\n') {
            printf("%s", nom);
            fgets(&buffer[m], sizeof(buffer) - m, stdin);
        }
        sendto(sock, buffer, strlen(buffer) + 1, 0, (const struct sockaddr*)&to, sizeof(to));
    }

    close(sock);
    exit(0);
}
