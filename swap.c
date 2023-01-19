#include "monty.h"

/**
 * swap - Function that has the top two elements trade places
 * @stack: The stack. Basically a linked list in stack format
 * @line_num: Line number in .m file
 * Return: Nothing. Exits if stack contains less than two elements
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *swap = NULL;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_num);
		atexit(free_them_all);
		exit(EXIT_FAILURE);
	}

	swap = (*stack)->next;
	(*stack)->next = swap->next;
	swap->next = *stack;

	/**
	 * This if statement is to avoid seg faults if the stack only consists
	 * of two elements
	 */
	if ((*stack)->next != NULL)
		(*stack)->next->prev = *stack;

	(*stack)->prev = swap;
	swap->prev = NULL;
	*stack = swap;
}
