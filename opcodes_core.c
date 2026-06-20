#include "monty.h"

/**
 * run_push - Validates and executes a push action locally.
 * @head: Double pointer to stack head
 * @arg: String argument containing integer
 * @line: Line number index
 * @con: String buffer to clean on failure
 * @f: File stream descriptor
 */
void run_push(stack_t **head, char *arg, unsigned int line, char *con, FILE *f)
{
int n, j = 0, flag = 0;
stack_t *new_node;

if (!arg)
flag = 1;
else
{
if (arg[0] == '-')
j++;
for (; arg[j] != '\0'; j++)
{
if (!isdigit(arg[j]))
flag = 1;
}
}
if (flag == 1)
{
fprintf(stderr, "L%d: usage: push integer\n", line);
free_stack(*head);
free(con);
fclose(f);
exit(EXIT_FAILURE);
}
n = atoi(arg);
new_node = malloc(sizeof(stack_t));
if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
free_stack(*head);
free(con);
fclose(f);
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
 * f_pint - Prints the value at the top of the stack.
 * @head: Double pointer to stack head
 * @arg: String argument (unused here)
 * @line: Line number index
 * @con: String buffer to clean on failure
 * @f: File stream descriptor
 */
void f_pint(stack_t **head, char *arg, unsigned int line,
char *con, FILE *f)
{
(void)arg; /* Suppress unused parameter warning safely */

if (!head || !*head)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line);
free_stack(*head);
free(con);
fclose(f);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}
