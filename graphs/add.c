#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *ptr = NULL;
    ptr = fopen("Air_Quality_SPM_2007 (1).csv", "r");
    char str[1000000] , buff[1000000];
    fgets(buff , 1000000 , ptr);
    // {
        char* l1 = strtok(NULL , ",");
         printf("%sh\n",l1);
          char* l2 = strtok(buff , ",");
         printf("%s\n",l2);
          char* l3 = strtok(buff , ",");
         printf("%s\n",l3);
          char* l4 = strtok(buff , ",");
         printf("%s\n",l4);
          char* l5 = strtok(buff , ",");
         printf("%s\n",l5);
    // }
    return 0;
}