// Address: 0x140077c00
// Ghidra name: FUN_140077c00
// ============ 0x140077c00 FUN_140077c00 (size=150) ============


undefined8

FUN_140077c00(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

             undefined8 param_5,undefined4 param_6)



{

  longlong lVar1;

  longlong lVar2;

  int local_18 [4];

  

  lVar1 = FUN_140079610(param_5,param_6,param_2,param_3,param_4,local_18);

  if (lVar1 != 0) {

    lVar2 = FUN_1402ce0f8(param_1,&DAT_14030a390);

    if (lVar2 != 0) {

      FUN_1402d185c(lVar1,1,(longlong)local_18[0],lVar2);

      FUN_1402ce288(lVar2);

      thunk_FUN_1402e9a80(lVar1);

      return 1;

    }

    thunk_FUN_1402e9a80();

  }

  return 0;

}




