// Address: 0x1400dc1a0
// Ghidra name: FUN_1400dc1a0
// ============ 0x1400dc1a0 FUN_1400dc1a0 (size=285) ============


void FUN_1400dc1a0(longlong param_1)



{

  ulonglong uVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  undefined8 *puVar4;

  undefined8 local_28;

  undefined8 uStack_20;

  ulonglong local_18;

  ulonglong local_10;

  

  local_28 = 0;

  uStack_20 = 0;

  if (*(int *)(param_1 + 600) != 0) {

    local_18 = 6;

    local_10 = 0xf;

    local_28 = (ulonglong)CONCAT24(s_Stable_14030f134._4_2_,s_Stable_14030f134._0_4_);

    FUN_14003f340(&local_28,1);

    return;

  }

  puVar4 = (undefined8 *)(param_1 + 0x38);

  local_18 = 0;

  local_10 = 0;

  if (0xf < *(ulonglong *)(param_1 + 0x50)) {

    puVar4 = *(undefined8 **)(param_1 + 0x38);

  }

  uVar1 = *(ulonglong *)(param_1 + 0x48);

  if (uVar1 < 0x8000000000000000) {

    if (uVar1 < 0x10) {

      local_10 = 0xf;

      local_28 = *puVar4;

      uStack_20 = puVar4[1];

      local_18 = uVar1;

    }

    else {

      uVar2 = uVar1 | 0xf;

      uVar3 = 0x7fffffffffffffff;

      if ((uVar2 < 0x8000000000000000) && (uVar3 = uVar2, uVar2 < 0x16)) {

        uVar3 = 0x16;

      }

      local_28 = FUN_1400285e0(uVar3 + 1);

      local_18 = uVar1;

      local_10 = uVar3;

      FUN_1402f8e20(local_28,puVar4,uVar1 + 1);

    }

    FUN_14003f340(&local_28,1);

    return;

  }

                    /* WARNING: Subroutine does not return */

  FUN_140024130();

}




