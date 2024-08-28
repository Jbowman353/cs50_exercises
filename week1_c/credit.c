#include <stdio.h>
#include <cs50.h>
#include <limits.h>

// Performs Luhn's calculations and check for card company
void checkLuhn(long cardNum) {
    string cardMSG = "INVALID"; // will be overwritten if number is verified
    // if card number is negative, automatically invalid
    if (cardNum > 0) {
        int numDigits = 0;
        int currentDigit = -1; // Will iterate across entirety of cardnum
        int prevDigit; // used for checking company
        long nextNum = cardNum;
        int sum = 0;

        do {
            prevDigit = currentDigit;
            currentDigit = nextNum % 10;
            numDigits += 1;
            if (numDigits % 2 == 0) { // even-indexed digits
                sum += ((currentDigit * 2) % 10) + ((currentDigit * 2) / 10); // multiply digit by 2, then add the digits of the result
            } else {
                sum += currentDigit;
            }
            nextNum = nextNum / 10;
        } while (nextNum > 0);

        // Check for validity and card company
        if (sum % 10 == 0) {
            // AMEX
            if (numDigits == 15 && currentDigit == 3 && (prevDigit == 4 || prevDigit == 7)) {
                cardMSG = "AMEX";
            // MASTERCARD
            } else if (numDigits == 16 && currentDigit == 5 && prevDigit > 0 && prevDigit < 6) {
                cardMSG = "MASTERCARD";
            // VISA
            } else if ((numDigits == 13 || numDigits == 16) && currentDigit == 4) {
                cardMSG = "VISA";
            }
        }
    }
    
    // Print card company or invalid
    printf("%s\n",cardMSG);

}

int main (void) {
    // Prompt user for card number
    long cardNum = get_long("Card Number: ");
    checkLuhn(cardNum);
    return 0;
}