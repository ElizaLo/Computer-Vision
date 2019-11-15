//
//  main.cpp
//  Task
//
//  Created by Elizabeth Lorelei on 15.11.2019.
//  Copyright © 2019 Yelyzaveta Losieva. All rights reserved.
//

#include <iostream>
#include <Eigen/Dense>
#include <Eigen/LU>
#include <array>

using namespace std;
using namespace Eigen;

Matrix3d calcHomography(const array<Vector2d,4>& oldPoints,
                        const array<Vector2d,4>& newPoints);

int main()
{
    Vector2d X1{0,1};
    Vector2d X2{1,1};
    Vector2d X3{1,0};
    Vector2d X4{0,0};
    Vector2d U1{0,1};
    Vector2d U2{2,1};
    Vector2d U3{2,0};
    Vector2d U4{0,0};
    Matrix3d homography{calcHomography({X1, X2, X3, X4}, {U1, U2, U3, U4})};
    cout << homography << endl;
}

Matrix3d calcHomography(const array<Vector2d,4>& oldPoints,
                        const array<Vector2d,4>& newPoints)
{
    Matrix<double,9,9> A{Matrix<double,9,9>::Zero()};
    for (size_t i{0}; i<4; ++i)
    {
        auto X = oldPoints[i];
        auto U = newPoints[i];
        
        A(2*i,0) = -X[0];
        A(2*i,1) = -X[1];
        A(2*i,2) = -1;
        A(2*i,6) =  X[0]*U[0];
        A(2*i,7) =  X[1]*U[0];
        A(2*i,8) =  U[0];
        
        A(2*i+1,3) =  -X[0];
        A(2*i+1,4) =  -X[1];
        A(2*i+1,5) =  -1;
        A(2*i+1,6) =  X[0]*U[1];
        A(2*i+1,7) =  X[1]*U[1];
        A(2*i+1,8) =  U[1];
    }
    A(8,8) = 1;
    cout << A << endl;
    Matrix<double,9,1> b{Matrix<double,9,1>::Zero()};
    b(8) = 1;
    Matrix<double,9,1> flattenRes {A.colPivHouseholderQr().solve(b)};
    cout << endl << flattenRes << endl << endl;
    Matrix3d res;
    for (size_t i{0}; i<9; ++i)
    {
        res(i/3, i%3) = flattenRes[i];
    }
    return res;
}
