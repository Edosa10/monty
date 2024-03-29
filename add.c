#include "monty.h"

/**
 * f_add - Adds the top two elements of the stack.
 * @head: Pointer to the head of the stack
 * @counter: Line number where the operation occurs
 * Return: No return value
 */
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;

	while (h)
	{
		h = h->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file); // This line assumes a global variable named 'bus' which is not provided in the code snippet.
		free(bus.content); // This line assumes a global variable named 'bus' which is not provided in the code snippet.
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
