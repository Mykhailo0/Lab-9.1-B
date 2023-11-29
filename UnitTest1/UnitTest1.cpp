#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 9.1 B/9.1 B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			const int N = 3;
			Student* students = new Student[N];


			students[0] = { "Ivanov", 5, 5, 1, КН, 5 };
			students[1] = { "Petrov", 4, 5, 1, ІНФ, 5 };
			students[2] = { "Sidorov", 5, 4, 1, МТЕ, 5 };

			Assert::AreEqual(0, Physics(students, N));
		}
	};
}
