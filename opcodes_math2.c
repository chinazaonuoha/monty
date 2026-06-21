#include "monty.h"
/**
 * f_sub - Subtracts the top element from the second top element.
 * @head: Double pointer to stack head
 * @arg: String argument (unused)
 * @line: Line number index
 * @con: String buffer to clean on failure
 * @f: File stream descriptor
 */
void f_sub(stack_t **head, char *arg, unsigned int line, char *con, FILE *f)
{
stack_t *temp;

(void)arg;
if (!head || !*head || !(*head)->next)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", line);
free_stack(*head);
free(con);
fclose(f);
exit(EXIT_FAILURE);
}
(*head)->next->n -= (*head)->n;
temp = *head;
*head = temp->next;
(*head)->prev = NULL;
free(temp);
}

/**
 * f_div - Divides the second top element by the top element.
 * @head: Double pointer to stack head
 * @arg: String argument (unused)
 * @line: Line number index
 * @con: String buffer to clean on failure
 * @f: File stream descriptor
 */
void f_div(stack_t **head, char *arg, unsigned int line, char *con, FILE *f)
{
stack_t *temp;

(void)arg;
if (!head || !*head || !(*head)->next)
{
fprintf(stderr, "L%d: can't div, stack too short\n", line);
free_stack(*head);
free(con);
fclose(f);
exit(EXIT_FAILURE);
}
if ((*head)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line);
free_stack(*head);
free(con);
fclose(f);
exit(EXIT_FAILURE);
}
(*head)->next->n /= (*head)->n;
temp = *head;
*head = temp->next;
(*head)->prev = NULL;
free(temp);
}

/**
 * f_mul - Multiplies the second top element with the top element.
 * @head: Double pointer to stack head
 * @arg: String argument (unused)
 * @line: Line number index
 * @con: String buffer to clean on failure
 * @f: File stream descriptor
 */
void f_mul(stack_t **head, char *arg, unsigned int line, char *con, FILE *f)
{
stack_t *temp;

(void)arg;
if (!head || !*head || !(*head)->next)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", line);
free_stack(*head);
free(con);
fclose(f);
exit(EXIT_FAILURE);
}
(*head)->next->n *= (*head)->n;
temp = *head;
*head = temp->next;
(*head)->prev = NULL;
free(temp);
}

/**
 * f_mod - Computes the remainder of division of second top by top element.
 * @head: Double pointer to stack head
 * @arg: String argument (unused)
 * @line: Line number index
 * @con: String buffer to clean on failure
 * @f: File stream descriptor
 */
void f_mod(stack_t **head, char *arg, unsigned int line, char *con, FILE *f)
{
stack_t *temp;

(void)arg;
if (!head || !*head || !(*head)->next)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line);
free_stack(*head);
free(con);
fclose(f);
exit(EXIT_FAILURE);
}
if ((*head)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line);
free_stack(*head);
free(con);
fclose(f);
exit(EXIT_FAILURE);
}
(*head)->next->n %= (*head)->n;
temp = *head;
*head = temp->next;
(*head)->prev = NULL;
free(temp);
}
