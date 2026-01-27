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
    BST_NO_POSTORDER_SUCCESSOR      = -8, 
    LIST_EMPTY                      = -9, 
    STACK_EMPTY                     =  LIST_EMPTY, 
    QUEUE_EMPTY                     =  LIST_EMPTY
}; 
//=======================SYMBOLIC - CONSTANTS - END=======================

//=======================TYPEDEFS - START=======================
typedef int                 data_t; 
typedef enum status         status_t; 
typedef struct bst_node     bst_node_t; 
typedef struct bst          bst_t;
typedef struct bstptr_node  bstptr_node_t; 
typedef bstptr_node_t       bstptr_list_t; 
typedef bstptr_list_t       bstptr_stack_t; 
typedef bstptr_list_t       bstptr_queue_t; 
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

//  Definition of instance node of bst node pointer 
struct bstptr_node 
{
    bst_node_t* p_bst_node; 
    struct bstptr_node* prev; 
    struct bstptr_node* next; 
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
bst_node_t* search_nodelevel(bst_node_t* root_node, data_t search_data); 

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

//=======================INTERFACE FUNCTIONS FOR STACK OF BST NODE POINTERS=======================
bstptr_stack_t* create_bstptr_stack(void); 
status_t push_bstptr(bstptr_stack_t* p_bstptr_stack, bst_node_t* p_bst_node); 
status_t top_bstptr(bstptr_stack_t* p_bstptr_stack, bst_node_t** pp_bst_node); 
status_t pop_bstptr(bstptr_stack_t* p_bstptr_stack, bst_node_t** pp_bst_node); 
status_t is_bstptr_stack_empty(bstptr_stack_t* p_bstptr_stack); 
status_t destroy_bstptr_stack(bstptr_stack_t** pp_bstptr_stack); 

//=======================INTERFACE FUNCTIONS FOR STACK OF BST NODE POINTERS - END=======================

//=======================INTERFACE FUNCTIONS FOR QUEUE OF BST NODE POINTERS=======================
bstptr_queue_t* create_bstptr_queue(void); 
status_t insert_bstptr(bstptr_queue_t* p_bstptr_queue, bst_node_t* p_bst_node); 
status_t peek_bstptr(bstptr_queue_t* p_bstptr_queue, bst_node_t** pp_bst_node); 
status_t delete_bstptr(bstptr_queue_t* p_bstptr_queue, bst_node_t** pp_bst_node); 
status_t is_bstptr_queue_empty(bstptr_queue_t* p_bstptr_queue); 
status_t destroy_bstptr_queue(bstptr_queue_t** pp_bstptr_queue); 
//=======================INTERFACE FUNCTIONS FOR QUEUE OF BST NODE POINTERS - END =======================

//=======================INTERFACE FUNCTIONS FOR LINKED LIST OF BST NODE POINTERS=======================
bstptr_list_t* create_bstptr_list(void); 
status_t insert_bstptr_start(bstptr_list_t* p_bstptr_list, bst_node_t* p_bst_node); 
status_t insert_bstptr_end(bstptr_list_t* p_bstptr_list, bst_node_t* p_bst_node); 
status_t get_bstptr_start(bstptr_list_t* p_bstptr_list, bst_node_t** pp_bst_node); 
status_t get_bstptr_end(bstptr_list_t* p_bstptr_list, bst_node_t** pp_bst_node); 
status_t pop_bstptr_start(bstptr_list_t* p_bstptr_list, bst_node_t** pp_bst_node); 
status_t pop_bstptr_end(bstptr_list_t* p_bstptr_list, bst_node_t** pp_bst_node); 
status_t is_bstrptrlist_empty(bstptr_list_t* p_bstptr_list); 
status_t destroy_bstptr_list(bstptr_list_t** pp_list); 
//=======================INTERFACE FUNCTIONS FOR LINKED LIST OF BST NODE POINTERS - END=======================

//=======================AUXILLARY FUNCTIONS FOR LINKED LIST OF BST NODE POINTERS=======================
void generic_insert(bstptr_node_t* p_beg, bstptr_node_t* p_mid, bstptr_node_t* p_end); 
void generic_delete(bstptr_node_t* p_delete_node); 
//=======================AUXILLARY FUNCTIONS FOR LINKED LIST OF BST NODE POINTERS - END======================= 

//=======================GENERAL PURPOSE FUNCTIONS - START=======================
bst_node_t* get_bst_node(data_t new_data); 
bstptr_node_t* getbstptr_node(bst_node_t* p_bst_node); 
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
    data_t succ_data, pred_data; 

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

