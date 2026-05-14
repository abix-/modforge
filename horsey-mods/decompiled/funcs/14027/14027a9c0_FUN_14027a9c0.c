// Address: 0x14027a9c0
// Ghidra name: FUN_14027a9c0
// ============ 0x14027a9c0 FUN_14027a9c0 (size=128) ============


uint FUN_14027a9c0(longlong param_1)



{

  int iVar1;

  uint uVar2;

  longlong *plVar3;

  undefined4 local_18;

  undefined8 local_14;

  

  local_18 = 0xc00f0008;

  local_14 = 0;

  FUN_1402083c0(param_1,"Xbox 360 Wireless Controller");

  plVar3 = (longlong *)FUN_1401841a0(1,0x58);

  uVar2 = (uint)plVar3;

  if (plVar3 != (longlong *)0x0) {

    *plVar3 = param_1;

    *(longlong **)(param_1 + 0x70) = plVar3;

    iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_18,0xc);

    if (iVar1 == 0xc) {

      *(undefined4 *)(param_1 + 0x5c) = 2;

      return 1;

    }

    uVar2 = FUN_14012e850("Couldn\'t write init packet");

  }

  return uVar2 & 0xffffff00;

}




