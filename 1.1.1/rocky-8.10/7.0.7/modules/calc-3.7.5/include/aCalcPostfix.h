/*************************************************************************\
* Copyright (c) 2010 UChicago Argonne LLC, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE is distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/
/* aCalcPostfix.h
 *      Derived from postfix.h in EPICS base
 *      Current author: Tim Mooney
 */

#ifndef INC_aCalcPostfixh
#define INC_aCalcPostfixh

#include <shareLib.h>

/* lifted from postfix.h in base, and adapted for sCalc */
#define ACALC_INFIX_TO_POSTFIX_SIZE(n) (2+n*21/6)

#define	BAD_EXPRESSION	0

#define CALC_ERR_NONE              0 /* No error */
#define CALC_ERR_TOOMANY           1 /* Too many results returned */
#define CALC_ERR_BAD_LITERAL       2 /* Badly formed numeric literal */
#define CALC_ERR_BAD_ASSIGNMENT    3 /* Bad assignment target */
#define CALC_ERR_BAD_SEPARATOR     4 /* Comma without enclosing parentheses */
#define CALC_ERR_PAREN_NOT_OPEN    5 /* Close parenthesis found without open */
#define CALC_ERR_PAREN_OPEN        6 /* Parenthesis still open at end of expression */
#define CALC_ERR_CONDITIONAL       7 /* Unbalanced conditional ?: operators */
#define CALC_ERR_INCOMPLETE        8 /* Incomplete expression, operand missing */
#define CALC_ERR_UNDERFLOW         9 /* Not enough operands provided (runtime stack would underflow) */
#define CALC_ERR_OVERFLOW         10 /* Runtime stack would overflow */
#define CALC_ERR_SYNTAX           11 /* Syntax error */
#define CALC_ERR_NULL_ARG         12 /* NULL or empty input argument */
#define CALC_ERR_INTERNAL         13 /* Internal error, bad element type */
#define CALC_ERR_BRACKET_NOT_OPEN 14 /* Close bracket without open */
#define CALC_ERR_CURLY_NOT_OPEN   15 /* Close curly bracket without open */

#ifdef __cplusplus
extern "C" {
#endif

epicsShareFunc long
	aCalcPostfix(const char *pinfix, unsigned char * const p_postfix, short *perror);

epicsShareFunc long  
	aCalcPerform(double *p_dArg, int num_dArgs, double **pp_aArg, int num_aArgs,
		int arraySize, double *p_dresult, double *p_aresult,
		const unsigned char *post, const int allocSize, epicsUInt32 *amask);

epicsShareFunc const char *
	aCalcErrorStr(short error);

epicsShareFunc long
	acalcTotalAllocatedMemory(void);

#ifdef __cplusplus
}
#endif

#endif /* INC_aCalcPostfixh */

