// Address: 0x14016eac0
// Ghidra name: FUN_14016eac0
// ============ 0x14016eac0 FUN_14016eac0 (size=95) ============


ulonglong FUN_14016eac0(longlong param_1)



{

  char cVar1;

  ulonglong uVar2;

  

  if (DAT_1403fc410 == 0) {

    uVar2 = FUN_1401730c0();

    return uVar2 & 0xffffffffffffff00;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_14016eb0b;

    }

    return (ulonglong)

           CONCAT31((uint3)(*(uint *)(param_1 + 0x48) >> 0x17),

                    (char)(*(uint *)(param_1 + 0x48) >> 0xf)) & 0xffffffffffffff01;

  }

LAB_14016eb0b:

  uVar2 = FUN_14012e850("Invalid window");

  return uVar2 & 0xffffffffffffff00;

}