    for(index = 0; index < sizeof(data)/sizeof(data[0]); ++index)
    {
        status = inorder_predecessor(p_bst, data[index], &pred_data); 
        switch(status)
        {
            case SUCCESS: 
                printf("INORDER-PREDECESSOR(%d):%d\n", data[index], pred_data); 
                break; 
            case BST_DATA_NOT_FOUND: 
                printf("%d is not present in the given BST\n", data[index]); 
                break; 
            case BST_NO_INORDER_PREDECESSOR: 
                printf("%d is the first node in-order, thereofore, it has not predecessor\n", data[index]); 
                break; 
            default: 
                break; 
        }

        status = inorder_successor(p_bst, data[index], &succ_data); 
        switch(status)
        {
            case SUCCESS: 
                printf("INORDER-SUCCESSOR(%d):%d\n", data[index], succ_data); 
                break; 
            case BST_DATA_NOT_FOUND: 
                printf("%d is not present in the given BST\n", data[index]); 
                break; 
            case BST_NO_INORDER_SUCCESSOR: 
                printf("%d is the last node in-order, thereofore, it has not successor\n", data[index]); 
                break; 
            default: 
                break; 
        }
    }

    printf("Inorder traversal before starting element by element removal:\n"); 
    inorder(p_bst); 
    for(size_t index = 0; index < sizeof(data) / sizeof(data[0]); ++index)
    {
        status = remove_bst(p_bst, data[index]); 
        assert(status == SUCCESS); 
        printf("%d is successfully removed from tree\n", data[index]); 
        inorder(p_bst); 
    }

    assert(p_bst->root_node == NULL);   // This assertion is VERY IMPORTANT 

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
    free(p_bst); 
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

    run = search_nodelevel(p_bst->root_node, search_data); 
    return (run != NULL); 
}

