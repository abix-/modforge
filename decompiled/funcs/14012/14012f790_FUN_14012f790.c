// Address: 0x14012f790
// Ghidra name: FUN_14012f790
// ============ 0x14012f790 FUN_14012f790 (size=203) ============


int FUN_14012f790(longlong *param_1,undefined8 param_2,undefined8 param_3)



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  int iVar4;

  

  *param_1 = 0;

  iVar4 = 100;

  lVar2 = FUN_1401841f0(100);

  if (lVar2 == 0) {

    iVar1 = -1;

  }

  else {

    iVar1 = FUN_14012f860(lVar2,100,param_2,param_3);

    while (-1 < iVar1) {

      if (iVar1 < iVar4) {

        *param_1 = lVar2;

        return iVar1;

      }

      iVar4 = iVar1 + 1;

      lVar3 = FUN_140184230(lVar2,(longlong)iVar4);

      if (lVar3 == 0) {

        FUN_1401841e0(lVar2);

        return -1;

      }

      iVar1 = FUN_14012f860(lVar3,(longlong)iVar4,param_2,param_3);

      lVar2 = lVar3;

    }

    FUN_1401841e0(lVar2);

  }

  return iVar1;

}




