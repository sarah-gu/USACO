//
//  test.cpp
//  
//
//  Created by Sarah Gu on 1/28/19.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int field[100000];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    cin >> N;
    
    for(int x = 0; x < N; x++)
    {
        int f1, f2;
        cin >> f1 >> f2;
        field[f1] +=1;
        field[f2] +=1;
    }
    sort(field, field+N, greater<int>());
    // solve();
    cout << field[0] + 1; 
    return 0;
}

