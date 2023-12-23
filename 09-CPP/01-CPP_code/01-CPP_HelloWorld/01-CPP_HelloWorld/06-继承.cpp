//#include <iostream>
//using namespace std;
//
//class Animal
//{
//public:
//	int m_Age;
//
//};
//
//class Sheep :virtual public Animal
//{
//};
//
//class Tuo :virtual public Animal
//{
//};
//
//class SheepTuo :public Sheep, public Tuo
//{
//
//};
//
//void test01()
//{
//	SheepTuo st;
//	st.Sheep::m_Age = 18;
//	st.Tuo::m_Age = 28;
//
//	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
//	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
//	cout << "st.m_Age = " << st.m_Age << endl;
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
//class Base1
//{
//public:
//	Base1()
//	{
//		m_A = 100;
//	}
//	int m_A;
//};
//
//class Base2
//{
//public:
//	Base2()
//	{
//		m_B = 200;
//	}
//	int m_B;
//};
//
//class Son :public Base1, public Base2
//{
//public:
//	Son()
//	{
//		m_C = 300;
//		m_D = 400;
//	}
//	int m_C;
//	int m_D;
//};
//
//void test01()
//{
//	Son s;
//
//	cout << "sizeof(Son) = " << sizeof(s) << endl;
//
//}
//
//int main()
//{
//	test01();
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//class Base
//{
//public:
//	static int m_A;
//	static void func()
//	{
//		cout << "Base-static func()" << endl;
//	}
//};
//
//int Base::m_A = 100;
//
//class Son :public Base
//{
//public:
//	static int m_A;
//	static void func()
//	{
//		cout << "Son-static func()" << endl;
//	}
//};
//int Son::m_A = 200;
//
//void test01()
//{
//	Son s;
//	cout << "通过对象访问" << endl;
//	cout << "s.m_A = " << s.m_A << endl;
//	cout << "s.Base::m_A = " << s.Base:: m_A << endl;
//
//	cout << "通过类名访问" << endl;
//	cout << "Son::m_A = " << Son::m_A << endl;
//	cout << "Base::m_A = " << Base::m_A << endl;
//	cout << "Son::Base::m_A = " << Son::Base::m_A << endl;
//
//}
//
//void test02()
//{
//	Son s;
//	s.func();
//	s.Base::func();
//	Son::func();
//	Base::func();
//	Son::Base::func();
//
//}
//int main()
//{
//	test01();
//	test02();
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//class Base
//{
//public:
//	Base()
//	{
//		m_A = 100;
//	}
//
//	void func()
//	{
//		cout << "Base - func 函数调用" << endl;
//	}
//
//	void func(int a)
//	{
//		cout << "Base - func(int a) 函数调用" << endl;
//	}
//public:
//	int m_A;
//};
//
//class Son :public Base
//{
//public:
//	Son()
//	{
//		m_A = 200;
//	}
//	void func()
//	{
//		cout << "Son - func 函数调用" << endl;
//	}
//public:
//	int m_A;
//};
//
//void test01(void)
//{
//	Son s;
//	cout << "m_A = " << s.m_A << endl;
//	cout << "s.Base::m_A = " << s.Base::m_A << endl;
//}
//
//void test02()
//{
//	Son s;
//	s.func();
//	s.Base::func();
//	s.Base::func(100);
//}
//
//int main()
//{
//	test01();
//	test02();
//	return 0;
//}



//#include<iostream>
//using namespace std;

//class Base
//{
//public:
//	Base()
//	{
//		m_A = 100;
//	}
//	void func()
//	{
//		cout << "Base-func()" << endl;
//	}
//	int m_A;
//};
//
//class Son : public Base
//{
//public:
//	Son()
//	{
//		m_A = 200;
//	}
//	void func()
//	{
//		cout << "Son-func()" << endl;
//	}
//	int m_A;
//};
//
//void test01()
//{
//	Son s1;
//	cout << s1.Base::m_A << endl;
//	cout << s1.m_A << endl;
//}
//
//void test02()
//{
//	Son s2;
//	s2.Base::func();
//	s2.func();
//}
//
//int main()
//{
//	test01();
//	test02();
//	return  0;
//}

