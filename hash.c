#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

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

    // check if the index is already occupied
    if (hashTable[index] != NULL) {
        return false;
    }

    // if a spot in the hash table is available
    hashTable[index] = item;
    return true;
}

/*
method to find a hash item in the hash table by name
*/
HashItem *lookup(char *name) {
    int index = hashFunction(name);

    // if the name in the hash table matches the name lookup
    if (hashTable[index] != NULL && 
    strncmp(hashTable[index]->name, name, TABLE_SIZE) == 0) {
        return hashTable[index];
    } else {
        return NULL;
    }
}

/*
method to remove a hash item from the hash table
*/
HashItem *delete(char *name) {
    //
}

// method to display the current hash table
void display() {
    printf("\nHash Table\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == NULL) {
            printf("\t%i\t---\n", i);
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

    insert(&jacob);
    insert(&kate);
    insert(&mpho);

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

    // test different inputs for the hash function
    // printf("Jacob => %d\n", hashFunction("Jacob"));
    // printf("Natalie => %d\n", hashFunction("Natalie"));
    // printf("Sara => %d\n", hashFunction("Sara"));
    // printf("Mpho => %d\n", hashFunction("Mpho"));
    // printf("Tebogo => %d\n", hashFunction("Tebogo"));
    // printf("Ron => %d\n", hashFunction("Ron"));
    // printf("Jane => %d\n", hashFunction("Jane"));
    // printf("Maren => %d\n", hashFunction("Maren"));
    // printf("Bill => %d\n", hashFunction("Bill"));

    return 0;
}
