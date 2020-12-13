#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 11.1/lab 11.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest111
{
	TEST_CLASS(UnitTest111)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		
			ifstream stream("t.txt");
			int count = 0;
			char* FileName = 0;
			if (stream.is_open())
			{
				count = averageEven(FileName);
				stream.close();
			}
			Assert::AreEqual(count, 0);
		}
	};
}
