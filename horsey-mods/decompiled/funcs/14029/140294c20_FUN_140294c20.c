// Address: 0x140294c20
// Ghidra name: FUN_140294c20
// ============ 0x140294c20 FUN_140294c20 (size=838) ============


void FUN_140294c20(longlong param_1)



{

  undefined1 *puVar1;

  byte *pbVar2;

  byte *pbVar3;

  undefined1 *puVar4;

  byte bVar5;

  undefined1 uVar6;

  undefined1 uVar7;

  undefined1 uVar8;

  uint uVar9;

  int iVar10;

  longlong lVar11;

  uint uVar12;

  uint uVar13;

  int iVar14;

  undefined1 *puVar15;

  uint *puVar16;

  int iVar17;

  ulonglong uVar18;

  longlong lVar19;

  

  uVar9 = *(uint *)(param_1 + 0x38);

  iVar14 = *(int *)(param_1 + 0x3c);

  puVar15 = *(undefined1 **)(param_1 + 8);

  iVar10 = *(int *)(param_1 + 0x1c);

  lVar11 = *(longlong *)(param_1 + 0x58);

  puVar16 = *(uint **)(param_1 + 0x30);

  lVar19 = (longlong)*(int *)(param_1 + 0x44);

  uVar18 = (ulonglong)*(byte *)(lVar11 + 5);

  bVar5 = *(byte *)(*(longlong *)(param_1 + 0x48) + 5);

  if (*(int *)(lVar11 + 0x14) == 0) {

    while (iVar14 != 0) {

      iVar17 = (int)(((int)(uVar9 + 3) >> 0x1f & 3U) + uVar9 + 3) >> 2;

      uVar12 = uVar9 & 3;

      if (uVar12 == 0) goto LAB_140294ec7;

      if (uVar12 == 1) goto LAB_140294f24;

      if (uVar12 == 2) goto LAB_140294f05;

      if (uVar12 == 3) {

        while( true ) {

          uVar6 = puVar15[1];

          uVar7 = puVar15[2];

          *(undefined1 *)((longlong)puVar16 + 2) = *puVar15;

          *(undefined1 *)((longlong)puVar16 + 1) = uVar6;

          *(undefined1 *)puVar16 = uVar7;

          puVar16 = (uint *)((longlong)puVar16 + uVar18);

          puVar15 = puVar15 + bVar5;

LAB_140294f05:

          uVar6 = puVar15[1];

          uVar7 = puVar15[2];

          *(undefined1 *)((longlong)puVar16 + 2) = *puVar15;

          *(undefined1 *)((longlong)puVar16 + 1) = uVar6;

          *(undefined1 *)puVar16 = uVar7;

          puVar16 = (uint *)((longlong)puVar16 + uVar18);

          puVar15 = puVar15 + bVar5;

LAB_140294f24:

          uVar6 = *puVar15;

          iVar17 = iVar17 + -1;

          uVar7 = puVar15[1];

          uVar8 = puVar15[2];

          puVar15 = puVar15 + bVar5;

          *(undefined1 *)((longlong)puVar16 + 2) = uVar6;

          *(undefined1 *)((longlong)puVar16 + 1) = uVar7;

          *(undefined1 *)puVar16 = uVar8;

          puVar16 = (uint *)((longlong)puVar16 + uVar18);

          if (iVar17 < 1) break;

LAB_140294ec7:

          uVar6 = puVar15[1];

          uVar7 = puVar15[2];

          *(undefined1 *)((longlong)puVar16 + 2) = *puVar15;

          *(undefined1 *)((longlong)puVar16 + 1) = uVar6;

          *(undefined1 *)puVar16 = uVar7;

          puVar16 = (uint *)((longlong)puVar16 + uVar18);

          puVar15 = puVar15 + bVar5;

        }

        puVar15 = puVar15 + iVar10;

        puVar16 = (uint *)((longlong)puVar16 + lVar19);

        iVar14 = iVar14 + -1;

      }

      else {

        puVar15 = puVar15 + iVar10;

        puVar16 = (uint *)((longlong)puVar16 + lVar19);

        iVar14 = iVar14 + -1;

      }

    }

  }

  else if (*(int *)(*(longlong *)(param_1 + 0x48) + 0x14) == 0) {

    uVar12 = (uint)*(byte *)(param_1 + 0x83) << (*(byte *)(lVar11 + 0x1f) & 0x1f);

    while (iVar14 != 0) {

      iVar17 = (int)(((int)(uVar9 + 3) >> 0x1f & 3U) + uVar9 + 3) >> 2;

      uVar13 = uVar9 & 3;

      if (uVar13 == 0) goto LAB_140294dde;

      if (uVar13 == 1) goto LAB_140294e4d;

      if (uVar13 == 2) goto LAB_140294e28;

      if (uVar13 == 3) {

        while( true ) {

          *puVar16 = CONCAT21(CONCAT11(*puVar15,puVar15[1]),puVar15[2]) | uVar12;

          puVar16 = puVar16 + 1;

          puVar15 = puVar15 + bVar5;

LAB_140294e28:

          *puVar16 = CONCAT21(CONCAT11(*puVar15,puVar15[1]),puVar15[2]) | uVar12;

          puVar16 = puVar16 + 1;

          puVar15 = puVar15 + bVar5;

LAB_140294e4d:

          puVar1 = puVar15 + 1;

          iVar17 = iVar17 + -1;

          uVar6 = *puVar15;

          puVar4 = puVar15 + 2;

          puVar15 = puVar15 + bVar5;

          *puVar16 = CONCAT21(CONCAT11(uVar6,*puVar1),*puVar4) | uVar12;

          puVar16 = puVar16 + 1;

          if (iVar17 < 1) break;

LAB_140294dde:

          *puVar16 = CONCAT21(CONCAT11(*puVar15,puVar15[1]),puVar15[2]) | uVar12;

          puVar16 = puVar16 + 1;

          puVar15 = puVar15 + bVar5;

        }

        puVar15 = puVar15 + iVar10;

        puVar16 = (uint *)((longlong)puVar16 + lVar19);

        iVar14 = iVar14 + -1;

      }

      else {

        puVar15 = puVar15 + iVar10;

        puVar16 = (uint *)((longlong)puVar16 + lVar19);

        iVar14 = iVar14 + -1;

      }

    }

  }

  else {

    while (iVar14 != 0) {

      iVar17 = (int)(((int)(uVar9 + 3) >> 0x1f & 3U) + uVar9 + 3) >> 2;

      uVar12 = uVar9 & 3;

      if (uVar12 == 0) goto LAB_140294cbd;

      if (uVar12 == 1) goto LAB_140294d4d;

      if (uVar12 == 2) goto LAB_140294d1d;

      if (uVar12 == 3) {

        while( true ) {

          *puVar16 = (uint)CONCAT11(*puVar15,puVar15[1]) << 8 |

                     (uint)(byte)puVar15[3] << (*(byte *)(lVar11 + 0x1f) & 0x1f) |

                     (uint)(byte)puVar15[2];

          puVar16 = puVar16 + 1;

          puVar15 = puVar15 + 4;

LAB_140294d1d:

          *puVar16 = (uint)CONCAT11(*puVar15,puVar15[1]) << 8 |

                     (uint)(byte)puVar15[3] << (*(byte *)(lVar11 + 0x1f) & 0x1f) |

                     (uint)(byte)puVar15[2];

          puVar16 = puVar16 + 1;

          puVar15 = puVar15 + 4;

LAB_140294d4d:

          puVar1 = puVar15 + 1;

          iVar17 = iVar17 + -1;

          uVar6 = *puVar15;

          pbVar2 = puVar15 + 3;

          pbVar3 = puVar15 + 2;

          puVar15 = puVar15 + 4;

          *puVar16 = (uint)CONCAT11(uVar6,*puVar1) << 8 |

                     (uint)*pbVar2 << (*(byte *)(lVar11 + 0x1f) & 0x1f) | (uint)*pbVar3;

          puVar16 = puVar16 + 1;

          if (iVar17 < 1) break;

LAB_140294cbd:

          *puVar16 = (uint)CONCAT11(*puVar15,puVar15[1]) << 8 |

                     (uint)(byte)puVar15[3] << (*(byte *)(lVar11 + 0x1f) & 0x1f) |

                     (uint)(byte)puVar15[2];

          puVar16 = puVar16 + 1;

          puVar15 = puVar15 + 4;

        }

        puVar15 = puVar15 + iVar10;

        puVar16 = (uint *)((longlong)puVar16 + lVar19);

        iVar14 = iVar14 + -1;

      }

      else {

        puVar15 = puVar15 + iVar10;

        puVar16 = (uint *)((longlong)puVar16 + lVar19);

        iVar14 = iVar14 + -1;

      }

    }

  }

  return;

}




