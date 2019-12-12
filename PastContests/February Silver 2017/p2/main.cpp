//
//  main.cpp
//  
//
//  Created by Sarah Gu on 1/30/19.
//
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int N, K,B;
int lights[100000];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    cin >> N >> K >> B;
    for(int z= 0; z < N; z++)
    {
        lights[z] = 1;
    }
    for(int x = 0; x < B; x++)
    {
        int idx;
        cin >> idx;
        lights[idx-1] = 0;
    }
    int bestcount = N;
    for(int ar = 0; ar < N-K+1; ar++)
    {
        int count = 0;
        //out << lights[ar]<< endl;
        if(lights[ar] != 0)
        {
            for(int c = ar; c < ar+K; c++)
            {
              //  cout << lights[c];
                if(lights[c] == 0)
                    count += 1;
            }
          //  cout <<endl;
         //   cout << count << endl;
            if(count < bestcount)
                bestcount = count;
        }
    }
    cout << bestcount;
    return 0;
}
