//
//  p1.cpp
//  
//
//  Created by Sarah Gu on 1/20/19.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
pair<int,int> swaps[100];
int guess[100];
int numRight(int cups[3])
{
    int count = 0;
    for(int x = 0; x < N; x++)
    {
        pair<int,int> p= swaps[x];
        int c1 = p.first-1;
        int c2 = p.second-1;
        int temp = cups[c1];
        cups[c1] = cups[c2];
        cups[c2] = temp;
        //cout << cups[c1] << " " << cups[c2] << endl;
      //  cout << guess[x] << endl;
        if(cups[guess[x]-1] == 1)
        {
         //   cout << "HI" << endl;
            count +=1;
        }
    }
    return count;
}
void solve()
{
    //assume started under 1
    int cups[3] = {1,0,0};
    //cout << cups[0];
    int try1 = numRight(cups);
    int cup2[3] = {0,1,0};
    int try2 = numRight(cup2);
    int cup3[3] = {0,0,1};
    int try3 = numRight(cup3);
    //cout << try1 << " " << try2 << " " << try3 <<endl;
    int max1 = max(try1, try2);

    cout << max(try3,max1);
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    cin >> N;
   // cout << "{HI" << endl;
    for(int x = 0; x < N; x++)
    {
        int s1, s2;
        cin >> s1 >> s2;
        swaps[x] = make_pair(s1, s2);
        int g;
        cin >> g;
        guess[x] = g;
        //cout << guess[x];
    }
    solve();
    return 0;
}

