// Address: 0x140077e50
// Ghidra name: FUN_140077e50
// ============ 0x140077e50 FUN_140077e50 (size=122) ============


undefined8

FUN_140077e50(code *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,

             undefined4 param_5,undefined8 param_6,undefined4 param_7)



{

  longlong lVar1;

  undefined4 local_18 [4];

  

  lVar1 = FUN_140079610(param_6,param_7,param_3,param_4,param_5,local_18);

  if (lVar1 == 0) {

    return 0;

  }

  (*param_1)(param_2,lVar1,local_18[0]);

  thunk_FUN_1402e9a80(lVar1);

  return 1;

}




