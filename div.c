#include "monty.h"

/**
 * f_div - Divides the top two elements of the stack.
 * @head: Pointer to the head of the stack
 * @counter: Line number
 */
void f_div(stack_t **head, unsigned int counter)
{
    stack_t *current;
    int stack_length = 0;
    int division_result;

    current = *head;

    // Calculate the length of the stack
    while (current)
    {
        current = current->next;
        stack_length++;
    }

    // Check if there are at least two elements in the stack
    if (stack_length < 2)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;

    // Check for division by zero
    if (current->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    // Perform division and update the stack
    division_result = current->next->n / current->n;
    current->next->n = division_result;
    *head = current->next;
    free(current);
}
