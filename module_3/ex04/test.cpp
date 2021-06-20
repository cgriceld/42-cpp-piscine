// #include <iostream>
// using namespace std;
// class A
// {
// 	public:
// 		A() : _i(1) {cout << "a def\n"; cout << _i;};
// 		A(int i) {cout << "a i\n"; _i = i; cout << _i;};
// 		int _i;
// };

// class B : virtual public A
// {
// 	public:
// 		B() : A(7) {cout << "b def\n"; cout << _i;};
// };

// class C : public B
// {
// 	public:
// 		C() : A(6) {cout << "c def\n"; cout << _i;};
// };

// int main(void)
// {
// 	C c;
// 	return (0);
// }