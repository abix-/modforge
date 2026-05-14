// Address: 0x1401a19f0
// Ghidra name: FUN_1401a19f0
// ============ 0x1401a19f0 FUN_1401a19f0 (size=96) ============


undefined8 FUN_1401a19f0(int param_1,int param_2,uint param_3,undefined4 param_4)



{

  int iVar1;

  int iVar2;

  ulonglong uVar3;

  

  uVar3 = (ulonglong)param_3;

  iVar1 = FUN_1401a1c40();

  iVar2 = (int)uVar3;

  if (iVar1 != 0) {

    param_1 = param_1 * param_2;

    iVar1 = FUN_1401a1c40(param_1,uVar3 & 0xffffffff);

    if (iVar1 != 0) {

      iVar1 = FUN_14019ca20(param_1 * iVar2,param_4);

      if (iVar1 != 0) {

        return 1;

      }

    }

  }

  return 0;

}




