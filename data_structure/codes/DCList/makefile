.PHONY: clean
CFLAGS = -Wall -g -O2
targets = DCList
sources = DCList.c Main.c
objects = DCList.o Main.o

$(targets): $(objects)
	gcc $(CFLAGS) $(objects) -o $@

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o DCList