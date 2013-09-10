#include<iostream>
using std::cout;
using std::endl;
#include<fstream>
using std::ifstream;
#include<cmath>
using std::sin;
using std::cos;
#include<vector>
using std::vector;
#include<Eigen/Dense>
using Eigen::Matrix;
using Eigen::Matrix2f;
using Eigen::Vector2f;

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
        cout << rot(M_PI/4) * pts                                << endl;
        cout << "After rotating 90 degrees"                      << endl;
        cout << rot(M_PI/2) * pts                                << endl;
        cout << "Enter a filename of tab separated values"       << endl;
    } else {
        // Load File
        ifstream file;
        file.open(argv[1]);
        vector<Vector2f> v0;
        float x, y;
        while(file >> x >> y) {
            v0.push_back( Vector2f(x,y) );
        }
        file.close();
        
        //Rotate points
        const int nTH = 5;
        for( int i=0; i<nTH; i++) {
            float TH = i*M_PI / (2*nTH);
            printf( "%.2f ====================\n", TH);
            for( vector<Vector2f>::size_type j=0; j < v0.size(); j++) {
                Vector2f v1 = rot(TH) * v0[j];
                printf("% 6f\t% 6f\n", v1(0),  v1(1));
            }
        }
    }
    return 0;
}
