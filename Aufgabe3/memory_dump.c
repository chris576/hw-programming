#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *string;

/**
 * Finds the amount of substrings within the string.
 *
 * @param s: The string within heap.
  * @param first_found: A pointer to the reference of the first occurrence of c within s.
 *
 */
size_t findString(string s, string *first_found)
{
    string p = strstr(*first_found, s);
    *first_found = p;
    int i = 0;
    while (p != NULL)
    {
        string sub = p + (strlen(s));
        p = strstr(sub, s);
        i++;
    }
    return i;
}

/**
 *
 */
void memdump(string p, size_t length)
{
    printf("\n");
    //zeilen müssen an durch 16 teilbren adressen beginnen
    printf("%-20s\n", "ADDR");
    for (; *p; p++) 
    {
        if ((unsigned long)p % 16 == 0) 
        {
            printf("\n%p  ", p);
        }
        if (isprint(*p)) 
        {
            printf("%c", *p);
        }
        else 
        {
            printf("%c", '.');
        }
    }
    printf("\n\n");    
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
    string freeMe = mstring; //sicherheitkopie der reservierten adresse

    if (mstring == NULL || sstring == NULL)
    {
        return 2;
    }
    strcpy(mstring, argv[1]);
    strcpy(sstring, argv[2]);

    printf("Laenge der Zeichenkette (inkl. Nullterminierung): %d Byte(s)\n", stringSize);
    printf("Suchkriterium: %s\n", sstring);
    
    memdump(mstring, stringSize);
    int count = findString(sstring, &mstring);

    printf("Die Suchzeichenkette wurde %u mal gefunden.\nZuerst in Adresse %p\n", count, mstring);
    
    free(freeMe);
    free(sstring);
}
