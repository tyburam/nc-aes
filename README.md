# nc-aes
C++ Implementation of Neural Cryptography for Public Key Exchange and Secure Message Encryption with Rijndael Cipher 

# Based on
1. Article [NeuroCrypto: C++ Implementation of Neural Cryptography for Public Key Exchange and Secure Message Encryption with Rijndael Cipher](http://www.academia.edu/4055547/NeuroCrypto_C_Implementation_of_Neural_Cryptography_for_Public_Key_Exchange_and_Secure_Message_Encryption_with_Rijndael_Cipher)
2. GitHub repo [NeuroCrypto](https://github.com/sagunms/NeuroCrypto)

# Idea (from original repo)
This work is the software implementation of the concept of neural cryptography, which is a communication of two tree parity machines for agreement on a common key over a public channel. This key is utilized to encrypt a sensitive message to be transmitted over an insecure channel using Rijndael cipher. This is a new potential source for public key cryptography schemes which are not based on number theoretic functions, and have small time and memory complexities.

# Changes
1. Removed .NET Framework dependency
   1. No GUI
   2. Not even a tiny little bit of Managed C++
   3. AES implemented from GPL2.1 library stored in two files
2. Using namespaces
3. Classes separated into distinct files
4. CMake usage

# Future plans
1. Consistent naming convention
2. Removal of common.h?

# Software used
1. CLion 2018.3.4
2. Apple LLVM version 10.0.0 (clang-1000.10.44.4)
3. CMake 3.13.4