#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
 *main - check the code
 *@argv: array of command line argument
 *@argc: number of command line argument
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
FILE *file = NULL;
stack_t *stack;
char *line = NULL;
size_t len = 0;
ssize_t read;
unsigned int line_number = 1;

if (argc != 2 || argv[1] == NULL)
{
fprintf(stderr, "Usage: %s <file>\n", argv[0]);
exit(EXIT_FAILURE);
}
file = fopen(argv[1], "r");
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
stack = NULL;

while ((read = getline(&line, &len, file)) != -1)
{
execute(line, &stack, line_number, file);
line_number++;
}
cleanup(&stack);
fclose(file);
free(line);
return (0);
}
