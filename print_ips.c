#include <stdio.h>
#include <stdlib.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void) {
    struct ifaddrs *ifaddr, *ifa;

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        return 1;
    }

    printf("System IP Addresses:\n");
    printf("--------------------------\n");

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (!ifa->ifa_addr)
            continue;

        if (ifa->ifa_addr->sa_family == AF_INET) {
            char host[INET_ADDRSTRLEN];

            struct sockaddr_in *sa =
                (struct sockaddr_in *)ifa->ifa_addr;

            inet_ntop(AF_INET, &sa->sin_addr,
                      host, sizeof(host));

            printf("Interface: %-10s Address: %s\n",
                   ifa->ifa_name, host);
        }
    }

    freeifaddrs(ifaddr);
    return 0;
}
