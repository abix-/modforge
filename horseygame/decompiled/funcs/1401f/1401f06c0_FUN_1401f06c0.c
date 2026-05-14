// Address: 0x1401f06c0
// Ghidra name: FUN_1401f06c0
// ============ 0x1401f06c0 FUN_1401f06c0 (size=424) ============


undefined8 FUN_1401f06c0(longlong param_1,uint param_2,int param_3)



{

  undefined4 uVar1;

  longlong lVar2;

  undefined8 uVar3;

  longlong lVar4;

  int iVar5;

  int iVar6;

  int local_res20 [2];

  int local_58 [2];

  longlong local_50 [5];

  

  uVar1 = 0;

  local_58[0] = 0;

  lVar2 = FUN_140240f00(param_2);

  if (lVar2 == 0) {

    uVar3 = FUN_14012e850("No shader body src");

    return uVar3;

  }

  iVar6 = 0;

  do {

    if (local_58[0] != 0) goto LAB_1401f0865;

    local_50[0] = FUN_140241070((ulonglong)param_2);

    iVar5 = 1;

    lVar4 = 1;

    if (param_3 == 0x8b30) {

      if (iVar6 == 0) {

        uVar1 = *(undefined4 *)(param_1 + 0x310);

      }

      else {

        uVar1 = 4;

      }

      local_50[1] = FUN_140241030(uVar1);

      iVar5 = 2;

      lVar4 = 2;

    }

    local_50[lVar4] = lVar2;

    uVar1 = (**(code **)(param_1 + 0x60))(param_3);

    (**(code **)(param_1 + 0x120))(uVar1,iVar5 + 1,local_50,0);

    (**(code **)(param_1 + 0x50))(uVar1);

    (**(code **)(param_1 + 0xe8))(uVar1,0x8b81,local_58);

    iVar6 = iVar6 + 1;

  } while (iVar6 < 2);

  if (local_58[0] == 0) {

    local_res20[0] = 0;

    (**(code **)(param_1 + 0xe8))(uVar1,0x8b84,local_res20);

    if (0 < local_res20[0]) {

      lVar2 = FUN_1401841f0((longlong)local_res20[0]);

      if (lVar2 != 0) {

        (**(code **)(param_1 + 0xe0))(uVar1,local_res20[0],local_res20,lVar2);

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(6,"Failed to load the shader %d: %s",param_2,lVar2);

      }

    }

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(6,"Failed to load the shader %d",param_2);

  }

LAB_1401f0865:

  *(undefined4 *)(param_1 + 0x1e4 + (ulonglong)param_2 * 4) = uVar1;

  return 1;

}




