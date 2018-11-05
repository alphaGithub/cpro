TARGET=simulate
OBJS=basic_gate.o tool.o main.o 
CC=g++ 
$(TARGET): $(OBJS)
	g++ -o $(TARGET) $(OBJS)

basic_gate.o: basic_gate.cpp 
	g++ -c basic_gate.cpp 
tool.o: tool.cpp
	g++ -c tool.cpp 
main.o: main.cpp
	g++ -c main.cpp