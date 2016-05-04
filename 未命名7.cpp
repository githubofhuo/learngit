#include<stdio.h> 
#include<string.h>
char* reverse2(char* s)
{
    char* start = s;
    char* end = s+strlen(s)-1;
    while (start<end)
    {
        *start = *start^*end;
        *end = *start^*end;
        *start = *start^*end;
        start++;
        end--;
    }
    return s;
}

int main()
{
	reverse2("hello");
	
	return 0;
}
