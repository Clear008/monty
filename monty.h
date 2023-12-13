#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number, char *arg);
} instruction_t;


/* Instructions */
void w_push(stack_t **stack, unsigned int line_number, char *arg);
void w_pall(stack_t **stack, unsigned int line_number, char *arg);


/* Error handler */
void w_error_handle(const char *w_nt, unsigned int line_number);


/* Other funtions */
int w_isdigit(char *wstr);
void wparse_line(char *line, char **opcode, char **arg);
void w_execInstru(char *oc, char *arg, stack_t **stack, unsigned int ln);
void wcheck_oc(char *oc, char *arg, stack_t **stack, unsigned int ln);

#endif
