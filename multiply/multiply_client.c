#include "multiply.h"

int main(int argc, char **argv){
	int input[2];
	int *result;
	CLIENT *cl;
	if(argc != 4){
		fprintf(stderr, "Utilisation : %s <RPC_SERVER_NAME> <int> <int> \n", argv[0]);
		exit(1);
	}
	
	cl = clnt_create(argv[1], RPCDJAMEL, V1, "tcp");
	if (cl == (CLIENT *) NULL) {
		clnt_pcreateerror(argv[1]);
		exit(1);
	}
	//input[0] = atoi(argv[2]);
	//input[1] = atoi(argv[3]);
	printf("%d %d\n",input[0],input[1]);
	result = multiply_1(atoi(argv[2]),atoi(argv[3]), cl);

	if(result == NULL){
		printf("erreur");
		exit(1);
	}

	printf("Result = %d\n", *result);
	clnt_destroy(cl);
	exit(0);
}

