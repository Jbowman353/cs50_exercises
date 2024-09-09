#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

// index = 0.0588 * L - 0.296 * S - 15.8
// L = avg number of letters per 100 words
// S = avg number of sentences per 100 words

int count_words(string input);
int count_letters(string input);
int count_sentences(string input);

int main (void) {
    string inputText = get_string("Text: ");
    
    int totalWords = count_words(inputText);
    int totalLetters = count_letters(inputText);
    int totalSentences = count_sentences(inputText);

    printf("# Letters: %i\n", totalLetters);
    printf("# Words: %i\n", totalWords);
    printf("# Sentences: %i\n", totalSentences);

    float grade = round(0.0588 * (100.0 * totalLetters / totalWords) - 0.296 * (100.0 * totalSentences / totalWords) - 15.8);

    if (grade >= 16) {
        printf("GRADE 16+\n");
    } else {
        printf("GRADE %i\n", (int) grade);
    }

    return 0;

}

// Per instructions, consider any sequence of characters separated by a space to be a word
int count_words(string input) {
    int words = 0;
    bool newWord = true;
    for (int i = 0, n = strlen(input); i < n; i++) {
        if (isalpha(input[i]) && newWord) {
            words++;
            newWord = false;
        } else if (input[i] == ' ') {
            newWord = true;
        }
    }
    return words;
}

int count_letters(string input) {
    int letters = 0;
    for (int i = 0, n = strlen(input); i < n; i++) {
        if (isalpha(input[i])) {
            letters += 1;
        }
    }
    return letters;
}

// 
int count_sentences(string input) {
    int sentences = 0;
    bool newSentence = true;
    for (int i = 0, n = strlen(input); i < n; i++) {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!'){
            newSentence = true;
        } else if (newSentence && isalnum(input[i])) {
            newSentence = false;
            sentences++;
        }
    }
    return sentences;
}