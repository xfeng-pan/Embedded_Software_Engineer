////�����������������
//#include <iostream>
//using namespace std;
//
//class myPrint
//{
//public:
//	void operator()(string text)
//	{
//		cout << text << endl;
//	};
//};
//
//class myAdd
//{
//public:
//	int operator()(int a, int b)
//	{
//		return a + b;
//	}
//};
//
//void test01()
//{
//	myPrint print;
//	print("Hello world!");
//}
//
//void test02()
//{
//	myAdd add;
//	cout << "add(10,10) = " << add(10, 10) << endl;
//	cout << "myAdd()(20,20) = " << myAdd()(20, 20) << endl;
//}
//
//
//int main()
//{
//	test01();
//	test02();
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		m_Name = name;
//		m_Age = age;
//	}
//	bool operator==(Person& p)
//	{
//		if (m_Name == p.m_Name && m_Age == p.m_Age)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	bool operator!=(Person& p)
//	{
//		if (m_Name == p.m_Name && m_Age == p.m_Age)
//		{
//			return false;
//		}
//		else
//		{
//			return true;
//		}
//	}
//
//	string m_Name;
//	int m_Age;
//};
//
//
//void test01()
//{
//	Person p1("abc", 18);
//	Person p2("abd", 18);
//
//	if (p1 == p2)
//	{
//		cout << "p1��p2���" << endl;
//	}
//	else
//	{
//		cout << "p1��p2�����" << endl;
//	}
//	if (p1 != p2)
//	{
//		cout << "p1��p2�����" << endl;
//	}
//	else
//	{
//		cout << "p1��p2���" << endl;
//	}
//}
//
//int main()
//{
//	test01();
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//	Person(int age)
//	{
//		m_Age = new int(age);
//	}
//	~Person()
//	{
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//	}
//	Person& operator=(Person& p)
//	{
//		if (m_Age == NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//
//		m_Age = new int(*p.m_Age);
//
//		return *this;
//	}
//
//	int * m_Age;
//};
//
//void test01()
//{
//	Person p1(19);
//	
//	Person p2(20);
//
//	Person p3(30);
//
//	p3 = p2 = p1;
//
//	cout << "p1������Ϊ��" << *p1.m_Age << endl;
//	
//	cout << "p2������Ϊ��" << *p2.m_Age << endl;
//
//	cout << "p3������Ϊ��" << *p3.m_Age << endl;
//
//	int a = 10;
//	int b = 20;
//	int c = 30;
//
//	c = b = a;
//
//	cout << " a = " << a << endl;
//	cout << " b = " << b << endl;
//	cout << " c = " << c << endl;
//
//}
//
//int main()
//{
//	test01();
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class MyInteger
//{
//	friend ostream& operator<<(ostream& cout, MyInteger p);
//
//public:
//	MyInteger()
//	{
//		m_A = 0;
//	}
//	MyInteger(int a)
//	{
//		m_A = a;
//	}
//	//����ǰ��++�����
//	MyInteger& operator++()
//	{
//		m_A++;
//		return *this;
//	}
//
//	//���غ���++�������
//	MyInteger operator++(int)//int����ռλ��������������ǰ�úͺ���
//	{
//		//�ȼ�¼���
//		MyInteger temp = *this;
//		//�������
//		m_A++;
//		return temp;
//
//	}
//	//����ǰ��--�����
//	MyInteger& operator--()
//	{
//		m_A--;
//		return *this;
//	}
//	MyInteger operator--(int)
//	{
//		MyInteger temp = *this;
//		m_A--;
//		return temp;
//	}
//private:
//	int m_A;
//
//};
//
//ostream& operator<<(ostream & cout, MyInteger p)
//{
//	cout << p.m_A << endl;
//	return cout;
//}
//
//
//
//
//
//void test01()
//{
//	MyInteger myint(10);
//	cout << myint << endl;
//	cout << ++myint << endl;
//	cout << myint++ << endl;
//	cout << myint++ << endl;
//	cout << myint << endl;
//	cout << --myint << endl;
//	cout << --myint << endl;
//	cout << myint-- << endl;
//	cout << myint << endl;
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Person
//{
//	friend ostream& operator<<(ostream& cout, Person& p);
//	//friend void test01();
//public:
//	Person(int a, int b)
//	{
//		m_A = a;
//		m_B = b;
//	}
//	////���ó�Ա�������� 
//	//// �޷�ʵ��
//	//void operator<< (Person &p)
//	//{
//
//	//}
//private:
//	int m_A;
//	int m_B;
//
//};
//
//ostream & operator<<(ostream& cout, Person& p)
//{
//	cout << " m_A = " << p.m_A << endl;
//	cout << " m_B = " << p.m_B << endl;
//	return cout;
//}
//
//void test01()
//{
//	Person p1(10, 10);
//	//p1.m_A = 10;
//	//p1.m_B = 10;
//	cout << p1 <<"hello world " << endl;
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//
//}


