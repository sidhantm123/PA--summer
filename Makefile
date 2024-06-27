CC = gcc
CFLAGS = -g -std=c11
EXEUCTABLE = pa1
SRC_C = main.c

default: $(EXEUCTABLE)

$(EXEUCTABLE): $(SRC_C)
	$(CC) -o $(EXEUCTABLE) $(SRC_C) $(CFLAGS)

run: 
	./$(EXEUCTABLE)