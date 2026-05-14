// Address: 0x1401827a0
// Ghidra name: FUN_1401827a0
// ============ 0x1401827a0 FUN_1401827a0 (size=357) ============


undefined * FUN_1401827a0(uint param_1)



{

  int iVar1;

  undefined *puVar2;

  undefined8 uVar3;

  undefined1 *puVar4;

  uint uVar5;

  byte local_res8 [8];

  undefined1 local_res10 [8];

  

  if ((param_1 >> 0x1e & 1) != 0) {

    puVar2 = (undefined *)FUN_140182c30(param_1 & 0xbfffffff);

    return puVar2;

  }

  if ((param_1 >> 0x1d & 1) != 0) {

    if (((param_1 & 0xdfffffff) != 0) && (uVar5 = (param_1 & 0xdfffffff) - 1, uVar5 < 7)) {

      return (&PTR_s_LeftTab_1403e3940)[uVar5];

    }

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140331e68);

    return &DAT_14039bcb9;

  }

  switch(param_1) {

  case 8:

    puVar2 = (undefined *)FUN_140182c30(0x2a);

    return puVar2;

  case 9:

    puVar2 = (undefined *)FUN_140182c30(0x2b);

    return puVar2;

  case 0xd:

    puVar2 = (undefined *)FUN_140182c30(0x28);

    return puVar2;

  case 0x1b:

    puVar2 = (undefined *)FUN_140182c30(0x29);

    return puVar2;

  case 0x20:

    puVar2 = (undefined *)FUN_140182c30(0x2c);

    return puVar2;

  case 0x7f:

    puVar2 = (undefined *)FUN_140182c30(0x4c);

    return puVar2;

  }

  if ((0x7f < param_1) || (param_1 - 0x61 < 0x1a)) {

    uVar3 = FUN_1401831d0(0);

    iVar1 = FUN_140182b50(uVar3,param_1,local_res8);

    if (((iVar1 != 0) && ((local_res8[0] & 3) == 0)) &&

       ((uVar5 = FUN_1401829a0(uVar3,iVar1,3), 0x7f < uVar5 || (uVar5 - 0x41 < 0x1a)))) {

      param_1 = uVar5;

    }

  }

  puVar4 = (undefined1 *)FUN_14012ed70(param_1,local_res10);

  *puVar4 = 0;

  puVar2 = (undefined *)FUN_1401aa890(local_res10);

  return puVar2;

}




