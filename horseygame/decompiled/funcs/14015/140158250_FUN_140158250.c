// Address: 0x140158250
// Ghidra name: FUN_140158250
// ============ 0x140158250 FUN_140158250 (size=92) ============


undefined4 * FUN_140158250(undefined4 *param_1,undefined4 param_2)



{

  char cVar1;

  undefined4 *puVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  undefined4 local_res8 [2];

  longlong local_res18 [2];

  undefined1 local_18 [16];

  

  FUN_140159d30();

  cVar1 = FUN_140157a10(param_2,local_res18,local_res8);

  if (cVar1 == '\0') {

    uVar3 = 0;

    uVar4 = 0;

    uVar5 = 0;

    uVar6 = 0;

  }

  else {

    puVar2 = (undefined4 *)(**(code **)(local_res18[0] + 0x48))(local_18,local_res8[0]);

    uVar3 = *puVar2;

    uVar4 = puVar2[1];

    uVar5 = puVar2[2];

    uVar6 = puVar2[3];

  }

  *param_1 = uVar3;

  param_1[1] = uVar4;

  param_1[2] = uVar5;

  param_1[3] = uVar6;

  FUN_14015bb10();

  return param_1;

}




