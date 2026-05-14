// Address: 0x14027bbf0
// Ghidra name: FUN_14027bbf0
// ============ 0x14027bbf0 FUN_14027bbf0 (size=319) ============


void FUN_14027bbf0(undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4)



{

  if (*(byte *)(param_3 + 0x6a) != *(byte *)(param_4 + 0xe)) {

    FUN_14015ad00(param_1,param_2,0,*(byte *)(param_4 + 0xe) & 1);

    FUN_14015ad00(param_1,param_2,1,*(byte *)(param_4 + 0xe) >> 1 & 1);

    FUN_14015ad00(param_1,param_2,2,*(byte *)(param_4 + 0xe) >> 2 & 1);

    FUN_14015ad00(param_1,param_2,3,*(byte *)(param_4 + 0xe) >> 3 & 1);

    FUN_14015ad00(param_1,param_2,9,*(byte *)(param_4 + 0xe) >> 4 & 1);

    FUN_14015ad00(param_1,param_2,10,*(byte *)(param_4 + 0xe) >> 5 & 1);

    FUN_14015ad00(param_1,param_2,4,*(byte *)(param_4 + 0xe) >> 6 & 1);

    FUN_14015ad00(param_1,param_2,6,*(byte *)(param_4 + 0xe) >> 7);

  }

  if (*(byte *)(param_3 + 0x6b) != *(byte *)(param_4 + 0xf)) {

    FUN_14015ad00(param_1,param_2,7,*(byte *)(param_4 + 0xf) & 1);

    FUN_14015ad00(param_1,param_2,8,*(byte *)(param_4 + 0xf) >> 1 & 1);

  }

  return;

}




