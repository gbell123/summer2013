#include <stdbool.h>

// A binary search tree with int as data

typedef struct treeNode {
  int data;
  struct treeNode *left;
  struct treeNode *right;
} treeNode;

// Inserts a node into the tree specified with head
// Smaller data left, larger data right, duplicates ignored
void BSTinsert(treeNode **, int);

// Executes a pre order traversal of tree (standard dfs), performing function f
void preOrderDFS(treeNode *);

// Prints in order traversal (traverse left, print head, traverse right)
void inOrderDFS(treeNode *);

// Prints a post oreder traversal (traverse left, traverse right, print head)
void postOrderDFS(treeNode *);

// Prints a breadth first traversal
void bfsPrint(treeNode *);

/* Reinsert nodes from the subtree who's head is the second param
   into the subtree who's head is the first param */
void dfReinsert(treeNode *, treeNode *);

/* Removes the corresponding node from the tree, returns true if a node was deleted
   Pass second param as NULL, it gets filled with a parent during recursion */
bool BSTdelete(treeNode **, int);

// Helper for delete
bool BSTdeleteHelper(treeNode **, treeNode **, int);

// Frees the tree
void freeTree(treeNode *);

// Used for testing, creates this:
/*
                  4
             2         6
	   1   3     5	 7
*/
void createSevenNodeComplete(treeNode **);

// Runs a test suite on a BST
//void testBST();
