CC= gcc
LIBS= -L../lib -llog -lpthread
LFAGS= -Wl,-rpath,'$$ORIGIN/../lib'

######### Files

SOURCES= main.c \
		 queue.c \
		 queue_internal.c\
		 event.c\
		 time.c

OBJECTS= obj/main.o\
		 obj/queue.o\
		 obj/queue_internal.o\
		 obj/event.o\
		 obj/time.o

TARGET= ../bin/Test


######### Compile
$(TARGET):$(OBJECTS)
	$(CC) $(LFAGS) -o $(TARGET)  $(OBJECTS) $(LIBS)

obj/main.o: main.c
	$(CC) -c -o obj/main.o main.c
obj/queue.o: queue.c
	$(CC) -c -o obj/queue.o queue.c
obj/queue_internal.o: queue_internal.c
	$(CC) -c -o obj/queue_internal.o queue_internal.c
obj/event.o: event.c
	$(CC) -c -o obj/event.o event.c
obj/time.o: time.c
	$(CC) -c -o obj/time.o time.c



######### Clean
clean:
	rm $(OBJECTS) $(TARGET)
