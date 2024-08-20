#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LENGTH 100

// Structure for a node in the linked list

typedef struct Graph_Node
{
    char word[WORD_LENGTH];
    struct Graph_Node *next;
} Graph_Node;

void removeNewline(char *word)
{
    int len = strlen(word);

    for (int i = 0; i < len; i++)
    {
        if (word[i] == '\n')
        {
            word[i] = '\0';
            break; // Assuming there is only one newline character in the word
        }
    }
}

void get_key(const char *word, char *key)//using bubble sort
{
    int length = strlen(word);

    // Make a copy of the word
    memset(key, '\0', WORD_LENGTH);
    strcpy(key, word);

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (key[j] < key[i])
            {
                char temp = key[i];
                key[i] = key[j];
                key[j] = temp;
            }
        }
    }
}

// Calculating the hash value
int hash(char *str, int e)
{
    int hashValue = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        hashValue += str[i];
    }

    return hashValue % e; // e is size of hash table
}

// inserting a word into the hash table

void insertWord(Graph_Node **hashTable, char *word, int e)
{
    int index = hash(word, e);
    Graph_Node *newNode = (Graph_Node *)malloc(sizeof(Graph_Node));
    strcpy(newNode->word, word);
    if (hashTable[index] == NULL)
    {
        hashTable[index] = newNode;
    }
    else
    {
        struct Graph_Node *current = hashTable[index];
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

int areAnagrams(const char *s1, const char *s2)
{
    char str1[WORD_LENGTH];
    char str2[WORD_LENGTH];
    get_key(s1, str1);
    get_key(s2, str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2)
    {
        return 0;
    }

    int count[256] = {0}; // Assuming ASCII characters

    // Count the frequency of characters in the first string
    for (int i = 0; i < len1; i++)
    {
        count[(int)str1[i]]++;
    }

    // Decrease the frequency of characters in the second string
    // If a character is encountered with a frequency of 0, the strings are not anagrams
    for (int i = 0; i < len2; i++)
    {
        count[(int)str2[i]]--;
        if (count[(int)str2[i]] < 0)
        {
            return 0;
        }
    }
    // If the frequencies of all characters are 0, the strings are anagrams
    return 1;
}

void searchAnagrams(Graph_Node **hashTable, char *word, int m, FILE *outputFile)
{
    int index = hash(word, m);
    Graph_Node *currentNode = hashTable[index];

    while (currentNode != NULL)
    {
        if (strcmp(word, currentNode->word) == 0 && areAnagrams(word, currentNode->word))
        {
            fprintf(outputFile, "%s ", currentNode->word);
        }
        if (strcmp(word, currentNode->word) != 0 && areAnagrams(word, currentNode->word))
        {
            fprintf(outputFile, "%s ", currentNode->word);
        }
        currentNode = currentNode->next;
    }
    fprintf(outputFile, "\n");
}

void FreeHashTable(Graph_Node **hashTable, int e)
{
    for (int i = 0; i < e; i++)
    {
        Graph_Node *current = hashTable[i];
        while (current != NULL)
        {
            Graph_Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hashTable);
}

int main(int argc, char *argv[])
{
    FILE *wordfile, *queryfile, *out;
    wordfile = fopen(argv[1], "r");
    queryfile = fopen(argv[3], "r");
    int e = atoi(argv[2]);

    out = fopen("anagrams.txt", "w");
    if (out == NULL)
    {
        printf("Error opening  output files!\n");
        return 1;
    }
    if (wordfile == NULL)
    {
        printf("Error opening  word files!\n");
        return 1;
    }
    if (queryfile == NULL)
    {
        printf("Error opening  query files!\n");
        return 1;
    }

    Graph_Node **hashTable = (Graph_Node **)malloc(e * sizeof(Graph_Node *));
    for (int i = 0; i < e; i++)
    {
        hashTable[i] = NULL;
    }

    char word[WORD_LENGTH];
    while (fgets(word, WORD_LENGTH, wordfile) != NULL)
    {
        removeNewline(word);
        insertWord(hashTable, word, e);
    }

    char query[WORD_LENGTH];
    while (fgets(query, WORD_LENGTH, queryfile) != NULL)
    {
        removeNewline(query);
        searchAnagrams(hashTable, query, e, out);
    }

    fclose(wordfile);
    fclose(queryfile);
    fclose(out);

    FreeHashTable(hashTable, e);
    return 0;
}
