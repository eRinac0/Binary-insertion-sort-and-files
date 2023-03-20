#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
const  int M = 20, N = 20;
void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        double x = arr[i];
        int j = i - 1;
        int low = 0, high = j;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (x > arr[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        while (j >= high + 1) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[high + 1] = x;
    }
}

void get_mas1(int arr[], int& n, string filename) {
    ifstream file(filename);
    file >> n;
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {
            file >> arr[i];
        }
        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}

void show_mas1(int arr[], int n, string filename) {
    ofstream out(filename);
    for (int i = 0; i < n; i++) {
        out << arr[i] << " ";
    }
    cout << endl;
}
void show_mas3(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}
void get_mas2(int matrix[M][N], int& n, int& m, string filename) {
    ifstream file(filename);
    file >> m;
    file >> n;
    if (file.is_open()) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
            {
                file >> matrix[i][j];
            }

        }
        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}


void get_mas3(int arr[], int& n, string filename) {
    ifstream file(filename);
    file >> n;
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {
            file >> arr[i];
        }
        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}

void task1() {
    int n = 0, n2 = 0;
    int* a = new int[n];
    int* res = new int[n];
    get_mas1(a, n, "array_in_n.txt"); // передаем поток ifstream вместо имени файла
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[i + 1])
            res[j++] = a[i];
    }
    show_mas1(res, n, "array_out_n.txt"); // передаем поток ofstream вместо имени файла
    delete[] a;
}

void task2() {

    int matrix[M][N]{};
    int s = 0, n = 0, m = 0;

    get_mas2(matrix, n, m, "matr_in_n.txt"); // передаем поток ifstream вместо имени файла
    ofstream out("matr_in_n.txt", ios::app);
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] < matrix[i][j - 1])
            {
                break;
            }
            else if (j == n - 1)
            {
                s++;
            }
        }
    }
    out << "\nNumber of lines ordered in ascending - " << s;
    out.close();
}

void task3() {

    int n = 0;
    int* arr = new int[n];
    get_mas3(arr, n, "task3.txt");
    cout << "Масив до сортування:" << endl;
    show_mas3(arr, n);
    binaryInsertionSort(arr, n);
    cout << "Масив після сортування:" << endl;
    show_mas3(arr, n);


}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int menu;
    do
    {
        cout << "Task number(0 for exit):";
        cin >> menu;
        switch (menu)
        { // перемикання між завданнями
        case 1:
            task1();
            break; // Завдання 1
        case 2:
            task2();
            break; // Завдання 2
        case 3:
            task3();
            break; // Завдання 3

        }
    } while (menu);



    system("pause");
    return 0;
}