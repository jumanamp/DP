#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <limits>

using namespace std;

int cal_min_coins_recurse(const vector<int>& coin_list, const int& val) {
    int min_coins = std::numeric_limits<int>::max();
    for(auto const& coin: coin_list) {
        cout << "coin: " << coin << endl;
        int diff = val - coin ;
        if(diff < 0) {
            return std::numeric_limits<int>::max();
        }
        if(diff == 0){
            return 1;
        }
        if(diff > 0) {
            min_coins = min( min_coins, 1 + cal_min_coins_recurse(coin_list, diff)) ;
            cout << "min_coins: " << min_coins << endl;
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
    cout << "Minimum number of coins: " << min_coins << endl;
    return 0;
}


