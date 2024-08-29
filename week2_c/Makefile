CC= clang
CFLAGS = -ferror-limit=1 -gdwarf-4 -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
LDLIBS = -lcs50 -lm

# scrabble
SCRABBLE_SRCS = scrabble.c
SCRABBLE_OBJS = $(SCRABBLE_SRCS:.c=.o)

scrabble: $(SCRABBLE_OBJS)
	$(CC) $(CFLAGS) -o $@ $(SCRABBLE_OBJS) $(LDLIBS)