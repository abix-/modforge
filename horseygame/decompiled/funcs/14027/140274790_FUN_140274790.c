// Address: 0x140274790
// Ghidra name: FUN_140274790
// ============ 0x140274790 FUN_140274790 (size=140) ============


undefined8 FUN_140274790(longlong param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)



{

  longlong lVar1;

  int iVar2;

  undefined8 uVar3;

  undefined2 local_res8;

  byte local_resa;

  undefined1 local_resb;

  byte local_resc;

  undefined2 local_resd;

  

  local_resa = (byte)((ulonglong)param_3 >> 8);

  local_resc = (byte)((ushort)param_4 >> 8);

  if (*(short *)(param_1 + 0x22) == 0x7210) {

    local_res8 = 1;

    local_resb = 0;

    local_resd = 0;

    iVar2 = FUN_140284590(param_1,&local_res8,7);

    if (iVar2 != 7) {

      uVar3 = FUN_14012e850("Couldn\'t send rumble packet");

      return uVar3;

    }

  }

  else {

    lVar1 = *(longlong *)(param_1 + 0x70);

    *(byte *)(lVar1 + 0x12) = local_resa >> 3;

    *(byte *)(lVar1 + 0x13) = local_resc >> 3;

    *(undefined1 *)(lVar1 + 0x11) = 1;

    if (*(char *)(lVar1 + 0x10) == '\0') {

      uVar3 = FUN_140275210();

      return uVar3;

    }

  }

  return 1;

}




