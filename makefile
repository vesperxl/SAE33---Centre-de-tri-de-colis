CC      = gcc
CFLAGS  = -Wall -Wextra -g
HEADERS = common.h tri.h

MAIN_SRC = main.c
##TRI_SRC  = tri.c  
##AFF_SRC  = affichage.c

MAIN_OBJ = $(MAIN_SRC:.c=.o)
TRI_OBJ  = $(TRI_SRC:.c=.o)
AFF_OBJ  = $(AFF_SRC:.c=.o)

all: main tri affichage

main: $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

tri: $(TRI_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -pthread

affichage: $(AFF_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main tri affichage

distclean: clean
	rm -f /tmp/*.pid /tmp/fifo_* *.log

.PHONY: all clean distclean