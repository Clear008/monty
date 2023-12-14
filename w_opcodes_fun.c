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
if (!isdigit(gv.arg[j]))
{
flag = 1;
}
}
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(gv.file);
			free(gv.ctt);
			cleanup(stack);
			exit(EXIT_FAILURE); }
}
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
