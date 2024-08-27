#include <stdio.h>
#include <cs50.h>

// HELLO WORLD!
int main (int argc, char** argv) {
    string name = get_string("What's your name? ");
    printf("Hello %s!\n", name);
    return 0;
}
