#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    
    char str[30] = "     push 5    ";
    char *token;
    int len = 0;
    char *delim = " \n\t";
    
    len = strlen(str);
    printf("%d\n", len);
    printf("%s", str);
    //token = malloc(sizeof(char *) * len);
    printf("%d\n", len);
    token = strtok(str, delim);
    while (token != NULL)
    {
	    printf("%s\n", token);
	    sleep(5);
	    token = strtok(NULL, delim);
    }
    //printf("%d\n", len);
    //printf("%s\n", token);

    return 0;
}
