#include <stdio.h>
#include <stdlib.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    struct ifaddrs *ifaddr, *ifa;
    int family, s;
    char host[NI_MAXHOST];

    // getifaddrs() creates a linked list of structures describing 
    // the network interfaces of the local system.
    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    printf("System IP Addresses:\n");
    printf("--------------------------\n");

    // Walk through linked list, maintaining head pointer so we can free it later
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL)
            continue;

        family = ifa->ifa_addr->sa_family;

        // We only care about IPv4 addresses (AF_INET)
        // If you want IPv6, you would also check for AF_INET6
        if (family == AF_INET) {
            s = getnameinfo(ifa->ifa_addr,
                            sizeof(struct sockaddr_in),
                            host, NI_MAXHOST,
                            NULL, 0, NI_NUMERICHOST);
            if (s != 0) {
                printf("getnameinfo() failed: %s\n", gai_strerror(s));
                exit(EXIT_FAILURE);
            }

            printf("Interface: %-10s Address: %s\n", ifa->ifa_name, host);
        }
    }

    freeifaddrs(ifaddr);
    return 0;
}
