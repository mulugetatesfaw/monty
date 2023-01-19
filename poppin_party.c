#include "monty.h"

/**
 * Poppin_Party - Function that pops a stack. That is, removes
 * the top element of the stack. Kira Kira Doki Doki
 * @stack: The stack. Basically a linked list in stack format
 * @line_num: Line number of .m file
 * Return: Nothing. Exits if the stack is empty
 */
void Poppin_Party(stack_t **stack, unsigned int line_num)
{
	stack_t *Kasumi;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	Kasumi = *stack;
	*stack = (*stack)->next;
	free(Kasumi);
}
