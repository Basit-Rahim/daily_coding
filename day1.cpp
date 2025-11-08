#include<iostream>
#include<ctime>
#include <random>

using namespace std;


mt19937 rng(random_device{}());
uniform_int_distribution<int> dist(1, 5);
bool toss_biased() {
    // returns 1 with probability 1/5 (20%), 0 with 4/5 (80%)
    int number = dist(rng);
    return number== 1;
}

/* 
Assume you have access to a function toss_biased() which returns 0 or 1 with a probability that's not 50-50 
(but also not 0-100 or 100-0). You do not know the bias of the coin.
Write a function to simulate an unbiased coin toss.
*/

// Lets creat some random method



// This is interesting technique, so when we get different result then the probability of getting first as 0 or second is 0.5 so, this will work when ever
// any one probabilty is not 0
bool toss_unbiased(){
    while (true){
        bool first = toss_biased();
        bool second = toss_biased();
        if (first!=second){
            return first;
        }
    }
}

int main(){
    float total_count_unbiased = 0.0;
    float total_count_biased = 0.0;
    for (int i=0;i<100000;i++){
        bool un_bias = toss_unbiased();
        bool biased = toss_biased();

        if (un_bias){
            total_count_unbiased+=1;
        }
        if (biased){
            total_count_biased+=1;
        }
        
    }
    cout<<"Probabilty un_Biased method avg of 100k tosses: "<<total_count_unbiased/100000.0<<"\n";
    cout<<"Probabilty Biased method avg of 100k tosses: "<<total_count_biased/100000.0<<"\n";
    return 0;
}