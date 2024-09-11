/**
 * @file transit-card.cpp
 * @author Bob Lowe (rlowe8@utm.edu)
 * @brief My solution to https://open.kattis.com/problems/transitcard
 * @version 0.1
 * @date 2024-09-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int price(vector<int> &p, vector<int> &d, int n);


int main() 
{
    int l;              // number of price levels
    vector<int> p;      // prices
    vector<int> d;      // days for which price is in effect
    int t;              // number of days for which we need a transit card
    int n;              // Number of trips home
    vector <int> a;     // Start of trip interval
    vector <int> b;     // End of trip interval

    // read in pricing details
    cin >> l;
    for(int i=0; i<l; i++) {
        int x;
        cin >> x;
        p.push_back(x);
    }
    
    for(int i=0; i<l-1; i++) {
        int x;
        cin >> x;
        d.push_back(x);
    }

    // get the time and trip count
    cin >> t >> n;

    // get the trip intervals
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        a.push_back(x);
        cin >> x;
        b.push_back(x);
    }

    // compute the price
    cout << price(p, d, t) << endl;
}

int price(vector<int> &p, vector<int> &d, int n) 
{
    auto ditr = d.begin();
    auto pitr = p.begin();
    int pdays;
    int price = 0;
    while(n) {
        if(ditr == d.end()) {
            pdays = n;
        } else {
            pdays = min(n, *ditr);
            ditr++;
        }
        price += pdays * *pitr;
        pitr++;
        n -= pdays;
    }

    return price;
}