//#include <iostream>
//using namespace std;
//
////�Ӻ����������
//class Person
//{
//public:
//	////1. ��Ա��������+��
//	//Person operator+(Person& p)
//	//{
//	//	Person tmp;
//	//	tmp.m_A = this->m_A + p.m_A;
//	//	tmp.m_B = this->m_B + p.m_B;
//	//	return tmp;
//	//}
//	//���ó�Ա�����������������
//
//public:
//	int m_A;
//	int m_B;
//};
//
////2. ȫ�ֺ�������+��
//Person operator+(Person& p1, Person& p2)
//{
//	Person tmp;
//	tmp.m_A = p1.m_A + p2.m_A;
//	tmp.m_B = p1.m_B + p2.m_B;
//	return tmp;
//}
//
////�������������
//
//
//void test01()
//{
//	Person p1;
//	p1.m_A = 10;
//	p1.m_B = 10;
//		
//	Person p2;
//	p2.m_A = 10;
//	p2.m_B = 10;
//
//	Person p3 = p1 + p2;
//	cout << p3.m_A << " " << p3.m_B << endl;
//}
//
//
//
//
//
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//
//}

//#include <iostream>
//using namespace std;
//#include <string>
//
//class Building;
//
//class goodGay
//{
//public:
//	goodGay();
//
//	void visit();
//	void visit2();
//
//	Building* building;
//};
//
//class Building
//{
//	friend void goodGay::visit2();
//
//public:
//	Building();
//public:
//	string m_SittingRoom;
//
//private:
//	string m_BedRoom;
//};
//
//Building::Building()
//{
//	m_SittingRoom = "sittingRoom";
//	m_BedRoom = "BedRoom";
//}
//
//goodGay::goodGay()
//{
//	building = new Building;
//}
//
//void goodGay::visit()
//{
//	cout << "visit " << building->m_SittingRoom << endl;
//	
//}
//void goodGay::visit2()
//{
//	cout << "visit " << building->m_SittingRoom << endl;
//	cout << "visit " << building->m_BedRoom << endl;
//}
//
//void test01()
//{
//	goodGay gg;
//	gg.visit();
//	gg.visit2();
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#include <string>
//
//class Building
//{
//	friend void goodGay(Building* buiding);
//public:
//	Building()
//	{
//		m_SittingRoom = "����";
//		m_BedRoom = "����";
//	}
//public:
//	string m_SittingRoom;
//
//private:
//	string m_BedRoom;
//};
//
//void goodGay(Building* buiding)
//{
//	cout << "ȫ�ֺ������ڷ��ʣ�" << buiding->m_SittingRoom << endl;
//	cout << "ȫ�ֺ������ڷ��ʣ�" << buiding->m_BedRoom << endl;
//}
//
//void test01()
//{
//	Building b;
//	goodGay(&b);
//}
//
//int main()
//{
//	
//	test01();
//
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//	//������
//	void showPerson() const //����������thisָ�룺 const Person * const this
//	{
//		//thisָ��ı��ʣ���ָ�볣����ָ���ָ���ǲ������޸ĵ�
//		//�൱�ڣ� Person * const this
//		//Ҫ��ָ��ָ���ֵҲ�������޸ģ�����Ҫд�ɣ�
//		//const Person * const this
//		//���վ������ڳ�Ա�����ĺ��棺
//		m_A = 100;// this->m_A = 100
//		//m_B = 100; 
//		cout << "showPerson: " << m_A << endl;
//	}
//	void agePerson()
//	{
//		int m_A = 50;
//	}
//
//public:
//	mutable int m_A;
//	int m_B;
//};
//
//void test01()
//{
//	Person p;
//	p.showPerson();
//}
//
//int main()
//{
//	// ������
//	//������ֻ�ܵ��ó�����
//	const Person p1;//�ڶ���ǰ�����const�������Ϊ������
//	p1.m_A = 100;
//	p1.showPerson();
//	//p.m_B = 100;
//	test01();
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
////��ָ����ó�Ա����
//class Person
//{
//public:
//	void showClassName()
//	{
//		cout << "this is class Person" << endl;
//	}
//	void showPersonAge()
//	{
//		cout << "age = " << m_Age << endl;
//	}
//
//public:
//	int m_Age;
//};
//
//void test01()
//{
//	Person* p = NULL;
//	p->showClassName();
//	//p->showPersonAge();
//}
//
//
//
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
////��Ա�����ͳ�Ա�����ֿ��洢�ģ�
//class Person
//{
//public:
//	int m_A;//�Ǿ�̬����������Ķ���
//	static int m_B;//��̬������������Ķ���
//	void func() {}//�Ǿ�̬��Ա������������Ķ���
//	static void func2() {}//��̬��Ա����Ҳ��������Ķ���
//
//};
//
//int Person::m_B = 4;
//
//void test01()
//{
//	Person p; 
//
//
//	//�ն���ռ���ڴ�ռ�Ϊ��1�ֽ�
//	//��Ϊc++������Ҳ���ÿ���ն������һ���ֽڵĿռ䣬��Ϊ�����ֿն���ռ���ڴ��λ�ã�
//	//ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ��
//
//	cout << "size of p = " << sizeof(p) << endl;
//
//}
//
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//	static void func1()
//	{
//
//		cout << "��̬����1" << endl;
//		m_A += 20;
//		cout << m_A << endl;
//	}
//
//	void func3()
//	{
//		cout << "����3" << endl;
//		func2();
//	}
//private:
//	static void func2()
//	{
//		cout << "��̬����2" << endl;
//		m_A += 20;
//		cout << m_A << endl;
//	}
//public:
//	static int m_A;
//	int m_B;
//};
//
//int Person::m_A = 10;
//
//void test()
//{
//	Person p;
//	cout << p.m_A << endl;
//	p.func1();
//	p.func3();
//	Person::func1();
//}
//
//
//int main()
//{
//	test();
//
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person ���캯��" << endl;
//	}
//	~Person()
//	{
//		cout << "Person ��������" << endl;
//	}
//
//public:
//	static int m_A;
//};
//
//int Person::m_A = 10;
//
//void test()
//{
//	cout << Person::m_A << endl;
//}
//
//int main()
//{
//	test();
//	Person p1;
//	cout << p1.m_A << endl;
//
//
//	system("pause");
//	return 0;
//}


