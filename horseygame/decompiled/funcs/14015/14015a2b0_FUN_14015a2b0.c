// Address: 0x14015a2b0
// Ghidra name: FUN_14015a2b0
// ============ 0x14015a2b0 FUN_14015a2b0 (size=231) ============


void FUN_14015a2b0(undefined4 param_1)



{

  char cVar1;

  int iVar2;

  undefined4 local_res10 [2];

  longlong local_res18 [2];

  undefined4 local_88 [2];

  undefined8 local_80;

  undefined4 local_78;

  

  cVar1 = FUN_140159a90();

  if (cVar1 == '\0') {

    DAT_1403fc06a = 1;

    cVar1 = FUN_140157a10(param_1,local_res18,local_res10);

    if (((cVar1 != '\0') &&

        ((iVar2 = (**(code **)(local_res18[0] + 0x30))(local_res10[0]), -1 < iVar2 ||

         (iVar2 = (**(code **)(local_res18[0] + 0x38))(local_res10[0]), -1 < iVar2)))) ||

       ((cVar1 = FUN_14013f5e0(param_1), cVar1 != '\0' && (iVar2 = FUN_140157960(), -1 < iVar2)))) {

      FUN_14015b440(iVar2,param_1);

    }

    FUN_14015bba0(param_1);

    local_88[0] = 0x605;

    local_80 = 0;

    cVar1 = FUN_140139420(0x605);

    if (cVar1 != '\0') {

      local_78 = param_1;

      FUN_14013b140(local_88);

    }

    cVar1 = FUN_14013f5e0(param_1);

    DAT_1403fc06a = 0;

    if (cVar1 != '\0') {

      FUN_140140020(param_1);

    }

    return;

  }

  return;

}




