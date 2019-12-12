//hi
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <unordered_set>
using namespace std;

int main(int argc, const char * argv[]) {
    freopen("leftout.in", "w", stdout);
    int N = 1000;
    cout << N << endl;
    for(int x = 0; x < N; x++)
    {
        string curString = "";
        for(int y = 0; y < N; y++)
        {
            int v1 = rand() % 100;
            if(v1 > 50)
                curString += 'R';
            else
                curString += 'L';
            
        }
        cout << curString << endl;
    }
}
