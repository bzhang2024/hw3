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
    if (head->val <= pivot){
        llpivot(next, smaller, larger, pivot);
        head->next = smaller;
        smaller = head;
    }
    else{
        llpivot(next, smaller, larger, pivot); 
        head->next = larger;
        larger = head;
    }
    head = NULL; 
}

