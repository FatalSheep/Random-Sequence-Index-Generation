#ifndef __RAND_INDICES__
#define __RAND_INDICES__
    #include <stdlib.h>
    #include <string.h>

    template<int S, typename T>
    void rand_indicies(int(&ptr)[S], __int8 (T::*func)(), T* object) {
        for (int i = 0, j; i < S; i++) {
            j = (i == 0) ? 0 : (static_cast<int>((object->*func)()) % (i + 1));

            if (j != i)
                ptr[i] = ptr[j];
            ptr[j] = i;
        }
    }

    template<int S>
    void rand_indicies(int(&ptr)[S], __int8 (*func)()) {
        for (int i = 0, j; i < S; i++) {
            j = (i == 0) ? 0 : (static_cast<int>((*func)()) % (i + 1));

            if (j != i)
                ptr[i] = ptr[j];
            ptr[j] = i;
        }
    }
#endif
