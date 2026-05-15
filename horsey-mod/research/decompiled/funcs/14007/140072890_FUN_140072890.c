// Address: 0x140072890
// Ghidra name: FUN_140072890
// ============ 0x140072890 FUN_140072890 (size=339) ============


undefined1 * FUN_140072890(undefined1 *param_1,float param_2,float param_3,float param_4)



{

  float fVar1;

  int iVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float local_res10;

  

  param_2 = param_2 * DAT_140303398;

  fVar3 = (float)FUN_1402d0350(param_2);

  fVar1 = DAT_14030a2d0;

  param_2 = param_2 - fVar3;

  iVar2 = (int)fVar3;

  fVar4 = (DAT_14039ca44 - param_3) * param_4;

  fVar7 = (DAT_14039ca44 - param_2 * param_3) * param_4;

  fVar6 = (DAT_14039ca44 - (DAT_14039ca44 - param_2) * param_3) * param_4;

  fVar3 = local_res10;

  fVar5 = local_res10;

  switch(iVar2 + (iVar2 / 6 + (iVar2 >> 0x1f) +

                 (int)(((longlong)iVar2 / 6 + ((longlong)iVar2 >> 0x3f) & 0xffffffffU) >> 0x1f)) *

                 -6) {

  case 0:

    local_res10 = param_4;

    fVar3 = fVar4;

    fVar5 = fVar6;

    break;

  case 1:

    local_res10 = fVar7;

    fVar3 = fVar4;

    fVar5 = param_4;

    break;

  case 2:

    local_res10 = fVar4;

    fVar3 = fVar6;

    fVar5 = param_4;

    break;

  case 3:

    local_res10 = fVar4;

    fVar3 = param_4;

    fVar5 = fVar7;

    break;

  case 4:

    local_res10 = fVar6;

    fVar3 = param_4;

    fVar5 = fVar4;

    break;

  case 5:

    local_res10 = param_4;

    fVar3 = fVar7;

    fVar5 = fVar4;

  }

  fVar4 = local_res10 * DAT_14030a2d0;

  param_1[3] = 0xff;

  *param_1 = (char)(int)fVar4;

  param_1[1] = (char)(int)(fVar5 * fVar1);

  param_1[2] = (char)(int)(fVar3 * fVar1);

  return param_1;

}




