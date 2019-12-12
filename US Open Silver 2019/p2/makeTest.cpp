//hi

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    freopen("cowjump.in", "w", stdout);
    cout << 100000 << endl;
    int xC=1000000000-1, yC=1000000000-1;
    for(int x = 1; x < 100000 ; x++)
    {
        cout << xC << " " << yC << " " << xC - 1 << " " << yC << endl;
        if(x == 1000)
        {
            cout << 0 << " " << 0 << " " << 1000000000 << " " << 1000000000 << endl;
        }
        xC -= 1;
        yC -= 1;
    }
    
}
