#include "multiply.h"

int *multiply_1_svc(int a, int b, struct svc_req *rqstp){
	static int result;
	//fprintf(stdout,"CALCUL");
	//*result = argp[0] * argp[1];
	result = a * b;
	//fprintf(stdout,"TEST %d %d",argp[0],argp[1]);
	return &result;

}
