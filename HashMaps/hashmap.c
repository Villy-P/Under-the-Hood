#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define KEY char*
#define VALUE int

typedef struct kvpair {
    KEY key;
    VALUE value;
} Pair;

typedef struct node {
    Pair* value;
    struct node* next;
} Node;

typedef struct hm {
    Node** items;
} HashMap;

HashMap* createHashMap(int initialLength) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->items = (Node**)calloc(initialLength, sizeof(Node*));
    return map;
}

int hash(KEY str) {
    int sum = 0;
    while (*str != '\0') {
        sum += (int)*str;
        str++;
    }
    return sum % 10;
}

void put(HashMap* map, KEY key, VALUE val) {
    int hashvalue = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    Pair* pair = (Pair*)malloc(sizeof(Pair));
    pair->key = key;
    pair->value = val;
    newNode->value = pair;
    newNode->next = NULL;
    if (map->items[hashvalue] == NULL) {
        map->items[hashvalue] = newNode;
    } else {
        Node* current = map->items[hashvalue];
        while (current->next != NULL) {
            if (strcmp(current->value->key, key) == 0) {
                current->value->value = val;
                free(newNode->value);
                free(newNode->next);
                return;
            }
            current = current->next;
        }
        current->next = newNode;
    }
}

VALUE get(HashMap* map, KEY key) {
    int hashvalue = hash(key);
    if (map->items[hashvalue] == NULL) 
        return NULL;
    if (map->items[hashvalue]->next == NULL)
        return map->items[hashvalue]->value->value;
    
    Node* node = map->items[hashvalue];
    while (node != NULL) {
        if (strcmp(key, node->value->key) == 0)
            return node->value->value;
        node = node->next;
    }

    return NULL;
}

int main() {
    HashMap* map = createHashMap(10);

    put(map, "Banana", 100);
    put(map, "Orange", 1);
    put(map, "Apple", 10);
    put(map, "Chat", 1000);

    printf("Banana: %d\n", get(map, "Banana"));
    printf("Orange: %d\n", get(map, "Orange"));
    printf("Apple: %d\n", get(map, "Apple"));
    printf("Chat: %d\n", get(map, "Chat"));

    return 0;
}