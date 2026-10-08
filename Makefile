CC = gcc
CFLAGS  = -Wall -Wextra -std=c11 -Iincludes
TARGET  = main.exe
SRC = $(wildcard src/*.c src/*/*.c)
OBJ = $(SRC:.c=.o)
DEPS = $(wildcard includes/*.h includes/*/*.h)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	.\$(TARGET)

clean:
	-del /Q $(TARGET) $(subst /,\,$(OBJ))

.PHONY: all run clean
