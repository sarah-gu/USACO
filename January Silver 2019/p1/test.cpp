//
//  test.cpp
//  
//
//  Created by Sarah Gu on 1/28/19.
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
void solve()
{
    int count = 0;
    for(int x = 0; x < N; x++)
    {
        Mountain comp1 = m[x];
        bool check = true;
        for(int y = 0; y < N; y++)
        {
            Mountain comp2 = m[y];
            if(comp1.x2 <= comp2.x3 && comp1.x2 >= comp2.x2 && x!=y && comp1.y1 < comp2.y1 && comp1.x3 <= comp2.x3 && comp1.x3 >= comp2.x2 )
            {
               // cout << comp1.x2 << " " << comp1.x3 << " " << comp2.x2 << " " << comp2.x3 << endl;
                check = false;
                break;
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
    freopen("mountains.out", "w", stdout);
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
