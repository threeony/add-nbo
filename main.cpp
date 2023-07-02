#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){

	FILE *fp1;
	FILE *fp2;
	uint32_t n1;
	uint32_t n2;

	fp1 = fopen(argv[1], "r");
	fp2 = fopen(argv[2], "r");
	if(fp1 && fp2){
		fread(&n1, sizeof(uint32_t),1, fp1);
		fread(&n2, sizeof(uint32_t),1, fp2);
	}

	n1=ntohl(n1);
	n2=ntohl(n2);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", n1, n1, n2, n2, n1+n2, n1+n2);

	fclose(fp2);
	fclose(fp1);
}
