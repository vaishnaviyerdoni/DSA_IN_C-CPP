//=======================HEADER FILES - START=======================
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 
//=======================HEADER FILES - END=======================

//=======================SYMBOLIC - CONSTANTS - START=======================
enum status
{
    SUCCESS                         = 1, 
    TRUE                            = 1, 
    FALSE                           = 0, 
    BST_EMPTY                       = -1, 
    BST_DATA_NOT_FOUND              = -2,
    BST_NO_INORDER_PREDECESSOR      = -3, 
    BST_NO_INORDER_SUCCESSOR        = -4, 
    BST_NO_PREORDER_PREDECESSOR     = -5, 
    BST_NO_PREORDER_SUCCESSOR       = -6, 
    BST_NO_POSTORDER_PREDECESSOR    = -7, 
    BST_NO_POSTORDER_SUCCESSOR      = -8
}; 
//=======================SYMBOLIC - CONSTANTS - END=======================

//=======================TYPEDEFS - START=======================
typedef int             data_t; 
typedef enum status     status_t; 
typedef struct bst_node bst_node_t; 
typedef struct bst      bst_t;
//=======================TYPEDEFS - END=======================

//=======================INFORMATION STRUCTURE DEFINITIONS - START=======================
//  Definition of node of bst 
struct bst_node
{
    data_t data; 
    struct bst_node* left; 
    struct bst_node* right; 
    struct bst_node* parent; 
}; 

//  Definition of instance of bst 
struct bst 
{
    bst_node_t* root_node; 
    size_t nr_elements; 
}; 

//=======================INTERFACE FUNCTION DECLARATIONS - START=======================
//  Create and destroy data structure instance 
bst_t* create_bst(void); 
status_t destroy_bst(bst_t** pp_bst); 

//  Insert new data into BST
status_t insert_bst(bst_t* p_bst, data_t new_data); 

//  Search data in BST 
status_t search_bst(bst_t* p_bst, data_t search_data); 

//  Remove data from BST 
status_t remove_bst(bst_t* p_bst, data_t r_data); 

//  BST traversals - recursive
void preorder(bst_t* p_bst); 
void inorder(bst_t* p_bst); 
void postorder(bst_t* p_bst); 

//  Inorder predecessor and successor 
status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

//  Preorder predecessorr & successor 
status_t preorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t preorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

//  Postorder predecessor & successor 
status_t postorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t postorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

//  Minimum and maximum 
status_t max_bst(bst_t* p_bst, data_t* p_max_data); 
status_t min_bst(bst_t* p_bst, data_t* p_min_data); 

//  BST traversals - non-recursive 
void preorder_nrc(bst_t* p_bst); 
void inorder_nrc(bst_t* p_bst); 
void postorder_nrc(bst_t* p_bst); 
//=======================INTERFACE FUNCTION DECLARATIONS - END=========================

//=======================AUXILLARY FUNCTION DECLARATIONS - START=======================
void destroy_nodelevel(bst_node_t* root_node); 
bst_node_t* search_nodelevel(bst_node_t* root_node, data_t s_data);

void preorder_nodelevel(bst_node_t* root_node); 
void inorder_nodelevel(bst_node_t* root_node); 
void postorder_nodelevel(bst_node_t* root_node); 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node); 
bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node); 

bst_node_t* preorder_predecessor_nodelevel(bst_node_t* existing_node); 
bst_node_t* preorder_successor_nodelevel(bst_node_t* existing_node); 

bst_node_t* postorder_predecessor_nodelevel(bst_node_t* existing_node); 
bst_node_t* postorder_successor_nodelevel(bst_node_t* existing_node); 

bst_node_t* max_bst_nodelevel(bst_node_t* root_node); 
bst_node_t* min_bst_nodelevel(bst_node_t* root_node); 
//=======================AUXILLARY FUNCTION DECLARATIONS - END=======================

