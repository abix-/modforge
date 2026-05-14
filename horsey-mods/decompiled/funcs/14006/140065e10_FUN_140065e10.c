// Address: 0x140065e10
// Ghidra name: FUN_140065e10
// ============ 0x140065e10 FUN_140065e10 (size=370) ============


void FUN_140065e10(longlong param_1)



{

  ulonglong uVar1;

  undefined8 uVar2;

  ulonglong uVar3;

  uint uVar4;

  undefined8 *puVar6;

  undefined8 *puVar7;

  undefined8 local_48;

  undefined8 uStack_40;

  ulonglong local_38;

  ulonglong local_30;

  ulonglong uVar5;

  

  uVar5 = 0;

  puVar6 = (undefined8 *)(param_1 + 600);

  do {

    local_38 = 0;

    puVar7 = (undefined8 *)(uVar5 * 0x20 + 600 + param_1);

    local_30 = 0;

    local_48 = 0;

    uStack_40 = 0;

    if (0xf < (ulonglong)puVar6[3]) {

      puVar7 = (undefined8 *)*puVar6;

    }

    uVar1 = puVar6[2];

    if (0x7fffffffffffffff < uVar1) {

                    /* WARNING: Subroutine does not return */

      FUN_140024130();

    }

    if (uVar1 < 0x10) {

      local_30 = 0xf;

      local_48 = *puVar7;

      uStack_40 = puVar7[1];

      local_38 = uVar1;

    }

    else {

      uVar3 = uVar1 | 0xf;

      if (uVar3 < 0x8000000000000000) {

        if (uVar3 < 0x16) {

          uVar3 = 0x16;

        }

      }

      else {

        uVar3 = 0x7fffffffffffffff;

      }

      local_48 = FUN_1400285e0(uVar3 + 1);

      local_38 = uVar1;

      local_30 = uVar3;

      FUN_1402f8e20(local_48,puVar7,uVar1 + 1);

    }

    FUN_140075850(&local_48);

    uVar4 = (int)uVar5 + 1;

    uVar5 = (ulonglong)uVar4;

    puVar6 = puVar6 + 4;

  } while ((int)uVar4 < 4);

  uVar2 = FUN_1400279c0(&local_48,param_1 + 0x2d8);

  FUN_140075850(uVar2);

  uVar2 = FUN_1400279c0(&local_48,param_1 + 0x300);

  FUN_140075850(uVar2);

  FUN_140075670(*(undefined4 *)(param_1 + 800));

  FUN_140075750(*(undefined1 *)(param_1 + 0x2f8));

  FUN_140075750(*(undefined1 *)(param_1 + 0x325));

  return;

}




