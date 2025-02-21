.PHONY: clean
CFLAGS = -Wall -g -O2
targets = SCList
sources = SCList.c Main.c
objects = SCList.o Main.o

$(targets): $(objects)
	gcc $(CFLAGS) $(objects) -o $@

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o SCList