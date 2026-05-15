// Address: 0x14017a300
// Ghidra name: FUN_14017a300
// ============ 0x14017a300 FUN_14017a300 (size=99) ============


void FUN_14017a300(longlong param_1,uint *param_2,uint *param_3)



{

  uint uVar1;

  uint uVar2;

  

  if (*(uint *)(param_1 + 0x14) != 0) {

    *param_2 = *(uint *)(param_1 + 0x14);

    *param_3 = (uint)*(byte *)(param_1 + 0x1f);

    return;

  }

  uVar2 = ~(*(uint *)(param_1 + 0x10) | *(uint *)(param_1 + 0xc) | *(uint *)(param_1 + 8));

  *param_2 = uVar2;

  if (uVar2 == 0xff) {

    *param_3 = 0;

    return;

  }

  if (uVar2 == 0xff00) {

    *param_3 = 8;

    return;

  }

  if (uVar2 != 0xff0000) {

    uVar1 = 0x18;

    if (uVar2 != 0xff000000) {

      uVar1 = 0;

    }

    *param_3 = uVar1;

    return;

  }

  *param_3 = 0x10;

  return;

}




