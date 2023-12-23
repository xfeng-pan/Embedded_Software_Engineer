#include <iostream>
using namespace std;
#include <fstream>

class Person
{
public:
	char m_Name[64];
	int m_Age;
};


void test01()
{
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	while (!ifs.is_open())
	{
		cout << "file open failed" << endl;
		return;
	}
	Person p;
	ifs.read((char*)&p, sizeof(p));
	cout << "m_Name: " << p.m_Name << endl;
	cout << "m_Age: " << p.m_Age << endl;
	ifs.close();

}


int main()
{

	test01();
	return 0;
}

//#include <iostream>
//using namespace std;
//#include <fstream>
//#include <string>
//
//class Person
//{
//public:
//	char m_Name[64];
//	int m_Age;
//};
//
//
//void test01()
//{
//	ofstream ofs;
//	ofs.open("person.txt", ios::out | ios::binary);
//	Person p = { "Ashe",18 };
//	ofs.write((const char*)&p, sizeof(Person));
//	ofs.close();
//}
//
//int main()
//{
//
//	test01();
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#include <fstream>
//#include <string>
//
//void test01()
//{
//	ifstream ifs;
//	ifs.open("test.txt", ios::in);
//
//	if (!ifs.is_open())
//	{
//		cout << "file open failed!" << endl;
//		return;
//	}
//
//	//第一种
//	/*char buf[1024] = { 0 };
//	while (ifs >> buf)
//	{
//		cout << buf << endl;
//	}*/
//
//	//第二种
//	//char buf[1024] = { 0 };
//	//while (ifs.getline(buf, sizeof(buf)))
//	//{
//	//	cout << buf << endl;
//	//}
//
//	//第三种
//	//string buf;
//	//while (getline(ifs, buf))
//	//{
//	//	cout << buf << endl;
//	//}
//	//ifs.close();
//
//	//第四种
//	char c;
//	while ((c = ifs.get()) != EOF)
//	{
//		cout << c;
//	}
//}
//
//int main()
//{
//	test01();
//	return 0;
//}


//#include<iostream>
//using namespace std;
//#include<fstream>
//
//
//void test01()
//{
//	ofstream ofs;
//	ofs.open("test.txt", ios::out);
//	ofs << "name: xxxx" << endl;
//	ofs << "age: ?????" << endl;
//	ofs << "XXXX: XXXX" << endl;
//
//	ofs.close();
//}
//
// 
//int main()
//{
//	test01();
//	return 0;
//}


