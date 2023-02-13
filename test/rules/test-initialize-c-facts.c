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
    FILE *stream = fopen("facts.txt", "r");

    initialize_c_facts(c_fact, stream);

    assert(c_fact->facts[0] == 2);
    assert(c_fact->facts[1] == 1);

    destroy_c_fact(c_fact);
    fclose(stream);
  }
  facts_finish();

  return EXIT_SUCCESS;
}
