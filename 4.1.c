#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <stdbool.h>

/**
* @brief считывает значение введённое с клавиатуры, с проверкой ввода
* @return число 
*/
const long int get_sizearray(void);

/**
* @brief проверяет корректно ли выделена память под массив
* @param arr - проверяемый массив
*/
void check_pointer(const int* arr);

/**
* @brief считывает значение введённое с клавиатуры, с проверкой ввода
* @return число
*/
int get_int(void);

/**
* @brief проверяет промежуток на корректность
* @param min - нижняя граница промежутка
* @param max - верхняя граница промежутка
*/
void check_min_max(const int min, const int max);

/**
* @brief заполняет массив элементами, которые задаёт пользователь
* @param arr - массив, который будет заполнен
* @param rows - размер массива
* @param min - нижняя граница промежутка, в котором будут заданы числа
* @param max - верхняя граница промежутка, в котором будут заданы числа
*/
void get_manual(int* arr, const size_t rows, const int min, const int max);

/**
* @brief заполняет массив случайными элементами
* @param arr - массив, который будет заполнен
* @param rows - размер массива
* @param min - нижняя граница промежутка, в котором будут заданы числа
* @param max - верхняя граница промежутка, в котором будут заданы числа
*/
void get_random(int* arr, const size_t rows, const int min, const int max);

/**
* @brief проверяет, лежит ли число в заданном промежутке
* @param input - число
* @param min - нижняя граница промежутка, в котором будут заданы числа
* @param max - верхняя граница промежутка, в котором будут заданы числа
*/
void check_int(const int input, const int min, const int max);

/**
* @brief выводит массив на экран
* @param arr - массив, который будет выведен
* @param rows - размер массива
*/
void print_arr(const int* arr, const size_t rows);

/**
* @brief копирует массив
* @param arr - массив, который будет скопирован
* @param rows - размер массива
* @return скопированный массив
*/
int* get_copyarray(const int* arr, const size_t rows);

/**
* @brief изменяет массив согласно условию №1 и выводит его на экран
* @param arr - массив
* @param rows - размер массива
* @return изменённый массив
*/
void def_task_one(int* arr, const size_t rows);

/**
* @brief изменяет массив согласно условию №2 и выводит его на экран
* @param arr - массив
* @param rows - размер массива
*/
void def_task_two(const int* arr, const size_t rows);

/**
* @brief изменяет массив согласно условию №3 и выводит его на экран
* @param arr - массив
* @param rows - размер массива
*/
void def_task_three(int* arr, const size_t rows);

/**
* @brief ищет максимальный элемент массива среди отрицательных.
* @param arr - массив
* @param rows - размер массива
* @return минимально возможный элемент среди отрицательных, либо 1, если отрицательных элементов в массиве нету.
*/
const int max_in_minus(const int* arr, const size_t rows);

/**
* @param CHOISE_ONE - выбор ручного заполнения
* @param CHOISE_TWO - выбор заполнения случайными числами
* @param TASK_ONE - выбор выполнения 1 задания
* @param TASK_TWO - выбор выполнения 2 задания
* @param TASK_THREE - выбор выполнения 3 задания
*/
enum { CHOISE_ONE = 1, CHOISE_TWO, TASK_ONE = 1, TASK_TWO, TASK_THREE };

/**
* @brief точка входа в программу
* @return 0 или 1 в зависимости от корректности выполнения
*/
int main(void)
{
    system("chcp 1251");

    printf("Введите количество строк массива: ");
    size_t rows = (size_t)get_sizearray();

    int* main_array = (int*)calloc(rows, sizeof(int));
    check_pointer(main_array);

    printf("Введите минимальное возможное число в массиве: ");
    const int min = get_int();
    printf("Введите максимальное возможное число в массиве: ");
    const int max = get_int();
    check_min_max(min, max);

    printf("\nМассив из %zu строк будет заполнен числами в диапазоне [%d;%d]\n\n", rows, min, max);

    printf("\nКак будет заполнен массив?\n%d - Ручное заполнение\n%d - Автоматическое заполнение\n", CHOISE_ONE, CHOISE_TWO);
    int fir

    switch (first_choise)
    {
    case CHOISE_ONE:
        get_manual(main_array, rows, min, max);
        break;

    case CHOISE_TWO:
        get_random(main_array, rows, min, max);
        break;

    default:
        fprintf(stderr, "Error 0\n");
        free(main_array);
        exit(1);
    }

    int* copy_array = get_copyarray(main_array, rows);
    check_pointer(copy_array);
    print_arr(copy_array, rows);

    printf("\nКакие будут преобразования?\n%d - Заменить второй элемент массива на максимальный среди отрицательных\n%d - Найти количество тех элементов, значения которых положительны и по модулю не превосходят заданное число А\n%d - Найти номер первой пары соседних элементов, сумма которых меньше заданного числа\n", TASK_ONE, TASK_TWO, TASK_THREE);
    int second_choise = get_int();

    switch (second_choise)
    {
    case TASK_ONE:
        def_task_one(copy_array, rows);
        break;

    case TASK_TWO:
        def_task_two(copy_array, rows);
        break;

    case TASK_THREE:
        def_task_three(copy_array, rows);
        break;

    default:
        fprintf(stderr, "Error 0\n");
        free(main_array);
        free(copy_array);
        exit(1);
    }

    free(main_array);
    free(copy_array);
    return 0;
}

