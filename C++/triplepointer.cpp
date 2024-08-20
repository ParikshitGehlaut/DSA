#include <iostream>

typedef struct structure
{
    int width;
    int height;
    int ***tensor;
} s;

void printTensor(const s &query)
{
    for (int i = 0; i < query.height; ++i)
    {
        for (int j = 0; j < query.width; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                std::cout << query.tensor[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void deleteTensor(s &query)
{
    for (int i = 0; i < query.height; ++i)
    {
        for (int j = 0; j < query.width; ++j)
        {
            delete[] query.tensor[i][j];
        }
        delete[] query.tensor[i];
    }
    delete[] query.tensor;
}

int main()
{
    s Query;
    Query.width = 3;
    Query.height = 2;

    Query.tensor = new int **[Query.height];
    for (int i = 0; i < Query.height; ++i)
    {
        Query.tensor[i] = new int *[Query.width];
        for (int j = 0; j < Query.width; ++j)
        {
            Query.tensor[i][j] = new int[3];
            for (int k = 0; k < 3; ++k)
            {
                Query.tensor[i][j][k] = i * 100 + j * 10 + k;
            }
        }
    }

    printTensor(Query);

    deleteTensor(Query);

    return 0;
}
