// Address: 0x14013ab80
// Ghidra name: FUN_14013ab80
// ============ 0x14013ab80 FUN_14013ab80 (size=114) ============


undefined1 FUN_14013ab80(uint param_1,uint param_2)



{

  uint *puVar1;

  undefined1 uVar2;

  

  uVar2 = 0;

  FUN_140179b40(DAT_1403fbea0);

  puVar1 = DAT_1403fbeb8;

  if (DAT_1403fbea8 != '\0') {

    for (; puVar1 != (uint *)0x0; puVar1 = *(uint **)(puVar1 + 0x24)) {

      if ((param_1 <= *puVar1) && (*puVar1 <= param_2)) {

        uVar2 = 1;

        break;

      }

    }

  }

  FUN_140179b60(DAT_1403fbea0);

  return uVar2;

}




