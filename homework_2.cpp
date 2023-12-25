#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

/*task 3*/
void change(int *arr, int size) { //в функцию передаем массив по указателю, а также длину массива 
    for (int i = 0; i < size - 1; i += 2) { //увеличиваем на 2, так как проходимся сразу по четным (c 0) элементам массива и их соседними справа в каждой итерации цикла
        int tmp = arr[i]; //создаем временную вспомогательную переменную
        arr[i] = arr[i+1];
        arr[i+1] = tmp;
    }
}


/*task 4*/
void fill(int **arr, int rows, int cols) { //функция на вход принимает указатель на двумерный массив, число строк, число столбцов
    srand(time(0)); //используем  генератор случайных чисел
    for (int i = 0; i < rows; i++) { //заполняем строки и столбцы случайными числами
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 41 + 10; //генерируем число от 10 до 50 с помощью функции 
        }
    }
}

void print(int **arr, int rows, int cols) { //функция на вход принимает указатель на двумерный массив, число строк, число столбцов
    for (int i = 0; i < rows; i++) { //просто перебираем элементы по строкам и столбцам, чтобы вывести на экран
        for (int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


/*task 5*/
int add(int a, int b) { //сложение
    return a + b;
}

int diff(int a, int b) { //вычитание
    return a - b;
}

int multiply(int a, int b) { //умножение
    return a * b;
}

int divide(int a, int b) { //деление
    if (b != 0) {
        return a / b;
    } else {
        std::cout << "нельзя делить на ноль" << std::endl;
        return 0;
    }
} 



int main() {

    /*task 3*/
    int *array = new int[12]; //выделяем память для 12 элементов массива

    std::cout << "изначальный массив "; //массив заполняется с консоли
    for (int i = 0; i < 12; i++) {
        std::cin >> array[i];
    }
    
    change(array, 12); //вызываем функцию, которая меняет местами четные и нечетные элементы

    std::cout << "измененный массив "; //выводим получившийся массив
    for (int i = 0; i < 12; i++) {
        std::cout << array[i] << " ";
    }
    

    delete[] array; //освобождаем память


    /*task 4*/

    int rows = 0;
    int cols = 0;

    std::cout << "количество строк: ";
    std::cin >> rows;
    std::cout << "количество столбцов: ";
    std::cin >> cols;

    
    int **arr = new int*[rows]; //выделяем память под двумерный массив
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    fill(arr, rows, cols);  //вызываем функции
    print(arr, rows, cols); 

    for (int i = 0; i < rows; i++) { //освобождаем выделенную память по элементам строк, так как выделяли память изначально по элементам строк
        delete[] arr[i];
    }
    delete[] arr; //освобождаем выделенную для самого массива память 


    /*task 5*/

    int x = 0; 
    int y = 0; 
    char symbol; 
    int (*operation)(int, int) = 0; //создаем указатель на функцию

    do {
        std::cout << "Введите два числа; знак операции +, -, *, / или пробел для выхода: ";
        std::cin >> x >> y; 
        symbol = getchar(); // используем функцию getchar() для сохранения значения в переменной


        switch (symbol) { //в зависимости от введенного символа operation принимает значения разных функций
            case '+':
              operation = add;
              break;
            case '-':
                operation = diff;
                break;
            case '*':
                operation = multiply;
                break;
            case '/':
                operation = divide;
                break;
            default:
                if (symbol!=' ') //если symbol не равен ни одному из 5 символов, то выводится сообщение об ошибке и цикл снова продолжается
                 std::cout << "такой операции нет" << std::endl;
                 continue;
                    }
        std::cout << "Result: " << operation(x, y) << std::endl; //выводим на экран значение функции

    } 
    while (symbol != ' '); //цикл выполняется пока symbol не равен пробелу

    return 0;
}

