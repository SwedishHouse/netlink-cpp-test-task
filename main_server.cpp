#include <iostream>
#include <cstring>
#include <unistd.h>
#include <linux/netlink.h>
#include <linux/genetlink.h>
#include <sys/socket.h>
#include <thread>
#include <chrono>
#include <cstring>
#include <sys/socket.h>

#include "data_handler.h"
#include "request_processing.h"
#include "pid_manager.h"

#define TEST_NL_BUFF_SIZE 1024
#define GENL_TEST_FAMILY_NAME "genl_test"
#define GENL_TEST_MCGRP_NAME "genl_mcgrp"
#define GENL_TEST_CMD_ECHO 1

int main() {
    unsigned int counter = 0;
    DataHandler data_handler;
    // Create socket
    int sock_fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_GENERIC);
    if (sock_fd < 0) {
        perror("socket");
        return -1;
    }

    // Заполнение структуры sockaddr_nl для сервера
    struct sockaddr_nl sa = {0};
    memset(&sa, 0, sizeof(sa)); // Для надежности

    PIDManager pid_mngr;

    pid_t server_pid = getpid();
    pid_mngr.writePIDToFile(pid_info, server_pid);
    std::cout << "Server PID: " << server_pid <<std::endl;
    
    sa.nl_family = AF_NETLINK; // Family Must
    sa.nl_pid = server_pid; //PID MUST
    sa.nl_groups = 0; // In modern must be zero


    //Bind process
    if (bind(sock_fd, (struct sockaddr*)&sa, sizeof(sa)) < 0) {
        perror("bind");
        close(sock_fd);
        return -1;
    }
    // const std::string response_base = "Response from server: ";
    // std::string response; 

    std::string from_client;
    std::string response;
    while (true) {
        from_client = receive_gnl_message(sock_fd);

        std::cout << from_client << std::endl;
        data_handler.parseDataToStructure(from_client);
        data_handler.processData();
        response = data_handler.parseToJSON();
        send_gnl_message(response, sock_fd);
        
    }

    close(sock_fd);
    return 0;
}