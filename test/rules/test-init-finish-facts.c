#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>
#include <rules/rules.h>

int main(void) {
  assert(facts_init());
  assert(facts_init());
  assert(facts_init());

  assert(facts_finish());
  assert(facts_finish());
  assert(facts_finish());
  assert(!facts_finish());
  return EXIT_SUCCESS;
}
