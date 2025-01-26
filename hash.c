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
    char* key;         // key
    char* data;        // value or data associated with a certain key
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
    int capacity;        // capacity of the hash map (number of buckets)
    int currNumElements; // current number of elements in the hash map
    struct Node** arr;   // pointer to a pointer to the array of the linked list
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
    for (int i = 0; i < strlen(key); i++) {
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
void insert(struct HashMap* map, char* key, char* data) {
    // perform hash function on element key to get index and store into bucket
    int bucketIndex = hashFunction(map, key);

    printf("Inserting key '%s' with data '%s'.\n", key, data);

    // create new node to store the key-value pair
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    // init the value of the new node
    // newNode->next is NULL since it is initially not connected to any other node
    initNode(newNode, key, data);

    // if the bucket at index is empty/available, store the new node
    if (map->arr[bucketIndex] == NULL) {
        map->arr[bucketIndex] = newNode;
    }
    else {
        // if there is a collision
        newNode->next = map->arr[bucketIndex]; // link new node to existing list at the bucket
        map->arr[bucketIndex] = newNode; // make new node the head of linked list at the bucket index
    }

    return;
}

/*
method to delete data from hash map
*/
void delete(struct HashMap* map, char* key) {
    //
}

/*
method to search for data in the hash map
*/
char* search(struct HashMap* map, char* key) {
    // get bucket index for the given key
    int bucketIndex = hashFunction(map, key);

    // assign head of linked list at bucket index to new variable
    struct Node* bucketHead = map->arr[bucketIndex];

    while (bucketHead != NULL) {
        // key is found at the bucket (head of the linked list)
        if (bucketHead->key == key) {
            return bucketHead->data;
        }

        bucketHead = bucketHead->next; // if not at bucket, go to next bucket
    }

    // if no key is found in hash map
    char* errorMsg = (char*)malloc(sizeof(char) * 25);
    errorMsg = "Oops! No data found.\n";
    return errorMsg;
}

// main
int main(int argc, char* argv[]) {
    // init hash map
    struct HashMap* map = (struct HashMap*)malloc(sizeof(struct HashMap));
    initHashMap(map);

    // insert key-value pairs into hash map
    insert(map, "username", "Kelsey");
    insert(map, "age", "22");
    insert(map, "role", "user");

    // find data associated with keys
    printf("Data: %s\n", search(map, "username"));
    printf("Data: %s\n", search(map, "age"));
    printf("Data: %s\n", search(map, "role"));

    return 0;
}
