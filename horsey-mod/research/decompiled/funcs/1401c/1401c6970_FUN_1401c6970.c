// Address: 0x1401c6970
// Ghidra name: FUN_1401c6970
// ============ 0x1401c6970 FUN_1401c6970 (size=919) ============


undefined8 FUN_1401c6970(longlong param_1,longlong param_2,char param_3)



{

  longlong *plVar1;

  byte bVar2;

  int iVar3;

  undefined8 uVar4;

  ulonglong uVar5;

  uint uVar6;

  ulonglong uVar7;

  uint uVar8;

  bool bVar9;

  

  uVar7 = 0;

  bVar9 = true;

  uVar5 = uVar7;

  if (*(int *)(param_2 + 0x9b8) != 0) {

    do {

      if (param_3 == '\0') {

        bVar2 = FUN_1401c7440(param_2,*(undefined8 *)(*(longlong *)(param_2 + 0x9b0) + uVar5 * 8));

        bVar9 = (bVar9 & bVar2) != 0;

      }

      FUN_1401841e0(*(undefined8 *)(*(longlong *)(param_2 + 0x9b0) + uVar5 * 8));

      uVar8 = (int)uVar5 + 1;

      uVar5 = (ulonglong)uVar8;

    } while (uVar8 < *(uint *)(param_2 + 0x9b8));

  }

  *(undefined4 *)(param_2 + 0x9b8) = 0;

  if (bVar9 != false) {

    iVar3 = (**(code **)(**(longlong **)(param_2 + 0x118) + 0x40))();

    if (-1 < iVar3) {

      iVar3 = (**(code **)(**(longlong **)(param_2 + 0x120) + 0x50))

                        (*(longlong **)(param_2 + 0x120),*(undefined8 *)(param_2 + 0x118),0);

      if (iVar3 < 0) {

        FUN_1401cb240(param_1,"Could not reset command list",iVar3);

        return 0;

      }

      uVar5 = uVar7;

      if (*(int *)(param_2 + 0x1f8) != 0) {

        do {

          FUN_1401cb150(param_1,*(undefined8 *)(*(longlong *)(param_2 + 0x1f0) + uVar5 * 8));

          uVar8 = (int)uVar5 + 1;

          uVar5 = (ulonglong)uVar8;

        } while (uVar8 < *(uint *)(param_2 + 0x1f8));

      }

      *(undefined4 *)(param_2 + 0x1f8) = 0;

      *(undefined8 *)(param_2 + 0x1e0) = 0;

      *(undefined8 *)(param_2 + 0x1e8) = 0;

      FUN_140179b40(*(undefined8 *)(param_1 + 0x208));

      uVar5 = uVar7;

      if (*(int *)(param_2 + 0x208) != 0) {

        do {

          FUN_1401cb1d0(param_1,*(undefined8 *)(*(longlong *)(param_2 + 0x200) + uVar5 * 8));

          uVar8 = (int)uVar5 + 1;

          uVar5 = (ulonglong)uVar8;

        } while (uVar8 < *(uint *)(param_2 + 0x208));

      }

      *(undefined4 *)(param_2 + 0x208) = 0;

      FUN_140179b60(*(undefined8 *)(param_1 + 0x208));

      uVar5 = uVar7;

      if (*(int *)(param_2 + 0x968) != 0) {

        do {

          FUN_140138fb0(*(longlong *)(*(longlong *)(param_2 + 0x960) + uVar5 * 8) + 0x48,0xffffffff)

          ;

          uVar8 = (int)uVar5 + 1;

          uVar5 = (ulonglong)uVar8;

        } while (uVar8 < *(uint *)(param_2 + 0x968));

      }

      *(undefined4 *)(param_2 + 0x968) = 0;

      uVar5 = uVar7;

      if (*(int *)(param_2 + 0x978) != 0) {

        do {

          FUN_140138fb0(*(longlong *)(*(longlong *)(param_2 + 0x970) + uVar5 * 8) + 0x88,0xffffffff)

          ;

          uVar8 = (int)uVar5 + 1;

          uVar5 = (ulonglong)uVar8;

        } while (uVar8 < *(uint *)(param_2 + 0x978));

      }

      *(undefined4 *)(param_2 + 0x978) = 0;

      uVar5 = uVar7;

      if (*(int *)(param_2 + 0x988) != 0) {

        do {

          FUN_140138fb0(*(longlong *)(*(longlong *)(param_2 + 0x980) + uVar5 * 8) + 0x58,0xffffffff)

          ;

          uVar8 = (int)uVar5 + 1;

          uVar5 = (ulonglong)uVar8;

        } while (uVar8 < *(uint *)(param_2 + 0x988));

      }

      *(undefined4 *)(param_2 + 0x988) = 0;

      uVar5 = uVar7;

      if (*(int *)(param_2 + 0x998) != 0) {

        do {

          FUN_140138fb0(*(longlong *)(*(longlong *)(param_2 + 0x990) + uVar5 * 8) + 0x74,0xffffffff)

          ;

          uVar8 = (int)uVar5 + 1;

          uVar5 = (ulonglong)uVar8;

        } while (uVar8 < *(uint *)(param_2 + 0x998));

      }

      *(undefined4 *)(param_2 + 0x998) = 0;

      uVar5 = uVar7;

      if (*(int *)(param_2 + 0x9a8) != 0) {

        do {

          FUN_140138fb0(*(longlong *)(*(longlong *)(param_2 + 0x9a0) + uVar5 * 8) + 0x28,0xffffffff)

          ;

          uVar8 = (int)uVar5 + 1;

          uVar5 = (ulonglong)uVar8;

        } while (uVar8 < *(uint *)(param_2 + 0x9a8));

      }

      *(undefined4 *)(param_2 + 0x9a8) = 0;

      *(undefined4 *)(param_2 + 0x140) = 0;

      if (*(char *)(param_2 + 0x130) != '\0') {

        FUN_1401cbf30(param_1,*(undefined8 *)(param_2 + 0x128));

        *(undefined8 *)(param_2 + 0x128) = 0;

      }

      FUN_140179b40(*(undefined8 *)(param_1 + 0x200));

      if (*(int *)(param_1 + 0x118) == *(int *)(param_1 + 0x11c)) {

        uVar8 = *(int *)(param_1 + 0x11c) + 1;

        *(uint *)(param_1 + 0x11c) = uVar8;

        uVar4 = FUN_140184230(*(undefined8 *)(param_1 + 0x110),(ulonglong)uVar8 << 3);

        *(undefined8 *)(param_1 + 0x110) = uVar4;

      }

      *(longlong *)(*(longlong *)(param_1 + 0x110) + (ulonglong)*(uint *)(param_1 + 0x118) * 8) =

           param_2;

      *(int *)(param_1 + 0x118) = *(int *)(param_1 + 0x118) + 1;

      FUN_140179b60(*(undefined8 *)(param_1 + 0x200));

      if ((param_3 == '\0') && (uVar8 = *(uint *)(param_1 + 0x128), uVar8 != 0)) {

        do {

          plVar1 = (longlong *)(*(longlong *)(param_1 + 0x120) + uVar7 * 8);

          if (*plVar1 == param_2) {

            *plVar1 = *(longlong *)(*(longlong *)(param_1 + 0x120) + (ulonglong)(uVar8 - 1) * 8);

            *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) + -1;

            uVar8 = *(uint *)(param_1 + 0x128);

          }

          uVar6 = (int)uVar7 + 1;

          uVar7 = (ulonglong)uVar6;

        } while (uVar6 < uVar8);

      }

      return 1;

    }

    FUN_1401cb240(param_1,"Could not reset command allocator",iVar3);

  }

  return 0;

}




