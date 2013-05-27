#include "../includes/binarySearchTree.h"
#include "../includes/utilities.h"

/* Functions used for BFS queue */
typedef struct treeNodeQueue {
  treeNode *tn;
  struct treeNodeQueue *next;
} queueNode;

void qInsert(queueNode **head, treeNode *tn) {
  if (*head == NULL) {
    queueNode *newNode = Malloc(sizeof(queueNode));
    newNode->tn = tn;
    newNode->next = NULL;
    *head = newNode;
  } else {
    qInsert((&(*head)->next), tn);
  }
}

treeNode *qPop(queueNode **head) {
  queueNode *temp = *head;
  treeNode *ret = (*head)->tn;
  *head = (*head)->next;
  Free(temp, sizeof(queueNode));
  return ret;
}
/* End queue functions */

void BSTinsert(treeNode **head, int data) {
  if (*head == NULL) {
    treeNode *newNode = Malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    *head = newNode;
  } else {
    if (data < (*head)->data) {
      BSTinsert(&((*head)->left), data);
    } else if (data > (*head)->data) {
      BSTinsert(&((*head)->right), data);
    }
  }
}

void preOrderDFS(treeNode *head) {
  if (head == NULL) {
    return;
  }
  printf("treeNode: %d\n", head->data);
  preOrderDFS(head->left);
  preOrderDFS(head->right);
}

void inOrderDFS(treeNode *head) {
  if (head == NULL) {
    return;
  }
  inOrderDFS(head->left);
  printf("treeNode: %d\n", head->data);
  inOrderDFS(head->right);
}

void postOrderDFS(treeNode *head) {
  if (head == NULL) {
    return;
  }
  postOrderDFS(head->left);
  postOrderDFS(head->right);
  printf("treeNode: %d\n", head->data);
}

void bfsPrint(treeNode *head) {
  if (head == NULL) {
    return;
  }
  queueNode *queue = NULL;
  qInsert(&queue, head);
  while (queue != NULL) {
    treeNode *node = qPop(&queue);

    if (node->left != NULL) {
      qInsert(&queue, node->left);
    }

    if (node->right != NULL) {
      qInsert(&queue, node->right);
    }

    printf("treeNode: %d\n", node->data);
  } 
}   

void dfReinsert(treeNode *head, treeNode *start) {
  if ((head == NULL) || (start == NULL)) {
    return;
  } else {
    treeNode *curr = start;
    BSTinsert(&head, curr->data);
    dfReinsert(head, curr->left);
    dfReinsert(head, curr->right);
    Free(curr, sizeof(treeNode));
  }
}

bool BSTdelete(treeNode **head, int data) {
  treeNode *parent = NULL;
  return BSTdeleteHelper(head, &parent, data);
}

bool BSTdeleteHelper(treeNode **head, treeNode **parent, int data) {
  if (*head == NULL) {
    return false;
  } else {
    if ((*head)->data == data) {
      treeNode *oldHead = *head;
      if (*parent == NULL) {
	// deleting the root

	if (oldHead->left != NULL) {
	  treeNode *newHead = oldHead->left;
	  treeNode *newHeadRight = newHead->right;
	  newHead->right = oldHead->right;
	  dfReinsert(newHead, newHeadRight);
	  *head = newHead;
	} else if (oldHead->right != NULL) {
	  *head = oldHead->right;
	}

      } else {
	// deleting non inner node or leaf
	
	if (oldHead->data < (*parent)->data) {
	  // deleting from the left of parent

	  if (oldHead->left != NULL) {
	    treeNode *rightSubtree = oldHead->right;
	    (*parent)->left = oldHead->left;
	    dfReinsert(oldHead->left, rightSubtree);
	  } else if (oldHead->right != NULL) {
	    (*parent)->left = oldHead->right;
	  } else {
	    (*parent)->left = NULL;
	  }
	} else {
	  // deleting from the right of the parent

	  if (oldHead->left != NULL) {
	    treeNode *rightSubtree = oldHead->right;
	    (*parent)->right = oldHead->left;
	    dfReinsert(oldHead->left, rightSubtree);
	  } else if (oldHead->right != NULL) {
	    (*parent)->right = oldHead->right;
	  } else {
	    (*parent)->right = NULL;
	  }
	}
      }
      Free(oldHead, sizeof(treeNode));
      return true;
    } else {
      if (!BSTdeleteHelper(&(*head)->left, head, data)) {
	return BSTdeleteHelper(&(*head)->right, head, data);
      } else {
	return true;
      }
    }
  }
}

void freeTree(treeNode *head) {
  if (head == NULL) {
    return;
  }
  treeNode *left = head->left;
  treeNode *right = head->right;
  Free(head, sizeof(treeNode));
  freeTree(left);
  freeTree(right);
}

// Testing
void createSevenNodeComplete(treeNode **head) {
  BSTinsert(head, 4);
  BSTinsert(head, 2);
  BSTinsert(head, 6);
  BSTinsert(head, 1);
  BSTinsert(head, 3);
  BSTinsert(head, 5);
  BSTinsert(head, 7);
}

int main() {
  printf("----------Binary Search Tree Testing----------\n");
  memcheck();
  treeNode *head = NULL;
  createSevenNodeComplete(&head);

  printf("-----Pre Order-----\n");
  preOrderDFS(head);

  printf("-----In Order-----\n");
  inOrderDFS(head);

  printf("-----Post Order-----\n");
  postOrderDFS(head);

  printf("-----BFS-----\n");
  bfsPrint(head);

  //delete root
  BSTdelete(&head, 4);
  printf("-----In Order-----\n");
  inOrderDFS(head);

  BSTdelete(&head, 2);
  printf("-----In Order-----\n");
  inOrderDFS(head);

  BSTdelete(&head, 6);
  printf("-----In Order-----\n");
  inOrderDFS(head);

  BSTdelete(&head, 7);
  printf("-----In Order-----\n");
  inOrderDFS(head);
  
  freeTree(head);
  memcheck();

  printf("----------End Binary Search Tree Testing----------\n");
  return 0;
}
