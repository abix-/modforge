// Address: 0x140175050
// Ghidra name: FUN_140175050
// ============ 0x140175050 FUN_140175050 (size=86) ============


undefined1 FUN_140175050(int param_1)



{

  undefined1 uVar1;

  longlong local_res10 [3];

  

  local_res10[0] = 0;

  if (param_1 != 0) {

    FUN_1401aaff0(DAT_1403fc450,param_1,local_res10);

    if (local_res10[0] != 0) {

      FUN_140179b40(*(undefined8 *)(local_res10[0] + 8));

      return 1;

    }

  }

  uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","props");

  return uVar1;

}




