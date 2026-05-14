// Address: 0x1401ddcc0
// Ghidra name: FUN_1401ddcc0
// ============ 0x1401ddcc0 FUN_1401ddcc0 (size=1857) ============


undefined8

FUN_1401ddcc0(undefined8 param_1,longlong param_2,longlong param_3,longlong param_4,int param_5,

             longlong param_6,int param_7,longlong param_8,int param_9,int param_10,

             longlong param_11,int param_12,int param_13,float param_14,float param_15)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float *pfVar4;

  longlong lVar5;

  ushort *puVar6;

  byte *pbVar7;

  longlong lVar8;

  int iVar9;

  uint uVar10;

  uint uVar11;

  longlong lVar12;

  uint *puVar13;

  uint uVar14;

  float fVar15;

  longlong local_res10;

  

  if (param_11 != 0) {

    param_10 = param_12;

  }

  lVar12 = (longlong)param_10;

  pfVar4 = (float *)FUN_14014b940(param_1,lVar12 * 0x18,0,param_2 + 8);

  fVar3 = DAT_14039ca34;

  fVar2 = DAT_14030a2d0;

  fVar1 = *(float *)(param_2 + 0x18);

  if (pfVar4 == (float *)0x0) {

    return 0;

  }

  iVar9 = 0;

  if (param_11 != 0) {

    iVar9 = param_13;

  }

  lVar8 = 0;

  uVar14 = 0;

  *(longlong *)(param_2 + 0x10) = lVar12;

  if (lVar12 < 4) {

    uVar14 = 0;

    if (lVar12 < 1) {

      return 1;

    }

  }

  else {

    pbVar7 = (byte *)(param_11 + 2);

    puVar6 = (ushort *)(param_11 + 4);

    puVar13 = (uint *)(param_11 + 8);

    local_res10 = (lVar12 - 4U >> 2) + 1;

    uVar11 = 2;

    lVar8 = local_res10 * 4;

    do {

      if (iVar9 == 4) {

        uVar10 = puVar13[-2];

      }

      else if (iVar9 == 2) {

        uVar10 = (uint)puVar6[-2];

      }

      else {

        uVar10 = uVar14;

        if (iVar9 == 1) {

          uVar10 = (uint)pbVar7[-2];

        }

      }

      lVar5 = (longlong)(int)(uVar10 * param_7);

      *pfVar4 = param_14 * *(float *)((int)(uVar10 * param_5) + param_4) - fVar3;

      fVar15 = *(float *)((longlong)(int)(uVar10 * param_5) + 4 + param_4);

      pfVar4[2] = 0.0;

      pfVar4[1] = param_15 * fVar15 - fVar3;

      pfVar4[3] = (float)((((uint)(longlong)(fVar1 * *(float *)(lVar5 + param_6) * fVar2) & 0xff |

                           (int)(longlong)(*(float *)(lVar5 + 0xc + param_6) * fVar2) << 8) << 8 |

                          (uint)(longlong)(fVar1 * *(float *)(lVar5 + 4 + param_6) * fVar2) & 0xff)

                          << 8 | (uint)(longlong)(fVar1 * *(float *)(lVar5 + 8 + param_6) * fVar2) &

                                 0xff);

      if (param_3 == 0) {

        pfVar4[4] = 0.0;

        fVar15 = 0.0;

      }

      else {

        pfVar4[4] = *(float *)((int)(uVar10 * param_9) + param_8);

        fVar15 = *(float *)((longlong)(int)(uVar10 * param_9) + 4 + param_8);

      }

      pfVar4[5] = fVar15;

      if (iVar9 == 4) {

        uVar10 = puVar13[-1];

      }

      else if (iVar9 == 2) {

        uVar10 = (uint)puVar6[-1];

      }

      else if (iVar9 == 1) {

        uVar10 = (uint)pbVar7[-1];

      }

      else {

        uVar10 = uVar11 - 1;

      }

      lVar5 = (longlong)(int)(uVar10 * param_7);

      pfVar4[6] = param_14 * *(float *)((int)(uVar10 * param_5) + param_4) - fVar3;

      fVar15 = *(float *)((longlong)(int)(uVar10 * param_5) + 4 + param_4);

      pfVar4[8] = 0.0;

      pfVar4[7] = param_15 * fVar15 - fVar3;

      pfVar4[9] = (float)((((uint)(longlong)(fVar1 * *(float *)(lVar5 + param_6) * fVar2) & 0xff |

                           (int)(longlong)(*(float *)(lVar5 + 0xc + param_6) * fVar2) << 8) << 8 |

                          (uint)(longlong)(fVar1 * *(float *)(lVar5 + 4 + param_6) * fVar2) & 0xff)

                          << 8 | (uint)(longlong)(fVar1 * *(float *)(lVar5 + 8 + param_6) * fVar2) &

                                 0xff);

      if (param_3 == 0) {

        pfVar4[10] = 0.0;

        fVar15 = 0.0;

      }

      else {

        pfVar4[10] = *(float *)((int)(uVar10 * param_9) + param_8);

        fVar15 = *(float *)((longlong)(int)(uVar10 * param_9) + 4 + param_8);

      }

      pfVar4[0xb] = fVar15;

      if (iVar9 == 4) {

        uVar10 = *puVar13;

      }

      else if (iVar9 == 2) {

        uVar10 = (uint)*puVar6;

      }

      else {

        uVar10 = uVar11;

        if (iVar9 == 1) {

          uVar10 = (uint)*pbVar7;

        }

      }

      lVar5 = (longlong)(int)(uVar10 * param_7);

      pfVar4[0xc] = param_14 * *(float *)((int)(uVar10 * param_5) + param_4) - fVar3;

      fVar15 = *(float *)((longlong)(int)(uVar10 * param_5) + 4 + param_4);

      pfVar4[0xe] = 0.0;

      pfVar4[0xd] = param_15 * fVar15 - fVar3;

      pfVar4[0xf] = (float)((((uint)(longlong)(fVar1 * *(float *)(lVar5 + param_6) * fVar2) & 0xff |

                             (int)(longlong)(*(float *)(lVar5 + 0xc + param_6) * fVar2) << 8) << 8 |

                            (uint)(longlong)(fVar1 * *(float *)(lVar5 + 4 + param_6) * fVar2) & 0xff

                            ) << 8 | (uint)(longlong)

                                           (fVar1 * *(float *)(lVar5 + 8 + param_6) * fVar2) & 0xff)

      ;

      if (param_3 == 0) {

        pfVar4[0x10] = 0.0;

        fVar15 = 0.0;

      }

      else {

        pfVar4[0x10] = *(float *)((int)(uVar10 * param_9) + param_8);

        fVar15 = *(float *)((longlong)(int)(uVar10 * param_9) + 4 + param_8);

      }

      pfVar4[0x11] = fVar15;

      if (iVar9 == 4) {

        uVar10 = puVar13[1];

      }

      else if (iVar9 == 2) {

        uVar10 = (uint)puVar6[1];

      }

      else if (iVar9 == 1) {

        uVar10 = (uint)pbVar7[1];

      }

      else {

        uVar10 = uVar11 + 1;

      }

      lVar5 = (longlong)(int)(uVar10 * param_7);

      pfVar4[0x12] = param_14 * *(float *)((int)(uVar10 * param_5) + param_4) - fVar3;

      fVar15 = *(float *)((longlong)(int)(uVar10 * param_5) + 4 + param_4);

      pfVar4[0x14] = 0.0;

      pfVar4[0x13] = param_15 * fVar15 - fVar3;

      pfVar4[0x15] = (float)((((uint)(longlong)(fVar1 * *(float *)(lVar5 + param_6) * fVar2) & 0xff

                              | (int)(longlong)(*(float *)(lVar5 + 0xc + param_6) * fVar2) << 8) <<

                              8 | (uint)(longlong)(fVar1 * *(float *)(lVar5 + 4 + param_6) * fVar2)

                                  & 0xff) << 8 |

                            (uint)(longlong)(fVar1 * *(float *)(lVar5 + 8 + param_6) * fVar2) & 0xff

                            );

      if (param_3 == 0) {

        pfVar4[0x16] = 0.0;

        fVar15 = 0.0;

      }

      else {

        pfVar4[0x16] = *(float *)((int)(uVar10 * param_9) + param_8);

        fVar15 = *(float *)((longlong)(int)(uVar10 * param_9) + 4 + param_8);

      }

      uVar14 = uVar14 + 4;

      uVar11 = uVar11 + 4;

      pfVar4[0x17] = fVar15;

      puVar13 = puVar13 + 4;

      pfVar4 = pfVar4 + 0x18;

      puVar6 = puVar6 + 4;

      pbVar7 = pbVar7 + 4;

      local_res10 = local_res10 + -1;

    } while (local_res10 != 0);

    if (lVar12 <= lVar8) {

      return 1;

    }

  }

  pfVar4 = pfVar4 + 2;

  do {

    if (iVar9 == 4) {

      uVar11 = *(uint *)(param_11 + lVar8 * 4);

    }

    else if (iVar9 == 2) {

      uVar11 = (uint)*(ushort *)(param_11 + lVar8 * 2);

    }

    else {

      uVar11 = uVar14;

      if (iVar9 == 1) {

        uVar11 = (uint)*(byte *)(lVar8 + param_11);

      }

    }

    lVar5 = (longlong)(int)(uVar11 * param_7);

    pfVar4[-2] = param_14 * *(float *)((int)(uVar11 * param_5) + param_4) - fVar3;

    fVar15 = *(float *)((longlong)(int)(uVar11 * param_5) + 4 + param_4);

    *pfVar4 = 0.0;

    pfVar4[-1] = param_15 * fVar15 - fVar3;

    pfVar4[1] = (float)((((uint)(longlong)(fVar1 * *(float *)(lVar5 + param_6) * fVar2) & 0xff |

                         (int)(longlong)(*(float *)(lVar5 + 0xc + param_6) * fVar2) << 8) << 8 |

                        (uint)(longlong)(fVar1 * *(float *)(lVar5 + 4 + param_6) * fVar2) & 0xff) <<

                        8 | (uint)(longlong)(fVar1 * *(float *)(lVar5 + 8 + param_6) * fVar2) & 0xff

                       );

    if (param_3 == 0) {

      pfVar4[2] = 0.0;

      fVar15 = 0.0;

    }

    else {

      pfVar4[2] = *(float *)((int)(uVar11 * param_9) + param_8);

      fVar15 = *(float *)((longlong)(int)(uVar11 * param_9) + 4 + param_8);

    }

    uVar14 = uVar14 + 1;

    lVar8 = lVar8 + 1;

    pfVar4[3] = fVar15;

    pfVar4 = pfVar4 + 6;

  } while (lVar8 < lVar12);

  return 1;

}




