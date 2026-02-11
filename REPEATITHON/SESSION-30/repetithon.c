//HEADER FILES - FUNCTION DECLARATIONS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>

//SYMBOLIC CONSTANTS
enum status
{
    SUCCESS                      = 1,
    TRUE                         = 2,
    FALSE                        = 0,
    BST_EMPTY                    = -1,
    BST_NO_INORDER_SUCCESSOR     = -2,
    BST_NO_INORDER_PREDECESSOR   = -3,
    BST_NO_PREORDER_SUCCESSOR    = -4,
    BST_NO_PREORDER_PREDECESSOR  = -5,
    BST_NO_POSTORDER_SUCCESSOR   = -6,
    BST_NO_POSTORDER_PREDECESSOR = -7
};

//TYPEDEFS
typedef int             data_t;
typedef enum status     status_t;

typedef struct bst      bst_t;
typedef struct bst_node bst_node_t;

//INFORMATION STRUCTURE DEFINITION
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

//INTERFACE FUNCTIONS
//CREATE AND DESTROY
bst_t* create_bst(void);
status_t destroy_bst(bst_t** pp_bst);

//INSERT DATA ALGORITHM
status_t insert_bst(bst_t* p_bst, data_t n_data);

//SEARCH DATA ALGORITHM
status_t search_bst(bst_t* p_bst, data_t s_data);

//REMOVE DATA ALGORITHM
status_t remove_bst(bst_t* p_bst, data_t r_data);

//BST - TRAVERSALS :- RECURSIVE
void inorder(bst_t* p_bst);
void preorder(bst_t* p_bst);
void postorder(bst_t* p_bst);

//BST - TRAVERSALS :- NON RECURSIVE
void inorder_nrc(bst_t* p_bst);
void preorder_nrc(bst_t* p_bst);
void postorder_nrc(bst_t* p_bst);

//INORDER SUCCESSOR AND PREDECESSOR
status_t inorder_successor(bst_t* p_bst, data_t e_data, data_t* succ_data);
status_t inorder_predecessor(bst_t* p_bst, data_t e_data, data_t* pred_data);

//PREORDER SUCCESSOR AND PREDECESSOR
status_t preorder_successor(bst_t* p_bst, data_t e_data, data_t* succ_data);
status_t preorder_predecessor(bst_t* p_bst, data_t e_data, data_t* pred_data);

//POSTORDER SUCCESSOR AND PREDECESSOR
status_t postorder_successor(bst_t* p_bst, data_t e_data, data_t* succ_data);
status_t postorder_predecessor(bst_t* p_bst, data_t e_data, data_t* pred_data);

//MINIMUN AND MAXIMUM ALGORITHMS
status_t max_bst(bst_t*  p_bst, data_t* p_max_data);
status_t min_bst(bst_t* p_bst, data_t* p_min_data);

//NODE LEVEL ALGORITHMS
//DESTROY
void destroy_nodelevel(bst_node_t* root_node);

//SEARCH
void search_nodelevel(bst_node_t* root_node, data_t s_data);

//TRAVERSALS
void inorder_nodelevel(bst_node_t* root_node);
void preorder_nodelevel(bst_node_t* root_node);
void postorder_nodelevel(bst_node_t* root_node);

//NODELEVEL INORDER SUCCESSOR AND PREDECESSOR
bst_node_t* inorder_successor_nodelevel(bst_node_t* e_node);
bst_node_t* inorder_predecessor_nodelevel(bst_node_t* e_node);

//NODELEVEL PREORDER SUCCESSOR AND PREDECESSOR
bst_node_t* preorder_successor_nodelevel(bst_node_t* e_node);
bst_node_t* preorder_predecessor_nodelevel(bst_node_t* e_node);

//NODELEVEL POSTORDER SUCCESSOR AND PREDECESSOR
bst_node_t* postorder_successor_nodelevel(bst_node_t* e_node);
bst_node_t* postorder_predecessor_nodelevel(bst_node_t* e_node);

//MINIMUM AND MAXIMUM NODELEVEL
bst_node_t* max_bst_nodelevel(bst_node_t* root_node);
bst_node_t* min_bst_nodelevel(bst_node_t* root_node);

//AUXILLARY FUNCTIONS
bst_node_t* get_bst_node(data_t n_data);
void* xmalloc(size_t size);

//TEST
void test_bst_normal(void);
void test_bst_extreme(void);

int main(void)
{
    return(EXIT_SUCCESS);
}

//TEST
void test_bst_normal(void)
{

}

void test_bst_extreme(void)
{
    
}

//INTERFACE FUNCTIONS
//CREATE AND DESTROY
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

