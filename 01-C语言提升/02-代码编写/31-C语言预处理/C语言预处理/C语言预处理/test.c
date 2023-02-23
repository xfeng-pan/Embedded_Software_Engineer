#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int i = 0;
	int arr[10] = { 0 };
	FILE* pf = fopen("log.txt", "w");
	if (pf == NULL)
	{
		perror("fopen:");
		return 0;
	}
	for (i = 0; i < 10; i++)
	{
		arr[i] = i;
		fprintf(pf,"file:%s line:%d date:%s time:%s i=%d\n", 
			__FILE__, __LINE__, __DATE__, __TIME__, i);
	}
	fclose(pf);
	pf = NULL;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("%s\n", __FUNCTION__);
	return 0;
}


//int main()
//{
//	//Ô¤¶¨Òå·ûºÅ
//	printf("%s\n", __FILE__);
//	printf("%d\n", __LINE__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//	//printf("%s\n", __STDC__);
//
//	return 0;
//}









//
//#include <stdio.h>
//#include "add.h"












//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("%d\n", add(1, 3));
//	
//	return 0;
//}

















