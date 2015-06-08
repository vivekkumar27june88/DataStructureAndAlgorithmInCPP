CC=g++
CFLAGS=-c -Wall -std=c++11 -g
LDFLAGS=
SOURCES=main.cpp
HEADERS=binary-heap.h utils.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=dsa.exe

all: $(SOURCES) $(EXECUTABLE)
	    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o: $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

run: $(EXECUTABLE)
	./$(EXECUTABLE)
