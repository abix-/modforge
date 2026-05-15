// Address: 0x140027890
// Ghidra name: FUN_140027890
// ============ 0x140027890 FUN_140027890 (size=80) ============


undefined8 * FUN_140027890(undefined8 *param_1,undefined1 param_2)



{

  ulonglong uVar1;

  ulonglong uVar2;

  undefined8 *puVar3;

  

  uVar1 = param_1[2];

  uVar2 = param_1[3];

  if (uVar1 < uVar2) {

    param_1[2] = uVar1 + 1;

    puVar3 = param_1;

    if (0xf < uVar2) {

      puVar3 = (undefined8 *)*param_1;

    }

    *(undefined1 *)((longlong)puVar3 + uVar1) = param_2;

    *(undefined1 *)((longlong)puVar3 + uVar1 + 1) = 0;

    return param_1;

  }

  FUN_1400280d0(param_1,param_2,uVar2,param_2);

  return param_1;

}




