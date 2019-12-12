
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
bool operator<(const Point& t1, const Point& t2)
{
    return (t1.x < t2.x);
}
pair<Point, Point> lines[100000];
int N;
int timestart;
//map<pair<Point, Point>, int> allInt;
bool onLine(pair<Point, Point> line1, Point p) {
    if(p.x <= max(line1.first.x, line1.second.x) && p.x <= min(line1.first.x, line1.second.x) &&
       (p.y <= max(line1.first.y, line1.second.y) && p.y <= min(line1.first.y, line1.second.y)))
        return true;
    return false;
}
int orient(Point a, Point b, Point c) {
    long long val = (b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
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
    return false;
}
void checkManualInt(int idx1, int idx2)
{
  //  int intCount = 0;
    for(int x = 0; x < N; x++)
    {
        pair<Point,Point> curPoint = lines[x];
        if(x != idx1 && x != idx2)
        {
            if(intersection(lines[x], lines[idx1]))
            {
                cout << idx1+1 << endl;
                exit(0);
            }
         /*   if(intCount > 1)
            {
              //  cout << ((double(clock()-timestart)/(double) CLOCKS_PER_SEC)) << endl;
                
                exit(0);
            }*/
        }
    }
  //  intCount = 0;
    for(int y = 0; y < N; y++)
    {
        pair<Point,Point> curPoint = lines[y];
        if(y != idx2 && y != idx1)
        {
            if(intersection(lines[y], lines[idx2]))
            {
               cout << idx2+1 << endl;
                 exit(0);
            }
         /*   if(intCount > 1)
            {
              //  cout << ((double(clock()-timestart)/(double) CLOCKS_PER_SEC)) << endl;
                cout << idx2+1 << endl;
                exit(0);
            }*/
        }
    }
    cout << idx1+1 << endl;
    exit(0);
}
int main(int argc, const char * argv[]) {
    timestart = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("cowjump.in", "r", stdin);
    freopen("cowjump.out", "w", stdout);
    cin >> N;
    for(int x = 0; x < N; x++)
    {
        int p1,p2,p3,p4;
        cin >> p1 >> p2 >> p3 >>p4;
        Point po = {p1, p2};
        Point pt = {p3, p4};
        lines[x] = make_pair(po,pt);
        //pair<Point, Point> key = make_pair(po,pt);
      // allInt[key] = 0;
      //  cout << po.x << " " << pt.x << endl;
    }
    int firstInt = 0;
    bool check = true;
    for(int t = 0; t < N; t++)
    {
        int curInters = 0;
        for(int s = t+1; s < N; s++)
        {
            if(t != s)
            {
                if(intersection(lines[t], lines[s]))
                {
                    checkManualInt(t, s);

         /*           if(check)
                    {
                        firstInt = t;
                        check = false;
                    }
                  //  cout << lines[t].first.x << " " << lines[s].first.x << endl;
                    allInt[lines[t]] += 1;
                    allInt[lines[s]] += 1;
                    if(allInt[lines[t]]> 1)
                    {
                        cout << t+1<< endl;
                      //  cout << ((double(clock()-timestart)/(double) CLOCKS_PER_SEC)) << endl;
                        exit(0);
                    }
                    else if(allInt[lines[s]]> 1)
                    {
                        cout << s+1<< endl;
                     //   cout << ((double(clock()-timestart)/(double) CLOCKS_PER_SEC)) << endl;
                        exit(0);
                    }*/
                }
            }
        }
    }
   // cout << ((double(clock()-timestart)/(double) CLOCKS_PER_SEC)) << endl;
    cout << firstInt+1 << endl;
    return 0;
}
