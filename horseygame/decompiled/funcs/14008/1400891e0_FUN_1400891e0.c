// Address: 0x1400891e0
// Ghidra name: FUN_1400891e0
// ============ 0x1400891e0 FUN_1400891e0 (size=654) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400891e0(longlong param_1,longlong param_2,int param_3)



{

  float fVar1;

  undefined8 uVar2;

  float *pfVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float local_res8;

  float local_resc;

  ulonglong in_stack_ffffffffffffff98;

  uint uVar8;

  ulonglong uVar7;

  undefined4 uVar9;

  char *local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  ulonglong uStack_40;

  

  uVar8 = (uint)(in_stack_ffffffffffffff98 >> 0x20);

  if (*(int *)(param_1 + 0x250) == 0) {

    return;

  }

  if (param_3 != 3) {

    if (param_3 != 4) {

      return;

    }

    if (*(int *)(param_1 + 0x250) != 2) {

      return;

    }

    if (*(int *)(param_2 + 8) != 3) {

      return;

    }

    if (*(int *)(param_2 + 0xc) != 0xd) {

      return;

    }

    FUN_14005cf70(param_2);

    if (*(longlong *)(param_2 + 0x78) == 0) {

      return;

    }

    *(longlong *)(param_1 + 0x278) = param_2;

    *(undefined4 *)(param_2 + 0x28) = 0x461c4000;

    *(undefined8 *)(param_1 + 0x250) = 8;

    return;

  }

  if (*(int *)(param_2 + 8) != 3) {

    return;

  }

  if (*(longlong *)(param_1 + 0x270) == 0) {

    *(longlong *)(param_1 + 0x270) = param_2;

    uVar7 = in_stack_ffffffffffffff98 & 0xffffffff00000000;

    FUN_1400a8890(param_2,*(undefined4 *)(param_1 + 0x268),*(undefined4 *)(param_1 + 0x26c),

                  DAT_140303354,uVar7);

    uVar9 = (undefined4)(uVar7 >> 0x20);

    local_58 = (char *)0x0;

    uStack_50 = 0;

    local_48 = 0;

    uStack_40 = 0;

    local_58 = (char *)FUN_1400285e0(0x20);

    uVar2 = s_Receptacle_loaded_14030b240._8_8_;

    local_48 = _DAT_1403040f0;

    uStack_40 = _UNK_1403040f8;

    *(undefined8 *)local_58 = s_Receptacle_loaded_14030b240._0_8_;

    *(undefined8 *)(local_58 + 8) = uVar2;

    local_58[0x10] = s_Receptacle_loaded_14030b240[0x10];

    local_58[0x11] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_58,0,CONCAT44(uVar9,DAT_140303758)

                 );

    if (uStack_40 < 0x10) {

      return;

    }

    if ((0xfff < uStack_40 + 1) && ((char *)0x1f < local_58 + (-8 - *(longlong *)(local_58 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

    return;

  }

  fVar5 = *(float *)(param_2 + 0x28) - *(float *)(param_1 + 0x268);

  fVar6 = *(float *)(param_2 + 0x2c) - *(float *)(param_1 + 0x26c);

  fVar4 = fVar6 * fVar6 + fVar5 * fVar5;

  if (fVar4 < 0.0) {

    fVar4 = (float)FUN_1402cdfa0();

  }

  else {

    fVar4 = SQRT(fVar4);

  }

  fVar1 = DAT_140303354;

  if (DAT_14039c9f0 <= fVar4) {

    if (DAT_140303354 <= fVar4) {

      fVar5 = (DAT_14039ca44 / fVar4) * fVar5 * DAT_140303380;

      local_resc = (DAT_14039ca44 / fVar4) * fVar6 * DAT_140303380;

      pfVar3 = &local_res8;

      local_res8 = fVar5;

      goto LAB_1400892f0;

    }

  }

  pfVar3 = (float *)FUN_1400c6d00(&local_res8,DAT_140303380);

  fVar5 = *pfVar3;

LAB_1400892f0:

  FUN_1400a8890(param_2,fVar5 + *(float *)(param_1 + 0x268),pfVar3[1] + *(float *)(param_1 + 0x26c),

                fVar1,(ulonglong)uVar8 << 0x20);

  return;

}




