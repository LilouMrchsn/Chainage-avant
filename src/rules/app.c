#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./rules.h"
#include "./rules.inc"

int main(int argc, char *argv[]) {
  // declaration des structure
  CurrentFacts *currentfacts = create_c_fact();
  Rule *rule = create_rule();

  // ouverture des fichiers
  FILE *stream = fopen(argv[2], "r");
  FILE *fichier = fopen(argv[4], "r");
  FILE *file = fopen(argv[6], "a");

  char *str;
  str = (char *)malloc(sizeof(char));

  // recuperation de la premiere ligne de fichier facts
  initialize_c_facts(currentfacts, fichier);

  // fermeture de fichier facts
  fclose(fichier);

  // printf("current :%s \n", currentfacts->facts);
  while (!feof(stream)) {
    update_rule(rule, stream);
    int inside = 1;
    int i = 0;
    bool a = isSubset(currentfacts->facts, rule->facts, currentfacts->size,
                      rule->size_facts);
    bool b = isSubset(currentfacts->facts, rule->answers, currentfacts->size,
                      rule->size_answers);

    printf("\ncurrent_facts : ");
    for (int j = 0; j < currentfacts->size; j++) {
      printf("%i ", currentfacts->facts[j]);
    }
    printf("\ncurrent_rules : ");
    for (int j = 0; j < rule->size_facts; j++) {
      printf("%i ", rule->facts[j]);
    }

    if (a) {
      printf("a");
      if (!b) {
        inside = 1;
        printf("k");
      } else {
        printf("b");

        inside = 0;
      }
    } else {
      printf("c");
      inside = 0;
    }

    // printf("%i",inside);

    if (inside == 1) {
      printf("ifff");

      update_c_fact(currentfacts, rule);

      rewind(stream);
    }
  }

  fwrite_final(currentfacts, file);

  destroy_c_fact(currentfacts);
  destroy_rule(rule);

  fclose(stream);
  fclose(file);

  return EXIT_SUCCESS;
}
