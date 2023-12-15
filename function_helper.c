#include "monty.h"
/**
* w_exet - executes the opcode
* @stack: head linked list - stack
* @line_number: line_counter
* @file: poiner to monty file
* @content: line content
* Return: to 1
*/
void (*w_exet(char *content, stack_t **stack, unsigned int line_number, FILE *file))(stack_t **, unsigned int)
{
	instruction_t wopc[] = {
				{"push", w_push}, {"pall", w_pall}, {"pint", w_pint},
{"pop", w_pop}, {"swap", w_swap}, {"add", w_add}, {"nop", w_nop},
			    {NULL, NULL}
				};
	unsigned int i;
	(void)stack;
	(void)line_number;
	(void)file;
    for (i = 0; wopc[i].opcode; i++)
    {
        if (strcmp(wopc[i].opcode, content) == 0)
            break;
    }

    return wopc[i].f;
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
