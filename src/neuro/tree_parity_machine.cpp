//
// Created by Mateusz Tybura on 2019-02-18.
//

#include <cstdlib>
#include "tree_parity_machine.h"
#include "common.h"

namespace ncaes {
    namespace neuro {
        void TreeParityMachine::ComputeTPMResult(const DynamicArray <int> & X) {
            TPMOutput = 1;
            for (int i = 0; i < K; i++) {
                int sum = 0;
                for (int j = 0; j < N; j++) {
                    sum += (W.Z[i * N + j] * X.Z[i * N + j]);
                }
                H.Z[i]= Signum(sum);
                TPMOutput *= Signum(sum);
            }
        }

        void TreeParityMachine::Initialize() {
            W.length(K * N);
            H.length(K);
        }

        void TreeParityMachine::RandomWeight() {
            int i;
            for ( i = 0; i < K * N; i ++ ) {
                W.Z[i] = L - (rand() % (2 * L + 1));
            }
        }


        void TreeParityMachine::UpdateWeight(const DynamicArray <int> & X) {
            for (int i = 0; i < K; i++) {
                for (int j = 0; j < N; j++) {
                    int newW = W.Z[i * N + j];
                    newW += X.Z[i * N + j] * TPMOutput * IsEqual (TPMOutput, H.Z[i]) * IsEqual (TPMOutput, TPMOutput);
                    if (newW > L)
                        newW = L;
                    if (newW < - L)
                        newW = - L;
                    W.Z[i * N + j] = newW;
                }
            }
        }
    }
}
