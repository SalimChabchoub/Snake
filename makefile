
CC=gcc
CFLAGS=-lncurses
LDFALGS =-lncurses
EXEC= main2
SNAKE = serpent
APPLE = pomme
WORLD = monde
BOXE = case
GRAPH = graphe


HEADERS = $(BOXE).h $(APPLE).h $(SNAKE).h $(WORLD).h $(GRAPH).h
OBJECTS = $(EXEC).o $(BOXE).o $(APPLE).o $(SNAKE).o $(WORLD).o $(GRAPH).o

default: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^ $(CFLAGS)

%.o: %.c $(HEADERS)
	$(CC) $(LDFLAGS) -c -o $@ $< $(CFLAGS)

prog: $(EXEC)
	./$(EXEC)



clean:
	-rm -f $(OBJECTS)
	-rm -f $(EXEC)
