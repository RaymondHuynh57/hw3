#include "llrec.h"


//#include <iostream>
//*********************************************
// Provide your implementation of llpivot below
//*********************************************

/**
 * Given a linked list pointed to by head, creates two lists
 * where all values less than or equal to the pivot value are
 * placed in a linked list whose head will be pointed to by
 * smaller and all values greater than the pivot
 * value are placed in a linked list whose head will be pointed to
 * by larger.  The input list pointed to by head should be empty
 * upon return and head set to NULL (i.e. we are not making copies)
 * in the smaller and larger lists but simply moving Nodes out of
 * the input list and into the two other lists.
 * 
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @pre: smaller and larger may containing garbage (do NOT have
 *       to be NULL)
 *
 * @param[inout] head
 *   Reference to the head pointer to the input list.
 *   Should be set to NULL upon return
 * @param[out] smaller
 *   Reference to a head pointer for the list of nodes with values
 *   less than or equal to the pivot
 * @param[out] larger
 *   Reference to a head pointer for the list of nodes with values
 *   greater than the pivot
 * @param[in] pivot
 *   Pivot value
 *
 */
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
/*
    if(head == nullptr){  //EOL
        larger = nullptr;
        smaller = nullptr;
    }else{
        //Tail Recursion
        //std::cout << head->val << std::endl;

        
        if(head->val < pivot){
            smaller = head;
            llpivot(head->next, smaller->next, larger, pivot);
        }else if(head->val > pivot){
            larger = head;
            std::cout << "larger->val: " << larger->val << std::endl;
            llpivot(head->next, smaller, larger->next, pivot);
        }
        

        //head = nullptr;
        //llpivot(head->next, smaller->next, larger->next, pivot);
    }
  */
    llpivot_Helper(head, smaller, larger, pivot, 0);
}

void llpivot_Helper(Node *&head, Node *&smaller, Node *&larger, int pivot, int counter){


  
    if(head == nullptr){  //EOL
        larger = nullptr; //<----THIS IS THE PROBLEM
        smaller = nullptr;
    }else{
        //Tail Recursion
        //std::cout << head->val << std::endl;
        //std::cout << "RECURSION" << std::endl;
        if(head->val <= pivot){
            smaller = head;
            //std::cout << "head memory smaller: " << head << std::endl;
            llpivot_Helper(head->next, smaller->next, larger, pivot, counter + 1);
        }else if(head->val > pivot){
            larger = head;
            
            //std::cout << "larger->val: " << larger->val << std::endl;
            //std::cout << "head memory larger: " << head << std::endl;
            

            llpivot_Helper(head->next, smaller, larger->next, pivot, counter + 1);
            
        }
        
        

          if(counter == 0){ //This is the first part of the recursion where you will set head to nullptr
              head = nullptr;
          }
    }
    


/*
    if(head == nullptr){
        std::cout << "EOL" << std::endl;
    }else{
        std::cout << "RECURSION: " << head << std::endl;
        llpivot_Helper(head->next, smaller, larger, pivot, counter + 1);
        std::cout << "END RECURSION: " << head << std::endl;
        head = nullptr;
        std::cout << "END RECURSION 2: " << head << std::endl;
    }
*/
}

