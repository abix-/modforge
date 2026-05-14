// Address: 0x140149810
// Ghidra name: FUN_140149810
// ============ 0x140149810 FUN_140149810 (size=480) ============


undefined8 FUN_140149810(longlong param_1)



{

  undefined4 *puVar1;

  int iVar2;

  uint uVar3;

  ulonglong uVar4;

  longlong lVar5;

  undefined4 *puVar6;

  longlong lVar7;

  undefined4 *puVar8;

  undefined4 *puVar9;

  undefined4 *puVar10;

  ulonglong uVar11;

  

  puVar8 = (undefined4 *)0x0;

  puVar9 = (undefined4 *)0x0;

  do {

    FUN_14018b130(param_1 + 0xb0);

    lVar5 = *(longlong *)(param_1 + 0xc0);

    *(undefined8 *)(param_1 + 0xc0) = 0;

    if (puVar8 != (undefined4 *)0x0) {

      *(undefined8 *)(puVar9 + 0xe) = *(undefined8 *)(param_1 + 200);

      *(undefined4 **)(param_1 + 200) = puVar8;

    }

    FUN_14018b190(param_1 + 0xb0);

    while (lVar5 != 0) {

      lVar7 = *(longlong *)(lVar5 + 0x38);

      FUN_140149000(param_1,lVar5);

      lVar5 = lVar7;

    }

    iVar2 = FUN_140138fe0(param_1 + 0xd0);

    if (iVar2 == 0) {

      return 0;

    }

    uVar11 = 0xffffffffffffffff;

    uVar4 = FUN_140149300();

    puVar1 = *(undefined4 **)(param_1 + 0xd8);

    puVar8 = (undefined4 *)0x0;

    puVar9 = (undefined4 *)0x0;

    while (puVar10 = puVar1, puVar10 != (undefined4 *)0x0) {

      if (uVar4 < *(ulonglong *)(puVar10 + 10)) {

        uVar11 = *(ulonglong *)(puVar10 + 10) - uVar4;

        break;

      }

      *(undefined8 *)(param_1 + 0xd8) = *(undefined8 *)(puVar10 + 0xe);

      iVar2 = FUN_140138fe0(puVar10 + 0xc);

      if (iVar2 == 0) {

        if (*(code **)(puVar10 + 2) == (code *)0x0) {

          lVar5 = (**(code **)(puVar10 + 4))(*(undefined8 *)(puVar10 + 6),*puVar10);

        }

        else {

          uVar3 = (**(code **)(puVar10 + 2))

                            (*(undefined8 *)(puVar10 + 6),*puVar10,

                             *(ulonglong *)(puVar10 + 8) / 1000000 & 0xffffffff);

          lVar5 = (ulonglong)uVar3 * 1000000;

        }

        if (lVar5 == 0) goto LAB_140149964;

        *(longlong *)(puVar10 + 8) = lVar5;

        *(ulonglong *)(puVar10 + 10) = lVar5 + uVar4;

        FUN_140149000(param_1,puVar10);

        puVar6 = puVar8;

        puVar10 = puVar9;

      }

      else {

LAB_140149964:

        puVar6 = puVar10;

        if (puVar8 != (undefined4 *)0x0) {

          puVar6 = puVar8;

        }

        if (puVar9 != (undefined4 *)0x0) {

          *(undefined4 **)(puVar9 + 0xe) = puVar10;

        }

        FUN_140139010(puVar10 + 0xc,1);

      }

      puVar8 = puVar6;

      puVar9 = puVar10;

      puVar1 = *(undefined4 **)(param_1 + 0xd8);

    }

    lVar7 = FUN_140149300();

    lVar5 = 0;

    if (lVar7 - uVar4 <= uVar11) {

      lVar5 = uVar11 - (lVar7 - uVar4);

    }

    FUN_14017ceb0(*(undefined8 *)(param_1 + 0xb8),lVar5);

  } while( true );

}




