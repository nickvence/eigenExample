/** \file
 *  \brief An example Eigen program.
 *
 * \mainpage This code showcases Eigen (a linear algebra package).
 * When called with no prameters, it rotates a triangle.
 * When given a filename containing one white-space-separted, 2D vector,
 * the points are rotated.
 * \author Nick Vence
 * \date 09/10/2013
 **/
#include<iostream>
using std::cout;
using std::endl;
#include<fstream>
using std::ifstream;
#include<cmath>
using std::sin;
using std::cos;
#include<Eigen/Dense>
using Eigen::Matrix;
using Eigen::Matrix2f;
using Eigen::Vector2f;
using Eigen::Dynamic;

///rot() creates a 2D rotation matrix about an angle TH.
///\param TH theta, the angle of rotation
Matrix2f rot(float th) {
    float sinTH = sin(th);
    float cosTH = cos(th);
    Matrix2f rot;
    rot << cosTH, -sinTH,
           sinTH,  cosTH;
    return rot;
}

/// If( argv[1] ) load vectors,
/// otherwise rotate a triangle.
int main(int argc, char* argv[]) {
    if(argc == 1) {
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
        /// Counting nVec: the number of vectors in filename.
        ifstream file;
        file.open(argv[1]);
        int nVec = 0;
        float x, y;
        while( file >> x >> y) nVec++;
        cout << "nVec = " << nVec << endl;
        Matrix<float, 2, Dynamic> v(2,nVec);
        file.close();

        ///Load v: data vector 
        file.open(argv[1]);
        for(int i=0; file >> x >> y;  i++) {
            v(0,i) = x;
            v(1,i) = y;
        }
        cout << "v = " << endl;
        cout << v << endl;
        file.close();

        ///Rotate points
        const int nTH = 6;
        for( int i=0; i<nTH; i++) {
            float TH = i*M_PI / (2*nTH);
            printf( "%.2f =================\n", TH);
            for( int j=0; j < nVec; j++) {
                Vector2f v1 = rot(TH) * v.col(j);
                printf("% 6f\t% 6f\n", v1(0),  v1(1));
            }
        }
    }
    return 0;
}
