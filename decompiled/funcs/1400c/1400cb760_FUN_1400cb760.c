// Address: 0x1400cb760
// Ghidra name: FUN_1400cb760
// ============ 0x1400cb760 FUN_1400cb760 (size=337) ============


void FUN_1400cb760(longlong param_1,int param_2,undefined8 param_3,char param_4,undefined8 param_5,

                  char param_6)



{

  int iVar1;

  char local_30 [8];

  ulonglong uStack_28;

  undefined8 local_20;

  undefined8 local_18;

  

  FUN_140104dc0(DAT_1403fb0d8);

  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) <

      DAT_1403f35cc) {

    FUN_1402c7138(&DAT_1403f35cc);

    if (DAT_1403f35cc == -1) {

      local_20 = 10;

      local_18 = 0xf;

      local_30[0] = s_InvTrumpet_14030e7e0[0];

      local_30[1] = s_InvTrumpet_14030e7e0[1];

      local_30[2] = s_InvTrumpet_14030e7e0[2];

      local_30[3] = s_InvTrumpet_14030e7e0[3];

      local_30[4] = s_InvTrumpet_14030e7e0[4];

      local_30[5] = s_InvTrumpet_14030e7e0[5];

      local_30[6] = s_InvTrumpet_14030e7e0[6];

      local_30[7] = s_InvTrumpet_14030e7e0[7];

      uStack_28 = (ulonglong)(ushort)s_InvTrumpet_14030e7e0._8_2_;

      DAT_1403f35c8 = FUN_14006fe60(local_30);

      _Init_thread_footer(&DAT_1403f35cc);

    }

  }

  *(uint *)(param_1 + 0x1a0) = (-(uint)(param_4 != '\0') & 6) + DAT_1403f35c8 + param_2;

  *(undefined8 *)(param_1 + 0x1a4) = param_5;

  if (param_6 != '\0') {

    iVar1 = FUN_140072ca0();

    *(float *)(param_1 + 0x1a4) = *(float *)(param_1 + 0x1a4) - (float)(iVar1 / 2);

    iVar1 = FUN_140072cc0(*(undefined4 *)(param_1 + 0x1a0));

    *(float *)(param_1 + 0x1a8) = *(float *)(param_1 + 0x1a8) - (float)(iVar1 / 2);

  }

  return;

}




