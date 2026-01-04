#include <stdio.h>
#include <stdlib.h>

struct bst_node
{
    int data;
    struct bst_node* left;
    struct bst_node* right;
    struct bst_node* parent;
};

struct bst
{
    struct bst_node* root_node;
    int no_of_elements;
};

void* xmalloc(size_t size);
struct bst_node* get_bst_node(int data);
void build_bst(void);

int main(void)
{
    build_bst();
    return(0);
}

void build_bst(void)
{
    struct bst_node* root_node = NULL;
    struct bst_node* node_50 = NULL;
    struct bst_node* node_150 = NULL;
    struct bst_node* node_25 = NULL;
    struct bst_node* node_60 = NULL;
    struct bst_node* node_200 = NULL;
    struct bst_node* node_125 = NULL;
    struct bst_node* node_130 = NULL;
    struct bst_node* node_70 = NULL;

    root_node = get_bst_node(100);
    node_50 = get_bst_node(50);
    node_150 = get_bst_node(150);
    node_25 = get_bst_node(25);
    node_60 = get_bst_node(60);
    node_200 = get_bst_node(200);
    node_125 = get_bst_node(125);
    node_130 = get_bst_node(130);
    node_70 = get_bst_node(70);

    //root node link setting
    root_node -> left = node_50;
    root_node -> right = node_150;
    root_node -> parent = NULL;

    //node 50 link setting
    node_50 -> left = node_25;
    node_50 -> right = node_60;
    node_50 -> parent = root_node;

    //node 60 link settting
    node_60 -> left = NULL;
    node_60 -> right = node_70;
    node_60 -> parent = node_50;

    //node 125 link setting
    
}

struct bst_node* get_bst_node(int data)
{
    struct bst_node* ptr = NULL;

    ptr = (struct bst_node*)xmalloc(sizeof(struct bst_node));
    ptr -> data = data;
    ptr -> left = ptr -> right = ptr -> parent = NULL;

    return(ptr);
}

void* xmalloc(size_t size)
{
    void* ptr = NULL;
    ptr = malloc(size);
    if(ptr == NULL)
    {
        printf("Out of Memory");
        exit(EXIT_FAILURE);
    }

    return(ptr);
}