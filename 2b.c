#include <stdio.h>
char stack[30], infix[30];
int t = -1;
void push(char x)
{
stack[++t] = x;
}
char pop()
{
if (t == -1)
return -1;
else
return stack[t--];
}
int priority(char x)
{
if (x == '(')
return 0;
if (x == '+' || x == '-')
return 1;
if (x == '*' || x == '/')
return 2;
if (x == '^')
return 3;
return 0;
}
void main()
{
char ch;
int i = 0;
printf("Enter an Infix Expression: ");
scanf("%s", infix);
printf("\nPostfix Expression: ");
while ((ch = infix[i++]) != '\0')
{
if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '1'
&& ch <= '9'))
printf("%c", ch);
else if (ch == '(')
push(ch);
else if (ch == ')')
{
while ((ch = pop()) != '(')
printf("%c", ch);
}
else
{
while (priority(stack[t]) >= priority(ch))
printf("%c", pop());
push(ch);
}
}
while (t != -1)
printf("%c", pop());
}
