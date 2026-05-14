// Address: 0x140221f60
// Ghidra name: FUN_140221f60
// ============ 0x140221f60 FUN_140221f60 (size=83) ============


undefined4 FUN_140221f60(longlong param_1,uint param_2,int param_3)



{

  int iVar1;

  uint uVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  

  uVar3 = 0;

  uVar4 = (ulonglong)param_2;

  if (param_2 != 0) {

    do {

      iVar1 = FUN_140221f30(param_1 + uVar3 * 0xc);

      if (iVar1 == param_3) {

        return 1;

      }

      uVar2 = (int)uVar3 + 1;

      uVar3 = (ulonglong)uVar2;

    } while (uVar2 < (uint)uVar4);

  }

  return 0;

}




