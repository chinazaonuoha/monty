#include "monty.h"

/**
 * f_push - Pushes an element to the stack with robust input checking.
 * @head: Double pointer to stack head
 * @line_number: Line tracking index
 */
void f_push(stack_t **head, unsigned int line_number)
{
int n, j = 0, flag = 0;
stack_t *new_node;

if (!bus.arg)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
free_stack(*head);
free(bus.content);
fclose(bus.file);
exit(EXIT_FAILURE);
}

if (bus.arg[0] == '-')
j++;
for (; bus.arg[j] != '\0'; j++)
{
if (!isdigit(bus.arg[j]))
flag = 1;
}
if (flag == 1)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
free_stack(*head);
free(bus.content);
fclose(bus.file);
exit(EXIT_FAILURE);
}

n = atoi(bus.arg);
new_node = malloc(sizeof(stack_t));
if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
free_stack(*head);
free(bus.content);
fclose(bus.file);
exit(EXIT_FAILURE);
}

new_node->n = n;
new_node->prev = NULL;
new_node->next = *head;
if (*head)
(*head)->prev = new_node;
*head = new_node;
}

/**
 * f_pall - Traverses and prints the whole stack from top to bottom.
 * @head: Double pointer to stack head
 * @line_number: Line tracking index (unused)
 */
void f_pall(stack_t **head, unsigned int line_number)
{
stack_t *current = *head;
(void)line_number;

while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}

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