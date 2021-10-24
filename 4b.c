#include<stdio.h>
#include<stdlib.h>
struct node
{
 int c;
 int e;
 struct node* link;
};
struct node* insert(struct node* start,int c,int e)
{
 struct node* temp;
 struct node* p=malloc(sizeof(struct node));
 p->c=c;
 p->e=e;
 p->link=NULL;
 if(start==NULL||e>start->e)
 {
 p->link=start;
 start=p;
 }
 else
 {
 temp=start;
 while(temp->link != NULL && temp->link->e >=e)
 {
 temp=temp->link;
 }
 p->link=temp->link;
 temp->link=p;
 }
 return start;
}
struct node* create(struct node* start)
{
 int n,i,c,e;
 printf("Enter the number of terms :");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 printf("Enter coefficient for term %d : ",i+1);
 scanf("%d",&c);
 printf("Enter exponent for term %d : ",i+1);
 scanf("%d",&e);
 
 start=insert(start,c,e);
 }
 return start;
}
void print(struct node* start)
{
 if(start==NULL)
 {
 printf("\nNO POLYNOMIAL\n");
 }
 else
 {
 struct node* temp=start;
 while(temp!=NULL)
 {
 printf("%dx^%d",temp->c,temp->e);
 temp=temp->link;
 if(temp!=NULL)
 printf(" + ");
 else
 printf("\n");
 }
 }
}
void polyadd(struct node* start1,struct node* start2)
{
 struct node* p1=start1;
 struct node* p2=start2;
 struct node* start3=NULL;
 while(p1!=NULL && p2!=NULL)
 {
 if(p1->e == p2->e)
 {
 start3=insert(start3,p1->c+p2->c,p1->e);
 p1=p1->link;
 p2=p2->link;
 }
 else if(p1->e > p2->e)
 {
 start3=insert(start3,p1->c,p1->e);
 p1=p1->link;
 }
 else if(p1->e < p2->e)
 {
 start3=insert(start3,p2->c,p2->e);
 p2=p2->link;
 }
 }
 while(p1!=NULL)
 {
 start3=insert(start3,p1->c,p1->e);
 p1=p1->link;
 }
 while(p2!=NULL)
 {
 start3=insert(start3,p2->c,p2->e);
 p2=p2->link;
 }
 printf("\nADDED POLYNOMIAL : ");
 print(start3);
}
void polysub(struct node* start1,struct node* start2)
{
 struct node* p1=start1;
 struct node* p2=start2;
 struct node* start3=NULL;
 while(p1!=NULL && p2!=NULL)
 {
 if(p1->e == p2->e)
 {
 start3=insert(start3,p1->c-p2->c,p1->e);
 p1=p1->link;
 p2=p2->link;
 }
 else if(p1->e > p2->e)
 {
 start3=insert(start3,p1->c,p1->e);
 p1=p1->link;
 }
 else if(p1->e < p2->e)
 {
 start3=insert(start3,p2->c,p2->e);
 p2=p2->link;
 }
 }
 while(p1!=NULL)
 {
 start3=insert(start3,p1->c,p1->e);
 p1=p1->link;
 }
 while(p2!=NULL)
 {
 start3=insert(start3,p2->c,p2->e);
 p2=p2->link;
 }
 printf("\nSUBSTRACTED POLYNOMIAL : ");
 print(start3);
}
void polymul(struct node* start1,struct node* start2)
{
 struct node* p1=start1;
 struct node* p2=start2;
 struct node* start3=NULL;
 
 if(start1== NULL || start2==NULL)
 {
 printf("!!Zero!!");
 return;
 }
 while(p1!=NULL)
 {
 while(p2!=NULL)
 {
 start3=insert(start3,p1->c * p2->c,p1->e+p2->e);
 p2=p2->link;
 }
 p1=p1->link;
 p2=start2;
 }
 printf("\nMULTIPLIED POLYNOMIAL : ");
 print(start3);
}
void main()
{
 int choice;
 struct node* start1=NULL;
 struct node* start2=NULL;
 printf("!Enter the First polynomial! \n");
 start1=create(start1);
 printf("\n!Enter the Second polynomial! \n");
 start2=create(start2);
 printf("\n\nEnter 1 for Adding Polynomial");
 printf("\nEnter 2 for Multiplying Polynomial");
 printf("\nEnter 3 for Substracting Polynomial");
 printf("\nEnter your Choice : ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1: polyadd(start1,start2); break;
 case 2: polymul(start1,start2); break;
 case 3: polysub(start1,start2); break;
 }
