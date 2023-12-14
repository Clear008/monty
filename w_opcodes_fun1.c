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
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(gv.file);
		free(gv.ctt);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}