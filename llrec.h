#ifndef LLREC_H
#define LLREC_H
#ifndef NULL
#define NULL 0
#endif

#include <iostream>

/**
 * Node struct for both problems
 */
struct Node
{
    int val;
    Node *next;

    Node(int v, Node* n) : val(v), next(n) {}
};


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
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot);
void llpivot_Helper(Node *&head, Node *&smaller, Node *&larger, int pivot, int counter);
/**
 * Given a linked list pointed to by head, removes (filters out) nodes
 * whose value does not meet the criteria given by the predicate
 * function object, pred (i.e. pred should be a function object that implements
 * `bool operator()(int value)` and returns *true* for items that should
 * be *removed/filtered*.  Removed items should be deallocated.
 *
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @param[in] head
 *   Reference to the head pointer to the input list.
 * @param[in] pred
 *   Predicate object implementing: `bool operator()(int value)` that
 *   returns true if a node (based on its value) should be removed.
 * @return a head pointer to the resulting list (since the head pointer
 *   may change [i.e. be filtered])
 *
 */
template <typename Comp>
Node* llfilter(Node* head, Comp pred);

//*****************************************************************************
// Since template implementations should be in a header file, we will
// implement the above function now.
//*****************************************************************************


template <typename Comp>
Node* llfilter(Node* head, Comp pred)
{
    //*********************************************
    // Provide your implementation below
    //*********************************************
/*
  if(head == nullptr){  //EOL
      std::cout << "EOL" << std::endl;
      return head;
  }else{
    //Most Likely have to use head recursion
      //Tail Recursion
      
     // Node* temp = head;
      if(pred(head->val)){
          std::cout << head->val << " is not 8" << std::endl;

          //head = head->next;
          //delete temp;
      }else{
          std::cout << head->val << " is 8" << std::endl;
          //head = head->next;
      }

      
      
      return llfilter(head->next, pred);  //Don't return here
     

  }
*/
    //Node* filter = new Node(0, nullptr);
    Node* filter = nullptr;
    return llfilter_Helper(head, filter, pred);
}

template <typename Comp>
Node* llfilter_Helper(Node* head, Node*& filter_temp, Comp pred){
    //Node* temp = new Node(head->val, )
     //*********************************************
    // Provide your implementation below
    //*********************************************
  if(head == nullptr){  //EOL
      //EXTRA
      filter_temp = nullptr;
      //EXTRA
      //std::cout << "nullptr" << std::endl;
      return nullptr;
  }else{
    //Most Likely have to use head recursion
      //Tail Recursion

    /*
      if(pred(head->val)){
          //filter_temp = new Node(head->val, llfilter_Helper(head->next, filter_temp, pred));  //Tail Recursion so start from back or EOL. Use Tail Recursion to fill up another linked list with new Nodes
          //return filter_temp;
          return llfilter_Helper(head->next, filter_temp, pred);
      }else{
          filter_temp = new Node(head->val, llfilter_Helper(head->next, filter_temp, pred));  //Tail Recursion so start from back or EOL. Use Tail Recursion to fill up another linked list with new Nodes
          return filter_temp;

          //std::cout << head->val << " is 8" << std::endl;
          //return llfilter_Helper(head->next, filter_temp, pred);
      }
    */
    
    //std::cout << head->val << std::endl;
    Node* temp = nullptr;
    if(pred(head->val)){  //Filter out
        //std::cout << "FILTER BEFORE filter_temp->val: " << filter_temp->val << std::endl;
        temp = llfilter_Helper(head->next, filter_temp, pred);
        //std::cout << "FILTER AFTER filter_temp->val: " << filter_temp->val << std::endl;
        delete head;
        return filter_temp;
    }else{  //Keep
        filter_temp = head;
        //std::cout << "KEEP BEFORE head->val: " << head->val << std::endl;
        temp = llfilter_Helper(head->next, filter_temp->next, pred);
        //std::cout << "KEEP AFTER head->val: " << head->val << std::endl;
        //std::cout << "FILTER_TEMP ELSE->val: " << filter_temp->val << std::endl;
        return filter_temp;
    }
     

  }
}

#endif
