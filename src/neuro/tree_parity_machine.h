//
// Created by Mateusz Tybura on 2019-02-18.
//

#ifndef NC_AES_TREE_PARITY_MACHINE_H
#define NC_AES_TREE_PARITY_MACHINE_H

#include "dynamic_array.h"

namespace ncaes {
    namespace neuro {
        class TreeParityMachine {
        public :
            DynamicArray<int> W, H;
            int K, N, L;
            int TPMOutput;

            void Initialize();

            void ComputeTPMResult(const DynamicArray<int> &X);

            void UpdateWeight(const DynamicArray<int> &X);

            void RandomWeight();
        };
    }
}

#endif //NC_AES_TREE_PARITY_MACHINE_H
