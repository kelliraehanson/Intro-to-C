#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s (as a pointer), return the number of 
    characters in the string.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char *s)
// A string in C is an array of char(character) in which the last char is null '\0'
// Null lets you know when the string is at it's end. This data structure will go until
// it finds it's end or '\0'.
{
    int length = 0;
    while (s[length] != '\0'){
        length++;
    }
    return length;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/

// Remember!:
// gcc -o strings strings.c
// ./strings
// You can add -g -Wall for debugging purposes 
// gcc -Wall -Wextra -o strings strings.c
char *reverse_string(char *rv, char *s)
{
    int length = string_length(s) - 1;
    int counter = 0;
    
    // In C you have an array data structure.
    // When you set it you have to declare the size and 
    // the type of data that will be displayed in that array.
    // This data structure will go backwards through the input array rv and
    // then the counter will go forward through s and assign value to the input array rv.
    for(int i = length; i >= 0; i--){
        rv[counter] = s[i];
        counter++;
    }

    // Terminates the reversed string with a null character
    rv[counter] = '\0';
    
    // Return the input array rv
    return rv;

}

#ifndef TESTING
int main(void)
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "a man a plan a canal panama";

    char rv[512];

    printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

    return 0;
}
#endif
    
