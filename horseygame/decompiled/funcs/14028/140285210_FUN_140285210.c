// Address: 0x140285210
// Ghidra name: FUN_140285210
// ============ 0x140285210 FUN_140285210 (size=177) ============


ulonglong FUN_140285210(undefined1 param_1,undefined2 *param_2,undefined2 *param_3,ushort *param_4)



{

  ulonglong uVar1;

  undefined1 local_28 [2];

  byte local_26;

  undefined2 local_14;

  ushort local_12;

  ushort local_10;

  

  uVar1 = 0;

  if ((DAT_1403fde00 != (code *)0x0) &&

     (uVar1 = (*DAT_1403fde00)(1,param_1,0,local_28), (int)uVar1 == 0)) {

    uVar1 = (ulonglong)local_12;

    if ((local_12 == 0) && ((local_26 & 2) != 0)) {

      local_14 = 0x45e;

      uVar1 = 0x2a1;

    }

    if (param_2 != (undefined2 *)0x0) {

      *param_2 = local_14;

    }

    if (param_3 != (undefined2 *)0x0) {

      *param_3 = (short)uVar1;

    }

    if (param_4 != (ushort *)0x0) {

      uVar1 = (ulonglong)local_10;

      *param_4 = local_10;

    }

    return CONCAT71((int7)(uVar1 >> 8),1);

  }

  if (param_2 != (undefined2 *)0x0) {

    *param_2 = 0x45e;

  }

  if (param_3 != (undefined2 *)0x0) {

    *param_3 = 0x2a1;

  }

  return uVar1 & 0xffffffffffffff00;

}




