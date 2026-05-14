// Address: 0x140072bb0
// Ghidra name: FUN_140072bb0
// ============ 0x140072bb0 FUN_140072bb0 (size=222) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 * FUN_140072bb0(undefined4 *param_1,uint param_2,float param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  undefined4 local_res10;

  

  fVar2 = (float)(param_2 & 0xff) / DAT_14030a2d0;

  fVar3 = (float)(param_2 >> 8 & 0xff) / DAT_14030a2d0;

  fVar1 = (float)(param_2 >> 0x10 & 0xff) / DAT_14030a2d0;

  fVar4 = fVar3 * _DAT_14030a2cc + fVar2 * _DAT_14030a2c8 + fVar1 * _DAT_14030a2c4;

  local_res10._3_1_ = (undefined1)(param_2 >> 0x18);

  local_res10._0_3_ =

       CONCAT12((char)(int)(((fVar4 - fVar1) * param_3 + fVar1) * DAT_14030a2d0),

                CONCAT11((char)(int)(((fVar4 - fVar3) * param_3 + fVar3) * DAT_14030a2d0),

                         (char)(int)(((fVar4 - fVar2) * param_3 + fVar2) * DAT_14030a2d0)));

  *param_1 = local_res10;

  return param_1;

}




