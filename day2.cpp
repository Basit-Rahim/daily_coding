#include<iostream>
#include<vector>
#include<cmath> //Ceil
#include <numeric> // gcd
using namespace std;
/*
The ancient Egyptians used to express fractions as a sum of several terms 
where each numerator is one.For example, 4 / 13 can be represented as 
1 / 4 + 1 / 18 + 1 / 468.

Create an algorithm to turn an ordinary fraction a / b,
 where a < b, into an Egyptian fraction.
*/

/*
thoughts:

*/

void solution(int a, int b) {

    vector<int> denominators;
    while (a != 0) {
        int n = ceil((double)b / a);
        denominators.push_back(n);

        a = a * n - b;
        b = b * n;
        int g = std::gcd(abs(a), abs(b)); // <-- use abs() here
        a /= g;
        b /= g;
    }

    cout << "Egyptian Fraction representation: ";
    for (size_t i = 0; i < denominators.size(); ++i) {
        cout << "1/" << denominators[i];
        if (i != denominators.size() - 1) cout << " + ";
    }
    cout << endl;
}

int main(){
    int a = 4, b = 13;
    solution(a, b);
    return 0;
}