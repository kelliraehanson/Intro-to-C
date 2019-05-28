#include <stdio.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/

// NOTES:
// Pointers are references to the address of a variable, rather than its value. 
// They are useful when working with dynamically-sized data.
// Pointer Arithmetic:
// increment to access which means if you want to do something with the second number in your array and not just the first you have to access that with a pointer.
// - subsequent slots in an array
// - the next char in a string 
// Here is an example of what this will actually look like:
// char *str = "Hello world!";
// 	printf("%c\n", *str);
// So the pointer to the str is going to represent the address and not the value.  This will print the first letter of this string. 
// But if you want to print the second letter you do this:
// printf("%c\n, *(str + 1));
// keep in mind dereference operator * takes precedence over arithmetic operations ( adding subtracting etc), hence the parentheses. 
// The other operation that you will find helpful:
// Memory Allocation:
// Which means you will be creating a block of memory that is the specific size that you will want it to be. 
// We do this with a function called Malloc.
// Malloc uses a parameter that indicates how much memory the user wants. in bytes.
// It also find a contiguous spot in memory that satisfies the size criteria. 
// And then it will return a pointer to the first spot of the allocated block. So it will point to the first address space in that block of memory. 
// // create a pointer to a block of memory that is big enough to hold 100 integers:
// int *100_ints = malloc(100 * sizeof(int));
// fill in the empty block of memory
// for (int i = 0; i < 100; i++) {
// put a rondom int in the ith slot
// *(100_ints+i) = rand();
// you don't have to use pointers when working with integers of a big size but potentially it will be useful.
// One way to pass parameters to functions:
// pass by value
// - parameter is a copy of a value of a specific variable
// - must return new value to retain changes outside scope of function
// passing pointer to functions:
// pass by reference 
// - parameter is a pointer
// - cheaper if we are working with large arrays/strings/objects
// - muted thing retains those updates outside the scope of the function
// example - print out a long string:
// void print_long_str(int *str, int len) {
// for (int i = 0; i < len: i++) {
// 	printf("%c, *(str + i));
// 	}
// } 

void string_copy(char *x, char *y)
{

}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{

}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{

}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
