/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc server and client chained list utils
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct          s_list {
        char            *data;
        struct s_list   *next;
        struct s_list   *prev;
}                       t_list;

t_list *get_new(char *data)
{
        t_list *thenew = malloc(sizeof(*thenew));

        if (thenew) {
                memset(thenew, 0, sizeof(*thenew));
                thenew->data = strdup(data);
                thenew->next = NULL;
                thenew->prev = NULL;
        }
        return (thenew);
}

void *push_front(t_list *head, t_list *new)
{
        if (!head) {
                head = new;
        } else {
                head->prev = new;
                new->next = head;
                head = new;
        }
        return (head);
}

void *push_back(t_list *head, t_list *new)
{
        t_list *foo = head;
        if (!head) {
                head = new;
        } else {
                while (foo->next) foo = foo->next;
                foo->next = new;
                new->prev = foo;
        }
        return (head);
}

void print_me_right(t_list *liste)
{
        printf("%s\n", "Print right");
        for (t_list *foo = liste; foo; foo = foo->next ) {
                printf("%s\n", foo->data);
        }
}

void print_me_back(t_list *liste)
{
        t_list *foo = liste;
        printf("%s\n", "Print back");
        while (foo->next) foo = foo->next;
        for (t_list *faa = foo; faa; faa = faa->prev) {
                printf("%s\n", faa->data);
        }
}

void clean_me(t_list *head)
{
        while (head) {
                free(head->data);
                t_list *next = head->next;
                free(head);
                head = next;
        }
}

int main(void)
{
        t_list *foo = NULL;
        char *yolo[5] = {"foo", "fii", "faa", "#yolo", "#yulu"};
        for (int i = 0; i != 5; ++i) {
                t_list *faa = get_new(yolo[i]);
                foo = push_back(foo, faa);
        }
        print_me_right(foo);
        print_me_back(foo);
        clean_me(foo);
        return (0);
}
