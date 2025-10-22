#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *s;

    s = malloc(50 * sizeof(char));

    strcpy(s, "Engenheiro muito em breve");
    
    int i = 0;
    while(s[i] != '\0')
    {
        printf("%c ", s[i]);
        i++;
    }

    free(s);
    
    return 0;
}