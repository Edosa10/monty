#include "monty.h"

/**
 * f_rotr - Rotates the stack to the bottom
 * @head: Pointer to the head of the stack
 * @counter: Line number
 * Return: No return value
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *copy, *last;

    if (*head == NULL || (*head)->next == NULL)
        return;

    copy = *head;
    while (copy->next != NULL)
    {
        last = copy;
        copy = copy->next;
    }

    last->next = NULL;
    copy->next = *head;
    copy->prev = NULL;
    (*head)->prev = copy;
    *head = copy;
}
