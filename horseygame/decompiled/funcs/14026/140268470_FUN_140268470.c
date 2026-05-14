// Address: 0x140268470
// Ghidra name: FUN_140268470
// ============ 0x140268470 FUN_140268470 (size=104) ============


ulonglong FUN_140268470(longlong param_1,undefined8 param_2,undefined8 param_3,short param_4,

                       short param_5)



{

  int iVar1;

  ulonglong uVar2;

  

  uVar2 = 0x57e;

  if (param_4 == 0x57e) {

    uVar2 = 0x2009;

    if (param_5 != 0x2009) {

      uVar2 = (ulonglong)(ushort)(param_5 + 0xdffaU);

      if (1 < (ushort)(param_5 + 0xdffaU)) {

        return CONCAT71(0x20,param_5 == 0x200e);

      }

LAB_1402684d1:

      return CONCAT71((int7)(uVar2 >> 8),1);

    }

    if ((param_1 != 0) && (*(longlong *)(param_1 + 0x80) != 0)) {

      iVar1 = FUN_14026c810();

      uVar2 = (ulonglong)(iVar1 - 1U);

      if (iVar1 - 1U < 2) goto LAB_1402684d1;

    }

  }

  return uVar2 & 0xffffffffffffff00;

}




