#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){

if(head != nullptr){
  int temp2 = head->val;
  llpivot(head->next,smaller,larger, pivot);

    if(temp2 <= pivot){  //smaller pivot
      Node* temp = smaller;
      smaller = head;
      smaller -> next = temp;
      head = nullptr;
    }
    if(temp2 > pivot){ //larger pivot
      Node* temp = larger;
      larger = head;
      larger -> next = temp;
      head = nullptr;
    }
  }else{
    larger = nullptr;
    smaller = nullptr;
  }
  
}



/*

  if(head != nullptr){

    if(head->val <= pivot){
      if(smaller == nullptr){
        smaller = head;
        head = head->next;
        smaller->next = nullptr;
        llpivot(head,smaller,larger,pivot);

      }else{
        smaller -> next = head;
        head = head ->next;
        smaller -> next -> next = nullptr;
        llpivot(head,smaller->next,larger,pivot);
      }

    }else if(head->val > pivot){
      if(larger == nullptr){
        larger = head;
        head = head->next;
        larger->next = nullptr;
        llpivot(head,smaller,larger,pivot);
      }else{
        larger -> next = head;
        head = head ->next;
        larger -> next -> next = nullptr;
        llpivot(head,smaller,larger->next,pivot);
      }

    }
}else{
  smaller = nullptr;
  larger = nullptr;
}
}
*/

