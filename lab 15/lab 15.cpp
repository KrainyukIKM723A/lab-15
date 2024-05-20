#include <iostream> 


using namespace std;



void transformArray(double arr[], int size) {

    int low = 0, high = size - 1;

    while (low < high) {

        while (arr[low] <= 1 && low < high) {

            ++low;

        }

        while (arr[high] > 1 && low < high) {

            --high;

        }

        if (low < high) {

            swap(arr[low], arr[high]);

            ++low;

            --high;

        }

    }

}



void bubbleSort(double arr[], int n) {

    for (int i = 0; i < n - 1; ++i) {

        for (int j = 0; j < n - i - 1; ++j) {

            if (arr[j] > arr[j + 1]) {

                swap(arr[j], arr[j + 1]);

            }

        }

    }

}



void selectionSort(double arr[], int n) {

    for (int i = 0; i < n - 1; ++i) {

        int min_idx = i;

        for (int j = i + 1; j < n; ++j) {

            if (arr[j] < arr[min_idx]) {

                min_idx = j;

            }

        }

        swap(arr[i], arr[min_idx]);

    }

}



void insertionSort(double arr[], int n) {

    for (int i = 1; i < n; ++i) {

        double key = arr[i];

        int j = i - 1;

        while (j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j];

            --j;

        }

        arr[j + 1] = key;

    }

}



int partition(double arr[], int low, int high) {

    double pivot = arr[low];



    int count = 0;

    for (int i = low + 1; i <= high; i++) {

        if (arr[i] <= pivot)

            count++;

    }



    int pivotIndex = low + count;

    swap(arr[pivotIndex], arr[low]);

    int i = low, j = high;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {

            i++;

        }

        while (arr[j] > pivot) {

            j--;

        }

        if (i < pivotIndex && j > pivotIndex) {

            swap(arr[i++], arr[j--]);

        }

    }



    return pivotIndex;

}



void quickSort(double arr[], int low, int high) {

    if (low >= high)

        return;

    int p = partition(arr, low, high);



    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);

}



void printArray(double arr[], int size) {

    for (int i = 0; i < size; ++i) {

        cout << arr[i] << " ";

    }

    cout << endl;

}



int main() {

    double a[] = { 0.5, 1.7, 0.2, 3.4, 1.1, 0.9, 2.6, 0.8, 1.2, 4.5, 1.9, 3.2, 0.4, 2.3, 1.5, 2.9, 0.6, 3.8, 1.3, 2.1 };

    int size = sizeof(a) / sizeof(a[0]);



    cout << "Initial array: ";

    printArray(a, size);
    transformArray(a, size);



    cout << "Transformed Array: ";

    printArray(a, size);
    quickSort(a, 0, size - 1);


    cout << "Sorted Array: ";

    printArray(a, size);



    return 0;

}