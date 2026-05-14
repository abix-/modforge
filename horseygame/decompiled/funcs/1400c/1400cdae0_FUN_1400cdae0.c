// Address: 0x1400cdae0
// Ghidra name: FUN_1400cdae0
// ============ 0x1400cdae0 FUN_1400cdae0 (size=733) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400cdae0(longlong *param_1)



{

  float fVar1;

  float fVar2;

  longlong lVar3;

  undefined8 uVar4;

  undefined4 uVar5;

  float *pfVar6;

  float local_res8;

  float local_resc;

  ulonglong in_stack_ffffffffffffffc8;

  char *local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  if (DAT_1403f3110 != 0) {

    FUN_1400c8d90();

  }

  FUN_14003f6f0();

  *(undefined4 *)((longlong)param_1 + 0x16c) = 0xffffffff;

  if ((int)param_1[0x36] == 1) {

    FUN_1400cba60(param_1);

  }

  if (*(int *)((longlong)param_1 + 0xd4) != -1) {

    (**(code **)(*param_1 + 0x90))

              (param_1,*(undefined8 *)

                        (param_1[0x17] + (longlong)*(int *)((longlong)param_1 + 0xd4) * 8));

    *(undefined4 *)((longlong)param_1 + 0xd4) = 0xffffffff;

  }

  if ((int)param_1[0x2d] != -1) {

    lVar3 = *(longlong *)(param_1[0x26] + (longlong)(int)param_1[0x2d] * 8);

    local_18 = _DAT_1403040c0;

    uStack_10 = _UNK_1403040c8;

    local_28 = (char *)s_DropHorseFail_14030e7c0._0_8_;

    uStack_20 = (ulonglong)CONCAT14(s_DropHorseFail_14030e7c0[0xc],s_DropHorseFail_14030e7c0._8_4_);

    FUN_1400b4a10(lVar3,&local_res8);

    uVar5 = FUN_140040fe0();

    in_stack_ffffffffffffffc8 = in_stack_ffffffffffffffc8 & 0xffffffffffffff00;

    FUN_140040ca0(&local_28,100,uVar5,DAT_14039ca44,in_stack_ffffffffffffffc8);

    if (0xf < uStack_10) {

      if (0xfff < uStack_10 + 1) {

        if ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

    pfVar6 = (float *)FUN_1400b4a10(lVar3,&local_res8);

    fVar1 = pfVar6[1];

    fVar2 = *(float *)(param_1 + 0x31);

    *(float *)(lVar3 + 0x1e4) = *pfVar6 - *(float *)((longlong)param_1 + 0x184);

    *(float *)(lVar3 + 0x1e8) = fVar1 - fVar2;

    *(undefined1 *)(lVar3 + 0x1e1) = 1;

    local_res8 = *(float *)((longlong)param_1 + 0x184) + 0.0;

    local_resc = *(float *)(param_1 + 0x31) - DAT_140303358;

    FUN_1400b6610(lVar3,&local_res8);

    *(undefined4 *)(param_1 + 0x2d) = 0xffffffff;

  }

  if (*(char *)((longlong)param_1 + 0x234) != '\0') {

    local_28 = (char *)0x0;

    uStack_20 = 0;

    local_18 = 0;

    uStack_10 = 0;

    local_28 = (char *)FUN_1400285e0(0x20);

    uVar4 = s_TruckLeaveLocation_140303278._8_8_;

    local_18 = _DAT_140303410;

    uStack_10 = _UNK_140303418;

    *(undefined8 *)local_28 = s_TruckLeaveLocation_140303278._0_8_;

    *(undefined8 *)(local_28 + 8) = uVar4;

    *(undefined2 *)(local_28 + 0x10) = s_TruckLeaveLocation_140303278._16_2_;

    local_28[0x12] = '\0';

    FUN_140040ca0(&local_28,100,0,DAT_14039ca44,in_stack_ffffffffffffffc8 & 0xffffffffffffff00);

    if (0xf < uStack_10) {

      if (0xfff < uStack_10 + 1) {

        if ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

    *(undefined8 *)((longlong)param_1 + 0x23c) = 1;

    return;

  }

  (**(code **)(*param_1 + 0x38))(param_1);

  FUN_1400ce9b0(param_1);

  FUN_140104ac0(DAT_1403fb0d8);

  return;

}




