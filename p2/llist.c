 /* Program assignment 2 - A program that implemets a linked list. It performs functions like
 *   inserting an element, searching for an element and deleting and printing all elements
 *     Date : 10/7/20
 *       program name: llist.c
 *         CS 320
 *           @author Hrishikesh . M, cssc2644
 *             Created by Hrishikesh Manjunath on 10/1/20.
 *               Copyright © 2020 hr. All rights reserved.
 *               */

#include "llist.h"

Link root=NULL;
/* the following function reads user input and converts into a string*/ 
Link strToList(char s[]){
   Link node,tempcur;
   char *c=s,*current;
   if(*c!='\0'){
       node=(Link)(malloc(sizeof(Link)));
       node->data=*c;
       node->next=NULL;

       if(root==NULL){
           root=node;
       }
       else{
           tempcur=root;
           while(tempcur!=NULL){
               if(tempcur->next==NULL){
                   tempcur->next=node;
                   break;
               }
               tempcur=tempcur->next;
           }
       }
    
       printf("%s: %c\n",c,*c);
       c++;
       s=c;
       strToList(s);
   }

   return root;
}

/* it will obtain the size*/
int size(Link head){
   Link current=head;
   int count=0;
   while(current!=NULL){
       current=current->next;
       count++;
   }
   return count;
}

Link find(Data c,Link head){
   Link current=head;
   while(current!=NULL){
/*The current link will be returned if found*/
       if(current->data==c){
           return current;
       }
       current=current->next;
   }
   
   return NULL;
}

void insert(Link p1,Link p2,Link q){
   p1->next=q;
   q->next=p2;
}
/* It will remove the link */
void delete_(Link p,Link q){
   p->next=q->next;
}
void deleteList(Link head){
   if(head!=NULL){
/*it will print head val*/
       printf("\ndeleting %c",head->data);
       head=head->next;
       deleteList(head);
   }
}

/* the following function will print out the linked list */
void print(Link head){
   Link current=head;
   while(current!=NULL){
       printf("%c",current->data);
       current=current->next;
   }
}

