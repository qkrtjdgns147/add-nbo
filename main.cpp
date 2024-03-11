#include <fstream>
#include <iostream>
#include <string>
#include <stdint.h>
#include <cstdlib>
#include <cstring>
#include <stdio.h>


using namespace std;

int main(int argc, char* argv[]) {
	
	//open file on file pointer
	FILE* fp1 = fopen(argv[1], "rb");	
	FILE* fp2 = fopen(argv[2], "rb");

	//error : input number & name is not matched
	if (argc != 3) {
		printf("Type 2 files to read");
		return 0;
	}
	if (fp1 == NULL || fp2 == NULL){
		printf("Wrong file name.");
		return 0;
	}

	//read files
	unsigned char ch1[4] = {0};
	unsigned char ch2[4] = {0};
	fread(ch1,4,1,fp1);
	fread(ch2,4,1,fp2);

	//error : file size is less than 4bytes
	fseek(fp1,0,SEEK_END);
	fseek(fp2,0,SEEK_END);

	long file_size1 = ftell(fp1);
	long file_size2 = ftell(fp2);

	if(file_size1 < 4 || file_size2 < 4) {
		printf("file size is less than 4bytes");
		return 0;
	}
	
	//do calculate
	uint32_t o1, o2;
	o1 = (uint32_t) ch1[0] << 24 |
		(uint32_t) ch1[1] << 16 |
		(uint32_t) ch1[2] << 8 |
	       (uint32_t) ch1[3];

	o2 = (uint32_t) ch2[0] << 24 |
		(uint32_t) ch2[1] << 16 |
		(uint32_t) ch2[2] << 8 |
	       (uint32_t) ch2[3];

	uint32_t sum = o1 + o2;
	printf("%d(ox%x) + %d(ox%x) = %d(ox%x)", o1,o1,o2,o2,sum,sum);



	return 0;
}
