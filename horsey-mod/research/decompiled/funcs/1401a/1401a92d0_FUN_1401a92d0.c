// Address: 0x1401a92d0
// Ghidra name: FUN_1401a92d0
// ============ 0x1401a92d0 FUN_1401a92d0 (size=242) ============


undefined8 FUN_1401a92d0(short *param_1)



{

  short sVar1;

  int iVar2;

  undefined8 uVar3;

  

  sVar1 = *param_1;

  if (sVar1 == 3) {

    if (param_1[7] == 0x20) {

      return 0x8120;

    }

  }

  else if (sVar1 == 1) {

    if (param_1[7] == 0x10) {

      return 0x8010;

    }

    if (param_1[7] == 0x20) {

      return 0x8020;

    }

  }

  else if (sVar1 == -2) {

    iVar2 = memcmp(param_1 + 0xc,&DAT_14033c478,0x10);

    if ((iVar2 == 0) && (param_1[7] == 0x20)) {

      return 0x8120;

    }

    iVar2 = memcmp(param_1 + 0xc,&DAT_14033c468,0x10);

    if ((iVar2 == 0) && (param_1[7] == 0x10)) {

      return 0x8010;

    }

    iVar2 = memcmp(param_1 + 0xc,&DAT_14033c468,0x10);

    if (iVar2 == 0) {

      uVar3 = 0;

      if (param_1[7] == 0x20) {

        uVar3 = 0x8020;

      }

      return uVar3;

    }

  }

  return 0;

}




