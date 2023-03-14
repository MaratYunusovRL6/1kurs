#include <iostream>
#include "res.h"
#include <functional>
#include <string>
#include<time.h>

int main() {
    int s = 100;
    float timer=0;
    float check[6]{0,0,0,0,0,0};//массив-кармашек, для сохранения последней строчки,
    // чтобы потом проверять превысит ли время сортировки 20 секунд
    void (*fnctn[6])(int *, int) ={bubbleSort,countSort,mergeSort,
                                   quickSort, insertSort, gnomeSort};//массив указателей на функцию, упрощает программу
    FILE *f;
    f = fopen("result.txt", "w");
    fprintf(f, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
            "size","bubbleSort" ,"countSort","mergeSort","quickSort", "insertSort", "gnomeSort");// создание названия
            // столбцов для таблицы
    while (s <= 10000000) {
        fprintf(f, "%d\t", s);//
        int *arr = new int[s];
        for (int h = 0; h<6; h++) {// создание массива с определенным размером и рандомными значениями
            if(check[h]<=20) {
                for (int q = 0; q < s; q++) {
                    arr[q] = rand();
                }
                clock_t start = clock();
                fnctn[h](arr, s);
                clock_t end = clock();
                timer = (float)(end - start) / CLOCKS_PER_SEC;//подсчет времени через такты процессора
                check[h]=timer;
                fprintf(f, "%f\t", timer);// запись времени в строчку, через табуляцию
            }
        }
        fprintf(f, "\n");//переход на новую строку
        s = s + s / 6;
        delete[] arr;
    }
    fclose(f);
    return 0;
}
