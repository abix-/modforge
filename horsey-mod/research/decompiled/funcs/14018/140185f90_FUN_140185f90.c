// Address: 0x140185f90
// Ghidra name: FUN_140185f90
// ============ 0x140185f90 FUN_140185f90 (size=267) ============


int FUN_140185f90(undefined8 param_1,undefined4 param_2,undefined1 *param_3)



{

  int iVar1;

  longlong lVar2;

  undefined8 *puVar3;

  undefined8 uVar4;

  undefined1 *puVar5;

  longlong lVar6;

  

  FUN_140186540();

  iVar1 = FUN_1401864e0(param_1);

  if (iVar1 < 0) {

    lVar2 = FUN_140184230(DAT_1403fcb60,(longlong)(DAT_1403fcb5c + 1) << 3);

    iVar1 = DAT_1403fcb5c;

    if (lVar2 != 0) {

      lVar6 = (longlong)DAT_1403fcb5c;

      DAT_1403fcb60 = lVar2;

      puVar3 = (undefined8 *)FUN_1401841f0(0x28);

      lVar2 = DAT_1403fcb60;

      lVar6 = lVar6 * 8;

      *(undefined8 **)(lVar6 + DAT_1403fcb60) = puVar3;

      if (puVar3 != (undefined8 *)0x0) {

        DAT_1403fcb5c = DAT_1403fcb5c + 1;

        *puVar3 = param_1;

        *(undefined4 *)(*(longlong *)(lVar6 + lVar2) + 8) = param_2;

        *(undefined4 *)(*(longlong *)(lVar6 + lVar2) + 0xc) = 0;

        *(undefined4 *)(*(longlong *)(lVar6 + lVar2) + 0x10) = 0;

        *(undefined8 *)(*(longlong *)(lVar6 + lVar2) + 0x18) = 0;

        lVar2 = *(longlong *)(lVar6 + lVar2);

        puVar5 = &DAT_14039bcb9;

        if (param_3 != (undefined1 *)0x0) {

          puVar5 = param_3;

        }

        uVar4 = FUN_14012f0d0(puVar5);

        *(undefined8 *)(lVar2 + 0x20) = uVar4;

        FUN_140186c50();

        return iVar1;

      }

    }

    FUN_140186c50();

    iVar1 = -1;

  }

  else {

    FUN_140186c50();

  }

  return iVar1;

}




