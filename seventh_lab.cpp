#include <iostream>
#include <stdio.h>
#include <math.h>
#include <random>
using std::cin;
using std::swap;
using std::endl;


std::default_random_engine generator; // Объекты, генерирующие равномерно распределенные числа.
std::uniform_int_distribution<int> distribution(1,100); // Объекты, которые преобразуют последовательности чисел, сгенерированные генератором, в последовательности чисел, 
                                                        // которые соответствуют определенному распределению случайных величин.
void task(){
    // иницализация и заполнение матрицы случайными числами от 1 до 100
    int n[100][100]{}, sums[100]{};
    for (int i = 0; i < 100; i++){
        int sum = 0;
        for (int j = 0; j < 100; j++){
            n[i][j] = distribution(generator);
            sum += n[i][j];
        }
        sums[i] = sum;
    }
    // !ВЫВОД!
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            std::cout << n[i][j] << " ";
        }
        std::cout << " " << sums[i] << endl;
    }

    std::cout << "Sorted:" << endl;
    // Сортировка матрицы
    for (int i = 1; i < 100; i++){
        for (int j = i; j > 0 && sums[j-1] > sums[j]; j--){
            for (int k = 0; k < 100; k++){
                swap(n[j-1][k], n[j][k]);
            }
            swap(sums[j-1], sums[j]);
        }
    }
    // !ВЫВОД!
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            std::cout << n[i][j] << " ";
        }
        std::cout << " " << sums[i] << endl;
    }
}

int main(){
    // varian 7
    task();
}