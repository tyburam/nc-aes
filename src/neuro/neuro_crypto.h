//
// Created by Mateusz Tybura on 2019-02-18.
//

#ifndef NC_AES_NEURO_CRYPTO_H
#define NC_AES_NEURO_CRYPTO_H

#include <string>
#include "tree_parity_machine.h"
#include "tpm_input_vector.h"
#include "../../vendor/aes256.hpp"

namespace ncaes {
    namespace neuro {
        class NeuroCrypto {
        public:
            NeuroCrypto(int k, int n, int l);
            void Init();
            std::string Encrypt(const std::string &text);
            std::string Decrypt(const std::string &text);
        private:
            std::string Cipher(const std::string &text, bool encrypt = true);

            unsigned int itrMax;
            TreeParityMachine A, B;
            TPMInputVector objInput;
            DynamicArray<char> publickey;
        };
    }
}

#endif //NC_AES_NEURO_CRYPTO_H
