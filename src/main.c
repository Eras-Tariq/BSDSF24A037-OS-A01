#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main()
{
    printf("--- Testing String Functions ---\n");

    char str1[] = "Hello";
    char str2[] = "World";
    char copy[50];
    char copy2[50];
    char combined[100] = "Hello ";

    printf("mystrlen: %d\n", mystrlen(str1));

    mystrcpy(copy, str1);
    printf("mystrcpy: %s\n", copy);

    mystrncpy(copy2, str2, 3);
    printf("mystrncpy: %s\n", copy2);

    mystrcat(combined, str2);
    printf("mystrcat: %s\n", combined);


    printf("\n--- Testing File Functions ---\n");

    FILE* file = fopen("src/test.txt", "r");

    if (file == NULL)
    {
        printf("Could not open test.txt\n");
        return 1;
    }

    int lines, words, chars;

    if (wordCount(file, &lines, &words, &chars) == 0)
    {
        printf("Lines: %d\n", lines);
        printf("Words: %d\n", words);
        printf("Characters: %d\n", chars);
    }

    fclose(file);


    file = fopen("src/test.txt", "r");

    if (file == NULL)
    {
        printf("Could not open test.txt\n");
        return 1;
    }

    char** matches;
    int count = mygrep(file, "Linux", &matches);

    printf("mygrep matches: %d\n", count);

    for (int i = 0; i < count; i++)
    {
        printf("%s", matches[i]);
        free(matches[i]);
    }

    free(matches);
    fclose(file);

    return 0;
}
