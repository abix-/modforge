// Address: 0x140280040
// Ghidra name: FUN_140280040
// ============ 0x140280040 FUN_140280040 (size=148) ============


undefined8 FUN_140280040(longlong param_1)



{

  ushort uVar1;

  undefined8 uVar2;

  

  uVar1 = *(ushort *)(param_1 + 0x22);

  if (0x6009 < uVar1) {

    if (uVar1 == 0x6012) {

      uVar2 = 1000;

      if (*(char *)(param_1 + 0x54) != '\0') {

        uVar2 = 0x78;

      }

      return uVar2;

    }

    if ((uVar1 != 0x6100) && (uVar1 != 0x6101)) {

      return 0x78;

    }

LAB_1402800a3:

    if (*(char *)(param_1 + 0x54) == '\0') {

      uVar2 = 100;

      if (*(char *)(*(longlong *)(param_1 + 0x70) + 9) != '\0') {

        uVar2 = 200;

      }

      return uVar2;

    }

    return 0x46;

  }

  if (uVar1 != 0x6009) {

    if ((uVar1 == 0x6000) || (uVar1 == 0x6001)) goto LAB_1402800a3;

    if ((uVar1 != 0x6003) && (uVar1 != 0x6006)) {

      return 0x78;

    }

  }

  if (*(char *)(param_1 + 0x54) != '\0') {

    return 0x55;

  }

  if (*(char *)(*(longlong *)(param_1 + 0x70) + 9) != '\0') {

    return 200;

  }

  return 100;

}




