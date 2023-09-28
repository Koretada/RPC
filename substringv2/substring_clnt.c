/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "substring.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

int *
is_forbidden_substring_1(char *arg1, char *arg2,  CLIENT *clnt)
{
	is_forbidden_substring_1_argument arg;
	static int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, is_forbidden_substring, (xdrproc_t) xdr_is_forbidden_substring_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_int, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

char *
generate_next_char_1(char *arg1, int arg2, char *arg3,  CLIENT *clnt)
{
	generate_next_char_1_argument arg;
	static char clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	arg.arg3 = arg3;
	if (clnt_call (clnt, generate_next_char, (xdrproc_t) xdr_generate_next_char_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_char, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

void *
generate_string_without_substrings_1(int arg1, char arg2, char *arg3,  CLIENT *clnt)
{
	generate_string_without_substrings_1_argument arg;
	static char clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	arg.arg3 = arg3;
	if (clnt_call (clnt, generate_string_without_substrings, (xdrproc_t) xdr_generate_string_without_substrings_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_void, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return ((void *)&clnt_res);
}
