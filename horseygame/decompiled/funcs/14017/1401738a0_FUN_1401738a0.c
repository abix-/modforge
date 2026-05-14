// Address: 0x1401738a0
// Ghidra name: FUN_1401738a0
// ============ 0x1401738a0 FUN_1401738a0 (size=130) ============


ulonglong FUN_1401738a0(longlong param_1)



{

  char cVar1;

  ulonglong uVar2;

  undefined8 local_18;

  undefined1 local_10 [4];

  undefined1 local_c [4];

  

  if (DAT_1403fc410 == 0) {

    uVar2 = FUN_1401730c0();

    return uVar2 & 0xffffffffffffff00;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_14017390e;

    }

    local_18 = 0;

    FUN_14016ebe0(param_1,local_10,local_c);

    uVar2 = FUN_1401737d0(param_1,&local_18,1);

    return uVar2;

  }

LAB_14017390e:

  uVar2 = FUN_14012e850("Invalid window");

  return uVar2 & 0xffffffffffffff00;

}




