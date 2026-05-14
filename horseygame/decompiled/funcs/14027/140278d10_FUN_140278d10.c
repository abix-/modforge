// Address: 0x140278d10
// Ghidra name: FUN_140278d10
// ============ 0x140278d10 FUN_140278d10 (size=168) ============


void FUN_140278d10(longlong param_1,undefined8 param_2)



{

  byte bVar1;

  undefined8 uVar2;

  

  bVar1 = *(byte *)(param_1 + 0x2c);

  uVar2 = FUN_140149300();

  *(undefined8 *)(param_1 + 0x10) = uVar2;

  if (bVar1 == 0x20) {

    FUN_140279220(param_1,param_2);

    return;

  }

  if (1 < bVar1 - 0x21) {

    if (bVar1 - 0x30 < 0x10) {

      FUN_140278930(param_1,param_2);

      return;

    }

    FUN_14012e080(7,"HIDAPI Wii: Unexpected input packet of type %x",bVar1);

    return;

  }

  FUN_140279100(param_1,param_2);

  return;

}




