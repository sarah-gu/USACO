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
int mat[1001][1001];
int N, K;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    cin >> N >> K;
    int maxX = 0;
    int maxY = 0;
    for(int x = 0; x < N; x++)
    {
        int llx, lly, urx, ury;
        cin >> llx >> lly >> urx >> ury;
        if(urx > maxX)
            maxX = urx;
        if(ury > maxY)
            maxY = ury;
        for(int r = llx; r <urx; r++)
        {
            for(int c = lly; c < ury; c++)
            {
                mat[r][c] += 1;
            }
        }
    }
    int count = 0;
   /* for(int z = 0; z < 9; z++)
    {
        for(int b = 0; b < 9; b++)
        {
            cout << mat[z][b] << " ";
        }
        cout << endl;
    } */
    for(int rr = 0; rr < maxX; rr++)
    {
        for(int cc = 0; cc < maxY; cc++)
        {
            if(mat[rr][cc] == K)
                count +=1;
        }
    }
    cout << count;
    return 0;
}
