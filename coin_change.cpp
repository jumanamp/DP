#include <cstdio>
#include <vector>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <limits>

using namespace std;

// Using dynamic programming tabulation technique
// Tabulation takes bottom down approach, filling all values before requested
// value. Thta means you fill in an array from 0 to value one by one.
// Complexity is O(value*coin_list_size)
// Note always in DP, there are two loops, one to find solution for all values, 
// each value solution needs iteration through all possibilities

int cal_min_coins_dp(const vector<int>& coin_list, const int& val) {
    
    vector<int> coin_change(val+1, std::numeric_limits<int>::max());
    coin_change[0] = 0;
    
    for(int i=1; i<=val; i++) {
        for(auto const& coin: coin_list) {
            int min_val = std::numeric_limits<int>::max();
            int diff = i - coin ;
            if (diff >= 0) {
               min_val =  coin_change[diff] + 1;
            }
            coin_change[i] = min(coin_change[i], min_val);
        }
    }
    return coin_change[val];
}

// Recursive Solution, calling same function over and over on subproblem
// Complexity is exponential size as recrusion forms tree. In this problem,
// tree has number of children equal to coin list size. 
int cal_min_coins_recurse(const vector<int>& coin_list, const int& val) {
    int min_coins = std::numeric_limits<int>::max();
    for(auto const& coin: coin_list) {
        int diff = val - coin ;
        if(diff < 0) {
            return std::numeric_limits<int>::max()-1;
        }
        if(diff == 0){
            return 1;
        }
        if(diff > 0) {
            min_coins =  min(min_coins, 1 + cal_min_coins_recurse(coin_list, diff)) ;
        }
    }
    return min_coins;
}

int main()
{
    vector<int> coin_list;
    int val;
    
    // Parse coin list line
    string coins;
    getline(cin, coins);
    stringstream stream(coins);
    int coin;
    while(stream >> coin) {
        coin_list.push_back(coin);
    }
    
    string value;
    getline(cin, value);
    val = stoi(value);
    int min_coins = cal_min_coins_recurse(coin_list, val);
    cout << "Minimum number of coins, Recursion: " << min_coins << endl;
    min_coins = cal_min_coins_dp(coin_list, val);
    cout << "Minimum number of coins, DP: " << min_coins << endl;
    return 0;
}


