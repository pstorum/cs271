CC = gcc
CFLAGS = -Wall -I.
LDFLAGS = 
OBJFILES = main.c symtable.c
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~