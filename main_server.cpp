#include <iostream>
#include <cstring>
#include <unistd.h>
#include <linux/netlink.h>
#include <linux/genetlink.h>
#include <sys/socket.h>
#include <thread>
#include <chrono>

#define GENL_TEST_FAMILY_NAME "genl_test"
#define GENL_TEST_MCGRP_NAME "genl_test_mcgrp"

int main() {
    struct sockaddr_nl sa, client_sa;
    struct nlmsghdr *nlh;
    int sock_fd;
    char buffer[256];

    sock_fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_GENERIC);
    if (sock_fd < 0) {
        perror("socket");
        return -1;
    }

    pid_t pid = getpid();
    std::cout << "Server pid: " << pid << std::endl;
    memset(&sa, 0, sizeof(sa));
    sa.nl_family = AF_NETLINK;
    // sa.nl_pid = getpid();
    sa.nl_pid = pid;
    sa.nl_groups = 0;

    if (bind(sock_fd, (struct sockaddr *)&sa, sizeof(sa)) < 0) {
        perror("bind");
        close(sock_fd);
        return -1;
    }

    nlh = (struct nlmsghdr *)malloc(NLMSG_SPACE(256));
    while (true) {
        socklen_t client_sa_len = sizeof(client_sa);
        int len = recvfrom(sock_fd, nlh, NLMSG_SPACE(256), 0, (struct sockaddr *)&client_sa, &client_sa_len);
        if (len < 0) {
            perror("recvfrom");
            close(sock_fd);
            return -1;
        }

        std::string received_json = (char *)NLMSG_DATA(nlh) + GENL_HDRLEN;
        std::cout << "Received JSON string: " << received_json << std::endl;

        // Отправка полученного сообщения обратно клиенту
        // nlh->nlmsg_len = NLMSG_LENGTH(GENL_HDRLEN + received_json.size() + 1);
        // strcpy((char *)NLMSG_DATA(nlh) + GENL_HDRLEN, received_json.c_str());
        std::string hello = "Hello from server";
        nlh->nlmsg_len = NLMSG_LENGTH(GENL_HDRLEN + hello.size() + 1);
        strcpy((char *)NLMSG_DATA(nlh) + GENL_HDRLEN, hello.c_str());

        if (sendto(sock_fd, nlh, nlh->nlmsg_len, 0, (struct sockaddr *)&client_sa, client_sa_len) < 0) {
            perror("sendto");
            close(sock_fd);
            return -1;
        }

        std::cout << "Echoed JSON string sent: " << received_json << std::endl;
    }

    close(sock_fd);
    return 0;
}