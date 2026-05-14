// Address: 0x140139560
// Ghidra name: FUN_140139560
// ============ 0x140139560 FUN_140139560 (size=121) ============


void FUN_140139560(uint param_1,uint param_2)



{

  uint uVar1;

  uint *puVar2;

  

  FUN_140179b40(DAT_1403fbea0);

  puVar2 = DAT_1403fbeb8;

  if (DAT_1403fbea8 != '\0') {

    while (puVar2 != (uint *)0x0) {

      uVar1 = *puVar2;

      puVar2 = *(uint **)(puVar2 + 0x24);

      if ((param_1 <= uVar1) && (uVar1 <= param_2)) {

        FUN_140139320();

      }

    }

  }

  FUN_140179b60(DAT_1403fbea0);

  return;

}




