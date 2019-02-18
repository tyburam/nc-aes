//
// Created by Mateusz Tybura on 2019-02-18.
//

#ifndef NC_AES_COMMON_H
#define NC_AES_COMMON_H

#include <cstdlib>

namespace ncaes {
    namespace neuro {
        inline int IsEqual(int a, int b) {
            return (a == b ? 1 : 0);
        }

        inline int RandomBit() {
            return (rand() % 2 == 0 ? -1 : 1);
        }

        inline int Signum(double r) {
            return (r > 0 ? 1 : -1);
        }
    }
}

#endif //NC_AES_COMMON_H