//#include <iostream>
//using namespace std;
//
//class Base
//{
//public:
//	Base()
//	{
//		cout << "Base构造函数" << endl;
//	}
//	~Base()
//	{
//		cout << "Base析构函数" << endl;
//	}
//};
//
//class Son :public Base
//{
//public:
//	Son()
//	{
//		cout << "Son构造函数" << endl;
//	}
//	~Son()
//	{
//		cout << "Son析构函数" << endl;
//	}
//};
//
//void test01()
//{
//	Son s1;
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
//class Base
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//
//class Son :public Base
//{
//public:
//	int m_D;
//};
//
//void test01()
//{
//	cout << "sizeof(Base) = " << sizeof(Base) << endl;
//	//在父类种的所有非静态成员属性都会被子类继承下去；
//	//父类中私有成员是被编译器隐藏了；
//	//但是私有成员确实是被继承了；
//	cout << "Sizeof(Son) = " << sizeof(Son) << endl;
//}
//
//
//int main()
//{
//	test01();
//	return 0;
//}

////继承方式
//#include <iostream>
//using namespace std;
//
//class Base1
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//
//class Son1 :public Base1
//{
//public:
//	void func()
//	{
//		m_A = 10;
//		m_B = 10;
//	}
//};
//
//class Son2 : protected Base1
//{
//public:
//	void func()
//	{
//		m_A = 10;
//		m_B = 10;
//	}
//};
//
//class Son3 :private Base1
//{
//public:
//	void func()
//	{
//		m_A = 10;
//		m_B = 10;
//		//m_C = 10;
//	}
//};
//
//class GrandSon3 :public Son3
//{
//public:
//	void func()
//	{
//		//m_A = 10;
//	}
//};
//
//void test01()
//{
//	Son1 s1;
//	s1.m_A = 10;
//	//s1.m_B = 10;
//	s1.func();
//
//	Son2 s2;
//	//s2.m_A = 10;
//	//s2.m_B = 10;
//	s2.func();
//
//	Son3 s3;
//	//s3.m_A = 10;
//	//s3.m_B = 10;
//	//s3.m_C = 10;
//	s3.func();
//
//
//
//}
//
//int main()
//{
//	test01();
//	return 0;
//}


//// 继承
//#include <iostream>
//using namespace std;
//
//
//class BasePage
//{
//public:
//	void header()
//	{
//		cout << "首页，公共课，登陆，注册......（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心，交流合作，站内地图......（公共底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Jave, Python, C++ ......（公共分类列表）" << endl;
//	}
//};
//
//class Java: public BasePage
//{
//public:
//	void content()
//	{
//		cout << "Java学科视频" << endl;
//	}
//};
//
//class Python : public BasePage
//{
//public:
//	void content()
//	{
//		cout << "Python学科视频" << endl;
//	}
//};
//
//class CPP : public BasePage
//{
//public:
//	void content()
//	{
//		cout << "CPP学科视频" << endl;
//	}
//};
//
//void test01()
//{
//	//Java 学科页面
//	cout << "Java学科页面" << endl;
//	Java java;
//	java.header();
//	java.left();
//	java.content();
//	java.footer();
//	cout << "---------------------------------------------------" << endl;
//
//	//Python 学科页面
//	cout << "Python学科页面" << endl;
//	Python py;
//	py.header();
//	py.left();
//	py.content();
//	py.footer();
//	cout << "---------------------------------------------------" << endl;
//
//	//CPP 学科页面
//	cout << "CPP学科页面" << endl;
//	CPP cpp;
//	cpp.header();
//	cpp.left();
//	cpp.content();
//	cpp.footer();
//	cout << "---------------------------------------------------" << endl;
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


