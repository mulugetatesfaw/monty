#include "monty.h"

/**
 * print_int - Function that prints the value at the top of the stack
 * @stack: The stack. Basically a linked list in stack format
 * @line_num: Line number of .m file
 * Return: Nothing. Exits if the stack is empty
 */
void print_int(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_num);
		atexit(free_them_all);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
