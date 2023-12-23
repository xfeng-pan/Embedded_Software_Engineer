//#include <iostream>
//using namespace std;
//
//class CPU
//{
//public:
//	virtual void calculate() = 0;
//};
//
//class GPU
//{
//public:
//	virtual void display() = 0;
//};
//
//class Mem
//{
//public:
//	virtual void stroge() = 0;
//};
//
//
//class Computer
//{
//public:
//	Computer(CPU* cpu, GPU* gpu, Mem* mem)
//	{
//		m_cpu = cpu;
//		m_gpu = gpu;
//		m_mem = mem;
//	}
//
//	~Computer()
//	{
//		if (m_cpu != NULL)
//		{
//			delete m_cpu;
//			m_cpu = NULL;
//		}
//		if (m_gpu != NULL)
//		{
//			delete m_gpu;
//			m_gpu = NULL;
//		}
//		if (m_mem != NULL)
//		{
//			delete m_mem;
//			m_mem = NULL;
//		}
//	}
//
//	void work()
//	{
//		m_cpu->calculate();
//		m_gpu->display();
//		m_mem->stroge();
//	}
//
//private:
//	CPU* m_cpu;
//	GPU* m_gpu;
//	Mem* m_mem;
//};
//
//class IntelCPU :public CPU
//{
//	virtual void calculate()
//	{
//		cout << "Intel CPU is calculating" << endl;
//	}
//};
//
//class IntelGPU :public GPU
//{
//	virtual void display()
//	{
//		cout << "Intel GPU is displaying" << endl;
//	}
//};
//
//class IntelMem :public Mem
//{
//	virtual void stroge()
//	{
//		cout << "Intel Mem is storging" << endl;
//	}
//};
//
//class AMDCPU :public CPU
//{
//	virtual void calculate()
//	{
//		cout << "AMD CPU is calculating" << endl;
//	}
//};
//
//class AMDGPU :public GPU
//{
//	virtual void display()
//	{
//		cout << "AMD GPU is displaying" << endl;
//	}
//};
//
//class AMDMem :public Mem
//{
//	virtual void stroge()
//	{
//		cout << "AMD Mem is storging" << endl;
//	}
//};
//
//
//
//void test01()
//{
//	CPU* intel_cpu = new IntelCPU;
//	GPU* intel_gpu = new IntelGPU;
//	Mem* intel_mem = new IntelMem;
//
//	Computer* computer1 = new Computer(intel_cpu, intel_gpu, intel_mem);
//	computer1->work();
//	delete computer1;
//	cout << "***************************************************************" << endl;
//
//	CPU* amd_cpu = new AMDCPU;
//	GPU* amd_gpu = new AMDGPU;
//	Mem* amd_mem = new AMDMem;
//	Computer* computer2 = new Computer(amd_cpu, amd_gpu, amd_mem);
//	computer2->work();
//	delete computer2;
//	cout << "***************************************************************" << endl;
//
//	Computer* computer3 = new Computer(new AMDCPU, new IntelGPU, new IntelMem);
//	computer3->work();
//	delete computer3;
//
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
//
//#include <string>
//
//class Animal
//{
//public:
//	Animal()
//	{
//		cout << "Animal 构造函数调用" << endl;
//	}
//	/*virtual ~Animal()
//	{
//		cout << "Animal 析构函数调用" << endl;
//	}*/
//
//	virtual ~Animal() = 0;
//
//
//	virtual void Speaking() = 0;
//};
//
//Animal::~Animal()
//{
//	cout << "Animal 纯虚析构函数调用" << endl;
//}
//
//class Cat :public Animal
//{
//public:
//	Cat(string name)
//	{
//		cout << "Cat 构造函数调用" << endl;
//		m_Name = new string(name);
//	}
//	~Cat()
//	{
//		if (m_Name != NULL)
//		{
//			cout << "Cat 析构函数调用" << endl;
//			delete m_Name;
//			m_Name = NULL;
//		}
//	}
//
//
//	virtual void Speaking()
//	{
//		cout << *m_Name <<  " cat is speaking " << endl;
//	}
//
//	string *m_Name;
//};
//
//void test01()
//{
//	Animal* animal = new Cat("Tom");
//	animal->Speaking();
//	delete animal;
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
//class AbstractDrink
//{
//public:
//	virtual void Biol() = 0;
//	virtual void Brew() = 0;
//	virtual void PourInCup() = 0;
//	virtual void PutSomething() = 0;
//
//	void makeDrink()
//	{
//		Biol();
//		Brew();
//		PourInCup();
//		PutSomething();
//	}
//};
//
//class Coffee :public AbstractDrink
//{
//	virtual void Biol()
//	{
//		cout << " biol coffee" << endl;
//	}
//
//	virtual void Brew()
//	{
//		cout << " Brew coffee" << endl;
//	}
//	virtual void PourInCup()
//	{
//		cout << " Pour in cup" << endl;
//	}
//	virtual void PutSomething()
//	{
//		cout << " put sugar" << endl;
//	}
//};
//
//class Tea :public AbstractDrink
//{
//	virtual void Biol()
//	{
//		cout << " biol Tea" << endl;
//	}
//
//	virtual void Brew()
//	{
//		cout << " Brew Tea" << endl;
//	}
//	virtual void PourInCup()
//	{
//		cout << " Pour in Tea" << endl;
//	}
//	virtual void PutSomething()
//	{
//		cout << " put tea" << endl;
//	}
//};
//
//void doWork(AbstractDrink* abs)
//{
//	abs->makeDrink();
//}
//
//void test01()
//{
//	Coffee c;
//	Tea t;
//	c.makeDrink();
//	t.makeDrink();
//	cout << "***************************************" << endl;
//	Coffee c2;
//	doWork(&c2);
//
//	cout << "***************************************" << endl;
//	Tea* c3 = new Tea;
//	doWork(c3);
//
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
//	virtual void func() = 0;
//	void func2()
//	{
//
//	}
//};
//
//
//class Son :public Base
//{
//public:
//	virtual void func()
//	{
//		cout << "func() 调用 " << endl;
//	}
//};
//
//void test01()
//{
//	//Base b;
//	//new Base;
//	Son ss;
//	ss.func();
//}
//
//int main()
//{
//	test01();
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
////普通写法 实现计算器
//class Calculator
//{
//public:
//	int getResult(string oper)
//	{
//		if (oper == "+")
//		{
//			return m_Num1 + m_Num2;
//		}
//		if (oper == "-")
//		{
//			return m_Num1 - m_Num2;
//		}
//		if (oper == "*")
//		{
//			return m_Num1 * m_Num2;
//		}
//	}
//
//
//	int m_Num1;
//	int m_Num2;
//};
//
//
//void test01()
//{
//	//
//	Calculator c;
//	c.m_Num1 = 10;
//	c.m_Num2 = 10;
//
//	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
//
//	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
//	
//	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
//}
////多态写法 实现计算器
////实现计算器抽象类
//class AbstractCalculator
//{
//public:
//	virtual int getResult()
//	{
//		return 0;
//	}
//	
//	int m_Num1;
//	int m_Num2;
//
//};
//
//class AddCalculator : public AbstractCalculator
//{
//	virtual int getResult()
//	{
//		return m_Num1 + m_Num2;
//	}
//};
//class SubCalculator : public AbstractCalculator
//{
//	virtual int getResult()
//	{
//		return m_Num1 - m_Num2;
//	}
//};
//
//class MultiCalculator : public AbstractCalculator
//{
//	virtual int getResult()
//	{
//		return m_Num1 * m_Num2;
//	}
//};
//
//
//void test02()
//{
//	AbstractCalculator* abc = new AddCalculator;
//	abc->m_Num1 = 100;
//	abc->m_Num2 = 10;
//
//	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
//	delete abc;
//
//	abc = new SubCalculator;
//	abc->m_Num1 = 100;
//	abc->m_Num2 = 10;
//
//	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
//	delete abc;
//
//
//	abc = new MultiCalculator;
//	abc->m_Num1 = 100;
//	abc->m_Num2 = 10;
//
//	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
//	delete abc;
//
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
//
//
//class Animal
//{
//public:
//	void speak()
//	{
//		cout << " is speaking" << endl;
//	}
//};
//
//class Cat :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "miao miao miao ~ " << endl;
//	}
//};
//
//class Dog :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "wang wang wang " << endl;
//	}
//};
//
//void doSpeak(Animal &animal)
//{
//	animal.speak();
//}
//
//void test01()
//{
//	Cat cat;
//	doSpeak(cat);
//	Dog dog;
//	doSpeak(dog);
//}
//
//void test02()
//{
//	cout << "sizeof(Animal) = " << sizeof(Animal) << endl;
//}
//
//int main()
//{
//	//test01();
//	test02();
//	return 0;
//}