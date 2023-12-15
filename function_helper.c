#include "monty.h"
/**
* w_exet - executes the opcode
* @stack: head linked list - stack
* @line_number: line_counter
* @file: poiner to monty file
* @content: line content
* Return: to 1
*/
int w_exet(char *content, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t wopc[] = {
				{"push", w_push}, {"pall", w_pall}, {"pint", w_pint},
{"pop", w_pop}, {"swap", w_swap}, {"add", w_add}, {"nop", w_nop},
			    {NULL, NULL}
				};
	unsigned int i = 0;
	char *w_op;

	w_op = strtok(content, " $\n\t");
	if (w_op && w_op[0] == '#')
		return (0);
	gv.arg = strtok(NULL, " $\n\t");
	for (i = 0; wopc[i].opcode; i++)
    {
        if (strcmp(w_op, wopc[i].opcode) == 0)
        {
            wopc[i].f(stack, line_number);
            return 0;
        }
    }

	if (w_op && wopc[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_number, w_op);
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
