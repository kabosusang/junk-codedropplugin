#include"pch.h"



//======================================必须导出的函数=======================================================


extern "C" __declspec(dllexport) cdecl int ODBG_Plugindata(char* shortname)
{
	const char* pluginName = "花指令去除插件";
	strcpy_s(shortname, strlen(pluginName) + 1, pluginName);
	return PLUGIN_VERSION;
}

//OD主界面句柄
HWND g_hOllyDbg;
// Method:插件初始化，用于判断当前OD版本号和插件所支持的版本是否一致
// Description:必须的导出函数 
//************************************
extern "C" __declspec(dllexport) cdecl int ODBG_Plugininit(int ollydbgversion, HWND hw, ulong * features)
{

	if (ollydbgversion != PLUGIN_VERSION)
	{
		MessageBox(hw, "本插件不支持当前版本OD!", "MyFirstPlugin", MB_ICONERROR);
		return -1;
	}
	g_hOllyDbg = hw;
	return 0;
}
//======================================重要的导出函数=======================================================


//************************************
// Method:显示菜单项
// Description:显示对应的菜单选项
//************************************
extern "C" __declspec(dllexport) cdecl int  ODBG_Pluginmenu(int origin, TCHAR data[4096], VOID * item)
{

	if (origin == PM_MAIN)
	{
		strcpy(data, "0&指令去除,1&About");
	}
	if (origin == PM_DISASM)
	{
		strcpy(data, "JunkcodeDrop{0&指令去除}");
	}
	return 1;
}
//************************************
// Method:菜单项被点击执行函数
// Description:所有的菜单项被点击都会执行到这个函数
//************************************
extern "C" __declspec(dllexport) cdecl void ODBG_Pluginaction(int origin, int action, VOID * item)
{
	//如果是在主窗口点击
	if (origin == PM_MAIN)
	{
		if (action == 0)
		{
			//t_module* module = _Findmodule(0x00401000);
			//JunkCodeDrop((t_dump*)item);

		}
		if (action == 1)
		{

			MessageBoxA(g_hOllyDbg, "Ka_bo", "关于作者", MB_ICONINFORMATION);
		}
	}
	//如果是在反汇编窗口点击
	if (origin == PM_DISASM)
	{
		if (action == 0)
		{
			JunkCodeDrop((t_dump*)item);
		}

	}
}
