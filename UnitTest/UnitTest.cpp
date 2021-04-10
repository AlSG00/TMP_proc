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

		TEST_METHOD(Container_In_7) //Проверка функции In для контейнера
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_7.txt");
			Container c;
			Init(c);
			In(c, ifst);
			int actual = c.len;
			Assert::AreEqual(7, actual);//OK
			Clear(c);
		}
		TEST_METHOD(Container_In_0) //Проверка функции In для контейнера
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_0.txt"); //В файле пусто
			Container c;
			Init(c);
			In(c, ifst);
			int actual = c.len;
			Assert::AreEqual(0, actual);//OK
			Clear(c);
		}
		TEST_METHOD(Movie_In_3) //Проверка функции In для Movie
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_3_with_incorrect_keys.txt");
			Container c;
			Init(c);
			In(c, ifst);
			int actual = c.len;
			Assert::AreEqual(2, actual);//OK
			Clear(c);
		}
		TEST_METHOD(Container_Sort_7) //Проверка функции Sort для контейнера
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_7.txt"); //В файле 7 фильмов
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Sort(c); // ОК, сортировка прошла как обычно
			Out(c, ofst);
			//тут сравнение двух файлов
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/out_7_SORTED.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			Clear(c);
		}
		TEST_METHOD(Container_Sort_0) //Проверка функции Sort для пустого контейнера
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_0.txt"); //В файле пусто
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Sort(c); //OK, сортировка не произошла
			Out(c, ofst); //В выходном файле "Container contents 0 elements."
			//тут сравнение двух файлов
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/out_0_SORTED.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			Clear(c);
		}
		TEST_METHOD(Container_Sort_1) //Проверка функции Sort для контейнера с одним элементом
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_1.txt"); //В файле один элемент
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Sort(c);  //OK, сортировка не произошла
			Out(c, ofst); //В выходном файле "Container contents 1 elements."
			//тут сравнение двух файлов
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/out_1_SORTED.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			Clear(c);
		}
		TEST_METHOD(Container_Sort_2) //Проверка функции Sort для контейнера с двумя элементами
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_2.txt"); //В файле два элемента
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Sort(c);  //OK, сортировка ведет себя адекватно 
			Out(c, ofst); //В выходном файле "Container contents 2 elements."

			//тут сравнение двух файлов
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/out_2_SORTED.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			Clear(c);
		}
		TEST_METHOD(Container_OutCartoon_0) //Проверка функции OutCartoon для пустого контейнера
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_0.txt"); //В файле пусто
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			OutCartoon(c, ofst); //В выходном файле "Only cartoons."
			//тут сравнение двух файлов
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/out_0_IDEAL.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			Clear(c);
		}
		TEST_METHOD(Container_OutCartoon_without_cartoons) //Проверка функции OutCartoon контейнера без cartoons
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_5_without_cartoons.txt"); //В файле 5 фильмов
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			OutCartoon(c, ofst); //В выходном файле "Only cartoons."
			//тут сравнение двух файлов
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/out_5_without_cartoons_IDEAL.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			Clear(c);
		}
		TEST_METHOD(Movie_InData_OverBuf) //Проверка функции InData на поведение в случае переполнения
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_1_overbuf.txt"); //В файле один cartoon с выражением > 50 символов
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			//тут сравнение двух файлов
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/out_1_overbuf_IDEAL.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			Clear(c);
		}
		TEST_METHOD(Movie_CountOfVowel_0) //Проверка функции VowelCount в случае 0 гласных
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_0_vowels.txt"); //В выражении нет гласных
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			//тут сравнение двух файлов
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/out_0_vowels_IDEAL.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			Clear(c);
		}
		TEST_METHOD(Movie_CountOfVowel_5) //Проверка функции VowelCount в случае 5 гласных
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_5_vowels.txt"); //В выражении 5 гласных
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			//тут сравнение двух файлов
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/out_5_vowels_IDEAL.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			Clear(c);
		}
		TEST_METHOD(Container_Clean_0) //Проверка очистки контейнера при отсутствии элементов
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_0.txt"); //В файле пусто
			Container c;
			Init(c);
			In(c, ifst);
			Clear(c);//OK, цикл не начинался
			Assert::AreEqual(c.len, 0); //OK
		}
	};
}
