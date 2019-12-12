//hi

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    freopen("fenceplan.in", "w", stdout);
    int N = 10000;
    int M = 10000-1;
    cout << N << " " << M << endl;
    int count = 0;
    for(int x = 0; x < N; x++)
    {
        cout << count << " " << count << endl;
        count +=1;
    }
    count = 1;
    for(int y = 0; y < M; y++)
    {
        cout << count << " " << count+1 << endl;
        count +=1;
    }

    
}

