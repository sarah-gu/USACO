/*
 ID: guwen881
 PROG: transform
 LANG: C++
 */
//  main.cpp
//  Transformations
//
//  Created by Sarah Gu on 12/30/18.
//  Copyright © 2018 Sarah Gu. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int areSame(int ** A, int **B, int N)
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (A[i][j] != B[i][j])
                return 0;
    return 1;
}
bool rotateMatrix180(int **arr, int ** fin, int N)
{
    int **mat;
    mat = new int *[N];
    for(int i = 0; i < N; i++)
    {
        mat[i] = new int[N];
    }
    int cR = 0, cC = 0;
    for(int r = N-1 ; r >= 0; r--)
    {
        cC = 0;
        for(int c = N-1; c >= 0; c--)
        {
            mat[cR][cC] = arr[r][c];
            cC += 1;
        }
        cR += 1;
    }
    if(areSame(mat,fin,N))
        return true;
    return false;
}
bool rotateMatrix90(int ** arr, int ** fin, int N)
{
    int **mat;
    mat = new int *[N];
    for(int i = 0; i < N; i++)
    {
        mat[i] = new int[N];
    }
    if(N%2 != 0)
    {
        mat[N/2][N/2] = arr[N/2][N/2];
    }
    for (int x = 0; x < N / 2; x++)
    {
        // Consider elements in group of 4 in
        // current square
        for (int y = x; y < N-x-1; y++)
        {
            int temp = arr[x][y];
            // move values from right to top
            mat[x][y] = arr[N-1-y][x];
            
            // move values from bottom to right
            mat[N-1-y][x] = arr[N-1-x][N-1-y];
            
            // move values from left to bottom
            mat[N-1-x][N-1-y] = arr[y][N-1-x];
            
            // assign temp to left
            mat[y][N-1-x] = temp;
        }
    }
//        for(int r = 0; r < N; r++)
//        {
//            for(int c = 0; c < N; c++)
//            {
//                cout << mat[r][c] << " ";
//            }
//            cout << endl;
     //   }
    if (areSame(fin, mat, N) == 1)
        return true;
    return false;
}

bool rotateMatrix270(int **arr, int **fin, int N)
{
    
    int **mat;
    mat = new int *[N];
    for(int i = 0; i < N; i++)
    {
        mat[i] = new int[N];
    }
    if(N%2 != 0)
    {
        mat[N/2][N/2] = arr[N/2][N/2];
    }
    for (int x = 0; x < N / 2; x++)
    {
        // Consider elements in group of 4 in
        // current square
        for (int y = x; y < N-x-1; y++)
        {
            int temp = arr[x][y];
            // move values from right to top
            mat[x][y] = arr[y][N-1-x];
            
            // move values from bottom to right
            mat[y][N-1-x] = arr[N-1-x][N-1-y];
            
            // move values from left to bottom
            mat[N-1-x][N-1-y] = arr[N-1-y][x];
            
            // assign temp to left
            mat[N-1-y][x] = temp;
        }
    }
//    for(int r = 0; r < N; r++)
//    {
//        for(int c = 0; c < N; c++)
//        {
//            cout << mat[r][c] << " ";
//        }
//        cout << endl;
//    }
    if (areSame(fin, mat, N) == 1)
        return true;
    return false;
}
bool reflect(int **arr, int **fin, int N)
{
    int **mat;
    mat = new int *[N];
    for(int i = 0; i < N; i++)
    {
        mat[i] = new int[N];
    }
    if(N%2 != 0)
    {
        for(int r = 0; r < N; r++)
        {
            mat[r][N/2] = arr[r][N/2];
        }
    }
    int cC = 0;
    for(int row = 0; row < N; row++)
    {
        cC = 0;
        for(int col = N-1; col >= 0; col--)
        {
            mat[row][cC] = arr[row][col];
            cC += 1;
        }
       
    }
//        for(int r = 0; r < N; r++)
//        {
//            for(int c = 0; c < N; c++)
//            {
//                cout << mat[r][c] << " ";
//            }
//            cout << endl;
//        }
    if(areSame(mat, fin, N))
        return true;
    return false;
}
bool combination(int **arr, int **fin, int N)
{
    int **mat;
    mat = new int *[N];
    for(int i = 0; i < N; i++)
    {
        mat[i] = new int[N];
    }
    if(N%2 != 0)
    {
        for(int r = 0; r < N; r++)
        {
            mat[r][N/2] = arr[r][N/2];
        }
    }
    int cC = 0;
    for(int row = 0; row < N; row++)
    {
        cC = 0;
        for(int col = N-1; col >= 0; col--)
        {
            mat[row][cC] = arr[row][col];
            cC += 1;
        }
        
    }
    
    if(rotateMatrix90(mat, fin, N))
        return true;
    if(rotateMatrix180(mat, fin, N))
        return true;
    if(rotateMatrix270(mat,fin,N))
        return true;
    return false;
}
bool solve(int **arr, int ** fin, int N)
{
    if(rotateMatrix90(arr, fin, N))
    {
        cout << "1" << endl;
        return true;
    }
    if(rotateMatrix180(arr, fin, N))
    {
        cout << "2" << endl;
        return true;
    }
    else if(rotateMatrix270(arr, fin, N))
    {
        cout << "3" << endl;
        return true;
    }
    else if(reflect(arr, fin, N))
    {
        cout << "4" << endl;
        return true;
    }
    else if(combination(arr, fin, N))
    {
        cout << "5" << endl;
        return true;
    }
    else if(areSame(arr,fin,N))
    {
        cout << "6" << endl;
        return true;
    }
    else
    {
        cout << "7" << endl;
        return true;
    }
    
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    int N;
    cin >> N;
    int **A;
    A = new int *[N];
    for(int i = 0; i < N; i++)
    {
        A[i] = new int[N];
    }
    for(int x = 0; x < N; x++)
    {
        for(int y = 0; y  <N; y++)
        {
            char temp;
            cin>> temp;
            if(temp == '@')
            {
                A[x][y] = 1;
            }
            else
                A[x][y] = 0;
        }
    }
    int **fin;
    fin = new int *[N];
    for(int z = 0; z < N; z++)
    {
        fin[z] = new int[N];
    }
    for(int t = 0; t < N; t++)
    {
        for(int r = 0; r  <N; r++)
        {
            char tem;
            cin>> tem;
            if(tem == '@')
                fin[t][r] = 1;
            else
                fin[t][r] = 0;
        }
    }
    solve(A, fin, N);
    
    return 0;
}
