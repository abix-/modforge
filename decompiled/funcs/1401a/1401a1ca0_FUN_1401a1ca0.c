// Address: 0x1401a1ca0
// Ghidra name: FUN_1401a1ca0
// ============ 0x1401a1ca0 FUN_1401a1ca0 (size=1603) ============


undefined8 FUN_1401a1ca0(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  longlong lVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  int local_res10;

  undefined1 local_b8 [128];

  

  lVar7 = param_1;

  FUN_1401a1660();

  if (*(int *)(lVar7 + 0x4830) == 0) {

    if (*(int *)(lVar7 + 0x4854) == 1) {

      iVar9 = *(int *)(lVar7 + 0x4858);

      iVar11 = 0;

      lVar7 = (longlong)iVar9 * 0x60 + lVar7;

      iVar10 = *(int *)(lVar7 + 0x46bc) + 7 >> 3;

      iVar8 = *(int *)(lVar7 + 0x46c0) + 7 >> 3;

      if (0 < iVar8) {

        do {

          iVar5 = 0;

          if (0 < iVar10) {

            iVar6 = 0;

            do {

              iVar2 = FUN_1401a0500(param_1,local_b8,

                                    (longlong)*(int *)(lVar7 + 0x46b0) * 0x690 + 8 + param_1,

                                    (longlong)*(int *)(lVar7 + 0x46b4) * 0x690 + 0x1a48 + param_1,

                                    (longlong)*(int *)(lVar7 + 0x46b4) * 0x400 + 0x3688 + param_1,

                                    iVar9,(longlong)*(int *)(lVar7 + 0x46ac) * 0x80 + 0x3488 +

                                          param_1);

              if (iVar2 == 0) {

                return 0;

              }

              (**(code **)(param_1 + 0x4870))

                        ((longlong)(*(int *)(lVar7 + 0x46c4) * iVar11 * 8) +

                         *(longlong *)(lVar7 + 0x46d0) + (longlong)iVar6,*(int *)(lVar7 + 0x46c4),

                         local_b8);

              *(int *)(param_1 + 0x486c) = *(int *)(param_1 + 0x486c) + -1;

              if (*(int *)(param_1 + 0x486c) < 1) {

                if (*(int *)(param_1 + 0x4824) < 0x18) {

                  FUN_14019f510(param_1);

                }

                if (7 < (byte)(*(char *)(param_1 + 0x4828) + 0x30U)) {

                  return 1;

                }

                FUN_1401a1660(param_1);

              }

              iVar5 = iVar5 + 1;

              iVar6 = iVar6 + 8;

            } while (iVar5 < iVar10);

          }

          iVar11 = iVar11 + 1;

        } while (iVar11 < iVar8);

      }

    }

    else {

      local_res10 = 0;

      if (0 < *(int *)(lVar7 + 0x4694)) {

        do {

          iVar9 = 0;

          if (0 < *(int *)(param_1 + 0x4690)) {

            do {

              iVar8 = 0;

              if (0 < *(int *)(param_1 + 0x4854)) {

                piVar4 = (int *)(param_1 + 0x4858);

                do {

                  iVar10 = *piVar4;

                  iVar11 = 0;

                  lVar7 = (longlong)iVar10 * 0x60 + param_1;

                  if (0 < *(int *)(lVar7 + 0x46a8)) {

                    do {

                      iVar5 = *(int *)(lVar7 + 0x46a4);

                      iVar6 = 0;

                      if (0 < iVar5) {

                        do {

                          iVar2 = *(int *)(lVar7 + 0x46a8);

                          iVar3 = FUN_1401a0500(param_1,local_b8,

                                                (longlong)*(int *)(lVar7 + 0x46b0) * 0x690 + 8 +

                                                param_1,(longlong)*(int *)(lVar7 + 0x46b4) * 0x690 +

                                                        0x1a48 + param_1,

                                                (longlong)*(int *)(lVar7 + 0x46b4) * 0x400 + 0x3688

                                                + param_1,iVar10,

                                                (longlong)*(int *)(lVar7 + 0x46ac) * 0x80 + 0x3488 +

                                                param_1);

                          if (iVar3 == 0) {

                            return 0;

                          }

                          (**(code **)(param_1 + 0x4870))

                                    ((longlong)((iVar5 * iVar9 + iVar6) * 8) +

                                     (longlong)

                                     ((local_res10 * iVar2 + iVar11) * *(int *)(lVar7 + 0x46c4) * 8)

                                     + *(longlong *)(lVar7 + 0x46d0),*(int *)(lVar7 + 0x46c4),

                                     local_b8);

                          iVar5 = *(int *)(lVar7 + 0x46a4);

                          iVar6 = iVar6 + 1;

                        } while (iVar6 < iVar5);

                      }

                      iVar11 = iVar11 + 1;

                    } while (iVar11 < *(int *)(lVar7 + 0x46a8));

                  }

                  iVar8 = iVar8 + 1;

                  piVar4 = piVar4 + 1;

                } while (iVar8 < *(int *)(param_1 + 0x4854));

              }

              *(int *)(param_1 + 0x486c) = *(int *)(param_1 + 0x486c) + -1;

              if (*(int *)(param_1 + 0x486c) < 1) {

                if (*(int *)(param_1 + 0x4824) < 0x18) {

                  FUN_14019f510(param_1);

                }

                if (7 < (byte)(*(char *)(param_1 + 0x4828) + 0x30U)) {

                  return 1;

                }

                FUN_1401a1660(param_1);

              }

              iVar9 = iVar9 + 1;

            } while (iVar9 < *(int *)(param_1 + 0x4690));

          }

          local_res10 = local_res10 + 1;

        } while (local_res10 < *(int *)(param_1 + 0x4694));

      }

    }

  }

  else if (*(int *)(lVar7 + 0x4854) == 1) {

    iVar9 = *(int *)(lVar7 + 0x4858);

    iVar8 = 0;

    lVar7 = (longlong)iVar9 * 0x60 + param_1;

    iVar11 = *(int *)(lVar7 + 0x46bc) + 7 >> 3;

    iVar10 = *(int *)(lVar7 + 0x46c0) + 7 >> 3;

    if (0 < iVar10) {

      do {

        iVar5 = 0;

        if (0 < iVar11) {

          do {

            lVar1 = *(longlong *)(lVar7 + 0x46f0) +

                    (longlong)((iVar8 * *(int *)(lVar7 + 0x46f8) + iVar5) * 0x40) * 2;

            if (*(int *)(param_1 + 0x4834) == 0) {

              iVar6 = FUN_1401a1110(param_1,lVar1,

                                    (longlong)*(int *)(lVar7 + 0x46b0) * 0x690 + 8 + param_1,iVar9);

            }

            else {

              iVar6 = FUN_1401a0a00(param_1,lVar1,

                                    (longlong)*(int *)(lVar7 + 0x46b4) * 0x690 + 0x1a48 + param_1,

                                    (longlong)*(int *)(lVar7 + 0x46b4) * 0x400 + 0x3688 + param_1);

            }

            if (iVar6 == 0) {

              return 0;

            }

            *(int *)(param_1 + 0x486c) = *(int *)(param_1 + 0x486c) + -1;

            if (*(int *)(param_1 + 0x486c) < 1) {

              if (*(int *)(param_1 + 0x4824) < 0x18) {

                FUN_14019f510(param_1);

              }

              if (7 < (byte)(*(char *)(param_1 + 0x4828) + 0x30U)) {

                return 1;

              }

              FUN_1401a1660(param_1);

            }

            iVar5 = iVar5 + 1;

          } while (iVar5 < iVar11);

        }

        iVar8 = iVar8 + 1;

      } while (iVar8 < iVar10);

    }

  }

  else {

    iVar9 = 0;

    if (0 < *(int *)(lVar7 + 0x4694)) {

      do {

        iVar8 = 0;

        if (0 < *(int *)(param_1 + 0x4690)) {

          do {

            iVar10 = 0;

            if (0 < *(int *)(param_1 + 0x4854)) {

              piVar4 = (int *)(param_1 + 0x4858);

              do {

                iVar11 = *piVar4;

                iVar5 = 0;

                lVar7 = (longlong)iVar11 * 0x60 + param_1;

                if (0 < *(int *)(lVar7 + 0x46a8)) {

                  do {

                    iVar6 = *(int *)(lVar7 + 0x46a4);

                    iVar2 = 0;

                    if (0 < iVar6) {

                      do {

                        iVar6 = FUN_1401a1110(param_1,*(longlong *)(lVar7 + 0x46f0) +

                                                      (longlong)

                                                      ((iVar6 * iVar8 +

                                                       (iVar9 * *(int *)(lVar7 + 0x46a8) + iVar5) *

                                                       *(int *)(lVar7 + 0x46f8) + iVar2) * 0x40) * 2

                                              ,(longlong)*(int *)(lVar7 + 0x46b0) * 0x690 + 8 +

                                               param_1,iVar11);

                        if (iVar6 == 0) {

                          return 0;

                        }

                        iVar6 = *(int *)(lVar7 + 0x46a4);

                        iVar2 = iVar2 + 1;

                      } while (iVar2 < iVar6);

                    }

                    iVar5 = iVar5 + 1;

                  } while (iVar5 < *(int *)(lVar7 + 0x46a8));

                }

                iVar10 = iVar10 + 1;

                piVar4 = piVar4 + 1;

              } while (iVar10 < *(int *)(param_1 + 0x4854));

            }

            *(int *)(param_1 + 0x486c) = *(int *)(param_1 + 0x486c) + -1;

            if (*(int *)(param_1 + 0x486c) < 1) {

              if (*(int *)(param_1 + 0x4824) < 0x18) {

                FUN_14019f510(param_1);

              }

              if (7 < (byte)(*(char *)(param_1 + 0x4828) + 0x30U)) {

                return 1;

              }

              FUN_1401a1660(param_1);

            }

            iVar8 = iVar8 + 1;

          } while (iVar8 < *(int *)(param_1 + 0x4690));

        }

        iVar9 = iVar9 + 1;

      } while (iVar9 < *(int *)(param_1 + 0x4694));

    }

  }

  return 1;

}




