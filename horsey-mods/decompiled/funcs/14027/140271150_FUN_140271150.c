// Address: 0x140271150
// Ghidra name: FUN_140271150
// ============ 0x140271150 FUN_140271150 (size=348) ============


undefined8 FUN_140271150(longlong *param_1,undefined8 param_2,int param_3,char param_4)



{

  longlong lVar1;

  undefined4 uVar2;

  int iVar3;

  undefined8 uVar4;

  undefined1 *puVar5;

  longlong lVar6;

  ulonglong uVar7;

  undefined1 local_res8 [8];

  undefined4 uStack_6c;

  ushort local_68 [2];

  undefined1 auStack_64 [2];

  undefined1 auStack_62 [4];

  undefined8 local_5e;

  undefined8 local_56;

  undefined8 local_4e;

  undefined8 local_46;

  undefined8 local_3e;

  undefined8 local_36;

  undefined8 local_2e;

  undefined8 local_26;

  undefined4 local_1e;

  

  if (*(char *)((longlong)param_1 + 0x17) == '\0') {

LAB_140271168:

    uVar4 = FUN_14012e850("That operation is not supported");

    return uVar4;

  }

  if (*(char *)((longlong)param_1 + 0x21) == '\0') {

    if (param_4 != '\0') {

      FUN_140271e10();

    }

    if (*(char *)((longlong)param_1 + 0x21) == '\0') goto LAB_140271168;

  }

  lVar1 = *param_1;

  stack0xffffffffffffff9a = 0;

  local_5e = 0;

  local_56 = 0;

  local_4e = 0;

  local_46 = 0;

  local_3e = 0;

  local_36 = 0;

  local_2e = 0;

  local_26 = 0;

  local_1e = 0;

  if ((*(char *)(lVar1 + 0x54) == '\0') || (*(char *)((longlong)param_1 + 0x12) == '\0')) {

    local_68[0] = 0x705;

    puVar5 = auStack_64;

    lVar6 = 0x20;

    uVar7 = 0x4a;

  }

  else {

    puVar5 = auStack_62;

    local_68[0] = CONCAT11(*(undefined1 *)((longlong)param_1 + 0x23),0x11) | 0xc000;

    lVar6 = 0x4e;

    stack0xffffffffffffff9a = 0x300;

    uVar7 = 0x48;

  }

  if ((ulonglong)(longlong)param_3 <= uVar7) {

    uVar7 = (longlong)param_3;

  }

  FUN_1402f8e20(puVar5,param_2,uVar7);

  if (*(char *)(lVar1 + 0x54) != '\0') {

    local_res8[0] = 0xa2;

    uVar2 = FUN_1401917b0(0,local_res8,1);

    uVar2 = FUN_1401917b0(uVar2,local_68,lVar6 + -4);

    *(undefined4 *)((longlong)&uStack_6c + lVar6) = uVar2;

  }

  iVar3 = FUN_140284590(*param_1,local_68,lVar6);

  if (iVar3 != (int)lVar6) {

    uVar4 = FUN_14012e850("Couldn\'t send rumble packet");

    return uVar4;

  }

  return 1;

}




