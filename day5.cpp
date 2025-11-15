#include<iostream>
#include<vector>

using namespace std;


/*
Given a list of numbers and a number k,
 return whether any two numbers from the list add up to k.
*/

// brut force
bool solution(vector<int>& arr, int k){
    
    int length = arr.size();

    for (int i=0;i<length;i++){
        for (int j=i+1;j<length;j++){
            if ((arr[i]+arr[j]) == k) {
                return true;
            }
        }
    }
    return false;
    
}

int main(){
    vector <int> test = {1,2,3,4}   ;
    cout << "sum of two number in the array equal to 3: "<< solution(test,7)<<endl;
    return 0;
}