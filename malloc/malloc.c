#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
// C requires importing system / header files 

// NOTES:
// Memory Allocation:
// Which means you will be creating a block of memory that is the specific size that you will want it to be. 
// We do this with a function called Malloc.
// Malloc uses a parameter that indicates how much memory the user wants. in bytes.
// It also find a contiguous spot in memory that satisfies the size criteria. 
// And then it will return a pointer to the first spot of the allocated block. So it will point to the first address space in that block of memory. 
// // create a pointer to a block of memory that is big enough to hold 100 integers:
// int *100_ints = malloc(100 * sizeof(int));
// // fill in the empty block of memory
// for (int i = 0; i < 100; i++) {
// // put a rondom int in the ith slot
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


/*
    Duplicates the input string by dynamically allocating memory for 
    the duplicate string using `malloc` and then copying the string
    into the allocated memory. Returns a pointer to the allocated memory.
    You may want to use the string_length function to figure out the
    length of the input string.
*/
char *string_dup(char *src)
{

}

/*
    A generic version of string_copy, mem_copy receives a block of memory
    of any type and copies its contents to the destination pointer (dest).
    You may want to cast the input pointers to char pointers first before
    performing the copying. `n` is the amount of data that should be copied
    from `src` to `dest`. 
*/
void mem_copy(void *dest, const void *src, int n)
{

}

/*
    Given a pointer of `malloc`'d memory, this function will 
    attempt to resize the allocated memory to the new specified
    size. Any data that was previously in the old `malloc`'d 
    memory should be intact in the new resized block of memory. 
    Some edge cases to consider: how should resizing be handled
    in the case when old_size < new_size? What about when 
    old_size > new_size?
    
    Do not use the `realloc` function from the standard libary.
*/
void *resize_memory(void *ptr, int old_size, int new_size)
{

}

#ifndef TESTING
int main(void)
{
    char *s = "Some string to duplicate.";
    char *dup = string_dup(s);

    printf("Duplicated string: %s\n", dup);

    int numbers[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int *target = malloc(n * sizeof(int));
    
    mem_copy(target, numbers, n * sizeof(int));

    printf("Copied array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", target[i]);
    }

    printf("\n");

    char *url = string_dup("http://lambdaschool.com");
    char *path = string_dup("/students/");
    int url_length = string_length(url);
    int path_length = string_length(path);
    
    int new_length = url_length - 1 + path_length;
    char *new_url = resize_memory(url, url_length, new_length);
    char *p = new_url + url_length;

    while (*path != '\0') {
        *p = *path;
        p++;
        path++;
    }

    printf("Full path string: %s\n", new_url);

    return 0;
}
#endif