#ifndef RULES_H_
#define RULES_H_
#include <stdbool.h>
#include <stdio.h>

//********************* typedefs *******************************

/**
 * @brief This is the curents facts typedef and struct declaration.
 *
 * Creation of a typedef CurrentFacts of struct _current_facts
 */
typedef struct _current_facts CurrentFacts;

/**
 * @brief This is the Rule typedef and struct declaration.
 *
 * Creation of a typedef Rule of struct _Rule
 */
typedef struct _Rule Rule;

//********************* facts functions *******************************

/**
 * This is the facts init function.
 *
 * @param  void parameter
 * @return a boolean value, true if fact was initialised
 */
extern bool facts_init(void);

/**
 * This is the facts finish function.
 *
 * @param  void parameter
 * @return a boolean value, true if fact was finished
 */
extern bool facts_finish(void);

/**
 * Pointer function, creates a fact
 *
 * @param  void parameter
 * @return a CurrentFacts object
 */
extern CurrentFacts *create_c_fact(void);

/**
 * Destroy facts function,
 *
 * @param *current_rule parameter to be destroyed
 * @return void
 */
extern void destroy_c_fact(CurrentFacts *current_rule);

/**
 * Update function
 *
 * @param *current_facts and *rule parameters
 * @return void
 */
extern void update_c_fact(CurrentFacts *current_facts, Rule *rule);

/**
 * Initialise facts function
 *
 * @param *current_facts and *stream parameters
 * @return void
 */
extern void initialize_c_facts(CurrentFacts *current_facts, FILE *stream);

//********************* rules functions *******************************

/**
 * This is the rules init function
 *
 * @param void parameter
 * @return bool value, true if rule initialised
 */
extern bool rules_init(void);

/**
 *This is the rules finish function
 *
 * @param void parameter
 * @return boolean value, true if rules was finished
 */
extern bool rules_finish(void);

/**
 *Create rule function
 *
 * @param void parameters
 * @return a Rule
 */
extern Rule *create_rule(void);

/**
 *Destroy rule function
 *
 * @param *rule is the Rule to be destroyed
 * @return void
 */
extern void destroy_rule(Rule *rule);

/**
 *Update rule function
 *
 * @param a pointer Rule and a pointer FILE parameters
 * @return void
 */
extern void update_rule(Rule *rule, FILE *stream);

//******************* other functions *****************************

/**
 *Final fwrite function, writes the facts into chosen file
 *
 * @param the fact to be written and the file in parameters
 * @return void
 */
extern void fwrite_final(CurrentFacts *current_facts, FILE *file);

/**
 *This function converts a string to array
 *
 * @param a pointer string and a pointer int in parameters
 * @return  int value
 */
extern int *string_to_table(char *string, int *i);
extern bool isSubset(int arr1[], int arr2[],
int m, int n);

#endif  // RULES_H_
