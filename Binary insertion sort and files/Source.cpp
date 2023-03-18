#include <iostream>
#include <fstream>

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

void readArrayFromFile(double arr[], int n, string filename) {
    ifstream file(filename);
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

void printArray(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int n = 7;
    double arr[n];
    readArrayFromFile(arr, n, "input.txt");
    cout << "Original array: ";
    printArray(arr, n);
    binaryInsertionSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}