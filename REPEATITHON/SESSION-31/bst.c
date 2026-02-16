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
    TRUE                         = 1,
    FALSE                        = 0,
    BST_DATA_NOT_FOUND           = -1,
    BST_EMPTY                    = -2,
    BST_NO_INORDER_SUCCESSOR     = -3,
    BST_NO_INORDER_PREDECESSOR   = -4,
    BST_NO_PREORDER_SUCCESSOR    = -5,
    BST_NO_PREORDER_PREDECESSOR  = -6,
    BST_NO_POSTORDER_SUCCESSOR   = -7,
    BST_NO_POSTORDER_PREDECESSOR = -8
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
bst_node_t* search_nodelevel(bst_node_t* root_node, data_t s_data);

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
    test_bst_normal();

    #ifdef EXTREME_TESTING_ON
    test_bst_extreme();
    #endif

    return(EXIT_SUCCESS);
}

//TEST
void test_bst_normal(void)
{
    bst_t* p_bst = NULL;
    status_t status;
    data_t data[] = {100, 50, 150, 25, 75, 125, 200, 65, 130};
    data_t data2[] = {100, 50, 150, 25, 12, 40, 45, 43, 47, 200, 175, 250};
    data_t non_existent_data[] = {-200, 34, 68, 98, 0xaabb, 0xf0f0f0f0};
    size_t index;
    data_t min_data, max_data, pred_data, succ_data;

    const char* line = "---------------------------------------------------------------";

    puts(line);
    printf("Normal Testing begins:\n");
    puts(line);


    p_bst = create_bst();
    printf("Binary Search Tree created successfully\n");
    puts(line);

    for(index = 0; index < sizeof(data)/sizeof(data[0]); ++index)
    {
        status = insert_bst(p_bst, data[index]);
        assert(status == SUCCESS);
        printf("insert_bst() for [%d] is successful\n", data[index]);
    }

    puts(line);

    inorder(p_bst);
    preorder(p_bst);
    postorder(p_bst);

    puts(line);

    for(index = 0; index < sizeof(data)/sizeof(data[0]); ++index)
    {
        status = search_bst(p_bst, data[index]);
        assert(status == TRUE);
        printf("Search of [%d] is successful\n", data[index]);
    }

    puts(line);

    for(index = 0; index < sizeof(non_existent_data)/sizeof(non_existent_data[0]); ++index)
    {
        status = search_bst(p_bst, non_existent_data[index]);
        assert(status == FALSE);
        printf("Search for [%d] is not successful as expected\n", non_existent_data[index]);
    }

    puts(line);

    assert(max_bst(p_bst, &max_data) == SUCCESS);
    printf("The maximum data element in the bst is %d\n", max_data);

    assert(min_bst(p_bst, &min_data) == SUCCESS);
    printf("The minimum data element in the bst is %d\n", min_data);

    puts(line);

    for(index = 0; index < sizeof(data)/sizeof(data[0]); ++index)
    {
        status = inorder_predecessor(p_bst, data[index], &pred_data);
        switch (status)
        {
            case SUCCESS:
                printf("INORDER PREDECESSOR(%d):%d\n", data[index], pred_data);
                break;
            case BST_DATA_NOT_FOUND:
                printf("%d is not present in the given BST.\n", data[index]);
            case BST_NO_INORDER_PREDECESSOR:
                printf("%d is the first node in inorder, hence it does not have a predecessor.\n");
            default:
                break;
        }
    }

    puts(line);

    for(index = 0; index < sizeof(data)/sizeof(data[0]); ++index)
    {
        status = inorder_successor(p_bst, data[index], &succ_data);
        switch (status)
        {
            case SUCCESS:
                printf("INORDER SUCCESSOR(%d):%d\n", data[index], succ_data);
                break;
            case BST_DATA_NOT_FOUND:
                printf("%d is not present in the given BST.\n", data[index]);
            case BST_NO_INORDER_SUCCESSOR:
                printf("%d is the last node in inorder, hence it does not have a successor.\n");
            default:
                break;
        }
    }

    puts(line);

    status = destroy_bst(&p_bst);
    assert(status == SUCCESS && p_bst == NULL);
    puts("Binary Search Tree Destroyed Successfully!");

    puts(line);
    puts("Normal Testing Ends");
    puts(line);
}

