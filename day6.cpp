/*
Given an array of integers, return a new array such that each element at index i of the new array is 
the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24].
 If our input was [3, 2, 1], the expected output would be [2, 3, 6].


Follow-up: what if you can't use division?
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> solution1(vector<int> arr){
    int prod = 1;
    for (int i=0;i<arr.size();i++){
        if (arr[i] == 0){

            int curr_prod = prod;
            for (int j=i+1;j<arr.size();j++){
                curr_prod *= arr[j];
            }
            for (int j=0;j<arr.size();j++){
                if (i==j){
                    arr[j]=curr_prod;
                }
                else
                arr[j]=0;
        }
        return arr;
    }
        prod *= arr[i];
    }
    for (int i = 0; i < arr.size(); i++){
        if(arr[i] != 0)
        arr[i] = prod/arr[i];
        else
        arr[i] = prod;
    }
    return arr;
}

vector<int> solution2(vector<int> arr){
    vector<int> arrl;
    vector<int> arrr;
    int prodl = 1;
    int prodr = 1;
    int size = arr.size();

    for (int i=0;i<arr.size();i++) {
        arrl.push_back(prodl);
        arrr.push_back (prodr);
        prodl *= arr[i];
        prodr *= arr[size-1-i];
    }

    for (int i=0;i<arr.size();i++) {
        arr[i] = arrl[i] * arrr [size-1-i];
    }

    return arr;

}

int main(){


    // Test case 1: [1, 2, 3, 4, 5] -> [120, 60, 40, 30, 24]
    vector<int> arr1 = {1, 2, 3, 4, 5,0};
    vector<int> result1 = solution2(arr1);
    
    cout << "Test 1:" << endl;
    cout << "Input: [1, 2, 3, 4, 5,0]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;
    
    // Test case 2: [3, 2, 1] -> [2, 3, 6]
    vector<int> arr2 = {3, 2, 1};
    vector<int> result2 = solution2(arr2);
    
    cout << "Test 2:" << endl;
    cout << "Input: [3, 2, 1]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}