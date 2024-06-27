#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct window
{
    int value;
    struct window *next;
};

int is_empty(struct window* head){
    return (head == NULL);
}

struct window* open(struct window* head, int value){
    if(is_empty(head)){
        head = (struct window*)malloc(sizeof(struct window*));
        head->next = NULL;
        head->value = value;
        printf("%d\n", value);
        return head;
    }
    else{
        struct window* new_head = (struct window*)malloc(sizeof(struct window*));
        new_head->next = head;
        new_head->value = value;
        printf("%d\n", value);
        return new_head;
    }
}

struct window* close(struct window* head, int value){
    if(is_empty(head)){
        printf("can't close empty window");
        exit(0);
    }
    int head_val = head->value;
    if(head_val == value && head->next != NULL){
        printf("%d\n", head->next->value);
        struct window* newhead = head->next;
        free(head);
        return newhead;
    }

    struct window* prev = NULL;
    struct window* curr = head;
    while(curr->value != value && curr != NULL){
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL){
        printf("specified window does not exist");
        exit(0);
    }
    if(prev == NULL){
        head = curr->next;
    }
    else{
        prev->next = curr->next;
        printf("%d\n", head_val);
    }
    free(curr);
    return head;
}

struct window* switch_focus(struct window* head, int value){
    if(is_empty(head)){
        printf("can't close empty window");
        exit(0);
    }
    else if(head->value == value){
        printf("%d\n", head->value);
        return head;
    }
    
    struct window* prev = head;
    struct window* curr = head;
    while(curr->value != value && curr != NULL){
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL){
        printf("specified window does not exist");
    }

    if (prev != NULL) {
        prev->next = head;
        struct window* temp = head->next;
        head->next = curr->next;
        curr->next = temp;
        head = curr;
    }
    
    printf("%d\n", head->value);
    return head;
}

int main()
{
    char str[20];
    int value;

    struct window* head = NULL;

     while (scanf("%s %d", str, &value) != EOF) {
        if (strcmp(str, "open") == 0) {
            head = open(head, value);
        } else if (strcmp(str, "switch") == 0) {
            head = switch_focus(head, value);
        } else if (strcmp(str, "close") == 0) {
            head = close(head, value);
        }
        struct window* temp = head;
        if(is_empty(head)){
            exit(0);
        }
     }

    return 0;
}