#include <stdio.h>
#include <cs50.h>

int main(void) {
    int height;
    // check to make sure input is > 0
    do {
        height = get_int("How tall is the pyramid? ");
    } while (height <= 0);
    
    const int width = (height * 2) + 2;

    // print rows of # based on input 
    for (int i = 0; i < height; i++) {
        // total number of characters printed for each row is equal to the width
        for(int j = 0; j < width; j++) {
            // print outer spaces and middle spaces
            if (j < height - i - 1 || j > height + 2 + i || j == height || j == height + 1) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }

    // Alternative, possibly easier to follow but more lines
    // // print rows of #
    // for(int i = 0; i < height; i++) {
    //     // print a number of spaces equal to the height minus the row you're in
    //     for (int leftSpaces = 0; leftSpaces < height - i; leftSpaces++) {
    //         printf(" ");
    //     }

    //     // print a number of #s equal to the index of the row + 1
    //     for (int leftChecks = 0; leftChecks <= i; leftChecks++) {
    //         printf("#");
    //     }

    //     // always print two spaces in the middle
    //     printf("  ");

    //     // print a number of #s equal to the index of the row + 1
    //     for (int rightChecks = 0; rightChecks <= i; rightChecks++) {
    //         printf("#");
    //     }

    //     // print a number of spaces equal to the height minus the row you're in
    //     for (int rightSpaces = 0; rightSpaces < height - i; rightSpaces++) {
    //         printf(" ");
    //     }
    //     printf("\n");
    // }

    return 0;
}