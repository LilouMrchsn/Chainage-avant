#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>
#include <rules/rules.h>

int main(void) {
  assert(rules_init());
  assert(rules_init());
  assert(rules_init());

  assert(rules_finish());
  assert(rules_finish());
  assert(rules_finish());
  assert(!rules_finish());
  return EXIT_SUCCESS;
}
