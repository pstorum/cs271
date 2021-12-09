CC = gcc
CFLAGS = -Wall -I.
LDFLAGS = 
OBJFILES = main.c parser.c symtable.c error.c
TARGET = main.o

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~