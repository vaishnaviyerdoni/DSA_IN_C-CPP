//================BINARY SEARCH TREE - START================//
//================HEADER FILES - START================//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//=================HEADER FILES - END=================//

//================SYMBOLIC CONSTANTS - START================//
enum status
{
    SUCCESS                       = 1,
    TRUE                          = 1,
    FALSE                         = 0,
    BST_EMPTY                    = -1,
    BST_NO_INORDER_PREDECESSOR   = -2,
    BST_NO_INORDER_SUCCESSOR     = -3,
    BST_NO_PREORDER_PREDECESSOR  = -4,
    BST_NO_PREORDER_SUCCESSOR    = -5,
    BST_NO_POSTORDER_PREDECESSOR = -6,
    BST_NO_POSTORDER_SUCCESSOR   = -7
};
//=================SYMBOLIC CONSTANTS - END=================//

//================TYPEDEFS - START================//
typedef int             data_t;
typedef enum status     status_t;

typedef struct bst_node bst_node_t;
typedef struct bst      bst_t;
//=================TYPEDEFS - END=================//

//================INFORMAITON STRUCTURE DEFINITION - START================//
//DEFINITION OF NODE OF BST
struct bst_node
{
    data_t data;
    struct bst_node* left;
    struct bst_node* right;
    struct bst_node* parent;
};

//DEFINITION OF INSTANCE OF BST
struct bst
{
    bst_node_t* root_node;
    size_t nr_elements;
};
//=================INFORMATION STRUCTURE DEFINITIONS - END=================//

//================INTERFACE FUNCTION DECLARATIONS - START================//
//CREATE AND DESTROY FUNCTIONS
bst_t* create_bst(void);
status_t destroy_bst(bst_t** pp_bst);

//DATA INSERTION FUNCTION
status_t insert_bst(bst_t* p_bst, data_t n_data);

//DATA SEARCH ALGORITHM
status_t search_bst(bst_t* p_bst, data_t s_data);

//DATA REMOVAL ALGORITHM
status_t remove_bst(bst_t* p_bst, data_t r_data);

//BST TRAVERSAL ALGORITHM - RECURSIVE
void inorder(bst_t* p_bst);
void preorder(bst_t* p_bst);
void postorder(bst_t* p_bst);

//BST TRAVERSAL ALGORITHM - NON RECURSIVE
void inorder_nrc(bst_t* p_bst);
void preorder_nrc(bst_t* p_bst);
void postorder_nrc(bst_t* p_bst);

//INORDER PREDECESSOR AND SUCCESSOR
status_t inorder_predecessor(bst_t* p_bst, data_t e_data, data_t* p_pred_data);
status_t inorder_successor(bst_t* p_bst, data_t e_data, data_t* p_succ_data);

//PREORDER PREDECESSOR AND SUCCESSOR
status_t preorder_predecessor(bst_t* p_bst, data_t e_data, data_t* p_pred_data);
status_t preorder_successor(bst_t* p_bst, data_t e_data, data_t* p_succ_data);

//POSTORDER PREDECESSOR AND SUCCESSOR 
status_t postorder_predecessor(bst_t* p_bst, data_t e_data, data_t* p_pred_data);
status_t postorder_successor(bst_t* p_bst, data_t e_data, data_t* p_succ_data);

//MAXIMUM AND MINIMUM
status_t max_bst(bst_t* p_bst, data_t* max_data);
status_t min_bst(bst_t* p_bst, data_t* min_data);
//=================INTERFACE FUNCTION DECLARATIONS - END=================//

//================AUXILLARY FUNCTION DECLARATIONS - START================//
//DESTROY NODE-LEVEL
void destroy_nodelevel(bst_node_t* root_node);

//BST TRAVERSAL NODE-LEVEL
void inorder_nodelevel(bst_node_t* root_node);
void preorder_nodelevel(bst_node_t* root_node);
void postorder_nodelevel(bst_node_t* root_node);

