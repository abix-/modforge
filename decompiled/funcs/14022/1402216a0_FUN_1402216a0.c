// Address: 0x1402216a0
// Ghidra name: FUN_1402216a0
// ============ 0x1402216a0 FUN_1402216a0 (size=411) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void FUN_1402216a0(longlong param_1,undefined8 param_2,longlong param_3,longlong *param_4,

                  longlong *param_5)



{

  undefined1 *puVar1;

  undefined1 *puVar2;

  undefined4 uVar3;

  code *pcVar4;

  longlong lVar5;

  uint uVar6;

  uint uVar7;

  undefined4 uVar8;

  undefined4 uVar9;

  longlong lVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  ulonglong uVar13;

  uint uVar14;

  uint uVar15;

  undefined4 *puVar16;

  longlong lVar17;

  undefined8 auStack_70 [5];

  undefined1 auStack_48 [16];

  

  lVar17 = *(longlong *)(param_1 + 0x30);

  auStack_70[0] = 0x1402216d2;

  lVar10 = (**(code **)(*param_5 + 0x28))(param_5);

  uVar3 = *(undefined4 *)(param_3 + 0x18);

  lVar17 = (lVar10 + lVar17) * 1000;

  uVar13 = (ulonglong)*(uint *)(*(longlong *)(*(longlong *)(param_3 + 8) + 0xd0) + 0x10);

  uVar12 = uVar13 * 0xc;

  uVar11 = uVar12 + 0xf;

  if (uVar11 <= uVar12) {

    uVar11 = 0xffffffffffffff0;

  }

  auStack_70[0] = 0x140221719;

  lVar10 = -(uVar11 & 0xfffffffffffffff0);

  uVar11 = uVar12 + 0xf;

  puVar1 = &stack0xffffffffffffffc8 + lVar10;

  if (uVar11 <= uVar12) {

    uVar11 = 0xffffffffffffff0;

  }

  *(undefined8 *)((longlong)auStack_70 + lVar10) = 0x140221736;

  lVar5 = -(uVar11 & 0xfffffffffffffff0);

  puVar2 = &stack0xffffffffffffffc8 + lVar5 + lVar10;

  if ((puVar1 != (undefined1 *)0x0) && (puVar2 != (undefined1 *)0x0)) {

    uVar12 = 0;

    pcVar4 = *(code **)(*param_4 + 0x78);

    *(undefined8 *)((longlong)auStack_70 + lVar5 + lVar10) = 0x140221761;

    uVar6 = (*pcVar4)(param_4,uVar13,puVar1);

    pcVar4 = *(code **)(*param_5 + 0x78);

    *(undefined8 *)((longlong)auStack_70 + lVar5 + lVar10) = 0x140221778;

    uVar7 = (*pcVar4)(param_5,uVar13,puVar2);

    uVar11 = uVar12;

    while( true ) {

      while( true ) {

        uVar15 = (uint)uVar11;

        uVar14 = (uint)uVar12;

        if (uVar6 <= uVar15) break;

        if (uVar14 < uVar7) {

          uVar13 = (ulonglong)*(uint *)(puVar1 + uVar11 * 0xc);

          if (*(uint *)(puVar1 + uVar11 * 0xc) == *(uint *)(puVar2 + uVar12 * 0xc)) {

            uVar12 = (ulonglong)(uVar14 + 1);

            uVar11 = (ulonglong)(uVar15 + 1);

          }

          else {

            *(undefined8 *)((longlong)auStack_70 + lVar5 + lVar10) = 0x1402217e5;

            uVar9 = FUN_140221f30(puVar1 + uVar11 * 0xc);

            auStack_48[lVar5 + lVar10] = 0;

            *(undefined8 *)((longlong)auStack_70 + lVar5 + lVar10) = 0x1402217fb;

            FUN_140183990(lVar17,uVar3,uVar13 & 0xffffffff,uVar9);

            uVar11 = (ulonglong)(uVar15 + 1);

          }

        }

        else {

          puVar16 = (undefined4 *)(puVar1 + uVar11 * 0xc);

          *(undefined8 *)((longlong)auStack_70 + lVar5 + lVar10) = 0x14022180b;

          uVar8 = FUN_140221f30(puVar16);

          uVar9 = *puVar16;

          auStack_48[lVar5 + lVar10] = 0;

          *(undefined8 *)((longlong)auStack_70 + lVar5 + lVar10) = 0x140221821;

          FUN_140183990(lVar17,uVar3,uVar9,uVar8);

          uVar11 = (ulonglong)(uVar15 + 1);

        }

      }

      if (uVar7 <= uVar14) break;

      puVar16 = (undefined4 *)(puVar2 + uVar12 * 0xc);

      *(undefined8 *)((longlong)auStack_70 + lVar5 + lVar10) = 0x1402217a0;

      uVar8 = FUN_140221f30(puVar16);

      uVar9 = *puVar16;

      auStack_48[lVar5 + lVar10] = 1;

      *(undefined8 *)((longlong)auStack_70 + lVar5 + lVar10) = 0x1402217b6;

      FUN_140183990(lVar17,uVar3,uVar9,uVar8);

      uVar12 = (ulonglong)(uVar14 + 1);

    }

  }

  return;

}




