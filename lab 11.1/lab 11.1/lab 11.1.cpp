// lab 11.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <iomanip>
using namespace std;

void create(char* FileName, int N, int min, int max)
{
    ofstream f(FileName, ios::binary);
    if (!f)
    {
        cerr << "file did not opened" << endl;
        exit(1);
    }

    int a;
    double test = 0;
    for (int i = 0; i < N; i++)
    {
        a = min + rand() % (max - min + 1);
        f.write((char*)&a, sizeof(int));
    }
    cout << endl;
}
double averageOdd(char* FileName)
{
    ifstream f(FileName, ios::binary);
    if (!f)
    {
        cerr << "file did not opened" << endl;
        exit(1);
    }
    int a, l = 0;
    double avgOdd = 0;
    while (f.read((char*)&a, sizeof(int)))
    {

        if (a % 2 ==! 0)
        {
            ++l;
            avgOdd += a;
        }
    }
    avgOdd = (avgOdd * 1.0) / l;
    return avgOdd;
}

double averageEven(char* FileName)
{
    ifstream f(FileName, ios::binary);
    if (!f)
    {
        cerr << "file did not opened" << endl;
        exit(1);
    }
    int a, l = 0;
    double avgEven = 0;
    while (f.read((char*)&a, sizeof(int)))
    {
        ++l;
        if (a & 2 == 0)
            avgEven += a;
    }
    avgEven = (avgEven * 1.0) / l;
    return avgEven;
}
void print(char* FileName)
{
    ifstream f(FileName, ios::binary);
    if (!f)
    {
        cerr << "file did not opened" << endl;
        exit(1);
    }
    int a;
    while (f.read((char*)&a, sizeof(int)))
        cout << a << "   ";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(NULL));
    int N, min, max, menu;
    double avgOdd, avgEven;
    char FileName[] = "t.txt";
    cout << "Select a menu item" << endl;
    do {
        cout << endl;
        cout << "[0] - Write the numbers in a binary file: " << endl;
        cout << "[1] - Download binary file and output arithmetic mean of positive and negative" << endl;
        cout << "[2] - Download numbers from a binary file and display" << endl;
        cout << "[other] - Exit the program" << endl;
        cout << "Menu item:"; cin >> menu;
        switch (menu)
        {
        case 0:
            cout << endl;
            cout << "Enter the number of numbers: "; cin >> N;
            cout << "Enter the minimum value:"; cin >> min;
            cout << "Enter the maximum value:"; cin >> max;
            create(FileName, N, min, max);
            break;
        case 1:
            cout << endl;
            cout << "Arithmetic mean negative: " << averageOdd(FileName) << endl;
            cout << "Positive arithmetic mean:" << averageEven(FileName) << endl;
            break;
        case 2:
            print(FileName);
        default:
            break;
        }
    } while (menu == 0 || menu == 1 || menu == 2);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
