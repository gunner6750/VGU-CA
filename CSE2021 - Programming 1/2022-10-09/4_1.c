#include <stdio.h>
#include <stdlib.h>

int *i_arrayNew_1d(int _size)
{
    return (int *)calloc(_size, sizeof(int));
}

int **i_arrayNew_2d(int row, int col)
{
    int **matrix = (int **)calloc(row, sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int *)calloc(col, sizeof(int));
    }
    return matrix;
}

void i_arrayPrint_1d(int *arr, int _size)
{
    for (int i = 0; i < _size; i++)
    {
        printf("%d \t", *(arr + i));
    }
    puts("");
}

void i_arrayPrint_2d(int *matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        printf("\t");
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", matrix[i * col + j]);
        }
        printf("\n");
    }
}

// void i_arrayFree_2d(int **matrix)
// {
//     for (int i = 0; i < (*matrix)[0][0]; i++)
//     {
//         free((*matrix)[i]);
//     }
//     free((*matrix));
//     (*matrix) = NULL;
//     return;
// }

int *i_arrayAddEvenIndicesRowwise_2d(int *arr, int row, int col)
{
    int *result = i_arrayNew_1d(row);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j % 2 == 0)
            {
                result[i] += arr[i * col + j];
            }
        }
    }
    return result;
}

int main()
{
    int row = 4;
    int col = 3;
    int *arr = i_arrayNew_1d(row * col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i * col + j] = i * col + j + 1;
        }
    }
    printf("The matrix:\n");
    i_arrayPrint_2d(arr, row, col);

    int *result = i_arrayAddEvenIndicesRowwise_2d(arr, row, col);
    printf("The result:\n");
    i_arrayPrint_1d(result, row);
}