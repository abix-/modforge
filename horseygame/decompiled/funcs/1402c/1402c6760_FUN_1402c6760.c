// Address: 0x1402c6760
// Ghidra name: FUN_1402c6760
// ============ 0x1402c6760 FUN_1402c6760 (size=489) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



undefined1 (*) [16]

FUN_1402c6760(undefined1 (*param_1) [16],undefined1 (*param_2) [16],undefined1 (*param_3) [16],

             ulonglong param_4)



{

  undefined1 auVar1 [16];

  undefined1 (*pauVar2) [16];

  int iVar3;

  ulonglong uVar4;

  char *pcVar5;

  undefined1 (*pauVar6) [16];

  longlong lVar7;

  undefined1 uVar8;

  bool bVar9;

  undefined1 auVar10 [16];

  undefined1 auStack_78 [32];

  undefined1 local_58 [16];

  ulonglong local_48;

  

  local_48 = DAT_1403e8b00 ^ (ulonglong)auStack_78;

  pauVar2 = param_1;

  if (param_4 != 0) {

    if (param_4 == 1) {

      pauVar2 = (undefined1 (*) [16])FUN_1402c61c0(param_1,param_2,(*param_3)[0]);

    }

    else {

      uVar4 = (longlong)param_2 - (longlong)param_1;

      pauVar2 = param_2;

      if (param_4 <= uVar4) {

        if (((DAT_1403e8ad4 >> 2 & 1) == 0) || (uVar4 < 0x10)) {

          pauVar6 = (undefined1 (*) [16])((longlong)param_1 + uVar4 + (1 - param_4));

          if (param_1 != pauVar6) {

            lVar7 = (longlong)param_3 - (longlong)param_1;

            do {

              if ((*param_1)[0] == (*param_3)[0]) {

                pcVar5 = *param_1 + 1;

                while (*pcVar5 == pcVar5[lVar7]) {

                  pcVar5 = pcVar5 + 1;

                  if ((longlong)pcVar5 - (longlong)param_1 == param_4) {

                    return param_1;

                  }

                }

              }

              param_1 = (undefined1 (*) [16])(*param_1 + 1);

              lVar7 = lVar7 + -1;

            } while (param_1 != pauVar6);

          }

        }

        else if (param_4 < 0x11) {

          uVar8 = 0x10 < (uint)param_4;

          FUN_1402f8e20(local_58,param_3,param_4);

          auVar1 = local_58;

          do {

            iVar3 = pcmpestri(local_58,*param_1,0xc);

            if ((bool)uVar8) {

              param_1 = (undefined1 (*) [16])(*param_1 + iVar3);

              if (iVar3 <= (int)(0x10 - (uint)param_4)) {

                return param_1;

              }

            }

            else {

              param_1 = param_1 + 1;

            }

            uVar8 = param_1 < param_2 + -1;

          } while (param_1 <= param_2 + -1);

          bVar9 = param_2 < param_1;

          if ((longlong)param_2 - (longlong)param_1 != 0) {

            FUN_1402f8e20(local_58,param_1,(longlong)param_2 - (longlong)param_1);

            iVar3 = pcmpestri(auVar1,local_58,0xc);

            if (bVar9) {

              pauVar2 = (undefined1 (*) [16])(*param_1 + iVar3);

            }

          }

        }

        else {

          auVar1 = *param_3;

          bVar9 = CARRY8((longlong)param_1 - param_4,uVar4);

          pauVar6 = (undefined1 (*) [16])(((longlong)param_1 - param_4) + uVar4);

          do {

            iVar3 = pcmpestri(auVar1,*param_1,0xc);

            if (bVar9) {

              if (iVar3 == 0) {

LAB_1402c68b8:

                iVar3 = memcmp(param_1 + 1,param_3 + 1,param_4 - 0x10);

                if (iVar3 == 0) {

                  return param_1;

                }

              }

              else {

                param_1 = (undefined1 (*) [16])(*param_1 + iVar3);

                if (pauVar6 < param_1) {

                  return param_2;

                }

                auVar10._0_4_ = *(uint *)*param_1 ^ auVar1._0_4_;

                auVar10._4_4_ = *(uint *)(*param_1 + 4) ^ auVar1._4_4_;

                auVar10._8_4_ = *(uint *)(*param_1 + 8) ^ auVar1._8_4_;

                auVar10._12_4_ = *(uint *)(*param_1 + 0xc) ^ auVar1._12_4_;

                if (auVar10 == (undefined1  [16])0x0) goto LAB_1402c68b8;

              }

              param_1 = (undefined1 (*) [16])(*param_1 + 1);

            }

            else {

              param_1 = param_1 + 1;

            }

            bVar9 = param_1 < pauVar6;

          } while (param_1 <= pauVar6);

        }

      }

    }

  }

  return pauVar2;

}




