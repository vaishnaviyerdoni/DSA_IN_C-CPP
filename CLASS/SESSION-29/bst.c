//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//symbolic constants
enum status
{
    SUCCESS                       = 1,
    TRUE                          = 1,
    FALSE                         = 0,
    BST_EMPTY                    = -1,
    BST_NO_INORDER_PREDECCESSOR  = -2,
    BST_NO_INORDER_SUCCESSOR     = -3,
    BST_NO_PREORDER_PREDECESSOR  = -4,
    BST_NO_PREORDER_SUCCESSOR    = -5,
    BST_NO_POSTORDER_PREDECESSOR = -6,
    BST_NO_POSTORDER_SUCCESSOR   = -7
};


//typedefs 
typedef int              data_t;
typedef enum status      status_t;
typedef struct bst_node  bst_node_t;
typedef struct bst       bst_t;

//Node Layout definitions
struct bst_node{
    data_t* data;
    struct bst_node* left;
    struct bst_node* right;
    struct bst_node* parent;
};

struct bst
{
    bst_node_t* root_node;
    size_t nr_elements;
};

//interface functions declarations
bst_t* create_bst(void);
status_t destroy_bst(bst_t** pp_bst);

//insert new data
status_t insert_bst(bst_t* p_bst, data_t n_data);

//search bst
status_t search_bst(bst_t* p_bst, data_t s_data);

//remove data
status_t remove_bst(bst_t* p_bst, data_t r_data);

//bst traversals
void preorder_traversal(bst_t* p_bst);
void inorder(bst_t* p_bst);
void postorder(bst_t* p_bst);

//Inorder predecessor and successor
status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data);
status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data);

////Preorder successor and predecessor
status_t preorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data);
status_t preorder_successor(bst_t* p_bst, data_t existing data, data_t p_succ_data);

//mINIMUM AND MAXIMUM 
status_t max_bst(bst_t* p_bst, data_t* p_max_data);
status_t min_bst(bst_t* p_bst, data_t* p_min_data);

//bst traversals non recursive
void preorder_nrc(bst_t* p_bst);
void inorder_nrc(bst_t* p_bst);
void postorder_nrc(bst_t* p_bst);

//Auxillary Functions
void destroy_nodelevel(bst_node_t* root_node);
void inorder_nodelevel(bst_node_t* root_node);
void postorder_nodelevel(bst_node_t* root_node);

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node);
bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node);

bst_node_t* preorder_predecessor_nodelevel(bst_node_t* existing_node);
bst_node_t* preorder_sucessor_node_level(bst_node_t* existing_node);

bst_node_t* postorder_predecessor_nodelevel(bst_node_t* existing_node);
bst_node_t* postorder_sucessor_nodelevel(bst_node_t* existing_node);

//General purpose
bst_node_t* get_bst_node(data_t n_data);
void* xmalloc(size_t size);

//Client side
int main(void)
{
    return(0);
}

//Server side
//interface functions definitions
bst_t* create_bst(void)
{
    bst_t* new_bst = NULL;
    new_bst = (bst_t*)xmalloc(sizeof(bst_t));

    new_bst -> root_node = NULL;
    new_bst -> nr_elements = 0;

    return(new_bst);
}

status_t destroy_bst(bst_t** pp_bst)
{

}

//insert new data
status_t insert_bst(bst_t* p_bst, data_t n_data)
{
    bst_node_t* new_node = NULL;
    bst_node_t* run = NULL;

    new_node = get_bst_node(n_data);

    if(p_bst -> root_node == NULL)
    {
        //Case 1 - Empty BST
        p_bst -> root_node = new_node;
        p_bst -> nr_elements += 1;
        
        return(SUCCESS);
    }

    run = p_bst -> root_node;
    while(TRUE)
    {
        if(n_data <= run -> data)
        {
            if(run -> left == NULL)
            {
                run -> left = new_node;
                run -> left -> parent = run; // run -> left is new_node and new_node's parent is run

                break;
            }

            run = run -> left;
        }
        else
        {
            if(run -> right == NULL)
            {
                run -> right = new_node;
                run -> right -> parent = run; //run -> right is new_node and new_node's parent is run

                break;
            }

            run = run -> right;
        }
    }

    p_bst -> nr_elements += 1;
    return(SUCCESS);
}

//search bst
status_t search_bst(bst_t* p_bst, data_t s_data)
{
    bst_node_t* run = NULL;

    run = p_bst -> root_node;
    while(run != NULL)
    {
        if(run -> data == s_data)
            return(TRUE);
        
        else if(s_data < run -> data)
            run -> left;
        
        else
            run = run -> right;
    }

    return(FALSE);
}

//remove data
status_t remove_bst(bst_t* p_bst, data_t r_data)
{

}

//bst traversals - recursive
void preorder_traversal(bst_t* p_bst)
{

}

void inorder(bst_t* p_bst)
{

}

void postorder(bst_t* p_bst)
{

}

//Inorder predecessor and successor
status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data)
{

}

status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data)
{

}

////Preorder successor and predecessor
status_t preorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data)
{

}

status_t preorder_successor(bst_t* p_bst, data_t existing data, data_t p_succ_data)
{

}

//mINIMUM AND MAXIMUM 
status_t max_bst(bst_t* p_bst, data_t* p_max_data)
{

}

status_t min_bst(bst_t* p_bst, data_t* p_min_data)
{

}

//bst traversals non recursive
void preorder_nrc(bst_t* p_bst)
{

}

void inorder_nrc(bst_t* p_bst)
{

}

void postorder_nrc(bst_t* p_bst)
{

}

//Auxillary Functions
void destroy_nodelevel(bst_node_t* root_node)
{

}

void inorder_nodelevel(bst_node_t* root_node)
{

}

void postorder_nodelevel(bst_node_t* root_node)
{

}

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node)
{

}

bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node)
{

}

bst_node_t* preorder_predecessor_nodelevel(bst_node_t* existing_node)
{

}

bst_node_t* preorder_sucessor_node_level(bst_node_t* existing_node)
{

}

bst_node_t* postorder_predecessor_nodelevel(bst_node_t* existing_node)
{

}

bst_node_t* postorder_sucessor_nodelevel(bst_node_t* existing_node)
{

}

//General purpose
bst_node_t* get_bst_node(data_t n_data)
{
    bst_node_t* new_node = NULL;

    new_node = (bst_node_t*)xmalloc(sizeof(bst_node_t));
    new_node -> data = n_data;
    new_node -> right = new_node -> left = new_node = new_node -> parent = NULL;

}

void* xmalloc(size_t size)
{
    void* ptr = NULL;

    ptr = malloc(size);
    if(NULL == ptr) 
    {
        fprintf(stderr, "Malloc() :fatal error");
        exit(EXIT_FAILURE);
    }

    return(ptr);
}