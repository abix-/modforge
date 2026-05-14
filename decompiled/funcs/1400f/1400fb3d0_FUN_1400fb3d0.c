// Address: 0x1400fb3d0
// Ghidra name: FUN_1400fb3d0
// ============ 0x1400fb3d0 FUN_1400fb3d0 (size=902) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400fb3d0(longlong param_1)



{

  longlong lVar1;

  float fVar2;

  char local_68 [8];

  undefined8 uStack_60;

  undefined8 local_58;

  undefined8 local_50;

  

  lVar1 = *(longlong *)(DAT_1403fb0d8 + 0x300);

  lVar1 = FUN_1401010d0(DAT_1403fb0d8,

                        (int)((*(float *)(lVar1 + 0x30) * DAT_14039ca34 + *(float *)(lVar1 + 0x28))

                             * DAT_140303fb4),

                        (int)((*(float *)(lVar1 + 0x34) * DAT_14039ca34 + *(float *)(lVar1 + 0x2c))

                             * DAT_140303fb4));

  FUN_140071ed0(*(undefined4 *)(lVar1 + 8));

  if (((*(int *)(param_1 + 0x25c) < 4) && (DAT_1403d9599 != '\0')) &&

     (*(char *)(param_1 + 0x260) == '\0')) {

    FUN_140086570(DAT_1403ede18);

    if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)

        < DAT_1403f4e64) {

      FUN_1402c7138(&DAT_1403f4e64);

      if (DAT_1403f4e64 == -1) {

        local_58 = 0xd;

        local_50 = 0xf;

        local_68[0] = s_DragHorseHere_140303318[0];

        local_68[1] = s_DragHorseHere_140303318[1];

        local_68[2] = s_DragHorseHere_140303318[2];

        local_68[3] = s_DragHorseHere_140303318[3];

        local_68[4] = s_DragHorseHere_140303318[4];

        local_68[5] = s_DragHorseHere_140303318[5];

        local_68[6] = s_DragHorseHere_140303318[6];

        local_68[7] = s_DragHorseHere_140303318[7];

        uStack_60 = (ulonglong)

                    CONCAT14(s_DragHorseHere_140303318[0xc],s_DragHorseHere_140303318._8_4_);

        _DAT_1403f4e60 = FUN_14006fe60(local_68);

        _Init_thread_footer(&DAT_1403f4e64);

      }

    }

  }

  if (*(char *)(param_1 + 0x260) != '\0') {

    if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)

        < DAT_1403f4e6c) {

      FUN_1402c7138(&DAT_1403f4e6c);

      if (DAT_1403f4e6c == -1) {

        uStack_60 = 0;

        local_58 = 4;

        local_50 = 0xf;

        builtin_strncpy(local_68,"Cas9",5);

        local_68[5] = '\0';

        local_68[6] = '\0';

        local_68[7] = '\0';

        DAT_1403f4e68 = FUN_14006fe60(local_68);

        _Init_thread_footer(&DAT_1403f4e6c);

      }

    }

    FUN_140071ed0(DAT_1403f4e68 + -1);

    FUN_140071ed0(DAT_1403f4e68 + 1);

  }

  fVar2 = (float)(*(uint *)(param_1 + 0x114) ^ DAT_14039cac0);

  FUN_140072fe0(CONCAT44(fVar2 * *(float *)(param_1 + 0x110),fVar2 * *(float *)(param_1 + 0x10c)));

  if (*(char *)(param_1 + 0x260) == '\0') {

    FUN_1400d5d90(param_1,0);

  }

  FUN_1400d5ff0(param_1,1);

  FUN_1400730f0();

  FUN_1400cacd0(param_1,1);

  return;

}




