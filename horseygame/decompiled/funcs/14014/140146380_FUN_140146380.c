// Address: 0x140146380
// Ghidra name: FUN_140146380
// ============ 0x140146380 FUN_140146380 (size=264) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



undefined8 FUN_140146380(longlong param_1)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  ulonglong uVar4;

  undefined1 *puVar5;

  longlong lVar6;

  undefined1 *puVar7;

  longlong lVar8;

  longlong lVar9;

  undefined1 auStack_38 [32];

  

  puVar7 = auStack_38;

  if (1 < *(int *)(param_1 + 0xc)) {

    uVar1 = *(uint *)(param_1 + 0x10);

    lVar9 = *(longlong *)(param_1 + 0x18);

    lVar8 = (int)((*(int *)(param_1 + 0xc) + -1) * uVar1) + lVar9;

    if (uVar1 < 0x80) {

      uVar4 = (longlong)(int)uVar1 + 0xf;

      if (uVar4 <= (ulonglong)(longlong)(int)uVar1) {

        uVar4 = 0xffffffffffffff0;

      }

      puVar7 = auStack_38 + -(uVar4 & 0xfffffffffffffff0);

      puVar5 = &stack0xffffffffffffffe8 + -(uVar4 & 0xfffffffffffffff0);

    }

    else {

      puVar5 = (undefined1 *)FUN_1401841f0();

    }

    if (puVar5 == (undefined1 *)0x0) {

      return 0;

    }

    iVar3 = *(int *)(param_1 + 0xc) / 2;

    if (iVar3 != 0) {

      lVar6 = (longlong)*(int *)(param_1 + 0x10);

      do {

        *(undefined8 *)(puVar7 + -8) = 0x14014642e;

        FUN_1402f8e20(puVar5,lVar9,lVar6);

        iVar2 = *(int *)(param_1 + 0x10);

        *(undefined8 *)(puVar7 + -8) = 0x14014643d;

        FUN_1402f8e20(lVar9,lVar8,(longlong)iVar2);

        iVar2 = *(int *)(param_1 + 0x10);

        *(undefined8 *)(puVar7 + -8) = 0x14014644c;

        FUN_1402f8e20(lVar8,puVar5,(longlong)iVar2);

        lVar6 = (longlong)*(int *)(param_1 + 0x10);

        lVar9 = lVar9 + lVar6;

        lVar8 = lVar8 - lVar6;

        iVar3 = iVar3 + -1;

      } while (iVar3 != 0);

    }

    if (0x7f < uVar1) {

      *(undefined8 *)(puVar7 + -8) = 0x14014646d;

      FUN_1401841e0(puVar5);

    }

  }

  return 1;

}




