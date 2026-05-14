// Address: 0x1401a1a50
// Ghidra name: FUN_1401a1a50
// ============ 0x1401a1a50 FUN_1401a1a50 (size=116) ============


undefined8 FUN_1401a1a50(int param_1,int param_2,int param_3,uint param_4,undefined4 param_5)



{

  int iVar1;

  int iVar2;

  ulonglong uVar3;

  

  uVar3 = (ulonglong)param_4;

  iVar1 = FUN_1401a1c40();

  if (iVar1 != 0) {

    param_1 = param_1 * param_2;

    iVar1 = FUN_1401a1c40(param_1,param_3);

    iVar2 = (int)uVar3;

    if (iVar1 != 0) {

      param_1 = param_1 * param_3;

      iVar1 = FUN_1401a1c40(param_1,uVar3 & 0xffffffff);

      if (iVar1 != 0) {

        iVar1 = FUN_14019ca20(param_1 * iVar2,param_5);

        if (iVar1 != 0) {

          return 1;

        }

      }

    }

  }

  return 0;

}




