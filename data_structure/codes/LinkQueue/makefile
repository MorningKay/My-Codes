CC = gcc
CFLAGS = -Wall -g -O2

PROJECT_SRCS = LinkQueue.c main.c
PROJECT_OBJS = $(PROJECT_SRCS:.c=.o)
PROJECT_TARGET = LinkQueue

$(PROJECT_TARGET):$(COMMON_OBJS1) $(PROJECT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PROJECT_TARGET) *.o

.PHONY: clean
