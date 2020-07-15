// Creating and traversing a binary tree 
// preorder, inorder, and postorder
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree_node.h"

// insert node into tree
void insertNode(TreeNodePtr *treePtr, int value)
{ 
   // if tree is empty
   if (*treePtr == NULL) {   
      *treePtr = malloc(sizeof(TreeNode));

      // if memory was allocated, then assign data
      if (*treePtr != NULL) { 
         (*treePtr)->data = value;
         (*treePtr)->leftPtr = NULL;
         (*treePtr)->rightPtr = NULL;
      } 
      else {
         printf("%d not inserted. No memory available.\n", value);
      } 
   } 
   else { // tree is not empty
      // data to insert is less than data in current node
      if (value < (*treePtr)->data) {                   
         insertNode(&((*treePtr)->leftPtr), value);   
      }                                         

      // data to insert is greater than data in current node
      else if (value > (*treePtr)->data) {                 
         insertNode(&((*treePtr)->rightPtr), value);     
      }                                        
      else { // duplicate data value ignored
         printf("%s", "dup");
      } 
   } 
} 

// begin inorder traversal of tree
void inOrder(TreeNodePtr treePtr)
{ 
   // if tree is not empty, then traverse
   if (treePtr != NULL) {                
      inOrder(treePtr->leftPtr);         
      printf("%3d", treePtr->data);      
      inOrder(treePtr->rightPtr);        
   }                           
} 

// begin preorder traversal of tree
void preOrder(TreeNodePtr treePtr)
{ 
   // if tree is not empty, then traverse
   if (treePtr != NULL) {                
      printf("%3d", treePtr->data);      
      preOrder(treePtr->leftPtr);        
      preOrder(treePtr->rightPtr);       
   }                           
} 

// begin postorder traversal of tree
void postOrder(TreeNodePtr treePtr)
{ 
   // if tree is not empty, then traverse
   if (treePtr != NULL) {                
      postOrder(treePtr->leftPtr);       
      postOrder(treePtr->rightPtr);      
      printf("%3d", treePtr->data);      
   }                           
} 

