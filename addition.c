#include "monty.h"
#include "lists.h"

/**
 * addition - Function that finds the sum of the two top stacks, stores
 * the sum into the second top element, then eliminates the first top
 * element
 * @stack: The stack. Basically a linked list in stack format
 * @line_num: Line number in .m file
 * Return: Nothing. Exits if less than two elements are in the stack
 */
void addition(stack_t **stack, unsigned int line_num)
{
	stack_t *sum = NULL;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_num);
		atexit(free_them_all);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->next;
	sum->n += (*stack)->n;
	sum->prev = NULL;
	/**
	 * Freeing stack results in a segmentation fault. A workaround
	 * is provided instead as we need stack preserved
	 * The following two lines are commented out to demonstrate
	 * initial thought process
	 * free(stack);
	 * (*stack) = sum;
	 */
	sum = *stack;
	*stack = (*stack)->next;
	free(sum);
}
