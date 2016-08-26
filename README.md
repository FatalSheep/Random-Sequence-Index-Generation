# Random-Sequence-Index-Generation.
Generates a random sequence of indices from `0` to `N`--without repeats--in O(n) time via [Fisher Yates' In-Side-Out](https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_.22inside-out.22_algorithm) shuffling algorithm. The function `rand_indices(n)` is the full implementation.

***NOTE:*** I'm using thiss for packet obfuscation for use with cryptography, if you plan to do the same thing make sure to use a cryptographically safe PRNG and seed the PRNG with entropy.

```C
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Include the rand_indices header.
#include ".\rand_indices"

// Create a function to pass to rand_indices().
__int8 random() {
    return static_cast<__int8>(std::rand());
}

int main() {
    int n = 24;
    
    // Call rand_indices() using our random function.
    int* arr = rand_indicies(&random);

    for(int i = 0; i < n; i++)
        printf("%i%c", arr[i], '\n');

    free(arr);
    system("pause");
}
```
