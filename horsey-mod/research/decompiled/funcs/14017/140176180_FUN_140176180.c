// Address: 0x140176180
// Ghidra name: FUN_140176180
// ============ 0x140176180 FUN_140176180 (size=96) ============


undefined8 FUN_140176180(undefined8 param_1)



{

  char cVar1;

  undefined4 uVar2;

  undefined8 uVar3;

  

  uVar3 = 0;

  FUN_140159d30();

  cVar1 = FUN_1401596f0(param_1);

  if (cVar1 != '\0') {

    uVar2 = FUN_140158720(param_1);

    cVar1 = FUN_14013f5e0(uVar2);

    if (cVar1 == '\0') {

      cVar1 = FUN_14021ae80(param_1);

      if (cVar1 == '\0') {

        cVar1 = FUN_14021b470(param_1);

        if (cVar1 == '\0') goto LAB_1401761cd;

      }

      uVar3 = 1;

    }

  }

LAB_1401761cd:

  FUN_14015bb10();

  return uVar3;

}