//INSERT DATA ALGORITHM
status_t insert_bst(bst_t* p_bst, data_t n_data)
{
    bst_node_t* run = NULL;
    bst_node_t* new_node = NULL;

    new_node = get_bst_node(n_data);

    //case 1 - bst is empty
    if(p_bst -> root_node == NULL)
    {
        p_bst -> root_node = new_node;
        p_bst -> nr_elements += 1;
        return(SUCCESS);
    }

    //case 2 - bst is not empty
    run = p_bst -> root_node;
    while(TRUE)
    {
        if(n_data <= run -> data)
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

//SEARCH DATA ALGORITHM
status_t search_bst(bst_t* p_bst, data_t s_data)
{
    bst_node_t* s_node = NULL;

    s_node = search_nodelevel(p_bst -> root_node, s_data);
    return(s_node != NULL);
}

//REMOVE DATA ALGORITHM
status_t remove_bst(bst_t* p_bst, data_t r_data)
{

}

//BST - TRAVERSALS :- RECURSIVE
void inorder(bst_t* p_bst)
{
    printf("INORDER : [START] ->");
    inorder_nodelevel(p_bst -> root_node);
    puts("[END]");
}

void preorder(bst_t* p_bst)
{
    printf("PREORDER : [START] ->");
    preorder_nodelevel(p_bst -> root_node);
    puts("[END]");
}

void postorder(bst_t* p_bst)
{
    printf("POSTORDER : [START] ->");
    postorder_nodelevel(p_bst -> root_node);
    puts("[END]");
}

//BST - TRAVERSALS :- NON RECURSIVE
void inorder_nrc(bst_t* p_bst)
{

}

void preorder_nrc(bst_t* p_bst)
{

}

void postorder_nrc(bst_t* p_bst)
{

}

//INORDER SUCCESSOR AND PREDECESSOR
status_t inorder_successor(bst_t* p_bst, data_t e_data, data_t* succ_data)
{

}

status_t inorder_predecessor(bst_t* p_bst, data_t e_data, data_t* pred_data)
{

}

//PREORDER SUCCESSOR AND PREDECESSOR
status_t preorder_successor(bst_t* p_bst, data_t e_data, data_t* succ_data)
{

}

status_t preorder_predecessor(bst_t* p_bst, data_t e_data, data_t* pred_data)
{

}

//POSTORDER SUCCESSOR AND PREDECESSOR
status_t postorder_successor(bst_t* p_bst, data_t e_data, data_t* succ_data)
{

}

status_t postorder_predecessor(bst_t* p_bst, data_t e_data, data_t* pred_data)
{

}

//MINIMUN AND MAXIMUM ALGORITHMS
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

    min_node = min_bst_nodelevel(p_bst->root_node);
    *min_node = min_node -> data;

    return(SUCCESS);
}

//NODE LEVEL ALGORITHMS
//DESTROY
void destroy_nodelevel(bst_node_t* root_node)
{
    if(root_node != NULL)
    {
        destroy_nodelevel(root_node -> left);
        destroy_nodelevel(root_node -> right);
        free(root_node);
    }
}

//SEARCH
void search_nodelevel(bst_node_t* root_node, data_t s_data)
{
    bst_node_t* run = NULL;

    run = root_node;
    while(run != NULL)
    {
        if(run -> data == s_data)
            return(run);

        else if(run -> data < s_data)
            run = run -> left;

        else
            run = run -> right;
    }

    return(NULL);
}


//TRAVERSALS
void inorder_nodelevel(bst_node_t* root_node) //left, root, right
{
    if(root_node != NULL)
    {
        inorder_nodelevel(root_node -> left);
        printf("[%d] ->", root_node -> data);
        inorder_nodelevel(root_node -> right);
    }
}

void preorder_nodelevel(bst_node_t* root_node) //root, left, right
{
    if(root_node != NULL)
    {
        printf("[%d] ->", root_node -> data);
        preorder_nodelevel(root_node -> left);
        preorder_nodelevel(root_node -> right);
    }
}

void postorder_nodelevel(bst_node_t* root_node) //left, right, root
{
    if(root_node != NULL)
    {
        postorder_nodelevel(root_node -> left);
        postorder_nodelevel(root_node -> right);
        printf("[%d] ->", root_node -> data);
    }
}

//NODELEVEL INORDER SUCCESSOR AND PREDECESSOR
bst_node_t* inorder_successor_nodelevel(bst_node_t* e_node)
{

}

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* e_node)
{

}

//NODELEVEL PREORDER SUCCESSOR AND PREDECESSOR
bst_node_t* preorder_successor_nodelevel(bst_node_t* e_node)
{

}

bst_node_t* preorder_predecessor_nodelevel(bst_node_t* e_node)
{

}

//NODELEVEL POSTORDER SUCCESSOR AND PREDECESSOR
bst_node_t* postorder_successor_nodelevel(bst_node_t* e_node)
{

}

bst_node_t* postorder_predecessor_nodelevel(bst_node_t* e_node)
{

}


//MINIMUM AND MAXIMUM NODELEVEL
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
        run = run -> right;
    }

    return(run);
}

//AUXILLARY FUNCTIONS
bst_node_t* get_bst_node(data_t n_data)
{
    bst_node_t* n_node = NULL;
    n_node = (bst_node_t*)xmalloc(sizeof(bst_node_t));

    n_node -> data = n_data;
    n_node -> left = NULL;
    n_node -> right = NULL;
    n_node -> parent = NULL;

    return(n_node);
}

void* xmalloc(size_t size)
{
    void* p = NULL;
    p = malloc(size);

    if(p == NULL)
    {
        puts("xmalloc()Lmalloc():Allocation Error");
        exit(EXIT_FAILURE);
    }

    return(p);
}