#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAPACITY 100

/*
this is using the separate chaining approach for the hash map
hash map allows keys or values to be NULL
hash table does not

so we need a linked list data structure
linked list node struct for the items to be stored in the hash
*/ 
typedef struct Node {
    char* key; // key
    char* data; // value or data associated with a certain key
    struct Node* next; // pointer to next node (address of next node)
} Node;

// node constructor
struct Node* initNode(struct Node* node, char* key, char* data) {};

// hash map data structure
typedef struct HashMap {
    int capacity; // capacity of the hash map (number of buckets)
    int currNumElements; // current number of elements in the hash map
    struct Node** arr; // pointer to a pointer to the array of the linked list
} HashMap;

// hash map constructor
struct HashMap* initHashMap(struct HashMap* map) {};

/*
method to compute the index with a hash function

this returns a bucket index based on the input key
*/
int hashFunction(struct hashMap* map, char* key) {};

/*
method to insert data into hash map
*/
void insert(struct hashMap* map, char* key, char* data) {};

/*
method to delete data from hash map
*/
void delete(struct hashMap* map, char* key) {};

/*
method to search for data in the hash map
*/
char* search(struct hashMap* map, char* key) {};

// main
int main(int argc, char* argv[]) {
    
    return 0;
}
