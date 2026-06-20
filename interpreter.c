#include "monty.h"

/**
 * execute_extended - Fallback array loop for secondary opcodes.
 * @op: The opcode string token
 * @stack: Double pointer to the stack
 * @line: Current line number index
 * Return: 0 if matched and executed, 1 if no match found
 */
int execute_extended(char *op, stack_t **stack, unsigned int line)
{
instruction_t opst[] = {
{"pall", f_pall},
{NULL, NULL}
};
unsigned int i = 0;

while (opst[i].opcode && op)
{
if (strcmp(op, opst[i].opcode) == 0)
{
opst[i].f(stack, line);
return (0);
}
i++;
}
return (1);
}

/**
 * execute - Matches tokenized lines against the optimized jump table.
 * @content: The text line read from the script file
 * @stack: Pointer to the top of the stack
 * @line_number: Line tracking index
 * @file: Pointer to the open script file stream
 * Return: 0 if successfully resolved or empty
 */
int execute(char *content, stack_t **stack,
unsigned int line_number, FILE *file)
{
op_handler_t matrix[] = {
{"push", run_push},
{"pint", f_pint},
{"pop", f_pop},
{"swap", f_swap},
{"add", f_add},
{"nop", f_nop},
{NULL, NULL}
};
int i = 0;
char *op, *arg;

op = strtok(content, " \n\t\r");
if (!op || op[0] == '#')
return (0);

arg = strtok(NULL, " \n\t\r");

while (matrix[i].opcode)
{
if (strcmp(op, matrix[i].opcode) == 0)
{
matrix[i].f(stack, arg, line_number, content, file);
return (0);
}
i++;
}

if (execute_extended(op, stack, line_number) == 0)
return (0);

fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
free_stack(*stack);
free(content);
fclose(file);
exit(EXIT_FAILURE);
}
