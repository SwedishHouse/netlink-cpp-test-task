#include <gtest/gtest.h>
#include "json.hpp"
#include "data_handler.h"

using json = nlohmann::json;

// Тестовый класс для DataHandler
class DataHandlerTest : public ::testing::Test {
protected:
    DataHandler handler1, handler2, handler3;

    void SetUp() override {
        // Пример JSON строки
        std::string jsonString = R"({
            "action": "add",
            "argument_1": 10,
            "argument_2": 20.5
        })";
        // Парсинг JSON строки в структуру данных
        handler1.parseDataToStructure(jsonString);
        handler1.processData();

        jsonString = R"({
            "action": "sub",
            "argument_1": 4,
            "argument_2": 2
        })";
        handler2.parseDataToStructure(jsonString);
        handler2.processData();

        jsonString = R"({
            "action": "mul",
            "argument_1": -13.2,
            "argument_2": 2
        })";
        handler3.parseDataToStructure(jsonString);
        handler3.processData();
    }
};

// Тесты для методов DataHandler
TEST_F(DataHandlerTest, GetAction) {
    EXPECT_EQ(handler1.getAction(), "add");
    EXPECT_EQ(handler2.getAction(), "sub");
    EXPECT_EQ(handler3.getAction(), "mul");
}

TEST_F(DataHandlerTest, GetArgOneInt) {
    EXPECT_DOUBLE_EQ(handler1.getArgOne<double>(), 10.0);
    EXPECT_EQ(handler2.getArgOne<int>(), 4);
    EXPECT_DOUBLE_EQ(handler3.getArgOne<double>(), -13.2);
}

TEST_F(DataHandlerTest, GetArgTwoDouble) {
    EXPECT_DOUBLE_EQ(handler1.getArgTwo<double>(), 20.5);
    EXPECT_EQ(handler2.getArgTwo<int>(), 2);
    EXPECT_DOUBLE_EQ(handler3.getArgTwo<double>(), 2.0);
}

TEST_F(DataHandlerTest, parseToJSON) {
    std::string expectedJson = R"({"result":30.5})";
    std::string actualJson = handler1.parseToJSON();
    EXPECT_EQ(actualJson, expectedJson);

    expectedJson = R"({"result":2})";
    actualJson = handler2.parseToJSON();
    EXPECT_EQ(actualJson, expectedJson);

    expectedJson = R"({"result":-26.4})";
    actualJson = handler3.parseToJSON();
    EXPECT_EQ(actualJson, expectedJson);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}