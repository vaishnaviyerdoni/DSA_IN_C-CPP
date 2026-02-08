//1
#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <stdio.h>

//2
#include <stdlib.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdlib.h>

//3
#include <assert.h>
#include <assert.h>
#include <assert.h>
#include <assert.h>
#include <assert.h>

//4
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>

//1
enum status
{
    SUCCESS                      = 1,
    TRUE                         = 1,
    FALSE                        = 0,
    BST_EMPTY                    = -1,
    BST_NO_INORDER_PREDECESSOR   = -2,
    BST_NO_INORDER_SUCCESSOR     = -3,
    BST_NO_PREORDER_PREDECESSOR  = -4,
    BST_NO_PREORDER_SUCCESSOR    = -5,
    BST_NO_POSTORDER_PREDECESSOR = -6,
    BST_NO_POSTORDER_SUCCESSOR   = -7
};

//2
enum status
{
    SUCCESS                      = 1,
    TRUE                         = 1,
    FALSE                        = 0,
    BST_EMPTY                    = -1,
    BST_NO_INORDER_PREDECESSOR   = -2,
    BST_NO_INORDER_SUCCESSOR     = -3,
    BST_NO_PREORDER_PREDECESSOR  = -4,
    BST_NO_PREORDER_SUCCESSOR    = -5,
    BST_NO_POSTORDER_PREDECESSOR = -6,
    BST_NO_POSTORDER_SUCCESSOR   = -7
};

//3
enum status
{
    SUCCESS                      = 1,
    TRUE                         = 1,
    FALSE                        = 0,
    BST_EMPTY                    = -1,
    BST_NO_INORDER_PREDECESSOR   = -2,
    BST_NO_INORDER_SUCESSOR      = -3,
    BST_NO_PREORDER_PREDECESSOR  = -4,
    BST_NO_PREORDER_SUCESSOR     = -5,
    BST_NO_POSTORDER_PREDECESSOR = -6,
    BST_NO_POSTORDER_SUCCESSOR   = -7 
};

//4
enum status
{
    SUCCESS                      = 1,
    TRUE                         = 1,
    FALSE                        = 0,
    BST_EMPTY                    = -1,
    BST_NO_INORDER_PREDECESSOR   = -2,
    BST_NO_INORDER_SUCCESSOR     = -3,
    BST_NO_PREOREDER_PREDECESSOR = -4,
    BST_NO_PREOREDER_SUCCESSOR   = -5,
    BST_NO_POSTORDER_PREDECESSOR = -6,
    BST_NO_POSTORDER_SUCCESSOR   = -7
};

//5
enum status
{
    SUCCESS                      = 1,
    TRUE                         = 1,
    FALSE                        = 0,
    BST_EMPTY                    = -1,
    BST_NO_INORDER_PREDECESSOR   = -2,
    BST_NO_INORDER_SUCCESSOR     = -3,
    BST_NO_PREORDER_PREDECESSOR  = -4,
    BST_NO_PREORDER_SUCCESSOR    = -5,
    BST_NO_POSTORDER_PREDECESSOR = -6,
    BST_NO_POSTORDER_SUCCESSOR   = -7
};

//1
typedef int              data_t;
typedef enum status      status_t;
typedef struct bst_node  bst_node_t;
typedef struct bst       bst_t;

//2
typedef int              data_t;
typedef enum status      status_t;
typedef struct bst_node  bst_node_t;
typedef struct bst       bst_t;

//3
typedef int              data_t;
typedef enum status      status_t;
typedef struct bst_node  bst_node_t;
typedef struct bst       bst_t;

//4
typedef int              data_t;
typedef enum status      status_t;
typedef struct bst_node  bst_node_t;
typedef struct bst       bst_t;

//5
typedef int              data_t;
typedef enum status      status_t;
typedef struct bst_node  bst_node_t;
typedef struct bst       bst_t;

//1
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

//2
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

//3
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

//4
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

//5
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

//1
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

//2
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

//3
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

//4
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

//5 
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

//1
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

//2
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

//3
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

//4
bst_node_t* get_node(data_t n_data)
{
    bst_node_t* new_node = NULL;
    new_node = (bst_node_t*)xmalloc(sizeof(bst_node_t*));

    new_node -> data = n_data;
    new_node -> left = NULL;
    new_node -> right = NULL;
    new_node -> parent = NULL;

    return(new_node);
}

//5
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

//1
bst_t* create_bst(void)
{
    bst_t* p_bst = NULL;
    p_bst = (bst_t*)xmalloc(sizeof(bst_t));

    p_bst -> root_node = NULL;
    p_bst -> nr_elements = 0;

    return(p_bst);
}

//2
bst_t* create_bst(void)
{
    bst_t* p_bst = NULL;
    p_bst = (bst_t*)xmalloc(sizeof(bst_t));

    p_bst -> root_node = NULL;
    p_bst -> nr_elements = 0;

    return(p_bst);
}

