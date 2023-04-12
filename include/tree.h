#ifndef DOUBLY_LINKED_TREE_H
#define DOUBLY_LINKED_TREE_H

#include <memory.h>
#include <vector>
#include "game_state.h"

// Node class representing a node in the doubly linked tree
class tree_node
{
public:
    std::vector<tree_node *> children; // Vector to store pointers to child nodes
    tree_node *prev;                   // Pointer to previous node
    tree_node *next;                   // Pointer to next node
    int game_state[8][8];              // Game state
    int alpha, beta;
    int state_value;
    bool min, max;
    tree_node(int alpha, int beta, int state_value, bool min, bool max, int game_state[8][8]);
    ~tree_node();
};

// Doubly linked tree class
class doubly_linked_tree
{
public:
    doubly_linked_tree();

    ~doubly_linked_tree();

    // Function to check if the tree is empty
    bool is_empty() const;

    // Function to get the size of the tree
    int get_size() const;

    // Function to insert a node as a child of the given parent node with alpha, beta, and game_state values
    void insert(tree_node *parent, int alpha, int beta, int state_value, bool min, bool max, int game_state[8][8]);

private:
    tree_node *root; // Pointer to the root node
    int size;        // Size of the tree
};

#endif // DOUBLY_LINKED_TREE_H

