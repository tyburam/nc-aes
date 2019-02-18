//
// Created by Mateusz Tybura on 2019-02-18.
//

#include <ctime>
#include <cstdlib>
#include <sstream>
#include "neuro_crypto.h"

namespace ncaes {
    namespace neuro {
        NeuroCrypto::NeuroCrypto (int initK, int initN, int initL) {
            srand(static_cast<unsigned int>(time(nullptr)));
            //Initialize A
            A.K = initK, A.N = initN, A.L = initL;
            A.Initialize ();
            A.RandomWeight ();
            //Initialize B
            B.K = initK, B.N = initN, B.L = initL;
            B.Initialize ();
            B.RandomWeight ();
            objInput.xLength (B.K, B.N);

            itrMax = static_cast<unsigned int>((A.L * A.L * A.L * A.L) * A.N * A.K);
        }

        void NeuroCrypto::Init() {
            //Main Iteration
            for (int i=1; i!=itrMax; i++) {
                objInput.CreateRandomVector(B.K, B.N);
                A.ComputeTPMResult(objInput.X);
                B.ComputeTPMResult(objInput.X);

                if(A.TPMOutput == B.TPMOutput) {
                    A.UpdateWeight (objInput.X);
                    B.UpdateWeight (objInput.X);
                    int sum = 0;
                    for(int ss=0;ss<A.K*A.N;ss++)	//Find sum
                        sum += abs(A.W.Z[ss]-B.W.Z[ss]);
                    if ( sum == 0 ) break;
                }
            }

            int key_size = 37 / (A.L * 2 + 1);
            int key_length = A.K * A.N / key_size;
            publickey.length(static_cast<char>(key_length + 1));

            for(int i = 0; i < key_length; i++)
                publickey.Z[i] = 0;

            const char Dictionary[39] = "01234567890_abcdefghijklmnopqrstuvwxyz";
            for (int i=1; i < key_length+1; i++) {
                int K = 1;
                for(int j=(i-1)*key_size; j<i*key_size;j++)
                    K = K + A.W.Z[j] + A.L;
                //
                publickey.Z[i-1]=Dictionary[K];
            }

            publickey.Z[key_length]='\0'; //Null char
        }

        std::string NeuroCrypto::Encrypt(const std::string &text) {
            return Cipher(text);
        }

        std::string NeuroCrypto::Decrypt(const std::string &text) {
            return Cipher(text, false);
        }

        std::string NeuroCrypto::Cipher(const std::string &text, bool encrypt) {
            ByteArray key, in, enc;

            int j = 0;
            while(publickey.Z[j] != '\0') {
                key.emplace_back(publickey.Z[j]);
                ++j;
            }

            for (char i : text) {
                in.push_back(static_cast<unsigned char &&>(i));
            }

            ByteArray::size_type enc_len = encrypt? Aes256::encrypt(key, in, enc) : Aes256::decrypt(key, in, enc);

            std::stringstream ss;
            for(int i=0; i<enc_len; ++i) ss <<(char)enc[i];
            return ss.str();
        }
    }
}