//=======================GENERAL PURPOSE FUNCTIONS - START=======================
bst_node_t* get_bst_node(data_t new_data); 
void* xmalloc(size_t size); 
//=======================GENERAL PURPOSE FUNCTIONS - END=======================

//=======================CLIENT SIDE - START=======================
void test_bst_normal(void); 
void test_bst_extreme(void); 

int main(void)
{
    test_bst_normal(); 

    #ifdef EXTREME_TESTING_ON
    test_bst_extreme(); 
    #endif  //  EXTREME_TESTING_ON 

    return (EXIT_SUCCESS); 
}

void test_bst_normal(void)
{
    bst_t* p_bst = NULL; 
    status_t status = SUCCESS; 
    data_t data[] = {100, 50, 150, 25, 75, 125, 200, 65, 130}; 
    data_t nonexistent_data[] = {-200, 34, 68, 98, 0xaabb, 0xf0f0f0f0}; 

    size_t index; 

    p_bst = create_bst(); 

    for(index = 0; index < sizeof(data)/sizeof(data[0]); ++index)
    {
        status = insert_bst(p_bst, data[index]); 
        assert(status == SUCCESS); 
        printf("insert_bst() for [%d] is successful\n", data[index]); 
    }

    preorder(p_bst); 
    inorder(p_bst); 
    postorder(p_bst); 

    for(index = 0; index < sizeof(data)/sizeof(data[0]); ++index)
    {
        status = search_bst(p_bst, data[index]); 
        assert(status == TRUE); 
        printf("Search for [%d] is successful\n", data[index]); 
    }

    for(index = 0; index < sizeof(nonexistent_data)/sizeof(nonexistent_data[0]); ++index)
    {
        status = search_bst(p_bst, nonexistent_data[index]); 
        assert(status == FALSE); 
        printf("Search for [%d] is not successful\n", nonexistent_data[index]); 
    }

    status = destroy_bst(&p_bst); 
    assert(status == SUCCESS && p_bst == NULL); 

    puts("Binary search tree destroyed successfully.");
    puts("Normal testing completed successfully. Returning");  
}

void test_bst_extreme(void)
{
    bst_t* p_bst = NULL; 
    data_t* p_data_array = NULL; 
    size_t N = 1000000; 
    status_t status; 
    data_t non_existent_data[] = {-100, -200, 32768, 100000, 1234567}; 


    /* Allocate memory to hold 100000 random integers */
    p_data_array = (data_t*)xmalloc(N * sizeof(data_t)); 
    
    /* Set the seed of random number generator */
    srand(time(0)); 

    /* Populate data array */
    for(size_t index = 0; index < N; ++index)
    {
        p_data_array[index] = rand(); 
    }

    /*  Allocate bst intance */
    p_bst = create_bst(); 

    for(size_t index = 0; index < N; ++index)
    {
        status = insert_bst(p_bst, p_data_array[index]); 
        assert(status == SUCCESS); 
        printf("insert_bst(): Successful for [%d]\n", p_data_array[index]); 
    }

    preorder(p_bst); 
    inorder(p_bst); 
    postorder(p_bst); 

    for(size_t index = 0; index < N; ++index)
    {
        status = search_bst(p_bst, p_data_array[index]); 
        assert(status == SUCCESS); 
        printf("Search for [%d] is successful\n", p_data_array[index]); 
    }

    for(size_t index = 0; index < sizeof(non_existent_data)/sizeof(non_existent_data[0]); ++index)
    {
        status = search_bst(p_bst, non_existent_data[index]); 
        assert(status == FALSE); 
        printf("Search of [%d] is not successful\n", non_existent_data[index]); 
    }

    status = destroy_bst(&p_bst); 
    assert(status == SUCCESS && p_bst == NULL); 

    free(p_data_array); 
    p_data_array = NULL;

    puts("Binary search tree destroyed successfully.");
    puts("Extreme testing completed successfully. Returning");  
}
//=======================CLIENT SIDE END=======================

