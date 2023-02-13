#include <stdio.h>
#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>
#include <rules/rules.h>
#include <stdbool.h>
#include <string.h>

#include <rules/rules.inc>

int main(void) {
  facts_init();

  FILE *stream = fopen("output.txt", "r");
  // stream = tmpfile();

  CurrentFacts *c_fact = create_c_fact();
  c_fact->size = 1;
  c_fact->facts[0] = 3;
  c_fact->facts[1] = 8;
  c_fact->facts[2] = 7;
  c_fact->facts[3] = 1;

  fwrite_final(c_fact, stream);

  FILE *stream_r = fopen("output.txt", "r");
  char *c = malloc(10 * sizeof(char));
  fgets(c, 10, stream_r);
  assert(strcmp(c, "3 8 7 1"));
  fclose(stream);
  fclose(stream_r);
  free(c);

  destroy_c_fact(c_fact);

  facts_finish();
}
