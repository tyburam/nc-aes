//
// Created by Mateusz Tybura on 2019-02-18.
//

#ifndef NC_AES_TPM_INPUT_VETOR_H
#define NC_AES_TPM_INPUT_VETOR_H

#include "dynamic_array.h"

namespace ncaes {
    namespace neuro {
        class TPMInputVector {
        public :
            DynamicArray <int> X;
            void CreateRandomVector(int K, int N);
            void xLength(int K, int N);
        };
    }
}

#endif //NC_AES_TPM_INPUT_VETOR_H
