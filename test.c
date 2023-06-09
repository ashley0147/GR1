#include <stdio.h>
#include <stdlib.h>

int main()
{
    if ((fptr = fopen("data/roadNet-CA.txt.gz", "rb")) == NULL)
    {
        printf("Error !opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    fseek(fptr, -sizeof(struct threeNum), SEEK_END);
    for (n = 1; n < 5; ++n)
    {
        fread(&num, sizeof(struct threeNum), 1, fptr);
        printf("n1 : % d\tn2: % d\tn3: % d\n", num.n1, num.n2, num.n3);
        fseek(fptr, -2 * sizeof(struct threeNum), SEEK_CUR);
    }

    fclose(fptr);

    return 0;
}