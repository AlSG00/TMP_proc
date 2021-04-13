#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "../Container.h"
#include "../Container_Constr.cpp"
#include "../Container_In.cpp"
#include "../Container_Out.cpp"

#include "../Movie.h"
#include "../Movie_In.cpp"
#include "../Movie_Out.cpp"

#include "../Cartoon.h"
#include "../Cartoon_In.cpp"
#include "../Cartoon_Out.cpp"

#include "../Fiction.h"
#include "../Fiction_In.cpp"
#include "../Fiction_Out.cpp"

#include "../Documentary.h"
#include "../Documentary_In.cpp"
#include "../Documentary_Out.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		//Проверка функции In для контейнера на 7 элементов
		TEST_METHOD(ContainerInSeven)
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/InSeven.txt");
			Container c;
			Init(c);
			In(c, ifst);
			int actual = c.len;
			Assert::AreEqual(7, actual);
			Clear(c);
		}
		//Проверка функции In для пустого контейнера
		TEST_METHOD(ContainerInEmpty) 
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/InEmpty.txt");
			Container c;
			Init(c);
			In(c, ifst);
			int actual = c.len;
			Assert::AreEqual(0, actual);
			Clear(c);
		}
		//Проверка функции In для Movie с некорректными входными данными
		TEST_METHOD(MovieInCorrupted)
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/InCorruptedThree.txt");
			Container c;
			Init(c);
			In(c, ifst);
			int actual = c.len;
			Assert::AreEqual(2, actual);
			Clear(c);
		}
		//Проверка функции Sort для контейнера на 7 элементов
		TEST_METHOD(ContainerSortSeven) 
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/InSeven.txt"); 
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/Out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Sort(c); 
			Out(c, ofst);
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/Out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/OutSortedSevenSample.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); 
			Clear(c);
		}
		//Проверка функции Sort для пустого контейнера
		TEST_METHOD(ContainerSortEmpty) 
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/InEmpty.txt"); 
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/Out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Sort(c);
			Out(c, ofst);
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/Out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/OutSortedEmptySample.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual);
			Clear(c);
		}
		//Проверка функции Sort для контейнера с одним элементом
		TEST_METHOD(ContainerSortOne)
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/InSortOne.txt");
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/Out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Sort(c);
			Out(c, ofst);
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/Out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/OutSortedOneSample.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual);
			Clear(c);
		}
		//Проверка функции Sort для контейнера с двумя элементами
		TEST_METHOD(ContainerSortTwo) 
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/InTwo.txt");
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/Out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Sort(c); 
			Out(c, ofst);
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/Out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/OutSortedTwoSample.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual);
			Clear(c);
		}
		//Проверка функции OutCartoon для пустого контейнера
		TEST_METHOD(OutCartoonEmpty)
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/InEmpty.txt");
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/Out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			OutCartoon(c, ofst);
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/Out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/OutEmptySample.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual);
			Clear(c);
		}
		//Проверка функции OutCartoon контейнера без cartoons
		TEST_METHOD(ContainerWithoutCartoons) 
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/InWithoutCartoonsFive.txt");
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/Out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			OutCartoon(c, ofst);
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/Out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/outWithoutCartoonsSample.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual);
			Clear(c);
		}
		//Проверка функции InData на поведение в случае переполнения
		TEST_METHOD(MovieInDataOverbuf) 
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/InOverbufOne.txt");
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/Out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/Out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/OutOverbufOneSample.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual);
			Clear(c);
		}
		//Проверка функции VowelCount в случае 0 гласных
		TEST_METHOD(CountOfVowelEmpty) 
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/InVowelsEmpty.txt");
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/Out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/Out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/OutVowelsEmptySample.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual);
			Clear(c);
		}
		//Проверка функции VowelCount в случае 5 гласных
		TEST_METHOD(CountOfVowelFive) 
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/InVowelsFive.txt");
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/Out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/Out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/OutVowelsFiveSample.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual);
			Clear(c);
		}
		//Проверка очистки контейнера при отсутствии элементов
		TEST_METHOD(ClearEmptyContainer) 
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/InEmpty.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Clear(c);
			Assert::AreEqual(c.len, 0);
		}
	};
}
