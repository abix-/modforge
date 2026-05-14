// Address: 0x140139260
// Ghidra name: FUN_140139260
// ============ 0x140139260 FUN_140139260 (size=133) ============


undefined8 * FUN_140139260(undefined8 param_1,undefined8 param_2,char param_3)



{

  undefined8 *puVar1;

  longlong lVar2;

  

  puVar1 = (undefined8 *)FUN_1401841f0(0x28);

  if (puVar1 == (undefined8 *)0x0) {

LAB_1401392c1:

    puVar1 = (undefined8 *)0x0;

  }

  else {

    *puVar1 = param_1;

    puVar1[1] = param_2;

    FUN_140139010(puVar1 + 2,0);

    if (param_3 == '\0') {

      puVar1[3] = 0;

    }

    else {

      lVar2 = FUN_14017cda0(0);

      puVar1[3] = lVar2;

      if (lVar2 == 0) {

        FUN_1401841e0(puVar1);

        goto LAB_1401392c1;

      }

    }

    puVar1[4] = 0;

  }

  return puVar1;

}