//INORDER PREDECESSOR AND SUCCESSOR - NODE-LEVEL
bst_node_t* inorder_predecessor_nodelevel(bst_node_t* e_node);
bst_node_t* inorder_successor_nodelevel(bst_node_t* e_node);

//PREORDER PREDECESSOR AND SUCCESSOR - NODE-LEVEL
bst_node_t* preorder_predecessor_nodelevel(bst_node_t* e_node);
bst_node_t* preorder_successor_nodelevel(bst_node_t* e_node);

//POSTORDER PREDECESSOR AND SUCCESSOR - NODE-LEVEL
bst_node_t* postorder_predecessor_nodelevel(bst_node_t* e_node);
bst_node_t* postorder_successor_nodelevel(bst_node_t* e_node);

//MAXIMUM AND MININUM - NODE-LEVEL
bst_node_t* max_bst_nodelevel(bst_node_t* root_node);
bst_node_t* min_bst_nodelevel(bst_node_t* root_node);

//GENERAL PURPOSE FUNCTIONS
bst_node_t* get_node(data_t n_data);
void* xmalloc(size_t size);
//=================AUXILLARY FUNCTION DECLARATIONS - END=================//

//================TEST SERVER FUNCTION - START================//
void test_bst(void);
//=================TEST SERVER FUNCTION - END=================//

//================CLIENT OF BST - START================//
//================MAIN FUNCTION - START================//
int main(void)
{
    test_bst();
    return(EXIT_SUCCESS);
}
//=================MAIN FUNCTION - END=================//

//================TEST FUNCTION - START================//
void test_bst(void)
{
    
}
//=================TEST FUNCTION - END=================//
//=================CLIENT OF BST - END=================//

//================SERVER OF BST - START================//
//================INTERFACE FUNCTION DEFINITIONS - START================//
//CREATE AND DESTROY FUNCTIONS
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

//DATA INSERTION FUNCTION
status_t insert_bst(bst_t* p_bst, data_t n_data)
{
    bst_node_t* new_node = NULL;
    bst_node_t* run = NULL;

    new_node = get_node(n_data);

    //CASE 1 - BST IS EMPTY
    if(p_bst -> root_node == NULL)
    {
        p_bst -> root_node = new_node;
        p_bst -> nr_elements += 1;
        return(SUCCESS);
    }

    //CASE 2 - BST IS NOT EMPTY
    run = p_bst -> root_node;
    while(TRUE)
    {
        if(n_data <= run -> data)
        {
            if(run -> left == NULL)
            {
                run -> left = new_node;
                //  new_node -> parent = run;
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
                // new_node -> parent = run;
                run -> right -> parent = run; // run -> right is new_node and new_node's parent is run
                break;
            }

            run = run -> right;
        }
    }

    p_bst -> nr_elements += 1;
    return(SUCCESS);
}

//DATA SEARCH ALGORITHM
status_t search_bst(bst_t* p_bst, data_t s_data)
{
    bst_node_t* run = NULL;

    run = p_bst -> root_node;
    while(run != NULL)
    {
        if(run -> data == s_data)
            return(TRUE);
        
        else if(s_data < run->data)
            run = run -> left;
        
        else
            run = run -> right;
    }

    return(FALSE);
}

//DATA REMOVAL ALGORITHM
status_t remove_bst(bst_t* p_bst, data_t r_data)
{

}

//BST TRAVERSAL ALGORITHM - RECURSIVE
void inorder(bst_t* p_bst)
{
    printf("INORDER : [START] -> ");
    inorder_nodelevel(p_bst -> root_node);
    puts("[END]");
}

void preorder(bst_t* p_bst)
{
    printf("PREORDER : [START] -> ");
    preorder_nodelevel(p_bst -> root_node);
    puts("[END]");
}

void postorder(bst_t* p_bst)
{
    printf("POSTORDER :[START] -> ");
    postorder_nodelevel(p_bst -> root_node);
    puts("[END]");
}

