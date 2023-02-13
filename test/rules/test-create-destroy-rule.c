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
  rules_init();
  {
    Rule *rule = create_rule();
    rule->size_facts = 2;
    assert(rule->size_facts == 2);

    *rule->facts = 79;
    assert(*rule->facts == 79);

    rule->answers[0] = 3;
    rule->answers[1] = 8;

    assert(rule->answers[0] == 3);
    assert(rule->answers[1] == 8);

    rule->size_answers = 97;
    assert(rule->size_answers == 97);

    destroy_rule(rule);
  }
  rules_finish();

  return EXIT_SUCCESS;
}
