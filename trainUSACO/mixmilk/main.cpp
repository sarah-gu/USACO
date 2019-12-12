/*
 ID: guwen881
 PROG: milk
 LANG: C++
 */
//  main.cpp
//  Format
//
//  Created by Sarah Gu on 12/9/18.
//  Copyright © 2018 Sarah Gu. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
pair<int,int> farmers[5000];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);

    cin >> N >> M;

    for(int x = 0; x < M; x++)
    {
        int price, amount;
        cin >> price >> amount;
        farmers[x] = make_pair(price, amount);
    }
   // cout << " HELLO " << endl;
    sort(farmers, farmers+M);
   // cout << " HELLO " << endl;
    int milkLeft = N;
    int idx = 0;
    int cost = 0;
    while(milkLeft > 0)
    {
        pair<int,int> curFarm = farmers[idx];
        //cout << curFarm.second << endl;
        if(curFarm.second - milkLeft > 0)
        {
            cost += milkLeft*curFarm.first;
            milkLeft = 0;
        }
        else{
            cost += curFarm.first* curFarm.second;
            milkLeft -= curFarm.second;
            idx += 1;
        }
     //   cout << cost << endl;
    }
    cout << cost << endl;
    return 0;
    
}

