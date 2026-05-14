// Address: 0x1401a7a20
// Ghidra name: FUN_1401a7a20
// ============ 0x1401a7a20 FUN_1401a7a20 (size=312) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1401a7a20(longlong param_1)



{

  undefined8 uVar1;

  undefined8 uVar2;

  uint uVar3;

  uint uVar4;

  

  uVar2 = _UNK_1403102a8;

  uVar1 = _DAT_1403102a0;

  *(undefined8 *)(param_1 + 0x8f4a) = _DAT_1403102a0;

  *(undefined8 *)(param_1 + 0x8f52) = uVar2;

  *(undefined8 *)(param_1 + 0x8f5a) = uVar1;

  *(undefined8 *)(param_1 + 0x8f62) = uVar2;

  *(undefined8 *)(param_1 + 0x8f6a) = uVar1;

  *(undefined8 *)(param_1 + 0x8f72) = uVar2;

  *(undefined8 *)(param_1 + 0x8f7a) = uVar1;

  *(undefined8 *)(param_1 + 0x8f82) = uVar2;

  *(undefined8 *)(param_1 + 0x8f8a) = uVar1;

  *(undefined8 *)(param_1 + 0x8f92) = uVar2;

  *(undefined8 *)(param_1 + 0x8f9a) = uVar1;

  *(undefined8 *)(param_1 + 0x8fa2) = uVar2;

  *(undefined8 *)(param_1 + 0x8faa) = uVar1;

  *(undefined8 *)(param_1 + 0x8fb2) = uVar2;

  *(undefined8 *)(param_1 + 0x8fba) = uVar1;

  *(undefined8 *)(param_1 + 0x8fc2) = uVar2;

  *(undefined8 *)(param_1 + 0x8fca) = uVar1;

  *(undefined8 *)(param_1 + 0x8fd2) = uVar2;

  uVar2 = _UNK_1403102b8;

  uVar1 = _DAT_1403102b0;

  *(undefined8 *)(param_1 + 0x8fda) = _DAT_1403102b0;

  *(undefined8 *)(param_1 + 0x8fe2) = uVar2;

  *(undefined8 *)(param_1 + 0x8fea) = uVar1;

  *(undefined8 *)(param_1 + 0x8ff2) = uVar2;

  *(undefined8 *)(param_1 + 0x8ffa) = uVar1;

  *(undefined8 *)(param_1 + 0x9002) = uVar2;

  *(undefined8 *)(param_1 + 0x900a) = uVar1;

  *(undefined8 *)(param_1 + 0x9012) = uVar2;

  *(undefined8 *)(param_1 + 0x901a) = uVar1;

  *(undefined8 *)(param_1 + 0x9022) = uVar2;

  *(undefined8 *)(param_1 + 0x902a) = uVar1;

  *(undefined8 *)(param_1 + 0x9032) = uVar2;

  *(undefined8 *)(param_1 + 0x903a) = uVar1;

  *(undefined8 *)(param_1 + 0x9042) = uVar2;

  uVar2 = _UNK_140310298;

  uVar1 = _DAT_140310290;

  *(undefined8 *)(param_1 + 0x904a) = _DAT_140310290;

  *(undefined8 *)(param_1 + 0x9052) = uVar2;

  *(undefined8 *)(param_1 + 0x905a) = uVar1;

  uVar2 = _UNK_14033c2d8;

  uVar1 = _DAT_14033c2d0;

  *(undefined4 *)(param_1 + 0x9062) = 0x8080808;

  *(undefined4 *)(param_1 + 0x9066) = 0x8080808;

  *(undefined8 *)(param_1 + 0x906a) = uVar1;

  *(undefined8 *)(param_1 + 0x9072) = uVar2;

  *(undefined8 *)(param_1 + 0x907a) = uVar1;

  *(undefined8 *)(param_1 + 0x9082) = uVar2;

  FUN_1401a6e50(param_1,0,0x120,0xf,1);

  FUN_1401a6e50(param_1,1,0x20,0xf,1);

  uVar4 = *(uint *)(param_1 + 0x60) | 1 << (*(uint *)(param_1 + 0x5c) & 0x1f);

  uVar3 = *(uint *)(param_1 + 0x5c) + 2;

  *(uint *)(param_1 + 0x60) = uVar4;

  *(uint *)(param_1 + 0x5c) = uVar3;

  while (7 < uVar3) {

    if (*(undefined1 **)(param_1 + 0x40) < *(undefined1 **)(param_1 + 0x48)) {

      **(undefined1 **)(param_1 + 0x40) = (char)uVar4;

      *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + 1;

    }

    *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) >> 8;

    *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + -8;

    uVar4 = (uint)*(byte *)(param_1 + 0x60);

    uVar3 = *(uint *)(param_1 + 0x5c);

  }

  return;

}




