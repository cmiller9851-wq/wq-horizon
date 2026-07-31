CC = gcc
CFLAGS = -Wall -Wextra -O3 -Iinclude -std=c11
TARGET = libgagp_substrate.a

SRCS = src/gagp_hardware_gate.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	ar rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)
