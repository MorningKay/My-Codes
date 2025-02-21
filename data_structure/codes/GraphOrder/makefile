CC = g++
CFLAGS = -Wall -g -O2

PROJECT_SRCS = GraphOrder.cpp LinkQueue.cpp main.cpp
PROJECT_OBJS = $(PROJECT_SRCS:.cpp=.o)
PROJECT_TARGET = GraphOrder

$(PROJECT_TARGET):$(COMMON_OBJS1) $(PROJECT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PROJECT_TARGET) $(PROJECT_OBJS)

.PHONY: clean