// Address: 0x140280c50
// Ghidra name: FUN_140280c50
// ============ 0x140280c50 FUN_140280c50 (size=143) ============


undefined8 FUN_140280c50(longlong param_1,undefined8 param_2,undefined2 param_3,undefined2 param_4)



{

  int iVar1;

  undefined8 uVar2;

  undefined1 uVar3;

  undefined1 uVar4;

  bool bVar5;

  undefined2 local_res8;

  undefined1 local_resa;

  undefined1 local_resb;

  undefined4 local_18;

  undefined1 local_14;

  undefined1 local_13;

  undefined1 local_12;

  undefined2 local_11;

  undefined1 local_f;

  

  uVar3 = (undefined1)((ushort)param_3 >> 8);

  uVar4 = (undefined1)((ushort)param_4 >> 8);

  if (*(short *)(param_1 + 0x20) == 0x4b4) {

    local_res8 = 0xf05;

    local_resa = uVar3;

    local_resb = uVar4;

    iVar1 = FUN_140284590(param_1,&local_res8,4);

    bVar5 = iVar1 == 4;

  }

  else {

    local_18 = 0x12a55a03;

    local_14 = 6;

    local_11 = 0;

    local_f = 0;

    local_13 = uVar3;

    local_12 = uVar4;

    iVar1 = FUN_140284590(param_1,&local_18,10);

    bVar5 = iVar1 == 10;

  }

  if (!bVar5) {

    uVar2 = FUN_14012e850("Couldn\'t send rumble packet");

    return uVar2;

  }

  return 1;

}




