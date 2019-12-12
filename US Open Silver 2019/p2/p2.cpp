
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
struct Point {
    int x,y;
};
pair<Point, Point> lines[100000];
int N;

bool onLine(pair<Point, Point> line1, Point p) {
    if(p.x <= max(line1.first.x, line1.second.x) && p.x <= min(line1.first.x, line1.second.x) &&
       (p.y <= max(line1.first.y, line1.second.y) && p.y <= min(line1.first.y, line1.second.y)))
        return true;
    return false;
}
int orient(Point a, Point b, Point c) {
    int val = (b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
    if (val == 0)
        return 0;
    else if(val < 0)
        return 2;
    return 1;
}
bool intersection(pair<Point,Point> line1, pair<Point, Point> line2) {
    int dir1 = orient(line1.first, line1.second, line2.first);
    int dir2 = orient(line1.first, line1.second, line2.second);
    int dir3 = orient(line2.first, line2.second, line1.first);
    int dir4 = orient(line2.first, line2.second, line1.second);
    
    if ((dir1 != dir2 && dir3 != dir4) || (dir1==0 && onLine(line1, line2.first)) ||(dir2==0 && onLine(line1, line2.second)) ||(dir3==0 && onLine(line2, line1.first)) ||(dir4==0 && onLine(line2, line1.second)))
    {
        return true;
    }
                
/*
    if(dir1==0 && onLine(line1, line2.first))
        return true;
    if(dir2==0 && onLine(line1, line2.second))
        return true;
    if(dir3==0 && onLine(line2, line1.first))
        return true;
    if(dir4==0 && onLine(line2, line1.second))
        return true;
    */
    return false;
}

int main(int argc, const char * argv[]) {
    int timestart = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("cowjump.in", "r", stdin);
   // freopen("cowjump.out", "w", stdout);
    cin >> N;
    for(int x = 0; x < N; x++)
    {
        int p1,p2,p3,p4;
        cin >> p1 >> p2 >> p3 >>p4;
        Point po = {p1, p2};
        Point pt = {p3, p4};
        lines[x] = make_pair(po,pt);
      //  cout << po.x << " " << pt.x << endl;
    }
    int firstInt = 0;
    bool check = true;
    for(int t = 0; t < N; t++)
    {
        int curInters = 0;
        for(int s = 0; s < N; s++)
        {
            if(t != s)
            {
                if(intersection(lines[t], lines[s]))
                {
                    if(check)
                    {
                        firstInt = t;
                        check = false;
                    }
                  //  cout << lines[t].first.x << " " << lines[s].first.x << endl;
                    curInters += 1;
                    if(curInters > 1)
                    {
                        cout << t+1<< endl;
                        cout << ((double(clock()-timestart)/(double) CLOCKS_PER_SEC)) << endl;
                        exit(0);
                    }
                }
            }
        }
    }
    
    cout << ((double(clock()-timestart)/(double) CLOCKS_PER_SEC)) << endl;
    cout << firstInt << endl;
    return 0;
}
