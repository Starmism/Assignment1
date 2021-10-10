#include <stdio.h>
#include <string.h>
#include <ctype.h>

int testPalindrome(char string[]);

/*
 * (15 points) A palindrome is a string that’s spelled the same way forward and backward.
 * Some examples of palindromes are: “radar,” “able was i ere i saw elba,”
 * and, if you ignore blanks, “a man a plan a canal panama.”
 *
 * Write a recursive function testPalindrome that returns 1 if the string
 * stored in the array is a palindrome and 0 otherwise.
 * The function should ignore spaces and punctuation in the string.
 */
int main() {
    char test1[] = "radar";
    char test2[] = "able was i ere i saw elba";
    char test3[] = "a man a ?plan a !canal panama!";
    printf("%s - %d\n", test1, testPalindrome(test1));
    printf("%s - %d\n", test2, testPalindrome(test2));
    printf("%s - %d\n", test3, testPalindrome(test3));

    return 0;
}

int palindromeRecursive(char string[], int start, int end) {
    if (start == end) {
        return 1;
    }

    if (string[start] != string[end]) {
        return 0;
    }

    if (start < end + 1) {
        return palindromeRecursive(string, start + 1, end - 1);
    }

    return 1;
}

int testPalindrome(char string[]) {
    int len = (int) strlen(string);

    if (len == 0) {
        return 1;
    }

    char strOnlyAlpha[len + 1];
    int alphaLen = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(string[i])) {
            strOnlyAlpha[alphaLen] = string[i];
            alphaLen++;
        }
    }
    // Set all remaining characters to null
    memset(strOnlyAlpha + (alphaLen * sizeof(char)), 0, (len - alphaLen + 1) * sizeof(char));

    return palindromeRecursive(strOnlyAlpha, 0, alphaLen - 1);
}
