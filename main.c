#include "monty.h"
gv_t gv = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *wcontent;
	FILE *file;
	size_t size = 0;
	ssize_t r_line = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	gv.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
while ((r_line = getline(&wcontent, &size, file)) > 0)
{
gv.ctt = wcontent;
count++;
w_exet(wcontent, &stack, count, file);
free(wcontent);
wcontent = NULL;
size = 0;
}
cleanup(&stack);
fclose(file);
return (0);
}
