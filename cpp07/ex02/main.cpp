#include "Array.hpp"

#define MAX_VAL 750
int main(int argc, char** argv)
{
	std::cout << GREEN " ----- SUBJECT TESTS ----- " RESET << std::endl;
    Array<int> numbers(MAX_VAL);//instance of the class
    int* mirror = new int[MAX_VAL];//C-style array for comparison
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)//fills both with the same random values
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;//ASSIGNMENT OPERATOR
        Array<int> test(tmp);//COPY CONSTRUCTOR
    }//destructor should make sure it gets destroyed

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }//verify if after copying it kept the same values
    }
    try
    {
        numbers[-2] = 0;//tries to access invalid index
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }//SHOULD PRINT THE OUT OF RANGE EXCEPTION
    try
    {
        numbers[MAX_VAL] = 0;//invalid index
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }//SHOULD PRINT THE OUT OF RANGE EXCEPTION

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();//ensure the array is still usable
    }
    delete [] mirror;//

	std::cout << GREEN "\n ----- MY OWN TESTS ----- " RESET << std::endl;
	int *a = new int();
	//int *g = new int;
	std::cout << "a: " << *a << std::endl;
	//std::cout << "g: " << *g << std::endl;
	*a = 42;
	std::cout << "a: " << *a << std::endl;
	delete a;
	//delete g;
	
	char *end;
	if (argc != 2){
		std::cout << RED "Please input only one number" RESET << std::endl;
		return 1;
	}
	long input = strtol(argv[1], &end, 10);
	if (*end || input > INT_MAX || input < INT_MIN){
		std::cout << RED "Please input an integer" RESET << std::endl;
		return 1;
	}
	std::cout << GREEN "\nParameterized constructor test" RESET << std::endl;
	Array<int> b(input);
	for (unsigned int i = 0; i < b.size(); ++i)
		b[i] = i * 2;
	for (unsigned int i = 0; i < b.size(); ++i)
		std::cout << "b[" << i << "]: " << b[i] << std::endl;

	std::cout << GREEN "\nCopy constructor test" RESET << std::endl;
	Array<int> c(b);
	for (unsigned int i = 0; i < c.size(); ++i)
		std::cout << "c[" << i << "]: " << c[i] << std::endl;
	b[input - 1] = 0;//test deep copy
	std::cout << "b[input - 1] = " << b[input - 1] << "\nc[input - 1] = " << c[input - 1] << std::endl;

	std::cout << GREEN "\nAssignment operator test" RESET << std::endl;
	Array<int> d;
	d = c;
	for (unsigned int i = 0; i < d.size(); ++i)
		std::cout << "d[" << i << "]: " << d[i] << std::endl;

	std::cout << GREEN "\nOut of range test" RESET << std::endl;
	try {
		std::cout << b[input + 2] << std::endl;//is out of range, should throw an exception
	} catch (const std::out_of_range& e) {
		std::cerr << RED "Exception caught: " RESET << e.what() << std::endl;
	}

	std::cout << GREEN "\nConst test" RESET << std::endl;
	const Array<int> e = c;
	for (unsigned int i = 0; i < e.size(); ++i)
		std::cout << "e[" << i << "]: " << e[i] << std::endl;

	std::cout << GREEN "\nString array test" RESET <<std::endl;
	Array<std::string> f(5);
	f[0] = "Hello";
	f[1] = "World";
	f[2] = "C++";
	f[3] = "is awesome";
	for (int i = 0; i < 5; i++)
		std::cout << "f[" << i << "] = " << f[i] << std::endl;

    return 0;
}
