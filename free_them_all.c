#include "monty.h"
#include "lists.h"

/**
 * free_them_all - Liberates the system of all memory-occupying rebels
 * Return: Peace and tranquility to the system. ...Maybe!
 */
void free_them_all(void)
{
	stack_t *freedom = NULL;
	stack_t *liberation = NULL;

	freedom = *global_head;

	while (freedom != NULL)
	{
		liberation = freedom->next;
		free(freedom);
		freedom = liberation;
	}
}
