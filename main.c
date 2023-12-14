#include "monty.h"
/**
 *main - check the code
 *@argv: array of command line argument
 *@argc: number of command line argument
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
     char *line = NULL;
     int i;
    size_t len = 0;
    stack_t *stack = NULL;
    FILE *file = fopen(argv[1], "r");
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
                    instructions[i].f(&stack, 0);
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
    fclose(file);

    return 0;
}