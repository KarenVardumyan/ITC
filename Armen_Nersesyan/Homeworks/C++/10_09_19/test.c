#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.json"
void fillupjson(void);

int main()
{
    fillupjson();
    return 0;
}

void fillupjson(void)
{

    char *stringjson = "[";
    char *name = "";
    char *age = "";
    char *job = "";
    char bull = ' ';
    int count = 1;
    FILE * pFile;
    pFile = fopen ("data.json","w");
    for (int i = 1;; ++i)
    {
        printf("\t\tobject%i\t\n", count);
        printf("\"name\" : ");
        scanf("%s", &name);
        fprintf(pFile,"\n\t{\n\t\t\"name\":\"",name);
        printf("\"age\" : ");
        scanf("%s", &age);
        printf("\"job\" : ");
        scanf("%s", &job);
        printf("\t\t 0(break) else(countinue)\n");
        scanf("%s", &bull);
        if (bull == '0')
        {
            break;
        }
        count += 1;
        name = "";
        age = "";
        job = "";
    }
    fclose (pFile);
}