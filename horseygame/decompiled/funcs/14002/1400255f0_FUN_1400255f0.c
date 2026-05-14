// Address: 0x1400255f0
// Ghidra name: FUN_1400255f0
// ============ 0x1400255f0 FUN_1400255f0 (size=217) ============


void FUN_1400255f0(longlong param_1)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  undefined8 *puVar3;

  

  puVar1 = *(undefined8 **)(param_1 + 0x28);

  while (puVar1 != (undefined8 *)0x0) {

    puVar3 = (undefined8 *)puVar1[0xc];

    (**(code **)*puVar1)(puVar1,1);

    puVar1 = puVar3;

  }

  *(undefined8 *)(param_1 + 0x28) = 0;

  *(undefined8 *)(param_1 + 0x30) = 0;

LAB_140025634:

  do {

    puVar1 = *(undefined8 **)(param_1 + 0xd0);

    if ((puVar1 == (undefined8 *)(param_1 + 0x68)) || (puVar3 = puVar1, puVar1 == (undefined8 *)0x0)

       ) {

      return;

    }

    do {

      puVar2 = (undefined8 *)puVar3[0xd];

      if (puVar3 == puVar1) {

        *(undefined8 **)(puVar3[0xc] + 0x68) = puVar2;

        *(undefined8 *)(puVar3[0xd] + 0x60) = puVar3[0xc];

        puVar3[0xd] = 0;

        puVar3[0xc] = 0;

        (**(code **)*puVar1)(puVar1,1);

        goto LAB_140025634;

      }

      puVar3 = puVar2;

    } while (puVar2 != (undefined8 *)(param_1 + 0x68));

    FID_conflict__assert(L"0",L"C:\\dev\\tinyxml\\tinyxml.cpp",0x5d9);

    (**(code **)*puVar1)(puVar1,1);

  } while( true );

}




