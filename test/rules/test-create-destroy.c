#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>
#include <rules/rules.h>

#include <rules/rules.inc>

int main(void) {
  facts_init();
  {
    CurrentFacts *c_fact = create_c_fact();
    c_fact->size = 2;
    assert(c_fact->size == 2);

    *c_fact->facts = 79;
    assert(*c_fact->facts == 79);
    destroy_c_fact(c_fact);
  }
  facts_finish();
}