#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    //DONE
    //base case
    if( head == NULL){
        smaller = NULL;
        larger = NULL;
        return;
    }

    Node* next = head->next;

    //recursive call
    llpivot(next, smaller, larger, pivot); 

    
    if (head->val <= pivot){
        head->next = smaller;
        smaller = head;
    }
    else{
        head->next = larger;
        larger = head;
    }
    head = NULL; 
    return; 
}

