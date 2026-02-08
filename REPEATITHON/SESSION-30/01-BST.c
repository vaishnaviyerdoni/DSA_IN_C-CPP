#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

enum status
{
    SUCCESS                       = 1,
    TRUE                          = 1,
    FALSE                         = 0,
    BST_EMPTY                     = -1,
    BST_NO_INORDER_SUCCESSOR      = -2,
    BST_NO_INORDER_PREDECESSOR    = -3,
    BST_NO_PREORDER_SUCCESSOR     = -4,
    BST_NO_PREORDER_PREDECESSOR   = -5,
    BST_NO_POSTORDER_SUCCESSOR    = -6,
    BST_NO_POSTORDER_PREDECESSOR  = -7
};

typedef int             data_t;
typedef enum status     status_t;
typedef struct bst      bst_t;
typedef struct bst_node bst_node_t;

struct bst_node
{
    data_t data;
    struct bst_node* left;
    struct bst_node* right;
    struct bst_node* parent;
};

struct bst
{
    bst_node_t* root_node;
    size_t nr_elements;
};

//Interface Function 
//create and destroy
bst_t* create_bst(void);
status_t destroy_bst(bst_t** pp_bst);

//Insert Data
status_t insert_bst(bst_t* p_bst, data_t new_data);

//search Data
status_t search_bst(bst_t* p_bst, data_t search_data);

//Remove Data 
status_t remove_bst(bst_t* p_bst, data_t r_data);

//bst - traversals :- recursive
void preorder(bst_t* p_bst);
void inorder(bst_t* p_bst);
void postorder(bst_t* p_bst);

//bst - traversal :- non recursive
void nrc_preorder(bst_t* p_bst);
void nrc_inorder(bst_t* p_bst);
void nrc_postorder(bst_t* p_bst);

//PreOrder successor and predecessor

//PostOrder successor and predecessor

//InOrder success and predecessor

//Max and Min Algorithms
status_t max_bst(bst_t* p_bst, data_t* p_max_data);
status_t min_bst(bst_t* p_bst, data_t* p_min_data);

//Node_level Algorithms
void destroy_nodelevel(bst_node_t* root_node);

void preorder_nodelevel(bst_node_t* root_node);
void postorder_nodelevel(bst_node_t* root_node);
void inorder_nodelevel(bst_node_t* root_node);

//nodelevel inorder predecessor and successor

//nodelevel preorder predecessor and successor

//nodelevel postorder predecessor and successor

void search_nodelevel(bst_node_t* root_node, data_t s_data);

bst_node_t* max_bst_nodelevel(bst_node_t* root_node);
bst_node_t* min_bst_nodelevel(bst_node_t* root_node);

//auxillary functions
bst_node_t* get_node(data_t n_data);
void* xmalloc(size_t size);

int main(void)
{
    return(0);
}

//Interface Function 
//create and destroy
bst_t* create_bst(void)
{
    bst_t* p_bst = NULL;
    p_bst = (bst_t*)xmalloc(sizeof(bst_t));

    p_bst -> root_node = NULL;
    p_bst -> nr_elements = 0;

    return(p_bst);
}

status_t destroy_bst(bst_t** pp_bst)
{
    bst_t* p_bst = NULL;
    p_bst = *pp_bst;

    destroy_nodelevel(p_bst -> root_node);
    free(p_bst);
    *pp_bst = NULL;

    return(SUCCESS);
}

//Insert Data
status_t insert_bst(bst_t* p_bst, data_t new_data)
{
    bst_node_t* new_node = NULL;
    bst_node_t* run = NULL;

    new_node = get_node(new_data);

    //case 1 - if bst is empty
    if(p_bst -> root_node == NULL)
    {
        p_bst -> root_node = new_node;
        p_bst -> nr_elements += 1;
        return(SUCCESS);
    }

    //case 2 - if bst is not empty
    run = p_bst -> root_node;
    while(TRUE)
    {
        if(new_data <= run -> data)
        {
            if(run -> left == NULL)
            {
                run -> left = new_node;
                run -> left -> parent = run;
                break;
            }

            run = run -> left;
        }
        else
        {
            if(run -> right == NULL)
            {
                run -> right = new_node;
                run -> right -> parent = run;
                break;
            }

            run = run -> right;
        }
    }

    p_bst -> nr_elements += 1;
    return(SUCCESS);
}

