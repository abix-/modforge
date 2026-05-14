// Address: 0x14021d7e0
// Ghidra name: FUN_14021d7e0
// ============ 0x14021d7e0 FUN_14021d7e0 (size=290) ============


undefined8 FUN_14021d7e0(int param_1,int param_2,uint param_3,int *param_4)



{

  int *piVar1;

  longlong lVar2;

  char cVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  

  uVar4 = 0;

  if (DAT_1403e5480 == 0x7fffffff) {

    DAT_1403e5480 = 0;

    cVar3 = FUN_14017fe10();

    if (cVar3 != '\0') {

      DAT_1403e5480 = DAT_1403e5480 | 1;

    }

    cVar3 = FUN_14017fed0();

    if (cVar3 != '\0') {

      DAT_1403e5480 = DAT_1403e5480 | 2;

    }

    cVar3 = FUN_14017fe50();

    if (cVar3 != '\0') {

      DAT_1403e5480 = DAT_1403e5480 | 4;

    }

    cVar3 = FUN_14017fdc0();

    if (cVar3 != '\0') {

      cVar3 = FUN_140018e60();

      if (cVar3 == '\0') {

        DAT_1403e5480 = DAT_1403e5480 | 0x10;

      }

      else {

        DAT_1403e5480 = DAT_1403e5480 | 8;

      }

    }

  }

  lVar2 = *(longlong *)(param_4 + 4);

  uVar5 = uVar4;

  piVar1 = param_4;

  while( true ) {

    if (lVar2 == 0) {

      return 0;

    }

    if ((((param_1 == *piVar1) && (param_2 == piVar1[1])) &&

        ((piVar1[2] & param_3 & 0xff3) == (param_3 & 0xff3))) &&

       ((piVar1[3] & DAT_1403e5480) == piVar1[3])) break;

    uVar4 = uVar4 + 1;

    uVar5 = (ulonglong)((int)uVar5 + 1);

    lVar2 = *(longlong *)(param_4 + uVar4 * 6 + 4);

    piVar1 = param_4 + uVar4 * 6;

  }

  return *(undefined8 *)(param_4 + (longlong)(int)uVar5 * 6 + 4);

}




