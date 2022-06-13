CC = g++

LDFLAGS = -lpthread

#CLIENT = socketclient.cpp

#SERVER = socketsever.cpp

all: socketsever socketclient

socketclient: socketclient.o
		$(CC) $^ $(LDFLAGS) -o $@

socketsever: socketsever.o
		$(CC) $^ $(LDFLAGS) -o $@

clean:
		rm -f *.o
