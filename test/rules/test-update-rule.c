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
    Rule *rule = create_rule();

    FILE *stream = fopen("rules.txt", "r");

    update_rule(rule, stream);

    assert(rule->size_facts == 1);
    assert(rule->size_answers == 1);

    assert(rule->facts[0] == 7);
    assert(rule->answers[0] == 19);

    destroy_rule(rule);
  }
  facts_finish();

  return EXIT_SUCCESS;
}
