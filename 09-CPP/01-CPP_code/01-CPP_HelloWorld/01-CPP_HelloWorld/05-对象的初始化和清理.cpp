////函数调用运算符重载
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
//		cout << "p1和p2相等" << endl;
//	}
//	else
//	{
//		cout << "p1和p2不相等" << endl;
//	}
//	if (p1 != p2)
//	{
//		cout << "p1和p2不相等" << endl;
//	}
//	else
//	{
//		cout << "p1和p2相等" << endl;
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
//	cout << "p1的年龄为：" << *p1.m_Age << endl;
//	
//	cout << "p2的年龄为：" << *p2.m_Age << endl;
//
//	cout << "p3的年龄为：" << *p3.m_Age << endl;
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
//	//重载前置++运算符
//	MyInteger& operator++()
//	{
//		m_A++;
//		return *this;
//	}
//
//	//重载后置++运算符；
//	MyInteger operator++(int)//int代表占位参数，用于区分前置和后置
//	{
//		//先记录结果
//		MyInteger temp = *this;
//		//后递增；
//		m_A++;
//		return temp;
//
//	}
//	//重载前置--运算符
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
//	////利用成员函数重载 
//	//// 无法实现
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
////加号运算符重载
//class Person
//{
//public:
//	////1. 成员函数重载+号
//	//Person operator+(Person& p)
//	//{
//	//	Person tmp;
//	//	tmp.m_A = this->m_A + p.m_A;
//	//	tmp.m_B = this->m_B + p.m_B;
//	//	return tmp;
//	//}
//	//利用成员函数重载左移运算符
//
//public:
//	int m_A;
//	int m_B;
//};
//
////2. 全局函数重载+号
//Person operator+(Person& p1, Person& p2)
//{
//	Person tmp;
//	tmp.m_A = p1.m_A + p2.m_A;
//	tmp.m_B = p1.m_B + p2.m_B;
//	return tmp;
//}
//
////左移运算符重载
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
//		m_SittingRoom = "客厅";
//		m_BedRoom = "卧室";
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
//	cout << "全局函数正在访问：" << buiding->m_SittingRoom << endl;
//	cout << "全局函数正在访问：" << buiding->m_BedRoom << endl;
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
//	//常函数
//	void showPerson() const //本质是修饰this指针： const Person * const this
//	{
//		//this指针的本质：是指针常量，指针的指向是不可以修改的
//		//相当于： Person * const this
//		//要让指针指向的值也不可以修改，则需要写成：
//		//const Person * const this
//		//最终决定加在成员函数的后面：
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
//	// 常对象
//	//常对象只能调用常函数
//	const Person p1;//在对象前面加上const，对象变为常对象
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
////空指针调用成员函数
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
////成员变量和成员函数分开存储的；
//class Person
//{
//public:
//	int m_A;//非静态变量属于类的对象
//	static int m_B;//静态变量不属于类的对象
//	void func() {}//非静态成员函数不属于类的对象；
//	static void func2() {}//静态成员函数也不属于类的对象
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
//	//空对象占用内存空间为：1字节
//	//因为c++编译器也会给每个空对象分配一个字节的空间，是为了区分空对象占用内存的位置；
//	//每个空对象也应该有一个独一无二的内存地址；
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
//		cout << "静态函数1" << endl;
//		m_A += 20;
//		cout << m_A << endl;
//	}
//
//	void func3()
//	{
//		cout << "函数3" << endl;
//		func2();
//	}
//private:
//	static void func2()
//	{
//		cout << "静态函数2" << endl;
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
//		cout << "Person 构造函数" << endl;
//	}
//	~Person()
//	{
//		cout << "Person 析构函数" << endl;
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
//		cout << "phone 含参构造函数" << endl;
//	}
//	~Phone()
//	{
//		cout << "phone 析构函数" << endl;
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
//		cout << "Person 构造函数" << endl;
//	}
//	~Person()
//	{
//		cout << "Person 析构函数" << endl;
//	}
//	void playGame()
//	{
//		cout << m_PersonName << "在用" << m_phone.m_PhoneName << "手机玩游戏:" <<m_phone.m_size << endl;
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
////构造函数的分类和调用
////分类
////	按照参数分类： 无参构造（默认构造） 有参构造
////	按照类型分类： 普通构造	拷贝构造
//class Person
//{
//public:
//	int age;
//	//无参构造函数（普通构造函数）
//	Person()
//	{
//		cout << "构造函数的调用" << endl;
//	}
//	//有参构造函数
//	Person(int a)
//	{
//		age = a;
//		cout << "有参构造函数 参数为:" << a << endl;
//	}
//	//拷贝构造函数
//	Person(const Person &p)
//	{
//		age = p.age;
//		cout << "拷贝构造函数的调用" << endl;
//
//	}
//
//
//	~Person()
//	{
//		cout << "析构函数的调用" << endl;
//	}
//};
//
////调用
//void PersonTest()
//{
//	//括号法
//	//Person p1;
//	//Person p2(10);
//	//Person p3(p2);
//
//	//显示法
//	//Person p1;
//	//Person p2 = Person(10);
//	//Person p3 = Person(p2);
//	//Person(10) 匿名对象:特点，当前行执行结束后，系统对立刻回收该对象；
//	//cout << "aaa" << endl;
//
//	//隐式转换法
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
////对象的初始化和清理
////1 构造函数：进行初始化操作
//class Person
//{
//	
//public:
//	//1.1 构造函数
//	//没有返回值，不用写void
//	//函数名与类名相同
//	//构造函数可以有参数，可以发生重载；
//	//创建对象的时候，构造函数可以自动调用；
//	//不写的话系统会进行空实现；
//	Person()
//	{
//		cout << "Person 构造函数的调用" << endl;
//	}
//	//析构函数 进行清理操作
//	//没有返回值，不写void
//	//函数名与类名相同，在名称前面加~
//	//析构函数不可以有参数，不能发生重载
//	//对象销毁前，系统会自动调用析构函数，而且只会调用一次
//	~Person()
//	{
//		cout << "Person 析构函数的调用" << endl;
//	}
//
//};
//
//void PersonTest()
//{
//	Person P1;//在栈区创建的数据，在PersonTest执行完毕后，系统会自动释放这个对象；
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
