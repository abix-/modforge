// Address: 0x140279fc0
// Ghidra name: FUN_140279fc0
// ============ 0x140279fc0 FUN_140279fc0 (size=109) ============


ulonglong FUN_140279fc0(longlong *param_1,undefined8 param_2,int param_3,char param_4)



{

  byte extraout_var;

  byte extraout_var_00;

  byte bVar2;

  ulonglong uVar1;

  

  if (param_4 == '\0') {

    uVar1 = FUN_1402843f0();

    if ((char)uVar1 == '\0') {

      return uVar1;

    }

    FUN_140284650(*param_1,param_2,param_3);

    bVar2 = extraout_var_00;

  }

  else {

    FUN_140195730(*(undefined8 *)(*param_1 + 0x80),param_2,(longlong)param_3);

    bVar2 = extraout_var;

  }

  return (ulonglong)(bVar2 >> 7) ^ 1;

}




