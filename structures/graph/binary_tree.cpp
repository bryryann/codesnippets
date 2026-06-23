struct Node {
    int key;
    int value;
    Node *left;
    Node *right;
};

struct Graph {
    int next_key;
    int count;
    Node *init;
};

Node* create_node(int key, int value) {
    Node *new_node = new Node;

    new_node->key = key;
    new_node->value = value;
    new_node->left = nullptr;
    new_node->right = nullptr;

    return new_node;
}

void initialize_graph(Graph *g) {
    g->init = nullptr;
    g->count = 0;
    g->next_key = 0;
}

Node* insert_tree(Graph *g, Node *root, int value) {
    if (root == nullptr) {
        return create_node(++g->next_key, value);
    }

    if (value < root->value) {
        root->left = insert_tree(g, root->left, value);
    }
    else if (value > root->value) {
        root->right = insert_tree(g, root->right, value);
    }

    return root;
}

