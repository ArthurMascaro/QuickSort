#ifndef QUICKSORT_H
#define QUICKSORT

typedef struct StackNode {
    int left;
    int right;
} s_node;

typedef struct Stack {
    s_node* data;   
    int top;   
    int capacity;
} stack;


stack *stack_create(int capacity);
void stack_push(stack *stack, s_node node);
s_node stack_pop(stack *stack);
int stack_is_empty(const stack *stack);
void stack_free(stack *stack);

int* read_array(int n);
void print_array(const int *arr, int n);
int partition(int *arr, int left, int right);
void quick_sort(int *arr, int left, int right);

void quick_sort_non_recursive(int *arr, int left, int right);

#endif