// Address: 0x1402e1190
// Ghidra name: FUN_1402e1190
// ============ 0x1402e1190 FUN_1402e1190 (size=762) ============


/* WARNING: Removing unreachable block (ram,0x0001402e142c) */

/* WARNING: Removing unreachable block (ram,0x0001402e1425) */

/* WARNING: Removing unreachable block (ram,0x0001402e141e) */

/* WARNING: Removing unreachable block (ram,0x0001402e1417) */

/* WARNING: Removing unreachable block (ram,0x0001402e1410) */

/* WARNING: Removing unreachable block (ram,0x0001402e1409) */

/* WARNING: Removing unreachable block (ram,0x0001402e1402) */

/* WARNING: Removing unreachable block (ram,0x0001402e13fb) */

/* WARNING: Removing unreachable block (ram,0x0001402e13f4) */

/* WARNING: Removing unreachable block (ram,0x0001402e13ed) */

/* WARNING: Removing unreachable block (ram,0x0001402e13e6) */

/* WARNING: Removing unreachable block (ram,0x0001402e13df) */

/* WARNING: Removing unreachable block (ram,0x0001402e13d8) */

/* WARNING: Removing unreachable block (ram,0x0001402e13d1) */

/* WARNING: Removing unreachable block (ram,0x0001402e13ca) */

/* WARNING: Removing unreachable block (ram,0x0001402e128d) */

/* WARNING: Removing unreachable block (ram,0x0001402e129c) */

/* WARNING: Removing unreachable block (ram,0x0001402e12ab) */

/* WARNING: Removing unreachable block (ram,0x0001402e12ba) */

/* WARNING: Removing unreachable block (ram,0x0001402e12c9) */

/* WARNING: Removing unreachable block (ram,0x0001402e12d5) */

/* WARNING: Removing unreachable block (ram,0x0001402e12e1) */

/* WARNING: Removing unreachable block (ram,0x0001402e12ed) */

/* WARNING: Removing unreachable block (ram,0x0001402e12f9) */

/* WARNING: Removing unreachable block (ram,0x0001402e1305) */

/* WARNING: Removing unreachable block (ram,0x0001402e1311) */

/* WARNING: Removing unreachable block (ram,0x0001402e131d) */

/* WARNING: Removing unreachable block (ram,0x0001402e1329) */

/* WARNING: Removing unreachable block (ram,0x0001402e1335) */

/* WARNING: Removing unreachable block (ram,0x0001402e1341) */



char * FUN_1402e1190(char *param_1,longlong param_2)



