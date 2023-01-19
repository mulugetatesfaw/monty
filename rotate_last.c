#include "monty.h"
#include "lists.h"

/**
 * rotate_last - Function that moves the first element in the stack
 * to the bottom
 * @stack: The stack. Basically a linked list in stack format
 * @line_num: Line number in .m file
 * Return: Nothing. Exits if stack contains less than 2 elements
 */
void rotate_last(stack_t **stack, unsigned int line_num)
{
	stack_t *new_last = *stack;
	(void) line_num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	while (new_last->next != NULL)
		new_last = new_last->next;

	new_last->next = *stack;
	(*stack)->prev = new_last;
	new_last = (*stack)->next;
	new_last->prev = NULL;
	(*stack)->next = NULL;
	*stack = new_last;
}
