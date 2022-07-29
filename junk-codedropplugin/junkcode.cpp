#include"pch.h"
uchar Buf[MAXCMDSIZE] = { 0 };


//************************************************************//
//Fullname:JunkCodeDrop����
//Returns:
//parameter:����ĳ���t_dump*����ָ��
//Author:ka_bo
//************************************************************//

int JunkCodeDrop(t_dump* ptdump)
{
	//��ȡ�Ҽ������ģ���ַָ��
	ulong uSelectAddress = ptdump->sel0;
	//ѡ��ģ��������д����ַ
	t_module* Selectmodule = (t_module*)_Findmodule(uSelectAddress);
	ulong StartmoudleAddress = Selectmodule->base;
	ulong UltimatemoudleAddress = Selectmodule->resbase + Selectmodule->ressize;
	ulong BuffSize = UltimatemoudleAddress - StartmoudleAddress;

	//��ʼ�����������
	t_disasm td;

	//��ȡ�ڴ�

	_Readmemory(Buf, StartmoudleAddress, MAXCMDSIZE, MM_SILENT);
	//���������

	ulong LSize = _Disasm(Buf, 16, StartmoudleAddress, NULL, &td, DISASM_ALL, NULL);
	if (LSize)
	{
		//_Go(0, 0, STEP_SKIP, 0, 0);
		for (; StartmoudleAddress < UltimatemoudleAddress; )
		{
			//����ȡ��ָ��ĳ���
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
			//�Ա�������
			codecompare(td.dump);
			//ȡ��һ��ָ��
			ulong NextmoudleAddress = StartmoudleAddress + DisasmREDsize;


			ulong LSize = _Disasm(Buf, 16, NextmoudleAddress, NULL, &td, DISASM_ALL, NULL);
		}
	}
	return 0;

}
