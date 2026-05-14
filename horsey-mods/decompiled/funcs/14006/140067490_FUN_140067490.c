// Address: 0x140067490
// Ghidra name: FUN_140067490
// ============ 0x140067490 FUN_140067490 (size=193) ============


byte FUN_140067490(undefined8 param_1,float *param_2,undefined8 param_3)



{

  undefined4 uVar1;

  ulonglong uVar2;

  float local_18;

  float fStack_14;

  float fStack_10;

  float fStack_c;

  

  local_18 = *param_2;

  fStack_14 = param_2[1];

  fStack_10 = param_2[2];

  fStack_c = param_2[3];

  uVar2 = FUN_140067270(local_18,&local_18);

  local_18 = *param_2;

  fStack_14 = param_2[1];

  fStack_10 = param_2[2];

  fStack_c = param_2[3];

  uVar1 = DAT_1403d6368;

  if ((uVar2 & 1) != 0) {

    uVar1 = DAT_1403d6364;

  }

  FUN_140071120(&local_18,uVar1);

  uVar1 = DAT_1403d63b8;

  if ((uVar2 & 2) != 0) {

    uVar1 = DAT_1403d6374;

  }

  FUN_140086570(DAT_1403ede28,*param_2 + DAT_140303390,

                (param_2[3] + param_2[1]) - param_2[3] * DAT_14030335c,0,DAT_14039ca34,uVar1,param_3

               );

  return (byte)(uVar2 >> 2) & 1;

}




