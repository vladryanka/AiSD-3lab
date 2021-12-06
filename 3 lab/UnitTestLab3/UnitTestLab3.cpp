#include "pch.h"
#include "CppUnitTest.h"
#include "../3 lab.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab3
{
	TEST_CLASS(UnitTestLab3)
	{
	public:

		TEST_METHOD(ContainsFunction)
		{
			Tree lst;
			int array[] = { 16,6,20,2,12 };
			for (int i = 0; i < 5; i++)
			{
				lst.push_back(array[i]);
			}
			int temp = 0;
			for (int i = 0; i < 5; i++)
			{
				temp = lst.Contains(array[i]);
				Assert::IsTrue(temp == 1);
			}
		}
		TEST_METHOD(BFTFunction)
		{
			Tree lst;
			int array[7] = { 12,10,5,19,6,4,7 };
			for (int i = 0; i < 7; i++)
			{
				lst.push_back(array[i]);
			}
			int arraytest[] = { 12,10,19,5,4,6,7 };
			Iterator* lst_iterator = lst.create_BFT_iterator();
			int i = 0;
			int temp;
			while (lst_iterator->has_next())
			{
				temp = lst_iterator->next();
				Assert::IsTrue(temp == arraytest[i]);
				i++;
			}
		}
		TEST_METHOD(DFTFunction)
		{
			Tree lst;
			int array[7] = { 12,10,5,19,6,4,7 };
			for (int i = 0; i < 7; i++)
			{
				lst.push_back(array[i]);
			}
			int arraytest[] = { 12,10,5,4,6,7,19 };
			Iterator* lst_iterator = lst.create_DFT_iterator();
			int i = 0;
			int temp;
			while (lst_iterator->has_next())
			{
				temp = lst_iterator->next();
				Assert::IsTrue(temp == arraytest[i]);
				i++;
			}
		}
		TEST_METHOD(InsertFunction)
		{
			Tree lst;
			int array[5] = { 16,20,6,2,12 };
			for (int i = 0; i < 5; i++)
			{
				lst.push_back(array[i]);
			}
			int arraytest[] = { 16,6,20,2,12,14 };
			lst.insert(14);
			Iterator* lst_iterator = lst.create_BFT_iterator();
			int i = 0;
			int temp;
			for (int i = 0; i < 6; i++)
			{
				temp = lst_iterator->next();
				Assert::IsTrue(temp == arraytest[i]);
			}
		}
		TEST_METHOD(RemoveFunction)
		{
			Tree lst;
			int array[7] = { 16,20,6,2,12,11,13 };
			for (int i = 0; i < 7; i++)
			{
				lst.push_back(array[i]);
			}
			int arraytest[] = { 16,11,20,2,12,13 };
			lst.remove(6);
			Iterator* lst_iterator = lst.create_BFT_iterator();
			int i = 0;
			int temp;
			for (int i = 0; i < 6; i++)
			{
				temp = lst_iterator->next();
				Assert::IsTrue(temp == arraytest[i]);
			}
			int arraytest1[5] = {16,11,20,2,12};
			lst.remove(13);
			Iterator* lst_iterator1 = lst.create_BFT_iterator();
			for (int i = 0; i < 4; i++)
			{
				temp = lst_iterator1->next();
				Assert::IsTrue(temp == arraytest[i]);
			}
		}

	};
}
