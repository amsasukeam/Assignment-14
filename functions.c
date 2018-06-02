#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int reach[1001]; // This vector is a representation of the current node and if this node was allready visited.
int counter; // This variable will be used to counter how many pieces were used in the sort
int orientation[1001][1001]; // A matrix that retain the orientations between the nodes of the graph.
int adiacency_source[1001]; // Vector that retain if the source node allready appeared in the sort
int adiacency_destination[1001]; // Vector that retain if the destination node allready appeared in the sort

void orientations( int orientation [][1001] , int i , int n ){ //Function that reads and makes the graph orientated.

    int source;
    int destination;

    srand(time(NULL));

    while( i <= n){

         source = rand()%1000 + 1;
         destination = rand()%1000 + 1;

         while( adiacency_source[source] == 1 ) // Randomly generate another source node if the generated one allready appeared in the sort
               source = rand()%1000 + 1;
        adiacency_source[source] = 1;

         while(adiacency_destination[destination] == 1 ) // Randomly generate another destination node if the generated one allready appeared in the sort
               destination = rand()%1000 + 1;
         adiacency_destination[destination] = 1;

         orientation[source][destination] = 1; // Assign the orientation if it respects the conditions above
         i++;
        }
}


void depth_first_search(int source){ // This function will do the tropological sort of the graph.
     int destination;
     int i;
     reach[source]=1;

     for(i = 1;i <= 1000; i++)
         if(orientation[source][i] && !reach[i]){

            printf("\n %d->%d",source,i); //Printing the corect order of the game
            counter++; // This counter is used to retain how many nodes were used in the printed sort.
            depth_first_search(i);
            }
}
