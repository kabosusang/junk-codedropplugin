#pragma once

//我们要填充的特征码
void codecompare(char code[])
{
	char attcode1_c[] = { 0xa9,0x00,0x00,0x00,0x00 };//test eax,0x00
	char attcode2_c[] = { 0x33,0x30 };				//xor eax,eax
	char attcode3_c[] = { 0xb8,0x00,0x00,0x00 };    //mov eax,0x00
	char attcode4_c[] = { 0x3B,0x30 };				//cmp eax,eax
	char attcode5_c[] = { 0 };
	char attcode6_c[] = { 0 };
	char attcode7_c[] = { 0 };
	char attcode8_c[] = { 0 };
	char attcode9_c[] = { 0 };

	char attcode1_jcc[] = { 0x74 };//je 短跳
	char attcode2_jcc[] = { 0x75 };
	char attcode3_jcc[] = { 0 };
	char attcode4_jcc[] = { 0 };
	char attcode5_jcc[] = { 0 };
	char attcode6_jcc[] = { 0 };
	char attcode7_jcc[] = { 0 };
	char attcode8_jcc[] = { 0 };
	char attcode9_jcc[] = { 0 };
	char attcode10_jcc[] = { 0 };
	char attcode11_jcc[] = { 0 };


	char* attribute_code[] = { attcode1_c };


}