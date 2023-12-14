#include "monty.h"
/**
 *w_push - function that pushes an element to the stack.
 *@stack: stack that will be filled
 *@line_number: line number
*/
void w_push(stack_t **stack, unsigned int line_number)
{
	int n, j = 0, flag = 0;
if (gv.arg)
	{
		if (gv.arg[0] == '-')
			j++;
		for (; gv.arg[j] != '\0'; j++)
		{
			if (gv.arg[j] > 57 || gv.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(gv.file);
			free(gv.ctt);
			cleanup(stack);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(gv.file);
		free(gv.ctt);
		cleanup(stack);
		exit(EXIT_FAILURE); }
	n = atoi(gv.arg);
	if (gv.wlifi == 0)
		w_adds(stack, n);
	else
		w_addq(stack, n);
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