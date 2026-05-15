// Address: 0x14006f590
// Ghidra name: FUN_14006f590
// ============ 0x14006f590 FUN_14006f590 (size=298) ============


undefined8 * FUN_14006f590(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)



{

  longlong lVar1;

  ulonglong uVar2;

  undefined8 uVar3;

  undefined8 *puVar4;

  undefined8 *puVar5;

  ulonglong uVar6;

  

  puVar5 = param_2;

  if (0xf < (ulonglong)param_2[3]) {

    puVar5 = (undefined8 *)*param_2;

  }

  lVar1 = param_3[2];

  uVar2 = param_2[2];

  if ((ulonglong)(param_3[3] - lVar1) < uVar2) {

    param_3 = (undefined8 *)FUN_14006f6c0(param_3,uVar2,0,0,puVar5,uVar2);

  }

  else {

    param_3[2] = lVar1 + uVar2;

    puVar4 = param_3;

    if (0xf < (ulonglong)param_3[3]) {

      puVar4 = (undefined8 *)*param_3;

    }

    uVar6 = uVar2;

    if (((puVar4 < (undefined8 *)(uVar2 + (longlong)puVar5)) &&

        (puVar5 <= (undefined8 *)(lVar1 + (longlong)puVar4))) && (uVar6 = 0, puVar5 < puVar4)) {

      uVar6 = (longlong)puVar4 - (longlong)puVar5;

    }

    FUN_1402f8e20((undefined1 *)((longlong)puVar4 + uVar2),puVar4,lVar1 + 1);

    FUN_1402f8e20(puVar4,puVar5,uVar6);

    FUN_1402f8e20((undefined1 *)((longlong)puVar4 + uVar6),

                  (undefined1 *)(uVar6 + uVar2 + (longlong)puVar5),uVar2 - uVar6);

  }

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  uVar3 = param_3[1];

  *param_1 = *param_3;

  param_1[1] = uVar3;

  uVar3 = param_3[3];

  param_1[2] = param_3[2];

  param_1[3] = uVar3;

  param_3[2] = 0;

  param_3[3] = 0xf;

  *(undefined1 *)param_3 = 0;

  return param_1;

}




