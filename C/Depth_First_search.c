#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void DFS(int i, int A[][7], int visited[])
{
    int j;
    printf("%d ", i);
    visited[i] = 1;
    for (j = 0; j < 7; j++)
    {
        if (A[i][j] == 1 && !visited[j])
        {
            DFS(j, A, visited);
        }
    }
}

int main(int argc, char *argv[])
{
    // DFS implementation
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int A[7][7] = {{0, 1, 1, 1, 0, 0, 0},
                   {1, 0, 0, 1, 0, 0, 0},
                   {1, 0, 0, 1, 0, 0, 0},
                   {1, 1, 1, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};
    DFS(4, A, visited);
    return 0;
}
