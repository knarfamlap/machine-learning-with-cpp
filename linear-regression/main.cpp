#include "lsr.h"

int main()
{
    /* code */
    bool VERBOSE = true;
    simple_linear_regression slr({2, 3, 5, 7, 9}, {4, 5, 7, 10, 15}, VERBOSE);
    slr.train();

    std::cout << slr.predict(15);

    return 0;
}
