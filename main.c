#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "quick-sort.h"

int main()
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Erro: tamanho inválido\n");
        return 1;
    }

     int *arr = read_array(n);

     quick_sort_non_recursive(arr, 0, n - 1);

     print_array(arr, n);

    free(arr);
    return 1;
}

