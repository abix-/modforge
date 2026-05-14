// Address: 0x14017c4e0
// Ghidra name: FUN_14017c4e0
// ============ 0x14017c4e0 FUN_14017c4e0 (size=176) ============


undefined8 FUN_14017c4e0(undefined8 *param_1,char param_2)



{

  undefined4 uVar1;

  undefined8 uVar2;

  

  if (((param_1 != (undefined8 *)0x0) && ((char *)*param_1 != (char *)0x0)) &&

     (*(char *)*param_1 != '\0')) {

    uVar1 = FUN_1401746e0();

    FUN_140175480(uVar1,"SDL.process.create.args",param_1);

    if (param_2 != '\0') {

      FUN_140175360(uVar1,"SDL.process.create.stdin_option",2);

      FUN_140175360(uVar1,"SDL.process.create.stdout_option",2);

    }

    uVar2 = FUN_14017c3f0(uVar1);

    FUN_1401747e0(uVar1);

    return uVar2;

  }

  FUN_14012e850("Parameter \'%s\' is invalid","args");

  return 0;

}




