// Address: 0x14005e010
// Ghidra name: FUN_14005e010
// ============ 0x14005e010 FUN_14005e010 (size=501) ============


void FUN_14005e010(undefined8 param_1,int param_2,undefined4 param_3,undefined4 param_4,

                  undefined4 param_5)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  char local_70 [4];

  char local_6c [2];

  char local_6a;

  undefined1 local_69;

  undefined8 local_68;

  undefined8 local_60;

  undefined8 local_58;

  

  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) <

      DAT_1403ea94c) {

    FUN_1402c7138(&DAT_1403ea94c);

    if (DAT_1403ea94c == -1) {

      local_68 = 0;

      local_60 = 7;

      local_58 = 0xf;

      local_70[0] = s_LetterG_1403069c8[0];

      local_70[1] = s_LetterG_1403069c8[1];

      local_70[2] = s_LetterG_1403069c8[2];

      local_70[3] = s_LetterG_1403069c8[3];

      local_6c[0] = s_LetterG_1403069c8[4];

      local_6c[1] = s_LetterG_1403069c8[5];

      local_6a = s_LetterG_1403069c8[6];

      local_69 = 0;

      DAT_1403ea948 = FUN_14006fe60(local_70);

      _Init_thread_footer(&DAT_1403ea94c);

    }

  }

  FUN_140072f50(CONCAT44(param_4,param_3),0);

  uVar4 = DAT_14039ca7c;

  uVar3 = DAT_140304c58;

  uVar2 = DAT_14030335c;

  uVar1 = *(undefined4 *)(&DAT_1403ea8e0 + (longlong)param_2 * 4);

  FUN_1400731f0(param_1,0,DAT_140304c58,DAT_14030335c,DAT_14039ca7c,DAT_140304c58,DAT_14039ca7c,

                uVar1);

  FUN_140073140(param_1,uVar3,uVar4,DAT_14039ca34,DAT_1403069d4,uVar1);

  FUN_1400731f0(param_1,0,uVar2,uVar3,DAT_14039ca2c,uVar2,DAT_14039ca2c,uVar1);

  FUN_140073360(param_1,DAT_1403ea948 + param_2,0,0,param_5,DAT_1403069d0,0);

  FUN_1400730f0();

  return;

}




