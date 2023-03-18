#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

void binaryInsertionSort(double arr[], int n) {
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

void get_mas(int arr[], int n, string filename) {
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

void show_mas(int arr[], int n, string filename) {
    ofstream out(filename);
    for (int i = 0; i < n; i++) {
        out << arr[i] << " ";
    }
    
}

void task1() {

        int n=0;
      int* a = new int[n];
      get_mas(a, n, "array_in_n.txt");
    int i2;
    for (int i = (n / 2) * 2 - 1; i >= 0; i -= 2) {
        ++n;
        for (i2 = n - 1; i2 > i; --i2) a[i2] = a[i2 - 1];
    }
    show_mas(a, n, "array_out_n.txt");
    delete a;
}
void task2() {

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
            break; // Завдання 2

        }
    } while (menu);



    system("pause");
    return 0;
}