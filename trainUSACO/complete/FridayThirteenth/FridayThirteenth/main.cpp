/*
ID: guwen881
PROG: friday
LANG: C++
 */
//  main.cpp
//  FridayThirteenth
//
//  Created by Sarah Gu on 12/23/18.
//  Copyright © 2018 Sarah Gu. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
void solve(int n)
{
    //cout << N;
    int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int toRet[7] = {0,0,0,0,0,0,0};
    int dayofWeek = 2;
    for(int x = 0; x < n;x++)
    {
      //  cout << x << endl;
        if((1900 + x)%4 == 0 && (1900+x)%100 !=0 )
        {
            months[1] = 29;
        }
        else if((1900+x)%100 == 0 && (1900+x)%400 == 0)
        {
            months[1] = 29;
        }
        for(int size = 0; size < 12; size++)
        {
            for(int d = 0; d < months[size]; d++)
            {
                if(d == 12)
                    toRet[dayofWeek] +=1;
                dayofWeek +=1;
                dayofWeek = dayofWeek%7;
              //.  cout << dayofWeek << endl;
            }
        }
        months[1] = 28;
        
    }
    for(int p = 0; p < 6; p++)
    {
        cout << toRet[p] << " ";
    }
    cout << toRet[6] << endl;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    int N;
    cin>>N;
    //cout << N << endl;
    solve(N);
    return 0;
}
