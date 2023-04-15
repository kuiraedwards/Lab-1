// list/list.c
//
// Implementation for linked list.
//  Worked with Jamarri White
//
// Kuira Edwards @02942519

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_alloc() {
  list_t* list_new = (list_t*) malloc(sizeof(list_t));
  list_new->head = NULL;
  return list_new;
}

node_t *node_alloc(elem value) {
  node_t* new_node = (node_t*)malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

void list_free(list_t *l) {
  node_t *curr = l->head;
  if(curr == NULL) {
    printf("This list is empty!")
  }
  while (curr != NULL) {
    node_t *temp = curr->next;
    free(curr);
    curr = temp;
  }
}

char* toString(list_t *l) {
  char temp[250];
}

void node_free(node_t *n) {
  if (n->next != NULL) {
    node_free(n->next);
  }
  else {
    free(n);
  }
}

void list_print(list_t *l) {
  node_t *curr = l->head;
  if (curr == NULL) {
    printf("This list is empty!");
  }
  else {
    while (curr != NULL) {
      printf("The current node is %d \n", curr->value);
      curr = curr->next;
    }
  }
}

int list_length(list_t *l) {
  int length = 0;
  node_t *curr = l->head;
  while (curr != NULL) {
    length++;
    curr = curr->next;
  }
  return length;
}

void list_add_to_back(list_t *l, elem value) {
  node_t *new = node_alloc(value);
  node_t *curr = l->head;
  
  if (curr == NULL) {
    l->head = new;
    return;
  }
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = new_node;
}

void list_add_to_front(list_t *l, elem value) {
  node_t *new = node_alloc(value);
  new->next = l->head;
  l->head = new;
}

void list_add_at_index(list_t *l, elem value, int index) {
  if ((index >= list_length(l)) || (index < 0)) {
    return;
  }
  node_t *new = malloc(sizeof(node_t));
  new->value = value;
  node_t *curr = l->head;

  int curr_index = 0;
  for (curr_index = 0; curr_index < index-1; curr_index++) {
    curr = curr->next;
  }
  if (curr == NULL) {
    l->head = new;
  }
  else {
    new->next = curr->next;
    curr->next = new;
  }
}

elem list_remove_from_back(list_t *l) {
  node_t *curr = l->head;
  node_t *remove = curr;
  while ((curr != NULL) && (curr->next != NULL)) {
    if (curr->next->next == NULL) {
      remove = curr->next;
      curr->next = NULL;
    }
    else {
      curr = curr->next;
    }
  }
  return remove->value;
}

elem list_remove_from_front(list_t *l) {
  if(!l) {
    printf("This list is empty!");
    return;
  }
  else {
    int remove = l->head->value;
    l->head = l->head->next;
    return remove;
  }
}

elem list_remove_at_index(list_t *l, int index) {
  if ((index >= list_length(l)) || (index < 0)) {
    return 0;
  }
  node_t *curr = l->head;
  
  int curr_index = 0;
  for (curr_index = 0; curr_index < index-1; curr_index++) {
    curr = curr->next;
  }
  int remove = curr->next->value;
  curr->next = curr->next->next;
  return remove;
}

bool list_is_in(list_t *l, elem value) {
  node_t *curr = l->head;
  while(curr != NULL) {
    if(curr->value == value) {
      return true;
    }
    curr = curr->next;
  }
  return false;
}

elem list_get_elem_at(list_t *l, int index) {
  if ((index >= list_length(l)) || (index < 0)) {
    return 0;
  }
  node_t *curr = l->head;

  int curr_index = 0;
  for (curr_index; curr_index < index; curr_index++) {
    curr = curr->next;
  }
  return curr->value;
}

int list_get_index_of(list_t *l, elem value) {
  node_t* curr = l->head;
  int index = 0

  while (curr != NULL) {
    if (curr->value == value) {
      return index;
    }
    current = current->next;
    index += 1;
  }
  return -1;
}