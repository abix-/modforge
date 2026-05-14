// Address: 0x14013c910
// Ghidra name: FUN_14013c910
// ============ 0x14013c910 FUN_14013c910 (size=26) ============


void FUN_14013c910(undefined8 param_1,undefined8 *param_2,longlong param_3)



{

  undefined4 uVar1;

  char cVar2;

  undefined4 auStack_88 [2];

  undefined8 uStack_80;

  undefined4 uStack_78;

  undefined1 uStack_74;

  undefined2 uStack_70;

  

  uVar1 = *(undefined4 *)(param_3 + 0x14);

  if (*(int *)(param_3 + 0x10) != 2) {

    FUN_140141d70();

    return;

  }

  _guard_check_icall();

  cVar2 = FUN_140139420(0x650);

  if (cVar2 != '\0') {

    auStack_88[0] = 0x650;

    uStack_78 = *(undefined4 *)*param_2;

    uStack_74 = (undefined1)uVar1;

    uStack_70 = 0;

    uStack_80 = param_1;

    FUN_14013b140(auStack_88);

  }

  return;

}




