.PHONY: clean
CFLAGS = -Wall -g -O2
targets = Dlist
sources = Dlist.c Main.c
objects = Dlist.o Main.o

$(targets): $(objects)
	gcc $(CFLAGS) $(objects) -o $@

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o Dlist