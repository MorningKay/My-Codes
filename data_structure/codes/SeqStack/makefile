.PHONY: clean
CFLAGS = -Wall -g -O2
targets = SeqStack
sources = SeqStack.c Main.c
objects = SeqStack.o Main.o

$(targets): $(objects)
	gcc $(CFLAGS) $(objects) -o $@

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o SeqStack