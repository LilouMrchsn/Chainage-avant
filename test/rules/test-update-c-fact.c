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

    c_fact->facts[0] = 3;
    c_fact->facts[1] = 8;

    Rule *rule = create_rule();
    rule->size_facts = 1;
    rule->facts[0] = 7;

    update_c_fact(c_fact, rule);
    printf("\n%i\n", c_fact->size);

    assert(c_fact->facts[1] == 8);

    destroy_c_fact(c_fact);
    destroy_rule(rule);
  }
  facts_finish();

  return EXIT_SUCCESS;
}