//  Remove data from BST 
status_t remove_bst(bst_t* p_bst, data_t r_data)
{
    bst_node_t* z = NULL;   // For storing base address of node to be deleted 

    z = search_nodelevel(p_bst->root_node, r_data); 
    if(NULL == z)
        return (BST_DATA_NOT_FOUND); 

   
    if(z->left == NULL)                      /* Case I : Left subtree of z is empty, right subtree may or not may not be empty */
    {
        if(z->parent == NULL)               /*  Node to be deleted z itself is a root node */
            p_bst->root_node = z->right;    /*  Make right node a root of entire bst*/
        else if(z == z->parent->left)       /*  z has a parent and it is left child of its parent */
            z->parent->left = z->right;     /*  Delegate responsibility of right child to left pointer of  parent */
        else if(z == z->parent->right)      /*  z has a parent and it is right child of its parent */
            z->parent->right = z->right;    /*  Delegate responsibility of right child to right pointer of parnet*/
        
        if(z->right != NULL)                /*  z->right may or not may not be empty, therefore, the test */
            z->right->parent = z->parent;   /*  Make z->parent a parent of root of right subtree of z */
    }
    else if(z->right == NULL)               /*  Case II : Left subtree of z is not empty and right subtree of z is empty */
    {
        if(z->parent == NULL)               /*  Node to be deleted z itself is a root node */
            p_bst->root_node = z->left;     /*  Make left subtree of z to be a root of entire tree */
        else if(z == z->parent->left)       /*  z has a parent and it is a left child of its parent */
            z->parent->left = z->left;      /*  Delegate responsibility of left subtree to the left pointer of the parent */
        else if(z == z->parent->right)      /*  z has a parent and it is a right child of its parent */
            z->parent->right = z->left;     /*  Delegate responsibility of root node of left subtree to the right point of parent */

        z->left->parent = z->parent;        /*  We know that the z->left is not NULL, therefore, unconditionally set its parent 
                                                to the z->parent 
                                            */
    }
    else 
    {
        /*  Case - III : Both subtree of node to be deleted are not NULL */
        bst_node_t* u = z->right; 
        while(u->left != NULL)
            u = u->left; 
        /* After getting out of while loop, u is now an inorder successor of z */

        if(z->right != u)
        {
            /* 
                If inorder success 'u' of node to be deleted 'z' is a right child of z then 
                we *do not* delegate responsibility of u to its parent and we do not take 
                hold of right subtree z becuase u itself is a right subtree of z. 
            */
            /*  if inorder successor 'u' of node to be deleted 'z' is not a right child of z then 
                delegate responsibility of right child of u to the parent of u if right 
                child of u is not NULL
            */
            u->parent->left = u->right;             /*  Delegate u->right to u's parent */
            if(u->right != NULL)
                u->right->parent = u->parent;       /*  Make u->right accept u's parent as its parent */
            /* take hold of right subtree of z*/
            u->right = z->right;                    /*  Right subtree of z is now right subtree of u */
            u->right->parent = u;                   /*  Make root of right subtree z accept 'u' as its parent */
        }

        /* Take hold of left subtree of z*/
        u->left = z->left;                          /*  Left subtree of z is not a left subtree of u*/
        u->left->parent = u;                        /*  Make left subtree of z accept 'u' as its parent */

        /* Do setting with parent of z*/
        if(z->parent == NULL)                       /*  z is a root node */
            p_bst->root_node = u;                   /*  Make successor of z, viz. u, a root node of entire tree*/
        else if(z == z->parent->left)               /*  z has a parent and it is a left child of its parent */
            z->parent->left = u;                    /*  Delegate responsibility of u to left pointer of z's parent */
        else if(z == z->parent->right)              /*  z has a parent and it is a right child of its parent */
            z->parent->right = u;                   /*  Delegate responsibility of u to right pointer of z's parent */
        
        u->parent = z->parent;                      /*  Make u accept z's parent as its parent */
    }

    free(z);    /*  Release memory associated with node to be delete z */
    z = NULL;   /*  z is not a dangling pointer now */
    p_bst->nr_elements -= 1;    /* Decrement element count by 1 */

    return (SUCCESS); 
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
    bst_node_t* p_pred_node = NULL; 

    p_existing_node = search_nodelevel(p_bst->root_node, existing_data); 
    if(p_existing_node == NULL)
        return (BST_DATA_NOT_FOUND); 

    p_pred_node = inorder_predecessor_nodelevel(p_existing_node); 
    if(p_pred_node == NULL)
        return (BST_NO_INORDER_PREDECESSOR); 

    *p_pred_data = p_pred_node->data; 
    return (SUCCESS); 
}

status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data)
{
    bst_node_t* p_existing_node = NULL; 
    bst_node_t* p_succ_node = NULL; 

    p_existing_node = search_nodelevel(p_bst->root_node, existing_data); 
    if(p_existing_node == NULL)
        return (BST_DATA_NOT_FOUND); 

    p_succ_node = inorder_successor_nodelevel(p_existing_node); 
    if(p_succ_node == NULL)
        return (BST_NO_INORDER_SUCCESSOR); 

    *p_succ_data = p_succ_node->data; 
    return (SUCCESS); 
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

    if(p_bst->root_node == NULL)
        return (BST_EMPTY); 
    
    max_data_node = max_bst_nodelevel(p_bst->root_node); 
    *p_max_data = max_data_node->data; 

    return (SUCCESS); 
}

