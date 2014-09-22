// main.cpp : 定义控制台应用程序的入口点。
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "qh_string.h"
using namespace qh;

int main()
{
	string s;
	printf("=========\n\nstring s:\ns's length:%lu\n", s.size());
	printf("s:%s\n", s.c_str());

	char m[] = "123456";
	string s0(m, 6);
	printf("=========\n\nstring s0(m, 6)：\ns0's length:%lu\n", s0.size());
	printf("s0：%s\n", s0.c_str());
	printf("s0[0]：%c\n", s0[1]);

	char p[] = "ksdfldkdk";
	string s1(p);
	printf("=========\n\nstring s1(p):\ns1's length:%lu\n", s1.size());
	printf("s1:%s\n", s1.c_str());
	printf("s1[1]:%c\n", s1[1]);

	string s2(s1);
	printf("=========\n\nstring s2(s1):\ns2's length:%lu\n", s2.size());
	printf("s2:%s\n", s2.c_str());
	printf("s2[1]:%c\n", s2[1]);

	s2 = s0;
	printf("=========\n\ns2 = s0:\ns2's length%lu\n", s2.size());
	printf("s2:%s\n", s2.c_str());
	printf("s2[1]:%c\n", s2[1]);

	string s3 = s2;
	printf("=========\n\nstring s3 = s2:\ns3's length:%lu\n", s3.size());
	printf("s3:%s\n", s3.c_str());
	printf("s3[1]%c\n", s3[1]);

	string s4("jsdfhjdfk");
	printf("=========\n\n\nstring s4(\"jsdfhjdfk\"):\ns4's length%lu\n", s4.size());
	printf("s4:%s\n", s4.c_str());
	printf("s4[1]%c\n", s4[1]);

	for(int i = 0; i < 9; ++i) s4[i] = '0';
	printf("=========\n\nfor(int i = 0; i < 9; ++i) s4[i] = '0':\ns4's length:%lu\n", s4.size());
	printf("s4:%s\n", s4.c_str());
	printf("s4[1]:%c\n", s4[1]);

	string s5("");
	printf("=========\n\nstring s5(\"\"):\ns5's length:%lu\n", s5.size());
	printf("s5:%s\n", s5.c_str());

	string s6 = "";
	printf("=========\n\nstring s6 = \"\":\ns6's length:%lu\n", s6.size());
	printf("s6: %s\n", s6.c_str());

	s6 = "dsfgdsfgdf";
	printf("=========\n\ns6 = \"dsfgdsfgdf\":\ns6's length:%lu\n", s6.size());
	printf("s6:%s\n", s6.c_str());

	string s7 = "ksdfjksflkfj";
	printf("=========\n\nstring s7 = \"ksdfjksflkfj\":\ns7's length:%lu\n", s7.size());
	printf("s7:%s\n", s7.c_str());
	printf("s7[1]:%c\n", s7[1]);

	string s8 = s7 + s6;
	printf("=========\n\ns7.c_str():%s\n", s7.c_str());
	printf("s6.c_str():%s\n", s6.c_str());
	printf("s8 = s7 + s6:\nss13.size():%lu\n", s8.size());
	printf("s8.c_str():%s\n", s8.c_str());
	printf("s8[1]:%c\n", s8[1]);

	string s9 = "";
	string s10 = "";
	string s11 = "sjkfhhfdjhk";

	string s12 = s9 + s10;
	printf("=========\n\ns9.c_str():%s\n", s9.c_str());
	printf("s10.c_str():%s\n", s10.c_str());
	printf("s12 = s9 + s10:\nss12.size():%lu\n", s12.size());
	printf("s12.c_str():%s\n", s12.c_str());

	string s13 = s9 + s11;
	printf("=========\n\ns9.c_str():%s\n", s9.c_str());
	printf("s11.c_str():%s\n", s11.c_str());
	printf("s13 = s9 + s11:\nss13.size():%lu\n", s13.size());
	printf("s13.c_str():%s\n", s13.c_str());
	printf("s13[1]:%c\n", s13[1]);

	string s14 = s11 + s10;
	printf("=========\n\ns11.c_str():%s\n", s11.c_str());
	printf("s10.c_str():%s\n", s10.c_str());
	printf("s14 = s11 + s10:\nss14.size():%lu\n", s14.size());
	printf("s14.c_str():%s\n", s14.c_str());
	printf("s14[1]:%c\n", s14[1]);


	printf("\nbase address:%p\n", s14.data());
	s14.reserve(10);
	printf("\nafter s14.reserve(10):");
	printf("\nnew address:%p\n", s14.data());
	s14.reserve(10000);
	printf("\nafter s14.reserve(10000):");
	printf("\nchanged address:%p\n", s14.data());

	//printf("s14[1]：%c\n", s14[100]);

	
#ifdef WIN32
    system("pause");
#endif

	return 0;
}

