#include <stdio.h>
#include <stdlib.h>
#include "stack_node.h"


// insert a node at the stack top
void push(StackNodePtr *topPtr, int info)
{ 
   StackNodePtr newPtr = malloc(sizeof(StackNode));

   // insert the node at stack top
   if (newPtr != NULL) {           
      newPtr->data = info;           
      newPtr->nextPtr = *topPtr;     
      *topPtr = newPtr;              
   }                     
   else { // no space available
      printf("%d not inserted. No memory available.\n", info);
   } 
} 

// remove a node from the stack top
int pop(StackNodePtr *topPtr)
{ 
   StackNodePtr tempPtr = *topPtr;             
   int popValue = (*topPtr)->data;  
   *topPtr = (*topPtr)->nextPtr;
   free(tempPtr);               
   return popValue;
} 

// print the stack
void printStack(StackNodePtr currentPtr)
{ 
   // if stack is empty
   if (currentPtr == NULL) {
      puts("The stack is empty.\n");
   } 
   else { 
      puts("The stack is:");

      // while not the end of the stack
      while (currentPtr != NULL) { 
         printf("%d --> ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;
      } 

      puts("NULL\n");
   } 
} 

// return 1 if the stack is empty, 0 otherwise
int isEmpty(StackNodePtr topPtr)
{ 
   return topPtr == NULL;
} 
