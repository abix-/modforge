// Address: 0x1402ca2c4
// Ghidra name: FUN_1402ca2c4
// ============ 0x1402ca2c4 FUN_1402ca2c4 (size=1267) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



void FUN_1402ca2c4(int *param_1,__uint64 *param_2,undefined8 param_3,_xDISPATCHER_CONTEXT *param_4,

                  _s_FuncInfo *param_5,char param_6,undefined4 param_7,_xDISPATCHER_CONTEXT *param_8

                  )



{

  int *piVar1;

  undefined8 *puVar2;

  char cVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  longlong lVar7;

  undefined8 uVar8;

  uint uVar9;

  ulonglong uVar10;

  int iVar11;

  undefined1 auStack_168 [32];

  _s_FuncInfo *local_148;

  _s_FuncInfo *local_140;

  longlong local_138;

  _xDISPATCHER_CONTEXT *local_130;

  undefined8 local_128;

  _xDISPATCHER_CONTEXT *local_120;

  char local_118;

  char local_110;

  char local_108;

  int local_104;

  undefined8 local_100;

  int *local_f8;

  __uint64 *local_f0;

  longlong *local_e8;

  _xDISPATCHER_CONTEXT *local_e0;

  uint local_d8;

  undefined4 uStack_d4;

  longlong local_d0;

  int local_c8;

  int iStack_c4;

  int iStack_c0;

  uint uStack_bc;

  int local_b8;

  _s_FuncInfo *local_b0;

  undefined8 local_a8;

  longlong *local_a0;

  undefined8 uStack_98;

  longlong *local_90;

  undefined8 uStack_88;

  uint local_78;

  _s_FuncInfo local_70;

  

  local_70._24_8_ = DAT_1403e8b00 ^ (ulonglong)auStack_168;

  local_e0 = param_8;

  local_108 = '\0';

  local_100 = param_3;

  local_f0 = param_2;

  iVar4 = __FrameHandler3::GetHandlerSearchState(param_2,param_4,param_5);

  local_104 = iVar4;

  if ((-2 < iVar4) && (iVar4 < param_5->maxState)) {

    if (((*param_1 == -0x1f928c9d) && (param_1[6] == 4)) &&

       (((param_1[8] == 0x19930520 || (param_1[8] + 0xe66cfadfU < 2)) &&

        (*(longlong *)(param_1 + 0xc) == 0)))) {

      lVar7 = FUN_1402c97f8();

      if (*(longlong *)(lVar7 + 0x20) == 0) {

        return;

      }

      lVar7 = FUN_1402c97f8();

      param_1 = *(int **)(lVar7 + 0x20);

      lVar7 = FUN_1402c97f8();

      local_108 = '\x01';

      param_3 = *(undefined8 *)(lVar7 + 0x28);

      local_100 = param_3;

      FUN_1402c8e90(*(undefined8 *)(param_1 + 0xe));

      if ((param_1 == (int *)0x0) ||

         ((((*param_1 == -0x1f928c9d && (param_1[6] == 4)) &&

           ((param_1[8] == 0x19930520 || (param_1[8] + 0xe66cfadfU < 2)))) &&

          (*(longlong *)(param_1 + 0xc) == 0)))) goto LAB_1402ca7b5;

      lVar7 = FUN_1402c97f8();

      if (*(longlong *)(lVar7 + 0x38) != 0) {

        lVar7 = FUN_1402c97f8();

        uVar8 = *(undefined8 *)(lVar7 + 0x38);

        lVar7 = FUN_1402c97f8();

        *(undefined8 *)(lVar7 + 0x38) = 0;

        cVar3 = FUN_1402cc784(param_1,uVar8);

        iVar4 = local_104;

        if (cVar3 == '\0') {

          cVar3 = FUN_1402cc86c(uVar8);

          if (cVar3 == '\0') {

                    /* WARNING: Subroutine does not return */

            FUN_1402cf8b8();

          }

          FUN_1402c9000(param_1,1);

          FUN_1402cbbb4(&local_c8);

                    /* WARNING: Subroutine does not return */

          FUN_1402c8240(&local_c8,&DAT_1403c7800);

        }

      }

    }

    local_a8 = *(undefined8 *)(param_4 + 8);

    local_b0 = param_5;

    if (((*param_1 == -0x1f928c9d) && (param_1[6] == 4)) &&

       ((param_1[8] == 0x19930520 || (param_1[8] + 0xe66cfadfU < 2)))) {

      if (param_5->nTryBlocks != 0) {

        local_140 = (_s_FuncInfo *)CONCAT44(local_140._4_4_,param_7);

        local_148 = param_5;

        FUN_1402c86f8(&local_90,&local_b0,iVar4,param_4);

        uVar5 = (uint)uStack_88;

        local_a0 = local_90;

        uStack_98 = uStack_88;

        if (uVar5 < local_78) {

          local_e8 = local_90;

          do {

            lVar7 = (longlong)*(int *)(*local_a0 + 0x10) + (ulonglong)uVar5 * 0x14;

            piVar1 = (int *)(lVar7 + local_90[1]);

            local_c8 = *piVar1;

            iStack_c4 = piVar1[1];

            iStack_c0 = piVar1[2];

            uStack_bc = piVar1[3];

            local_b8 = *(int *)(lVar7 + 0x10 + local_90[1]);

            if ((local_c8 <= iVar4) && (iVar4 <= iStack_c4)) {

              local_d0 = (longlong)local_b8 + *(longlong *)(param_4 + 8);

              uVar10 = 0;

              uStack_d4 = 0;

              param_2 = local_f0;

              local_d8 = uStack_bc;

              if (uStack_bc != 0) {

                do {

                  puVar2 = (undefined8 *)(local_d0 + uVar10 * 0x14);

                  local_70._0_8_ = *puVar2;

                  local_70._8_8_ = puVar2[1];

                  local_70.dispTryBlockMap = *(undefined4 *)(local_d0 + 0x10 + uVar10 * 0x14);

                  iVar4 = *(int *)(*(longlong *)(param_1 + 0xc) + 0xc);

                  lVar7 = FUN_1402c8e64();

                  local_f8 = (int *)(lVar7 + 4 + (longlong)iVar4);

                  iVar4 = *(int *)(*(longlong *)(param_1 + 0xc) + 0xc);

                  lVar7 = FUN_1402c8e64();

                  iVar11 = *(int *)(lVar7 + iVar4);

                  iVar4 = local_104;

                  param_2 = local_f0;

                  local_90 = local_e8;

                  for (; local_104 = iVar4, local_f0 = param_2, local_e8 = local_90, 0 < iVar11;

                      iVar11 = iVar11 + -1) {

                    iVar4 = *local_f8;

                    lVar7 = FUN_1402c8e64();

                    iVar6 = FUN_1402cb260(&local_70,iVar4 + lVar7,*(undefined8 *)(param_1 + 0xc));

                    param_2 = local_f0;

                    if (iVar6 != 0) {

                      local_110 = param_6;

                      local_118 = local_108;

                      local_120 = local_e0;

                      local_128 = CONCAT44(local_128._4_4_,param_7);

                      local_130 = (_xDISPATCHER_CONTEXT *)&local_c8;

                      local_140 = &local_70;

                      local_148 = param_5;

                      local_138 = iVar4 + lVar7;

                      FUN_1402ca114(param_1,local_f0,local_100,param_4);

                      local_90 = local_e8;

                      iVar4 = local_104;

                      goto LAB_1402ca629;

                    }

                    local_f8 = local_f8 + 1;

                    iVar4 = local_104;

                    local_90 = local_e8;

                  }

                  uVar9 = (int)uVar10 + 1;

                  uVar10 = (ulonglong)uVar9;

                } while (uVar9 != local_d8);

              }

            }

LAB_1402ca629:

            uVar5 = uVar5 + 1;

          } while (uVar5 < local_78);

        }

      }

      if ((0x19930520 < (param_5->magicNumber_and_bbtFlags & 0x1fffffff)) &&

         (((iVar4 = param_5->dispESTypeList, iVar4 != 0 &&

           (lVar7 = FUN_1402c8e50(), lVar7 + iVar4 != 0)) ||

          ((((uint)param_5->EHFlags >> 2 & 1) != 0 &&

           (cVar3 = FUN_1402c8520(param_4,param_5), cVar3 == '\0')))))) {

        if (((uint)param_5->EHFlags >> 2 & 1) != 0) {

          lVar7 = FUN_1402c97f8();

          *(int **)(lVar7 + 0x20) = param_1;

          lVar7 = FUN_1402c97f8();

          *(undefined8 *)(lVar7 + 0x28) = local_100;

                    /* WARNING: Subroutine does not return */

          FUN_1402cf8b8();

        }

        iVar4 = param_5->dispESTypeList;

        if (iVar4 == 0) {

          lVar7 = 0;

        }

        else {

          lVar7 = FUN_1402c8e50();

          lVar7 = iVar4 + lVar7;

        }

        cVar3 = FUN_1402cc784(param_1,lVar7);

        if (cVar3 == '\0') {

          uVar8 = FUN_1402c85ec(param_2,param_4,param_5,&local_e0);

          local_118 = param_6;

          local_128 = 0;

          local_130 = (_xDISPATCHER_CONTEXT *)CONCAT44(local_130._4_4_,0xffffffff);

          local_138 = CONCAT44(local_138._4_4_,0xffffffff);

          local_140 = param_5;

          local_148 = (_s_FuncInfo *)0x0;

          local_120 = param_4;

          FUN_1402c89b0(param_2,param_1,local_100,uVar8);

        }

      }

    }

    else if (param_5->nTryBlocks != 0) {

      if (param_6 != '\0') goto LAB_1402ca7b5;

      local_130 = param_8;

      local_138 = CONCAT44(local_138._4_4_,param_7);

      local_140 = (_s_FuncInfo *)CONCAT44(local_140._4_4_,iVar4);

      local_148 = param_5;

      FUN_1402cacf4(param_1,param_2,param_3,param_4);

    }

    lVar7 = FUN_1402c97f8();

    if (*(longlong *)(lVar7 + 0x38) == 0) {

      return;

    }

  }

LAB_1402ca7b5:

                    /* WARNING: Subroutine does not return */

  FUN_1402e1bf8();

}




