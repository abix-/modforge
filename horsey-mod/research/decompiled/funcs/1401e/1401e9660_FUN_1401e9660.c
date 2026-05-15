// Address: 0x1401e9660
// Ghidra name: FUN_1401e9660
// ============ 0x1401e9660 FUN_1401e9660 (size=521) ============


undefined8 FUN_1401e9660(longlong param_1,longlong param_2)



{

  undefined4 uVar1;

  undefined4 *puVar2;

  longlong lVar3;

  undefined8 uVar4;

  undefined8 *puVar5;

  uint uVar6;

  uint uVar7;

  undefined8 local_b8 [4];

  undefined8 local_98;

  undefined1 local_88 [112];

  

  puVar2 = *(undefined4 **)(param_2 + 0x30);

  uVar4 = *(undefined8 *)(param_1 + 0x2e0);

  lVar3 = *(longlong *)(puVar2 + 0x4e);

  if (lVar3 == 0) {

    uVar4 = FUN_14012e850("Texture is not currently available");

    return uVar4;

  }

  FUN_1401e9e20(param_1,param_2,puVar2,local_88);

  FUN_1401ea070(uVar4,*(undefined8 *)(lVar3 + 8),*(undefined4 *)(lVar3 + 0x18),0x80);

  local_b8[0] = *(undefined8 *)(lVar3 + 0x10);

  *(undefined4 *)(lVar3 + 0x18) = 0x80;

  uVar6 = 1;

  puVar5 = (undefined8 *)

           FUN_1401e7f40(uVar4,*puVar2,*(undefined4 *)(param_2 + 0x38),

                         *(undefined4 *)(param_2 + 0x3c),*(undefined4 *)(param_2 + 0x40));

  if (puVar5 == (undefined8 *)0x0) {

LAB_1401e9846:

    uVar4 = 0;

  }

  else {

    local_b8[3] = *puVar5;

    if (*(longlong *)(puVar2 + 0x38) != 0) {

      puVar5 = *(undefined8 **)(*(longlong *)(puVar2 + 0x38) + 0x10);

      FUN_1401ea070(uVar4,*puVar5,*(undefined4 *)(puVar5 + 2),0x80);

      local_b8[1] = puVar5[1];

      *(undefined4 *)(puVar5 + 2) = 0x80;

      uVar6 = 2;

      puVar5 = (undefined8 *)FUN_1401e7f40(uVar4,0,0,1,1);

      if (puVar5 == (undefined8 *)0x0) goto LAB_1401e9846;

      local_98 = *puVar5;

    }

    if (*(char *)(lVar3 + 0x50) == '\0') {

      uVar7 = uVar6;

      if (*(char *)(lVar3 + 0x98) != '\0') {

        FUN_1401ea070(uVar4,*(undefined8 *)(lVar3 + 8),*(undefined4 *)(lVar3 + 0x18),0x80);

        uVar7 = uVar6 + 1;

        *(undefined4 *)(lVar3 + 0x18) = 0x80;

        local_b8[uVar6] = *(undefined8 *)(lVar3 + 0xa0);

      }

    }

    else {

      FUN_1401ea070(uVar4,*(undefined8 *)(lVar3 + 0x58),*(undefined4 *)(lVar3 + 0x68),0x80);

      uVar1 = *(undefined4 *)(lVar3 + 0x88);

      *(undefined4 *)(lVar3 + 0x68) = 0x80;

      local_b8[uVar6] = *(undefined8 *)(lVar3 + 0x60);

      FUN_1401ea070(uVar4,*(undefined8 *)(lVar3 + 0x78),uVar1,0x80);

      local_b8[uVar6 + 1] = *(undefined8 *)(lVar3 + 0x80);

      *(undefined4 *)(lVar3 + 0x88) = 0x80;

      uVar7 = uVar6 + 2;

    }

    uVar4 = FUN_1401e9870(param_1,param_2,local_88,3,uVar7,local_b8,uVar6,local_b8 + 3);

  }

  return uVar4;

}




