#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"
#include "CUnit/Console.h"
#include "./header/fonctions.h" // bibliothèque fonction du ruzzle
#include <stdio.h>  // for printf


// test de la fonction

void test_chercheDico(void)

{
CU_ASSERT (maxi("abri)== 2);
CU_ASSERT (maxi("abac")== 0);
CU_ASSERT (maxi("la") == 3);
}

int main(int argc, const char * argv[]) {

CU_pSuite pSuite = NULL;

if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();
pSuite = CU_add_suite("Suite_1", 0, 0);
if (!pSuite) { CU_cleanup_registry();
return CU_get_error(); }

if (!CU_add_test(pSuite, "test of fprintf()", test_max))
{   CU_cleanup_registry();
return CU_get_error();
}
CU_basic_run_tests();
CU_cleanup_registry();
return CU_get_error();
}

