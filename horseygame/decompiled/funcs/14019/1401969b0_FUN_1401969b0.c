// Address: 0x1401969b0
// Ghidra name: FUN_1401969b0
// ============ 0x1401969b0 FUN_1401969b0 (size=391) ============


undefined8 FUN_1401969b0(ulonglong param_1,ulonglong param_2,undefined8 param_3)



{

  char cVar1;

  ushort uVar2;

  short sVar3;

  uint uVar4;

  int iVar5;

  

  cVar1 = (char)param_1;

  if ((param_1 & 3) == 0) {

    if ((int)param_1 == 0xc0) {

      FUN_140196830(param_1,param_3);

      return 0;

    }

    if (((int)param_1 - 0x14U & 0xffffffcf) == 0) {

      if (param_2 + 0x80 < 0x100) {

LAB_140196a8b:

        FUN_140196830(cVar1 + '\x01',param_3);

        FUN_140196830(param_2 & 0xff);

        return 0;

      }

      if (param_2 + 0x8000 < 0x10000) {

        FUN_140196830(cVar1 + '\x02',param_3);

        sVar3 = (short)param_2;

        FUN_140196830(param_2 & 0xff);

        FUN_140196830(sVar3 >> 8 & 0xff);

        return 0;

      }

      if (param_2 + 0x80000000 < 0x100000000) {

        FUN_140196830(cVar1 + '\x03',param_3);

        iVar5 = (int)param_2;

        FUN_140196830(param_2 & 0xff);

        FUN_140196830(iVar5 >> 8);

        FUN_140196830(iVar5 >> 0x10);

        FUN_140196830(iVar5 >> 0x18 & 0xff);

        return 0;

      }

    }

    else if (-1 < (longlong)param_2) {

      if ((longlong)param_2 < 0x100) goto LAB_140196a8b;

      if ((longlong)param_2 < 0x10000) {

        FUN_140196830(cVar1 + '\x02',param_3);

        uVar2 = (ushort)param_2;

        FUN_140196830(param_2 & 0xff);

        FUN_140196830(uVar2 >> 8);

        return 0;

      }

      if ((longlong)param_2 < 0x100000000) {

        FUN_140196830(cVar1 + '\x03',param_3);

        FUN_140196830(param_2 & 0xff);

        FUN_140196830(param_2 >> 8 & 0xffffff);

        uVar4 = (uint)param_2;

        FUN_140196830(param_2 >> 0x10 & 0xffff);

        FUN_140196830(uVar4 >> 0x18);

        return 0;

      }

    }

  }

  return 0xffffffff;

}




