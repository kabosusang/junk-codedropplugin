#pragma once
#include"pch.h"
#include"attribute_code.h"
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
	ulong Nextadd = 0;
	//��ʼ�����������
	t_disasm td;
	t_disasm ad;
	//��ȡ�ڴ�

	_Readmemory(Buf, StartmoudleAddress, MAXCMDSIZE, MM_SILENT);
	//���������

	ulong LSize = _Disasm(Buf, 16, StartmoudleAddress, NULL, &td, DISASM_ALL, NULL);
	if (LSize)
	{
		//_Go(0, 0, STEP_SKIP, 0, 0);
		for (; StartmoudleAddress < UltimatemoudleAddress; )
		{
			_Progress(100, NULL);
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

			if (codecompare(td.dump, StartmoudleAddress))
			{
				Nextadd = StartmoudleAddress + DisasmREDsize;
				//����ָ��ȥȡ��һ��
				ulong LSize = _Disasm(Buf, 16, Nextadd, NULL, &ad, DISASM_ALL, NULL);
				NExtcompare(ad.dump, Nextadd);
			}

			//ȡ��һ��ָ��
			ulong StartmoudleAddress = StartmoudleAddress + DisasmREDsize;
			//��һ��ָ����з����
			ulong LSize = _Disasm(Buf, 16, StartmoudleAddress, NULL, &td, DISASM_ALL, NULL);
		}
	}
	return 0;

}
