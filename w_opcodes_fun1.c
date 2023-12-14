#include "monty.h"
/**
 *w_pall - prints all the values on the stack,
 *starting from the top of the stack..
 *@stack: stack that will be filled
 *@line_number: line number
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

/**
 * w_pint - prints the value at the top of the stack
 * @stack: stack that will be printed
 * @line_number: line number
 */
void w_pint(stack_t **stack, unsigned int line_number)
{
if (!stack || !*stack)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}

/**
 * w_pop - removes the top element of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number
 */
void w_pop(stack_t **stack, unsigned int line_number)
{
stack_t *t;
if (!stack || !*stack)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
t = *stack;
*stack = t->next;
if (*stack)
(*stack)->prev = NULL;
free(t);
}

/**
 * w_swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void w_swap(stack_t **stack, unsigned int line_number)
{
stack_t *wfst, *wscd;

if (!stack || !*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
wfst = *stack;
wscd = wfst->next;

wfst->prev = wscd;
wfst->next = wscd->next;

wscd->prev = NULL;
wscd->next = wfst;

if (wfst->next)
wfst->next->prev = wfst;

*stack = wscd;
}

