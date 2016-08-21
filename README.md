# Random-Sequence-Index-Generation.
Generates a random sequence of indices from `0` to `N`--without repeats--in O(n) time via [Fisher Yates' In-Side-Out](https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_.22inside-out.22_algorithm) shuffling algorithm. The function `rand_indices(n)` is the full implementation.

***NOTE:*** I'm using thiss for packet obfuscation for use with cryptography, if you plan to do the same thing make sure to use a cryptographically safe PRNG and seed the PRNG with entropy.

```C
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//////////////////////////////////////////////////////////////////////////
int* rand_indicies(int n) {
    int* ptr = (int*) malloc(n * sizeof(int));

    for (int i = 0, j; i < n; i++) {
        j = (i == 0) ? 0 : rand() % (i + 1);

        if (j != i)
            ptr[i] = ptr[j];
        ptr[j] = i;
    }

    return ptr;
}
//////////////////////////////////////////////////////////////////////////

int main() {
    int n = 24;
    int* arr = rand_indicies(n);

    for(int i = 0; i < n; i++)
        printf("%i%c", arr[i], '\n');

    free(arr);
    system("pause");
}
```
