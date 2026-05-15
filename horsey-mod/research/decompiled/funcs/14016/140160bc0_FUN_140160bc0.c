// Address: 0x140160bc0
// Ghidra name: FUN_140160bc0
// ============ 0x140160bc0 FUN_140160bc0 (size=233) ============


longlong FUN_140160bc0(undefined8 *param_1,int param_2,undefined4 param_3,undefined4 param_4)



{

  undefined8 *puVar1;

  longlong lVar2;

  undefined8 uVar3;

  longlong lVar4;

  longlong lVar5;

  

  lVar5 = (longlong)param_2;

  lVar2 = FUN_1401841a0(1,0x20);

  if (lVar2 != 0) {

    uVar3 = FUN_1401841a0(lVar5,8);

    *(undefined8 *)(lVar2 + 0x10) = uVar3;

    lVar4 = FUN_1401841a0(lVar5,4);

    *(longlong *)(lVar2 + 0x18) = lVar4;

    if ((*(longlong *)(lVar2 + 0x10) == 0) || (lVar4 == 0)) {

LAB_140160c80:

      FUN_140160e30(lVar2);

      lVar2 = 0;

    }

    else {

      if (0 < param_2) {

        lVar4 = 0;

        do {

          uVar3 = FUN_140160aa0(*param_1,param_3,param_4);

          *(undefined8 *)(*(longlong *)(lVar2 + 0x10) + lVar4 * 8) = uVar3;

          if (*(longlong *)(*(longlong *)(lVar2 + 0x10) + lVar4 * 8) == 0) goto LAB_140160c80;

          puVar1 = param_1 + 1;

          param_1 = param_1 + 2;

          *(undefined4 *)(*(longlong *)(lVar2 + 0x18) + lVar4 * 4) = *(undefined4 *)puVar1;

          lVar4 = lVar4 + 1;

        } while (lVar4 < lVar5);

      }

      *(int *)(lVar2 + 8) = param_2;

    }

  }

  return lVar2;

}




