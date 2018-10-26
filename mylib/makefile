TARGET=mylib
OBJS=sort.o main.o 
CC=gcc 
$(TARGET): $(OBJS)
	gcc -o $(TARGET) $(OBJS)

sort.o: sort.c 
	gcc -c sort.c 
main.o: main.c 
	gcc -c main.c