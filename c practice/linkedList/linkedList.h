// A singly linked list with int as data

typedef struct listNode {
  int data;
  struct listNode *next;
} listNode;

// Prints the list data, head to tail
void LLprintList(listNode *head);

// Adds an element to the tail of the list, returns the head
listNode *LLaddTail(listNode *head, int data);

// Finds and returns a given node
listNode *LLfind(listNode *head, int data);

// Deletes the first occurrence of a node with the given data, frees
// returns head
listNode *LLdelete(listNode *head, int data);

// Deletes and frees the whole list
void LLfreeList(listNode *head);

// Creates and returns the head of a list 0-10
listNode *LLcreateTestList();