const long int get_sizearray(void)
{
    long int output = 0;
    if (!scanf_s("%ld", &output))
    {
        fprintf(stderr, "Error 1\n");
        exit(1);
    }
    if (output < 1)
    {
        fprintf(stderr, "Error 2\n");
        exit(1);
    }

    return output;
}

void check_pointer(const int* arr)
{
    if (arr == NULL)
    {
        fprintf(stderr, "Error 3\n");
        exit(1);
    }
}

int get_int(void)
{
    int output = 0;
    if (!scanf_s("%d", &output))
    {
        fprintf(stderr, "Error 4\n");
        exit(1);
    }
    return output;
}

void check_min_max(const int min, const int max)
{
    if (min >= max)
    {
        fprintf(stderr, "Error 5\n");
        exit(1);
    }
}

void get_manual(int* arr, const size_t rows, const int min, const int max)
{
    check_pointer(arr);

    for (size_t i = 0; i < rows; i++)
    {
        printf("\narr[%zu] = ", i);
        arr[i] = get_int();
        check_int(arr[i], min, max);
    }
}

void get_random(int* arr, const size_t rows, const int min, const int max)
{
    check_pointer(arr);
    srand(time(NULL));

    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void check_int(const int input, const int min, const int max)
{
    if (input<min || input>max)
    {
        fprintf(stderr, "Error 6\n");
        exit(1);
    }
}

void print_arr(const int* arr, const size_t rows)
{
    check_pointer(arr);

    printf("Массив: \n");
    for (size_t i = 0; i < rows; i++)
    {
        printf("%5d\n", arr[i]);
    }
}

int* get_copyarray(const int* arr, const size_t rows)
{
    check_pointer(arr);

    int* copyarr = (int*)calloc(rows, sizeof(int));
    check_pointer(copyarr);

    for (size_t i = 0; i < rows; i++)
    {
        copyarr[i] = arr[i];
    }

    return copyarr;
}

void def_task_one(int* arr, const size_t rows)
{
    check_pointer(arr);

    const int number = max_in_minus(arr, rows);
    

    if (number == 1)
    {
        printf("\nОтрицательных элементов в массиве нету, он не будет изменён");
    }
    else
    {
        for (size_t i = 0; i < rows; i++)
        {
            if (i == 1)
            {
                arr[i] = number;
                break;
            }
        }
        printf("\n");
        print_arr(arr, rows);
    }

}

void def_task_two(const int* arr, const size_t rows)
{
    check_pointer(arr);

    printf("\nЗадайте число A ");
    const int A = get_int();

    int count = 0;
    for (size_t i = 0; i < rows; i++)
    {
        if (arr[i] > 0 && arr[i] <= A) 
        {
            count++;
        }
    }

    printf("\nКоличество чисел, значения которых положительны и по модулю не превосходят заданное число А: %d", count);
}

void def_task_three(int* arr, const size_t rows)
{
    check_pointer(arr);st_choise = get_int();



    switch (first_choise)
    {
    case CHOISE_ONE:
        get_manual(main_array, rows, min, max);
        break;

    case CHOISE_TWO:
        get_random(main_array, rows, min, max);
        break;

    default:
        fprintf(stderr, "Error 0\n");
        free(main_array);
        exit(1);
    }

    int* copy_array = get_copyarray(main_array, rows);
    check_pointer(copy_array);
    print_arr(copy_array, rows);

    printf("\nКакие будут преобразования?\n%d - Заменить второй элемент массива на максимальный среди отрицательных\n%d - Найти количество тех элементов, значения которых положительны и по модулю не превосходят заданное число А\n%d - Найти номер первой пары соседних элементов, сумма которых меньше заданного числа\n", TASK_ONE, TASK_TWO, TASK_THREE);
    int second_choise = get_int();

    switch (second_choise)
    {
    case TASK_ONE:
        def_task_one(copy_array, rows);
        break;

    case TASK_TWO:
        def_task_two(copy_array, rows);
        break;

    case TASK_THREE:
        def_task_three(copy_array, rows);
        break;

    default:
        fprintf(stderr, "Error 0\n");
        free(main_array);
        free(copy_array);
        exit(1);
    }

    free(main_array);
    free(copy_array);
    return 0;
}

const long int get_sizearray(void)
{
    long int output = 0;
    if (!scanf_s("%ld", &output))
    {
        fprintf(stderr, "Error 1\n");
        exit(1);
    }
    if (output < 1)
    {
        fprintf(stderr, "Error 2\n");
        exit(1);
    }

    return output;
}

void check_pointer(const int* arr)
{
    if (arr == NULL)
    {
        fprintf(stderr, "Error 3\n");
        exit(1);
    }
}

int get_int(void)
{
    int output = 0;
    if (!scanf_s("%d", &output))
    {
        fprintf(stderr, "Error 4\n");
        exit(1);
    }
    return output;
}

void check_min_max(const int min, const int max)
{
    if (min >= max)
    {
        fprintf(stderr, "Error 5\n");
        exit(1);
    }
}

void get_manual(int* arr, const size_t rows, const int min, const int max)
{
    check_pointer(arr);

    for (size_t i = 0; i < rows; i++)
    {
        printf("\narr[%zu] = ", i);
        arr[i] = get_int();
        check_int(arr[i], min, max);
    }
}

void get_random(int* arr, const size_t rows, const int min, const int max)
{
    check_pointer(arr);
    srand(time(NULL));

    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void check_int(const int input, const int min, const int max)
{
    if (input<min || input>max)
    {
        fprintf(stderr, "Error 6\n");
        exit(1);
    }
}

void print_arr(const int* arr, const size_t rows)
{
    check_pointer(arr);

    printf("Массив: \n");
    for (size_t i = 0; i < rows; i++)
    {
        printf("%5d\n", arr[i]);
    }
}

int* get_copyarray(const int* arr, const size_t rows)
{
    check_pointer(arr);

    int* copyarr = (int*)calloc(rows, sizeof(int));
    check_pointer(copyarr);

    for (size_t i = 0; i < rows; i++)
    {
        copyarr[i] = arr[i];
    }

    return copyarr;
}

void def_task_one(int* arr, const size_t rows)
{
    check_pointer(arr);

    const int number = max_in_minus(arr, rows);
    

    if (number == 1)
    {
        printf("\nОтрицательных элементов в массиве нету, он не будет изменён");
    }
    else
    {
        for (size_t i = 0; i < rows; i++)
        {
            if (i == 1)
            {
                arr[i] = number;
                break;
            }
        }
        printf("\n");
        print_arr(arr, rows);
    }

}

void def_task_two(const int* arr, const size_t rows)
{
    check_pointer(arr);

    printf("\nЗадайте число A ");
    const int A = get_int();

    int count = 0;
    for (size_t i = 0; i < rows; i++)
    {
        if (arr[i] > 0 && arr[i] <= A) 
        {
            count++;
        }
    }

    printf("\nКоличество чисел, значения которых положительны и по модулю не превосходят заданное число А: %d", count);
}

void def_task_three(int* arr, const size_t rows)
{
    check_pointer(arr);


    printf("\nЗадайте число A ");
    const int A = get_int();

    size_t idx1 = 0;
    size_t idx2 = 0;
    for (size_t i = 0; i < rows-1; i++)
    {
        if (arr[i]+arr[i+1]<A)
        {
            idx1 = i;
            idx2 = i+1;
        }
    }
    printf("\nИндексы первой пары соседних элементов, сумма которых меньше заданного числа: %zu, %zu", idx1,idx2);
}

const int max_in_minus(const int* arr, const size_t rows)
{
    check_pointer(arr);

    int maxx = 0;
    bool check = 0;
    for (size_t i = 0; i < rows; i++)
    {
        if (arr[i] < 0)
        {
            check = 1;
            maxx = arr[i];
            break;
        }
    }

    if (check == 0)
    {
        return 1;
    }
 
    for (size_t i = 0; i < rows; i++)
    {
        if (arr[i] < 0 && arr[i]>maxx)
        {
            maxx = arr[i];
        }
    }

    return maxx;
}
