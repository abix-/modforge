// Address: 0x1400cb670
// Ghidra name: FUN_1400cb670
// ============ 0x1400cb670 FUN_1400cb670 (size=230) ============


void FUN_1400cb670(undefined8 param_1,int *param_2,undefined4 param_3,int param_4,int param_5,

                  int param_6)



{

  int iVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  char local_38 [8];

  ulonglong uStack_30;

  undefined8 local_28;

  undefined8 local_20;

  

  local_28 = 10;

  local_20 = 0xf;

  *param_2 = param_6;

  *(undefined1 *)(param_2 + 4) = 1;

  param_2[2] = (int)(float)param_4;

  param_2[3] = (int)(float)param_5;

  local_38[0] = s_InvTrumpet_14030e7e0[0];

  local_38[1] = s_InvTrumpet_14030e7e0[1];

  local_38[2] = s_InvTrumpet_14030e7e0[2];

  local_38[3] = s_InvTrumpet_14030e7e0[3];

  local_38[4] = s_InvTrumpet_14030e7e0[4];

  local_38[5] = s_InvTrumpet_14030e7e0[5];

  local_38[6] = s_InvTrumpet_14030e7e0[6];

  local_38[7] = s_InvTrumpet_14030e7e0[7];

  uStack_30 = (ulonglong)(ushort)s_InvTrumpet_14030e7e0._8_2_;

  iVar1 = FUN_14006fe60(local_38);

  iVar1 = iVar1 + param_6;

  param_2[1] = iVar1;

  uVar2 = FUN_140072cc0(iVar1);

  uVar3 = FUN_140072ca0(iVar1);

  FUN_1400c9c30(param_1,param_3,param_4,param_5,uVar3,uVar2,1);

  return;

}




