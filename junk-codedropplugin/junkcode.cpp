#include"pch.h"
uchar Buf[MAXCMDSIZE] = { 0 };


//************************************************************//
//Fullname:JunkCodeDrop函数
//Returns:
//parameter:传入的程序t_dump*类型指针
//Author:ka_bo
//************************************************************//

int JunkCodeDrop(t_dump* ptdump)
{
	//获取右键点击的模块地址指针
	ulong uSelectAddress = ptdump->sel0;
	//选中模块程序所有代码地址
	t_module* Selectmodule = (t_module*)_Findmodule(uSelectAddress);
	ulong StartmoudleAddress = Selectmodule->base;
	ulong UltimatemoudleAddress = Selectmodule->resbase + Selectmodule->ressize;
	ulong BuffSize = UltimatemoudleAddress - StartmoudleAddress;

	//初始化反汇编引擎
	t_disasm td;

	//读取内存

	_Readmemory(Buf, StartmoudleAddress, MAXCMDSIZE, MM_SILENT);
	//反汇编引擎

	ulong LSize = _Disasm(Buf, 16, StartmoudleAddress, NULL, &td, DISASM_ALL, NULL);
	if (LSize)
	{
		//_Go(0, 0, STEP_SKIP, 0, 0);
		for (; StartmoudleAddress < UltimatemoudleAddress; )
		{
			//计算取出指令的长度
			int DisasmREDsize = 0;
			for (size_t i = 0; i < TEXTLEN; i++)
			{
				if (td.dump[i])
				{
					DisasmREDsize++;
					i++;
				}
				DisasmREDsize / 2;
				break;
			}
			//对比特征码
			codecompare(td.dump);
			//取下一条指令
			ulong NextmoudleAddress = StartmoudleAddress + DisasmREDsize;


			ulong LSize = _Disasm(Buf, 16, NextmoudleAddress, NULL, &td, DISASM_ALL, NULL);
		}
	}
	return 0;

}
