#include "data_handler.h"

DataHandler::DataHandler()
{
    // There needs something do. But i din't mind
}

void DataHandler::processData(const std::string& jsonData)
{
    this->Doc = json::parse(jsonData);
}
