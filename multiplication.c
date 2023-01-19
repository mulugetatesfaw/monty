#include "monty.h"

/**
 * multiplication - Function that finds the product of the two top stacks,
 * stores the product into the second top element, then eliminates
 * the first top element
 * @stack: The stack. Basically a linked list in stack format
 * @line_num: Line number in .m file
 * Return: Nothing. Exits if less than two elements are in the stack
 */
void multiplication(stack_t **stack, unsigned int line_num)
{
	stack_t *product = NULL;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line_num);
		atexit(free_them_all);
		exit(EXIT_FAILURE);
	}

	product = (*stack)->next;
	product->n *= (*stack)->n;
	product->prev = NULL;
	product = *stack;
	*stack = (*stack)->next;
	free(product);
}