//=======================INTERFACE FUNCTION DECLARATIONS - START=======================
//  Create and destroy data structure instance 
bst_t* create_bst(void)
{
    bst_t* new_bst = NULL; 

    new_bst = (bst_t*)xmalloc(sizeof(bst_t)); 
    new_bst->root_node = NULL; 
    new_bst->nr_elements = 0; 

    return (new_bst); 
}

status_t destroy_bst(bst_t** pp_bst)
{
    bst_t* p_bst = *pp_bst; 

    destroy_nodelevel(p_bst->root_node); 
    *pp_bst = NULL; 

    return (SUCCESS); 
}

//  Insert new data into BST
status_t insert_bst(bst_t* p_bst, data_t new_data)
{
    bst_node_t* new_node = NULL; 
    bst_node_t* run = NULL; 

    new_node = get_bst_node(new_data); 

    if(p_bst->root_node == NULL)
    {
        /* CASE I : Empty BST*/
        p_bst->root_node = new_node; 
        p_bst->nr_elements += 1; 
        return (SUCCESS); 
    }

    /* CASE II : Non-Empty BST */
    run = p_bst->root_node;
    while(TRUE)
    {
        if(new_data <= run->data)
        {
            if(run->left == NULL)
            {
                run->left = new_node; 
                run->left->parent = run; 
                break; 
            }

            run = run->left; 
        }
        else 
        {
            if(run->right == NULL)
            {
                run->right = new_node; 
                run->right->parent = run; 
                break; 
            }
            run = run->right; 
        }
    }

    p_bst->nr_elements += 1; 
    return (SUCCESS); 
}

//  Search data in BST 
status_t search_bst(bst_t* p_bst, data_t search_data)
{
    bst_node_t* run = NULL; 

    run = search_nodelevel(p_bst -> root_node, search_data);
    return(run != NULL);
}

//  Remove data from BST 
status_t remove_bst(bst_t* p_bst, data_t r_data)
{

}

//  BST traversals - recursive
void preorder(bst_t* p_bst)
{
    printf("PREORDER:[START]->"); 
    preorder_nodelevel(p_bst->root_node); 
    puts("[END]"); 
}

void inorder(bst_t* p_bst)
{
    printf("INORDER:[START]->"); 
    inorder_nodelevel(p_bst->root_node); 
    puts("[END]"); 
}

void postorder(bst_t* p_bst)
{
    printf("POSTORDER:[START]->"); 
    postorder_nodelevel(p_bst->root_node); 
    puts("[END]"); 
}

//  Inorder predecessor and successor 
status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data)
{
    bst_node_t* p_existing_node = NULL;
    bst_node_t* pred_node = NULL;
    p_existing_node = search_nodelevel(p_bst -> root_node, existing_data);

    if(p_existing_node == NULL)
        return(BST_DATA_NOT_FOUND);

    pred_node = inorder_predecessor_nodelevel(p_existing_node);
    if(pred_node == NULL)
        return(BST_NO_INORDER_PREDECESSOR);

    *p_pred_data =pred_node -> data;
    return(SUCCESS);
}

status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data)
{
    
}

//  Preorder predecessorr & successor 
status_t preorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data)
{

}

status_t preorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data)
{

}

//  Postorder predecessor & successor 
status_t postorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data)
{

}

status_t postorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data)
{

}

//  Minimum and maximum 
status_t max_bst(bst_t* p_bst, data_t* p_max_data)
{
    bst_node_t* max_data_node = NULL;

    if(p_bst -> root_node == NULL)
    {
        return(BST_EMPTY);
    }

    max_data_node = max_bst_nodelevel(p_bst -> root_node);
    *p_max_data =  max_data_node -> data;

    return (SUCCESS);
}

status_t min_bst(bst_t* p_bst, data_t* p_min_data)
{
    bst_node_t* min_data_node = NULL;

    if(p_bst -> root_node == NULL)
    {
        return(BST_EMPTY);
    }

    min_data_node = min_bst_nodelevel(p_bst -> root_node);
    *p_min_data = min_data_node -> data;

    return(SUCCESS);
}

