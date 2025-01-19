CXX = g++
CXXFLAGS = -Iinc -g

# Цели для сборки main_server и main_client
all: main_server main_client

main_server: main_server.o action_handler.o
	$(CXX) -o main_server main_server.o action_handler.o

main_client: main_client.o action_handler.o
	$(CXX) -o main_client main_client.o action_handler.o

main_server.o: main_server.cpp
	$(CXX) $(CXXFLAGS) -c main_server.cpp

main_client.o: main_client.cpp
	$(CXX) $(CXXFLAGS) -c main_client.cpp

action_handler.o: src/action_handler.cpp inc/action_handler.h
	$(CXX) $(CXXFLAGS) -c src/action_handler.cpp

clean:
	rm -f *.o main_server main_client