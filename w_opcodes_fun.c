#include "monty.h"
/**
 *w_push - function that pushes an element to the stack.
 *@stack: stack that will be filled
 *@line_number: line number
 *@arg: arguments
*/
void w_push(stack_t **stack, unsigned int line_number, char *arg)
{
int wvalue;
stack_t *wn_node;

if (!arg || !w_isdigit(arg))
w_error_handle("usage: push integer", line_number);
wvalue = atoi(arg);
wn_node = malloc(sizeof(stack_t));
if (wn_node == NULL)
w_error_handle("malloc failed", line_number);

wn_node->n = wvalue;
wn_node->prev = NULL;
wn_node->next = *stack;

if (*stack != NULL)
(*stack)->prev = wn_node;

*stack = wn_node;
}
/**
 *w_pall - prints all the values on the stack,
 *starting from the top of the stack..
 *@stack: stack that will be filled
 *@line_number: line number
 *@arg: arguments
*/
void w_pall(stack_t **stack, unsigned int line_number, char *arg)

{
stack_t *wcrt = *stack;
(void)line_number;
(void)arg;

while (wcrt != NULL)
{
printf("%d\n", wcrt->n);
wcrt = wcrt->next;
}

}
