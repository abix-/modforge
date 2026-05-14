// Address: 0x140132550
// Ghidra name: FUN_140132550
// ============ 0x140132550 FUN_140132550 (size=422) ============


undefined8 FUN_140132550(longlong param_1,longlong param_2,undefined8 *param_3)



{

  uint uVar1;

  longlong lVar2;

  undefined8 uVar3;

  longlong lVar4;

  int iVar5;

  

  if (*(longlong *)(param_1 + 0x1a8) != 0) goto LAB_1401326a1;

  lVar2 = FUN_140130a00(param_1 + 0x3c);

  uVar3 = FUN_14017fc90();

  lVar4 = FUN_140190080(uVar3,lVar2);

  *(longlong *)(param_1 + 0x1a8) = lVar4;

  if (lVar4 == 0) {

    *param_3 = 0;

    return 1;

  }

  iVar5 = *(int *)(param_1 + 0x3c);

  if (iVar5 < 0x3259555a) {

    if (iVar5 == 0x32595559) {

LAB_140132673:

      if (lVar2 != 0) {

        lVar4 = lVar4 + 2;

        lVar2 = (lVar2 - 1U >> 2) + 1;

        do {

          *(undefined4 *)(lVar4 + -2) = 0x80008000;

          lVar4 = lVar4 + 4;

          lVar2 = lVar2 + -1;

        } while (lVar2 != 0);

      }

      goto LAB_1401326a1;

    }

    if (((iVar5 == 0x3132564e) || (iVar5 == 0x3231564e)) || (iVar5 == 0x32315659)) {

LAB_1401325dd:

      FUN_1402f94c0(lVar4,0,(longlong)(*(int *)(param_1 + 0x44) * *(int *)(param_1 + 0x48)));

      iVar5 = *(int *)(param_1 + 0x44) * *(int *)(param_1 + 0x48);

      FUN_1402f94c0(iVar5 + lVar4,0x80,(longlong)(iVar5 / 2));

      goto LAB_1401326a1;

    }

  }

  else {

    if (iVar5 == 0x55595659) goto LAB_140132673;

    if (iVar5 == 0x56555949) goto LAB_1401325dd;

    if (iVar5 == 0x59565955) {

      if (lVar2 != 0) {

        lVar4 = lVar4 + 2;

        lVar2 = (lVar2 - 1U >> 2) + 1;

        do {

          *(undefined4 *)(lVar4 + -2) = 0x800080;

          lVar4 = lVar4 + 4;

          lVar2 = lVar2 + -1;

        } while (lVar2 != 0);

      }

      goto LAB_1401326a1;

    }

  }

  FUN_1402f94c0(lVar4,0,lVar2);

LAB_1401326a1:

  uVar3 = FUN_140149300();

  *param_3 = uVar3;

  *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(param_1 + 0x1a8);

  iVar5 = *(int *)(param_1 + 0x44);

  *(int *)(param_2 + 0x10) = iVar5;

  uVar1 = *(uint *)(param_1 + 0x3c);

  if ((uVar1 == 0) || ((uVar1 & 0xf0000000) == 0x10000000)) {

    *(uint *)(param_2 + 0x10) = (uVar1 & 0xff) * iVar5;

  }

  return 2;

}




