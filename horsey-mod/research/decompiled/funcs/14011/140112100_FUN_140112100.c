// Address: 0x140112100
// Ghidra name: FUN_140112100
// ============ 0x140112100 FUN_140112100 (size=125) ============


undefined8 * FUN_140112100(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  undefined8 uVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  undefined8 *puVar6;

  undefined8 *puVar7;

  

  puVar7 = param_3;

  if (param_1 != param_2) {

    puVar6 = param_1 + 4;

    do {

      uVar3 = puVar6[-3];

      puVar1 = puVar6 + 6;

      *puVar7 = puVar6[-4];

      puVar7[1] = uVar3;

      puVar7 = puVar7 + 6;

      *(undefined4 *)((longlong)param_3 + (-0x40 - (longlong)param_1) + (longlong)puVar1) =

           *(undefined4 *)(puVar6 + -2);

      *(undefined4 *)((longlong)param_3 + (-0x3c - (longlong)param_1) + (longlong)puVar1) =

           *(undefined4 *)((longlong)puVar6 + -0xc);

      uVar3 = puVar6[-1];

      uVar4 = puVar6[1];

      uVar5 = *puVar6;

      puVar6[1] = 0;

      *puVar6 = 0;

      puVar6[-1] = 0;

      *(undefined8 *)((longlong)param_3 + (-0x38 - (longlong)param_1) + (longlong)puVar1) = uVar3;

      puVar2 = puVar6 + 2;

      *(undefined8 *)((longlong)param_3 + (-0x30 - (longlong)param_1) + (longlong)puVar1) = uVar5;

      *(undefined8 *)((longlong)param_3 + (-0x28 - (longlong)param_1) + (longlong)puVar1) = uVar4;

      puVar6 = puVar1;

    } while (puVar2 != param_2);

  }

  return puVar7;

}




