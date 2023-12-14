#include "monty.h"

/**
 *w_push - function that pushes an element to the stack.
 *@stack: stack that will be filled
 *@line_number: line number
*/

void w_push(stack_t **stack, unsigned int line_number)
{
char *value;
stack_t *new_node;
if (!stack || !*stack)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

new_node = malloc(sizeof(stack_t));
if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

value = strtok(NULL, " \n\t");
if (!value || (*value == '-' && !isdigit(value[1])) || !isdigit(*value))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
free(new_node);
exit(EXIT_FAILURE);
}
new_node->n = atoi(value);
new_node->prev = NULL;
new_node->next = *stack;

if (*stack)
(*stack)->prev = new_node;
*stack = new_node;
}

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
