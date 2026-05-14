// Address: 0x140204140
// Ghidra name: FUN_140204140
// ============ 0x140204140 FUN_140204140 (size=311) ============


undefined8 FUN_140204140(longlong param_1)



{

  longlong lVar1;

  char cVar2;

  undefined4 uVar3;

  undefined8 uVar4;

  int local_res8 [2];

  int local_res10 [2];

  longlong local_res18 [2];

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  undefined8 uStack_60;

  longlong local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  uVar4 = *(undefined8 *)(lVar1 + 0xa0);

  if (*(longlong *)(param_1 + 0x118) != 0) {

    cVar2 = FUN_1401389e0(uVar4,*(longlong *)(param_1 + 0x118),local_res18,local_res10,local_res8);

    if (cVar2 == '\0') {

      uVar4 = FUN_14012e730();

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"Failed to acquire swapchain texture: %s",uVar4);

    }

    if (local_res18[0] != 0) {

      local_78 = *(undefined8 *)(lVar1 + 0x58);

      local_68 = 0;

      local_48 = 0;

      uStack_70 = 0;

      uStack_60 = *(undefined8 *)(lVar1 + 100);

      uStack_50 = 0;

      local_58 = local_res18[0];

      uStack_30 = 0;

      local_28 = 0;

      local_38 = 2;

      uStack_20 = 1;

      FUN_140133e30(*(undefined8 *)(lVar1 + 0xa0),&local_78);

      FUN_140138650(*(undefined8 *)(lVar1 + 0xa0));

      if ((local_res10[0] != *(int *)(lVar1 + 100)) || (local_res8[0] != *(int *)(lVar1 + 0x68))) {

        uVar3 = FUN_140137880(*(undefined8 *)(lVar1 + 8),*(undefined8 *)(param_1 + 0x118));

        FUN_140202fc0(lVar1,local_res10[0],local_res8[0],uVar3);

      }

      goto LAB_14020425a;

    }

    uVar4 = *(undefined8 *)(lVar1 + 0xa0);

  }

  FUN_140138650(uVar4);

LAB_14020425a:

  uVar4 = FUN_140132770(*(undefined8 *)(lVar1 + 8));

  *(undefined8 *)(lVar1 + 0xa0) = uVar4;

  return 1;

}




