#include<stdio.h>
#include<string.h>
char* reverse2(char* s)
{
    char* start = s;
    char* end = s+strlen(s)-1;
    while (start<end)
    {
        *start = *start ^ *end;
        *end = *start ^ *end;
        *start = *start ^ *end;
        start++;
        end--;
    }
    return s;
}

int main()
{
    char str[]="abcdefghijklmnopqrstuvwxyz";
    printf("%s\n", str);
//    printf("%s\n", reverse(str));
    printf("%s\n", reverse2(str));
    return 0;
}
