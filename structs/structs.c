#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
// C requires importing system / header files 

// NOTES:
// Struct:

// Grouping related pieces of data you have used:
// - arrays (lists) 
// 	- but something that is limiting about arrays is that they can only hold the same type of data. arrays are great for holding many pieces of data that are the same type. 
// - objects
// 	- can group related pieces of data, regardless of the type. So, objects take care of some things that arrays are not able to do, BUT they dont exist in C programming language. 
// To solve this problem in C we use something called: Struct. Which is short for structure. Here is a sample struct that is used to model a pet:
// struct Pet {
// 	char[ 20 ] name;
// 	char [ 20 ] breed;
// 	int age;
// } pet;

// In this struct we have mixed different types and we have included a name, breed, age and you could add even more attributes to the struct if you would like. This is just a short and sweet example of what a struct looks like. 
// We know that is is modeling a pet because we used the optional structure tag "Pet". The structure tag makes it more readable but if you are creating a struct that you are going to only use one time you might not want to include a tag because you won't have to refer to it later on. But it is never a bad idea to include a tag. Also, you have the option to create an instance of your struct when you define it and that would be the pet; at the end. It is an instance of struct and this is also optional and you can include this late in other parts of your code. The biggest component here is our keyword struct. 
// But how do we USE member variable of our struct?
// To do this we use something you may have used other places and that is Dot Notation. 
// Defining a struct:
// typedef struct Pet { // creating struct for Pet
// 	char[ 20 ] name;
// 	char [ 20 ] breed;
// 	int age;
// } ;

// Pet pet; // instance of Pet. If you include typedef keyword before struct when creating is you only need Pet pet; here

// int main( ) {
// 	strycpy( pet.name, "Kelli");
// 	strycpy( pet.breed, "Golden Retriever");
// 	pet.age = 14;
// 	printf("Pet's name: %s\n", pet.name); // These are strings %s
// 	printf("Pet's breed: %s\n", pet.breed);
// 	printf("Pet's age: %d\n", pet.age); // This is integer for age %d

// }

// So, we use structs to model more complex things that has mix of types that can't all go into one array. We can create structs and then create functions that return those different structs. So they are an acceptable return type. You can pass structs as arguments as well. And we can use them to create our own custom data types to handle different situations. 

// To sum it all up, 
// 	- the C programming language doesn't have Objects like JS or Python.
// 	- BUT we can use structs to model pieces of data that need multiple variables of different types to represent them!

// Remember!:
// gcc -o structs structs.c
// ./structs
// You can add -g -Wall for debugging purposes 
// gcc -Wall -Wextra -o structs structs.c

/* 
    Define the Person struct by specifying the fields that make up the
    Person type. Don't forget to specify the type of each field. A 
    Person should have the fields `name`, `age`, `height`, and `weight`.
*/

typedef struct Person { // Person struct (structure) to group related pieces of data, regardless of the type using typedef when creating it so make it easier to call it later in code.
    char *name; // Name field char for a string
    int age; // Age field int for integer 
    int height; // Height field int for integer 
    int weight; // Weight field int for integer 
} Person;

/*
    Creates an instance of the Person struct that receives all the relevant
    pieces of data associated with a Person instance.
    Allocates the appropriate amount of memory to hold an instance of the 
    Person struct, and then sets the struct's fields with the input data.
    When setting the `name` field, use your previously-built string_dup
    function, which handles the allocation of memory for the new string.
*/
Person *createPerson(char *name, int age, int height, int weight) //Creates an instance of the Person struct that receives all the relevant pieces of data associated with a Person instance.
{
    
    Person *person = malloc(sizeof(Person)); // Allocates the appropriate amount of memory to hold an instance of the Person struct
    person->name = string_dup(name); // When setting the `name` field, use your previously-built string_dup function, which handles the allocation of memory for the new string.
    person->age = age; // Use a dot notation when you have variable inside the struct and you use the arrow when you have a pointer to the struct
    person->height = height;
    person->weight = weight;

    return person;
}

/*
    Given a pointer to a Person struct, frees up the memory that holds the
    Person's name as well as the memory that holds the Person instance.
*/
void destroyPerson(Person *who)
{
    free(who->name); // Frees up the memory that holds the Person's name.
    free(who); // Frees up the memory that holds the Person's instance.
}

#ifndef TESTING
int main(void)
{
    Person *tony = createPerson("Tony Stark", 32, 64, 140);

    printf("  Name: %s\n", tony->name);
    printf("   Age: %d\n", tony->age);
    printf("Height: %d\n", tony->height);
    printf("Weight: %d\n", tony->weight);

    destroyPerson(tony);

    return 0;
}
#endif