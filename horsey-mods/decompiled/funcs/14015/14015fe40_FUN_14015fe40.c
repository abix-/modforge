// Address: 0x14015fe40
// Ghidra name: FUN_14015fe40
// ============ 0x14015fe40 FUN_14015fe40 (size=125) ============


void FUN_14015fe40(longlong param_1)



{

  char cVar1;

  int iVar2;

  undefined *puVar3;

  

  iVar2 = FUN_140138fb0(param_1 + 0x10,0xffffffff);

  if (iVar2 == 1) {

    FUN_14017cab0(DAT_1403fc128);

    cVar1 = FUN_1401ab340(DAT_1403fc130,*(undefined4 *)(param_1 + 0x50));

    if (cVar1 != '\0') {

      puVar3 = &DAT_1403fc168;

      if (*(char *)(param_1 + 0x94) != '\0') {

        puVar3 = &DAT_1403fc16c;

      }

      FUN_140138fb0(puVar3,0xffffffff);

    }

    FUN_14017cae0(DAT_1403fc128);

    FUN_14015c8d0(param_1);

    return;

  }

  return;

}




