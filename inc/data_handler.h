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

        enum class JSON_POS
        {
            POS_ACT=0,
            POS_ARG_1,
            POS_ARG_2,
            POS_SIZE
        };

        const std::vector<std::string> json_fields = {
            "action",
            "argument_1",
            "argument_2"
        };

        typedef struct client_data_struct {
            std::string operationType;
            std::variant<int, double> arg1;
            std::variant<int, double> arg2;
        }client_data_t;

        // typedef struct server_data_struct {
        //     const std::string str = "result";
        //     std::variant<int, double> result;
        // }server_data_t;

        std::map<std::string, std::variant<int, double>> server_data = {{"result", 0}};

        // Define client cmds
        const std::map<std::string, ActionHandler::Action> action_types = {
            {"add", ActionHandler::Action::ADD},
            {"sub", ActionHandler::Action::SUBSTRACT},
            {"mul", ActionHandler::Action::MULTIPLY}
        };
        // const std::map<std::string, ActionHandler::Action> operation_types = {
        //     {"action"}
        // };

        DataHandler(); //constructor
        void processData();// use object instance 
        // void processData(const std::string& jsonData); // Execute from ready JSON
        void parseDataToStructure(const std::string& jsonData);
        std::string parseToJSON();

        std::string getAction();

        template <typename T>
        T getArgOne();

        template <typename T>
        T getArgTwo();

    private:
        client_data_t client_data;
        // server_data_t server_data = {.str{"result"}, .result{0}};
        ActionHandler action_handler;
        std::string raw_data;
        json Doc;

};
