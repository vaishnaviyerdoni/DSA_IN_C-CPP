//Header Files
#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <stdio.h>

#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>

#include <stdlib.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdlib.h>

#include <assert.h>
#include <assert.h>
#include <assert.h>
#include <assert.h>
#include <assert.h>

//Symbolic constants
#define SUCCESS 1
#define SUCCESS 1
#define SUCCESS 1
#define SUCCESS 1
#define SUCCESS 1

#define TRUE 1
#define TRUE 1
#define TRUE 1
#define TRUE 1
#define TRUE 1

#define FALSE 0
#define FALSE 0
#define FALSE 0
#define FALSE 0
#define FALSE 0

#define LIST_DATA_NOT_FOUND 2
#define LIST_DATA_NOT_FOUND 2
#define LIST_DATA_NOT_FOUND 2
#define LIST_DATA_NOT_FOUND 2
#define LIST_DATA_NOT_FOUND 2

#define LIST_EMPTY 3
#define LIST_EMPTY 3
#define LIST_EMPTY 3
#define LIST_EMPTY 3
#define LIST_EMPTY 3

//Node Layout Definition
struct node
{
    int data;
    struct node* next;
};

struct node
{
    int data;
    struct node* next;
};

struct node
{
    int data;
    struct node* next;
};

struct node
{
    int data;
    struct node* next;
};

struct node
{
    int data;
    struct node* next;
};

//Interface Functions Declarations
//List creation function
struct node* create_list(void);
struct node* create_list(void);
struct node* create_list(void);
struct node* create_list(void);
struct node* create_list(void);

//Data addition Functions

int insert_start(struct node* p_list, int new_data);
int insert_start(struct node* p_list, int new_data);
int insert_start(struct node* p_list, int new_data);
int insert_start(struct node* p_list, int new_data);
int insert_start(struct node* p_list, int new_data);

int insert_end(struct node* p_list, int new_data);
int insert_end(struct node* p_list, int new_data);
int insert_end(struct node* p_list, int new_data);
int insert_end(struct node* p_list, int new_data);
int insert_end(struct node* p_list, int new_data);

int insert_before(struct node* p_list, int existing_data, int new_data);
int insert_before(struct node* p_list, int existing_data, int new_data);
int insert_before(struct node* p_list, int existing_data, int new_data);
int insert_before(struct node* p_list, int existing_data, int new_data);
int insert_before(struct node* p_list, int existing_data, int new_data);

int insert_after(struct node* p_list, int existing_data, int new_data);
int insert_after(struct node* p_list, int existing_data, int new_data);
int insert_after(struct node* p_list, int existing_data, int new_data);
int insert_after(struct node* p_list, int existing_data, int new_data);
int insert_after(struct node* p_list, int existing_data, int new_data);

//Get Functions
int get_start(struct node* p_list, int* start_data);
int get_start(struct node* p_list, int* start_data);
int get_start(struct node* p_list, int* start_data);
int get_start(struct node* p_list, int* start_data);
int get_start(struct node* p_list, int* start_data);

int get_end(struct node* p_list, int* end_data);
int get_end(struct node* p_list, int* end_data);
int get_end(struct node* p_list, int* end_data);
int get_end(struct node* p_list, int* end_data);
int get_end(struct node* p_list, int* end_data);

//Pop Functions
int pop_end(struct node* p_list, int* end_data);
int pop_end(struct node* p_list, int* end_data);
int pop_end(struct node* p_list, int* end_data);
int pop_end(struct node* p_list, int* end_data);
int pop_end(struct node* p_list, int* end_data);

int pop_start(struct node* p_list, int* start_data);
int pop_start(struct node* p_list, int* start_data);
int pop_start(struct node* p_list, int* start_data);
int pop_start(struct node* p_list, int* start_data);
int pop_start(struct node* p_list, int* start_data);

//remove Functions
int remove_start(struct node* p_list);
int remove_start(struct node* p_list);
int remove_start(struct node* p_list);
int remove_start(struct node* p_list);
int remove_start(struct node* p_list);

int remove_end(struct node* p_list);
int remove_end(struct node* p_list);
int remove_end(struct node* p_list);
int remove_end(struct node* p_list);
int remove_end(struct node* p_list);

int remove_data(struct node* p_list, int r_data);
int remove_data(struct node* p_list, int r_data);
int remove_data(struct node* p_list, int r_data);
int remove_data(struct node* p_list, int r_data);
int remove_data(struct node* p_list, int r_data);

//Miscellaneous Functions
int find(struct node* p_list, int f_data);
int find(struct node* p_list, int f_data);
int find(struct node* p_list, int f_data);
int find(struct node* p_list, int f_data);
int find(struct node* p_list, int f_data);

int get_list_length(struct node* p_list);
int get_list_length(struct node* p_list);
int get_list_length(struct node* p_list);
int get_list_length(struct node* p_list);
int get_list_length(struct node* p_list);

int is_list_empty(struct node* p_list);
int is_list_empty(struct node* p_list);
int is_list_empty(struct node* p_list);
int is_list_empty(struct node* p_list);
int is_list_empty(struct node* p_list);

void show_list(struct node* p_list);
void show_list(struct node* p_list);
void show_list(struct node* p_list);
void show_list(struct node* p_list);
void show_list(struct node* p_list);

//List destruction functions
int destroy_list(struct node* p_list);
int destroy_list(struct node* p_list);
int destroy_list(struct node* p_list);
int destroy_list(struct node* p_list);
int destroy_list(struct node* p_list);