void test_bst_extreme(void)
{
    bst_t* p_bst = NULL;
    data_t* p_arr = NULL;
    size_t N = 1000000;
    status_t status;
    data_t max_data, min_data;
    data_t nonexistent_data[] = {-100, -200, 32768, 100000, 1234567};

    const char* line = "---------------------------------------------------------------";

    puts(line);
    printf("Extreme Testing begins:\n");
    puts(line);

    //Allocate memory to hold 1000000 random integers
    p_arr = (data_t*)xmalloc(N * sizeof(data_t));

    //Set the seed of random number generator
    srand(time(0));

    //Populate data array
    for(size_t index = 0; index < N; ++index)
    {
        p_arr[index] = rand();
    }

    //Allocate the bst instance 
    p_bst = create_bst();
    printf("Binary Search Tree created successfully\n");
    puts(line);

    for(size_t index = 0; index < N; ++index)
    {
        status = insert_bst(p_bst, p_arr[index]);
        assert(status == SUCCESS);
    }
    printf("Binary Search Tree populated successfully\n");
    puts(line);

    inorder(p_bst);
    preorder(p_bst);
    postorder(p_bst);
    
    puts(line);

    for(size_t index = 0; index < N; ++index)
    {
        status = search_bst(p_bst, p_arr[index]);
        assert(status == SUCCESS);
        printf("Search for [%d] is successful\n", p_arr[index]);
    }

    puts(line);

    for(size_t index = 0; index < sizeof(nonexistent_data)/sizeof(nonexistent_data[0]); ++index)
    {
        status = search_bst(p_bst, nonexistent_data[index]);
        assert(status == FALSE);
        printf("Search for [%d] is unsuccessful\n", nonexistent_data[index]);
    }

    puts(line);

    assert(max_bst(p_bst, &max_data) == SUCCESS);
    printf("The maximum data element in the bst is %d\n", max_data);

    assert(min_bst(p_bst, &min_data) == SUCCESS);
    printf("The minimum data element in the bst is %d\n", min_data);

    puts(line);

    status = destroy_bst(&p_bst);
    assert(status == SUCCESS && p_bst == NULL);

    puts("Binary Search Destroyed Successfully!");

    free(p_arr);
    p_arr = NULL;

    puts(line);
    puts("Extreme Testing Ends");
    puts(line);
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
    bst_node_t* run = NULL;

    run = search_nodelevel(p_bst -> root_node, s_data);
    return(run != NULL);
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
    bst_node_t* p_e_node = NULL;
    bst_node_t* p_succ_node = NULL;
    
    p_e_node = search_nodelevel(p_bst->root_node, e_data);
    if(p_e_node == NULL)
        return(BST_DATA_NOT_FOUND);

    p_succ_node = inorder_successor_nodelevel(p_e_node);
    if(p_succ_node == NULL)
        return(BST_NO_INORDER_SUCCESSOR);

    *succ_data = p_succ_node -> data;

    return(SUCCESS);
}

status_t inorder_predecessor(bst_t* p_bst, data_t e_data, data_t* pred_data)
{
    bst_node_t* p_e_node = NULL;
    bst_node_t* p_pred_node = NULL;

    p_e_node = search_nodelevel(p_bst -> root_node, e_data);
    if(p_e_node == NULL)
        return(BST_DATA_NOT_FOUND);

    p_pred_node = inorder_predecessor_nodelevel(p_e_node);
    if(p_pred_node == NULL)
        return(BST_NO_INORDER_PREDECESSOR);

    *pred_data = p_pred_node -> data;

    return(SUCCESS);
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
    *p_min_data = min_node -> data;

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
bst_node_t* search_nodelevel(bst_node_t* root_node, data_t s_data)
{
    bst_node_t* run = NULL;

    run = root_node;
    while(run != NULL)
    {
        if(run->data == s_data)
            break;
        else if(s_data < run->data)
            run = run -> left;
        else
            run = run -> right;
    }

    return(run);
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
    bst_node_t* x = NULL;
    bst_node_t* y = NULL;
    bst_node_t* z = NULL;

    z = e_node;
    if(z -> right != NULL)
        return(min_bst_nodelevel(z -> right));

    x = z;
    y = x -> parent;
    while(y != NULL && y -> right == x)
    {
        x = y;
        y = y->parent;
    }

    return(y);
}

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* e_node)
{   
    bst_node_t* x = NULL;
    bst_node_t* y = NULL;
    bst_node_t* z = NULL;

    z = e_node;
    if(z->left != NULL)
        return(max_bst_nodelevel(z->left));

    x = z;
    y = x -> parent;
    while(y != NULL && y -> left == x)
    {
        x = y;
        y = y -> parent;
    }

    return(y);
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
    while(run->right != NULL)
    {
        run = run -> right;
    }

    return(run);
}

bst_node_t* min_bst_nodelevel(bst_node_t* root_node)
{
    bst_node_t* run = NULL;

    run = root_node;
    while(run->left != NULL)
    {
        run = run -> left;
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
        puts("xmalloc():malloc():Allocation Error");
        exit(EXIT_FAILURE);
    }

    return(p);
}