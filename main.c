#include "monty.h"
/**
 *main - check the code
 *@argv: array of command line argument
 *@argc: number of command line argument
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
FILE *file = fopen(argv[1], "r");
stack_t *stack;
if (argc != 2)
{
fprintf(stderr, "Usage: %s <file>\n", argv[0]);
exit(EXIT_FAILURE);
}

if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
stack = NULL;
processFile(file, &stack);
cleanup(&stack);
return (0);
}
