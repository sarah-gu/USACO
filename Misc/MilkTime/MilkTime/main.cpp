/*
 ID: guwen881
 PROG: milk2
 LANG: C++
 */
//  main.cpp
//  MilkTime
//
//  Created by Sarah Gu on 12/29/18.
//  Copyright © 2018 Sarah Gu. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
void solve(pair<int,int> * arr, int N)
{
    int longestCont = arr[0].second - arr[0].first, longestIdle = 0, prevEnd = arr[0].second, prevStart = arr[0].first;
    for(int t = 1; t < N; t++)
    {
        if(arr[t].first > prevEnd)
        {
            if(prevEnd - prevStart > longestCont)
                longestCont = prevEnd - prevStart;
            
            if(arr[t].first - prevEnd > longestIdle)
            {
                //cout << arr[t].first << " " << prevEnd  << endl;
                longestIdle = arr[t].first - prevEnd;
            }
            if(arr[t].second > prevEnd)
                prevEnd = arr[t].second;
            
            prevStart = arr[t].first;
        }
        if(arr[t].first <= prevEnd)
        {
            if(arr[t].second > prevEnd)
                prevEnd = arr[t].second;
        }
    }
    cout << longestCont << " " << longestIdle << endl;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    int N;
    cin >> N;
    pair<int,int> arr[N];
    for(int x = 0; x  <N; x++)
    {
        int t1,t2;
        cin >> t1 >> t2;
        arr[x] = make_pair(t1,t2);
    }
    int n = (int)sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    solve(arr, N);
    return 0;
}
