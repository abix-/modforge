// Address: 0x140027470
// Ghidra name: FUN_140027470
// ============ 0x140027470 FUN_140027470 (size=202) ============


undefined8 * FUN_140027470(undefined8 param_1,undefined8 *param_2)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  undefined8 *puVar3;

  

  puVar2 = (undefined8 *)FUN_1400273e0();

  if (puVar2 == (undefined8 *)0x0) {

    puVar2 = (undefined8 *)FUN_1402c704c();

    puVar1 = puVar2 + 4;

    puVar2[1] = 0xffffffffffffffff;

    puVar2[2] = 0;

    *puVar2 = TiXmlAttribute::vftable;

    *puVar1 = 0;

    puVar2[5] = 0;

    puVar2[6] = 0;

    puVar2[7] = 0xf;

    *(undefined1 *)puVar1 = 0;

    puVar2[8] = 0;

    puVar2[9] = 0;

    puVar2[10] = 0;

    puVar2[0xb] = 0xf;

    *(undefined1 *)(puVar2 + 8) = 0;

    puVar2[3] = 0;

    puVar2[0xd] = 0;

    puVar2[0xc] = 0;

    FUN_1400272d0(param_1,puVar2);

    if (puVar1 != param_2) {

      puVar3 = param_2;

      if (0xf < (ulonglong)param_2[3]) {

        puVar3 = (undefined8 *)*param_2;

      }

      FUN_140027f50(puVar1,puVar3,param_2[2]);

    }

  }

  return puVar2;

}