//#include <iostream>
//using namespace std;
//#include <string>
//
//class Phone
//{
//public:
//	Phone(string name, int size):m_PhoneName(name) ,m_size(size)
//	{
//		//m_PhoneName = name;
//		cout << "phone ���ι��캯��" << endl;
//	}
//	~Phone()
//	{
//		cout << "phone ��������" << endl;
//	}
//
//public:
//	string m_PhoneName;
//	int m_size;
//};
//
//class Person
//{
//public:
//	Person(string name, string pname, int size):m_PersonName(name), m_phone(pname, size)
//	{
//		cout << "Person ���캯��" << endl;
//	}
//	~Person()
//	{
//		cout << "Person ��������" << endl;
//	}
//	void playGame()
//	{
//		cout << m_PersonName << "����" << m_phone.m_PhoneName << "�ֻ�����Ϸ:" <<m_phone.m_size << endl;
//	}
//public:
//	string m_PersonName;
//	Phone m_phone;
//};
//
//void test()
//{
//	Person p1("zhangsan", "pingguo", 6);
//	p1.playGame();
//}
//
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//	 
//}

//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//	//Person(int a, int b, int c)
//	//{
//	//	m_A = a;
//	//	m_B = b;
//	//	m_C = c;
//	//}
//	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c)
//	{
//
//	}
//
//public:
//	int m_A;
//	int m_B;
//	int m_C;
//};
//
//void test()
//{
//	Person p(20, 10, 5);
//	cout << "m_A = " << p.m_A << endl;
//	cout << "m_B = " << p.m_B << endl;
//	cout << "m_C = " << p.m_C << endl;
//}
//
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//
//}


