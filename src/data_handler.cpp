#include "data_handler.h"

DataHandler::DataHandler()//: json_fields{"action", "argument_1", "argument_2"} 
{
    // There needs something do. But i din't mind
}

void DataHandler::processData(const std::string& jsonData)
{
    ActionHandler::Action act;
    std::variant<int, double> res;
    auto it = this->action_types.find(this->client_data.operationType);
    if (it != action_types.end()) 
        act = it->second;
    else
    {
        throw "No supported action!";
    }

    if(std::holds_alternative<double>(this->client_data.arg1))
    {
        res = this->action_handler.execute<double>(act,   std::get<double>(this->client_data.arg1),
                                                    std::get<double>( this->client_data.arg2));
    }
    else if(std::holds_alternative<int>(this->client_data.arg1))
    {
        res = this->action_handler.execute<int>(act,   std::get<int>(this->client_data.arg1),
                                                    std::get<int>( this->client_data.arg2));
    }
    
    this->server_data["result"] = res;
}

std::string DataHandler::getAction()
{
    return this->client_data.operationType;
}

template <typename T>
T  DataHandler::getArgOne()
{
    return std::get<T>(this->client_data.arg1);
}

template <typename T>
T  DataHandler::getArgTwo()
{
    return std::get<T>(this->client_data.arg2);
}



void DataHandler::parseDataToStructure(const std::string& jsonData)
{
    bool is_double = false;
    this->Doc = json::parse(jsonData);

    is_double = this->Doc[this->json_fields.at(static_cast<int>(DataHandler::JSON_POS::POS_ARG_1))].is_number_float() ||
    this->Doc[this->json_fields.at(static_cast<int>(DataHandler::JSON_POS::POS_ARG_2))].is_number_float();

    this->client_data.operationType = this->Doc[this->json_fields.at(static_cast<int>(DataHandler::JSON_POS::POS_ACT))];
    if(is_double){
        double arg_d_1, arg_d_2;

        arg_d_1 = this->Doc[this->json_fields.at(static_cast<int>(DataHandler::JSON_POS::POS_ARG_1))];
        arg_d_2 = this->Doc[this->json_fields.at(static_cast<int>(DataHandler::JSON_POS::POS_ARG_2))];

        this->client_data.arg1 = arg_d_1;
        this->client_data.arg2 = arg_d_2;
    }
    else{
        int arg_int_1, arg_int_2;

        arg_int_1 = this->Doc[this->json_fields.at(static_cast<int>(DataHandler::JSON_POS::POS_ARG_1))];
        arg_int_2 = this->Doc[this->json_fields.at(static_cast<int>(DataHandler::JSON_POS::POS_ARG_2))];

        this->client_data.arg1 = arg_int_1;
        this->client_data.arg2 = arg_int_2;
    }
}

std::string DataHandler::parseToJSON(const std::map<std::string, std::variant<int, double>>& data)
{
    json j;

    for (const auto& [key, value] : data) {
        if (std::holds_alternative<int>(value)) {
            j[key] = std::get<int>(value);
        } else if (std::holds_alternative<double>(value)) {
            j[key] = std::get<double>(value);
        }
    }

    return j.dump(); // Преобразование JSON объекта в строку
}


        
template int DataHandler::getArgOne<int>();
template int DataHandler::getArgTwo<int>();

template double DataHandler::getArgOne<double>();
template double DataHandler::getArgTwo<double>();