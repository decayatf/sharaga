#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <string.h>


void freeMatrix(double** matrix, int n){
    for (int i = 0; i < n; i++){
        free(matrix[i]);
    }
    free(matrix);
}

double** createMatrix(int n) {
    double** matrix = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(n * sizeof(double));
    }
    return matrix;
}

double** matrixSum(double** matrix1, double** matrix2, int n) {
    double** result = createMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

double** matrixPow(double** matrix1, double** matrix2, int n) {
    double** result = createMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

void genMatrixToFile(int n, char* filename) { 
    FILE* file = fopen(filename, "w"); //открываем файл на запись (создаём файл) // w=запись w-полностью переписыват файл(создаёт заного)
    
    srand(time(NULL)); //устанавливаем начальную последовательность генератора на основе текущего времени srand - функция для установки начальной последовательности генератора time - функция которая возвращает текущее время null - нулевой указатель
    fprintf(file, "%d\n", n); //fprintf функция для записи в файл %d целочисленный тип данных n-размер матрицы

    // генирируем массив случайных чисел n на n с записью в файл
    // генирация первого масива
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double value = (double)rand() / RAND_MAX;  // случайное число от 0 до 1 типа double rand_max(предопределённая константа которая представляет собой максимальное значение функции RAND) - максимальное число которое возможно съгенирировать
            fprintf(file, "%lf ", value); // делаем запись в файле
        }
        fprintf(file, "\n"); // переносим строку в файле так, как мы рассматриваем новую строку в матрице
    }

    fprintf(file, "\n"); // разделяем массивы переносом строки

    // генирация второго массива
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double value = (double)rand() / RAND_MAX;
            fprintf(file, "%lf ", value);
        }
        fprintf(file, "\n");
    }

    fclose(file); // закрываем файл 
    // очистка массивов не нужна так как я не использую временное хранилище данных
}

int readMatrixFromFile(FILE* file, double*** matrix1, double*** matrix2) {//(функция принимает ссылку на  файл "FILE*"), и 2 ссылки на матрицы
    int n;  // объявляем переменную 'n' для хранения размерности матриц
    char buffer[100]; //определяем массив значений типа чар размерностью 100 для хранения символов из файла
    fgets(buffer, sizeof(buffer), file); // считываем 1 строку для получения размерности матриц
    sscanf(buffer, "%d", &n); //из буфера сохраняем  значения  в переменную @n@
   
    *matrix1 = (double**)malloc(n * sizeof(double*)); // резервируем место под строки в матрицы
    *matrix2 = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) { //обходим кол-во строк
        (*matrix1)[i] = (double*)malloc(n * sizeof(double)); //резервирум место под элементы строк матрицы

        fgets(buffer, sizeof(buffer), file); //считываем строку файла
        char* numbers = strtok(buffer, " "); //разбиваем строку по пробелам и получаем первый элемент
        for (int j = 0; j < n; j++) { //
            (*matrix1)[i][j] = strtod(numbers, NULL); //преобразовываем значения в дабл
            numbers = strtok(NULL, " "); //берём следующее значение стоки
        }
    }

    fgets(buffer, sizeof(buffer), file); //пропускаем пустую стоку

    //считывает значения для второй матрицы
    for (int i = 0; i < n; i++) {
        (*matrix2)[i] = (double*)malloc(n * sizeof(double));

        fgets(buffer, sizeof(buffer), file);
        char* numbers = strtok(buffer, " ");
        for (int j = 0; j < n; j++) {
            (*matrix2)[i][j] =strtod(numbers, NULL);
            numbers = strtok(NULL, " ");
        }
    }
    //возвращаем размерность матрицы
    return n;
}

void writeResultToFile(double** summ, double** product, int n){
    FILE* file = fopen("output.txt", "w");
    fprintf(file, "сумма матриц: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(file, "%lf ", summ[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "произведение матриц: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(file, "%lf ", product[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}


int main() {
    clock_t start_time, end_time;
    double dif_time;

    int n;
    printf("Введите размер матрицы: ");
    scanf("%d", &n); 
    // Взаимодействие с пользователем не должно отражаться на время  работы программы
    start_time = clock(); // фиксируем текущее время

    // Генерация случайных матриц и запись их в файл
    genMatrixToFile(n, "input.txt");

    // Чтение матриц из файла
    FILE* file = fopen("input.txt", "r");
   
   //определяем переменные динамического размера
    double** matrix1; 
    double** matrix2;

    n = readMatrixFromFile(file, &matrix1, &matrix2);
    fclose(file);

    // Вычисление суммы и произведения матриц
    double** sum = matrixSum(matrix1, matrix2, n);
    double** product = matrixPow(matrix1, matrix2, n);

    writeResultToFile(sum, product, n);
    // Освобождение памяти
    freeMatrix(matrix1, n);
    freeMatrix(matrix2, n);
    freeMatrix(sum, n);
    freeMatrix(product, n);

    end_time = clock();
    dif_time = difftime(end_time, start_time) / CLOCKS_PER_SEC;
    printf("время выполнения команды: %.6f секунд", dif_time);
    return 0;
}