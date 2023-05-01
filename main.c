#include <stdio.h>
#include <stdlib.h>

int readFile(char *filename)
{
    int num;
    FILE *fptr;
    fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        printf("Cannot read file");
        return 0;
        exit(1);
    }
    char str[100];
    //read 2 lines
    for (int i = 0; i < 2; i++)
    {
        fgets(str, 100, fptr);
    }
    
    int f, t, nodes, edges;
    // read number of nodes and edges
    fscanf(fptr, "# %s %d %s %d", str, &nodes, str, &edges);
    printf("%d,%d", nodes, edges);

    for (int i = 0; i < edges; i++)
    {
        fscanf(fptr, "%d %d", &f, &t);
        printf("%d,%d", f, t)
    }
    fclose(fptr);
    return 1;
}
int main()
{

    readFile("roadNet-TX.txt");
    return 0;
}