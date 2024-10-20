#include<bits/stdc++.h>
using namespace std;
// Partition function used in Quick Sort
int partition(vector<int>&v, int low, int high) {
    int pivot = v[low];
    int i = low, j = high;
    while (i < j) {
        // Find the element greater than the pivot
        while (i <= high - 1 && v[i] <= pivot) {
            i++;
        }
        // Find the element smaller than the pivot
        while (j >= low + 1 && v[j] >= pivot) {
            j--;
        }
        // Swap elements at i and j if i < j
        if (i < j) {
            swap(v[i], v[j]);
        }
    }
    // Swap pivot with element at j
    swap(v[low], v[j]);
    return j;
}

// Quick Sort function
void quick_sort(vector<int>&v, int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high);  // Get pivot index
        quick_sort(v, low, pi - 1);        // Sort left part
        quick_sort(v, pi + 1, high);       // Sort right part
    }
}

// Ternary Search function (iterative version)
int ternary_search(vector<int>&v, int low, int high, int key) {
    while (low <= high) {
        int mid1 = low + (high - low) / 3;       // First mid
        int mid2 = high - (high - low) / 3;      // Second mid

        if (v[mid1] == key) {                    // Key found at mid1
            return mid1;
        }
        if (v[mid2] == key) {                    // Key found at mid2
            return mid2;
        }
        if (key < v[mid1]) {                     // Search left part
            high = mid1 - 1;
        } else if (key > v[mid2]) {              // Search right part
            low = mid2 + 1;
        } else {                                 // Search middle part
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }
    return -1;  // If key not found
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Sort the array using Quick Sort
    quick_sort(v, 0, n - 1);

    // Optional: Print the sorted array
    cout << "Sorted array: ";
    for (auto u : v) {
        cout << u << " ";
    }
    cout << endl;

    int key;
    cout << "Enter the value to search: ";
    cin >> key;

    // Perform ternary search
    int index = ternary_search(v, 0, n - 1, key);

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}
