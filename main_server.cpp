#include <libnl3/netlink/netlink.h>
#include <libnl3/netlink/genl/genl.h>
#include <libnl3/netlink/genl/ctrl.h>
#include <iostream>
#include <cstring>

#define GENL_TEST_FAMILY_NAME "genl_test"
#define GENL_TEST_MCGRP_NAME "genl_mcgrp"

int main() {
    nl_sock *sock;
    nl_msg *msg;
    genlmsghdr *genlh;
    const char *message = "Hello from server";

    sock = nl_socket_alloc();
    if (!sock) {
        std::cerr << "Failed to allocate socket." << std::endl;
        return -1;
    }

    if (genl_connect(sock)) {
        std::cerr << "Failed to connect to Generic Netlink." << std::endl;
        nl_socket_free(sock);
        return -1;
    }

    int family_id = genl_ctrl_resolve(sock, GENL_TEST_FAMILY_NAME);
    if (family_id < 0) {
        std::cerr << "Family not found." << std::endl;
        nl_socket_free(sock);
        return -1;
    }

    msg = nlmsg_alloc();
    if (!msg) {
        std::cerr << "Failed to allocate message." << std::endl;
        nl_socket_free(sock);
        return -1;
    }

    genlh = static_cast<genlmsghdr*>(genlmsg_put(msg, NL_AUTO_PORT, NL_AUTO_SEQ, family_id, 0, 0, 0, 1));
    if (!genlh) {
        std::cerr << "Failed to put Generic Netlink header." << std::endl;
        nlmsg_free(msg);
        nl_socket_free(sock);
        return -1;
    }

    nla_put_string(msg, 1, message);

    if (nl_send_auto(sock, msg) < 0) {
        std::cerr << "Failed to send message." << std::endl;
        nlmsg_free(msg);
        nl_socket_free(sock);
        return -1;
    }

    nlmsg_free(msg);
    nl_socket_free(sock);
    return 0;
}