//#include <iostream>
//using namespace std;
//
////���캯���ķ���͵���
////����
////	���ղ������ࣺ �޲ι��죨Ĭ�Ϲ��죩 �вι���
////	�������ͷ��ࣺ ��ͨ����	��������
//class Person
//{
//public:
//	int age;
//	//�޲ι��캯������ͨ���캯����
//	Person()
//	{
//		cout << "���캯���ĵ���" << endl;
//	}
//	//�вι��캯��
//	Person(int a)
//	{
//		age = a;
//		cout << "�вι��캯�� ����Ϊ:" << a << endl;
//	}
//	//�������캯��
//	Person(const Person &p)
//	{
//		age = p.age;
//		cout << "�������캯���ĵ���" << endl;
//
//	}
//
//
//	~Person()
//	{
//		cout << "���������ĵ���" << endl;
//	}
//};
//
////����
//void PersonTest()
//{
//	//���ŷ�
//	//Person p1;
//	//Person p2(10);
//	//Person p3(p2);
//
//	//��ʾ��
//	//Person p1;
//	//Person p2 = Person(10);
//	//Person p3 = Person(p2);
//	//Person(10) ��������:�ص㣬��ǰ��ִ�н�����ϵͳ�����̻��ոö���
//	//cout << "aaa" << endl;
//
//	//��ʽת����
//	Person p4 = 10;
//	Person p5 = p4;
//
//
//}
//
//int main()
//{
//	PersonTest();
//
//	system("pause");
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
////����ĳ�ʼ��������
////1 ���캯�������г�ʼ������
//class Person
//{
//	
//public:
//	//1.1 ���캯��
//	//û�з���ֵ������дvoid
//	//��������������ͬ
//	//���캯�������в��������Է������أ�
//	//���������ʱ�򣬹��캯�������Զ����ã�
//	//��д�Ļ�ϵͳ����п�ʵ�֣�
//	Person()
//	{
//		cout << "Person ���캯���ĵ���" << endl;
//	}
//	//�������� �����������
//	//û�з���ֵ����дvoid
//	//��������������ͬ��������ǰ���~
//	//���������������в��������ܷ�������
//	//��������ǰ��ϵͳ���Զ�������������������ֻ�����һ��
//	~Person()
//	{
//		cout << "Person ���������ĵ���" << endl;
//	}
//
//};
//
//void PersonTest()
//{
//	Person P1;//��ջ�����������ݣ���PersonTestִ����Ϻ�ϵͳ���Զ��ͷ��������
//}
//
//int main()
//{
//	PersonTest();
//	Person P;
//
//	system("pause");
//	return 0;
//}
//
//
