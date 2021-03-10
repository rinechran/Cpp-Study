#include <iostream>

using namespace std;

void first() {
	std::cout << "first" << std::endl;
}

template <typename T ,typename ...AS>
void two(T &func,AS && ...as) {
	first();
	func(as...);
	//std::cout << as...;
	
}
void k(int a) {
	std::cout << "k" << std::endl;
}

void c() {
	std::cout << "c" << std::endl;
}
void b(int a,int b) {
	std::cout << "b" << std::endl;
}

void print() {

}

template <typename T, typename ...AS>
void print(T type, AS&& ...as) {
	std::cout << type << std::endl;
	print(as...);
}

int main()
{
	two(b,10,20);
	two(k, 10);
	print(3, 4, 5, 5, 6, 7, 7, 7, "asdas");
}