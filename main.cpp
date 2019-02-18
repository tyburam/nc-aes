//
// Created by Mateusz Tybura on 2019-02-18.
//

#include <iostream>
#include "./src/neuro/neuro_crypto.h"

int main()
{
    auto crypter = ncaes::neuro::NeuroCrypto(9, 12, 4);
    crypter.Init();

    auto plain = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec odio ex, congue sit amet enim in, luctus volutpat lectus.";
    auto encrypted = crypter.Encrypt(plain);
    auto decrypted = crypter.Decrypt(encrypted);

    std::cout << std::endl
        << "Plain:     " << plain << std::endl
        << "Encrypted: " << encrypted << std::endl
        << "Decrypted: " << decrypted << std::endl;
    return 0;
}

