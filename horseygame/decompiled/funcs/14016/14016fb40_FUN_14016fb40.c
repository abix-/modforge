// Address: 0x14016fb40
// Ghidra name: FUN_14016fb40
// ============ 0x14016fb40 FUN_14016fb40 (size=330) ============


undefined8 FUN_14016fb40(longlong param_1,ulonglong param_2)



{

  char cVar1;

  char cVar2;

  char cVar3;

  undefined8 uVar4;

  uint uVar5;

  ulonglong uVar6;

  

  cVar1 = '\0';

  cVar2 = '\0';

  if (*(longlong *)(DAT_1403fc410 + 0x198) == 0) {

    return 0;

  }

  if ((*(ulonglong *)(param_1 + 0x48) >> 0xb & 1) != 0) {

    return 0;

  }

  if ((*(ulonglong *)(param_1 + 0x48) & 0x30000002) != 0) {

    return 0;

  }

  uVar5 = (uint)param_2 & 0x30000002;

  uVar6 = (ulonglong)uVar5;

  if ((uVar6 & uVar6 - 1) != 0) {

    uVar4 = FUN_14012e850("Conflicting window flags specified");

    return uVar4;

  }

  if (((param_2 & 2) != 0) && (*(longlong *)(DAT_1403fc410 + 0x1b8) == 0)) {

    uVar4 = FUN_14016a680("OpenGL");

    return uVar4;

  }

  if (((param_2 >> 0x1c & 1) != 0) && (*(longlong *)(DAT_1403fc410 + 0x210) == 0)) {

    uVar4 = FUN_14016a680("Vulkan");

    return uVar4;

  }

  if (((param_2 >> 0x1d & 1) != 0) && (*(longlong *)(DAT_1403fc410 + 0x228) == 0)) {

    uVar4 = FUN_14016a680("Metal");

    return uVar4;

  }

  FUN_14016b5e0(param_1);

  if ((char)uVar5 == '\0') {

    if ((uVar5 >> 0x1c & 1) == 0) goto LAB_14016fc3c;

    cVar2 = FUN_140174130(0);

    cVar3 = cVar2;

  }

  else {

    cVar1 = FUN_14016c850(0);

    cVar3 = cVar1;

  }

  if (cVar3 == '\0') {

    return 0;

  }

LAB_14016fc3c:

  cVar3 = (**(code **)(DAT_1403fc410 + 0x198))(DAT_1403fc410,param_1,uVar6);

  if (cVar3 == '\0') {

    if (cVar1 != '\0') {

      FUN_14016cef0();

    }

    if (cVar2 != '\0') {

      FUN_1401741d0();

    }

    return 0;

  }

  *(ulonglong *)(param_1 + 0x48) = *(ulonglong *)(param_1 + 0x48) | uVar6;

  return 1;

}




