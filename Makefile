CC = clang
CFLAGS = -std=c17 -Wall -Wextra

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

NAME = Program

all: exe

run: all
	./$(NAME).exe

exe: $(OBJ)
	$(CC) -o $(NAME).exe $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	del /Q /S *.o