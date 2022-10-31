#include <stdio.h>
#include "list.h"

int main() 
{
  printf("Tests for linked list implementation:\n\n");
  
  list_t *testlist = list_alloc();
  int length; 

//3, 15, and 1 are added to the list. length = 3
  list_add_to_front(testlist, 1);
  list_add_to_front(testlist, 15);
  list_add_to_front(testlist, 3);
  list_print(testlist);
  length = list_length(testlist);
  printf("\nLength of testlist is: %d\n", length);

//2, 6, 4, and 8 are added to the back of list. length = 7
  list_add_to_back(testlist, 2);
  list_add_to_back(testlist, 6);
  list_add_to_back(testlist, 4);
  list_add_to_back(testlist, 8);
  list_print(testlist);
  length = list_length(testlist);
  printf("Length of testlist is: %d\n", length);

//11 and 3 are added to the list at their respective indexes. length = 9
  list_add_at_index(testlist, 11, 2);
  list_add_at_index(testlist, 7,30);
  list_print(testlist);
  length = list_length(testlist);
  printf("Length of testlist is: %d\n", length);

//Last two elements are removed from the list at their respective indexes. length = 7
  list_remove_from_back(testlist);
  list_remove_from_back(testlist);
  list_print(testlist);
  length = list_length(testlist);
  printf("Length of testlist is: %d\n", length);

//First two elements are removed from the list at their respective indexes. length = 5
  list_remove_from_front(testlist);
  list_remove_from_front(testlist);
  list_print(testlist);
  length = list_length(testlist);
  printf("Length of testlist is: %d\n", length);

//2nd and 4th elements are removed from the list at their respective indexes. length = 3
  list_remove_at_index(testlist, 2);
  list_remove_at_index(testlist, 0);
  list_print(testlist);
  length = list_length(testlist);
  printf("Length of testlist is: %d\n", length);

//Checks if elements are in the list.
  bool result = list_is_in(testlist, 7);
  printf("%s\n", result ? "true" : "false");
  result = list_is_in(testlist, 3);
  printf("%s\n", result ? "true" : "false");
  result = list_is_in(testlist, 4);
  printf("%s\n", result ? "true" : "false");

//Gets index of element 3
  printf("%d\n", list_get_index_of(testlist, 3));

//Gets element at the 1st index
  printf("Element at 1st index is %d\n", list_get_elem_at(testlist, 1));

  return 0;
}