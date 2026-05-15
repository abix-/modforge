// Address: 0x140190740
// Ghidra name: FUN_140190740
// ============ 0x140190740 FUN_140190740 (size=47) ============


void FUN_140190740(undefined4 *param_1,ulonglong param_2,ulonglong param_3,code *param_4,

                  undefined8 param_5)



{

  undefined1 uVar1;

  undefined4 uVar2;

  int iVar3;

  undefined8 uVar4;

  ulonglong uVar5;

  undefined4 *puVar6;

  undefined4 *puVar7;

  ulonglong uVar8;

  undefined4 *puVar9;

  undefined4 *puVar10;

  longlong lStackX_18;

  undefined8 *puStack_468;

  ulonglong *puStack_460;

  undefined4 *puStack_458;

  undefined4 *puStack_450;

  undefined8 uStack_438;

  ulonglong auStack_430 [127];

  

  if (param_2 < 2) {

    return;

  }

  puStack_458 = param_1;

  if ((((byte)param_1 | (byte)param_3) & 3) != 0) {

    uVar4 = FUN_1401841f0(param_3);

    uVar8 = param_3 * 0xc;

    uVar5 = (param_2 - 1) * param_3;

    puStack_450 = (undefined4 *)(uVar5 + (longlong)param_1);

    if ((uVar8 <= uVar5) &&

       (puVar10 = (undefined4 *)((uVar5 / param_3 >> 1) * param_3 + (longlong)param_1),

       puVar10 < puStack_450)) {

      lStackX_18 = 0;

      puStack_460 = auStack_430;

      puStack_468 = &uStack_438;

      do {

        if (param_3 * 0x28 < (ulonglong)((longlong)puStack_450 - (longlong)puStack_458)) {

          puVar10 = (undefined4 *)

                    FUN_140190770(puStack_458,puVar10,puStack_450,param_3,param_4,param_5);

          puVar6 = puStack_450;

          puVar7 = puStack_458;

        }

        else {

          iVar3 = (*param_4)(param_5,puStack_458,puVar10);

          if (iVar3 < 0) {

            iVar3 = (*param_4)();

            puVar7 = puVar10;

            puVar6 = puStack_450;

            uVar5 = param_3;

            if (0 < iVar3) {

              do {

                uVar1 = *(undefined1 *)puVar7;

                *(undefined1 *)puVar7 = *(undefined1 *)puVar6;

                *(undefined1 *)puVar6 = uVar1;

                uVar5 = uVar5 - 1;

                puVar7 = (undefined4 *)((longlong)puVar7 + 1);

                puVar6 = (undefined4 *)((longlong)puVar6 + 1);

              } while (uVar5 != 0);

              iVar3 = (*param_4)(param_5,puStack_458,puVar10);

              puVar7 = puStack_458;

              puVar6 = puVar10;

              uVar5 = param_3;

              if (0 < iVar3) {

                do {

                  uVar1 = *(undefined1 *)puVar7;

                  *(undefined1 *)puVar7 = *(undefined1 *)puVar6;

                  *(undefined1 *)puVar6 = uVar1;

                  uVar5 = uVar5 - 1;

                  puVar7 = (undefined4 *)((longlong)puVar7 + 1);

                  puVar6 = (undefined4 *)((longlong)puVar6 + 1);

                } while (uVar5 != 0);

              }

            }

          }

          else {

            iVar3 = (*param_4)(param_5,puVar10,puStack_450);

            puVar7 = puStack_458;

            puVar6 = puVar10;

            puVar9 = puStack_450;

            uVar5 = param_3;

            if (iVar3 < 1) {

              do {

                uVar1 = *(undefined1 *)puVar7;

                *(undefined1 *)puVar7 = *(undefined1 *)puVar6;

                *(undefined1 *)puVar6 = uVar1;

                uVar5 = uVar5 - 1;

                puVar7 = (undefined4 *)((longlong)puVar7 + 1);

                puVar6 = (undefined4 *)((longlong)puVar6 + 1);

              } while (uVar5 != 0);

              iVar3 = (*param_4)(param_5,puVar10,puStack_450);

              puVar7 = puVar10;

              puVar6 = puStack_450;

              uVar5 = param_3;

              if (0 < iVar3) {

                do {

                  uVar1 = *(undefined1 *)puVar7;

                  *(undefined1 *)puVar7 = *(undefined1 *)puVar6;

                  *(undefined1 *)puVar6 = uVar1;

                  uVar5 = uVar5 - 1;

                  puVar7 = (undefined4 *)((longlong)puVar7 + 1);

                  puVar6 = (undefined4 *)((longlong)puVar6 + 1);

                } while (uVar5 != 0);

              }

            }

            else {

              do {

                uVar1 = *(undefined1 *)puVar7;

                *(undefined1 *)puVar7 = *(undefined1 *)puVar9;

                *(undefined1 *)puVar9 = uVar1;

                uVar5 = uVar5 - 1;

                puVar7 = (undefined4 *)((longlong)puVar7 + 1);

                puVar9 = (undefined4 *)((longlong)puVar9 + 1);

              } while (uVar5 != 0);

            }

          }

          puVar7 = (undefined4 *)((longlong)puStack_458 + param_3);

          puVar6 = (undefined4 *)((longlong)puStack_450 - param_3);

        }

        FUN_1402f8e20(uVar4,puVar10,param_3);

        do {

          iVar3 = (*param_4)(param_5,puVar7,uVar4);

          while (iVar3 < 0) {

            puVar7 = (undefined4 *)((longlong)puVar7 + param_3);

            iVar3 = (*param_4)(param_5,puVar7,uVar4);

          }

          iVar3 = (*param_4)(param_5,uVar4,puVar6);

          while (iVar3 < 0) {

            puVar6 = (undefined4 *)((longlong)puVar6 - param_3);

            iVar3 = (*param_4)(param_5,uVar4,puVar6);

          }

          puVar10 = puVar7;

          puVar9 = puVar6;

          uVar5 = param_3;

          if (puVar7 < puVar6) {

            do {

              uVar1 = *(undefined1 *)puVar10;

              *(undefined1 *)puVar10 = *(undefined1 *)puVar9;

              *(undefined1 *)puVar9 = uVar1;

              uVar5 = uVar5 - 1;

              puVar10 = (undefined4 *)((longlong)puVar10 + 1);

              puVar9 = (undefined4 *)((longlong)puVar9 + 1);

            } while (uVar5 != 0);

            puVar7 = (undefined4 *)((longlong)puVar7 + param_3);

            puVar6 = (undefined4 *)((longlong)puVar6 - param_3);

          }

          else if (puVar7 == puVar6) {

            puVar7 = (undefined4 *)((longlong)puVar7 + param_3);

            puVar6 = (undefined4 *)((longlong)puVar6 - param_3);

            break;

          }

        } while (puVar7 <= puVar6);

        uVar5 = (longlong)puStack_450 - (longlong)puVar7;

        if ((ulonglong)((longlong)puVar6 - (longlong)puStack_458) < uVar8) {

          puStack_458 = puVar7;

          puVar6 = puStack_450;

          if (uVar5 < uVar8) {

            lStackX_18 = lStackX_18 + -1;

            puStack_468 = puStack_468 + -2;

            puStack_460 = puStack_460 + -2;

            if (lStackX_18 < 0) break;

            puStack_458 = (undefined4 *)*puStack_468;

            puVar6 = (undefined4 *)*puStack_460;

          }

        }

        else if (uVar5 < (ulonglong)((longlong)puVar6 - (longlong)puStack_458)) {

          if (uVar8 <= uVar5) {

            lStackX_18 = lStackX_18 + 1;

            *puStack_468 = puStack_458;

            puStack_468 = puStack_468 + 2;

            *puStack_460 = (ulonglong)puVar6;

            puStack_460 = puStack_460 + 2;

            puStack_458 = puVar7;

            puVar6 = puStack_450;

          }

        }

        else {

          lStackX_18 = lStackX_18 + 1;

          *puStack_468 = puVar7;

          puStack_468 = puStack_468 + 2;

          *puStack_460 = (ulonglong)puStack_450;

          puStack_460 = puStack_460 + 2;

        }

        puStack_450 = puVar6;

        puVar10 = (undefined4 *)

                  (((ulonglong)((longlong)puStack_450 - (longlong)puStack_458) / param_3 >> 1) *

                   param_3 + (longlong)puStack_458);

      } while (puVar10 < puStack_450);

    }

    uVar5 = param_2;

    if (0xc < param_2) {

      uVar5 = 0xc;

    }

    puVar7 = (undefined4 *)((uVar5 - 1) * param_3 + (longlong)param_1);

    puVar10 = param_1;

    if (puVar7 != param_1) {

      do {

        iVar3 = (*param_4)(param_5,puVar10,puVar7);

        puVar6 = puVar7;

        if (iVar3 < 1) {

          puVar6 = puVar10;

        }

        puVar7 = (undefined4 *)((longlong)puVar7 - param_3);

        puVar10 = puVar6;

      } while (puVar7 != param_1);

      puVar10 = param_1;

      uVar5 = param_3;

      if (puVar6 != param_1) {

        do {

          uVar1 = *(undefined1 *)puVar6;

          *(undefined1 *)puVar6 = *(undefined1 *)puVar10;

          puVar6 = (undefined4 *)((longlong)puVar6 + 1);

          *(undefined1 *)puVar10 = uVar1;

          uVar5 = uVar5 - 1;

          puVar10 = (undefined4 *)((longlong)puVar10 + 1);

        } while (uVar5 != 0);

      }

    }

    puVar7 = param_1;

    puVar10 = param_1;

    while (puVar10 = (undefined4 *)(param_3 + (longlong)puVar10), puVar6 = puVar7,

          puVar10 != (undefined4 *)(param_2 * param_3 + (longlong)param_1)) {

      while ((param_1 <= puVar6 && (iVar3 = (*param_4)(param_5,puVar6,puVar10), 0 < iVar3))) {

        puVar6 = (undefined4 *)((longlong)puVar6 - param_3);

      }

      puVar6 = (undefined4 *)((longlong)puVar6 + param_3);

      if (puVar6 != puVar10) {

        FUN_1402f8e20(uVar4,puVar10,param_3);

        FUN_1402f8e20((undefined1 *)((longlong)puVar6 + param_3),puVar6,

                      (longlong)puVar10 - (longlong)puVar6);

        FUN_1402f8e20(puVar6,uVar4,param_3);

      }

      puVar7 = (undefined4 *)((longlong)puVar7 + param_3);

    }

    FUN_1401841e0(uVar4);

    return;

  }

  if (param_3 == 4) {

    FUN_1401912e0(param_1,param_2,param_4,param_5);

    return;

  }

  uVar4 = FUN_1401841f0(param_3);

  uVar8 = param_3 * 0xc;

  uVar5 = (param_2 - 1) * param_3;

  puStack_450 = (undefined4 *)(uVar5 + (longlong)param_1);

  if ((uVar8 <= uVar5) &&

     (puVar10 = (undefined4 *)((uVar5 / param_3 >> 1) * param_3 + (longlong)param_1),

     puVar10 < puStack_450)) {

    lStackX_18 = 0;

    puStack_460 = auStack_430;

    puStack_468 = &uStack_438;

    do {

      if (param_3 * 0x28 < (ulonglong)((longlong)puStack_450 - (longlong)puStack_458)) {

        puVar10 = (undefined4 *)

                  FUN_140190770(puStack_458,puVar10,puStack_450,param_3,param_4,param_5);

        puVar6 = puStack_450;

        puVar7 = puStack_458;

      }

      else {

        iVar3 = (*param_4)(param_5,puStack_458,puVar10);

        if (iVar3 < 0) {

          iVar3 = (*param_4)();

          puVar7 = puVar10;

          puVar6 = puStack_450;

          uVar5 = param_3;

          if (0 < iVar3) {

            do {

              uVar2 = *puVar7;

              *puVar7 = *puVar6;

              *puVar6 = uVar2;

              uVar5 = uVar5 - 4;

              puVar7 = puVar7 + 1;

              puVar6 = puVar6 + 1;

            } while (uVar5 != 0);

            iVar3 = (*param_4)(param_5,puStack_458,puVar10);

            puVar7 = puStack_458;

            puVar6 = puVar10;

            uVar5 = param_3;

            if (0 < iVar3) {

              do {

                uVar2 = *puVar7;

                *puVar7 = *puVar6;

                *puVar6 = uVar2;

                uVar5 = uVar5 - 4;

                puVar7 = puVar7 + 1;

                puVar6 = puVar6 + 1;

              } while (uVar5 != 0);

            }

          }

        }

        else {

          iVar3 = (*param_4)(param_5,puVar10,puStack_450);

          puVar7 = puStack_458;

          puVar6 = puVar10;

          puVar9 = puStack_450;

          uVar5 = param_3;

          if (iVar3 < 1) {

            do {

              uVar2 = *puVar7;

              *puVar7 = *puVar6;

              *puVar6 = uVar2;

              uVar5 = uVar5 - 4;

              puVar7 = puVar7 + 1;

              puVar6 = puVar6 + 1;

            } while (uVar5 != 0);

            iVar3 = (*param_4)(param_5,puVar10,puStack_450);

            puVar7 = puVar10;

            puVar6 = puStack_450;

            uVar5 = param_3;

            if (0 < iVar3) {

              do {

                uVar2 = *puVar7;

                *puVar7 = *puVar6;

                *puVar6 = uVar2;

                uVar5 = uVar5 - 4;

                puVar7 = puVar7 + 1;

                puVar6 = puVar6 + 1;

              } while (uVar5 != 0);

            }

          }

          else {

            do {

              uVar2 = *puVar7;

              *puVar7 = *puVar9;

              *puVar9 = uVar2;

              uVar5 = uVar5 - 4;

              puVar7 = puVar7 + 1;

              puVar9 = puVar9 + 1;

            } while (uVar5 != 0);

          }

        }

        puVar7 = (undefined4 *)((longlong)puStack_458 + param_3);

        puVar6 = (undefined4 *)((longlong)puStack_450 - param_3);

      }

      FUN_1402f8e20(uVar4,puVar10,param_3);

      do {

        iVar3 = (*param_4)(param_5,puVar7,uVar4);

        while (iVar3 < 0) {

          puVar7 = (undefined4 *)((longlong)puVar7 + param_3);

          iVar3 = (*param_4)(param_5,puVar7,uVar4);

        }

        iVar3 = (*param_4)(param_5,uVar4,puVar6);

        while (iVar3 < 0) {

          puVar6 = (undefined4 *)((longlong)puVar6 - param_3);

          iVar3 = (*param_4)(param_5,uVar4,puVar6);

        }

        puVar10 = puVar7;

        puVar9 = puVar6;

        uVar5 = param_3;

        if (puVar7 < puVar6) {

          do {

            uVar2 = *puVar10;

            *puVar10 = *puVar9;

            *puVar9 = uVar2;

            uVar5 = uVar5 - 4;

            puVar10 = puVar10 + 1;

            puVar9 = puVar9 + 1;

          } while (uVar5 != 0);

          puVar7 = (undefined4 *)((longlong)puVar7 + param_3);

          puVar6 = (undefined4 *)((longlong)puVar6 - param_3);

        }

        else if (puVar7 == puVar6) {

          puVar7 = (undefined4 *)((longlong)puVar7 + param_3);

          puVar6 = (undefined4 *)((longlong)puVar6 - param_3);

          break;

        }

      } while (puVar7 <= puVar6);

      uVar5 = (longlong)puStack_450 - (longlong)puVar7;

      if ((ulonglong)((longlong)puVar6 - (longlong)puStack_458) < uVar8) {

        puStack_458 = puVar7;

        puVar6 = puStack_450;

        if (uVar5 < uVar8) {

          lStackX_18 = lStackX_18 + -1;

          puStack_468 = puStack_468 + -2;

          puStack_460 = puStack_460 + -2;

          if (lStackX_18 < 0) break;

          puStack_458 = (undefined4 *)*puStack_468;

          puVar6 = (undefined4 *)*puStack_460;

        }

      }

      else if (uVar5 < (ulonglong)((longlong)puVar6 - (longlong)puStack_458)) {

        if (uVar8 <= uVar5) {

          lStackX_18 = lStackX_18 + 1;

          *puStack_468 = puStack_458;

          puStack_468 = puStack_468 + 2;

          *puStack_460 = (ulonglong)puVar6;

          puStack_460 = puStack_460 + 2;

          puStack_458 = puVar7;

          puVar6 = puStack_450;

        }

      }

      else {

        lStackX_18 = lStackX_18 + 1;

        *puStack_468 = puVar7;

        puStack_468 = puStack_468 + 2;

        *puStack_460 = (ulonglong)puStack_450;

        puStack_460 = puStack_460 + 2;

      }

      puStack_450 = puVar6;

      puVar10 = (undefined4 *)

                (((ulonglong)((longlong)puStack_450 - (longlong)puStack_458) / param_3 >> 1) *

                 param_3 + (longlong)puStack_458);

    } while (puVar10 < puStack_450);

  }

  uVar5 = param_2;

  if (0xc < param_2) {

    uVar5 = 0xc;

  }

  puVar7 = (undefined4 *)((uVar5 - 1) * param_3 + (longlong)param_1);

  puVar10 = param_1;

  if (puVar7 != param_1) {

    do {

      iVar3 = (*param_4)(param_5,puVar10,puVar7);

      puVar6 = puVar7;

      if (iVar3 < 1) {

        puVar6 = puVar10;

      }

      puVar7 = (undefined4 *)((longlong)puVar7 - param_3);

      puVar10 = puVar6;

    } while (puVar7 != param_1);

    puVar10 = param_1;

    uVar5 = param_3;

    if (puVar6 != param_1) {

      do {

        uVar2 = *puVar6;

        *puVar6 = *puVar10;

        *puVar10 = uVar2;

        uVar5 = uVar5 - 4;

        puVar10 = puVar10 + 1;

        puVar6 = puVar6 + 1;

      } while (uVar5 != 0);

    }

  }

  puVar7 = param_1;

  puVar10 = param_1;

  while (puVar10 = (undefined4 *)(param_3 + (longlong)puVar10), puVar6 = puVar7,

        puVar10 != (undefined4 *)(param_2 * param_3 + (longlong)param_1)) {

    while ((param_1 <= puVar6 && (iVar3 = (*param_4)(param_5,puVar6,puVar10), 0 < iVar3))) {

      puVar6 = (undefined4 *)((longlong)puVar6 - param_3);

    }

    puVar6 = (undefined4 *)((longlong)puVar6 + param_3);

    if (puVar6 != puVar10) {

      FUN_1402f8e20(uVar4,puVar10,param_3);

      FUN_1402f8e20((undefined1 *)((longlong)puVar6 + param_3),puVar6,

                    (longlong)puVar10 - (longlong)puVar6);

      FUN_1402f8e20(puVar6,uVar4,param_3);

    }

    puVar7 = (undefined4 *)((longlong)puVar7 + param_3);

  }

  FUN_1401841e0(uVar4);

  return;

}




