// Address: 0x14010cc50
// Ghidra name: FUN_14010cc50
// ============ 0x14010cc50 FUN_14010cc50 (size=307) ============


void FUN_14010cc50(longlong param_1,undefined8 param_2,int param_3)



{

  undefined4 local_res8;

  undefined4 local_resc;

  undefined8 local_38;

  char local_30 [8];

  ulonglong uStack_28;

  undefined8 local_20;

  undefined8 local_18;

  

  if (*(char *)(param_1 + 0x260) != '\0') {

    local_38 = param_2;

    if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)

        < DAT_1403fb424) {

      FUN_1402c7138(&DAT_1403fb424);

      if (DAT_1403fb424 == -1) {

        local_20 = 9;

        local_18 = 0xf;

        local_30[0] = s_PoofHeart_14030e9e0[0];

        local_30[1] = s_PoofHeart_14030e9e0[1];

        local_30[2] = s_PoofHeart_14030e9e0[2];

        local_30[3] = s_PoofHeart_14030e9e0[3];

        local_30[4] = s_PoofHeart_14030e9e0[4];

        local_30[5] = s_PoofHeart_14030e9e0[5];

        local_30[6] = s_PoofHeart_14030e9e0[6];

        local_30[7] = s_PoofHeart_14030e9e0[7];

        uStack_28 = (ulonglong)(byte)s_PoofHeart_14030e9e0[8];

        DAT_1403fb420 = FUN_14006fe60(local_30);

        _Init_thread_footer(&DAT_1403fb424);

      }

    }

    local_res8 = 0;

    local_resc = 0xc0000000;

    FUN_1400c8dc0(*(undefined8 *)(param_1 + 0x248),DAT_1403fb420 + param_3,&local_38,&local_res8,0,0

                  ,&DAT_1403dc2b4,0x3c,DAT_14039ca44);

  }

  return;

}




