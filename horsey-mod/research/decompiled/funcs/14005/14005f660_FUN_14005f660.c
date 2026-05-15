// Address: 0x14005f660
// Ghidra name: FUN_14005f660
// ============ 0x14005f660 FUN_14005f660 (size=1025) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14005f660(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  float fVar3;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 local_30;

  

  lVar1 = *(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8);

  if ((*(int *)(lVar1 + 4) < DAT_1403ea9a4) && (FUN_1402c7138(&DAT_1403ea9a4), DAT_1403ea9a4 == -1))

  {

    uStack_40 = 0;

    local_38 = 7;

    local_30 = 0xf;

    local_48 = (ulonglong)

               CONCAT16(s_poster2_140307280[6],

                        CONCAT24(s_poster2_140307280._4_2_,s_poster2_140307280._0_4_));

    DAT_1403ea9a0 = FUN_14006fe60(&local_48);

    _Init_thread_footer(&DAT_1403ea9a4);

  }

  if (*(char *)(param_1 + 600) == '\0') {

    FUN_140070f90(DAT_1403d6148);

    iVar2 = -DAT_1403eda00;

    if (iVar2 < DAT_14030b680 + DAT_1403eda00 * 2) {

      do {

        FUN_140071000();

        iVar2 = iVar2 + 8;

      } while (iVar2 < DAT_14030b680 + DAT_1403eda00 * 2);

    }

    iVar2 = -DAT_1403eda04;

    if (iVar2 < DAT_1403eda04 + 0x60) {

      do {

        FUN_140071000();

        iVar2 = iVar2 + 0x10;

      } while (iVar2 < DAT_1403eda04 + 0x60);

    }

    FUN_140071000();

    if ((*(int *)(lVar1 + 4) < DAT_1403ea9ac) &&

       (FUN_1402c7138(&DAT_1403ea9ac), DAT_1403ea9ac == -1)) {

      uStack_40 = 0;

      local_38 = 5;

      local_30 = 0xf;

      local_48._0_5_ = CONCAT14(s_Poang_140307288[4],s_Poang_140307288._0_4_);

      local_48 = (ulonglong)(uint5)local_48;

      DAT_1403ea9a8 = FUN_14006fe60(&local_48);

      _Init_thread_footer(&DAT_1403ea9ac);

    }

    if ((*(int *)(lVar1 + 4) < DAT_1403ea9b4) &&

       (FUN_1402c7138(&DAT_1403ea9b4), DAT_1403ea9b4 == -1)) {

      uStack_40 = 0;

      local_38 = 5;

      local_30 = 0xf;

      local_48._0_5_ = CONCAT14(DAT_140307294,DAT_140307290);

      local_48 = (ulonglong)(uint5)local_48;

      DAT_1403ea9b0 = FUN_14006fe60(&local_48);

      _Init_thread_footer(&DAT_1403ea9b4);

    }

    FUN_140071d20(DAT_1403ea9a8);

    FUN_140071d20(DAT_1403ea9b0);

    FUN_140071ed0(DAT_1403ea9a0);

    fVar3 = (float)(*(uint *)(param_1 + 0x114) ^ DAT_14039cac0);

    FUN_140072fe0(CONCAT44(fVar3 * *(float *)(param_1 + 0x110),fVar3 * *(float *)(param_1 + 0x10c)))

    ;

    FUN_1400d5d90(param_1,1);

    FUN_1400d5ff0(param_1,1);

    FUN_1400730f0();

    FUN_1400cacd0(param_1,1);

  }

  else {

    FUN_140070f90(DAT_1403d6130);

    FUN_140071ed0(DAT_1403ea9a0);

  }

  return;

}




