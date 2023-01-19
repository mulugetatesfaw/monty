#include "monty.h"
#include "lists.h"

/**
 * rotate_first - Function that moves the last element in the stack
 * to the top
 * @stack: The stack. Basically a linked list in stack format
 * @line_num: Line number in .m file
 * Return: Nothing. Exits if stack contains less than 2 elements
 */
void rotate_first(stack_t **stack, unsigned int line_num)
{
	stack_t *new_first = *stack;
	(void) line_num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	while (new_first->next != NULL)
		new_first = new_first->next;

	new_first->next = *stack;
	(*stack)->prev = new_first;
	new_first->prev = NULL;
	new_first = (*stack)->next;
	(*stack)->next = NULL;
	*stack = new_first;
}
