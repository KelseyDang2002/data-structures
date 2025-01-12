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
struct Node* initNode(struct Node* node, char* key, char* data) {
    node->key = key;
    node->data = data;
    
    // set next ptr to NULL since initially it is not pointing to any other node yet
    node->next = NULL;
    return;
}

// hash map data structure
typedef struct HashMap {
    int capacity; // capacity of the hash map (number of buckets)
    int currNumElements; // current number of elements in the hash map
    struct Node** arr; // pointer to a pointer to the array of the linked list
} HashMap;

// hash map constructor
struct HashMap* initHashMap(struct HashMap* map) {
    map->capacity = MAX_CAPACITY; // capacity of the hash map
    map->currNumElements = 0;

    /*
    array of size 1

    allocate memory for the array of pointers that represent the hash map's buckets
    struct Node** - an array of pointers to Node struct, each pointer represents the head
                    of a linked list for a bucket
    sizeof(struct Node*) - size of a single pointer to a Node
    map->capacity - total number of buckets in the hash map
    malloc() - allocates enough memory for all bucket pointers
    */
    map->arr = (struct Node**)malloc(sizeof(struct Node*) * map->capacity);
    return;
}

/*
method to compute the index with a hash function

this returns a bucket index based on the input key
*/
int hashFunction(struct HashMap* map, char* key) {
    int bucketIndex;

    // accumulates the hash values as the function iterates through the characters of the key
    int sum = 0;

    /*
    a multiplier that gives higher weight to characters at later positions in the string
    initialized to 31, a commonly used small prime number in hash functions 
    */
    int factor = 31;

    // loop through each character of the key string
    for(int i = 0; i < strlen(key); i++) {
        /*
        update sum

        sum = sum + (ascii value of char * (primeNumber ^ x))...
        where x = 1, 2, 3 ... n
        */
        sum = ((sum % map->capacity) + (((int)key[i]) * factor) % map->capacity) % map->capacity;

        /*
        update factor

        factor = factor * prime number...(prime number) ^ x
        */
        factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
    }

    bucketIndex = sum; // assign final computed hash value to bucket index
    return bucketIndex;
}

/*
method to insert data into hash map
*/
void insert(struct HashMap* map, char* key, char* data) {};

/*
method to delete data from hash map
*/
void delete(struct HashMap* map, char* key) {};

/*
method to search for data in the hash map
*/
char* search(struct HashMap* map, char* key) {};

// main
int main(int argc, char* argv[]) {
    
    return 0;
}
