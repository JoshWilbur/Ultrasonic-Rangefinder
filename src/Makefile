# Compiler choice and flags
CC = gcc
CFLAGS = -Wall -Wextra -g -lrt -lpigpio -Iinc

# Source and header files
SRCS = main.c display.c range.c
OBJS = $(SRCS:.c=.o)

# Output executable name
EXEC = US_range

# Make process
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJS)

