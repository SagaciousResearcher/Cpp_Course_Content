/*

Author :
DR. FERDIN SAGAI DON BOSCO
------------------------------------------------------
About Code:

This code covers the following C++ feature -
1. TEMPLATES
Templates are the foundation of generic programming. They are independent of any type
	a. Function Templates
	b. Class Templates
------------------------------------------------------
Theory:

Functions and Classes in C++ are written with a specific data type in mind.
Thus, they are restricted to operate using that data type only.
Templates address this issue by making the function/class generic.
The simple idea is to pass data type as a parameter.
We don�t need to write the same code for different data types.

Function Templates -
For instance
	int add(int a, int b) {return a+b;}
is a function that can only accept two integer arguments and returns an interger response.
This data type restriction is overcome to some extent by overloading the function
	int add(int a, int b) {return a+b;}
	float add(float a, float b) {return a+b;}
While this type of polymorphism works, it extends the number of lines in the code since each datatype requires am implementation


Class Templates -
A Class template is useful if we have multiple classes that perform are similar in all aspects except the datatype of their members.
This would necesstiate the definition of multiple classes, which can be avoided using templates.
For instance, in the creation of a stack

------------------------------------------------------
Key Points:
Templates are expanded at compiler time, wery much like macros.
The difference is, that the compiler does type checking before template expansion.
The idea is simple, source code contains only function/class.
But compiled code may contain multiple copies of the same function/class.

------------------------------------------------------
*/
//===============================================================================
//===============================================================================
//===============================================================================

// Primitive Implementation without Templates
#include<iostream>
int add(int a, int b) { return a + b; }
float add(float a, float b) { return a + b; }
void demo_primitive_function_overloading()
{
	int a{ 1 }, b{ 3 };
	float c{ 1.029f }, d{ 5.2389f };

	std::cout << "Addition of two integers is :: " << add(a, b) << std::endl;
	std::cout << "Addition of two float is :: " << add(c, d) << std::endl;
}


// Improved Implementation with Templates
template <typename datatype>
datatype add_template(datatype a, datatype b) { return a + b; }

template <typename datatype1, typename datatype2>
datatype1 subtract(datatype1 a, datatype2 b) { return a - b; }

void demo_function_templates()
{
	int a{ 1 }, b{ 3 };
	float c{ 1.029f }, d{ 5.2389f };
	std::cout << "Addition of two integers is :: " << add_template<int>(a, b) << std::endl;
	std::cout << "Addition of two float is :: " << add_template<float>(c, d) << std::endl;
	// Mixed addition is also possible with a different template definition that operates using 2 datatypes
	std::cout << "Subtraction of float-int is :: " << subtract<float, int>(d, a) << std::endl;
}

//===============================================================================
//===============================================================================
//===============================================================================

// Primitive Implementation without Templates
class StudentPerformance
{
public:
	char name;
	char performace_index; // grade of student (A, B, C, D, F)
};

class CarPerformance
{
public:
	char name;
	float performace_index; // Mileage of car 
};

void demo_primitive_classes()
{
	StudentPerformance student;
	CarPerformance car;

	student.name = 'X';
	student.performace_index = 'A';
	car.name = 'B';
	car.performace_index = 31.5;

	std::cout << "Performance of Student" << std::endl;
	std::cout << "\t Name :: " << student.name << std::endl;
	std::cout << "\t Grade :: " << student.performace_index << std::endl;

	std::cout << "Performance of Car" << std::endl;
	std::cout << "\t Name :: " << car.name << std::endl;
	std::cout << "\t Mileage :: " << car.performace_index << std::endl;
}

// Improved Implementation with Templates
template<typename T, typename U>
class Performance
{
public:
	T name;
	U performace_index;
};

void demo_class_templates()
{
	Performance<char, char> student;
	Performance<char, float> car;

	student.name = 'X';
	student.performace_index = 'A';
	car.name = 'B';
	car.performace_index = 31.5;

	std::cout << "Performance of Student" << std::endl;
	std::cout << "\t Name :: " << student.name << std::endl;
	std::cout << "\t Grade :: " << student.performace_index << std::endl;

	std::cout << "Performance of Car" << std::endl;
	std::cout << "\t Name :: " << car.name << std::endl;
	std::cout << "\t Mileage :: " << car.performace_index << std::endl;

	return;
}

int main()
{
	std::cout << "================ FUNCTION OVERLOADING ================" << std::endl;
	demo_primitive_function_overloading();

	std::cout << "\n================ FUNCTION TEMPLATES ===================" << std::endl;
	demo_function_templates();

	std::cout << "\n================ PRIMITIVE CLASSES ====================" << std::endl;
	demo_primitive_classes();

	std::cout << "\n================ CLASS TEMPLATES ======================" << std::endl;
	demo_class_templates();

	return 0;
}