// Address: 0x14027b0c0
// Ghidra name: FUN_14027b0c0
// ============ 0x14027b0c0 FUN_14027b0c0 (size=66) ============


void FUN_14027b0c0(longlong *param_1,ulonglong param_2)



{

  uint uVar1;

  

  if ((char)param_1[2] != '\0') {

    uVar1 = *(uint *)((longlong)param_1 + 0xc);

    param_2 = (ulonglong)uVar1;

    if (-1 < (int)uVar1) {

      uVar1 = uVar1 & 0x80000003;

      if ((int)uVar1 < 0) {

        uVar1 = (uVar1 - 1 | 0xfffffffc) + 1;

      }

      FUN_14027b010(*(undefined8 *)(*param_1 + 0x80),uVar1,1);

      return;

    }

  }

  FUN_14027b010(*(undefined8 *)(*param_1 + 0x80),param_2 & 0xffffffffffffff00,0);

  return;

}




