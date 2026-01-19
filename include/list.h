#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int val;
    struct Node* next;
} Node;

/*@ ghost
  typedef struct list_shape {
      Node** cell; 
      int size;
  } list_shape;
*/

/*@ axiomatic List_to_shape {
      logic list_shape get_s(Node* head);

      axiom size_nil : get_s(\null).size == 0;
      axiom size_cons : \forall Node* head; \valid(head) 
                          ==> get_s(head).size == get_s(head->next).size + 1;

      axiom cell_first : \forall Node* head; head != \null  
                          ==> get_s(head).cell[0] == head;
      axiom cell_next : \forall Node* head, integer i; \valid(head) && 0 <= i < get_s(head->next).size 
                          ==> get_s(head).cell[i+1] == get_s(head->next).cell[i];
    }
*/


/*@ predicate valid_list(list_shape list) =
      list.size >= 0 &&
      (\forall integer i; 0 <= i < list.size ==> list.cell[i] != \null) &&
      (\forall integer i, j; 0 <= i < list.size && 0 <= j < list.size ==>
            i != j ==> list.cell[i] != list.cell[j]); 
*/

/*@ predicate listLR(list_shape list, Node* p, integer lo, integer hi, Node* q) =
        0 <= lo <= hi <= list.size && 
        p == list.cell[lo] && 
        q == list.cell[hi] &&
        \forall integer i; lo <= i < hi ==> list.cell[i]->next == list.cell[i+1];
*/

/*@ predicate listRL(list_shape list, Node* p, integer k) =
        k == 0 && p == \null || 
        (0 < k <= list.size && p == list.cell[k-1] && list.cell[0]->next == \null &&
        \forall integer i; 0 < i < k ==> list.cell[i]->next == list.cell[i-1]);
*/

/*
    Pour le prédicat frame, on indiquera dans la clause 'assigns' ce qui est modifié en mémoire
*/

/*@ requires valid_list : valid_list(get_s(head));
  @ requires listLR : listLR(get_s(head), head, 0, (get_s(head)).size, \null);
  @
  @ ensures reverse : \let s = get_s(head); 
  @                     \forall integer i; 0 <= i < s.size 
  @                         ==> s.cell[i]->val == \old(s.cell[s.size-1-i]->val)
  @                         && s.cell[i]->next == \old(s.cell[i]->next);
  @
  @ assigns (get_s(head)).cell[0..(get_s(head)).size-1]->val,
  @         (get_s(head)).cell[0..((get_s(head)).size)/2]->next;
*/
void value_reverse(Node* head);

#endif




