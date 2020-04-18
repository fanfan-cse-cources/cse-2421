/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

#include <stdlib.h>
#include <stdio.h>

struct ThreeD_values
{
    unsigned long z;
    int x;
    int y;
};

void multlong(int a, int b, struct ThreeD_values *values);

int main(int argc, char **argv)
{
    long x, y;
    unsigned long z;

    int limit, i;
    FILE *results;
    struct ThreeD_values *values;

    if (argc != 4)
    {
        printf("Usage: %s <val1> <val2> <val3>\n", argv[0]);
        return 0;
    }

    x = atol(argv[1]);
    y = atol(argv[2]);

    /* set limit to # of structures we need in array given x and y  */
    limit = (2 * x + 1) * (2 * y + 1);

    /* malloc space for structure array */
    values = calloc(limit, sizeof(struct ThreeD_values));

    multlong(x, y, values);

    results = fopen(argv[3], "w");
    for(i = 0; i < limit; i++)
    {
        /* print x, y, z values in each structure */
        fprintf(results, "%i %i %lu \n", values -> x, values -> y, values -> z);
        values++;
    }
    if(fclose(results) != 0)
    {
        perror("flose error");
        exit(EXIT_FAILURE);
    }

    values -= limit;

    free(values);
    values = NULL;

    return 0;
}
