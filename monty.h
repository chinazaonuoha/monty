#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE /* Exposes getline and ssize_t to the compiler */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h> /* Ensures ssize_t is fully defined */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
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
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct op_handler_s - Context-aware
 * opcode configuration matrix
 * @opcode: The opcode string
 * @f: The function pointer matching the execution context signature
 */
typedef struct op_handler_s
{
char *opcode;
void (*f)(stack_t **stack, char *arg,
unsigned int line, char *con, FILE *f);
} op_handler_t;

/* Core Engine Prototypes */
int execute(char *content, stack_t **stack,
unsigned int line_number, FILE *file);
int execute_extended(char *op, stack_t **stack, unsigned int line);
void free_stack(stack_t *head);

/* Opcode Function Prototypes matching our context signature */
void run_push(stack_t **head, char *arg,
unsigned int line, char *con, FILE *f);
void f_pint(stack_t **head, char *arg, unsigned int line, char *con, FILE *f);
void f_pop(stack_t **head, char *arg, unsigned int line, char *con, FILE *f);
void f_swap(stack_t **head, char *arg, unsigned int line, char *con, FILE *f);
void f_add(stack_t **head, char *arg, unsigned int line, char *con, FILE *f);
void f_pall(stack_t **head, unsigned int line_number);

void f_nop(stack_t **head, char *arg, unsigned int line, char *con, FILE *f);

#endif
