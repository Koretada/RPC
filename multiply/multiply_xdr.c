/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "multiply.h"

bool_t
xdr_multiply_1_argument (XDR *xdrs, multiply_1_argument *objp)
{
	 if (!xdr_int (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}