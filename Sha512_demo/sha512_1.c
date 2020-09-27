#include<stdio.h>
#include<string.h>
#include<openssl/evp.h>

#define SHA512_BYTES 64

static char filename[]="./test1";
//static char filename[]="./test2";
//static char filename[]="./test3";




int main(int argc, char* argv[])
{

	FILE *fp;
	char JsonStr[2048] = {0};
	char *sp = NULL;
	long FileSize;
	int Len;

	if((fp = fopen(filename, "rb+")) == NULL)
	{
		perror("fopen file");
		exit (1);
	}

	fseek(fp, 0, SEEK_END);
	FileSize = ftell(fp);
	rewind(fp);

	sp = (char *)malloc(sizeof(char)*FileSize);

	fread(sp, 1, FileSize, fp);
	
	sp[FlieSize] = '\0';

	strncpy(JsonStr, sp, strlen(sp));

	printf("sp: %s, S_Len: %d, JsonStr: %s,JsonStrLen: %ld\n", sp,Len = strlen(sp), JsonStr, strlen(JsonStr));


     /*局部字符串测试*/
	//	char String[]="123456";	
     
	 /*终端命令测试*/
	/*
	   if (argc != 2) {

	   fprintf(stderr, "Usage: %s string\n", argv[0]);

	   exit(1);

	   }
	 */

	EVP_MD_CTX* ctx = EVP_MD_CTX_new();


	if (ctx == NULL) {

		fprintf(stderr, "Failed to initialize context\n");

		exit(2);

	}


	if (EVP_DigestInit(ctx, EVP_sha512())) {

		//		if (EVP_DigestUpdate(ctx, (void*)argv[1], strlen(argv[1]))) 
		if (EVP_DigestUpdate(ctx, (void*)JsonStr, strlen(JsonStr))) 
		{

			unsigned char buffer[SHA512_BYTES];

			int i;

			if (EVP_DigestFinal_ex(ctx, buffer, NULL)) {

				for(i = 0; i < SHA512_BYTES; i++) {

					printf("%02x", buffer[i]);

				}

				EVP_MD_CTX_free(ctx);

				exit(0);

			}

		}

	}

	fprintf(stderr, "Some error happened while calculating the digest\n");

	EVP_MD_CTX_free(ctx);

	exit(3);

}