//  BST traversals - non-recursive 
void preorder_nrc(bst_t* p_bst)
{

}

void inorder_nrc(bst_t* p_bst)
{

}

void postorder_nrc(bst_t* p_bst)
{

}
//=======================INTERFACE FUNCTION DECLARATIONS - END=========================

//=======================AUXILLARY FUNCTION DECLARATIONS - START=======================
void destroy_nodelevel(bst_node_t* root_node)
{
    if(root_node != NULL)
    {
        destroy_nodelevel(root_node->left); 
        destroy_nodelevel(root_node->right); 
        free(root_node); 
        root_node = NULL; 
    }
}

bst_node_t* search_nodelevel(bst_node_t* root_node, data_t s_data)
{
    bst_node_t* run = NULL;
    run = root_node;

    while(run != NULL)
    {
        if(s_data == run -> data)
            break;
        
        else if(s_data < run -> data)
            run = run -> left;
        else  
            run = run -> right;
    }

    return(run);
}

void preorder_nodelevel(bst_node_t* root_node)
{
    if(root_node != NULL)
    {
        printf("[%d]->", root_node->data); 
        preorder_nodelevel(root_node->left); 
        preorder_nodelevel(root_node->right); 
    }
}

void inorder_nodelevel(bst_node_t* root_node)
{
    if(root_node != NULL)
    {
        inorder_nodelevel(root_node->left); 
        printf("[%d]->", root_node->data); 
        inorder_nodelevel(root_node->right); 
    }
}

void postorder_nodelevel(bst_node_t* root_node)
{
    if(root_node != NULL)
    {
        postorder_nodelevel(root_node->left); 
        postorder_nodelevel(root_node->right); 
        printf("[%d]->", root_node->data); 
    }
}

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node)
{
    bst_node_t* x = NULL;
    bst_node_t* y = NULL;
    bst_node_t* z = NULL;
    
    z = existing_node;
    if(z -> leftt != NULL)
    {
        return(max_bst_nodelevel(z -> right));
    }

}

bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node)
{
    bst_node_t* x = NULL;
    bst_node_t* y = NULL;
    bst_node_t* z = NULL;
    
    z = existing_node;
    if(z -> right != NULL)
    {
        return(min_bst_nodelevel(z -> right));
    }

    x = z;
    y = x -> parent;

    while(y != NULL && y -> right == x)
    {

    }
}

bst_node_t* preorder_predecessor_nodelevel(bst_node_t* existing_node)
{

}

bst_node_t* preorder_successor_nodelevel(bst_node_t* existing_node)
{

}

bst_node_t* postorder_predecessor_nodelevel(bst_node_t* existing_node)
{

}

bst_node_t* postorder_successor_nodelevel(bst_node_t* existing_node)
{

}

bst_node_t* max_bst_nodelevel(bst_node_t* root_node)
{
    while(root_node -> right != NULL)
    {
        root_node = root_node -> left;
    }
}


bst_node_t* min_bst_nodelevel(bst_node_t* root_node)
{
    while ()
    {
        /* code */
    }
    
}
//=======================AUXILLARY FUNCTION DECLARATIONS - END=======================

//=======================GENERAL PURPOSE FUNCTIONS - START=======================
bst_node_t* get_bst_node(data_t new_data)
{
    bst_node_t* new_node = NULL; 

    new_node = (bst_node_t*)xmalloc(sizeof(bst_node_t)); 
    new_node->data = new_data; 
    new_node->left = NULL; 
    new_node->right = NULL; 
    new_node->parent = NULL; 

    return (new_node); 
}

void* xmalloc(size_t size)
{
    void* ptr = NULL; 

    ptr = malloc(size); 
    if(NULL == ptr)
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    }

    return (ptr); 
}
//=======================GENERAL PURPOSE FUNCTIONS - END=======================