// Address: 0x140146210
// Ghidra name: FUN_140146210
// ============ 0x140146210 FUN_140146210 (size=364) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



undefined8 FUN_140146210(longlong param_1)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  ulonglong uVar5;

  undefined1 *puVar6;

  undefined8 uVar7;

  undefined1 *puVar8;

  longlong lVar9;

  longlong lVar10;

  longlong lVar11;

  undefined1 auStack_58 [32];

  

  puVar8 = auStack_58;

  uVar1 = *(uint *)(param_1 + 4);

  if (((uVar1 == 0) || (((byte)((int)uVar1 >> 0x1c) & 0xf) != 1)) || ((uVar1 & 0xff00) < 0x800)) {

    uVar7 = FUN_14012e850("That operation is not supported");

  }

  else {

    if ((0 < *(int *)(param_1 + 0xc)) && (1 < *(int *)(param_1 + 8))) {

      uVar2 = *(uint *)(param_1 + 0x10);

      lVar11 = *(longlong *)(param_1 + 0x18);

      if (uVar2 < 0x80) {

        uVar5 = (longlong)(int)uVar2 + 0xf;

        if (uVar5 <= (ulonglong)(longlong)(int)uVar2) {

          uVar5 = 0xffffffffffffff0;

        }

        puVar8 = auStack_58 + -(uVar5 & 0xfffffffffffffff0);

        puVar6 = &stack0xffffffffffffffc8 + -(uVar5 & 0xfffffffffffffff0);

      }

      else {

        puVar6 = (undefined1 *)FUN_1401841f0();

      }

      if (puVar6 == (undefined1 *)0x0) {

        return 0;

      }

      iVar3 = *(int *)(param_1 + 0xc);

      while (iVar3 != 0) {

        uVar5 = (ulonglong)(uVar1 & 0xff);

        iVar3 = iVar3 + -1;

        lVar10 = (int)((*(int *)(param_1 + 8) + -1) * (uVar1 & 0xff)) + lVar11;

        lVar9 = lVar11;

        for (iVar4 = *(int *)(param_1 + 8) / 2; iVar4 != 0; iVar4 = iVar4 + -1) {

          *(undefined8 *)(puVar8 + -8) = 0x14014630e;

          FUN_1402f8e20(puVar6,lVar9,uVar5);

          *(undefined8 *)(puVar8 + -8) = 0x14014631c;

          FUN_1402f8e20(lVar9,lVar10,uVar5);

          *(undefined8 *)(puVar8 + -8) = 0x14014632a;

          FUN_1402f8e20(lVar10,puVar6,uVar5);

          lVar9 = lVar9 + uVar5;

          lVar10 = lVar10 - uVar5;

        }

        lVar11 = lVar11 + *(int *)(param_1 + 0x10);

      }

      if (0x7f < uVar2) {

        *(undefined8 *)(puVar8 + -8) = 0x140146359;

        FUN_1401841e0(puVar6);

      }

    }

    uVar7 = 1;

  }

  return uVar7;

}




