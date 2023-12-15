#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct gv_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @ctt: line content
 * @wlifi: last in first out
 * Description: carries values
 */
typedef struct gv_s
{
	char *arg;
	FILE *file;
	char *ctt;
	int wlifi;
}  gv_t;
extern gv_t gv;

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
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;




/* Instructions */
void w_push(stack_t **stack, unsigned int line_number);
void w_pall(stack_t **stack, unsigned int line_number);
void w_pint(stack_t **stack, unsigned int line_number);
void w_pop(stack_t **stack, unsigned int line_number);
void w_swap(stack_t **stack, unsigned int line_number);
void w_add(stack_t **stack, unsigned int line_number);
void w_nop(stack_t **stack, unsigned int line_number);


/* others */
int w_exet(char *ctt, stack_t **stack, unsigned int line_number, FILE *file);
void cleanup(stack_t **stack);


void w_addq(stack_t **head, int wn);
void w_adds(stack_t **head, int wn);




#endif
