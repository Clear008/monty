#include "monty.h"

/**
 * w_add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void w_add(stack_t **stack, unsigned int line_number)
{
stack_t *wfst, *wscd;

if (!stack || !*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

wfst = *stack;
wscd = wfst->next;

wscd->n += wfst->n;
*stack = wscd;
free(wfst);
if (*stack)
(*stack)->prev = NULL;
}
/**
 * w_nop - doesn't do anything
 * @stack: pointer
 * @line_number: line number
 */
void w_nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}
