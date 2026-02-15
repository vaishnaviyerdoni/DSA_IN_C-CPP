#ifndef LIST_HPP
#define LIST_HPP

#include "list_exceptions.hpp"
#include <iostream>

class node
{
    friend class list;

    private:
        int data;
        node* next;
        node* prev;

        node(int _data);
        //CLIENT LA DIRECTLY NODE CHA INSTANCE BANAVTA YEU NAYE MHNUN CONSTRUCTOR PRIVATE KELA AHE

        //JAR OBJECT MADHLE MEMBERS KUTHLYAHI DYNAMICALLY ALLOCATED MEMORY LA POINT KARAT ASTIL TAR TE FREE KARAYLA DESTRUCTOR USE KARTAT
        //PAN ITHE TASE SARVA 
};

class list
{
    private:
        node* head_node;

        //GENERIC FUNCTIONS OR HELPER FUNCTIONS

        //CLASS SHI RELATED AHE PAN CLASS CHYA OBJECT VAR DIRECTLY KAM KARAT NAHIT MHNUN HE STATIC AHET
        //HYANA THIS POINTER CHI GARAJ NASTE KARAN HE TYA OBJECT VAR DIRECTLY KAM CH KARAT NAHIYE
        //PRIVATE AHE KARAN CLIENT LA HE FUNCTION DIRECTLY ACCESSIBLE NAKOY
        //GENERIC INSERT KUTHLAHI DILELA TYACHYA ADHICHYA AND NANTARCHYA NODE MADHE INSERT KARTO ANI DELETE KUTLAHI GIVEN NODE JO
        //LIST MADHE TO DELETE KARUN DETO MHUNU HE LIST SHI RELATED TARA AHET PAN DIRECTLY OBJECT VAR MHNJECH HEADNODE VAR KAM KARAT NAHI
        //HENCE THEY ARE STATIC
        static void generic_insert(node* p_start, node* p_mid, node* p_end);
        static void generic_delete(node* p_del_node);

        //HE CLASS CHYA OBJECT VAR KAM KARTO MHNUN HE STATIC NAHIYE
        //LIST MADHLA KUTHLAHI NODE SHODHUN HAVA ASEL TAR HE FUNCTION TE SHODHUN DETO
        //HENCE TO LIST SHI RELATED TAR AHECH PAN TYALA JYA LIST MADHUN NODE SHODHUN HAVA AHE TICHA ADDRESS PAN LAGTO
        //MHNUN HEADNODE CHA ADDRESS LAGEL MEANS THIS POINTER LAGEL HENCE ITS NOT STATIC

        //HE TINHI FUNCTIONS NODE LEVEL LA WORK KARTAT ANI CLIENT KUTHLAHI NODE LEVEL ALGORITHM ACCESSIBLE THEVAYCHA NAHIYE HENCE HE TINHI PRIVATE THEVAYCHE
        node* search_node(int search_data);
    
    public:
        list();
        ~list();

        void insert_start(int new_data);
        void insert_end(int new_data);
        void insert_after(int e_data, int n_data);
        void insert_before(int e_data, int n_data);

        void get_start(int* p_start_data);
        void get_end(int* p_end_data);
        void pop_start(int* p_start_data);
        void pop_end(int* p_end_data);

        void remove_start();
        void remove_end();
        void remove_data(int r_data);

        std::size_t size() const;
        bool empty() const;
        void show(const char* msg = 0);

        list* concat(list* other);
        list* merge(list* other);
        void append(list* other);

        static list* to_list(int* p_arr, std::size_t N);
        void to_array(int** pp_arr, std::size_t* pN);

        list* get_reversed_list() const;
        void reverse();
};

#endif