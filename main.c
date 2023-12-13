#include "monty.h"
/**
 *main - check the code
 *@argv: array of command line argument
 *@argc: number of command line argument
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
char *line = NULL, *opcode, *arg;
size_t len = 0;
ssize_t read;
stack_t *stack = NULL;

unsigned int line_number = 0;
FILE *file = fopen(argv[1], "r");
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

while ((ssize_t)(read = getline(&line, &len, file)) != -1)
{
line_number++;
wparse_line(line, &opcode, &arg);
w_execInstru(opcode, arg, &stack, line_number);
wcheck_oc(opcode, arg, &stack, line_number);
}

free(line);
fclose(file);

return (EXIT_SUCCESS);
}
