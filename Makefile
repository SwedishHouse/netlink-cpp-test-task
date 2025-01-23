CXX = g++
CXXFLAGS = -Iinc -I/usr/local/include -I/usr/include/libnl3/ -g -std=c++17
LDFLAGS = -L/usr/local/lib -lgtest -lgtest_main -pthread -lnl-3 -lnl-genl-3

all: main_server main_client test_math test_data_handler

main_server: main_server.o action_handler.o request_processing.o pid_manager.o
	$(CXX) -o main_server main_server.o action_handler.o request_processing.o pid_manager.o $(LDFLAGS)

main_client: main_client.o action_handler.o request_processing.o pid_manager.o
	$(CXX) -o main_client main_client.o action_handler.o request_processing.o pid_manager.o $(LDFLAGS)

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

test_data_handler: tests/test_data_handler.o data_handler.o action_handler.o
	$(CXX) $(CXXFLAGS) -o tests/test_data_handler tests/test_data_handler.o data_handler.o action_handler.o $(LDFLAGS)

request_processing.o: src/request_processing.cpp inc/request_processing.h
	$(CXX) $(CXXFLAGS) -c src/request_processing.cpp

pid_manager.o: src/pid_manager.cpp inc/pid_manager.h
	$(CXX) $(CXXFLAGS) -c src/pid_manager.cpp

clean:
	rm -f *.o main_server main_client tests/test_math tests/test_data_handler pid_info