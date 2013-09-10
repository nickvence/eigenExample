OBJECTS=
CFLAGS =-I/usr/local/include/eigen3 -I/opt/local/include/cairo -g -Wall -O1
LDLIBS = -L/opt/local/lib -lcairo
CC= g++

vec: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $@.cc

cairo: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $@ $@.cc
