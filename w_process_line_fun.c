#include"monty.h"


void w_push_wrapper(stack_t **stack, unsigned int ln, char *arg)
{
(void)arg;
    w_push(stack, ln);
}

void w_pall_wrapper(stack_t **stack, unsigned int ln, char *arg)
{
    (void)arg;
    w_pall(stack, ln);
}
/**
 * wparse_line - fuction that parse a line
 * @line: a line
 * @arg: arguments
 * @opcode: opcode
*/

void wparse_line(char *line, char **opcode, char **arg)
{
*opcode = strtok(line, " \t\n");
*arg = strtok(NULL, " \t\n");
}
/**
 * w_execInstru - fuction that execute instructions
 * @ln: a line number
 * @oc: opcode
 * @stack: stack
*/
void w_execInstru(char *oc, stack_t **stack, unsigned int ln)
{
if (oc == NULL || oc[0] == '#')
return;

if (strcmp(oc, "push") == 0)
{
w_error_handle("usage: push integer", ln);
}
else if (strcmp(oc, "pall") == 0)
{
w_pall(stack, ln);
}
}
/**
 * wcheck_oc - fuction that execute instructions
 * @ln: a line number
 * @oc: opcode
 * @stack: stack
 * @arg: arguments
*/
void wcheck_oc(char *oc, stack_t **stack, unsigned int ln)
{
instruction_t instructions[] = {
{"push", w_push_wrapper},
{"pall", w_pall_wrapper},
};
int found = 0;
size_t winx;
for (winx = 0; winx < sizeof(instructions) / sizeof(instructions[0]); winx++)
{
if (strcmp(oc, instructions[winx].opcode) == 0)
{
found = 1;
instructions[winx].f(stack, ln);
break;
}
}
if (!found)
w_error_handle("unknown instruction", ln);
}
