#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "quick-sort.h"

stack *stack_create(int capacity) {
    stack *s = malloc(sizeof(stack));
    if (!s) {
        return NULL;
    }
    s->data = malloc(capacity * sizeof(int));
    s->top = -1;
    s->capacity = capacity;
    return s;
}

void stack_push(stack *stack, s_node value) {
    if (stack->top + 1 >= stack->capacity) {
        int new_cap = stack->capacity * 2;
        int *tmp = realloc(stack->data, new_cap * sizeof(int));
        if (!tmp) {
            stack_free(stack);
            return -1;
        }
        stack->data = tmp;
        stack->capacity = new_cap;
    }
    stack->data[++stack->top] = value;
}

s_node stack_pop(stack *stack) {
    if (stack->top < 0) {
        printf("Erro: pop em pilha vazia\n");
        return;
    }
    return stack->data[stack->top--];
}

int stack_is_empty(const stack *stack) {
    return stack->top < 0;
}

void stack_free(stack *stack) {
    if (!stack) return;
    free(stack->data);
    free(stack);
}

int* read_array(int n) {
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        return;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Erro: valor inválido na posição %d\n", i);
            free(arr);
            return;
        }
    }
    return arr;
}

void print_array(const int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
}

int partition(int *arr, int left, int right) {
    int pivot = arr[right];

    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    int tmp = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = tmp;

    return i + 1;
}

void quick_sort(int *arr, int left, int right) {
    if (left < right) {
        int pi = partition(arr, left, right);
        quick_sort(arr, left, pi - 1);
        quick_sort(arr, pi + 1, right);
    }
}

void quick_sort_non_recursive(int *arr, int left, int right) {
    if (left >= right) return;
    stack *st = stack_create(right - left + 1);

    stack_push(st, (s_node){ .left = left, .right = right });

    while (!stack_is_empty(st)) {
        s_node range = stack_pop(st);
        int l = range.left, r = range.right;

        int p = partition(arr, l, r);

        if (p - 1 > l) {
            stack_push(st, (s_node){ .left = l, .right = p - 1 });
        }
        if (p + 1 < r) {
            stack_push(st, (s_node){ .left = p + 1, .right = r });
        }
    }

    stack_free(st);
}