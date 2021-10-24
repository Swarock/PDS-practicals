#include <stdio.h>
int front = 0;
int rear = 0;
struct data
{
 int id;
 int priority;
} ids[5];
void enqueue(int id, int priority)
{
 if (rear == 4)
 {
 printf("\nOverflow\n");
 }
 else
 {
 ids[rear].id = id;
 ids[rear].priority = priority;
 printf("\nData of user-%d has been enqueued.\n", ids[rear].id);
 rear++;
 }
}
void dequeue()
{
 int i;
 int max = 0;
 front = -1;
 for (i = 0; i < 5; i++)
 {
 if (ids[i].priority > max)
 {
 max = ids[i].priority;
 front = i;
 }
 }
 if (front != -1)
 {
 printf("\nData of user-%d is deleted.\n", ids[front].id);
 ids[front].priority = -1;
 }
 else
 {
 printf("\nUnderflow\n");
 }
}
void display()
{
 int i;
 for (i = 0; i < 5; i++)
 {
 if (ids[i].priority != -1)
 {
 printf("\nIt is data of user-%d.\n", ids[i].id);
 }
 }
}
void main()
{
 int i = 0, choice = 0, nid, prio;
 while (choice != 4)
 {
 printf("Enter your choice:\n 1-Display Data\n 2-Enter Data\n 3-Delete Data\n 4-Exit\n");
 printf("Choice:");
 scanf("%d", &choice);
 if (choice == 1)
 {
 display();
 }
 else if (choice == 2)
 {
 printf("Enter your id:");
 scanf("%d", &nid);
 printf("Enter your priority:");
 scanf("%d", &prio);
 enqueue(nid, prio);
 }
 else if (choice == 3)
 {
 dequeue();
 }
 }
}
