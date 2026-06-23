struct Node {
    int key;
    int value;
    Node *next;
};

struct List {
    int count;
    int next_key;
    Node *init;
};

void create_list(List *l) {
    l->count = 0;
    l->next_key = 0;
    l->init = nullptr;
}

void limpar_lista(List *list) {
    Node *aux = list->init;

    while (aux != nullptr) {
        Node *prox = aux->next;
        delete aux;
        aux = prox;
    }

    list->init = nullptr;
    list->count = 0;
    list->next_key = 0;
}

void push_back(List *list, int value) {
    Node *new_node = new Node;

    new_node->value = value;
    new_node->key = ++list->next_key;
    new_node->next = nullptr;

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

void push_front(List *list, int value) {
    Node *new_node = new Node;

    new_node->value = value;
    new_node->key = ++list->next_key;
    new_node->next = list->init;

    list->init = new_node;
    list->count++;
}

Node* pop_back(List *list) {
    Node *node;

    if (list->init == nullptr) {
        return nullptr;
    }

    node = list->init;

    if (list->init->next == nullptr) {
        list->init = nullptr;
        list->count--;
        return node;
    }

    Node *aux = nullptr;
    while (node->next != nullptr) {
        aux = node;
        node = node->next;
    }

    list->count--;
    aux->next = nullptr;
    return node;
}

Node* pop_front(List *list) {
    Node *node = list->init;

    if (!node) {
        return nullptr;
    }

    list->init = node->next;
    list->count--;
    node->next = nullptr;

    return node;
}
