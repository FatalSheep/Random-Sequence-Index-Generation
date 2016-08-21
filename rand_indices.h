#ifndef __RAND_INDICES__
#define __RAND_INDICES__
  #include <stdlib.h>
  #include <string.h>
  
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
#endif
