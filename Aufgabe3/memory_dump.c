#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *string;

/**
 * Finds the amount of substrings within the string.
 *
 * @param s: The string within heap.
 * @param c: A pointer to the first char in the string.
 * @param first_found: A pointer to the reference of the first occurence of c within s.
 *
 */
size_t findString(string s, string c, char **first_found)
{
    char *p = strstr(s, c);
    first_found = &p;
    int i = 0;
    while (p != NULL)
    {
        string sub = p + (strlen(c) - 1);
        p = strstr(sub, c);
        i++;
    }
    return i;
}

/**
 *
 */
void memdump(string s)
{
    printf("\n");
    printf("%-20s\n", "ADDR");
    char *p = s;
    while (strlen(p) > 1)
    {
        printf("%-#10x %-.16s\n", &p, p);
        if (strlen(p) >= 16)
        {
            p += 16;
        }
        else if (strlen(p) < 16 && strlen(p) > 1)
        {
            p += strlen(p);
        }
    }
    printf("\n");
}

/**
 *
 * @param arc: Anzahl der Argumente
 * @param argv: Zeiger auf die Argumente
 */
int main(int argc, char **argv)
{
    // Step 1: Calculating the size of string and substring.
    // Step 2: Allocating memory for the string and substring with malloc.
    // Step 3: Copy string and substring to the heap.
    if (argc != 3)
    {
        return 1;
    }
    size_t stringSize = strlen(argv[1]) + 1;
    size_t substringSize = strlen(argv[2]) + 1;
    string mstring = (string)malloc(stringSize);
    string sstring = (string)malloc(substringSize);
    if (mstring == NULL || sstring == NULL)
    {
        return 2;
    }
    strcpy(mstring, argv[1]);
    strcpy(sstring, argv[2]);
    printf("Laenge der Zeichenkette (inkl. Nullterminierung): %d Byte(s)\n", stringSize);
    printf("Suchkriterium: %s\n", sstring);
    memdump(mstring);
    char **first_found;
    int count = findString(mstring, sstring, first_found);
    printf("Die Suchzeichenkette wurde %u mal gefunden.\nZuerst in Adresse %#010x\n", count, first_found);
}