// Address: 0x140278930
// Ghidra name: FUN_140278930
// ============ 0x140278930 FUN_140278930 (size=467) ============


void FUN_140278930(longlong param_1,undefined8 param_2)



{

  uint uVar1;

  longlong lVar2;

  undefined8 uVar3;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  undefined4 local_10;

  undefined1 local_c;

  

  lVar2 = param_1;

  uVar1 = FUN_140278680();

  if (uVar1 != *(byte *)(lVar2 + 0x2c)) {

    FUN_14012e080(7,"HIDAPI Wii: Resetting report mode to %d",uVar1);

    FUN_140279ca0(param_1,uVar1);

  }

  local_18 = 0;

  local_10 = 0;

  local_c = 0;

  local_28 = 0;

  uStack_20 = 0;

  switch(*(undefined1 *)(param_1 + 0x2c)) {

  case 0x30:

    FUN_140278670(&local_28,param_1 + 0x2d);

    FUN_140278840(param_1,param_2,&local_28);

    return;

  case 0x31:

  case 0x33:

    FUN_140278670(&local_28,param_1 + 0x2d);

    FUN_140278650(&local_28,param_1 + 0x2f);

    FUN_140278840(param_1,param_2,&local_28);

    return;

  case 0x32:

    FUN_140278670(&local_28,param_1 + 0x2d);

    lVar2 = param_1 + 0x2f;

    uVar3 = 8;

    break;

  case 0x34:

    FUN_140278670(&local_28,param_1 + 0x2d);

    lVar2 = param_1 + 0x2f;

    uVar3 = 0x13;

    break;

  case 0x35:

    FUN_140278670(&local_28,param_1 + 0x2d);

    FUN_140278650(&local_28,param_1 + 0x2f);

    lVar2 = param_1 + 0x32;

    uVar3 = 0x10;

    break;

  case 0x36:

    FUN_140278670(&local_28,param_1 + 0x2d);

    lVar2 = param_1 + 0x39;

    uVar3 = 9;

    break;

  case 0x37:

    FUN_140278670(&local_28,param_1 + 0x2d);

    lVar2 = param_1 + 0x3c;

    uVar3 = 6;

    break;

  default:

    FUN_14012e080(7,"HIDAPI Wii: Unsupported button data type %02x");

    return;

  case 0x3d:

    lVar2 = param_1 + 0x2d;

    uVar3 = 0x15;

  }

  FUN_1402786c0(&local_28,lVar2,uVar3);

  FUN_140278840(param_1,param_2,&local_28);

  return;

}




