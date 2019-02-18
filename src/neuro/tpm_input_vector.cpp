//
// Created by Mateusz Tybura on 2019-02-18.
//

#include "tpm_input_vector.h"
#include "common.h"

namespace ncaes {
    namespace neuro {
        void TPMInputVector::CreateRandomVector(int K, int N) {
            for (int i = 0; i < K * N; i++) {
                X.Z[i] = RandomBit();
            }
        }

        void TPMInputVector::xLength(int K, int N) {
            X.length(K * N);
        }
    }
}
