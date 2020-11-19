#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
int main(){
    int k; // Assume k is a given value.
    int total_generate_value = 0;
    int last_time_random_number = rand();
    int same_number_counter = 0;
    while(same_number_counter<k){
        total_generate_value++;
        int this_time_random_number = rand();
        if(this_time_random_number == last_time_random_number)
            same_number_counter++;
        last_time_random_number = this_time_random_number;
    }
}