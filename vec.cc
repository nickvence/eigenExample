#include<iostream>
using std::cout;
using std::endl;
#include<fstream>
#include<cmath>
using std::sin;
using std::cos;
#include<Eigen/Dense>
using Eigen::Matrix;
using Eigen::Matrix2f;

Matrix2f rot(float th) {
    float sinTH = sin(th);
    float cosTH = cos(th);
    Matrix2f rot;
    rot << cosTH, -sinTH,
           sinTH,  cosTH;
    return rot;
}


int main(int argc, char* argv[]) {
    if(argc == 1) { // Create simple default
        Matrix<float,2,3> pts;
        pts << 1, 0, 1,
               0, 1, 1;
        cout << pts << endl;
        cout << "After rotating 45 degrees" << cout.precision(3) << endl;
        cout << rot(M_PI/4) * pts << endl;
        cout << "After rotating 90 degrees" << endl;
        cout << rot(M_PI/2) * pts << endl;
    } else {
        //printf("Hello argc = %d\n",argc);
        //std::ifstream f;
        //f.open("star.tsv");
    }
    return 0;
}
