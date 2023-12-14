#include "monty.h"
/**
* w_exet - executes the opcode
* @stack: head linked list - stack
* @count: line_counter
* @file: poiner to monty file
* @content: line content
* Return: to 1
*/
int w_exet(char *content, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t wopc[] = {
				{"push", w_push}, {"pall", w_pall}, {"pint", w_pint},
{"pop", w_pop}, {"swap", w_swap},
			    {NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " $\n\t");
	if (op && op[0] == '#')
		return (0);
	gv.arg = strtok(NULL, " $\n\t");
	while (wopc[i].opcode && op)
	{
		if (strcmp(op, wopc[i].opcode) == 0)
		{	wopc[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && wopc[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(content);
		cleanup(stack);
		exit(EXIT_FAILURE); }
	return (1);
}


/**
 * cleanup - Frees the memory allocated for the stack.
 * @stack: Double pointer to the stack.
 */
void cleanup(stack_t **stack)
{
stack_t *current = *stack;
stack_t *next;

while (current != NULL)
{
next = current->next;
free(current);
current = next;
}
*stack = NULL;
}
