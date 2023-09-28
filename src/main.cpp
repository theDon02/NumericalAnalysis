#include "linear_algebra/matrix.h"
#include "linear_algebra/vector.h"
#include "linear_algebra/specialMatricies.h"

int main(int argc, char* argv[]) {
    //m1 (3x2)
    std::vector<std::vector<double>> m1 {
        {3, 4},
        {3, -2},
        {4, -2}
    };

    //m2 (2x3)
    std::vector<std::vector<double>> m2 {
        {0, 3, 4},
        {5, 5, 5}
    };

    //m3 (3x3)
    std::vector<std::vector<double>> m3 {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    //Create matrix 
    linear_algebra::IdentityMatrix a((unsigned int) 3, (unsigned int) 3);
    linear_algebra::SquareMatrix b((unsigned int) 3, (unsigned int) 3, argv[1]);
    linear_algebra::SquareMatrix c(argv[1]);
    linear_algebra::SquareMatrix d(m3);

    a.printMatrix();
    b.printMatrix();
    c.printMatrix();
    d.printMatrix();
        
    return 0;
}