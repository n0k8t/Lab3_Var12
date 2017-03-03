#include "TVector.h"

int main() {

    size_t n = 0;
    std::cout << "Enter number of elements: ";// << std::endl;
    std::cin >> n;

    double *doubles = new double[n];
    for (int i = 0; i < n; i++) {
        doubles[i] = rand() / 99.;
    }

    TVector vector = TVector();
    vector = TVector(doubles, n);
    doubles = vector + doubles; // Vector + double * = Vector

    for (int i = 0; i < n * 2; i++) {
        std::cout << doubles[i] << " ";
    }

    delete[] doubles;
    return 0;
}