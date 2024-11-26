#include <bits/stdc++.h>
using namespace std;

// Partition function as per the video lectures
int partition(int arr[], int l, int r) {
    int pivot = arr[l];  // First element as pivot
    int i = l + 1;

    for (int j = l + 1; j <= r; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    // Place the pivot in its correct position
    swap(arr[l], arr[i - 1]);
    return i - 1;
}

// QuickSort function with comparison counting
int quickSort(int arr[], int l, int r) {
    if (l >= r) return 0;

    // Number of comparisons for this subarray
    int comparisons = r - l;

    // Partition and get pivot index
    int pivotIndex = partition(arr, l, r);

    // Recurse on left and right subarrays
    comparisons += quickSort(arr, l, pivotIndex - 1);
    comparisons += quickSort(arr, pivotIndex + 1, r);

    return comparisons;
}

int main() {
    const int arr_size = 10000;
    int arr[arr_size];

    // Read input from the file
    ifstream file("C:\\Users\\ashra\\Downloads\\QuickSort.txt");
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string str;
    int k = 0;
    while (getline(file, str)) {
        arr[k++] = stoi(str);
    }

    // Compute the total number of comparisons
    cout << quickSort(arr, 0, k - 1) << endl;

    return 0;
}
