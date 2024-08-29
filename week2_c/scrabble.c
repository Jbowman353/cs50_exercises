#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// scores for each letter, a = index 0, b = index 1, etc
const int LETTER_SCORES[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// gets score for a string s, counting only letters (other characters will be ignored)
int get_word_score(string s) {
    int len = strlen(s);
    int score = 0;

    for (int i = 0, n = strlen(s); i < n; i++) {
        char lowerChar = tolower(s[i]); // to simplify letter score indexing
        if (lowerChar >= 'a' && lowerChar <= 'z') { // only get scores for letters, not other chars
            score += LETTER_SCORES[lowerChar - 'a'];
        }
    }

    return score;
}

int main (void) {
    // Prompt user for player inputs
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");
    
    // Get player scores
    int p1Score = get_word_score(p1);
    int p2Score = get_word_score(p2);

    // Compare scores and print results!
    if (p1Score > p2Score) {
        printf("Player 1 wins!\n");
    } else if (p2Score > p1Score) { 
        printf("Player 2 wins!\n");
    } else {
        printf("TIE!\n");
    }
    return 0;
}