CC= gcc

CCFLAGS= -O2 $(MYCCFLAGS)
LDFLAGS= -pthread $(MYLDFLAGS)
PPFLAGS= $(MYPPFLAGS)

SOURCES= $(wildcard *.c)
HEADERS= $(wildcard *.h)
OBJECTS= $(SOURCES:%.c=%.o)
OUT= tptmpd

all: tptmpd

%.o: %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CCFLAGS) $(PPFLAGS)

tptmpd: $(OBJECTS)
	$(CC) -o $(OUT) $(OBJECTS) $(LDFLAGS)

clean: 
	rm -f $(OUT) $(OBJECTS)

.PHONY: all clean
