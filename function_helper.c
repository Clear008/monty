#include "monty.h"
/**
 * processFile - function
 * @file: a file
 * @stack: a stack
*/
void processFile(FILE *file, stack_t **stack)
{
char *line = NULL;
size_t len = 0;
int i;
while (getline(&line, &len, file) != -1)
{
char *opcode = strtok(line, " \n\t");

if (opcode)
{
instruction_t instructions[] = {
{"push", w_push},
{"pall", w_pall},
{NULL, NULL}};

i = 0;
while (instructions[i].opcode)
{
if (strcmp(opcode, instructions[i].opcode) == 0)
{
instructions[i].f(stack, 0);
break;
}
i++;
}
if (!instructions[i].opcode)
{
fprintf(stderr, "L%d: unknown instruction %s\n", 0, opcode);
exit(EXIT_FAILURE);
}
}
}
free(line);
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