status_t min_bst(bst_t* p_bst, data_t* p_min_data)
{
    bst_node_t* min_data_node = NULL; 

    if(p_bst->root_node == NULL)
        return (BST_EMPTY); 

    min_data_node = min_bst_nodelevel(p_bst->root_node); 
    *p_min_data = min_data_node->data; 
    
    return (SUCCESS); 
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

bst_node_t* search_nodelevel(bst_node_t* root_node, data_t search_data)
{
    bst_node_t* run = NULL; 

    run = root_node; 
    while(run != NULL)
    {
        if(search_data == run->data)
            break; 
        else if(search_data < run->data)
            run = run->left; 
        else 
            run = run->right; 
    }

    return (run); 
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
    if(z->left != NULL)
        return (max_bst_nodelevel(z->left)); 

    x = z; 
    y = x->parent; 

    while(y != NULL && y->left == x)
    {
        x = y; 
        y = y->parent; 
    }

    return (y); 
}

bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node)
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->right != NULL)
        return (min_bst_nodelevel(z->right)); 

    x = z; 
    y = x->parent; 

    while(y != NULL && y->right == x)
    {
        x = y; 
        y = y->parent; 
    }

    return (y); 
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
    while(root_node->right != NULL)
        root_node = root_node->right; 
    return (root_node); 
}

bst_node_t* min_bst_nodelevel(bst_node_t* root_node)
{
    while(root_node->left != NULL)
        root_node = root_node->left; 
    return (root_node); 
}
//=======================AUXILLARY FUNCTION DECLARATIONS - END=======================

//=======================INTERFACE FUNCTIONS FOR STACK OF BST NODE POINTERS=======================
bstptr_stack_t* create_bstptr_stack(void)
{
    return (create_bstptr_list()); 
}

status_t push_bstptr(bstptr_stack_t* p_bstptr_stack, bst_node_t* p_bst_node)
{
    return (insert_bstptr_end(p_bstptr_stack, p_bst_node)); 
}

status_t top_bstptr(bstptr_stack_t* p_bstptr_stack, bst_node_t** pp_bst_node)
{
    return (get_bstptr_end(p_bstptr_stack, pp_bst_node)); 
}

status_t pop_bstptr(bstptr_stack_t* p_bstptr_stack, bst_node_t** pp_bst_node)
{
    return (pop_bstptr_end(p_bstptr_stack, pp_bst_node)); 
}

status_t is_bstptr_stack_empty(bstptr_stack_t* p_bstptr_stack)
{
    return (is_bstptrlist_empty(p_bstptr_stack)); 
}

status_t destroy_bstptr_stack(bstptr_stack_t** pp_bstptr_stack)
{
    return (destroy_bstptr_list(pp_bstptr_stack)); 
}

//=======================INTERFACE FUNCTIONS FOR STACK OF BST NODE POINTERS - END=======================

//=======================INTERFACE FUNCTIONS FOR QUEUE OF BST NODE POINTERS=======================
bstptr_queue_t* create_bstptr_queue(void)
{
    return (create_bstptr_list()); 
}

status_t insert_bstptr(bstptr_queue_t* p_bstptr_queue, bst_node_t* p_bst_node)
{
    return (insert_bstptr_end(p_bstptr_queue, p_bst_node));
}

status_t peek_bstptr(bstptr_queue_t* p_bstptr_queue, bst_node_t** pp_bst_node)
{
    return (get_start(p_bstptr_queue, pp_bst_node)); 
}

status_t delete_bstptr(bstptr_queue_t* p_bstptr_queue, bst_node_t** pp_bst_node)
{
    return (pop_start(p_bstptr_queue, pp_bst_node)); 
}

status_t is_bstptr_queue_empty(bstptr_queue_t* p_bstptr_queue)
{
    return (is_bstrptrlist_empty(p_bstptr_queue)); 
}

status_t destroy_bstptr_queue(bstptr_queue_t** pp_bstptr_queue)
{
    return (destroy_bstptr_list(pp_bstptr_queue)); 
}
//=======================INTERFACE FUNCTIONS FOR QUEUE OF BST NODE POINTERS - END =======================

//=======================INTERFACE FUNCTIONS FOR LINKED LIST OF BST NODE POINTERS=======================
bstptr_list_t* create_bstptr_list(void)
{
    bstptr_list_t* p_bstptr_list = NULL; 

    p_bstptr_list = getbstptr_node(NULL); 
    p_bstptr_list->prev = p_bstptr_list; 
    p_bstptr_list->next = p_bstptr_list; 

    return (p_bstptr_list); 
}