//search Data
status_t search_bst(bst_t* p_bst, data_t search_data)
{
    bst_node_t* s_node = NULL; // s_node is node to be searched

    s_node = search_bst_nodelevel(p_bst -> root_node, search_data);
    return(s_node != NULL);
}

//Remove Data 
status_t remove_bst(bst_t* p_bst, data_t r_data)
{

}

//bst - traversals :- recursive
void preorder(bst_t* p_bst)
{
    printf("PREORDER : [START] ->");
    preorder_nodelevel(p_bst -> root_node);
    puts("[END]");
}

void inorder(bst_t* p_bst)
{
    printf("INORDER : [START] ->");
    inorder_nodelevel(p_bst -> root_node);
    puts("[END]");
}

void postorder(bst_t* p_bst)
{
    printf("POSTORDER : [START] ->");
    postorder_nodelevel(p_bst -> root_node);
    puts("[END]");
}

//bst - traversal :- non recursive
void nrc_preorder(bst_t* p_bst)
{

}

void nrc_inorder(bst_t* p_bst)
{

}

void nrc_postorder(bst_t* p_bst)
{

}

status_t max_bst(bst_t* p_bst, data_t* p_max_data)
{
    bst_node_t* max_node = NULL;

    if(p_bst -> root_node == NULL)
        return(BST_EMPTY);

    max_node = max_bst_nodelevel(p_bst -> root_node);
    *p_max_data = max_node -> data;

    return(SUCCESS);    
}

status_t min_bst(bst_t* p_bst, data_t* p_min_data)
{
    bst_node_t* min_node = NULL;

    if(p_bst -> root_node == NULL)
        return(BST_EMPTY);

    min_node = min_bst_nodelevel(p_bst -> root_node);
    *p_min_data = min_node -> data;

    return(SUCCESS);
}

//Node_level Algorithms
void destroy_nodelevel(bst_node_t* root_node)
{
    if(root_node != NULL)
    {
        destroy_nodelevel(root_node -> left);
        destroy_nodelevel(root_node -> right);
        free(root_node);
    }
}

void preorder_nodelevel(bst_node_t* root_node)
{
    if(root_node != NULL)
    {
        printf("[%d] ->", root_node -> data);
        preorder_nodelevel(root_node -> left);
        preorder_nodelevel(root_node ->right);
    }
}

void postorder_nodelevel(bst_node_t* root_node)
{
    if(root_node != NULL)
    {
        postorder_nodelevel(root_node -> left);
        postorder_nodelevel(root_node -> right);
        printf("[%d] ->", root_node -> data);
    }
}


void inorder_nodelevel(bst_node_t* root_node)
{
    if(root_node != NULL)
    {
        inorder_nodelevel(root_node -> left);
        printf("[%d] ->", root_node -> data);
        inorder_nodelevel(root_node -> right);
    }
}


void search_nodelevel(bst_node_t* root_node, data_t s_data)
{
    bst_node_t* run = NULL;
    run = root_node;

    while(run != NULL)
    {
        if(run -> data == s_data)
            break;

        else if(run -> data < s_data)
            run = run -> left;
        
        else
            run = run -> right;
    }

    return(run);
}

bst_node_t* max_bst_nodelevel(bst_node_t* root_node)
{
    bst_node_t* run = NULL;

    run = root_node;
    while(run != NULL)
    {
        run = run -> right;
    }

    return(run);
}

bst_node_t* min_bst_nodelevel(bst_node_t* root_node)
{
    bst_node_t* run = NULL;

    run = root_node;
    while(run != NULL)
    {
        run = run -> left;
    }

    return(run);
}

//auxillary functions
bst_node_t* get_node(data_t n_data)
{
    bst_node_t* new_node = NULL;
    new_node = (bst_node_t*)xmalloc(sizeof(bst_node_t));

    new_node -> data = n_data;
    new_node -> left = NULL;
    new_node -> right = NULL;
    new_node -> parent = NULL;

    return(new_node);
}

void* xmalloc(size_t size)
{
    void* p = NULL;
    p = malloc(size);

    if(NULL != p)
    {
        puts("xmalloc():malloc():Out of Memory");
        exit(EXIT_FAILURE);
    }

    return(p);
}
