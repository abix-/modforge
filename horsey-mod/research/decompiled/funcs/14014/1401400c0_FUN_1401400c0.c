// Address: 0x1401400c0
// Ghidra name: FUN_1401400c0
// ============ 0x1401400c0 FUN_1401400c0 (size=100) ============


void FUN_1401400c0(int param_1)



{

  undefined8 *puVar1;

  undefined4 local_88 [2];

  undefined8 local_80;

  int local_78;

  

  _guard_check_icall();

  puVar1 = DAT_1403fbef8;

  if (DAT_1403fbef0 != '\0') {

    for (; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)puVar1[10]) {

      if (*(int *)*puVar1 == param_1) {

        FUN_14013c880();

        break;

      }

    }

    local_88[0] = 0x654;

    local_80 = 0;

    local_78 = param_1;

    FUN_14013b140(local_88);

  }

  return;

}




