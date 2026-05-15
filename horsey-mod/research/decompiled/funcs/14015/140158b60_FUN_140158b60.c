// Address: 0x140158b60
// Ghidra name: FUN_140158b60
// ============ 0x140158b60 FUN_140158b60 (size=174) ============


undefined2 FUN_140158b60(undefined4 *param_1)



{

  undefined2 uVar1;

  char cVar2;

  longlong lVar3;

  undefined4 *puVar4;

  undefined2 local_res8 [16];

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  FUN_140159d30();

  if (param_1 != (undefined4 *)0x0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,4);

      if (cVar2 == '\0') goto LAB_140158bee;

    }

    lVar3 = FUN_140158f10(*param_1);

    if (lVar3 != 0) {

      uVar1 = *(undefined2 *)(lVar3 + 0x12);

      FUN_14015bb10();

      return uVar1;

    }

    puVar4 = (undefined4 *)FUN_1401585d0(&local_18,param_1);

    local_18 = *puVar4;

    uStack_14 = puVar4[1];

    uStack_10 = puVar4[2];

    uStack_c = puVar4[3];

    FUN_1401582b0(&local_18,0,local_res8,0,0);

    FUN_14015bb10();

    return local_res8[0];

  }

LAB_140158bee:

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  FUN_14015bb10();

  return 0;

}




