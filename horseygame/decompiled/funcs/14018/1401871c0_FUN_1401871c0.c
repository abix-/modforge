// Address: 0x1401871c0
// Ghidra name: FUN_1401871c0
// ============ 0x1401871c0 FUN_1401871c0 (size=22) ============


void FUN_1401871c0(undefined8 *param_1)



{

  uint uVar1;

  uint *puVar2;

  char cVar3;

  

  puVar2 = (uint *)param_1[1];

  if ((puVar2 == (uint *)0x0) || (puVar2 == (uint *)*param_1)) {

    return;

  }

  cVar3 = FUN_1401489c0();

  if (((cVar3 != '\0') && ((puVar2[0xc] & 1) == 0)) &&

     (puVar2[8] = puVar2[8] - 1, (int)puVar2[8] < 1)) {

    FUN_140147e50(puVar2);

    FUN_1401747e0(puVar2[0xd]);

    FUN_14017ba60(puVar2 + 0x1e);

    uVar1 = puVar2[0x18];

    while (0 < (int)uVar1) {

      FUN_1401489e0(puVar2);

      uVar1 = puVar2[0x18];

    }

    if ((puVar2[0xc] & 4) != 0) {

      FUN_1401d2c00(puVar2);

    }

    FUN_1401487f0(puVar2,0);

    if ((*puVar2 & 1) == 0) {

      if ((*puVar2 & 8) == 0) {

        FUN_1401841e0(*(undefined8 *)(puVar2 + 6));

      }

      else {

        FUN_140190140();

      }

    }

    puVar2[10] = 0;

    puVar2[0xb] = 0;

    if ((puVar2[0xc] & 2) == 0) {

      FUN_1401841e0(puVar2);

      return;

    }

  }

  return;

}




