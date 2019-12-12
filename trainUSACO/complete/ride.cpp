/*
 ID: guwen881
 PROG: ride
 LANG: C++
 */
//  main.cpp
//  trainUFO
//
//  Created by Sarah Gu on 9/18/18.
//  Copyright © 2018 Sarah Gu. All rights reserved.


#include <iostream>
#include <fstream>
#include <map>
using namespace std;
void readFile(string filename, string arr[2])
{
    ifstream infile;
    infile.open("ride.in");
    int c = 0;
    string line;
    while( getline(infile, line))
    {
        arr[c] = line;
        c += 1;
    }


}
int main(int argc, const char * argv[]) {
    // insert code here...
    string input[2];
    readFile("ride.in", input);
    map<char, int> alphabet;
    string ref = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < ref.length(); i++)
    {
        alphabet[ref[i]] = i+1;
    }
    int counter = 1;

    for (int x = 0; x < input[0].length(); x++)
    {
        counter *= alphabet[input[0][x]];
        cout << alphabet[input[0][x]] << " ";
    }
    int c2 = 1;
    for (int y = 0; y < input[1].length(); y++)
    {
        c2 *= alphabet[input[1][y]];
    }
    cout << counter << " " <<  c2 << endl;
    ofstream outfile;
    outfile.open("ride.out");
    if (outfile.fail())
    {
        cout << "K" << endl;
    }
    if (counter%47 == c2%47)
    {
        outfile << "GO" << endl;;
    }
    else
    {
        outfile << "STAY"<< endl;;
    }
    return 0;
}
