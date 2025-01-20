#include <gtest/gtest.h>
#include "action_handler.h"

// Тесты для функций ActionHandler::execute
// Int
TEST(ActionHandlerTest, AddInt) {
    ActionHandler handler;
    EXPECT_EQ(handler.execute<int>(ActionHandler::Action::ADD, 1, 1), 2);
    EXPECT_EQ(handler.execute<int>(ActionHandler::Action::ADD, -1, 1), 0);
    EXPECT_EQ(handler.execute<int>(ActionHandler::Action::ADD, -1, -1), -2);
}

TEST(ActionHandlerTest, MultiplyInt) {
    ActionHandler handler;
    EXPECT_EQ(handler.execute<int>(ActionHandler::Action::MULTIPLY, 2, 3), 6);
    EXPECT_EQ(handler.execute<int>(ActionHandler::Action::MULTIPLY, -2, 3), -6);
    EXPECT_EQ(handler.execute<int>(ActionHandler::Action::MULTIPLY, -2, -3), 6);
}

TEST(ActionHandlerTest, SubstractInt) {
    ActionHandler handler;
    EXPECT_EQ(handler.execute<int>(ActionHandler::Action::SUBSTRACT, 1, 1), 0);
    EXPECT_EQ(handler.execute<int>(ActionHandler::Action::SUBSTRACT, -1, 1), -2);
    EXPECT_EQ(handler.execute<int>(ActionHandler::Action::SUBSTRACT, -1, -1), 0);
    EXPECT_EQ(handler.execute<int>(ActionHandler::Action::SUBSTRACT, 14, 2), 12);
    EXPECT_EQ(handler.execute<int>(ActionHandler::Action::SUBSTRACT, -14, 2), -16);
}


// Double
TEST(ActionHandlerTest, AddDouble) {
    ActionHandler handler;
    EXPECT_DOUBLE_EQ(handler.execute<double>(ActionHandler::Action::ADD, 1.5, 2.5), 4.0);
    EXPECT_DOUBLE_EQ(handler.execute<double>(ActionHandler::Action::ADD, -1.5, 1.5), 0.0);
    EXPECT_DOUBLE_EQ(handler.execute<double>(ActionHandler::Action::ADD, -1.5, -2.5), -4.0);
    EXPECT_DOUBLE_EQ(handler.execute<double>(ActionHandler::Action::ADD, -1, -2.5), -3.5);
    EXPECT_DOUBLE_EQ(handler.execute<double>(ActionHandler::Action::ADD, -1.0, -2), -3.0);
}

TEST(ActionHandlerTest, MultiplyDouble) {
    ActionHandler handler;
    EXPECT_DOUBLE_EQ(handler.execute<double>(ActionHandler::Action::MULTIPLY, 2.0, 3.0), 6.0);
    EXPECT_DOUBLE_EQ(handler.execute<double>(ActionHandler::Action::MULTIPLY, -2.0, 3.0), -6.0);
    EXPECT_DOUBLE_EQ(handler.execute<double>(ActionHandler::Action::MULTIPLY, -2.0, -3.0), 6.0);
    EXPECT_DOUBLE_EQ(handler.execute<double>(ActionHandler::Action::MULTIPLY, -2, -3.0), 6.0);
    EXPECT_DOUBLE_EQ(handler.execute<double>(ActionHandler::Action::MULTIPLY, -2.0, -3), 6.0);
}

TEST(ActionHandlerTest, SubstractDouble) {
    ActionHandler handler;
    EXPECT_DOUBLE_EQ(handler.execute<double>(ActionHandler::Action::SUBSTRACT, 2.0, 3.0), -1.0);
    EXPECT_DOUBLE_EQ(handler.execute<double>(ActionHandler::Action::SUBSTRACT, -2.0, 3.0), -5.0);
    EXPECT_DOUBLE_EQ(handler.execute<double>(ActionHandler::Action::SUBSTRACT, 2.0, -3.0), 5.0);
    EXPECT_DOUBLE_EQ(handler.execute<double>(ActionHandler::Action::SUBSTRACT, 2, -3.0), 5.0);
    EXPECT_DOUBLE_EQ(handler.execute<double>(ActionHandler::Action::SUBSTRACT, 2.0, -3), 5.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}