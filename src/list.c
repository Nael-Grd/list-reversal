#include <stddef.h>
#include <stdlib.h>

#include "../include/list.h"

void value_reverse(Node* head) {
    if (head == NULL || head->next == NULL) {      //cas 0 ou 1 element
        return;
    }

    Node* sp = head;       // pointeur lent
    Node* fp = head;       // pointeur rapide
    Node* bp = NULL;       // predecesseur de sp

    /*@ ghost int i = 0; */

    /*@ loop invariant size : 0 <= i <= get_s(head).size / 2;

      @ loop invariant sp : sp == get_s(head).cell[i];
      @ loop invariant fp : (fp == \null || fp == get_s(head).cell[2*i]);
      @ loop invariant bp : i > 0 ==> bp == get_s(head).cell[i-1];

      @ loop invariant RL : listRL(get_s(head), bp, i);
      @ loop invariant LR : listLR(get_s(head), sp, i, get_s(head).size, \null);

      @ loop assigns i, sp, fp, bp, get_s(head).cell[0..get_s(head).size-1]->next;
      
      @ loop variant get_s(head).size - i;
    */
    while (fp != NULL && fp->next != NULL) {  
        fp = fp->next->next;   // fp avance de 2

        Node* tmp_sp = sp;    // avancement de sp, bp et inversion des pointeurs bp
        sp = sp->next;  
        Node* tmp_bp = bp;
        bp = tmp_sp;
        bp->next = tmp_bp;
        /*@ ghost i++; */
    }                               
    //Etat a la fin de la boucle : liste gauche pointeurs inversés, sp milieu, bp predec pointe a gauche, np succs pointe a droite
    

    Node* np;
    if (fp == NULL) {  // liste paire
        np = sp;            
    }
    else {        //liste impaire
        np = sp->next;
    }


    /*@ loop invariant size_bis : 0 <= i <= get_s(head).size / 2;

      @ loop invariant sp_bis : sp == get_s(head).cell[i];
      @ loop invariant bp_bis : i > 0 ==> bp == get_s(head).cell[i-1];
      @ loop invariant np : np == get_s(head).cell[get_s(head).size - i];
      
      @ loop invariant RL_bis : listRL(get_s(head), bp, i);
      @ loop invariant LR_bis : listLR(get_s(head), sp, i, get_s(head).size, \null);

      @ loop invariant swap_values : \forall integer j; i < j <= get_s(head).size / 2 
                                 ==> get_s(head).cell[j]->val == \at(get_s(head).cell[get_s(head).size - 1 - j]->val, Pre);

      @ loop assigns bp, sp, np, i, get_s(head).cell[0..get_s(head).size/2]->next, get_s(head).cell[0..get_s(head).size-1]->val;
      @ loop variant i;
    */
    while (bp != NULL) {    
        int tmp = bp->val;
        bp->val = np->val;
        np->val = tmp;

        Node* prev = bp->next;  
        bp->next = sp;
        sp = bp;
        bp = prev;

        np = np->next;       
        /*@ ghost i--; */
    }
}



// frama-c -wp -wp-rte -wp-smoke-tests -wp-prover alt-ergo list.h list.c

