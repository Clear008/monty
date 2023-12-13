#include"monty.h"
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
 * @arg: arguments
 * @oc: opcode
 * @stack: stack
*/
void w_execInstru(char *oc, char *arg, stack_t **stack, unsigned int ln)
{
if (oc == NULL || oc[0] == '#')
return;

if (strcmp(oc, "push") == 0)
{
if (arg == NULL || !w_isdigit(arg))
w_error_handle("usage: push integer", ln);

w_push(stack, ln, arg);
}
else if (strcmp(oc, "pall") == 0)
{
w_pall(stack, ln, arg);
}
}
/**
 * wcheck_oc - fuction that execute instructions
 * @ln: a line number
 * @oc: opcode
 * @stack: stack
 * @arg: arguments
*/
void wcheck_oc(char *oc, char *arg, stack_t **stack, unsigned int ln)
{
instruction_t instructions[] = {
{"push", w_push},
{"pall", w_pall},
};
int found = 0;
size_t winx;
for (winx = 0; winx < sizeof(instructions) / sizeof(instructions[0]); winx++)
{
if (strcmp(oc, instructions[winx].opcode) == 0)
{
found = 1;
instructions[winx].f(stack, ln, arg);
break;
}
}
if (!found)
w_error_handle("unknown instruction", ln);
}
