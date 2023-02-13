#include <stdio.h>
#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>
#include <rules/rules.h>
#include <stdbool.h>

int main(void) {
  facts_init();
  char *c = (char *)malloc(sizeof(char));
  c = "1 2 3";
  int *i;

  int *t = malloc(sizeof(int) * 100);
  t = string_to_table(c, i);

  // assert(t == {1, 2, 3});
  assert(*i == 3);

  free(c);

  free(t);

  facts_finish();
  return EXIT_SUCCESS;
}
