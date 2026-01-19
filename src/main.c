#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/list.h"


Node* create_list(int value) {
    Node* new_list = malloc(sizeof(Node));
    
    new_list->val = value;
    new_list->next = NULL;

    return new_list;
}

void print_list(char* text, Node* head) {
    printf("%s [", text);
    Node* cur = head;
    while (cur != NULL) {
        printf("%d, ", cur->val);
        cur = cur->next;
    }
    printf("NULL]\n");
}

static void free_list(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        Node* next = cur->next;
        free(cur);
        cur = next;
    }
}

int main(void) {

    Node *head = NULL, *tail = NULL;
    int value;
    char c;

    printf("Entrez votre liste d'entiers sous la forme [a,b,c...] : \n");
    scanf(" %c", &c);   // on saute le premier crochet '['

    while (scanf("%d", &value) == 1) {
        Node* newNode = create_list(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        scanf(" %c", &c);
        if (c == ']') break; 
    }

    if (head) {
        print_list("Liste originale : \n", head);
        value_reverse(head);
        print_list("Liste inversee  : \n", head);
        free_list(head);
    } else {
        printf("Liste vide ou erreur de format.\n");
    }

    return 0;
}


// gcc -Wall -Wextra -g -o main main.c list.c