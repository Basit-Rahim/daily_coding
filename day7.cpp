/*
Given an array of numbers of length N, find both the minimum and maximum using less than 2 * (N - 2) comparisons.

[a,b,c,d...]

[a,b,c,d,e,f,g,h,i]

mins [a/2]
max = [a/2]


n-1, 
*/
#include <iostream>
using namespace std;

pair<int,int> min_max(int* arr, int n) {
    if (n == 0) return {0, 0};

    int global_min, global_max;
    int start;

    // If N is odd, initialize with first element
    if (n % 2 == 1) {
        global_min = arr[0];
        global_max = arr[0];
        start = 1;
    } else {
        // Compare first two elements
        if (arr[0] < arr[1]) {
            global_min = arr[0];
            global_max = arr[1];
        } else {
            global_min = arr[1];
            global_max = arr[0];
        }
        start = 2;
    }

    // Process pairs
    for (int i = start; i < n; i += 2) {
        int local_min, local_max;

        // One comparison per pair
        if (arr[i] < arr[i + 1]) {
            local_min = arr[i];
            local_max = arr[i + 1];
        } else {
            local_min = arr[i + 1];
            local_max = arr[i];
        }

        // Compare against global min/max (2 comparisons)
        if (local_min < global_min) global_min = local_min;
        if (local_max > global_max) global_max = local_max;
    }

    return {global_min, global_max};
}

int main() {
    int arr[] = {4, 1, 9, -2, 7};
    int n = 5;

    auto result = min_max(arr, n);

    cout << "Min: " << result.first << "\n";
    cout << "Max: " << result.second << "\n";
}
