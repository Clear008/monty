#include "monty.h"



/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", w_push}, {"pall", w_pall},
			    {NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		cleanup(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}


/**
 * cleanup - Frees the memory allocated for the stack.
 * @stack: Double pointer to the stack.
 */
void cleanup(stack_t *stack)
{
	stack_t *aux;

	aux = stack;
	while (stack)
	{
		aux = stack->next;
		free(stack);
	 stack = aux;
	}
}