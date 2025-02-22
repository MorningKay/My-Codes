CC = gcc
CFLAGS = -Wall -g -O2

PROJECT_SRCS = SList.c Main.c
PROJECT_OBJS = $(PROJECT_SRCS:.c=.o)
PROJECT_TARGET = SList

$(PROJECT_TARGET):$(COMMON_OBJS1) $(PROJECT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PROJECT_TARGET) $(PROJECT_OBJS)

.PHONY: clean