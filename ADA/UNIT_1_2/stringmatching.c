#include <stdio.h>
#include <string.h>
int stringMatching(const char *text, const char *pattern)
{
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    for (int i = 0; i <= textLength - patternLength; i++)
    {
        int j;
        for (j = 0; j < patternLength; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == patternLength)
            return i;
    }
    return -1;
}
int main()
{
    char text[100];
    char pattern[100];
    printf("Enter the text: ");
    scanf("%[^\n]%*c", text); // Read the whole line including spaces
    printf("Enter the pattern to search: ");
    scanf("%[^\n]%*c", pattern); // Read the whole line including spaces
    int index = stringMatching(text, pattern);
    if (index != -1)
    {
        printf("Pattern found at index %d.\n", index);
    }
    else
    {
        printf("Pattern not found.\n");
    }

    return 0;
}
