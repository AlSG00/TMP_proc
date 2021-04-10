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

int Difference(ifstream& ifst_1, ifstream& ifst_2);

namespace TestLab4proc
{
	TEST_CLASS(TestLab4proc)
	{
	public:

		TEST_METHOD(Container_In_7) //�������� ������� In ��� ����������
		{
			ifstream ifst("in_7.txt"); //� ����� 7 ���������
			Container c;
			Init(c);
			In(c, ifst);
			int real_len = c.len;
			Assert::AreEqual(real_len, 7);//OK
			Clear(c);
		}
		TEST_METHOD(Container_In_0) //�������� ������� In ��� ����������
		{
			ifstream ifst("in_0.txt"); //� ����� �����
			Container c;
			Init(c);
			In(c, ifst);
			int real_len = c.len;
			Assert::AreEqual(real_len, 0);//OK
			Clear(c);
		}
		TEST_METHOD(Wisdom_In_7) //�������� ������� In ��� ������ wisdom
		{
			ifstream ifst("in_7_with_incorrect_keys.txt"); //� ����� 7 ���������, 3 �������� � ������������� �������
			Container c;
			Init(c);
			In(c, ifst);
			int real_len = c.len;
			Assert::AreEqual(real_len, 4);//OK
			Clear(c);
		}
		TEST_METHOD(Container_Sort_7) //�������� ������� Sort ��� ����������
		{
			ifstream ifst("in_7.txt"); //� ����� 7 ���������
			ofstream ofst("out_7.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Sort(c); // ��, ���������� ������ ��� ������
			Out(c, ofst);
			int real_len = c.len;
			Assert::AreEqual(real_len, 7); //OK
			Clear(c);
		}
		TEST_METHOD(Container_Sort_0) //�������� ������� Sort ��� ������� ����������
		{
			ifstream ifst("in_0.txt"); //� ����� �����
			ofstream ofst("out_0.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Sort(c); //OK, ���������� �� ���������
			Out(c, ofst); //� �������� ����� "Container contents 0 elements."
			int real_len = c.len;
			Assert::AreEqual(real_len, 0); //OK
			Clear(c);
		}
		TEST_METHOD(Container_Sort_1) //�������� ������� Sort ��� ���������� � ����� ���������
		{
			ifstream ifst("in_1.txt"); //� ����� ���� �������
			ofstream ofst("out_1.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Sort(c);  //OK, ���������� �� ���������
			Out(c, ofst); //� �������� ����� "Container contents 1 elements."
			int real_len = c.len;
			Assert::AreEqual(real_len, 1); //OK
			Clear(c);
		}
		TEST_METHOD(Container_Sort_2) //�������� ������� Sort ��� ���������� � ����� ����������
		{
			ifstream ifst("in_2.txt"); //� ����� ��� ��������
			ofstream ofst("out_2.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Sort(c);  //OK, ���������� ����� ���� ��������� 
			Out(c, ofst); //� �������� ����� "Container contents 2 elements."
			int real_len = c.len;
			Assert::AreEqual(real_len, 2); //OK
			Clear(c);
		}
		TEST_METHOD(Container_OutAphorisms_0) //�������� ������� OutAphorisms ��� ������� ����������
		{
			ifstream ifst("in_0.txt"); //� ����� �����
			ofstream ofst("out_0.txt");
			Container c;
			Init(c);
			In(c, ifst);
			OutCartoon(c, ofst); //� �������� ����� "Only aphorisms."
			int real_len = c.len;
			Assert::AreEqual(real_len, 0); //OK
			Clear(c);
		}
		TEST_METHOD(Container_OutAphorisms_without_aphors) //�������� ������� OutAphorisms ���������� ��� ���������
		{
			ifstream ifst("in_5_without_aphors.txt"); //� ����� 5 ���������
			ofstream ofst("out_5_without_aphors.txt");
			Container c;
			Init(c);
			In(c, ifst);
			OutCartoon(c, ofst); //� �������� ����� "Only aphorisms."
			int real_len = c.len;
			Assert::AreEqual(real_len, 5); //OK
			Clear(c);
		}
		TEST_METHOD(Wisdom_InData_OverBuf) //�������� ������� InData �� ��������� � ������ ������������
		{
			ifstream ifst("in_1_overbuf.txt"); //� ����� ���� ������� � ���������� > 100 ��������
			ofstream ofst("out_1_overbuf.txt");
			ifstream ifst_IDEAL("in_1_overbuf_IDEAL.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			//��� ��������� ���� ������
			ifstream ifst_to_cmp("out_1_overbuf.txt");
			Assert::AreEqual(Difference(ifst_to_cmp, ifst_IDEAL), 1); //OK
			Clear(c);
		}
		TEST_METHOD(Wisdom_CountOfComma_0) //�������� ������� CountOfComma � ������ 0 �������
		{
			ifstream ifst("in_0_commas.txt"); //� ��������� ��� �������
			ofstream ofst("out_0_commas.txt");
			ifstream ifst_IDEAL("out_0_commas_IDEAL.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			//��� ��������� ���� ������
			ifstream ifst_to_cmp("out_0_commas.txt");
			Assert::AreEqual(Difference(ifst_to_cmp, ifst_IDEAL), 1); //OK
			Clear(c);
		}
		TEST_METHOD(Wisdom_CountOfComma_1) //�������� ������� CountOfComma � ������ 1 �������
		{
			ifstream ifst("in_1_comma.txt"); //� ��������� 1 �������
			ofstream ofst("out_1_comma.txt");
			ifstream ifst_IDEAL("out_1_comma_IDEAL.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			//��� ��������� ���� ������
			ifstream ifst_to_cmp("out_1_comma.txt");
			Assert::AreEqual(Difference(ifst_to_cmp, ifst_IDEAL), 1); //OK
			Clear(c);
		}
		TEST_METHOD(Wisdom_CountOfComma_5) //�������� ������� CountOfComma � ������ 5 �������
		{
			ifstream ifst("in_5_commas.txt"); //� ��������� 5 �������
			ofstream ofst("out_5_commas.txt");
			ifstream ifst_IDEAL("out_5_commas_IDEAL.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			//��� ��������� ���� ������
			ifstream ifst_to_cmp("out_5_commas.txt");
			Assert::AreEqual(Difference(ifst_to_cmp, ifst_IDEAL), 1); //OK
			Clear(c);
		}
		TEST_METHOD(Container_Clean_0) //�������� ������� ���������� ��� ���������� ���������
		{
			ifstream ifst("in_0.txt"); //� ����� �����
			Container c;
			Init(c);
			In(c, ifst);
			Clear(c);//OK, ���� �� ���������
			Assert::AreEqual(c.len, 0); //OK
		}
	};
}

int Difference(ifstream& ifst_1, ifstream& ifst_2)
{
	char ch_1 = '0';
	char ch_2 = '0';

	while (ifst_1.get(ch_1) && ifst_2.get(ch_2)) {
		if (ch_1 != ch_2)
		{
			return 0;
		}
	}
	return 1;
}
