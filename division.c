#include "monty.h"
#include "lists.h"

/**
 * division - Function that finds the quotient of the top two stacks,
 * stores the quotient into the second top element, then eliminates
 * the first top element
 * @stack: The stack. Basically a linked list in stack format
 * @line_num: Line number in .m file
 * Return: Nothing. Exits if less than two elements are in the stack,
 * or if an attempt to divide by 0 is found
 */
void division(stack_t **stack, unsigned int line_num)
{
	stack_t *quotient = NULL;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", line_num);
		atexit(free_them_all);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_num);
		atexit(free_them_all);
		exit(EXIT_FAILURE);
	}

	quotient = (*stack)->next;
	quotient->n /= (*stack)->n;
	quotient->prev = NULL;
	quotient = *stack;
	*stack = (*stack)->next;
	free(quotient);
}
