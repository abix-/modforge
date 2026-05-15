// Address: 0x140271d80
// Ghidra name: FUN_140271d80
// ============ 0x140271d80 FUN_140271d80 (size=130) ============


void FUN_140271d80(longlong param_1,byte param_2)



{

  ulonglong uVar1;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined2 local_18;

  undefined1 local_16;

  

  uVar1 = (ulonglong)param_2;

  local_28 = 0;

  uStack_20 = 0;

  local_18 = 0;

  local_16 = 0;

  if (*(char *)(param_1 + 0x15) != '\0') {

    local_28 = (ulonglong)CONCAT11(*(undefined1 *)(param_1 + 100),*(undefined1 *)(param_1 + 0x65));

  }

  if (*(char *)(param_1 + 0x14) != '\0') {

    if (*(char *)(param_1 + 0x66) == '\0') {

      FUN_140272050(&local_28,*(undefined4 *)(param_1 + 0x60));

    }

    else {

      local_28 = (ulonglong)

                 CONCAT14(*(undefined1 *)(param_1 + 0x69),

                          CONCAT13(*(undefined1 *)(param_1 + 0x68),

                                   CONCAT12(*(undefined1 *)(param_1 + 0x67),(undefined2)local_28)));

    }

  }

  FUN_140271150(param_1,&local_28,0x13,uVar1 & 0xff);

  return;

}




