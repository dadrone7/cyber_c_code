#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP>\n", argv[0]);
        return 1;
    }

    char *target_ip = argv[1];
    int start_port = 1;
    int end_port = 1024;  // you can expand this if you like

    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(target_ip);

    printf("Scanning host: %s\n", target_ip);

    for (int port = start_port; port <= end_port; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("Socket");
            continue;
        }

        target.sin_port = htons(port);

        // Try to connect
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d is OPEN\n", port);
        }

        close(sock);
    }

    return 0;
}
