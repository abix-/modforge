// Address: 0x14009ea70
// Ghidra name: FUN_14009ea70
// ============ 0x14009ea70 FUN_14009ea70 (size=232) ============


void FUN_14009ea70(longlong param_1,float param_2,float param_3,float param_4,float param_5,

                  undefined4 param_6,undefined4 param_7)



{

  float *pfVar1;

  undefined8 *puVar2;

  

  puVar2 = (undefined8 *)FUN_14009f4a0(param_1 + 0x10,&param_7);

  pfVar1 = (float *)*puVar2;

  FUN_140072640(param_6);

  FUN_1400734c0(*(undefined4 *)(param_1 + 8));

  if (pfVar1 != (float *)0x0) {

    FUN_140072100(*(undefined4 *)(param_1 + 8),param_4 * pfVar1[2] + param_2,

                  param_5 * pfVar1[3] + param_3,param_4 * *pfVar1,param_5 * pfVar1[1],pfVar1[4],

                  pfVar1[5],pfVar1[6],pfVar1[7]);

  }

  return;

}




