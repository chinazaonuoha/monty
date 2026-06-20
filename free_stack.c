#include "monty.h"

/**
 * free_stack - Housekeeping helper to clean up nodes.
 * @head: Stack head
 */
void free_stack(stack_t *head)
{
stack_t *tmp;

while (head)
{
tmp = head->next;
free(head);
head = tmp;
}
}
