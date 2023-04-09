int N=3;
double summ_main=0;
double summ_sub=0;
void main()
{
    double mass[N][N];
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            printf("введите значения для строки  %d столбца %d \n", i+1, j+1);
            scanf("%d", &mass[i][j]);
            if (i==j){
                summ_main+=mass[i][j];
            }   
        }
        summ_sub+= mass[i][N-i-1];
    }
    printf("сумма основной диоганали %d \n", summ_main);
    printf("сумма побочной диоганали %d", summ_sub);

}
