// Address: 0x140176010
// Ghidra name: FUN_140176010
// ============ 0x140176010 FUN_140176010 (size=56) ============


ulonglong FUN_140176010(short *param_1,int param_2,short param_3,short param_4)



{

  ulonglong uVar1;

  ulonglong uVar2;

  

  if ((param_1 != (short *)0x0) && (uVar1 = 0, 0 < param_2)) {

    uVar2 = uVar1;

    do {

      if ((*param_1 == param_3) && (param_1[1] == param_4)) {

        return uVar2;

      }

      uVar2 = (ulonglong)((int)uVar2 + 1);

      uVar1 = uVar1 + 1;

      param_1 = param_1 + 3;

    } while ((longlong)uVar1 < (longlong)param_2);

  }

  return 0xffffffff;

}




