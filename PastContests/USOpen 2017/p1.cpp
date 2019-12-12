/*
 ID: guwen881
 PROG: friday
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
pair<int,int> cowArr[100000];
int N;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    cin >> N;
    for(int x = 0; x < N; x++)
    {
        int a, b;
        cin >> a >> b;
        cowArr[x] = make_pair(b,a);
    }
    sort(cowArr, cowArr+N);
    pair<int,int> lowCow, highCow;
    highCow = cowArr[N-1];
    lowCow = cowArr[0];
    int max =0, lC = 0, hC = N-1;
    while(lowCow.first < highCow.first)
    {
        lowCow.second -=1;
        highCow.second -=1;
        if(lowCow.second < 0)
        {
            lowCow = cowArr[++lC];
        }
        if(highCow.second < 0)
        {
            highCow = cowArr[--hC];
        }
        if(lowCow.first + highCow.first > max)
        {
            max = lowCow.first + highCow.first;
        }
    }
    cout << max;
    return 0;
}
