#include "./rules.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./rules.inc"

int *string_to_table(char *string, int *i) {
  char *token = strtok(string, " ");
  // int size=100;

  int *tab = (int *)malloc(100 * sizeof(int));
  int j = 0;
  while (token != NULL) {
    tab[j] = atoi(token);
    j++;
    token = strtok(NULL, " ");
  }

  *i = j;

  return tab;
}

static int counter = 0;

// facts struct functions

void *(*fa_malloc)(size_t size) = malloc;
void *(*fa_realloc)(void *ptr, size_t size) = realloc;
void (*fa_free)(void *ptr) = free;

bool facts_init(void) {
  if (!counter++) {
    printf("Facts initialised");
  }
  return true;
}

bool facts_finish(void) {
  if (counter) {
    if (!--counter) {
      printf("Facts finished\n");
    }
    return true;
  } else {
    return false;
  }
}
CurrentFacts *create_c_fact(void) {
  CurrentFacts *C_fact = fa_malloc(sizeof(CurrentFacts));
  C_fact->facts = fa_malloc(sizeof(int) * 500);
  return C_fact;
}

void destroy_c_fact(CurrentFacts *current_facts) { fa_free(current_facts); }
void initialize_c_facts(CurrentFacts *current_facts, FILE *stream) {
  char *first_line;
  first_line = (char *)malloc(sizeof(char));
  fgets(first_line, 10, stream);
  current_facts->facts = string_to_table(first_line, &current_facts->size);
  free(first_line);
}
void update_c_fact(CurrentFacts *current_facts, Rule *rule) {
  // strcat(current_facts->facts, " ") ;
  // strcat(current_facts->facts , rule->answers);
  for (int i = 0; i < rule->size_answers; i++) {
    current_facts->facts[current_facts->size] = rule->answers[i];
    current_facts->size++;
  }
}

// rules struct functions
void *(*ru_malloc)(size_t size) = malloc;
void *(*ru_realloc)(void *ptr, size_t size) = realloc;
void (*ru_free)(void *ptr) = free;

bool rules_init(void) {
  if (!counter++) {
    assert(printf("rules: initialised\n"));
  }
  return true;
}

bool rules_finish(void) {
  if (counter) {
    if (!--counter) {
      assert(printf("rules: finished\n"));
    }
    return true;
  } else {
    return false;
  }
}
Rule *create_rule(void) {
  Rule *rule = ru_malloc(sizeof(Rule));
  rule->facts = ru_malloc(sizeof(int));
  rule->answers = ru_malloc(sizeof(int));

  return rule;
}

void destroy_rule(Rule *rule) { ru_free(rule); }

void update_rule(Rule *rule, FILE *stream) {
  char *empty_line;
  empty_line = (char *)malloc(sizeof(char));
  char *rule_tmp;
  rule_tmp = (char *)malloc(sizeof(char));
  char *answers_tmp;
  answers_tmp = (char *)malloc(sizeof(char));
  fgets(rule_tmp, 10, stream);
  fgets(answers_tmp, 10, stream);
  fgets(empty_line, 10, stream);
  rule->facts = string_to_table(rule_tmp, &rule->size_facts);
  rule->answers = string_to_table(answers_tmp, &rule->size_answers);
  free(empty_line);
  free(rule_tmp);
  free(answers_tmp);
}

void fwrite_final(CurrentFacts *current_facts, FILE *file) {
  char *c = malloc(sizeof(char));
  for (int i = 0; i < current_facts->size; i++) {
    sprintf(c, "%d ", current_facts->facts[i]);
    fputs(c, file);
  }

<<<<<<< HEAD
  free(c);
=======
void fwrite_final(CurrentFacts *current_facts, FILE *file){


for(int i=0;i<current_facts->size;i++){

char charValue = current_facts->facts[i]+'0';


fputc(charValue,file); 
}

>>>>>>> 1973ce0f2257bd89d7bde8daead09a1cf0e4ef5c
}
