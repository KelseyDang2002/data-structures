#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (HashItem*)(0xFFFFFFFFFFFFFFFFUL)

// class for items that the hash table will store
typedef struct HashItem {
    char name[MAX_NAME];
    int age;
} HashItem;

/*
hash table

array of pointers to HashTable struct
*/
HashItem* hashTable[TABLE_SIZE];

/*
method to compute the hash of the given input

hash function should return a valid index in the hash table
for each unique input, the hash function should produce a unique output associated with that input
should be consistent
*/
int hashFunction(char *name) {
    int length = strnlen(name, MAX_NAME);
    int hash_value = 0;
    for (int i = 0; i < length; i++) { // go through each character and get the ascii value
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }

    return hash_value;
}

// method to initialize empty hash table
bool initHashTable() {
    // table is empty
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

/*
method to insert data into the hash value
*/
bool insert(HashItem *item) {
    // if pointer is null
    if (item == NULL) return false;

    // compute hash of the name
    int index = hashFunction(item->name);

    // loop to find next open slot
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;

        if (hashTable[try] == NULL || hashTable[try] == DELETED_NODE) {
            hashTable[try] = item;
            return true;
        }
    }
    return false;
}

/*
method to find a hash item in the hash table by name
*/
HashItem *lookup(char *name) {
    int index = hashFunction(name);

    // start at the index the hash function outputted, then keep iterating if there is a match
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (index + 1) % TABLE_SIZE;

        if (hashTable[try] == NULL) {
            return false; // not here
        }

        if (hashTable[try] == DELETED_NODE) continue;

        // if the name in the hash table matches the name lookup
        if (hashTable[try] != NULL && strncmp(hashTable[try]->name, name, TABLE_SIZE) == 0) {
            return hashTable[try];
        }
    }
    return NULL;
}

/*
method to remove a hash item from the hash table
*/
HashItem *delete(char *name) {
    int index = hashFunction(name);

    // start at the index the hash function outputted, then keep iterating if there is a match
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (index + i) % TABLE_SIZE;

        if (hashTable[try] == NULL) return NULL;

        if (hashTable[try] == DELETED_NODE) continue;

        // if the name in the hash table matches the name lookup
        if (hashTable[try] != NULL && strncmp(hashTable[try]->name, name, TABLE_SIZE) == 0) {
            HashItem *tmp = hashTable[try];
            hashTable[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}

// method to display the current hash table
void display() {
    printf("\nHash Table\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else if (hashTable[i] == DELETED_NODE) {
            printf("\t%i\t--- <deleted>\n", i);
        } else {
            printf("\t%i\t%s\n", i, hashTable[i]->name);
        }
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    initHashTable();
    display();

    HashItem jacob = {.name = "Jacob", .age = 256};
    HashItem kate = {.name = "Kate", .age = 27};
    HashItem mpho = {.name = "Mpho", .age = 14};
    HashItem sarah = {.name = "Sarah", .age = 54};
    HashItem edna = {.name = "Edna", .age = 15};
    HashItem maren = {.name = "Maren", .age = 25};
    HashItem eliza = {.name = "Eliza", .age = 34};
    HashItem robert = {.name = "Robert", .age = 1};
    HashItem jane = {.name = "Jane", .age = 75};

    insert(&jacob);
    insert(&kate);
    insert(&mpho);
    insert(&sarah);
    insert(&edna);
    insert(&maren);
    insert(&eliza);
    insert(&robert);
    insert(&jane);
    
    display();
    
    HashItem *tmp = lookup("Mpho");
    if (tmp == NULL) {
        printf("Not found.\n");
    } else {
        printf("Found %s\n", tmp->name);
    }
    
    tmp = lookup("George");
    if (tmp == NULL) {
        printf("Not found.\n");
    } else {
        printf("Found %s\n", tmp->name);
    }
    
    delete("Mpho");
    
    tmp = lookup("Mpho");
    if (tmp == NULL) {
        printf("Not found.\n");
    } else {
        printf("Found %s\n", tmp->name);
    }

    display();

    return 0;
}
