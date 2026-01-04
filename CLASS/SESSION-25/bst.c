#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//Symbolic constants
#define SUCCESS 1
#define TRUE 1
struct bst_node
{
    int data;
    struct bst_node* left;
    struct bst_node* right;
    struct bst_node* parent;
};

struct bst
{
    struct bst_node* p_root_node;
    size_t number_of_element;
};
 
//Interface Function declarations
//Allocate a new instance of binary search tree
struct bst* create_bst(void);

//insert a new data in a given binart search tree
int insert_bst(struct bst* p_bst, int new_data);

//travel through all elements of a given binary search tree
//in "inorder" traversal sequence
void inorder_traversal(struct bst* p_bst);

//destroy given instance of binary search tree
int destroy_bst(struct bst** pp_bst);

//Helper Functions
//HElper fnctions for inorder_traversal()
void inorder(struct bst_node* node);

//Helper for function for destroy_bst()
void destroy(struct bst_node* node);

int main(void)
{
    struct bst* p_bst = NULL;
    int status;
    int data[] = {10, 50, 150, 25, 65, 125, 175, 70, 130, 200};
    int i;

    p_bst = create_bst();
    for(i = 0; i < sizeof(data)/sizeof(data[0]); ++i)
        assert(insert_bst(p_bst, data[i]) == SUCCESS);

    inorder_traversal(p_bst);

    status = destroy_bst(&p_bst);
    assert(status == SUCCESS && p_bst == NULL);

    return(0);
}

//Interface Function definitions
//Allocate a new instance of binary search tree
struct bst* create_bst(void)
{
    struct bst* p_bst = NULL;

    p_bst = (struct bst*)malloc(sizeof(struct bst));
    if(NULL == p_bst)
    {
        fprintf(stderr, "malloc failed : out of memory");
        exit(EXIT_FAILURE);
    }

    p_bst -> p_root_node = NULL;
    p_bst -> number_of_element = 0;

    return(p_bst);
}

//insert a new data in a given binart search tree
//  Insert a new data in a given binary search tree 
int insert_bst(struct bst* p_bst, int new_data)
{
    struct bst_node* p_new_node = NULL; 

    //  Allocate and initialize new node 
    p_new_node = (struct bst_node*)malloc(sizeof(struct bst_node)); 
    if(NULL == p_new_node)
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    }
    p_new_node->data = new_data; 
    p_new_node->left = NULL; 
    p_new_node->right = NULL; 
    p_new_node->parent = NULL; 

    //  Check if the binary search tree is empty 
    //  If it is then insert a new node at root position 
    //  Increase the number of element by 1 and return 
    if(p_bst->p_root_node == NULL)
    {
        p_bst->p_root_node = p_new_node; 
        p_bst->number_of_element += 1; 
        return (SUCCESS); 
    }

    //  Insert into non-empty binary search tree 
    struct bst_node* run = p_bst->p_root_node; 
    while(TRUE)
    {
        if(new_data <= run->data)
        {
            if(run->left == NULL)
            {
                run->left = p_new_node; 
                run->left->parent = run; 
                break; 
            }
            run = run->left; 
        }
        else 
        {
            if(run->right == NULL)
            {
                run->right = p_new_node; 
                run->right->parent = run; 
                break; 
            }
            run = run->right; 
        }
    }

    p_bst->number_of_element += 1; 
    return (SUCCESS); 
}

//travel through all elements of a given binary search tree
//in "inorder" traversal sequence
void inorder_traversal(struct bst* p_bst)
{
    printf("[START] <->");
    inorder(p_bst -> p_root_node);
    printf("[END]");    
}

//destroy given instance of binary search tree
int destroy_bst(struct bst** pp_bst)
{
    struct bst* p_bst = *pp_bst;
    destroy(p_bst -> p_root_node);
    free(p_bst);
    *pp_bst = NULL;
    return(SUCCESS);
}

//Helper Functions
//HElper fnctions for inorder_traversal()
void inorder(struct bst_node* node)
{
    if(node != NULL)
    {
        inorder(node -> left);
        printf("[%d] <-> ", node -> data);
        inorder(node -> right);
    }
}

//Helper for function for destroy_bst()
void destroy(struct bst_node* node)
{
    if(node != NULL)
    {
        destroy(node -> left);
        destroy(node -> left);
        free(node);
    }
}