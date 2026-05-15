// Address: 0x140137340
// Ghidra name: FUN_140137340
// ============ 0x140137340 FUN_140137340 (size=492) ============


longlong FUN_140137340(longlong param_1,int param_2,uint param_3,undefined8 param_4,

                      undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,

                      undefined8 param_9,longlong *param_10,uint *param_11,uint *param_12)



{

  longlong lVar1;

  longlong lVar2;

  uint uVar3;

  ulonglong uVar4;

  ulonglong local_f8 [4];

  undefined4 local_d8;

  undefined8 local_c8;

  undefined8 local_c0;

  undefined4 local_98;

  undefined1 local_7b;

  undefined4 local_78;

  undefined1 local_70;

  ulonglong *local_40;

  undefined4 local_38;

  undefined4 local_34;

  undefined1 local_30;

  

  if (param_11 == (uint *)0x0) {

    lVar1 = *(longlong *)(*param_10 + 8 + (longlong)param_2 * 0x10);

  }

  else {

    uVar4 = 0;

    if (*param_11 != 0) {

      lVar1 = *param_10;

      do {

        if ((*(int *)(lVar1 + uVar4 * 0x10) == param_2) &&

           (*(uint *)(lVar1 + 4 + uVar4 * 0x10) == param_3)) {

          return *(longlong *)(lVar1 + 8 + uVar4 * 0x10);

        }

        uVar3 = (int)uVar4 + 1;

        uVar4 = (ulonglong)uVar3;

      } while (uVar3 < *param_11);

    }

    FUN_1402f94c0(&local_c8,0,0xa8);

    local_38 = 1;

    local_d8 = 0;

    local_34 = 0x3a;

    local_40 = local_f8;

    local_30 = 0;

    local_f8[1] = 0;

    local_f8[0] = (ulonglong)param_3;

    local_f8[2] = 0;

    local_f8[3] = 0xf00000000;

    local_c0 = param_8;

    if ((((param_2 != 3) && (local_c0 = param_9, param_2 != 4)) &&

        (local_c0 = param_6, param_2 != 1)) && (local_c0 = param_5, param_2 == 2)) {

      local_c0 = param_7;

    }

    local_7b = *(undefined1 *)(param_1 + 0x2ad);

    local_78 = 0;

    local_70 = 0;

    local_98 = 0;

    local_c8 = param_4;

    lVar1 = FUN_1401349d0(param_1,&local_c8);

    if (lVar1 == 0) {

      FUN_14012e850("Failed to create GPU pipeline for blit");

      lVar1 = 0;

    }

    else {

      if (*param_12 <= *param_11 + 1) {

        uVar3 = *param_12 * 2;

        *param_12 = uVar3;

        lVar2 = FUN_140184230(*param_10,(ulonglong)uVar3 << 4);

        *param_10 = lVar2;

      }

      *(longlong *)(*param_10 + 8 + (ulonglong)*param_11 * 0x10) = lVar1;

      *(int *)(*param_10 + (ulonglong)*param_11 * 0x10) = param_2;

      *(uint *)(*param_10 + 4 + (ulonglong)*param_11 * 0x10) = param_3;

      *param_11 = *param_11 + 1;

    }

  }

  return lVar1;

}




