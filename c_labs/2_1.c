int N=3; //объявил переменную(статичнут)
double summ_main=0;//объявил переменную (динамическую)
double summ_sub=0;
void main()
{
    double mass[N][N]; // объявил двумерный массив(матрицу) // так как в первой строке я указал, что N=3
    for (int i=0; i<N; i++){ //'for' параметрический цикл (цикл с заданным числом повторений);i=0 объявил переменную; i<N условие по которому закончится цикл; I++ действие выполняющееся после каждой итерации
        for (int j=0; j<N; j++){
            printf("введите значения для строки  %d столбца %d \n", i+1, j+1); // %d потому, что вывожу целочисленные значение
            scanf("%d", &mass[i][j]); // получаем с командной строки целочисленное значение и сохраняем его в текущую строку и столбец массива
            if (i==j){  //если номер столбца равен номеру строки
                summ_main+=mass[i][j]; //увеличиваем сумму по основной диагонале
            }   
        }
        summ_sub+= mass[i][N-i-1]; // после заполнения всей строки, получаем значение из текущей строки по столбцу индекс которого противоположен индксу текущей строки
    }
    printf("сумма основной диоганали %d \n", summ_main);
    printf("сумма побочной диоганали %d", summ_sub);

}//
