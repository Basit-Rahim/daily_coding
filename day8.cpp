/*
There are n points on a number line (a straight line).
All the point positions (their coordinates) are integers.

A grasshopper starts at the leftmost point (the smallest coordinate).
The goal is to reach the rightmost point (largest coordinate).

The grasshopper must follow these rules:

✔️ Rule 1 — All jumps must be the SAME length

If the grasshopper chooses a jump length 
𝐿
L,
then every jump must be exactly 
𝐿
L units long.

✔️ Rule 2 — The grasshopper must land exactly on one of the given points

• It cannot land in between points.
• It can only land on points from the provided list.

✔️ Rule 3 — Grasshopper can make at most 
𝑘
k jumps
❗ Goal

Find the minimum jump length 
𝐿
L such that the grasshopper can:

start at the first (leftmost) point,

make jumps of length 
𝐿
L,

land only on the given points,

reach the last (rightmost) point,

using no more than 
𝑘
k jumps.

And output that minimum length.



*/

#include<iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    int k;
    cout << "Please enter number of points on number line : ";
    cin>>n;
    cout << "\nPlease enter number maximum number of jumps  : ";
    cin>>k;
    int arr [n];
    for (int i=0;i<n;i++){
        cout << "\nPlease enter element number "<<(i+1)<<": ";
        cin>>arr[i];

    }
    int min_jump = int(float(n)/float(k) + 0.5);
    
    for (int i=min_jump;i<n;i++){
        if(((n-1)%i)==0){
            cout<<"The jump size is: "<<i<<endl;
            break;
        }
    }

}