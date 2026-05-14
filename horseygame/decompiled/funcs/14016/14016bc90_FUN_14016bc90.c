// Address: 0x14016bc90
// Ghidra name: FUN_14016bc90
// ============ 0x14016bc90 FUN_14016bc90 (size=133) ============


void FUN_14016bc90(longlong param_1,ulonglong param_2)



{

  char cVar1;

  undefined8 uVar2;

  

  if (*(longlong *)(DAT_1403fc410 + 0x300) == 0) goto LAB_14016bce7;

  cVar1 = FUN_140139420(0x1000);

  if (cVar1 == '\0') {

    cVar1 = FUN_140139420(0x1001);

    if (cVar1 != '\0') goto LAB_14016bcd1;

    uVar2 = 0;

  }

  else {

LAB_14016bcd1:

    uVar2 = 1;

  }

  (**(code **)(DAT_1403fc410 + 0x300))(param_1,uVar2);

LAB_14016bce7:

  if ((*(uint *)(param_1 + 0x48) >> 0xb & 1) == 0) {

    FUN_140169b20(param_1,param_2);

    if ((param_2 & 8) == 0) {

      FUN_140172c00(param_1);

    }

  }

  return;

}




