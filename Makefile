CXX = g++
CXXFLAGS = -Iinc -I/usr/local/include -g -std=c++17
LDFLAGS = -L/usr/local/lib -lgtest -lgtest_main -pthread


all: main_server main_client test_math

main_server: main_server.o action_handler.o
	$(CXX) -o main_server main_server.o action_handler.o

main_client: main_client.o action_handler.o
	$(CXX) -o main_client main_client.o action_handler.o

test_math: tests/test_math.o action_handler.o
	$(CXX) $(CXXFLAGS) -o tests/test_math tests/test_math.o action_handler.o $(LDFLAGS)

main_server.o: main_server.cpp
	$(CXX) $(CXXFLAGS) -c main_server.cpp

main_client.o: main_client.cpp
	$(CXX) $(CXXFLAGS) -c main_client.cpp

data_handler.o: src/data_handler.cpp inc/data_handler.h
	$(CXX) $(CXXFLAGS) -c src/data_handler.cpp

action_handler.o: src/action_handler.cpp inc/action_handler.h
	$(CXX) $(CXXFLAGS) -c src/action_handler.cpp

tests/test_math.o: tests/test_math.cpp
	$(CXX) $(CXXFLAGS) -c tests/test_math.cpp -o tests/test_math.o


clean:
	rm -f *.o main_server main_client