// Address: 0x1402da77c
// Ghidra name: FUN_1402da77c
// ============ 0x1402da77c FUN_1402da77c (size=1275) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



void FUN_1402da77c(longlong param_1,ulonglong param_2,longlong param_3,longlong param_4,long param_5

                  ,LPCWSTR param_6)



{

  short sVar1;

  int iVar2;

  BOOL BVar3;

  DWORD DVar4;

  errno_t eVar5;

  undefined4 *puVar6;

  short *psVar7;

  longlong lVar8;

  longlong lVar9;

  longlong lVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  undefined4 local_2d2;

  undefined2 local_2ce [15];

  undefined *puStackY_2b0;

  undefined1 auStackY_2a8 [32];

  HMODULE local_278 [2];

  WCHAR local_268 [264];

  ulonglong local_58;

  

  local_58 = DAT_1403e8b00 ^ (ulonglong)auStackY_2a8;

  puStackY_2b0 = (undefined *)0x1402da7c2;

  iVar2 = FUN_1402f1060();

  if (iVar2 != 0) goto LAB_1402dac63;

  puStackY_2b0 = (undefined *)0x1402da7df;

  iVar2 = FUN_1402f0fd0();

  if (iVar2 != 0) goto LAB_1402dac63;

  puStackY_2b0 = (undefined *)0x1402da7f9;

  iVar2 = FUN_1402f0fd0();

  if (iVar2 != 0) goto LAB_1402dac63;

  puStackY_2b0 = (undefined *)0x1402da815;

  FUN_1402f94c0(local_268,0,0x20a);

  local_278[0] = (HMODULE)0x0;

  puStackY_2b0 = (undefined *)0x1402da82c;

  BVar3 = GetModuleHandleExW(6,param_6,local_278);

  if (BVar3 == 0) {

    local_278[0] = (HMODULE)0x0;

  }

  puStackY_2b0 = (undefined *)0x1402da852;

  DVar4 = GetModuleFileNameW(local_278[0],local_268,0x105);

  if (DVar4 == 0) {

    puStackY_2b0 = (undefined *)0x1402da869;

    iVar2 = FUN_1402f1060();

    if (iVar2 != 0) goto LAB_1402dac63;

  }

  lVar10 = -1;

  lVar9 = -1;

  do {

    lVar8 = lVar9;

    lVar9 = lVar8 + 1;

  } while (local_268[lVar9] != L'\0');

  if (0x40 < lVar8 + 0xcU) {

    puVar6 = (undefined4 *)((longlong)&local_2d2 + lVar9 * 2);

    if (puVar6 == (undefined4 *)0x0) {

      puStackY_2b0 = (undefined *)0x1402da8b0;

      puVar6 = (undefined4 *)FUN_1402e68b0();

      *puVar6 = 0x16;

    }

    else {

      if (5 < 0x20aU - (lVar9 * 2 + -0x6a)) {

        *puVar6 = (undefined4)DAT_140389f40;

        local_2ce[lVar9] = DAT_140389f40._4_2_;

        goto LAB_1402da8d9;

      }

      puStackY_2b0 = (undefined *)0x1402da9e6;

      FUN_1402f94c0();

      puStackY_2b0 = (undefined *)0x1402da9eb;

      puVar6 = (undefined4 *)FUN_1402e68b0();

      *puVar6 = 0x22;

    }

    puStackY_2b0 = (undefined *)0x1402da9f6;

    FUN_1402cd454();

    goto LAB_1402dac63;

  }

LAB_1402da8d9:

  puStackY_2b0 = (undefined *)0x1402da8e7;

  iVar2 = FUN_1402f0fd0();

  if (iVar2 != 0) goto LAB_1402dac63;

  puStackY_2b0 = (undefined *)0x1402da901;

  iVar2 = FUN_1402f0fd0();

  if (iVar2 != 0) goto LAB_1402dac63;

  puStackY_2b0 = (undefined *)0x1402da91b;

  iVar2 = FUN_1402f0fd0();

  if (iVar2 != 0) goto LAB_1402dac63;

  lVar9 = -1;

  do {

    lVar8 = lVar9;

    lVar9 = lVar8 + 1;

  } while (*(short *)(param_4 + lVar9 * 2) != 0);

  if (lVar8 + 9U < 0x41) {

LAB_1402daacf:

    puStackY_2b0 = (undefined *)0x1402daada;

    iVar2 = FUN_1402f0fd0();

  }

  else {

    uVar11 = 0xffffffffffffffff;

    do {

      uVar11 = uVar11 + 1;

    } while (*(short *)(param_4 + uVar11 * 2) != 0);

    sVar1 = *(short *)(param_4 + -2 + uVar11 * 2);

    uVar12 = 1;

    if (sVar1 != 0x5c) {

      psVar7 = (short *)(param_4 + -2 + uVar11 * 2);

      do {

        if ((sVar1 == 0x2f) || (uVar11 <= uVar12)) break;

        psVar7 = psVar7 + -1;

        uVar12 = uVar12 + 1;

        sVar1 = *psVar7;

      } while (sVar1 != 0x5c);

    }

    if (0x26 < uVar11 - uVar12) {

      if (0x11 < uVar12) goto LAB_1402daa53;

      puStackY_2b0 = (undefined *)0x1402da9ae;

      iVar2 = FUN_1402f10f0();

      if (iVar2 != 0) goto LAB_1402dac63;

      puStackY_2b0 = (undefined *)0x1402da9cb;

      iVar2 = FUN_1402f0fd0();

joined_r0x0001402da9cd:

      if (iVar2 != 0) goto LAB_1402dac63;

      goto LAB_1402daacf;

    }

    if (0x25 < uVar11 - uVar12) {

LAB_1402daa53:

      puStackY_2b0 = (undefined *)0x1402daa67;

      iVar2 = FUN_1402f10f0();

      if (iVar2 != 0) goto LAB_1402dac63;

      puStackY_2b0 = (undefined *)0x1402daa84;

      iVar2 = FUN_1402f0fd0();

      if (iVar2 != 0) goto LAB_1402dac63;

      puStackY_2b0 = (undefined *)0x1402daa9f;

      iVar2 = FUN_1402f10f0();

      if (iVar2 != 0) goto LAB_1402dac63;

      puStackY_2b0 = (undefined *)0x1402daab9;

      iVar2 = FUN_1402f0fd0();

      goto joined_r0x0001402da9cd;

    }

    puStackY_2b0 = (undefined *)0x1402daa17;

    iVar2 = FUN_1402f10f0();

    if (iVar2 != 0) goto LAB_1402dac63;

    puStackY_2b0 = (undefined *)0x1402daa31;

    iVar2 = FUN_1402f0fd0();

    if (iVar2 != 0) goto LAB_1402dac63;

    puStackY_2b0 = (undefined *)0x1402daa4b;

    iVar2 = FUN_1402f0fd0();

  }

  if (iVar2 == 0) {

    puStackY_2b0 = (undefined *)0x1402daaf4;

    iVar2 = FUN_1402f0fd0();

    if (iVar2 == 0) {

      puStackY_2b0 = (undefined *)0x1402dab0e;

      iVar2 = FUN_1402f0fd0();

      if (iVar2 == 0) {

        lVar9 = -1;

        do {

          lVar9 = lVar9 + 1;

        } while (*(short *)(param_1 + lVar9 * 2) != 0);

        lVar8 = -1;

        do {

          lVar8 = lVar8 + 1;

        } while (*(short *)(param_1 + lVar8 * 2) != 0);

        puStackY_2b0 = (undefined *)0x1402dab4c;

        eVar5 = FID_conflict__ltow_s(param_5,(wchar_t *)(param_1 + lVar8 * 2),param_2 - lVar9,10);

        if (eVar5 == 0) {

          puStackY_2b0 = (undefined *)0x1402dab66;

          iVar2 = FUN_1402f0fd0();

          if (iVar2 == 0) {

            puStackY_2b0 = (undefined *)0x1402dab80;

            iVar2 = FUN_1402f0fd0();

            if (iVar2 == 0) {

              lVar9 = -1;

              do {

                lVar8 = lVar9;

                lVar9 = lVar8 + 1;

              } while (*(short *)(param_1 + lVar9 * 2) != 0);

              do {

                lVar10 = lVar10 + 1;

              } while (*(short *)(param_3 + lVar10 * 2) != 0);

              if (param_2 < (ulonglong)(lVar10 + lVar8 + 0xb1)) {

                puStackY_2b0 = (undefined *)0x1402dabc6;

                iVar2 = FUN_1402f10f0();

                if (iVar2 != 0) goto LAB_1402dac63;

              }

              puStackY_2b0 = (undefined *)0x1402dabe0;

              iVar2 = FUN_1402f0fd0();

              if (iVar2 == 0) {

                puStackY_2b0 = (undefined *)0x1402dabf6;

                iVar2 = FUN_1402f0fd0();

                if (iVar2 == 0) {

                  puStackY_2b0 = (undefined *)0x1402dac0c;

                  iVar2 = FUN_1402f0fd0();

                  if (iVar2 == 0) {

                    puStackY_2b0 = (undefined *)0x1402dac22;

                    iVar2 = FUN_1402f0fd0();

                    if (iVar2 == 0) {

                      puStackY_2b0 = (undefined *)0x1402dac38;

                      iVar2 = FUN_1402f0fd0();

                      if (iVar2 == 0) {

                        return;

                      }

                    }

                  }

                }

              }

            }

          }

        }

      }

    }

  }

LAB_1402dac63:

                    /* WARNING: Subroutine does not return */

  puStackY_2b0 = &UNK_1402dac77;

  _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

}




