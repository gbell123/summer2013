#include "linkedList.h"
#include "utilities.h"

void LLprintList(listNode *head) {
  listNode *curr = head;
  while (curr != NULL) {
    printf("data: %d\n", curr->data);
    curr = curr->next;
  }
}

listNode *LLaddTail(listNode *head, int data) {
  listNode *newListNode = Malloc(sizeof(listNode));
  newListNode->data = data;
  newListNode->next = NULL;
  
  if (head == NULL) {
    head = newListNode;
  } else {
    listNode *curr = head;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = newListNode;
  }
  return head;
}

listNode *LLfind(listNode *head, int data) {
  listNode *curr = head;
  while (curr != NULL) {
    if (curr->data == data) {
      return curr;
    } else {
      curr = curr->next;
    }
  }
  return NULL;
}

listNode *LLdelete(listNode *head, int data) {
  listNode *foundElem = LLfind(head, data);
  if (foundElem == NULL) {
    return head;
  } else if (head->data == data) {
    listNode *newHead = head->next;
    Free(head, sizeof(listNode));
    return newHead;
  } else {
    listNode *curr = head;
    while (curr->next->data != data) {
      curr = curr->next;
    }
    curr->next = curr->next->next;
    Free(foundElem, sizeof(listNode));
    return head;
  }
}

void LLfreeList(listNode *head) {
  listNode *next;
  while (head != NULL) {
    next = head->next;
    Free(head, sizeof(listNode));
    head = next;
  }
}

// Testing functions
listNode *LLcreateTestList() {
  listNode *head = NULL;
  // create ten test elements and add them
  int i;
  for (i=0; i<=10; i++) {
    head = LLaddTail(head, i);
  }
  return head;
}

int main() {
  printf("----------Linked List Testing----------\n");
  memcheck();
  // initialize head
  listNode *head = LLcreateTestList();

  // final list should be 0-10 
  LLprintList(head);

  // test delete head, alloc'd === 160
  head = LLdelete(head, 0);
  // list should be 1-10
  LLprintList(head);

  // delete last elem
  head = LLdelete(head, 10);
  // list should be 1-9
  LLprintList(head);
  
  //test free list, unalloc'd should be 0
  LLfreeList(head);
  memcheck();
  printf("--------End Linked List Testing--------\n");
  return 0;
}
