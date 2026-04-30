#include "pch.h"
#include "CppUnitTest.h"
#include "../v6task1/task1.h"
#include "../v6task1/task1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTask1
{
	TEST_CLASS(UnitTestTask1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::list<int> lst = { 1, 2, 3, 4, 5 };
			removeEvenOrThrow(lst);
			std::list<int> expected = { 1, 3, 5 };
			Assert::IsTrue(lst == expected);
		}
	};
}
