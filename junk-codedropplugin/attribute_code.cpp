#pragma once
#include"pch.h"

//ָ��Ӳ����  ���԰��ո�ʽ���������
char attcode1_c[] = { 0xa9,0x00,0x00,0x00,0x00 };//test eax,0x00
char attcode2_c[] = { 0x33,0x30 };				//xor eax,eax
char attcode3_c[] = { 0xb8,0x00,0x00,0x00 };    //mov eax,0x00
char attcode4_c[] = { 0x3B,0x30 };				//cmp eax,eax
char attcode5_c[] = { 0 };
char attcode6_c[] = { 0 };
char attcode7_c[] = { 0 };
char attcode8_c[] = { 0 };
char attcode9_c[] = { 0 };
//jccӲ����
char attcode1_jcc[] = { 0x74 };//je ����eaxΪ0��ת
char attcode2_jcc[] = { 0x75 };//jnz ����eax��Ϊ0��ת
char attcode3_jcc[] = { 0 };
char attcode4_jcc[] = { 0 };
char attcode5_jcc[] = { 0 };
char attcode6_jcc[] = { 0 };
char attcode7_jcc[] = { 0 };
char attcode8_jcc[] = { 0 };
char attcode9_jcc[] = { 0 };
char attcode10_jcc[] = { 0 };
char attcode11_jcc[] = { 0 };

char codecompare(char code1[], ulong add1)
{

	//test eax,0x0
	//je
	// ---
	int j = 0;
	int i = 0;
	if (code1[j] = attcode1_c[j])
	{

		for (int i = 1; i < sizeof(attcode1_c); i++)
		{
			if (code1[i] = attcode1_c[i])
			{
				continue;
			}
			if (i == sizeof(attcode1_c) + 1)
			{
				return 1;
			}


			break;
		}

	}

	//xor eax,eax
//je
//--
//je
//jnz
//--
//mov eax,0x00
//je
//--
//cmp eax,eax
//je

	return 0;
}
void NExtcompare(char code2[], ulong add2)
{
	if (code2[0] = attcode1_jcc[0])
	{
		//�����������log���ڵ�ֵ

		_Addtolist(add2, 1, (char*)"�õ�ַ���ƻ�ָ��");

		//�����Զ�ȥ�� �Ѻ���ת�����nop��
	}





}