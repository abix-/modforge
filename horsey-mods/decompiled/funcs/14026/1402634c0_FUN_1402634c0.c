// Address: 0x1402634c0
// Ghidra name: FUN_1402634c0
// ============ 0x1402634c0 FUN_1402634c0 (size=216) ============


longlong FUN_1402634c0(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4

                      )



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  char cVar4;

  undefined4 *puVar5;

  longlong local_res8;

  

  local_res8 = 0;

  cVar4 = FUN_1401aaff0(*param_1,param_4,&local_res8);

  if (cVar4 != '\0') {

    return local_res8;

  }

  puVar5 = (undefined4 *)FUN_1401841f0(0x20);

  if (puVar5 != (undefined4 *)0x0) {

    uVar1 = param_4[1];

    uVar2 = param_4[2];

    uVar3 = param_4[3];

    *puVar5 = *param_4;

    puVar5[1] = uVar1;

    puVar5[2] = uVar2;

    puVar5[3] = uVar3;

    uVar1 = param_4[5];

    uVar2 = param_4[6];

    uVar3 = param_4[7];

    puVar5[4] = param_4[4];

    puVar5[5] = uVar1;

    puVar5[6] = uVar2;

    puVar5[7] = uVar3;

    local_res8 = FUN_1402635f0(param_3,param_2,param_4);

    if ((local_res8 != 0) && (cVar4 = FUN_1401ab100(*param_1,puVar5,local_res8,0), cVar4 != '\0')) {

      return local_res8;

    }

  }

  FUN_1401841e0(puVar5);

  if (local_res8 != 0) {

    FUN_140137f40(param_3,local_res8);

  }

  return 0;

}




