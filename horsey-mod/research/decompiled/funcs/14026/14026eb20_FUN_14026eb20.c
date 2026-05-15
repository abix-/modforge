// Address: 0x14026eb20
// Ghidra name: FUN_14026eb20
// ============ 0x14026eb20 FUN_14026eb20 (size=126) ============


undefined4 FUN_14026eb20(undefined8 param_1,undefined8 param_2,undefined8 param_3,int param_4)



{

  int iVar1;

  undefined4 uVar2;

  ulonglong uVar3;

  undefined1 local_48;

  undefined8 local_47;

  undefined8 uStack_3f;

  undefined8 local_37;

  undefined8 uStack_2f;

  undefined8 local_27;

  undefined8 uStack_1f;

  

  local_48 = 0;

  uVar3 = (ulonglong)param_4;

  if (0x31 < uVar3) {

    uVar3 = 0x31;

  }

  local_47 = 0;

  uStack_3f = 0;

  local_37 = 0;

  uStack_2f = 0;

  local_27 = 0;

  uStack_1f = 0;

  FUN_1402f8e20(&local_48,param_3,uVar3);

  iVar1 = FUN_140284590(param_1,&local_48,0x31);

  if (iVar1 != 0x31) {

    uVar2 = FUN_14012e850("Couldn\'t send rumble packet");

    return uVar2;

  }

  return 1;

}




