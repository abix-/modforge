// Address: 0x14012f0b0
// Ghidra name: thunk_FUN_1402c9190
// ============ 0x14012f0b0 thunk_FUN_1402c9190 (size=5) ============


char * thunk_FUN_1402c9190(ulonglong param_1,char param_2)



{

  uint uVar1;

  ushort uVar2;

  uint uVar3;

  char *pcVar4;

  char *pcVar5;

  undefined1 auVar6 [16];

  undefined1 in_XMM1 [16];

  undefined1 auVar7 [16];

  undefined1 auVar8 [16];

  undefined1 auVar9 [16];

  char cVar10;

  char cVar11;

  char cVar12;

  char cVar13;

  

  pcVar4 = (char *)(param_1 & 0xfffffffffffffff0);

  auVar7 = pshuflw(in_XMM1,ZEXT216(CONCAT11(param_2,param_2)),0);

  auVar9[0] = -(*pcVar4 == '\0');

  auVar9[1] = -(pcVar4[1] == '\0');

  auVar9[2] = -(pcVar4[2] == '\0');

  auVar9[3] = -(pcVar4[3] == '\0');

  auVar9[4] = -(pcVar4[4] == '\0');

  auVar9[5] = -(pcVar4[5] == '\0');

  auVar9[6] = -(pcVar4[6] == '\0');

  auVar9[7] = -(pcVar4[7] == '\0');

  auVar9[8] = -(pcVar4[8] == '\0');

  auVar9[9] = -(pcVar4[9] == '\0');

  auVar9[10] = -(pcVar4[10] == '\0');

  auVar9[0xb] = -(pcVar4[0xb] == '\0');

  auVar9[0xc] = -(pcVar4[0xc] == '\0');

  auVar9[0xd] = -(pcVar4[0xd] == '\0');

  auVar9[0xe] = -(pcVar4[0xe] == '\0');

  auVar9[0xf] = -(pcVar4[0xf] == '\0');

  cVar10 = auVar7[0];

  auVar6[0] = -(*pcVar4 == cVar10);

  cVar11 = auVar7[1];

  auVar6[1] = -(pcVar4[1] == cVar11);

  cVar12 = auVar7[2];

  auVar6[2] = -(pcVar4[2] == cVar12);

  cVar13 = auVar7[3];

  auVar6[3] = -(pcVar4[3] == cVar13);

  auVar6[4] = -(pcVar4[4] == cVar10);

  auVar6[5] = -(pcVar4[5] == cVar11);

  auVar6[6] = -(pcVar4[6] == cVar12);

  auVar6[7] = -(pcVar4[7] == cVar13);

  auVar6[8] = -(pcVar4[8] == cVar10);

  auVar6[9] = -(pcVar4[9] == cVar11);

  auVar6[10] = -(pcVar4[10] == cVar12);

  auVar6[0xb] = -(pcVar4[0xb] == cVar13);

  auVar6[0xc] = -(pcVar4[0xc] == cVar10);

  auVar6[0xd] = -(pcVar4[0xd] == cVar11);

  auVar6[0xe] = -(pcVar4[0xe] == cVar12);

  auVar6[0xf] = -(pcVar4[0xf] == cVar13);

  auVar6 = auVar6 | auVar9;

  uVar3 = (uint)(ushort)((ushort)(SUB161(auVar6 >> 7,0) & 1) |

                         (ushort)(SUB161(auVar6 >> 0xf,0) & 1) << 1 |

                         (ushort)(SUB161(auVar6 >> 0x17,0) & 1) << 2 |

                         (ushort)(SUB161(auVar6 >> 0x1f,0) & 1) << 3 |

                         (ushort)(SUB161(auVar6 >> 0x27,0) & 1) << 4 |

                         (ushort)(SUB161(auVar6 >> 0x2f,0) & 1) << 5 |

                         (ushort)(SUB161(auVar6 >> 0x37,0) & 1) << 6 |

                         (ushort)(SUB161(auVar6 >> 0x3f,0) & 1) << 7 |

                         (ushort)(SUB161(auVar6 >> 0x47,0) & 1) << 8 |

                         (ushort)(SUB161(auVar6 >> 0x4f,0) & 1) << 9 |

                         (ushort)(SUB161(auVar6 >> 0x57,0) & 1) << 10 |

                         (ushort)(SUB161(auVar6 >> 0x5f,0) & 1) << 0xb |

                         (ushort)(SUB161(auVar6 >> 0x67,0) & 1) << 0xc |

                         (ushort)(SUB161(auVar6 >> 0x6f,0) & 1) << 0xd |

                         (ushort)(SUB161(auVar6 >> 0x77,0) & 1) << 0xe |

                        (ushort)(byte)(auVar6[0xf] >> 7) << 0xf) & -1 << ((byte)param_1 & 0xf);

  pcVar5 = pcVar4;

  if (uVar3 == 0) {

    do {

      pcVar4 = pcVar5 + 0x10;

      auVar7[0] = -(*pcVar4 == '\0');

      auVar7[1] = -(pcVar5[0x11] == '\0');

      auVar7[2] = -(pcVar5[0x12] == '\0');

      auVar7[3] = -(pcVar5[0x13] == '\0');

      auVar7[4] = -(pcVar5[0x14] == '\0');

      auVar7[5] = -(pcVar5[0x15] == '\0');

      auVar7[6] = -(pcVar5[0x16] == '\0');

      auVar7[7] = -(pcVar5[0x17] == '\0');

      auVar7[8] = -(pcVar5[0x18] == '\0');

      auVar7[9] = -(pcVar5[0x19] == '\0');

      auVar7[10] = -(pcVar5[0x1a] == '\0');

      auVar7[0xb] = -(pcVar5[0x1b] == '\0');

      auVar7[0xc] = -(pcVar5[0x1c] == '\0');

      auVar7[0xd] = -(pcVar5[0x1d] == '\0');

      auVar7[0xe] = -(pcVar5[0x1e] == '\0');

      auVar7[0xf] = -(pcVar5[0x1f] == '\0');

      auVar8[0] = -(*pcVar4 == cVar10);

      auVar8[1] = -(pcVar5[0x11] == cVar11);

      auVar8[2] = -(pcVar5[0x12] == cVar12);

      auVar8[3] = -(pcVar5[0x13] == cVar13);

      auVar8[4] = -(pcVar5[0x14] == cVar10);

      auVar8[5] = -(pcVar5[0x15] == cVar11);

      auVar8[6] = -(pcVar5[0x16] == cVar12);

      auVar8[7] = -(pcVar5[0x17] == cVar13);

      auVar8[8] = -(pcVar5[0x18] == cVar10);

      auVar8[9] = -(pcVar5[0x19] == cVar11);

      auVar8[10] = -(pcVar5[0x1a] == cVar12);

      auVar8[0xb] = -(pcVar5[0x1b] == cVar13);

      auVar8[0xc] = -(pcVar5[0x1c] == cVar10);

      auVar8[0xd] = -(pcVar5[0x1d] == cVar11);

      auVar8[0xe] = -(pcVar5[0x1e] == cVar12);

      auVar8[0xf] = -(pcVar5[0x1f] == cVar13);

      auVar8 = auVar8 | auVar7;

      uVar2 = (ushort)(SUB161(auVar8 >> 7,0) & 1) | (ushort)(SUB161(auVar8 >> 0xf,0) & 1) << 1 |

              (ushort)(SUB161(auVar8 >> 0x17,0) & 1) << 2 |

              (ushort)(SUB161(auVar8 >> 0x1f,0) & 1) << 3 |

              (ushort)(SUB161(auVar8 >> 0x27,0) & 1) << 4 |

              (ushort)(SUB161(auVar8 >> 0x2f,0) & 1) << 5 |

              (ushort)(SUB161(auVar8 >> 0x37,0) & 1) << 6 |

              (ushort)(SUB161(auVar8 >> 0x3f,0) & 1) << 7 |

              (ushort)(SUB161(auVar8 >> 0x47,0) & 1) << 8 |

              (ushort)(SUB161(auVar8 >> 0x4f,0) & 1) << 9 |

              (ushort)(SUB161(auVar8 >> 0x57,0) & 1) << 10 |

              (ushort)(SUB161(auVar8 >> 0x5f,0) & 1) << 0xb |

              (ushort)(SUB161(auVar8 >> 0x67,0) & 1) << 0xc |

              (ushort)(SUB161(auVar8 >> 0x6f,0) & 1) << 0xd |

              (ushort)(SUB161(auVar8 >> 0x77,0) & 1) << 0xe |

              (ushort)(byte)(auVar8[0xf] >> 7) << 0xf;

      uVar3 = (uint)uVar2;

      pcVar5 = pcVar4;

    } while (uVar2 == 0);

  }

  uVar1 = 0;

  if (uVar3 != 0) {

    for (; (uVar3 >> uVar1 & 1) == 0; uVar1 = uVar1 + 1) {

    }

  }

  pcVar5 = (char *)0x0;

  if (pcVar4[uVar1] == param_2) {

    pcVar5 = pcVar4 + uVar1;

  }

  return pcVar5;

}




