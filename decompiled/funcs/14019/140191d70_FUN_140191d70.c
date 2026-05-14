// Address: 0x140191d70
// Ghidra name: FUN_140191d70
// ============ 0x140191d70 FUN_140191d70 (size=135) ============


undefined8 FUN_140191d70(longlong param_1,longlong param_2,longlong param_3)



{

  wchar_t *pwVar1;

  

  if ((param_2 == 0) || (param_3 == 0)) {

    pwVar1 = L"Zero buffer/length";

  }

  else {

    if (*(longlong *)(param_1 + 0x88) != 0) {

      FUN_14012fcd0(param_2,*(undefined8 *)(*(longlong *)(param_1 + 0x88) + 0x20));

      *(undefined2 *)(param_2 + -2 + param_3 * 2) = 0;

      FUN_140196b60(param_1,0);

      return 0;

    }

    pwVar1 = L"NULL device info";

  }

  FUN_140196b60(param_1,pwVar1);

  return 0xffffffff;

}




