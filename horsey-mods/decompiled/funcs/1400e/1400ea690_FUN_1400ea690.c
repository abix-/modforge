// Address: 0x1400ea690
// Ghidra name: FUN_1400ea690
// ============ 0x1400ea690 FUN_1400ea690 (size=1075) ============


undefined8 FUN_1400ea690(longlong param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  longlong lVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int local_res8;

  int local_res10;

  undefined1 local_b8 [128];

  

  *(undefined4 *)(param_1 + 0x3648) = 0;

  *(undefined4 *)(param_1 + 0x3600) = 0;

  *(undefined4 *)(param_1 + 0x35b8) = 0;

  *(undefined8 *)(param_1 + 0x36c0) = 0;

  *(undefined4 *)(param_1 + 0x36cc) = 0;

  *(undefined1 *)(param_1 + 0x36c8) = 0xff;

  iVar7 = 0x7fffffff;

  if (*(int *)(param_1 + 0x36e4) != 0) {

    iVar7 = *(int *)(param_1 + 0x36e4);

  }

  *(int *)(param_1 + 0x36e8) = iVar7;

  if (*(int *)(param_1 + 0x36d0) == 1) {

    iVar7 = *(int *)(param_1 + 0x36d4);

    iVar9 = 0;

    lVar5 = param_1 + (longlong)iVar7 * 0x48;

    iVar8 = *(int *)(lVar5 + 0x35bc) + 7 >> 3;

    iVar6 = *(int *)(lVar5 + 0x35c0) + 7 >> 3;

    if (0 < iVar6) {

      do {

        iVar4 = 0;

        if (0 < iVar8) {

          iVar3 = 0;

          do {

            iVar1 = FUN_1400e83f0(param_1,local_b8,

                                  (longlong)*(int *)(lVar5 + 0x35b0) * 0x690 + 8 + param_1,

                                  (longlong)*(int *)(lVar5 + 0x35b4) * 0x690 + 0x1a48 + param_1,

                                  iVar7);

            if (iVar1 == 0) {

              return 0;

            }

            FUN_1400e9a60((longlong)(*(int *)(lVar5 + 0x35c4) * iVar9 * 8) +

                          *(longlong *)(lVar5 + 0x35d0) + (longlong)iVar3,*(int *)(lVar5 + 0x35c4),

                          local_b8,(longlong)*(int *)(lVar5 + 0x35ac) * 0x40 + 0x3488 + param_1);

            *(int *)(param_1 + 0x36e8) = *(int *)(param_1 + 0x36e8) + -1;

            if (*(int *)(param_1 + 0x36e8) < 1) {

              if (*(int *)(param_1 + 0x36c4) < 0x18) {

                FUN_1400e8fa0(param_1);

              }

              if (7 < (byte)(*(char *)(param_1 + 0x36c8) + 0x30U)) {

                return 1;

              }

              *(undefined4 *)(param_1 + 0x3648) = 0;

              *(undefined4 *)(param_1 + 0x3600) = 0;

              *(undefined4 *)(param_1 + 0x35b8) = 0;

              *(undefined8 *)(param_1 + 0x36c0) = 0;

              iVar1 = 0x7fffffff;

              if (*(int *)(param_1 + 0x36e4) != 0) {

                iVar1 = *(int *)(param_1 + 0x36e4);

              }

              *(undefined4 *)(param_1 + 0x36cc) = 0;

              *(int *)(param_1 + 0x36e8) = iVar1;

              *(undefined1 *)(param_1 + 0x36c8) = 0xff;

            }

            iVar4 = iVar4 + 1;

            iVar3 = iVar3 + 8;

          } while (iVar4 < iVar8);

        }

        iVar9 = iVar9 + 1;

      } while (iVar9 < iVar6);

    }

  }

  else {

    iVar7 = 0;

    if (0 < *(int *)(param_1 + 0x3594)) {

      do {

        local_res8 = 0;

        if (0 < *(int *)(param_1 + 0x3590)) {

          do {

            local_res10 = 0;

            if (0 < *(int *)(param_1 + 0x36d0)) {

              piVar2 = (int *)(param_1 + 0x36d4);

              do {

                iVar6 = *piVar2;

                lVar5 = (longlong)iVar6;

                iVar8 = 0;

                if (0 < *(int *)(param_1 + 0x35a8 + lVar5 * 0x48)) {

                  do {

                    iVar9 = *(int *)(param_1 + 0x35a4 + lVar5 * 0x48);

                    iVar4 = 0;

                    if (0 < iVar9) {

                      do {

                        iVar3 = *(int *)(param_1 + 0x35a8 + lVar5 * 0x48);

                        iVar1 = FUN_1400e83f0(param_1,local_b8,

                                              (longlong)*(int *)(param_1 + 0x35b0 + lVar5 * 0x48) *

                                              0x690 + 8 + param_1,

                                              (longlong)*(int *)(param_1 + 0x35b4 + lVar5 * 0x48) *

                                              0x690 + 0x1a48 + param_1,iVar6);

                        if (iVar1 == 0) {

                          return 0;

                        }

                        iVar1 = *(int *)(param_1 + 0x35c4 + lVar5 * 0x48);

                        FUN_1400e9a60((longlong)((iVar9 * local_res8 + iVar4) * 8) +

                                      (longlong)(iVar1 * (iVar7 * iVar3 + iVar8) * 8) +

                                      *(longlong *)(param_1 + 0x35d0 + lVar5 * 0x48),iVar1,local_b8,

                                      (longlong)*(int *)(param_1 + 0x35ac + lVar5 * 0x48) * 0x40 +

                                      0x3488 + param_1);

                        iVar9 = *(int *)(param_1 + 0x35a4 + lVar5 * 0x48);

                        iVar4 = iVar4 + 1;

                      } while (iVar4 < iVar9);

                    }

                    iVar8 = iVar8 + 1;

                  } while (iVar8 < *(int *)(param_1 + 0x35a8 + lVar5 * 0x48));

                }

                local_res10 = local_res10 + 1;

                piVar2 = piVar2 + 1;

              } while (local_res10 < *(int *)(param_1 + 0x36d0));

            }

            *(int *)(param_1 + 0x36e8) = *(int *)(param_1 + 0x36e8) + -1;

            if (*(int *)(param_1 + 0x36e8) < 1) {

              if (*(int *)(param_1 + 0x36c4) < 0x18) {

                FUN_1400e8fa0(param_1);

              }

              if (7 < (byte)(*(char *)(param_1 + 0x36c8) + 0x30U)) {

                return 1;

              }

              *(undefined4 *)(param_1 + 0x3648) = 0;

              *(undefined4 *)(param_1 + 0x3600) = 0;

              *(undefined4 *)(param_1 + 0x35b8) = 0;

              *(undefined8 *)(param_1 + 0x36c0) = 0;

              iVar6 = 0x7fffffff;

              if (*(int *)(param_1 + 0x36e4) != 0) {

                iVar6 = *(int *)(param_1 + 0x36e4);

              }

              *(undefined4 *)(param_1 + 0x36cc) = 0;

              *(int *)(param_1 + 0x36e8) = iVar6;

              *(undefined1 *)(param_1 + 0x36c8) = 0xff;

            }

            local_res8 = local_res8 + 1;

          } while (local_res8 < *(int *)(param_1 + 0x3590));

        }

        iVar7 = iVar7 + 1;

      } while (iVar7 < *(int *)(param_1 + 0x3594));

    }

  }

  return 1;

}




