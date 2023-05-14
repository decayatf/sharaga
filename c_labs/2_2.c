#include <stdio.h>
int N=2, j, k, i;
void main(){
    int mass[N][N];
    int mass_mul[N][N]; 
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            printf("введите значения для строки  %d столбца %d \n", i+1, j+1);
            scanf("%d", &mass[i][j]);
            mass_mul[i][j]=0;
        }
    }
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            for (k=0; k<N; k++){
                mass_mul[i][j]+=mass[i][k] * mass[k][j];
            }
            printf("%i ", mass_mul[i][j]);
        }
        printf("\n");
    }
}//