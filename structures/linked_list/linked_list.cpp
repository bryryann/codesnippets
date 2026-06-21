#include <iostream>

struct Node {
    int key;
    int value;
    Node *next;
};

struct List {
    int count;
    Node *init;
};

void create_list(List *l) {
    l->count = 0;
    l->init = nullptr;
}

void push_back(List *list, int value) {
    Node *new_node = new Node;

    if (new_node != nullptr) {
        new_node->value = value;
        new_node->key = list->count;
        new_node->next = nullptr;
    }

    if (list->init == nullptr) {
        list->init = new_node;
    }
    else {
        Node *aux = list->init;

        while (aux->next != nullptr) {
            aux = aux->next;
        }

        aux->next = new_node;
    }

    list->count++;
}

