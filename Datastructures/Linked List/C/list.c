#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int key;
  struct node *next;
} node;

typedef struct HefniImplementationSinglyLinkedList {
  struct node *head;
  struct node *tail;
} List;

List *create_list();
int top_front(List *list);
int top_back(List *list);
int is_empty(List *list);
void push_front(List *list, int val);
void push_back(List *list, int val);
void print_list(List *list);
int main() {
  List *lst = create_list();
  if (is_empty(lst))
    printf("list is empty\n");
  push_back(lst, 20);
  push_back(lst, 30);
  push_back(lst, 40);
  push_front(lst, 10);
  push_back(lst, 50);
  print_list(lst);
  printf("\nfirst Element in list is:  %d\n", top_front(lst));
  printf("Last Element in list is : %d\n", top_back(lst));
}

List *create_list() {
  List *list = malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

int is_empty(List *list) { return (list->head == NULL && list->tail == NULL); }

int top_front(List *list) { return list->head->key; }

int top_back(List *list) { return list->tail->key; }

void push_front(List *list, int val) {
  struct node *nd = malloc(sizeof(node));
  nd->key = val;
  nd->next = list->head;
  list->head = nd;
}

void push_back(List *list, int val) {
  struct node *nd = malloc(sizeof(node));
  nd->key = val;
  nd->next = NULL;
  if (list->tail == NULL) {
    list->tail = nd;
    list->head = list->tail;
  } else {
    list->tail->next = nd;
    list->tail = nd;
  }
}

void print_list(List *list) {

  node *n = list->head;
  while (n != NULL) {
    if (n->next) {

      printf("%d->", n->key);
    } else {

      printf("%d", n->key);
    }
    n = n->next;
  }
}