//BST TRAVERSAL ALGORITHM - NON RECURSIVE
void inorder_nrc(bst_t* p_bst)
{

}

void preorder_nrc(bst_t* p_bst)
{

}

void postorder_nrc(bst_t* p_bst)
{

}

//INORDER PREDECESSOR AND SUCCESSOR
status_t inorder_predecessor(bst_t* p_bst, data_t e_data, data_t* p_pred_data)
{

}

status_t inorder_successor(bst_t* p_bst, data_t e_data, data_t* p_succ_data)
{

}

//PREORDER PREDECESSOR AND SUCCESSOR
status_t preorder_predecessor(bst_t* p_bst, data_t e_data, data_t* p_pred_data)
{

}

status_t preorder_successor(bst_t* p_bst, data_t e_data, data_t* p_succ_data)
{

}

//POSTORDER PREDECESSOR AND SUCCESSOR 
status_t postorder_predecessor(bst_t* p_bst, data_t e_data, data_t* p_pred_data)
{

}

status_t postorder_successor(bst_t* p_bst, data_t e_data, data_t* p_succ_data)
{

}

//MAXIMUM AND MINIMUM
status_t max_bst(bst_t* p_bst, data_t* max_data)
{

}

status_t min_bst(bst_t* p_bst, data_t* min_data)
{

}
//=================INTERFACE FUNCTION DEFINITIONS - END=================//

//================AUXILLARY FUNCTION DEFINITIONS - START================//
//DESTROY NODE-LEVEL
void destroy_nodelevel(bst_node_t* root_node)
{

}

//BST TRAVERSAL NODE-LEVEL
void inorder_nodelevel(bst_node_t* root_node)
{
    if(root_node != NULL)
    {
        inorder_nodelevel(root_node -> left);
        printf("[%d] ->", root_node -> data);
        inorder_nodelevel(root_node -> right);
    }
}

void preorder_nodelevel(bst_node_t* root_node)
{
    if(root_node != NULL)
    {
        printf("[%d] ->", root_node -> data);
        preorder_nodelevel(root_node -> left);
        preorder_nodelevel(root_node -> right); 
    }
}

void postorder_nodelevel(bst_node_t* root_node)
{
    if(root_node != NULL)
    {
        postorder_nodelevel(root_node -> left);
        postorder_nodelevel(root_node -> right);
        printf("[%d] -> ", root_node -> data);
    }
}

//INORDER PREDECESSOR AND SUCCESSOR - NODE-LEVEL
bst_node_t* inorder_predecessor_nodelevel(bst_node_t* e_node)
{

}

bst_node_t* inorder_successor_nodelevel(bst_node_t* e_node)
{

}

//PREORDER PREDECESSOR AND SUCCESSOR - NODE-LEVEL
bst_node_t* preorder_predecessor_nodelevel(bst_node_t* e_node)
{

}

bst_node_t* preorder_successor_nodelevel(bst_node_t* e_node)
{

}

//POSTORDER PREDECESSOR AND SUCCESSOR - NODE-LEVEL
bst_node_t* postorder_predecessor_nodelevel(bst_node_t* e_node)
{

}

bst_node_t* postorder_successor_nodelevel(bst_node_t* e_node)
{

}

//MAXIMUM AND MININUM - NODE-LEVEL
bst_node_t* max_bst_nodelevel(bst_node_t* root_node)
{

}

bst_node_t* min_bst_nodelevel(bst_node_t* root_node)
{

}

//GENERAL PURPOSE FUNCTIONS
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
    if(NULL == p)
    {
        fprintf(stderr, "xmalloc():malloc():Out of Memory");
        exit(EXIT_FAILURE);
    }

    return(p);
}
//=================AUXILLARY FUNCTION DEFINITIONS - END=================//
//=================SERVER OF BST - END=================//
//=================BINARY SEARCH TREE - END=================//