#include "monty.h"

/**
 * print_char - Function that prints the character of the top element
 * @stack: The stack. Basically a linked list in stack format
 * @line_num: Line number in .m file
 * Return: Nothing. Exits if stack is empty or if value is out of
 * ASCII range
 */
void print_char(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_num);
		atexit(free_them_all);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n", line_num);
		atexit(free_them_all);
		exit(EXIT_FAILURE);
	}

	putchar((*stack)->n);
	putchar('\n');
}
