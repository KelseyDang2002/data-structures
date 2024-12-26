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
Array display_array(Array arr) {
    printf("\nCurrent Array = [");

    for (int i = 0; i < arr.size; i++) {
        printf("%d", arr.data[i]);

        // last element does not have a comma after
        if (i < arr.size - 1) {
            printf(", ");
        }
    }
    
    printf("]\n");
}

// TODO
Array insert_element_end();

// TODO
Array insert_element_beginning();

// TODO
Array search_element();

// TODO
Array delete_element();

int main(int argc, char* argv[]) {
    // command line arguments
    printf("Program name: %s\n\n", argv[0]);

    // file execution in command line
    if (argc == 1) {
        printf("No command line arguments passed.\n");
        return 0;
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

    free(arr.data); // free - deallocate memory that was previously allocated
    return 0;
}
