// Address: 0x140067560
// Ghidra name: FUN_140067560
// ============ 0x140067560 FUN_140067560 (size=333) ============


byte FUN_140067560(undefined8 param_1,float *param_2,undefined8 param_3,char param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  undefined4 uVar4;

  float fVar5;

  uint uVar6;

  float local_58;

  float fStack_54;

  float fStack_50;

  float fStack_4c;

  

  local_58 = *param_2;

  fStack_54 = param_2[1];

  fStack_50 = param_2[2];

  fStack_4c = param_2[3];

  uVar6 = FUN_140067270(local_58,&local_58);

  fVar5 = DAT_14030374c;

  fVar1 = *param_2;

  fVar2 = param_2[1];

  fVar3 = param_2[3];

  if ((uVar6 & 2) != 0) {

    fStack_50 = param_2[2] - DAT_14030374c;

    local_58 = fVar1 - DAT_14039ca80;

    fStack_54 = fVar2 - DAT_14039ca80;

    fStack_4c = fVar3 - DAT_14030374c;

    FUN_140071120(&local_58,DAT_1403d636c);

  }

  local_58 = *param_2;

  fStack_54 = param_2[1];

  fStack_50 = param_2[2];

  fStack_4c = param_2[3];

  uVar4 = DAT_1403d6374;

  if (param_4 != '\0') {

    uVar4 = DAT_1403d63b4;

  }

  FUN_140071120(&local_58,uVar4);

  FUN_140086570(DAT_1403ede50,fVar1 + fVar5,(fVar3 + fVar2) - fVar5,0,DAT_14039ca44,DAT_1403d6360,

                param_3);

  return (byte)(uVar6 >> 2) & 1;

}




