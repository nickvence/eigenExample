P=vec
OBJECTS=
CFLAGS =-I/usr/local/include/eigen3 -g -Wall -O1
LDLIBS=
CC= g++

$(P): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $@.cc
