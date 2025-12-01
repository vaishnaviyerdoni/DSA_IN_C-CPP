struct node
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

/* 
    Description: 
        @input: 
            @data: new data value 
            @return: address of newly and dynamically allocated instance of struct node 
                    whose data member is initialized by parameter @data 
                    prev and node links should be initialized to zero 
*/
struct node* get_node(int data); 
struct node* get_node(int data)
{
    struct node* new_node = NULL;
    new_node -> data = data;
    new_node -> prev = 0;
    new_node -> next = 0;

    return new_node;
}

/* 
    @start_node and @end_node are adjecent nodes in a doubly linked list 
    @mid_node is a newly allocated node which is not a part of any linked list. 
    
    Insert node pointed by @mid_node between the nodes pointed by @start_node and 
    @end_node. 

    Also handle the following case: 
    end_node may be NULL. 
    start_node is NEVER NULL. 
*/
void generic_insert(struct node* start_node, struct node* mid_node, struct node* end_node); 
void generic_insert(struct node* start_node, struct node* mid_node, struct node* end_node)
{
    mid_node -> data = 100;

    //insert mid node after start node
    start_node -> next = mid_node;
    //mid node will point to previous node ie start node
    mid_node -> prev = start_node;

    //mid node will point to end_node
    mid_node -> next = end_node;
    //end_node will point to previous (mid) node
    end_node -> prev = mid_node;
    
}

/* 
    @delete_node points to a NON-DUMMY node in a linked list. 
    (to be explicit, delete_node != head_node)

    The function should detach node pointed by @delete_node from the linked list and release 
    its memory. The function should do these activies in such a way that rest of the nodes 
    in the linked list remain intact. 
*/
void generic_delete(struct node* delete_node)
{
        
}


/* 
    Search for search_data in the linked list pointed by 
    @head_node. 

    The function should return the first node having the
    occurrence of the search_data

    if search_data is not present in any of the node then 
    NULL should be returned 
*/
struct node* search_node(struct node* head_node, int search_data); 