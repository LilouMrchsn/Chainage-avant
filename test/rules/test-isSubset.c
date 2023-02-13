#include <stdio.h>
#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>
#include <stdbool.h>

#include <rules/rules.h>
#include <rules/rules.inc>

int main(void) {
  facts_init();

  int *arr1 = malloc(sizeof(int)*3);
  int *arr2 = malloc(sizeof(int)*5);

  arr1[0] = 1, arr1[1] = 2, arr1[2] = 3;
  arr2[0] = 1, arr2[1] = 2, arr2[2] = 3, arr2[3] = 4, arr2[4] = 5;

  assert(isSubset(arr1, arr2, 3, 5) == false);
  assert(isSubset(arr2, arr1, 5, 3) == true);

  free(arr1);
  free(arr2);

  facts_finish();
}
