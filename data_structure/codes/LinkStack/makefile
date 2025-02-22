.PHONY: clean
CFLAGS = -Wall -g -O2
targets = LinkStack
sources = LinkStack.c main.c
objects = LinkStack.o main.o

$(targets): $(objects)
	gcc $(CFLAGS) $(objects) -o $@

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o LinkStack