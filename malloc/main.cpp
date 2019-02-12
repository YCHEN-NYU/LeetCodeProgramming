#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main() {
    /* char malloc
    int i, n;
    char * buffer;

    printf("how long do you want the string");
    scanf("%d", &i);
    buffer = (char *) malloc(i + 1);
    if(buffer == NULL) exit(1);

    for(n = 0; n < i; n++){
        buffer[n] = rand() % 1000 + 'a';
    }   buffer[i] = '\n';

    printf("Random string: %s\n", buffer);
    free(buffer);
    */

    /*
    int N = 10;
    int * numbers= (int *) malloc((N + 1)*sizeof(int));
    for(int j = 0; j < N; j++){
        numbers[j] = j;
    }   numbers[N] = INT_MAX;

    for(int j = 0; j < N; j++){
        printf("%d \t", numbers[j]);
    }
    free(numbers);
     */


    // float malloc
     int N = 10;
     float * arr;
     arr = (float *) malloc(sizeof(float)*(N + 1));
     for (int i = 0; i < N; i++){
         arr[i] = i*i;
     }  arr[N] = '\n';

     for (int i = 0; i < N; i++){
         std::cout << * (arr + i)<< '\t';
     }

     free (arr);
    return 0;
}