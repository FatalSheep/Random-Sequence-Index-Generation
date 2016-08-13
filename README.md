# Random-Sequence-Index-Generation.
Generates a random sequence of indices from `0` to `N`--without repeats--in O(n) time via Fisher Yate's In-Side-Out shuffling algorithm. The function `rand_indices(n)` is the full implementation.

```C
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* rand_indicies(int n) {
    int* ptr = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int j = (i == 0) ? 0 : rand() % (i + 1);

        if (j != i)
            ptr[i] = ptr[j];
        ptr[j] = i;
    }

    return ptr;
}

int main() {
    int n = 24;
    int* arr = rand_indicies(n);

    for(int i = 0; i < n; i++)
        printf("%i%c", arr[i], '\n');

    free(arr);
    system("pause");
}
```
