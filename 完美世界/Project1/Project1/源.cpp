#include<iostream>
//#include<iostream>
//#include<exception>
//
//int x = 0;
//class A{
//public:
//	A(){
//		std::cout << 'a';
//		if (x++ == 0){
//			throw std::exception();
//
//		}
//	}
//	~A(){ std::cout << 'A'; }
//};
//class B{
//public:
//	B(){ std::cout << 'b'; }
//	~B(){ std::cout << 'B'; }
//};
//
//void foo(){ static B b; }
//int main()
//{
//	try{
//		foo();
//	}
//	catch (std::exception &){
//		std::cout << 'c';
//		foo();
//	}
//}

//#include<iostream>
//int f(int &a, int &b){
//	int a = 5;
//	int b = 9;
//	return a + b;
//}
//int main()
//{
//	int a = 2;
//	int b = 7;
//	int c = f(a, a);
//		std::cout << a << b << c;
//}
//char* hello(){
//	char buf[] = "hello";
//	return buf;
//}
//
//
//int main()
//{
//	printf("%s", hello());
//	return 0;
//}
//int main()
//{
//	int a = 1;
//	(a++) += a;
//	a += (++a);
//	(++a) += (a++);
//	a += (a++);
//}
int main()
{
	int input;
	std::cin >> input;
	int result = input - 2;
	for (int i = input - 2; i > 1; i--){
		result = result*(i - 1);
	}
	std::cout << result*input;
	return 0;
}
