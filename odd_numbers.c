/* ****************************************************************************************/
/* // **********  ////    Program to test the C concepts
/* // **********  ////    How can compile the program?
/* // **********  ////    In prompt the command or terminal:
/* // **********  ////    LINUX: gcc odd_numbers.c -o obj_exec && ./obj_exec 
/* // **********  ////    WINDOWS: gcc odd_numbers.c -o obj_exec && obj_exec 
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
char *ltrim(char *);
char *rtrim(char *);

// Complete the oddNumbers function below.

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */
int *oddNumbers(int l, int r, int *result_count)
{
    int j = 0;
    int *res = malloc(sizeof(int) * (r - l));
    *result_count = 1;
    int n = r - l;

    //printf("L: %i\nR: %i\nn: %i\n", l, r, n);
    for (int i = 0; i <= n; i++)
    {
        //printf("i: %i\n", i);

        if (l % 2 == 1)
        {
            // ímpar
            res[j] = l;
            //printf("res[%i]: %i\n", j, res[j]);
            j++;
        }
        l++;
    }

    *result_count = j;

    return res;
}

int main()
{
    puts("Type: ");

    char *l_endptr; // trash > not number
    char *l_str = ltrim(rtrim(readline()));
    int l = strtol(l_str, &l_endptr, 10); // convert string to int

    if (l_endptr == l_str || *l_endptr != '\0')
    {
        exit(EXIT_FAILURE);
    }

    char *r_endptr; // trash > not number
    char *r_str = ltrim(rtrim(readline()));
    int r = strtol(r_str, &r_endptr, 10); // convert string to int

    if (r_endptr == r_str || *r_endptr != '\0')
    {
        exit(EXIT_FAILURE);
    }

    int res_count;
    int *res = oddNumbers(l, r, &res_count);

    //printf("res_count: %i\n", res_count);
    puts("");
    for (int i = 0; i < res_count; i++)
        printf("%d\n", *(res + i));


    free(res);

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

char *ltrim(char *str)
{
    if (!str)
    {
        return '\0';
    }

    if (!*str)
    {
        return str;
    }

    while (*str != '\0' && isspace(*str))
    {
        str++;
    }

    return str;
}

char *rtrim(char *str)
{
    if (!str)
    {
        return '\0';
    }

    if (!*str)
    {
        return str;
    }

    char *end = str + strlen(str) - 1;

    while (end >= str && isspace(*end))
    { // *end > number of position
        end--;
    }

    *(end + 1) = '\0';

    return str;
}
