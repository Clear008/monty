#include "monty.h"
/**
 *w_push - function that pushes an element to the stack.
 *@stack: stack that will be filled
 *@line_number: line number
*/

void w_push(stack_t **stack, unsigned int line_number)
{
int wvalue, j;
stack_t *wn_node;
if (!globalVar.arg)
{
w_error_handle("usage: push integer", line_number);
}

for (j = 0; globalVar.arg[j] != '\0'; j++)
{
if (!isdigit(globalVar.arg[j]) && globalVar.arg[j] != '-')
{
w_error_handle("usage: push integer", line_number);
}
}

wvalue = atoi(globalVar.arg);
wn_node = malloc(sizeof(stack_t));

if (wn_node == NULL)
{
w_error_handle("malloc failed", line_number);
}
wn_node->n = wvalue;
wn_node->prev = NULL;
wn_node->next = *stack;

if (*stack != NULL)
{
(*stack)->prev = wn_node;
}

*stack = wn_node;
}
/**
 *w_pall - prints all the values on the stack,
 *starting from the top of the stack..
 *@stack: stack that will be filled
 *@line_number: line number
 *@arg: arguments
*/
void w_pall(stack_t **stack, unsigned int line_number)
{
stack_t *wcrt = *stack;
(void)line_number;


while (wcrt != NULL)
{
printf("%d\n", wcrt->n);
wcrt = wcrt->next;
}

}
