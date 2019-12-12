/*
 ID: guwen881
 PROG: combo
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
int N;
int f1,f2,f3,m1,m2,m3;
bool check(int x, int y, int z)
{
    if((f1-2+50)%50<= x && (f1+2 +50)%50 >=x && (f2-2 + 50)%50 <= y && (f2+2 + 50)%50 >=y&& (f3-2 + 50)%50 <= z && (f3+2 + 50)%50>=z)
        return true;
    if(m1-2 <= x && m1+2 >=x && m2-2 <= y && m2+2 >=y&& m3-2 <= z && m3+2 >=z)
        return true;
    return false;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
    cin >> N >> f1 >> f2>> f3>> m1 >> m2 >> m3;
    int count = 0;
    for(int x = 1; x <= N; x++)
    {
        for(int y = 1; y <= N; y++)
        {
            for(int z = 1; z <= N; z++)
            {
                if(check(x,y,z))
                    count += 1;
            }
        }
    }
    cout << count << endl;
    return 0;
}
