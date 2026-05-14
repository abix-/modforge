// Address: 0x14008e1d0
// Ghidra name: FUN_14008e1d0
// ============ 0x14008e1d0 FUN_14008e1d0 (size=404) ============


undefined8 FUN_14008e1d0(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  int iVar3;

  int iVar4;

  ulonglong uVar5;

  longlong lVar6;

  float local_res8 [2];

  

  FUN_1400d0a00(param_1,0);

  if (((*(longlong *)(param_1 + 0x148) != 0) && (*(int *)(param_1 + 0x250) == 0)) &&

     (iVar4 = (int)(*(longlong *)(param_1 + 0x138) - *(longlong *)(param_1 + 0x130) >> 3), iVar4 < 3

     )) {

    uVar5 = (ulonglong)(3 - iVar4);

    do {

      FUN_14008e370(param_1);

      uVar5 = uVar5 - 1;

    } while (uVar5 != 0);

  }

  lVar2 = *(longlong *)(param_1 + 0x130);

  iVar4 = 0;

  *(int *)(param_1 + 0x268) = (int)(*(longlong *)(param_1 + 0x138) - lVar2 >> 3) + -1;

  if (*(longlong *)(param_1 + 0x138) - lVar2 >> 3 != 0) {

    lVar6 = 0;

    iVar3 = 6;

    do {

      if (*(longlong *)(lVar6 + lVar2) != *(longlong *)(param_1 + 0x148)) {

        local_res8[0] = (float)iVar3;

        local_res8[1] = 5.0;

        FUN_1400b6610(*(longlong *)(lVar6 + lVar2),local_res8);

        iVar3 = iVar3 + 8;

        lVar2 = *(longlong *)(lVar6 + *(longlong *)(param_1 + 0x130));

        if (*(int *)(lVar2 + 0x220) < 0x65) {

          iVar1 = *(int *)(&DAT_14030b7a8 + (*(ulonglong *)(lVar2 + 0x2a8) % 9) * 4) * 2;

          *(int *)(lVar2 + 0x220) =

               iVar1 / 3 + (iVar1 >> 0x1f) +

               (int)(((longlong)iVar1 / 3 + ((longlong)iVar1 >> 0x3f) & 0xffffffffU) >> 0x1f);

        }

      }

      lVar2 = *(longlong *)(param_1 + 0x130);

      iVar4 = iVar4 + 1;

      lVar6 = lVar6 + 8;

    } while ((ulonglong)(longlong)iVar4 < (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar2 >> 3));

  }

  FUN_1400cd5a0(param_1,CONCAT71((int7)((ulonglong)lVar2 >> 8),1));

  FUN_1400ce540(param_1,0,0);

  *(undefined4 *)(param_1 + 0x250) = 0;

  *(undefined8 *)(param_1 + 0x25c) = 0;

  return 1;

}




