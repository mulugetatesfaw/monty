#include "monty.h"
#include "lists.h"

/**
 * modulo_op - Function that finds the remainder of the top two stacks,
 * stores the remainder into the second top element, then eliminates
 * the first top element
 * @stack: The stack. Basically a linked list in stack format
 * @line_num: Line number in .m file
 * Return: Nothing. Exits if less than two elements are in the stack,
 * or if an attempt to divide by 0 is found
 */
void modulo_op(stack_t **stack, unsigned int line_num)
{
	stack_t *remainder = NULL;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", line_num);
		atexit(free_them_all);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_num);
		atexit(free_them_all);
		exit(EXIT_FAILURE);
	}

	remainder = (*stack)->next;
	remainder->n %= (*stack)->n;
	remainder->prev = NULL;
	remainder = *stack;
	*stack = (*stack)->next;
	free(remainder);
}
