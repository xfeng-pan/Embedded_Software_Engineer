#include <stdio.h>

int main()
{
	short age = 20;
	float weight = 95.6;
	//sizeof���ص���64λ���޷������ͣ����ռλ����%lld
	printf("char:%lld\n", sizeof(char)); //1
	printf("short:%lld\n", sizeof(short)); //2
	printf("int:%lld\n", sizeof(int)); //4
	printf("long:%lld\n", sizeof(long)); //4
	printf("long long:%lld\n", sizeof(long long)); //8
	printf("float:%lld\n", sizeof(float)); //4
	printf("double:%lld\n", sizeof(double)); //8
	printf("weight:%.3f\n", weight);
	return 0;
}