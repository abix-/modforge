// Address: 0x14012fcd0
// Ghidra name: FUN_14012fcd0
// ============ 0x14012fcd0 FUN_14012fcd0 (size=102) ============


ulonglong FUN_14012fcd0(longlong param_1,undefined8 param_2,longlong param_3)



{

  ulonglong uVar1;

  ulonglong uVar2;

  

  uVar1 = FUN_14012fd40(param_2);

  if (param_3 != 0) {

    uVar2 = param_3 - 1U;

    if (uVar1 < param_3 - 1U) {

      uVar2 = uVar1;

    }

    FUN_1402f8e20(param_1,param_2,uVar2 * 2);

    *(undefined2 *)(uVar2 * 2 + param_1) = 0;

  }

  return uVar1;

}




