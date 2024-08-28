CC= clang
CFLAGS = -ferror-limit=1 -gdwarf-4 -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
LDLIBS = -lcs50 -lm


# hello_name
HELLO_NAME_SRCS = hello_name.c
HELLO_NAME_OBJS = $(HELLO_NAME_SRCS:.c=.o)

hello_name: $(HELLO_NAME_OBJS)
	$(CC) $(CFLAGS) -o $@ $(HELLO_NAME_OBJS) $(LDLIBS)

# mario
MARIO_SRCS = mario.c
MARIO_OBJS = $(MARIO_SRCS:.c=.o)

mario: $(MARIO_OBJS)
	$(CC) $(CFLAGS) -o $@ $(MARIO_OBJS) $(LDLIBS)

# credit
CREDIT_SRCS = credit.c
CREDIT_OBJS = $(CREDIT_SRCS:.c=.o)

credit: $(CREDIT_OBJS)
	$(CC) $(CFLAGS) -o $@ $(CREDIT_OBJS) $(LDLIBS)