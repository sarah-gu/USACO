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
#include <cmath>
using namespace std;

struct Mountain
{
     double x1, y1, x2, y2, x3, y3;
};
Mountain m[100000];
int N;
float area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
bool collinear(double x1, double y1, double x2, double y2, double x3, double y3)
{
   // Putting all this together, the points (a,b), (m,n) and (x,y) are collinear if and only if
     //   (n−b)(x−m)=(y−n)(m−a)
    if((y2-y1) * (x3 - x2) == (y3 - y2) * (x2 - x1) && ((y2 < y1 && y2 > y3)|| (y2 > y1 && y2 < y3)))
        return true;
    return false;
}
/* A function to check whether point P(x, y) lies inside the triangle formed
 by A(x1, y1), B(x2, y2) and C(x3, y3) */
bool isInside(double x1, double y1, double x2, double y2, double x3, double y3, double x, double y)
{
    /* Calculate area of triangle ABC */
    float A = area (x1, y1, x2, y2, x3, y3);
    
    /* Calculate area of triangle PBC */
    float A1 = area (x, y, x2, y2, x3, y3);
    
    /* Calculate area of triangle PAC */
    float A2 = area (x1, y1, x, y, x3, y3);
    
    /* Calculate area of triangle PAB */
    float A3 = area (x1, y1, x2, y2, x, y);
    
    /* Check if sum of A1, A2 and A3 is same as A */
    // cout << x1 << " "<< y1 << " " << x << " " << y << endl;
   //  cout <<A << " " <<  A1 << " " << A2 << " " << A3 << endl;
    return (A == A1 + A2 + A3);
}
void solve()
{
    int count = 0;
    for(int i = 0; i < N; i++)
    {
        Mountain curMount = m[i];
        bool check = true;
        pair<double, double> peak = make_pair(curMount.x1, curMount.y1);
        for(int j = 0; j < N; j++)
        {
            if(peak.first != m[j].x1 || peak.second != m[j].y1)
            {
                Mountain cMount = m[j];
                if(isInside(cMount.x1, cMount.y1, cMount.x2, cMount.y2, cMount.x3, cMount.y3, peak.first, peak.second) && peak.second < cMount.y1)
                {
                    cout << cMount.x1 << " " << cMount.y1 << " " << peak.first << " " << peak.second << endl;
                    check = false;
                    break;
                }
               /* else if(collinear(cMount.x1, cMount.y1,  peak.first, peak.second,cMount.x2, cMount.y2))
                {
                    check = false;
                    break;
                }
                else if(collinear(cMount.x1, cMount.y1 , peak.first, peak.second, cMount.x3, cMount.y3))
                {
                    check = false;
                    break;
                } */
            }
        }
        if(check)
            count +=1;
    }
    cout << count;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("mountains.in", "r", stdin);
   // freopen("mountains.out", "w", stdout);
    cin >> N;
    for(int z = 0; z < N; z++)
    {
        double x,y;
        cin >> x >> y;
        m[z].x1 = x;
        m[z].y1 = y;
        m[z].x2 = x-y;
        m[z].y2 = 0;
        m[z].x3 = x+y;
        m[z].y3 = 0;

    }
    solve();
    return 0;
}
