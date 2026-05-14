// Address: 0x1401e3ba0
// Ghidra name: FUN_1401e3ba0
// ============ 0x1401e3ba0 FUN_1401e3ba0 (size=365) ============


undefined8 FUN_1401e3ba0(longlong param_1,longlong param_2,undefined8 param_3)



{

  undefined4 *puVar1;

  longlong lVar2;

  undefined8 uVar3;

  uint uVar4;

  uint uVar5;

  undefined8 in_stack_ffffffffffffff28;

  undefined4 uVar6;

  longlong local_b8 [4];

  longlong local_98;

  undefined1 local_88 [112];

  

  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffff28 >> 0x20);

  puVar1 = *(undefined4 **)(param_2 + 0x30);

  uVar3 = *(undefined8 *)(param_1 + 0x2e0);

  lVar2 = *(longlong *)(puVar1 + 0x4e);

  if (lVar2 == 0) {

    uVar3 = FUN_14012e850("Texture is not currently available");

    return uVar3;

  }

  FUN_1401e42a0(param_1,param_2,puVar1,local_88);

  local_b8[0] = *(longlong *)(lVar2 + 0x10);

  uVar4 = 1;

  local_b8[3] = FUN_1401e2330(uVar3,*puVar1,*(undefined4 *)(param_2 + 0x38),

                              *(undefined4 *)(param_2 + 0x3c),

                              CONCAT44(uVar6,*(undefined4 *)(param_2 + 0x40)));

  if (local_b8[3] == 0) {

LAB_1401e3ce5:

    uVar3 = 0;

  }

  else {

    if (*(longlong *)(puVar1 + 0x38) != 0) {

      uVar4 = 2;

      local_b8[1] = *(undefined8 *)(*(longlong *)(*(longlong *)(puVar1 + 0x38) + 0x10) + 8);

      local_98 = FUN_1401e2330(uVar3,0,0,1,1);

      if (local_98 == 0) goto LAB_1401e3ce5;

    }

    if (*(char *)(lVar2 + 0x38) == '\0') {

      uVar5 = uVar4;

      if (*(char *)(lVar2 + 0x60) != '\0') {

        uVar5 = uVar4 + 1;

        local_b8[uVar4] = *(longlong *)(lVar2 + 0x68);

      }

    }

    else {

      local_b8[uVar4] = *(longlong *)(lVar2 + 0x48);

      local_b8[uVar4 + 1] = *(longlong *)(lVar2 + 0x58);

      uVar5 = uVar4 + 2;

    }

    uVar3 = FUN_1401e3d10(param_1,param_2,local_88,uVar5,local_b8,uVar4,local_b8 + 3,param_3);

  }

  return uVar3;

}




