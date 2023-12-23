//案例2：英雄排序


////结构体案例1：毕设数据统计
//#include <iostream>
//using namespace std;
//#include<string>
//#include <ctime>
//
//struct Student
//{
//	string name;
//	int score;
//};
//
//struct Teacher
//{
//	string name;
//	struct Student sArray[5];
//};
//
////给老师和学生赋值
//void allocateSpace(struct Teacher* tArray, int len)
//{
//	string NameSeed = "ABCDE";
//
//	for (int i = 0; i < len; i++)
//	{
//		tArray[i].name = "Teacher_";
//		tArray[i].name += NameSeed[i];
//
//		for (int j = 0; j < 5; j++)
//		{
//			tArray[i].sArray[j].name = "Student_";
//			tArray[i].sArray[j].name += NameSeed[j];
//
//			tArray[i].sArray[j].score = rand()%101;
//
//		}
//	}
//
//}
//
//void PrintInfo(struct Teacher* tArray, int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		cout << "老师姓名：" << tArray[i].name << endl;
//		for (int j = 0; j < 5; j++)
//		{
//			cout << "\t学生姓名：" << tArray[i].sArray[j].name;
//			cout << "\t学生分数：" << tArray[i].sArray[j].score << endl;
//		}
//	}
//
//}
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//
//	//创建数组空间
//	struct Teacher tArray[3];
//
//	//给老师和学生赋值
//	allocateSpace(tArray, sizeof(tArray) / sizeof(tArray[0]));
//
//	//打印所有信息
//	PrintInfo(tArray, sizeof(tArray) / sizeof(tArray[0]));
//}


////结构体
//#include <iostream>
//using namespace std;
//
//struct student
//{
//	string name;
//	int age;
//	int score;
//};
//
//int main()
//{
//	student stu1 = { "stu1", 18, 90 };
//	
//	cout << stu1.name << " " << stu1.age << " " << stu1.score << endl;
//
//	system("pause");
//	return 0;
//}


////冒泡排序函数写法
//#include <iostream>
//using namespace std;
//
//void BubleSort(int* arr, int len)
//{
//	for (int i = 0; i < len - 1; i++)
//	{
//		for (int j = 0; j < len - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//	return;
//}
//
//void ArrayPrint(int* arr, int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int arr[] = { 2, 3, 5, 4, 1, 9, 8, 0, 6, 7 };
//	ArrayPrint(arr, sizeof(arr) / sizeof(arr[0]));
//	BubleSort(arr, sizeof(arr) / sizeof(arr[0]));
//	ArrayPrint(arr, sizeof(arr) / sizeof(arr[0]));
//
//	system("pause");
//	return 0;
//}








////二维数组及字符串使用
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int score[3][3] =
//	{
//		{90, 84, 92},
//		{92, 82, 87},
//		{91, 88, 79}
//	};
//	string name[3] = { "同学1", "同学2", "同学3" };
//
//	for (int i = 0; i < 3; i++)
//	{
//		int sum = 0;
//		for (int j = 0; j < 3; j++)
//		{
//			sum += score[i][j];
//		}
//		cout << name[i] << "的总成绩为：" << sum << "分" << endl;
//	}
//	system("pause");
//	return 0;
//}


////冒泡排序
//#include <iostream>
//using namespace std;
//#define N 10
//int main()
//{
//	int arr[N] = { 2, 1, 0, 3, 5, 4, 6, 9, 8 , 7 };
//	for (int index = 0; index < N; index++)
//	{
//		cout << arr[index] << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < N - 1; i++)
//	{
//		for (int j = 0; j < N - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//	for (int index = 0; index < N; index++)
//	{
//		cout << arr[index] << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int arr[5] = { 1, 3, 2, 5, 4 };
//	int head = 0; 
//	int tail = 4;
//	while (head < tail)
//	{
//		int tmp = arr[head];
//		arr[head] = arr[tail];
//		arr[tail] = tmp;
//		head++;
//		tail--;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int arr[5] = { 300, 350, 200, 400, 250 };
//	int index = 0;
//	int weight = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		if (arr[i] > weight)
//		{
//			index = i;
//			weight = arr[i];
//		}
//	}
//	cout << "第" << index << "只小猪最重" << endl;
//	cout << "重量为" << weight << "kg" << endl;
//
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int arr[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	cout << arr << endl;
//	cout << sizeof(arr) << endl;
//	cout << sizeof(arr) / sizeof(arr[0]) << endl;
//
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#define row 9
//#define column 9
//
//int main()
//{
//	for (int i = 1; i <= row; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			cout << j << " x " << i << " = " << i * j << "\t";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#define row 10
//#define column 10
//
//int main()
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < column; j++)
//		{
//			cout << "* ";
//		}
//		cout << endl;
//	}
//
//	system("pause");
//	return 0;
//	
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	for (int i = 1; i <= 100; i++)
//	{
//		if (i % 7 == 0 || i / 10 == 7 || i % 10 == 7)
//		{
//			cout << "敲桌子" << endl;
//		}
//		else
//		{
//			cout << i << endl;
//		}
//	}
//
//	system("pause");
//	return 0;
//}

////案例：水仙花数
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int num = 100;
//
//	do
//	{
//		int a = num % 10;
//		int b = num / 10 % 10;
//		int c = num / 100 % 10;
//		if (a * a * a + b * b * b + c * c * c == num)
//		{
//			cout << num << endl;
//		}
//		num++;
//	} while (num < 1000);
//
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int num = 0;
//	do
//	{
//		cout << num << endl;
//		num++;
//	} while (num < 10);
//
//	system("pause");
//	return 0;
//}


//#include <iostream>
//using namespace std;
//#include <ctime>
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//
//	int num = rand() % 100 + 1;
//	//cout << num << endl;
//
//	int val = 0;
//	cout << "请猜数字" << endl;
//	while (val != num)
//	{
//		cin >> val;
//		if (val == num)
//		{
//			cout << "num = " << val << endl;
//		}
//		else if (val < num)
//		{
//			cout << " 猜小了" << endl;
//		}
//		else if (val > num)
//		{
//			cout << "猜大了" << endl;
//		}
//	}
//
//
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int i = 10;
//
//	while (i > 0)
//	{
//		cout << " i == " << i << endl;
//		i--;
//	}
//
//	system("pause");
//	return 0;
//
//}


