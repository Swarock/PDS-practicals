#include <stdio.h>
#include<string.h>
int t=-1;
char str1[40], str2[40];
void Push(char);
void Pop();
void main()
{
printf("Enter the string:");
gets(str1);
int i, choice;
for (i = 0; i < strlen(str1); i++)
{
Push(str1[i]);
}
printf("\nReverse String is:\n");
Pop();
}
void Push(char c)
{
int x;
if (t == strlen(str1) - 1)
{
printf("\nOverflow!!");
}
else
{
t = t + 1;
str2[t] = c;
}
}
void Pop()
{
while (t != -1)
{
if (t == -1)
{
printf("\nUnderflow!!");
}
else
{
printf("%c", str2[t]);
t = t - 1;
}
}
}
