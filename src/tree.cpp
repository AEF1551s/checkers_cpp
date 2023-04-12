#include "tree.h"

bool min;
// Definition of tree_node constructor
tree_node::tree_node(int _data, int _alpha, int _beta, const int _game_state[8][8]) : prev(nullptr), next(nullptr), alpha(_alpha), beta(_beta), state_value(0)
{
    memcpy(game_state, _game_state, sizeof(game_state)); // Copy game state values to member variable
}

// Definition of tree_node destructor
tree_node::~tree_node()
{
    for (tree_node *child : children)
    {
        delete child;
    }
}

// Definition of doubly_linked_tree constructor
doubly_linked_tree::doubly_linked_tree() : root(nullptr), size(0)
{
}

// Definition of doubly_linked_tree destructor
doubly_linked_tree::~doubly_linked_tree()
{
    delete root;
}

// Definition of is_empty() function
bool doubly_linked_tree::is_empty() const
{
    return size == 0;
}

// Definition of get_size() function
int doubly_linked_tree::get_size() const
{
    return size;
}

// Definition of insert() function
void doubly_linked_tree::insert(tree_node *parent, int data, int alpha, int beta, const int game_state[8][8])
{
    tree_node *new_node = new tree_node(data, alpha, beta, game_state);
    new_node->prev = parent;
    if (parent != nullptr)
    {
        parent->children.push_back(new_node);
        if (parent->next == nullptr)
        {
            parent->next = new_node;
        }
    }
    else
    {
        root = new_node;
    }
    size++;
}
