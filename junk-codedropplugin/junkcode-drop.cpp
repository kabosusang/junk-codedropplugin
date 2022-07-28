#include"pch.h"



//======================================���뵼���ĺ���=======================================================


extern "C" __declspec(dllexport) cdecl int ODBG_Plugindata(char* shortname)
{
	const char* pluginName = "��ָ��ȥ�����";
	strcpy_s(shortname, strlen(pluginName) + 1, pluginName);
	return PLUGIN_VERSION;
}

//OD��������
HWND g_hOllyDbg;
// Method:�����ʼ���������жϵ�ǰOD�汾�źͲ����֧�ֵİ汾�Ƿ�һ��
// Description:����ĵ������� 
//************************************
extern "C" __declspec(dllexport) cdecl int ODBG_Plugininit(int ollydbgversion, HWND hw, ulong * features)
{

	if (ollydbgversion != PLUGIN_VERSION)
	{
		MessageBox(hw, "�������֧�ֵ�ǰ�汾OD!", "MyFirstPlugin", MB_ICONERROR);
		return -1;
	}
	g_hOllyDbg = hw;
	return 0;
}
//======================================��Ҫ�ĵ�������=======================================================


//************************************
// Method:��ʾ�˵���
// Description:��ʾ��Ӧ�Ĳ˵�ѡ��
//************************************
extern "C" __declspec(dllexport) cdecl int  ODBG_Pluginmenu(int origin, TCHAR data[4096], VOID * item)
{

	if (origin == PM_MAIN)
	{
		strcpy(data, "0&ָ��ȥ��,1&About");
	}
	if (origin == PM_DISASM)
	{
		strcpy(data, "JunkcodeDrop{0&ָ��ȥ��}");
	}
	return 1;
}
//************************************
// Method:�˵�����ִ�к���
// Description:���еĲ˵���������ִ�е��������
//************************************
extern "C" __declspec(dllexport) cdecl void ODBG_Pluginaction(int origin, int action, VOID * item)
{
	//������������ڵ��
	if (origin == PM_MAIN)
	{
		if (action == 0)
		{
			//t_module* module = _Findmodule(0x00401000);
			//JunkCodeDrop((t_dump*)item);

		}
		if (action == 1)
		{

			MessageBoxA(g_hOllyDbg, "Ka_bo", "��������", MB_ICONINFORMATION);
		}
	}
	//������ڷ���ര�ڵ��
	if (origin == PM_DISASM)
	{
		if (action == 0)
		{
			JunkCodeDrop((t_dump*)item);
		}

	}
}
