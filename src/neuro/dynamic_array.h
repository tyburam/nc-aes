//
// Created by Mateusz Tybura on 2019-02-18.
//

#ifndef NC_AES_DYNAMIC_ARRAY_H
#define NC_AES_DYNAMIC_ARRAY_H

namespace ncaes {
    namespace neuro {
        template <class T>
                class DynamicArray {
                public:
                    T* Z;
                    //Functions
                    ~DynamicArray ();
                    void length(T n);
                };

        template <class T>
        void DynamicArray<T>::length(T n)
        {
            Z = new T[n];
        }

        template <class T>
        DynamicArray<T>::~DynamicArray() {
            delete [] Z;
            Z = nullptr;
        }
    }
}

#endif //NC_AES_DYNAMIC_ARRAY_H
