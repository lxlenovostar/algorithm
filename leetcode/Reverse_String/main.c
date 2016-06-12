/*
 * 344:Reverse String
 */
#include <stdio.h>
#include <stdlib.h>

char* reverseString(char* s) {
    int i; 
    int length = 0;
    char tmp;
    char *result;

    for (i = 0; *(s+i) != '\0'; i++)
        length++;

    result = (char*)malloc(sizeof(char)*(length + 1));

    for (i = 0; i < length; i++) {
        *(result + i) = *(s + length - 1 - i);
    }

    *(result + length) = '\0';
    
    return result;
}

int main()
{
    char *s = "hello";
    char * result = reverseString(s);
    printf("%s\n", result);
    free(result);
}