//3
bst_t* create_bst(void)
{
    bst_t* p_bst = NULL;
    p_bst = (bst_t*)xmalloc(sizeof(bst_t));

    p_bst -> root_node = NULL;
    p_bst -> nr_elements = 0;

    return(p_bst);
}

//4
bst_t* create_bst(void)
{
    bst_t* p_bst = NULL;
    p_bst = (bst_t*)xmalloc(sizeof(bst_t));

    p_bst -> root_node = NULL;
    p_bst -> nr_elements = 0;

    return(p_bst);
}

//5
bst_t* create_bst(void)
{
    bst_t* p_bst = NULL;
    p_bst = (bst_t*)xmalloc(sizeof(bst_t));

    p_bst -> root_node = NULL;
    p_bst -> nr_elements = 0;

    return(p_bst);
}

//1
status_t insert_bst(bst_t* p_bst, data_t n_data)
{
    bst_node_t* new_node = NULL;
    bst_node_t* run = NULL;

    new_node = get_node(n_data);

    //CASE 1 - EMPTY BST
    if(p_bst -> root_node == NULL)
    {
        p_bst -> root_node = new_node;
        p_bst -> nr_elements += 1;
        return(SUCCESS);
    }

    //CASE 2 - NON EMPTY BST
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

//2
status_t insert_bst(bst_t* p_bst, data_t n_data)
{
    bst_node_t* run = NULL;
    bst_node_t* new_node = NULL;

    new_node = get_node(n_data);

    //CASE 1 - EMPTY BST
    if(p_bst -> root_node == NULL)
    {
        p_bst -> root_node = new_node;
        p_bst -> nr_elements += 1;
        return(SUCCESS);
    }

    //CASE 2 - NON EMPTY BST
    run = p_bst -> root_node;
    while(TRUE)
    {
        if(n_data <= p_bst -> root_node)
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

//3
status_t insert_bst(bst_t* p_bst, data_t n_data)
{
    bst_node_t* new_node = NULL;
    bst_node_t* run = NULL;

    new_node = get_node(n_data);

    //CASE 1 - EMPTY BST
    if(p_bst -> root_node == NULL)
    {
        p_bst -> root_node = new_node;
        p_bst -> nr_elements += 1;
        return(SUCCESS);
    }

    //CASE 2 - NON EMPTY BST
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

//4
status_t insert_bst(bst_t* p_bst, data_t n_data)
{
    bst_node_t* new_node = NULL;
    bst_node_t* run = NULL;

    new_node = get_node(n_data);

    //CASE 1 - EMPTY BST
    if(p_bst -> root_node == NULL)
    {
        p_bst -> root_node = new_node;
        p_bst -> nr_elements += 1;
        return(SUCCESS);
    }

    //CASE 2 - NON EMPTY BST
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

//5
status_t insert_bst(bst_t* p_bst, data_t n_data)
{
    bst_node_t* new_node = NULL;
    bst_node_t* run = NULL;

    new_node = get_node(n_data);

    //CASE 1 - EMPTY BST
    if(p_bst -> root_node == NULL)
    {
        p_bst -> root_node = new_node;
        p_bst -> nr_elements += 1;
        return(SUCCESS);
    }

    //CASE 2 - NON EMPTY BST
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

//1
status_t search_bst(bst_t* p_bst, data_t s_data)
{
    bst_node_t* run = NULL;

    run = p_bst -> root_node;
    while(run != NULL)
    {
        if(run -> data == s_data)
            return(TRUE);
        
        else if(run -> data < s_data)
            run = run -> left;

        else
            run = run -> right;
    }

    return(FALSE);
}

//2
status_t search_bst(bst_t* p_bst, data_t s_data)
{
    bst_node_t* run = NULL;

    run = p_bst -> root_node;
    while(run != NULL)
    {
        if(run -> data == s_data)
            return(TRUE);
        
        else if(run -> data < s_data)
            run = run -> left;

        else   
            run = run -> right;
    }

    return(FALSE);
}

//3
status_t search_bst(bst_t* p_bst, data_t s_data)
{
    bst_node_t* run = NULL;

    while(run != NULL)
    {
        if(run -> data == s_data)
            return(TRUE);
        
        else if(run -> data < s_data)
            run = run -> left;
        
        else   
            run = run -> right;
    }

    return(FALSE);
}

//4
status_t search_bst(bst_t* p_bst, data_t s_data)
{
    bst_node_t* run = NULL;

    run = p_bst -> root_node;
    while(run != NULL)
    {
        if(run -> data == s_data)
            return(TRUE);
        
        else if(run -> data < s_data)
            run = run -> left;
        
        else   
            run = run -> right;
    }

    return(FALSE);
}

//5
status_t search_bst(bst_t* p_bst, data_t s_data)
{
    bst_node_t* run = NULL;

    run = p_bst -> root_node;
    while(run != NULL)
    {
        if(run -> data == s_data)
            return(TRUE);

        else if(run -> data < s_data)
            run = run -> left;

        else
            run = run -> right;
    }

    return(FALSE);
}