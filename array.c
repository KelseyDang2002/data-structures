#include <stdio.h>
#include <stdlib.h>

// array class
typedef struct Array {
    int *data; // array data (integers)
    int size; // size of array
} Array;

// method to create array
Array create_array(int size) {
    Array arr;
    arr.data = (int*)malloc(size * sizeof(int));
    arr.size = size;
    return arr;
}

// method to display current array
void display_array(Array arr) {
    printf("\nCurrent Array = [");

    for (int i = 0; i < arr.size; i++) {
        printf("%d", arr.data[i]);

        // add comma after element except if it is the last element
        if (i < arr.size - 1) {
            printf(", ");
        }
    }
    
    printf("]\n");
}

/* 
method to insert an element at a specific index in the array

Insert element at the end:
    Time Complexity: O(1) (Amortized)
    Space Complexity: O(1)
    Inserting an element at the end of a 1D array usually involves updating
    the array's size and placing the new element in the next available position,
    which is constant-time operation on average.

Insert element at the beginning/specific index:
    Time Complexity: O(n)
    Space Complexity: O(n)
    Inserting an element at the beginning of a 1D array requires shifting all
    exisitng elements to make room, resulting in a linear time and space complexity.
*/
void insert_element(Array *arr, int index, int value) {
    // valid range: 0 <= index <= array size
    if (index >= 0 && index <= arr->size) {
        printf("\nInserting %d at index %d.", value, index);
        
        /*
        realloc - reallocate memory by expanding the array by 1
        arr->size + 1 is the new size of the array
        sizeof(int) is the size of each cell in the array
        int* - ensures type compatibility
        */
        arr->data = (int*)realloc(arr->data, (arr->size + 1) * sizeof(int));

        /*
        shift all exisitng elements to the right to create space for new element at index
        loop starts at the last element arr->size and moves backward to the index
        copies the element at i - 1 to position i, shifting all elements to the right by one
        */
        for (int i = arr->size; i > index; i--) {
            arr->data[i] = arr->data[i - 1];
        }

        arr->data[index] = value; // insert new value at specified index
        arr->size++; // update size of the array by 1
    }

    else {
        printf("\nInvalid index.");
    }
}

/*
method to return the index of a specific element in the array

Searching for an element (linear search):
    Time Complexity: O(n)
    Space Complexity: O(1)
    In the worst case, searching for an element in a 1D array may require looking at
    every element, resulting in a linear time complexity. The space complexity remains constant.

Accessing an element by index:
    Time Complexity: O(1)
    Space Complexity: O(1)
    Accessing an element on a 1D array by its index is typically a constant-time
    operation because it directly computes the memory location of the element.
*/
int search_element(Array arr, int value) {
    printf("\nIndex for %d: ", value);
    // loop through array
    for (int i = 0; i < arr.size; i++) {
        if (arr.data[i] == value) { // if value exists in the array
            return i; // return index of value
        }
    }
    return -1; // value not found
}

/*
method to delete element at a specific index in the current array

Deleting an element:
    Time Complexity: O(n)
    Space Complexity: O(1)
    In the worst case, deleting an element from the frint takes O(n) time as
    elements after an element should be shifted by one position.
*/
void delete_element(Array *arr, int index) {
    // valid range: 0 <= index <= array size
    if (index >= 0 && index <= arr->size) {
        printf("\nDeleting element at index %d\n", index);

        /*
        loop starts at index and copies element at i + 1 to i
        this fills the gap left by the deleted element
        */
        for (int i = index; i < arr->size - 1; i++) {
            arr->data[i] = arr->data[i + 1];
        }

        /*
        shrink size of array by 1 with realloc 
        arr->size - 1 is the new size of the array after removing one element
        */
        arr->data = (int*)realloc(arr->data, (arr->size - 1) * sizeof(int));
        arr->size--; // decrement size of array by 1
    }
}

// main
int main(int argc, char* argv[]) {
    // command line arguments
    printf("Program name: %s\n\n", argv[0]);

    // file execution in command line
    if (argc == 1) {
        printf("No command line arguments passed.\n");
    }

    // print command line args if more than 1 (includes execution)
    if (argc > 1) {
        printf("%d command line arguments passed.\n", argc);
        
        for (int i = 0; i < argc; i++) {
            printf("argv[%d]: %s\n", i, argv[i]);
        }
    }

    Array arr = create_array(5);
    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 4;
    arr.data[3] = 8;
    arr.data[4] = 16;
    
    display_array(arr);
    
    insert_element(&arr, 0, 0);
    insert_element(&arr, 6, 32);
    insert_element(&arr, 7, 64);
    display_array(arr);

    int index = search_element(arr, 16);
    printf("%d\n", index);

    delete_element(&arr, 2);
    display_array(arr);

    free(arr.data); // free - deallocate memory that was previously allocated
    return 0;
}
