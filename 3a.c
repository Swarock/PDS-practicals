#include <stdio.h>
int queue[5];
int front = -1;
int rear = -1;
int x;
void insert()
{
 if (front == -1)
 {
 printf("Insert the element: ");
 scanf("%d", &x);
 front = 0;
 rear = 0;
 queue[rear] = x;
 }
 else if ((rear + 1) % 5 == front)
 {
 printf("\nOverflow");
 }
 else if (rear == 4 && front != 0)
 {
 rear = 0;
 printf("Insert the element: ");
 scanf("%d", &x);
 queue[rear] = x;
 }
 else
 {
 printf("Insert the element: ");
 scanf("%d", &x);
 rear++;
 queue[rear] = x;
 }
}
void delete ()
{
 if (front == -1)
 {
 printf("\nUnderflow.");
 }
 else if (front == rear)
 {
 printf("\n Element DELETED");
 front = -1;
 rear = -1;
 }
 else if (front == 4)
 {
 front = 0;
 }
 else
 {
 front++;
 printf("\nElement DELETED");
 }
}
void display()
{
 if (front == -1)
 {
 printf("\nQueue is Empty");
 return;
 }
 printf("\nElements in Circular Queue are: \n");
 if (rear >= front)
 {
 for (int i = front; i <= rear; i++)
 printf("%d \n", queue[i]);
 }
 else
 {
 for (int i = front; i < 5; i++)
 printf("%d \n", queue[i]);
 for (int i = 0; i <= rear; i++)
 printf("%d \n", queue[i]);
 }
}
int main()
{
 int ch;
 printf("PRINTER SPOOLER APPLICATION");
 do
 {
 printf("\n\nPress 1 to insert an element \nPress 2 to delete an element \nPress 3 to display the elements");
 printf("\n\nEnter your choice: ");
 scanf("%d", &ch);
 switch (ch)
 {
 case 1:
 {
 insert();
 break;
 }
 case 2:
 {
 delete ();
 break;
 }
 case 3:
 {
 display();
 break;
 }
 }
 } while (ch > 0);
 return 0;
}
