// Address: 0x140268c40
// Ghidra name: FUN_140268c40
// ============ 0x140268c40 FUN_140268c40 (size=130) ============


undefined1 FUN_140268c40(longlong param_1,undefined8 param_2,char param_3)



{

  longlong lVar1;

  undefined8 uVar2;

  undefined1 uVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  FUN_14026d2a0(lVar1);

  if ((*(char *)(lVar1 + 0x98) != '\0') && ((param_3 == '\0' || (*(char *)(lVar1 + 0x34) != '\0'))))

  {

    *(char *)(lVar1 + 0x99) = param_3;

    *(undefined4 *)(lVar1 + 0xb8) = 0;

    uVar2 = FUN_140149300();

    *(undefined8 *)(lVar1 + 0xb0) = uVar2;

    FUN_14026d2c0(lVar1);

    FUN_14026cee0(lVar1,param_3);

    return 1;

  }

  uVar3 = FUN_14012e850("That operation is not supported");

  return uVar3;

}




