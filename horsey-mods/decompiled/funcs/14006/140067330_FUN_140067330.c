// Address: 0x140067330
// Ghidra name: FUN_140067330
// ============ 0x140067330 FUN_140067330 (size=343) ============


byte FUN_140067330(undefined8 param_1,float *param_2,undefined8 param_3,undefined4 param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  ulonglong uVar4;

  undefined4 uVar5;

  float local_48;

  float fStack_44;

  float fStack_40;

  float fStack_3c;

  

  local_48 = *param_2;

  fStack_44 = param_2[1];

  fStack_40 = param_2[2];

  fStack_3c = param_2[3];

  uVar4 = FUN_140067270(local_48,&local_48);

  local_48 = *param_2;

  fStack_44 = param_2[1];

  fStack_40 = param_2[2];

  fStack_3c = param_2[3];

  uVar5 = DAT_1403d63ac;

  if ((uVar4 & 1) != 0) {

    uVar5 = DAT_1403d63e8;

  }

  FUN_140071120(&local_48,uVar5);

  fVar3 = DAT_140303390;

  fStack_40 = param_2[2] - DAT_140303390;

  fVar1 = *param_2;

  uVar5 = DAT_1403d6374;

  if (((uint)uVar4 >> 1 & 1) != 0) {

    uVar5 = param_4;

  }

  fVar2 = param_2[3];

  local_48 = fVar1 - DAT_140304c68;

  fStack_44 = param_2[1] - DAT_140304c68;

  fStack_3c = fVar2 - DAT_140303390;

  FUN_140071120(&local_48,uVar5);

  if (((uint)uVar4 >> 1 & 1) != 0) {

    param_4 = DAT_1403d6374;

  }

  FUN_140086570(DAT_1403ede58,fVar1 + fVar3,(fVar2 + param_2[1]) - fVar3,0,DAT_14039ca44,param_4,

                param_3);

  return (byte)(uVar4 >> 2) & 1;

}




