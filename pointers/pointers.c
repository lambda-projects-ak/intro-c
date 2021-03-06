#include <stdio.h>
#include <string.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    int current = 0;
    while (*y != '\0')
    {
        x[current] = *y;
        y++;
        current++;
    }

    x[current] = '\0';
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    while (*str != '\0')
    {
        if (*str == c)
        {
            return str;
        }
        str++;
    }
    return NULL;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
int string_length(char *s)
{
    int counter = 0;
    while (*s != '\0')
    {
        counter++;
        s++;
    }
    return counter;
}

char *find_string(char *haystack, char *needle)
{
    int length = string_length(needle);

    // look while until match is found or end of haystack
    while (*haystack != '\0')
    {
        if (*haystack == needle[0])
        {
            char *startingIndex = haystack;

            for (int i = 0; i < 2; i++)
            {
                if (startingIndex[i] != needle[i])
                {
                    return NULL;
                }
            }
            printf("%s\n", startingIndex);
            return startingIndex;
        }
        // if letter match not found, increment
        haystack++;
    }
    // if no match is found
    return NULL;
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    // char buffer[1024];

    // string_copy(buffer, "Hello!");
    // printf("%s\n", buffer); // Prints "Hello!"

    return 0;
}
#endif
