#ifndef RULES_H
#define RULES_H

#include <string.h>

struct _current_facts {
  unsigned int size;
  int *facts;
};

struct _Rule {
  unsigned int size_facts;
  unsigned int size_answers;
  int *facts;
  int *answers;
};

#endif