status_t insert_bstptr_start(bstptr_list_t* p_bstptr_list, bst_node_t* p_bst_node)
{
    generic_insert(p_bstptr_list, getbstptr_node(p_bst_node), p_bstptr_list->next);
    return (SUCCESS);  
}

status_t insert_bstptr_end(bstptr_list_t* p_bstptr_list, bst_node_t* p_bst_node)
{
    generic_insert(p_bstptr_list->prev, getbstptr_node(p_bst_node), p_bstptr_list); 
    return (SUCCESS); 
}

status_t get_bstptr_start(bstptr_list_t* p_bstptr_list, bst_node_t** pp_bst_node)
{
    if(p_bstptr_list->prev == p_bstptr_list && p_bstptr_list->next == p_bstptr_list)
        return (LIST_EMPTY); 

    *pp_bst_node = p_bstptr_list->next->p_bst_node; 

    return (SUCCESS); 
}   

status_t get_bstptr_end(bstptr_list_t* p_bstptr_list, bst_node_t** pp_bst_node)
{
    if(p_bstptr_list->prev == p_bstptr_list && p_bstptr_list->next == p_bstptr_list)
        return (LIST_EMPTY);   
    
    *pp_bst_node = p_bstptr_list->prev->p_bst_node; 

    return (SUCCESS); 
}

status_t pop_bstptr_start(bstptr_list_t* p_bstptr_list, bst_node_t** pp_bst_node)
{
    if(p_bstptr_list->prev == p_bstptr_list && p_bstptr_list->next == p_bstptr_list)
        return (LIST_EMPTY); 

    *pp_bst_node = p_bstptr_list->next->p_bst_node; 
    generic_delete(p_bstptr_list->next); 
    
    return (SUCCESS); 
}

status_t pop_bstptr_end(bstptr_list_t* p_bstptr_list, bst_node_t** pp_bst_node)
{
    if(p_bstptr_list->prev == p_bstptr_list && p_bstptr_list->next == p_bstptr_list)
        return (LIST_EMPTY); 

    *pp_bst_node = p_bstptr_list->prev->p_bst_node; 
    generic_delete(p_bstptr_list->prev); 

    return (SUCCESS); 
}

status_t is_bstrptrlist_empty(bstptr_list_t* p_bstptr_list)
{
    return (p_bstptr_list->prev == p_bstptr_list && p_bstptr_list->next == p_bstptr_list); 
}

status_t destroy_bstptr_list(bstptr_list_t** pp_list)
{
    bstptr_list_t* p_bstptr_list = NULL; 
    bstptr_node_t* run = NULL; 
    bstptr_node_t* run_next = NULL; 

    p_bstptr_list = *pp_list; 
    for(run = p_bstptr_list->next; run != p_bstptr_list; run = run_next)
    {
        run_next = run->next; 
        free(run); 
    }

    free(p_bstptr_list); 
    *pp_list = NULL; 

    return (SUCCESS); 
}
//=======================INTERFACE FUNCTIONS FOR LINKED LIST OF BST NODE POINTERS - END=======================

//=======================AUXILLARY FUNCTIONS FOR LINKED LIST OF BST NODE POINTERS=======================
void generic_insert(bstptr_node_t* p_beg, bstptr_node_t* p_mid, bstptr_node_t* p_end)
{
    p_mid->next = p_end; 
    p_mid->prev = p_beg; 
    p_beg->next = p_mid; 
    p_end->prev = p_mid; 
}

void generic_delete(bstptr_node_t* p_delete_node)
{   
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    free(p_delete_node); 
}
//=======================AUXILLARY FUNCTIONS FOR LINKED LIST OF BST NODE POINTERS - END======================= 

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

bstptr_node_t* getbstptr_node(bst_node_t* p_bst_node)
{
    bstptr_node_t* p_bstptr_node = NULL; 

    p_bstptr_node = (bstptr_node_t*)xmalloc(sizeof(bstptr_node_t)); 
    p_bstptr_node->p_bst_node = p_bst_node; 
    p_bstptr_node->prev = NULL; 
    p_bstptr_node->next = NULL; 

    return (p_bstptr_node);
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

