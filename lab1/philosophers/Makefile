DDIR421=/clear/courses/comp421/lab1

INCLUDES = -I$(DDIR421)/include
LIBS = $(DDIR421)/lib/liblab1.a
CPPFLAGS = $(INCLUDES)
CFLAGS = -pthread -Wall

all: philosopher

philosopher: philosopher.o philmain.o
	$(CC) $(CFLAGS) -o philosopher $(LDFLAGS) \
		philosopher.o philmain.o $(LIBS)


clean:
	rm -f philosopher philosopher.o philmain.o
