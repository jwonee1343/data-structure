CC := gcc

SRCS := test/main.c
INCS := .

ifdef DEBUG
CFLAGS := -g
else
CFLAGS :=
endif

ifdef LOGALL
Q :=
else
Q := @
endif

default: $(SRCS:%.c=obj/%.o)
	$(CC) -o bin/test $? $(INCS:%=-I%) $(CFLAGS)

obj/%.o: %.c
	$(CC) -o $@ -c $< $(INCS:%=-I%) $(CFLAGS)

clean:
	rm $(SRCS:%.c=obj/%.o)
	rm bin/test

