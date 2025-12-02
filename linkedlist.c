/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:07:29 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/12/02 23:42:41 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct Node{
    int x;
    struct Node *next;
} Node;

void push_back(Node **root, int value)
{
    Node *new;

    new = malloc(sizeof(Node));
    if (!new)
        return ;
    new->x = value;
    new->next = NULL;
    if (!*root)
        {
        *root = new;
        return;
        }
    Node *curr = *root;
    while (curr->next)
        curr=curr->next;
    curr->next = new;
}

void push_front(Node **head, int value)
{
    Node *new_node = malloc(sizeof(Node));

    if (!new_node)
        return ;
    if (!head)
        return ;
    new_node->x = value;
    new_node->next = *head;
    *head = new_node;

}

void ffree(Node *ro)
{
    Node *n;
    while (ro)
    {
        n = ro->next;
        free(ro);
        ro = n;
    }
}

int lstsize(Node *head)
{
    Node *ls = head;
    int i = 0;
    while (ls)
    {
        i++;
        ls = ls->next;
    }

    return i;
}

void print_list(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        printf("%d\n", curr->x);
        curr = curr->next;
    }

}

void pop_front(Node **head)
{
    if (!head || !*head)
        return ;
    Node *lst = *head;
    *head = lst->next;
    free(lst);
    return;
}

void remove_one(Node **head, int value)
{
    Node *lst = *head;
    if (!head || !*head)
        return ;
    if (lst->x == value)
    {
        *head = lst->next;
        free(lst);
        return;
    }
    Node *prev = lst;
    lst = lst->next;
    while (lst)
    {
        if (lst->x == value)
        {
            prev->next = lst->next;
            free(lst);
            return;
        }
        prev = lst;
        lst = lst->next;
    }

}

void reverse(Node **head)
{
    Node *prev = NULL;
    Node *cur = *head;
    Node *next;

    if (!*head)
        return ;
    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}
