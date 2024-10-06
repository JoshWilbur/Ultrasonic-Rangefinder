# Compiler choice and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Source and header files
SRCS = main.c PWM_setup.c display.c
OBJS = $(SRCS:.c=.o)

# Output executable name
EXEC = US_range

# Make process
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJS)

