#include "monty.h"

/**
 * w_addq - add node to the tail
 * @wn: new element
 * @head: the head
*/
void w_addq(stack_t **head, int wn)
{
stack_t *n_node = malloc(sizeof(stack_t));
stack_t *t = *head;
if (!n_node)
{
fprintf(stderr, "Error: malloc failed\n");
fclose(gv.file);
free(gv.ctt);
cleanup(head);
exit(EXIT_FAILURE);
}
n_node->n = wn;
n_node->next = NULL;
if (!*head)
{
n_node->prev = NULL;
*head = n_node;
return;
}
while (t->next)
t = t->next;

n_node->prev = t;
t->next = n_node;
}


/**
 * w_adds - add node to the head
 * @head: the head
 * @wn: new element
*/
void w_adds(stack_t **head, int wn)
{
stack_t *n_node = malloc(sizeof(stack_t));
if (!n_node)
{
fprintf(stderr, "Error: malloc failed\n");
fclose(gv.file);
free(gv.ctt);
cleanup(head);
exit(EXIT_FAILURE);
}
n_node->n = wn;
n_node->prev = NULL;
n_node->next = *head;
if (*head)
(*head)->prev = n_node;
*head = n_node;
}
