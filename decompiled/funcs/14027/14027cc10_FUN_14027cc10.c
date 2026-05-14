// Address: 0x14027cc10
// Ghidra name: FUN_14027cc10
// ============ 0x14027cc10 FUN_14027cc10 (size=129) ============


undefined8 FUN_14027cc10(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  ulonglong uVar3;

  undefined8 uVar4;

  

  do {

    iVar1 = *(int *)(param_1 + 0xc);

    if (iVar1 == 0) {

LAB_14027cc50:

      uVar4 = 4;

LAB_14027cc55:

      FUN_14027d2d0(param_1,uVar4);

    }

    else {

      if (iVar1 == 1) {

        lVar2 = *(longlong *)(param_1 + 0x20);

        uVar3 = FUN_140149350();

        if (uVar3 < lVar2 + 100U) goto LAB_14027cc5d;

        uVar4 = 2;

        goto LAB_14027cc55;

      }

      if (iVar1 == 2) goto LAB_14027cc50;

      if (iVar1 == 3) {

        lVar2 = *(longlong *)(param_1 + 0x20);

        uVar3 = FUN_140149350();

        if (lVar2 + 0x32U <= uVar3) goto LAB_14027cc50;

      }

    }

LAB_14027cc5d:

    if (*(int *)(param_1 + 0xc) == iVar1) {

      return 1;

    }

  } while( true );

}




