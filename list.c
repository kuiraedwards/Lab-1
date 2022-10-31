// list/list.c
//
// Implementation for linked list.
//
// Kuira Edwards @02942519

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

node_t *node_alloc(int value) {
  node_t *node = (node_t*) malloc(sizeof(node_t));
  node->value = value;
  node->next = NULL;
  return node;
}

list_t *list_alloc() {
  list_t* list = (list_t*) malloc(sizeof(list_t));
  list->head = NULL;
  return list;
}
  
void list_free(list_t *l) {
  free(l);
}

void node_free(node_t *n) {
  free(n);
}

void list_print(list_t *l) {
  node_t* current = l->head;

  if (current == NULL) {
    printf("Empty list\n");
  }
  else{
    while (current != NULL) {
      printf("%d", current->value);
      current = current->next;
    }
  }
}

int list_length(list_t *l) {
  int count = 0;
  node_t* current = l->head;
  if (current == NULL) {
    printf("Empty list\n");
  }
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}
void list_add_to_back(list_t *l, elem value) {
  node_t* current = l->head;
  node_t* newNode = (node_t*) malloc(sizeof(node_t));
  if (current == NULL) {
    list_add_to_front(l, value);
  }
  else {
    while(current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
    newNode->value = value;
    newNode->next = NULL;
  }
}
  
void list_add_to_front(list_t *l, elem value) {
  node_t* newNode = node_alloc(value);
  if (l->head == NULL) {
    l->head = newNode;
  }
  else{
    newNode->next = l->head;
    l->head = newNode;
  }
}
void list_add_at_index(list_t *l, elem value, int index){
  node_t* current = l->head;
  node_t* newNode = (node_t*) malloc(sizeof(node_t));

  if(index == 0 || current == NULL) {
    list_add_to_front(l,value);
  }
  else{
    int count = 0;
    for(count = 0; count < index - 1; count++) {
      if(current->next == NULL) {
        return;
    }
    current = current->next;
  }
  newNode->value = value;
  newNode->next = current->next;
  current->next = newNode;
  }
}
elem list_remove_from_back(list_t *l) {
  elem val;

  if(list_length(l) == 0) {
    return -1;
  }
  if(l->head->next == NULL) {
    val = l->head->value;
    node_free(l->head);
    return val;
  }

  node_t* current = l->head;

  while(current->next->next != NULL) {
    current = current->next;
  }
  val = current->next->value;
  node_free(current->next);
  current->next = NULL;
  return val;
}
elem list_remove_from_front(list_t *l) {
  elem val;

  if(list_length(l) == 0) {
    return -1;
  }

  node_t* nextNode = l->head->next;
  val = l->head->value;
  node_free(l->head);
  l->head = nextNode;

  return val;
}
elem list_remove_at_index(list_t *l, int index) {
  elem val;

  if(list_length(l) == 0) {
    return -1;
  }

  if(index == 0) {
    return list_remove_from_front(l);
  }

  node_t* current = l->head;
  node_t* other = NULL;

  int i = 0;
  for(i = 0; i < index - 1; i++) {
    if(current->next = NULL) {
      return -1;
    }
    current = current->next;
  }

  other = current->next;
  val = other->value;
  current->next = other->next;
  node_free(other);

  return val;
}

bool list_is_in(list_t *l, elem value) {
  node_t* current = l->head;
  if(current == NULL) {
    return false;
  }
  while(current != NULL) {
    if(current->value == value) {
      return true;
    }
    current = current->next;
  }
  return false;
}

elem list_get_elem_at(list_t *l, int index) {
  node_t* current = l->head;
  if(current == NULL) {
    return -1;
  }
  int count = 0;
  for(count = 0; count < index; count++) {
    if(current->next == NULL) {
      return -1;
    }
    current = current->next;
  }
  return current->value;
}

int list_get_index_of(list_t *l, elem value) {
  node_t* current = l->head;
  elem length = list_length(l);
  int count = 1;
  if(current == NULL) {
    return -1;
  }
  for(count = 1; count < length - 1; count++) {
    if(current->next == NULL) {
      return -1;
    }
    current = current->next;
    if(current->value == value) {
      return count;
    }
  }
  return -1;
}