// Address: 0x1402ceae8
// Ghidra name: FUN_1402ceae8
// ============ 0x1402ceae8 FUN_1402ceae8 (size=141) ============


ulonglong FUN_1402ceae8(longlong param_1,longlong param_2)



{

  ulonglong uVar1;

  

  if (param_1 == 0) {

    *(undefined1 *)(param_2 + 0x30) = 1;

    *(undefined4 *)(param_2 + 0x2c) = 0x16;

    FUN_1402cd39c(0,0,0,0,0,param_2);

    uVar1 = 0xffffffff;

  }

  else {

    FUN_1402e1710();

    uVar1 = FUN_1402ceb78(param_1,param_2);

    if (0x7fffffff < (longlong)uVar1) {

      *(undefined1 *)(param_2 + 0x30) = 1;

      *(undefined4 *)(param_2 + 0x2c) = 0x16;

      uVar1 = 0xffffffff;

    }

    FUN_1402e171c(param_1);

    uVar1 = uVar1 & 0xffffffff;

  }

  return uVar1;

}




