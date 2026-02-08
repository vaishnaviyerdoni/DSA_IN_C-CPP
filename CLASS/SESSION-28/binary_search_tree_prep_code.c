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
    const char* line = "---------------------------------------------------------------";
    puts(line);
    puts("Application started successfully!");
    build_bst();
    puts("Application terminated successfully!");
    puts(line);
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

    //node 150 link setting
    node_150 -> left = node_125;
    node_150 -> right = node_200;
    root_node -> parent = root_node;

    //node 25 link setting
    node_25 -> left = NULL;
    node_25 -> right = NULL;
    node_25 -> parent = node_50;

    //node 60 link settting
    node_60 -> left = NULL;
    node_60 -> right = node_70;
    node_60 -> parent = node_50;

    //node 125 link setting
    node_125 -> left = NULL;
    node_125 -> right = node_130;
    node_125 -> parent = node_150;

    //node 200 link setting 
    node_200 -> left = NULL;
    node_200 -> right = NULL;
    node_200 -> parent = node_150;

    //node 70 link setting
    node_70 -> left = NULL;
    node_70 -> right = NULL;
    node_70 -> parent = node_60;

    //node 130 link setting
    node_130 -> left = NULL;
    node_130 -> right = NULL;
    node_130 -> parent = node_125;

    //verify:
    printf("%d -> %d -> %d -> %d -> %d -> %d -> %d -> %d -> %d\n",
            root_node -> data,                             // 100
            root_node -> left -> data,                     // 50
            root_node -> right -> data,                    // 150
            root_node -> left -> left -> data,             // 25
            root_node -> left -> right -> data,            // 60
            root_node -> right -> left -> data,            // 125
            root_node -> right -> right -> data,           // 200
            root_node -> left -> right -> right -> data,   // 70
            root_node -> right -> left -> right -> data    // 130
        );

    free(root_node);
    root_node = NULL;
    free(node_50);
    node_50 = NULL;
    free(node_150);
    node_150 = NULL;
    free(node_25);
    node_25 = NULL;
    free(node_60);
    node_60 = NULL;
    free(node_200);
    node_200 = NULL;
    free(node_125);
    node_125 = NULL;
    free(node_130);
    node_130 = NULL;
    free(node_70);
    node_70 = NULL;

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