/**
 * @brief It defines the general tests interface
 * @file test.h
 * @author Daniel Martinez
 * @version 0.1
 * @date 2025-02-08
 * 
 * @copyright Copyright (c) 2025
 */

#ifndef _TEST_H
#define _TEST_H

#pragma GCC diagnostic ignored "-Wpedantic"

#ifndef NOCOLOR
#define KRED  "\x1B[31m"/*!< It defines the red colour*/
#define KGRN  "\x1B[32m"/*!< It defines the green colour*/
#define KYEL  "\x1B[33m"/*!< It defines the yellow colour*/
#define KCYN  "\x1B[36m"/*!< It defines the blue colour*/
#define RESET "\033[0m"/*!< It defines the reset of the colour*/
#else
#define KRED
#define KGRN
#define KYEL
#define KCYN
#define RESET
#endif

#define PRINT_TEST_RESULT(x) do{					\
    __test_counter++;							\
    __pass = (x);							\
    __test_passed = (__pass)? __test_passed + 1 : __test_passed;	\
    printf(KYEL "%s" RESET " line "  "%d " KCYN "%s" RESET ": %s\n",	\
	   __FILE__, __LINE__ , __FUNCTION__,				\
	   ((!__pass) ? KRED "NOT PASS" RESET : KGRN "PASS" RESET));	\
  } while (0)/*!< It defines the function that print the test result */

#define PRINT_PASSED_PERCENTAGE printf("Tests passed %d%%\n", ((__test_passed * 100) / __test_counter))/*!< It defines the function that gives the percentage of test passed*/
      
static int __test_counter = 0;
static int __test_passed  = 0;
static int __pass = 0;

#endif
