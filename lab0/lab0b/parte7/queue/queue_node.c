// Operating and maintaining a queue
#include <stdio.h>
#include <stdlib.h>
#include "queue_node.h"

// insert a node at queue tail
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value)
{ 
   QueueNodePtr newPtr = malloc(sizeof(QueueNode));

   if (newPtr != NULL) { // is space available 
      newPtr->data = value;
      newPtr->nextPtr = NULL;

      // if empty, insert node at head
      if (isEmpty(*headPtr)) {
         *headPtr = newPtr;
      } 
      else {
         (*tailPtr)->nextPtr = newPtr;
      } 

      *tailPtr = newPtr;
   } 
   else {
      printf("%c not inserted. No memory available.\n", value);
   } 
} 

// remove node from queue head
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{ 
   char value = (*headPtr)->data;      
   QueueNodePtr tempPtr = *headPtr;              
   *headPtr = (*headPtr)->nextPtr;

   // if queue is empty
   if (*headPtr == NULL) {
      *tailPtr = NULL;
   } 

   free(tempPtr);
   return value;
} 

// return 1 if the queue is empty, 0 otherwise
int isEmpty(QueueNodePtr headPtr)
{ 
   return headPtr == NULL;
} 

// print the queue
void printQueue(QueueNodePtr currentPtr)
{ 
   // if queue is empty
   if (currentPtr == NULL) {
      puts("Queue is empty.\n");
   } 
   else { 
      puts("The queue is:");

      // while not end of queue
      while (currentPtr != NULL) { 
         printf("%c --> ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;
      } 

      puts("NULL\n");
   } 
} 

