#include <stdio.h>
#include <malloc.h>
struct node
{
 int nData;
 struct node *next;
};
struct node *head;
void addnode()
{
 struct node *ptr = (struct node *)malloc(sizeof(struct node));
 struct node *temp;
 int number;
 printf("Enter an ELEMENT: ");
 scanf("%d", &number);
 ptr->nData = number;
 if (head == NULL)
 {
 ptr->next = NULL;
 head = ptr;
 printf("Node Inserted");
 }
 else
 {
 temp = head;
 while (temp->next != NULL)
 {
 temp = temp->next;
 }
 temp->next = ptr;
 ptr->next = NULL;
 printf("Node Inserted");
 }
 printf("\n");
}
void display()
{
 struct node *current = head;
 if (head == NULL)
 {
 printf("there is no linked list");
 return;
 }
 printf("singly linked list is as follow\n");
 while (current != NULL)
 {
 printf("%d\n", current->nData);
 current = current->next;
 }
 printf("\n");
}
void deletenode()
{
 struct node *ptr, *p;
 struct node *temp= head;
 int position;
 printf("which position of node you want to delete?\n");
 scanf("%d",&position);
 if (position==0)
 {
 head=temp->next;
 free(temp);
 return;
 }
 for (int i=0; temp!=NULL && i<position-1; i++)
 {
 temp = temp->next;
 }
 if (temp == NULL || temp->next == NULL)
 {
 printf("Enter position less than no of node");
 return;
 }
 struct Node *next = temp->next->next;
 free(temp->next);
 temp->next = next;
 printf("Node Deleted\n");
}
void main()
{
 int choice;
 while (choice != 4)
 {
 printf("1-Add Node\n2-Display Nodes\n3-Delete Node\n4-Exit");
 printf("\nEnter your choice: ");
 scanf("%d", &choice);
 if (choice == 1)
 {
 addnode();
 }
 else if (choice == 2)
 {
 display();
 }
 else if (choice == 3)
 {
 deletenode();
 }
 }
}
