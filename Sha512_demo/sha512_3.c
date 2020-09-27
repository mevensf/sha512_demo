#include <stdio.h>  
#include <openssl/evp.h>   
#include <openssl/sha.h>  
#include <string.h>
#include <stdlib.h>

void printHash(unsigned char *md, int len)  
{  
	int i = 0;  
	for (i = 0; i < len; i++)  
	{  
		printf("%02x", md[i]);  
	}  

	printf("\n");  
}  

int main( int argc, char *argv[])
{
	printf("%s\n", argv[1]);
	FILE *fp;
	fp = fopen(argv[1], "r");
	fseek(fp,0,SEEK_END);	
	long lSize = ftell(fp);
	char *orgStr;
	orgStr=(char*)malloc(lSize+1);
	rewind(fp); 
	fread(orgStr,sizeof(char),lSize,fp);
	orgStr[lSize] = '\0';

	unsigned char md[SHA512_DIGEST_LENGTH] = {0};
	EVP_Digest(orgStr, strlen(orgStr), md, NULL, EVP_sha512(), NULL);
	printHash(md, SHA512_DIGEST_LENGTH);  

	free(orgStr);
	return 0;
}
