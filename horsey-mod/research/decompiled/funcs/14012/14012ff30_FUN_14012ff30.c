// Address: 0x14012ff30
// Ghidra name: FUN_14012ff30
// ============ 0x14012ff30 FUN_14012ff30 (size=114) ============


short * FUN_14012ff30(short *param_1,undefined8 param_2,ulonglong param_3)



{

  int iVar1;

  ulonglong uVar2;

  

  uVar2 = FUN_14012fd40(param_2);

  if (uVar2 != 0) {

    for (; (uVar2 <= param_3 && (*param_1 != 0)); param_1 = param_1 + 1) {

      iVar1 = FUN_14012feb0(param_1,param_2,uVar2);

      if (iVar1 == 0) {

        return param_1;

      }

      param_3 = param_3 - 1;

    }

    param_1 = (short *)0x0;

  }

  return param_1;

}




