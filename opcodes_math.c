#include "monty.h"

/**
 * f_pop - Removes the top element of the stack.
 * @head: Double pointer to stack head
 * @arg: String argument (unused here)
 * @line: Line number index
 * @con: String buffer to clean on failure
 * @f: File stream descriptor
*/
void f_pop(stack_t **head, char *arg, unsigned int line, char *con, FILE *f)
{
stack_t *temp;

(void)arg;

if (!head || !*head)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line);
free_stack(*head);
free(con);
fclose(f);
exit(EXIT_FAILURE);
}
temp = *head;
*head = temp->next;
if (*head)
(*head)->prev = NULL;
free(temp);
}

/**
 * f_swap - Swaps the top two elements of the stack.
 * @head: Double pointer to stack head
 * @arg: String argument (unused here)
 * @line: Line number index
 * @con: String buffer to clean on failure
 * @f: File stream descriptor
 */
void f_swap(stack_t **head, char *arg, unsigned int line, char *con, FILE *f)
{
int temp_val;

(void)arg; /* Suppress unused parameter warning safely */

if (!head || !*head || !(*head)->next)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line);
free_stack(*head);
free(con);
fclose(f);
exit(EXIT_FAILURE);
}

temp_val = (*head)->n;
(*head)->n = (*head)->next->n;
(*head)->next->n = temp_val;
}

/**
 * f_add - Adds the top two elements of the stack.
 * @head: Double pointer to stack head
 * @arg: String argument (unused here)
 * @line: Line number index
 * @con: String buffer to clean on failure
 * @f: File stream descriptor
 */
void f_add(stack_t **head, char *arg, unsigned int line, char *con, FILE *f)
{
stack_t *temp;

(void)arg; /* Safely suppress unused variable warning */

if (!head || !*head || !(*head)->next)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line);
free_stack(*head);
free(con);
fclose(f);
exit(EXIT_FAILURE);
}

(*head)->next->n += (*head)->n;
temp = *head;
*head = temp->next;
(*head)->prev = NULL;
free(temp);
}
