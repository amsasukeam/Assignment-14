#include <stdio.h>
#include <stdlib.h>
int orientation[1001][1001];
int counter;
#include "functions.h"



int main()
{
    int source;
    int destination;

    orientations(orientation, 1, 1000);
    depth_first_search(rand()%1000+1);

    printf("\n %d ", counter);

    return 0;
}
