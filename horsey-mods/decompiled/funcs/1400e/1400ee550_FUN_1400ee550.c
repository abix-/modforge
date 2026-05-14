// Address: 0x1400ee550
// Ghidra name: FUN_1400ee550
// ============ 0x1400ee550 FUN_1400ee550 (size=152) ============


undefined4 FUN_1400ee550(longlong param_1)



{

  byte *pbVar1;

  uint uVar2;

  undefined4 uVar3;

  char *pcVar4;

  

  pcVar4 = "#?RADIANCE\n";

  uVar3 = 0;

  do {

    pbVar1 = *(byte **)(param_1 + 0xb8);

    if (pbVar1 < *(byte **)(param_1 + 0xc0)) {

      uVar2 = (uint)*pbVar1;

      *(byte **)(param_1 + 0xb8) = pbVar1 + 1;

    }

    else if (*(int *)(param_1 + 0x30) == 0) {

      uVar2 = 0;

    }

    else {

      FUN_1400ed820(param_1);

      uVar2 = (uint)**(byte **)(param_1 + 0xb8);

      *(byte **)(param_1 + 0xb8) = *(byte **)(param_1 + 0xb8) + 1;

    }

    if (uVar2 != (int)*pcVar4) goto LAB_1400ee5c8;

    pcVar4 = pcVar4 + 1;

  } while (*pcVar4 != '\0');

  uVar3 = 1;

LAB_1400ee5c8:

  *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(param_1 + 200);

  return uVar3;

}