{

  char cVar1;

  uint uVar2;

  ushort uVar3;

  undefined1 auVar4 [16];

  undefined1 auVar5 [16];

  undefined1 auVar6 [16];

  undefined1 auVar7 [16];

  undefined1 auVar8 [16];

  undefined1 auVar9 [16];

  undefined1 auVar10 [16];

  undefined1 auVar11 [16];

  undefined1 auVar12 [16];

  undefined1 auVar13 [16];

  undefined1 auVar14 [16];

  undefined1 auVar15 [16];

  undefined1 auVar16 [16];

  undefined1 auVar17 [16];

  undefined1 auVar18 [16];

  char *pcVar19;

  undefined1 (*pauVar20) [16];

  ulonglong uVar21;

  undefined1 auVar22 [16];

  undefined1 auVar23 [16];

  undefined1 auVar24 [16];

  undefined1 auVar26 [16];

  undefined1 auVar27 [16];

  undefined1 auVar28 [16];

  undefined1 auVar29 [16];

  undefined1 auVar30 [16];

  undefined1 auVar31 [16];

  undefined1 auVar32 [16];

  undefined1 auVar33 [16];

  ulonglong uVar34;

  undefined1 auVar35 [16];

  longlong lVar25;

  

  uVar21 = (ulonglong)((uint)param_2 & 0xf);

  pauVar20 = (undefined1 (*) [16])(param_2 - uVar21);

  auVar33 = *pauVar20;

  switch(uVar21) {

  case 1:

    auVar33 = auVar33 >> 8;

    break;

  case 2:

    auVar33 = auVar33 >> 0x10;

    break;

  case 3:

    auVar33 = auVar33 >> 0x18;

    break;

  case 4:

    auVar33 = auVar33 >> 0x20;

    break;

  case 5:

    auVar33 = auVar33 >> 0x28;

    break;

  case 6:

    auVar33 = auVar33 >> 0x30;

    break;

  case 7:

    auVar33 = auVar33 >> 0x38;

    break;

  case 8:

    auVar33 = auVar33 >> 0x40;

    break;

  case 9:

    auVar33 = auVar33 >> 0x48;

    break;

  case 10:

    auVar33 = auVar33 >> 0x50;

    break;

  case 0xb:

    auVar33 = auVar33 >> 0x58;

    break;

  case 0xc:

    auVar33 = auVar33 >> 0x60;

    break;

  case 0xd:

    auVar33 = auVar33 >> 0x68;

    break;

  case 0xe:

    auVar33 = auVar33 >> 0x70;

    break;

  case 0xf:

    auVar33 = auVar33 >> 0x78;

  }

  auVar22[0] = -(auVar33[0] == '\0');

  auVar22[1] = -(auVar33[1] == '\0');

  auVar22[2] = -(auVar33[2] == '\0');

  auVar22[3] = -(auVar33[3] == '\0');

  auVar22[4] = -(auVar33[4] == '\0');

  auVar22[5] = -(auVar33[5] == '\0');

  auVar22[6] = -(auVar33[6] == '\0');

  auVar22[7] = -(auVar33[7] == '\0');

  auVar22[8] = -(auVar33[8] == '\0');

  auVar22[9] = -(auVar33[9] == '\0');

  auVar22[10] = -(auVar33[10] == '\0');

  auVar22[0xb] = -(auVar33[0xb] == '\0');

  auVar22[0xc] = -(auVar33[0xc] == '\0');

  auVar22[0xd] = -(auVar33[0xd] == '\0');

  auVar22[0xe] = -(auVar33[0xe] == '\0');

  auVar22[0xf] = -(auVar33[0xf] == '\0');

  uVar3 = (ushort)(SUB161(auVar22 >> 7,0) & 1) | (ushort)(SUB161(auVar22 >> 0xf,0) & 1) << 1 |

          (ushort)(SUB161(auVar22 >> 0x17,0) & 1) << 2 |

          (ushort)(SUB161(auVar22 >> 0x1f,0) & 1) << 3 |

          (ushort)(SUB161(auVar22 >> 0x27,0) & 1) << 4 |

          (ushort)(SUB161(auVar22 >> 0x2f,0) & 1) << 5 |

          (ushort)(SUB161(auVar22 >> 0x37,0) & 1) << 6 |

          (ushort)(SUB161(auVar22 >> 0x3f,0) & 1) << 7 |

          (ushort)(SUB161(auVar22 >> 0x47,0) & 1) << 8 |

          (ushort)(SUB161(auVar22 >> 0x4f,0) & 1) << 9 |

          (ushort)(SUB161(auVar22 >> 0x57,0) & 1) << 10 |

          (ushort)(SUB161(auVar22 >> 0x5f,0) & 1) << 0xb |

          (ushort)(SUB161(auVar22 >> 0x67,0) & 1) << 0xc |

          (ushort)(SUB161(auVar22 >> 0x6f,0) & 1) << 0xd |

          (ushort)(SUB161(auVar22 >> 0x77,0) & 1) << 0xe | (ushort)(auVar22[0xf] >> 7) << 0xf;

  if (uVar3 == 0) {

    if (uVar21 == 0) {

      if ((*pauVar20)[1] != '\0') {

        pcVar19 = (char *)FUN_1402e10f0();

        return pcVar19;

      }

      goto LAB_1402e1439;

    }

  }

  else {

    uVar2 = 0;

    if (uVar3 != 0) {

      for (; (uVar3 >> uVar2 & 1) == 0; uVar2 = uVar2 + 1) {

      }

    }

    lVar25 = auVar33._8_8_;

    switch(-uVar2) {

    case 0:

      auVar33 = ZEXT816(0);

      break;

    case 0xfffffff1:

      auVar26._0_8_ = auVar33._0_8_ << 8;

      auVar26._8_8_ = lVar25 << 8 | auVar33._0_8_ >> 0x38;

      auVar33 = auVar26 >> 8;

      break;

    case 0xfffffff2:

      auVar27._0_8_ = auVar33._0_8_ << 0x10;

      auVar27._8_8_ = lVar25 << 0x10 | auVar33._0_8_ >> 0x30;

      auVar33 = auVar27 >> 0x10;

      break;

    case 0xfffffff3:

      auVar28._0_8_ = auVar33._0_8_ << 0x18;

      auVar28._8_8_ = lVar25 << 0x18 | auVar33._0_8_ >> 0x28;

      auVar33 = auVar28 >> 0x18;

      break;

    case 0xfffffff4:

      auVar29._0_8_ = auVar33._0_8_ << 0x20;

      auVar29._8_8_ = lVar25 << 0x20 | auVar33._0_8_ >> 0x20;

      auVar33 = auVar29 >> 0x20;

      break;

    case 0xfffffff5:

      auVar30._0_8_ = auVar33._0_8_ << 0x28;

      auVar30._8_8_ = lVar25 << 0x28 | auVar33._0_8_ >> 0x18;

      auVar33 = auVar30 >> 0x28;

      break;

    case 0xfffffff6:

      auVar31._0_8_ = auVar33._0_8_ << 0x30;

      auVar31._8_8_ = lVar25 << 0x30 | auVar33._0_8_ >> 0x10;

      auVar33 = auVar31 >> 0x30;

      break;

    case 0xfffffff7:

      auVar32._0_8_ = auVar33._0_8_ << 0x38;

      auVar32._8_8_ = lVar25 << 0x38 | auVar33._0_8_ >> 8;

      auVar33 = auVar32 >> 0x38;

      break;

    case 0xfffffff8:

      auVar33._8_8_ = 0;

      break;

    case 0xfffffff9:

      auVar4._8_8_ = 0;

      auVar4._0_8_ = auVar33._0_8_ << 8;

      auVar33 = (auVar4 << 0x40) >> 0x48;

      break;

    case 0xfffffffa:

      auVar5._8_8_ = 0;

      auVar5._0_8_ = auVar33._0_8_ << 0x10;

      auVar33 = (auVar5 << 0x40) >> 0x50;

      break;

    case 0xfffffffb:

      auVar6._8_8_ = 0;

      auVar6._0_8_ = auVar33._0_8_ << 0x18;

      auVar33 = (auVar6 << 0x40) >> 0x58;

      break;

    case 0xfffffffc:

      auVar7._8_8_ = 0;

      auVar7._0_8_ = auVar33._0_8_ << 0x20;

      auVar33 = (auVar7 << 0x40) >> 0x60;

      break;

    case 0xfffffffd:

      auVar8._8_8_ = 0;

      auVar8._0_8_ = auVar33._0_8_ << 0x28;

      auVar33 = (auVar8 << 0x40) >> 0x68;

      break;

    case 0xfffffffe:

      auVar9._8_8_ = 0;

      auVar9._0_8_ = auVar33._0_8_ << 0x30;

      auVar33 = (auVar9 << 0x40) >> 0x70;

      break;

    case 0xffffffff:

      auVar10._8_8_ = 0;

      auVar10._0_8_ = auVar33._0_8_ << 0x38;

      auVar33 = (auVar10 << 0x40) >> 0x78;

    }

    if (uVar21 == 0 || (ulonglong)uVar2 < 0x10 - uVar21) goto LAB_1402e1439;

  }

  auVar35 = pauVar20[1];

  auVar23[0] = -(auVar35[0] == '\0');

  auVar23[1] = -(auVar35[1] == '\0');

  auVar23[2] = -(auVar35[2] == '\0');

  auVar23[3] = -(auVar35[3] == '\0');

  auVar23[4] = -(auVar35[4] == '\0');

  auVar23[5] = -(auVar35[5] == '\0');

  auVar23[6] = -(auVar35[6] == '\0');

  lVar25 = auVar35._8_8_;

  auVar23[7] = -(auVar35[7] == '\0');

  auVar23[8] = -(auVar35[8] == '\0');

  auVar23[9] = -(auVar35[9] == '\0');

  auVar23[10] = -(auVar35[10] == '\0');

  auVar23[0xb] = -(auVar35[0xb] == '\0');

  auVar23[0xc] = -(auVar35[0xc] == '\0');

  auVar23[0xd] = -(auVar35[0xd] == '\0');

  auVar23[0xe] = -(auVar35[0xe] == '\0');

  auVar23[0xf] = -(auVar35[0xf] == '\0');

  uVar3 = (ushort)(SUB161(auVar23 >> 7,0) & 1) | (ushort)(SUB161(auVar23 >> 0xf,0) & 1) << 1 |

          (ushort)(SUB161(auVar23 >> 0x17,0) & 1) << 2 |

          (ushort)(SUB161(auVar23 >> 0x1f,0) & 1) << 3 |

          (ushort)(SUB161(auVar23 >> 0x27,0) & 1) << 4 |

          (ushort)(SUB161(auVar23 >> 0x2f,0) & 1) << 5 |

          (ushort)(SUB161(auVar23 >> 0x37,0) & 1) << 6 |

          (ushort)(SUB161(auVar23 >> 0x3f,0) & 1) << 7 |

          (ushort)(SUB161(auVar23 >> 0x47,0) & 1) << 8 |

          (ushort)(SUB161(auVar23 >> 0x4f,0) & 1) << 9 |

          (ushort)(SUB161(auVar23 >> 0x57,0) & 1) << 10 |

          (ushort)(SUB161(auVar23 >> 0x5f,0) & 1) << 0xb |

          (ushort)(SUB161(auVar23 >> 0x67,0) & 1) << 0xc |

          (ushort)(SUB161(auVar23 >> 0x6f,0) & 1) << 0xd |

          (ushort)(SUB161(auVar23 >> 0x77,0) & 1) << 0xe | (ushort)(auVar23[0xf] >> 7) << 0xf;

  uVar34 = auVar35._0_8_;

  if (uVar3 != 0) {

    uVar2 = 0;

    if (uVar3 != 0) {

      for (; (uVar3 >> uVar2 & 1) == 0; uVar2 = uVar2 + 1) {

      }

    }

    if ((uVar2 - uVar21) + 0x10 < 0x11) {

      switch(-uVar2) {

      case 0:

        auVar35 = ZEXT816(0);

        break;

      case 0xfffffff1:

        auVar35._0_8_ = uVar34 << 8;

        auVar35._8_8_ = lVar25 << 8 | uVar34 >> 0x38;

        break;

      case 0xfffffff2:

        auVar35._0_8_ = uVar34 << 0x10;

        auVar35._8_8_ = lVar25 << 0x10 | uVar34 >> 0x30;

        break;

      case 0xfffffff3:

        auVar35._0_8_ = uVar34 << 0x18;

        auVar35._8_8_ = lVar25 << 0x18 | uVar34 >> 0x28;

        break;

      case 0xfffffff4:

        auVar35._0_8_ = uVar34 << 0x20;

        auVar35._8_8_ = lVar25 << 0x20 | uVar34 >> 0x20;

        break;

      case 0xfffffff5:

        auVar35._0_8_ = uVar34 << 0x28;

        auVar35._8_8_ = lVar25 << 0x28 | uVar34 >> 0x18;

        break;

      case 0xfffffff6:

        auVar35._0_8_ = uVar34 << 0x30;

        auVar35._8_8_ = lVar25 << 0x30 | uVar34 >> 0x10;

        break;

      case 0xfffffff7:

        auVar35._0_8_ = uVar34 << 0x38;

        auVar35._8_8_ = lVar25 << 0x38 | uVar34 >> 8;

        break;

      case 0xfffffff8:

        auVar18._8_8_ = 0;

        auVar18._0_8_ = uVar34;

        auVar35 = auVar18 << 0x40;

        break;

      case 0xfffffff9:

        auVar11._8_8_ = 0;

        auVar11._0_8_ = uVar34 << 8;

        auVar35 = auVar11 << 0x40;

        break;

      case 0xfffffffa:

        auVar12._8_8_ = 0;

        auVar12._0_8_ = uVar34 << 0x10;

        auVar35 = auVar12 << 0x40;

        break;

      case 0xfffffffb:

        auVar13._8_8_ = 0;

        auVar13._0_8_ = uVar34 << 0x18;

        auVar35 = auVar13 << 0x40;

        break;

      case 0xfffffffc:

        auVar14._8_8_ = 0;

        auVar14._0_8_ = uVar34 << 0x20;

        auVar35 = auVar14 << 0x40;

        break;

      case 0xfffffffd:

        auVar15._8_8_ = 0;

        auVar15._0_8_ = uVar34 << 0x28;

        auVar35 = auVar15 << 0x40;

        break;

      case 0xfffffffe:

        auVar16._8_8_ = 0;

        auVar16._0_8_ = uVar34 << 0x30;

        auVar35 = auVar16 << 0x40;

        break;

      case 0xffffffff:

        auVar17._8_8_ = 0;

        auVar17._0_8_ = uVar34 << 0x38;

        auVar35 = auVar17 << 0x40;

      }

      auVar33 = auVar33 | auVar35;

LAB_1402e1439:

      cVar1 = *param_1;

      while( true ) {

        if (cVar1 == '\0') {

          return (char *)0x0;

        }

        auVar24[0] = -(cVar1 == auVar33[0]);

        auVar24[1] = -(cVar1 == auVar33[1]);

        auVar24[2] = -(cVar1 == auVar33[2]);

        auVar24[3] = -(cVar1 == auVar33[3]);

        auVar24[4] = -(cVar1 == auVar33[4]);

        auVar24[5] = -(cVar1 == auVar33[5]);

        auVar24[6] = -(cVar1 == auVar33[6]);

        auVar24[7] = -(cVar1 == auVar33[7]);

        auVar24[8] = -(cVar1 == auVar33[8]);

        auVar24[9] = -(cVar1 == auVar33[9]);

        auVar24[10] = -(cVar1 == auVar33[10]);

        auVar24[0xb] = -(cVar1 == auVar33[0xb]);

        auVar24[0xc] = -(cVar1 == auVar33[0xc]);

        auVar24[0xd] = -(cVar1 == auVar33[0xd]);

        auVar24[0xe] = -(cVar1 == auVar33[0xe]);

        auVar24[0xf] = -(cVar1 == auVar33[0xf]);

        if ((((((((((((((((SUB161(auVar24 >> 7,0) & 1) != 0 || (SUB161(auVar24 >> 0xf,0) & 1) != 0)

                        || (SUB161(auVar24 >> 0x17,0) & 1) != 0) ||

                       (SUB161(auVar24 >> 0x1f,0) & 1) != 0) || (SUB161(auVar24 >> 0x27,0) & 1) != 0

                      ) || (SUB161(auVar24 >> 0x2f,0) & 1) != 0) ||

                    (SUB161(auVar24 >> 0x37,0) & 1) != 0) || (SUB161(auVar24 >> 0x3f,0) & 1) != 0)

                  || (SUB161(auVar24 >> 0x47,0) & 1) != 0) || (SUB161(auVar24 >> 0x4f,0) & 1) != 0)

                || (SUB161(auVar24 >> 0x57,0) & 1) != 0) || (SUB161(auVar24 >> 0x5f,0) & 1) != 0) ||

              (SUB161(auVar24 >> 0x67,0) & 1) != 0) || (SUB161(auVar24 >> 0x6f,0) & 1) != 0) ||

            (SUB161(auVar24 >> 0x77,0) & 1) != 0) || auVar24[0xf] < '\0') break;

        cVar1 = param_1[1];

        param_1 = param_1 + 1;

      }

      return param_1;

    }

  }

  pcVar19 = (char *)FUN_1402e10f0(param_1,param_2);

  return pcVar19;

}




