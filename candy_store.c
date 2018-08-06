/* ****************************************************************************************/
/* // **********  ////    Program to test the C concepts
/* // **********  ////    How can compile the program?
/* // **********  ////    In prompt the command or terminal:
/* // **********  ////    LINUX: gcc candy_store.c -o obj_exec && ./obj_exec 
/* // **********  ////    WINDOWS: gcc cady_store.c -o obj_exec && obj_exec 
/* // **********  ////    valgrind > valgrind --leak-check=full ./obj_exec
/* // **********  ////    Author: Luiz Otávio Mendes de Oliveira
/* // **********  ////    Creation date:    31jul2018
/* // **********  ////    Revision date:    31jul2018  
/* // **********  ////    ******************************************************************/

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline();
char **split_string(char *);

int transactionsSum(int values_count, int *values)
{

    int *vetor_diferenca = malloc(sizeof(int) * (values_count - 1));
    int j = 0;

    // VETOR DIFERENÇA
    for (int i = 1; i < values_count; i++)
    {
        *(vetor_diferenca + j) = *(values + i) - *(values + i - 1);
        j++;
    }

    // output vetor_diferenca
    // for (int i = 0; i < j; i++)
    //     printf("vetor_diferenca[%i]: %i\n", i, vetor_diferenca[i]);

    int sum = 0;
    for (int i = 0; i < j; i++)
    {
        if (vetor_diferenca[i] > 0)
        {
            sum += vetor_diferenca[i];
            //printf("Sum: %i\n", sum);
        }
    }

    free(vetor_diferenca);
    return sum;
}

int main()
{
    puts("Digite o tamanho do vetor: ");
    char *n_str = readline();
    char *n_endptr;                       // trash, not number
    int n = strtol(n_str, &n_endptr, 10); // number of elements > convert string to long

    if (n_endptr == n_str || *n_endptr != '\0')
    {
        exit(EXIT_FAILURE);
    }

    char **arr_temp = split_string(readline());

    int *arr = malloc(n * sizeof(int)); // array

    for (int i = 0; i < n; i++)
    {
        char *arr_item_endptr; // trash, not number
        char *arr_item_str = *(arr_temp + i);
        int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);

        if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0')
        {
            exit(EXIT_FAILURE);
        }

        *(arr + i) = arr_item;
    }

    int retorno = transactionsSum(n, arr);

    // printf("Retorno: %i\n", retorno);
    printf("%i\n", retorno);

    return 0;
}

char *readline()
{
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char *data = malloc(alloc_length);

    while (true)
    {
        char *cursor = data + data_length;
        char *line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line)
        {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
        {
            break;
        }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data)
        {
            break;
        }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n')
    {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char **split_string(char *str)
{
    char **splits = NULL;
    char *token = strtok(str, " ");

    int spaces = 0;

    while (token)
    {
        splits = realloc(splits, sizeof(char *) * ++spaces);
        if (!splits)
        {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

// char *ltrim(char *str)
// {
//     if (!str)
//     {
//         return '\0';
//     }

//     if (!*str)
//     {
//         return str;
//     }

//     while (*str != '\0' && isspace(*str))
//     {
//         str++;
//     }

//     return str;
// }

// char *rtrim(char *str)
// {
//     if (!str)
//     {
//         return '\0';
//     }

//     if (!*str)
//     {
//         return str;
//     }

//     char *end = str + strlen(str) - 1;

//     while (end >= str && isspace(*end))
//     { // *end > number of position
//         end--;
//     }

//     *(end + 1) = '\0';

//     return str;
// }

// int smallest = INT32_MAX;
// unsigned int position_smallest = 0;
// int best_profit = 0;
// int sell = 0;

// int day_next = 0;

// for (int i = 0; i < values_count; i++)
// {
//     if (*(values + i) < smallest)
//     {
//         smallest = values[i];
//         position_smallest = i;
//     }
// }

// day_next = position_smallest + 1;
// int N = values_count - position_smallest;

// int *matriz[] = malloc(sizeof(int) * N * N);

// for (int i = position_smallest + 1; i < values_count - position_smallest - 1; i++)
// {
//     // for (int j = i + 1; i < values_count - position_smallest - 1; i++)
//     // {
//     //     if (values[j] - values[i] > best_profit)
//     //         best_profit = *(values + j) - *(values + i);
//     // }
// }

// int *next_sub_today = malloc(sizeof(int) * (values_count - 1));
// int j = 0;

// for (int i = 0; i < values_count - 1; i++)
// {
//     j = i + 1;
//     *(next_sub_today + 1) = *(values + j) - *(values + i);

//     //     if (A[j] - A[i] <= 0)
//     //         continue;
//     //     else if
//     // }
//     printf("Sub A[%i]: %i\n", i, next_sub_today[i]);
// }

// for(int i=0; )
// 7 1 5 3 6 4
// -6 4 -2 3 -2

//

//         int vetor_max = 0;
// int position_max = 0;

// int profit = 0;
// int profit_total = 0;
// int now = 0;