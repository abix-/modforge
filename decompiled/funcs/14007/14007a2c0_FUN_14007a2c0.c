// Address: 0x14007a2c0
// Ghidra name: FUN_14007a2c0
// ============ 0x14007a2c0 FUN_14007a2c0 (size=1094) ============


undefined8 FUN_14007a2c0(undefined8 *param_1,int param_2,int param_3,int param_4,longlong param_5)



{

  char cVar1;

  uint uVar2;

  int iVar3;

  undefined8 uVar4;

  int iVar5;

  uint uVar6;

  size_t _Size;

  uint uVar7;

  void *_Buf1;

  int iVar8;

  ulonglong uVar9;

  code *pcVar10;

  void *_Buf1_00;

  bool bVar11;

  int local_res18 [2];

  uint local_res20;

  int local_68;

  int local_64;

  

  _Size = (size_t)param_4;

  bVar11 = (param_4 - 2U & 0xfffffffd) == 0;

  uVar7 = (uint)bVar11;

  local_res20 = (uint)bVar11;

  iVar8 = param_4 + -1;

  if (local_res20 == 0) {

    iVar8 = param_4;

  }

  if ((param_3 < 0) || (param_2 < 0)) {

    return 0;

  }

  iVar5 = (iVar8 + (uint)bVar11) * 8;

  if (DAT_1403d95d0 == 0) {

    uVar4 = FUN_14007a710(param_1,0xffffffff,0xffffffff,param_2,param_3,param_4,0,param_5,

                          local_res20,0,"111 221 2222 11",0,0,(iVar8 < 2) + '\x02',0,0,0,0,0,param_2

                          ,param_3,iVar5,bVar11 * '\b');

    return uVar4;

  }

  FUN_14007ac10(param_1,"111 221 2222 11",0,0,(iVar8 < 2) + '\n',0,0,0,0,0,param_2,param_3,iVar5,

                bVar11 * '\b');

  param_3 = param_3 + -1;

  if (-1 < param_3) {

    param_5 = param_3 * param_2 * param_4 + param_5;

    do {

      local_64 = 0;

      if (0 < param_2) {

        local_68 = 2;

        do {

          uVar6 = 1;

          _Buf1_00 = (void *)(local_64 * param_4 + param_5);

          iVar8 = 1;

          if (local_64 < param_2 + -1) {

            uVar6 = 2;

            local_res18[0] = memcmp(_Buf1_00,(void *)((local_64 + 1) * param_4 + param_5),_Size);

            if (local_res18[0] == 0) {

              iVar8 = 0;

              if (local_68 < param_2) {

                iVar5 = local_68 * param_4;

                do {

                  iVar8 = local_res18[0];

                  uVar7 = local_res20;

                  if ((0x7f < (int)uVar6) ||

                     (iVar3 = memcmp(_Buf1_00,(void *)(iVar5 + param_5),_Size),

                     iVar8 = local_res18[0], uVar7 = local_res20, iVar3 != 0)) break;

                  uVar6 = uVar6 + 1;

                  iVar5 = iVar5 + param_4;

                } while ((int)(local_68 + -2 + uVar6) < param_2);

              }

              goto LAB_14007a5a8;

            }

            if (local_68 < param_2) {

              iVar8 = local_68 * param_4;

              _Buf1 = _Buf1_00;

              do {

                if (0x7f < (int)uVar6) break;

                iVar5 = memcmp(_Buf1,(void *)(iVar8 + param_5),_Size);

                if (iVar5 == 0) {

                  uVar6 = uVar6 - 1;

                  break;

                }

                uVar6 = uVar6 + 1;

                _Buf1 = (void *)((longlong)_Buf1 + _Size);

                iVar8 = iVar8 + param_4;

              } while ((int)(local_68 + -2 + uVar6) < param_2);

            }

            cVar1 = (char)uVar6;

            uVar4 = param_1[1];

            pcVar10 = (code *)*param_1;

LAB_14007a5c9:

            local_res18[0] = CONCAT31(local_res18[0]._1_3_,cVar1 + -1);

            (*pcVar10)(uVar4,local_res18,1);

            uVar2 = local_res20;

            uVar7 = local_res20;

            if (0 < (int)uVar6) {

              uVar9 = (ulonglong)uVar6;

              do {

                FUN_14007a7b0(param_1,0xffffffff,param_4,uVar2,0,_Buf1_00);

                _Buf1_00 = (void *)((longlong)_Buf1_00 + _Size);

                uVar9 = uVar9 - 1;

                uVar7 = local_res20;

              } while (uVar9 != 0);

            }

          }

          else {

LAB_14007a5a8:

            cVar1 = (char)uVar6;

            uVar4 = param_1[1];

            pcVar10 = (code *)*param_1;

            if (iVar8 != 0) goto LAB_14007a5c9;

            local_res18[0] = CONCAT31(local_res18[0]._1_3_,cVar1 + '\x7f');

            (*pcVar10)(uVar4,local_res18,1);

            FUN_14007a7b0(param_1,0xffffffff,param_4,uVar7,0,_Buf1_00);

          }

          local_64 = local_64 + uVar6;

          local_68 = local_68 + uVar6;

        } while (local_64 < param_2);

      }

      param_3 = param_3 + -1;

      param_5 = param_5 + -(param_2 * param_4);

    } while (-1 < param_3);

  }

  return 1;

}




