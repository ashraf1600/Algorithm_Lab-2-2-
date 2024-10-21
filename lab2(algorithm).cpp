#include<bits/stdc++.h>
using namespace std;
// Bubble sort function to sort the vector in descending order
void bubble_sort(vector<int>& v, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] < v[j + 1]) {  // Compare v[j] with v[j+1] for descending order
                swap(v[j], v[j + 1]);
            }
        }
    }
}

// Binary search function to find the occurrences of 'k'
void bin_search(vector<int>& v, int n, int k)
{
    int leftm = -1, rightm = -1;
    int st = 0, it = n - 1;

    // Finding the rightmost occurrence of 'k'
    while (st <= it)
		{
        int mid = st + (it - st) / 2;
        if (k == v[mid])
        {
            rightm = mid;  // Update rightmost match
            st = mid + 1;  // Continue searching on the right side
        }
	else if (v[mid] > k)
        {
            it = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }

    // Reset search bounds to find the leftmost occurrence of 'k'
    st = 0, it = n - 1;

    // Finding the leftmost occurrence of 'k'
    while (st <= it)
		{
        int mid = st + (it - st) / 2;
        if (k == v[mid]) {
            leftm = mid;  // Update leftmost match
            it = mid - 1; // Continue searching on the left side
        } else if (v[mid] > k) {
            it = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    if (rightm == -1 && leftm == -1) {
        cout << "Not Found" << endl;
    } else {
        cout << rightm - leftm + 1 << endl;  // Print the count of occurrences
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    bubble_sort(v, n);  // Sort the array in descending order
    int key;
    cin >> key;

    bin_search(v, n, key);  // Find occurrences of 'key'

    return 0;
}
