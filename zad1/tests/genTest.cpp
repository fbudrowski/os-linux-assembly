#include<byteswap.h>
#include<stdio.h>


int main(){
	int testNo; scanf("%d", &testNo);
	char fileName[20];
	if (testNo > 0) sprintf(fileName, "test%d.0", testNo);
	else sprintf(fileName, "test%d.1", -testNo);
	FILE* ptr = fopen(fileName, "wb");
	if (testNo == -2){
		for (int i = 1; i < 100; i++){
			int j = bswap_32(i);
			fwrite(&j, sizeof(j), 1, ptr);
		}
	}
	if (testNo == 2){
		int k = bswap_32((1<<30));
		for(int i = 0; i < 3; i++) fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32((1<<30) - (6 + 8 + 0 + 2 + 0));
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(6);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(8);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(0);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(2);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(0);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(1);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(68019);
		fwrite(&k, sizeof(k), 1, ptr);
	}
	
	if (testNo == -3){
		int k = bswap_32((1<<30));
		for(int i = 0; i < 3; i++) fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32((1<<30) - (6 + 8 + 0 + 2 + 0));
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(6);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(8);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(0);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(2);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(0);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(0);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(68020);
		fwrite(&k, sizeof(k), 1, ptr);
	}

	if (testNo == 3){
		int k = bswap_32(68021);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(6);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(8);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(6);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(6);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(8);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(0);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(2);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(0);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(0);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(-37);
		fwrite(&k, sizeof(k), 1, ptr);
	}

	if (testNo == -4){
		int k = bswap_32(68020);
		fwrite(&k, sizeof(k), 1, ptr);
	}

	if (testNo == 4){
		int k = bswap_32(6);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(8);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(0);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(2);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(0);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(-13);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(68019);
		fwrite(&k, sizeof(k), 1, ptr);
		k = bswap_32(~0U >> 1);
		for(int i = 0; i < 2; i++) fwrite(&k, sizeof(k), 1, ptr);
	}

	fclose(ptr);
	return 0;
}

