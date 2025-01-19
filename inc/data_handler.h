#pragma once
#include <string>
#include <vector>
#include <map>
#include <variant>

#include "action_handler.h"
#include "json.hpp"

using json = nlohmann::json;


class DataHandler{


    
    public:

        typedef struct client_data_struct {
            std::string operationType;
            std::variant<int, double> arg1;
            std::variant<int, double> arg2;
        }client_data_t;

        typedef struct server_data_struct {
            std::string operationType;
            std::variant<int, double> result;
        }server_data_t;

        // Define client cmds
        const std::map<std::string, ActionHandler::Action> action_types = {
            {"add", ActionHandler::Action::Add},
            {"sub", ActionHandler::Action::Subtract},
            {"mul", ActionHandler::Action::Multiply}
        };
        // const std::map<std::string, ActionHandler::Action> operation_types = {
        //     {"action"}
        // };

        DataHandler(); //constructor
        void processData(const std::string& jsonData);

        void handle_data();

    private:
        client_data_t client_data;
        server_data_t server_data;
        ActionHandler action_handler;
        std::string raw_data;
        json Doc;

}


