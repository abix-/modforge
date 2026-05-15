// Address: 0x140175740
// Ghidra name: FUN_140175740
// ============ 0x140175740 FUN_140175740 (size=379) ============


ulonglong FUN_140175740(longlong param_1,undefined8 *param_2)



{

  undefined8 *puVar1;

  longlong lVar2;

  undefined8 uVar3;

  char cVar4;

  ulonglong uVar5;

  longlong *plVar6;

  longlong lVar7;

  ulonglong uVar8;

  char *pcVar9;

  

  if (param_1 == 0) {

LAB_1401758af:

    pcVar9 = "haptic";

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar4 = FUN_1401aa7c0(param_1,6);

      if (cVar4 == '\0') goto LAB_1401758af;

    }

    if (param_2 != (undefined8 *)0x0) {

      cVar4 = FUN_140175d80(param_1,param_2);

      if (cVar4 == '\0') {

        FUN_14012e850("Haptic: Effect not supported by haptic device.");

        return 0xffffffff;

      }

      cVar4 = FUN_14021b070(param_1);

      if (cVar4 != '\0') {

        uVar5 = FUN_14021b0d0(param_1,param_2);

        return uVar5;

      }

      uVar5 = 0;

      if (0 < *(int *)(param_1 + 0x18)) {

        plVar6 = (longlong *)(*(longlong *)(param_1 + 0x10) + 0x48);

        uVar8 = uVar5;

        do {

          if (*plVar6 == 0) {

            lVar7 = (longlong)(int)uVar8;

            cVar4 = FUN_14021ace0(param_1,*(longlong *)(param_1 + 0x10) + lVar7 * 0x50,param_2);

            if (cVar4 == '\0') {

              uVar8 = 0xffffffff;

            }

            else {

              uVar3 = param_2[1];

              lVar2 = *(longlong *)(param_1 + 0x10);

              puVar1 = (undefined8 *)(lVar2 + lVar7 * 0x50);

              *puVar1 = *param_2;

              puVar1[1] = uVar3;

              uVar3 = param_2[3];

              puVar1 = (undefined8 *)(lVar2 + 0x10 + lVar7 * 0x50);

              *puVar1 = param_2[2];

              puVar1[1] = uVar3;

              uVar3 = param_2[5];

              puVar1 = (undefined8 *)(lVar2 + 0x20 + lVar7 * 0x50);

              *puVar1 = param_2[4];

              puVar1[1] = uVar3;

              uVar3 = param_2[7];

              puVar1 = (undefined8 *)(lVar2 + 0x30 + lVar7 * 0x50);

              *puVar1 = param_2[6];

              puVar1[1] = uVar3;

              *(undefined8 *)(lVar2 + 0x40 + lVar7 * 0x50) = param_2[8];

            }

            return uVar8;

          }

          uVar8 = (ulonglong)((int)uVar8 + 1);

          uVar5 = uVar5 + 1;

          plVar6 = plVar6 + 10;

        } while ((longlong)uVar5 < (longlong)*(int *)(param_1 + 0x18));

      }

      FUN_14012e850("Haptic: Device has no free space left.");

      return 0xffffffff;

    }

    pcVar9 = "effect";

  }

  FUN_14012e850("Parameter \'%s\' is invalid",pcVar9);

  return 0xffffffff;

}




