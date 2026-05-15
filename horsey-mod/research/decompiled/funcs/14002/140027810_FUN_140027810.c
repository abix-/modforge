// Address: 0x140027810
// Ghidra name: FUN_140027810
// ============ 0x140027810 FUN_140027810 (size=128) ============


undefined8 * FUN_140027810(undefined8 *param_1,undefined8 param_2,ulonglong param_3)



{

  longlong lVar1;

  ulonglong uVar2;

  undefined8 *puVar3;

  

  lVar1 = param_1[2];

  uVar2 = param_1[3];

  if (param_3 <= uVar2 - lVar1) {

    param_1[2] = lVar1 + param_3;

    puVar3 = param_1;

    if (0xf < uVar2) {

      puVar3 = (undefined8 *)*param_1;

    }

    FUN_1402f8e20((longlong)puVar3 + lVar1,param_2,param_3);

    *(undefined1 *)((longlong)puVar3 + lVar1 + param_3) = 0;

    return param_1;

  }

  puVar3 = (undefined8 *)FUN_140027c80(param_1,param_3,uVar2,param_2,param_3);

  return puVar3;

}




