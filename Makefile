CC = cc -c
CFLAGS =
LINKEAR  = cc


all: simutransusb

# prompt: prompt.o
# 	$(CC) $(CFLAGS) -o prompt prompt.o hashtable.o

# prompt.o: hashtable
# 	$(CC) $(CFLAGS) -c prompt.c

# hashtable: hashtable.o
# 	$(CC) $(CFLAGS) -c hashtable.c hashtable.h

# hashtable.o:
# 	$(CC) $(CFLAGS) -o hashtable hashtable.h

OBJETOS  = readFile.o simutransusb.o 

simutransusb: $(OBJETOS)
	$(LINKEAR) $(OBJETOS) -o simutransusb

simutransusb.o: simutransusb.c
	$(CC) simutransusb.c -o simutransusb.o

readFile.o : readFile.c readFile.h
	$(CC) readFile.c -o readFile.o

clean:
	rm *.o simutransusb