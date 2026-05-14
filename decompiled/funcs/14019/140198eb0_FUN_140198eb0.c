// Address: 0x140198eb0
// Ghidra name: FUN_140198eb0
// ============ 0x140198eb0 FUN_140198eb0 (size=47) ============


undefined8 FUN_140198eb0(longlong param_1)



{

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","entry");

    return 0;

  }

  return *(undefined8 *)(param_1 + 0x1028);

}




