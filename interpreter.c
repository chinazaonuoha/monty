#include "monty.h"

/**
 * execute - Matches tokenized lines against the opcode execution table.
 * @content: The text line read from the script file
 * @stack: Pointer to the top of the stack
 * @line_number: Line tracking index
 * @file: Pointer to the open script file stream
 * Return: 0 if successfully resolved or empty
 */
int execute(char *content, stack_t **stack, unsigned int line_number, FILE *file)
{
instruction_t opst[] = {
{"pall", f_pall},
{NULL, NULL}
};
unsigned int i = 0;
char *op, *arg;

op = strtok(content, " \n\t\r");
if (!op || op[0] == '#')
return (0);

arg = strtok(NULL, " \n\t\r");

if (strcmp(op, "push") == 0)
{
run_push(stack, arg, line_number, content, file);
return (0);
}
if (strcmp(op, "pint") == 0)
{
f_pint(stack, line_number, content, file);
return (0);
}

while (opst[i].opcode && op)
{
if (strcmp(op, opst[i].opcode) == 0)
{
opst[i].f(stack, line_number);
return (0);
}
i++;
}

fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
free_stack(*stack);
free(content);
fclose(file);
exit(EXIT_FAILURE);
}
