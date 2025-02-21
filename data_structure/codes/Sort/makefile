CC = g++
# CC = x86_64-w64-mingw32-g++
CFLAGS = -Wall -g -O2

PROJECT_SRCS = main.cpp SList.cpp
PROJECT_OBJS = $(PROJECT_SRCS:.cpp=.o)
PROJECT_TARGET = Sort

$(PROJECT_TARGET):$(COMMON_OBJS1) $(PROJECT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PROJECT_TARGET) $(PROJECT_OBJS)

.PHONY: clean