#include "monty.h"
#include "lists.h"

/**
 * print_string - Function that prints all characters in the stack
 * @stack: The stack. Basically a linked list in stack format
 * @line_num: Line number in .m file
 * Return: Nothing. Exits if stack is empty or if value is out of
 * ASCII range
 */
void print_string(stack_t **stack, unsigned int line_num)
{
	stack_t *string = *stack;
	(void) line_num;

	while (string != NULL)
	{
		if (string->n < 0 || string->n > 127 || string->n == 0)
			break;

		putchar(string->n);
		string = string->next;
	}
	putchar('\n');
}
