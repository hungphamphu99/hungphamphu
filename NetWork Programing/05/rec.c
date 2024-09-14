#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>  // Include for close()

// Global variables for the handler.
struct ip_mreq multiaddr;
int sock;

void handler() {
    printf("FIN\n");
    setsockopt(sock, IPPROTO_IP, IP_DROP_MEMBERSHIP, &multiaddr, sizeof(multiaddr));
    close(sock);
    exit(0);
}

int main() {
    const int TTL = 64;
    char buffer[250];
    struct sockaddr_in si_me, si_other;
    int slen;

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    multiaddr.imr_multiaddr.s_addr = htonl(0xe1000001);
    multiaddr.imr_interface.s_addr = htonl(INADDR_ANY);

    setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, &multiaddr, sizeof(multiaddr));
    setsockopt(sock, IPPROTO_IP, IP_MULTICAST_TTL, &TTL, sizeof(TTL));
    signal(SIGINT, handler);

    si_me.sin_family = AF_INET;
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);
    si_me.sin_port = htons(2008);

    if (bind(sock, (struct sockaddr*)&si_me, sizeof(si_me)) == -1)
        perror("Erreur bind.");

    slen = sizeof(si_other);
    while (1) {
        if (recvfrom(sock, buffer, 100, 0, (struct sockaddr*)&si_other, (socklen_t*)&slen) == -1)
            perror("Erreur recvfrom");

        printf("%s\n", buffer);
    }

    close(sock);
    exit(0);
}
