// Address: 0x140031740
// Ghidra name: FUN_140031740
// ============ 0x140031740 FUN_140031740 (size=1077) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_140031740(longlong param_1,int param_2,int param_3)



{

  int iVar1;

  undefined8 uVar2;

  float fVar3;

  undefined4 uVar4;

  uint uVar5;

  longlong lVar6;

  longlong lVar7;

  longlong lVar8;

  longlong lVar9;

  int iVar10;

  longlong lVar11;

  undefined4 uVar12;

  undefined4 uVar13;

  float fVar14;

  undefined4 local_res20;

  uint local_res24;

  ulonglong in_stack_ffffffffffffff18;

  undefined4 uVar15;

  float local_b8;

  float local_b4;

  undefined8 *local_b0;

  ulonglong uStack_a8;

  undefined8 local_a0;

  ulonglong uStack_98;

  

  fVar14 = DAT_14039ca38;

  fVar3 = DAT_140303fd8;

  uVar4 = DAT_140303398;

  if ((param_3 == 3) && (*(int *)(param_1 + 0x250) != 0)) {

    iVar10 = 0;

    lVar9 = 0xcc;

    do {

      iVar1 = *(int *)(lVar9 + *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8)

                      );

      if (iVar1 != -1) {

        FUN_1400cc9d0(param_1,iVar1,fVar3 - (float)iVar10 * fVar14,uVar4);

        iVar10 = iVar10 + 1;

      }

      lVar9 = lVar9 + 4;

    } while (lVar9 < 0x120);

    lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8) + 0x2b8;

    lVar11 = 2;

    do {

      lVar8 = 0;

      lVar7 = 0x2b8;

      do {

        if ((*(char *)(lVar9 + lVar8) != -1) &&

           (lVar6 = *(char *)(lVar9 + lVar8) + lVar7, *(char *)(lVar6 + param_1) == '\0')) {

          *(undefined1 *)(lVar6 + param_1) = 1;

        }

        lVar8 = lVar8 + 1;

        lVar7 = lVar7 + 4;

      } while (lVar7 < 0x678);

      lVar9 = lVar9 + 0xf0;

      lVar11 = lVar11 + -1;

    } while (lVar11 != 0);

    FUN_140032610(param_1);

    FUN_1400cf7f0(param_1,param_2);

    *(undefined4 *)(param_1 + 0x694) = 0x3c;

    local_a0 = _DAT_1403040a0;

    uStack_98 = _UNK_1403040a8;

    local_b0 = (undefined8 *)s_VatBurble_140303a00._0_8_;

    uStack_a8 = (ulonglong)(byte)s_VatBurble_140303a00[8];

    in_stack_ffffffffffffff18 = in_stack_ffffffffffffff18 & 0xffffffffffffff00;

    FUN_140040ca0(&local_b0,100,0,DAT_14039ca44,in_stack_ffffffffffffff18);

    if (0xf < uStack_98) {

      if (0xfff < uStack_98 + 1) {

        if (0x1f < (ulonglong)((longlong)local_b0 + (-8 - local_b0[-1]))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

    uVar5 = DAT_14039cac0;

    uVar4 = DAT_14039ca24;

    fVar3 = DAT_140303354;

    fVar14 = (float)(0x5d - ((int)(*(int *)(param_1 + 0x690) +

                                  (*(int *)(param_1 + 0x690) >> 0x1f & 0x1fU)) >> 5)) *

             DAT_140303354;

    lVar9 = 0x1e;

    do {

      uVar15 = (undefined4)(in_stack_ffffffffffffff18 >> 0x20);

      local_res24 = FUN_1400c6940();

      local_res24 = local_res24 ^ uVar5;

      local_res20 = 0;

      iVar10 = FUN_1400c6580(0x24);

      local_b8 = (float)(iVar10 + 0x10e) * fVar3;

      uVar2 = *(undefined8 *)(param_1 + 0x248);

      local_b4 = fVar14;

      uVar12 = FUN_1400c6940();

      uVar13 = FUN_1400c6940();

      in_stack_ffffffffffffff18 = CONCAT44(uVar15,uVar13);

      FUN_1400c8dc0(uVar2,0xffffffff,&local_b8,&local_res20,in_stack_ffffffffffffff18,uVar12,

                    &DAT_1403d4148,0x3c,uVar4);

      uVar12 = (undefined4)(in_stack_ffffffffffffff18 >> 0x20);

      lVar9 = lVar9 + -1;

    } while (lVar9 != 0);

    if ((*(int *)(param_1 + 0x250) == 2) || (*(int *)(param_1 + 0x250) == 1)) {

      FUN_14003f6f0();

      *(undefined8 *)(param_1 + 0x250) = 3;

    }

    else {

      local_b0 = (undefined8 *)0x0;

      uStack_a8 = 0;

      local_a0 = 0;

      uStack_98 = 0;

      local_b0 = (undefined8 *)FUN_1400285e0(0x20);

      uVar2 = _UNK_140303a18;

      local_a0 = _DAT_140304140;

      uStack_98 = _UNK_140304148;

      *local_b0 = _DAT_140303a10;

      local_b0[1] = uVar2;

      local_b0[2] = _DAT_140303a20;

      *(undefined4 *)(local_b0 + 3) = s_in_that_horse_140303a21._7_4_;

      *(undefined2 *)((longlong)local_b0 + 0x1c) = s_in_that_horse_140303a21._11_2_;

      *(char *)((longlong)local_b0 + 0x1e) = s_in_that_horse_140303a21[0xd];

      *(undefined1 *)((longlong)local_b0 + 0x1f) = 0;

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_b0,0,

                    CONCAT44(uVar12,DAT_140303758));

      if (0xf < uStack_98) {

        if (0xfff < uStack_98 + 1) {

          if (0x1f < (ulonglong)((longlong)local_b0 + (-8 - local_b0[-1]))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

        }

        FUN_1402c7088();

      }

    }

  }

  return 1;

}




