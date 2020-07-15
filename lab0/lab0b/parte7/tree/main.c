#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree_node.h"

// function main begins program execution
int main(void)
{ 
   TreeNodePtr rootPtr = NULL; // tree initially empty

   srand(time(NULL)); 
   puts("The numbers being placed in the tree are:");

   // insert random values between 0 and 14 in the tree
   for (unsigned int i = 1; i <= 10; ++i) { 
      int item = rand() % 15;
      printf("%3d", item);
      insertNode(&rootPtr, item);
   } 

   // traverse the tree preOrder
   puts("\n\nThe preOrder traversal is:");
   preOrder(rootPtr);

   // traverse the tree inOrder
   puts("\n\nThe inOrder traversal is:");
   inOrder(rootPtr);

   // traverse the tree postOrder
   puts("\n\nThe postOrder traversal is:");
   postOrder(rootPtr);
   return 0;
} 