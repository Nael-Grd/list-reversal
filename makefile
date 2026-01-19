CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = src/list.c src/main.c
OBJ = $(SRC:.c=.o)
TARGET = main

FRAMAC = frama-c
WP_FLAGS = -wp -wp-rte -wp-smoke-tests -wp-prover alt-ergo

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

proof:
	$(FRAMAC) $(WP_FLAGS) include/list.h src/list.c

clean:
	rm -f $(TARGET) src/*.o
	rm -rf .frama-c *.jessie *.wp

.PHONY: all proof clean