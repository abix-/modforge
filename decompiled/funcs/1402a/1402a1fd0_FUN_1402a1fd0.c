// Address: 0x1402a1fd0
// Ghidra name: FUN_1402a1fd0
// ============ 0x1402a1fd0 FUN_1402a1fd0 (size=2298) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1402a1fd0(float *param_1,int param_2,int *param_3,uint param_4,float param_5,float param_6,

                  float param_7,float param_8,float param_9)



{

  char cVar1;

  int iVar2;

  undefined2 uVar3;

  uint uVar4;

  byte bVar5;

  byte bVar6;

  uint uVar7;

  byte bVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  

  param_4 = param_4 & 0x3e0;

  if (param_4 == 0x100) {

    param_6 = param_6 * param_5;

    param_7 = param_7 * param_5;

    param_8 = param_8 * param_5;

  }

  else if (param_4 == 0x1a0) {

    param_6 = (float)FUN_14017c370(param_6);

    param_7 = (float)FUN_14017c370(param_7);

    param_8 = (float)FUN_14017c370(param_8);

  }

  else if (param_4 == 0x200) {

    param_6 = (float)FUN_14017c120(param_5 * param_6);

    param_7 = (float)FUN_14017c120(param_5 * param_7);

    param_8 = (float)FUN_14017c120(param_5 * param_8);

  }

  fVar11 = DAT_14039ca44;

  fVar12 = DAT_14030ec38;

  fVar9 = DAT_14030a2d0;

  if (param_2 != 0) {

    if (param_2 == 1) {

      if (0.0 <= param_6) {

        fVar12 = DAT_14039ca44;

        if (param_6 <= DAT_14039ca44) {

          fVar12 = param_6;

        }

      }

      else {

        fVar12 = 0.0;

      }

      fVar12 = (float)thunk_FUN_1402e1d00(fVar12 * DAT_14030a2d0);

      if (0.0 <= param_7) {

        fVar14 = fVar11;

        if (param_7 <= fVar11) {

          fVar14 = param_7;

        }

      }

      else {

        fVar14 = 0.0;

      }

      fVar10 = (float)thunk_FUN_1402e1d00(fVar14 * fVar9);

      fVar14 = 0.0;

      if ((0.0 <= param_8) && (fVar14 = fVar11, param_8 <= fVar11)) {

        fVar14 = param_8;

      }

      fVar9 = (float)thunk_FUN_1402e1d00(fVar14 * fVar9);

      cVar1 = *(char *)((longlong)param_3 + 5);

      bVar6 = (byte)(int)fVar12;

      bVar8 = (byte)(int)fVar10;

      bVar5 = (byte)(int)fVar9;

      if (cVar1 == '\x01') {

        *(byte *)param_1 =

             (bVar5 >> (8U - *(char *)((longlong)param_3 + 0x1a) & 0x1f)) <<

             (*(byte *)((longlong)param_3 + 0x1e) & 0x1f) |

             (bVar8 >> (8U - *(char *)((longlong)param_3 + 0x19) & 0x1f)) <<

             (*(byte *)((longlong)param_3 + 0x1d) & 0x1f) |

             (bVar6 >> (8U - (char)param_3[6] & 0x1f)) << (*(byte *)(param_3 + 7) & 0x1f) |

             *(byte *)(param_3 + 5);

      }

      else if (cVar1 == '\x02') {

        *(ushort *)param_1 =

             (ushort)(bVar5 >> (8U - *(char *)((longlong)param_3 + 0x1a) & 0x1f)) <<

             (*(byte *)((longlong)param_3 + 0x1e) & 0x1f) |

             (ushort)(bVar8 >> (8U - *(char *)((longlong)param_3 + 0x19) & 0x1f)) <<

             (*(byte *)((longlong)param_3 + 0x1d) & 0x1f) |

             (ushort)(bVar6 >> (8U - (char)param_3[6] & 0x1f)) << (*(byte *)(param_3 + 7) & 0x1f) |

             *(ushort *)(param_3 + 5);

      }

      else if (cVar1 == '\x03') {

        *(byte *)((ulonglong)(*(byte *)(param_3 + 7) >> 3) + (longlong)param_1) = bVar6;

        *(byte *)((ulonglong)(*(byte *)((longlong)param_3 + 0x1d) >> 3) + (longlong)param_1) = bVar8

        ;

        *(byte *)((ulonglong)(*(byte *)((longlong)param_3 + 0x1e) >> 3) + (longlong)param_1) = bVar5

        ;

      }

      else if (cVar1 == '\x04') {

        *param_1 = (float)((((int)fVar9 & 0xffU) >>

                           (8U - *(char *)((longlong)param_3 + 0x1a) & 0x1f)) <<

                           (*(byte *)((longlong)param_3 + 0x1e) & 0x1f) |

                           (((int)fVar10 & 0xffU) >>

                           (8U - *(char *)((longlong)param_3 + 0x19) & 0x1f)) <<

                           (*(byte *)((longlong)param_3 + 0x1d) & 0x1f) |

                           (((int)fVar12 & 0xffU) >> (8U - (char)param_3[6] & 0x1f)) <<

                           (*(byte *)(param_3 + 7) & 0x1f) | param_3[5]);

      }

    }

    else if (param_2 == 2) {

      if (0.0 <= param_6) {

        fVar12 = DAT_14039ca44;

        if (param_6 <= DAT_14039ca44) {

          fVar12 = param_6;

        }

      }

      else {

        fVar12 = 0.0;

      }

      fVar12 = (float)thunk_FUN_1402e1d00(fVar12 * DAT_14030a2d0);

      if (0.0 <= param_7) {

        fVar14 = fVar11;

        if (param_7 <= fVar11) {

          fVar14 = param_7;

        }

      }

      else {

        fVar14 = 0.0;

      }

      fVar14 = (float)thunk_FUN_1402e1d00(fVar14 * fVar9);

      if (0.0 <= param_8) {

        fVar10 = fVar11;

        if (param_8 <= fVar11) {

          fVar10 = param_8;

        }

      }

      else {

        fVar10 = 0.0;

      }

      fVar13 = (float)thunk_FUN_1402e1d00(fVar10 * fVar9);

      fVar10 = 0.0;

      if ((0.0 <= param_9) && (fVar10 = fVar11, param_9 <= fVar11)) {

        fVar10 = param_9;

      }

      fVar9 = (float)thunk_FUN_1402e1d00(fVar10 * fVar9);

      cVar1 = *(char *)((longlong)param_3 + 5);

      uVar4 = (int)fVar9 & 0xff;

      bVar8 = (byte)(int)fVar12;

      bVar5 = (byte)(int)fVar14;

      bVar6 = (byte)(int)fVar13;

      if (cVar1 == '\x01') {

        *(byte *)param_1 =

             (char)(uVar4 >> (8U - *(char *)((longlong)param_3 + 0x1b) & 0x1f)) <<

             (*(byte *)((longlong)param_3 + 0x1f) & 0x1f) |

             (bVar6 >> (8U - *(char *)((longlong)param_3 + 0x1a) & 0x1f)) <<

             (*(byte *)((longlong)param_3 + 0x1e) & 0x1f) |

             (bVar5 >> (8U - *(char *)((longlong)param_3 + 0x19) & 0x1f)) <<

             (*(byte *)((longlong)param_3 + 0x1d) & 0x1f) |

             (bVar8 >> (8U - (char)param_3[6] & 0x1f)) << (*(byte *)(param_3 + 7) & 0x1f);

      }

      else if (cVar1 == '\x02') {

        *(ushort *)param_1 =

             (short)(uVar4 >> (8U - *(char *)((longlong)param_3 + 0x1b) & 0x1f)) <<

             (*(byte *)((longlong)param_3 + 0x1f) & 0x1f) |

             (ushort)(bVar6 >> (8U - *(char *)((longlong)param_3 + 0x1a) & 0x1f)) <<

             (*(byte *)((longlong)param_3 + 0x1e) & 0x1f) |

             (ushort)(bVar5 >> (8U - *(char *)((longlong)param_3 + 0x19) & 0x1f)) <<

             (*(byte *)((longlong)param_3 + 0x1d) & 0x1f) |

             (ushort)(bVar8 >> (8U - (char)param_3[6] & 0x1f)) << (*(byte *)(param_3 + 7) & 0x1f);

      }

      else if (cVar1 == '\x03') {

        *(byte *)((ulonglong)(*(byte *)(param_3 + 7) >> 3) + (longlong)param_1) = bVar8;

        *(byte *)((ulonglong)(*(byte *)((longlong)param_3 + 0x1d) >> 3) + (longlong)param_1) = bVar5

        ;

        *(byte *)((ulonglong)(*(byte *)((longlong)param_3 + 0x1e) >> 3) + (longlong)param_1) = bVar6

        ;

      }

      else if (cVar1 == '\x04') {

        *param_1 = (float)((((int)fVar13 & 0xffU) >>

                           (8U - *(char *)((longlong)param_3 + 0x1a) & 0x1f)) <<

                           (*(byte *)((longlong)param_3 + 0x1e) & 0x1f) |

                           (((int)fVar14 & 0xffU) >>

                           (8U - *(char *)((longlong)param_3 + 0x19) & 0x1f)) <<

                           (*(byte *)((longlong)param_3 + 0x1d) & 0x1f) |

                           (((int)fVar12 & 0xffU) >> (8U - (char)param_3[6] & 0x1f)) <<

                           (*(byte *)(param_3 + 7) & 0x1f) |

                          (uVar4 >> (8U - *(char *)((longlong)param_3 + 0x1b) & 0x1f)) <<

                          (*(byte *)((longlong)param_3 + 0x1f) & 0x1f));

      }

    }

    else if (param_2 == 3) {

      iVar2 = *param_3;

      fVar9 = DAT_14039ca44;

      if ((iVar2 == 0x16172004) || (fVar9 = param_9, iVar2 == 0x16372004)) {

        if (0.0 <= param_6) {

          fVar12 = DAT_14039ca44;

          if (param_6 <= DAT_14039ca44) {

            fVar12 = param_6;

          }

        }

        else {

          fVar12 = 0.0;

        }

        if (0.0 <= param_7) {

          if (param_7 <= DAT_14039ca44) {

            fVar11 = param_7;

          }

        }

        else {

          fVar11 = 0.0;

        }

        if (0.0 <= param_8) {

          fVar14 = DAT_14039ca44;

          if (param_8 <= DAT_14039ca44) {

            fVar14 = param_8;

          }

        }

        else {

          fVar14 = 0.0;

        }

        fVar10 = 0.0;

        if ((0.0 <= fVar9) && (fVar10 = DAT_14039ca44, fVar9 <= DAT_14039ca44)) {

          fVar10 = fVar9;

        }

        fVar10 = (float)thunk_FUN_1402e1d00(fVar10 * DAT_14030338c);

        fVar9 = _DAT_1403802bc;

        fVar12 = (float)thunk_FUN_1402e1d00(fVar12 * _DAT_1403802bc);

        uVar7 = (uint)(longlong)fVar12 | (int)(longlong)fVar10 << 10;

        fVar12 = (float)thunk_FUN_1402e1d00(fVar11 * fVar9);

        fVar14 = fVar14 * fVar9;

        uVar4 = (uint)(longlong)fVar12;

      }

      else {

        fVar9 = DAT_14039ca44;

        if ((iVar2 != 0x16572004) && (fVar9 = param_9, iVar2 != 0x16772004)) {

          *param_1 = 0.0;

          return;

        }

        if (0.0 <= param_6) {

          fVar14 = DAT_14039ca44;

          if (param_6 <= DAT_14039ca44) {

            fVar14 = param_6;

          }

        }

        else {

          fVar14 = 0.0;

        }

        if (0.0 <= param_7) {

          fVar12 = DAT_14039ca44;

          if (param_7 <= DAT_14039ca44) {

            fVar12 = param_7;

          }

        }

        else {

          fVar12 = 0.0;

        }

        if (0.0 <= param_8) {

          if (param_8 <= DAT_14039ca44) {

            fVar11 = param_8;

          }

        }

        else {

          fVar11 = 0.0;

        }

        fVar10 = 0.0;

        if ((0.0 <= fVar9) && (fVar10 = DAT_14039ca44, fVar9 <= DAT_14039ca44)) {

          fVar10 = fVar9;

        }

        fVar10 = (float)thunk_FUN_1402e1d00(fVar10 * DAT_14030338c);

        fVar9 = _DAT_1403802bc;

        fVar11 = (float)thunk_FUN_1402e1d00(fVar11 * _DAT_1403802bc);

        uVar7 = (uint)(longlong)fVar11 | (int)(longlong)fVar10 << 10;

        fVar12 = (float)thunk_FUN_1402e1d00(fVar12 * fVar9);

        fVar14 = fVar14 * fVar9;

        uVar4 = (uint)(longlong)fVar12;

      }

      fVar9 = (float)thunk_FUN_1402e1d00(fVar14);

      *param_1 = (float)((uint)(longlong)fVar9 | (uVar4 | uVar7 << 10) << 10);

    }

    else if (param_2 == 4) {

      fVar9 = param_8;

      fVar14 = param_8;

      switch(*param_3 >> 0x14 & 0xf) {

      case 1:

        fVar9 = param_6;

        param_9 = DAT_14039ca44;

        param_8 = param_7;

        break;

      case 2:

        fVar9 = param_6;

        param_8 = param_7;

        break;

      case 3:

        fVar9 = param_9;

        param_9 = param_8;

        fVar14 = param_7;

        param_8 = param_6;

        break;

      case 4:

        param_9 = DAT_14039ca44;

        fVar14 = param_6;

        param_8 = param_7;

        break;

      case 5:

        fVar14 = param_6;

        param_8 = param_7;

        break;

      case 6:

        fVar9 = param_9;

        param_9 = param_6;

        fVar14 = param_7;

        break;

      default:

        param_8 = 0.0;

        fVar9 = 0.0;

        param_9 = 0.0;

        fVar14 = 0.0;

      }

      uVar4 = *param_3 >> 0x18 & 0xf;

      if (uVar4 == 8) {

        if (0.0 <= fVar9) {

          fVar10 = DAT_14039ca44;

          if (fVar9 <= DAT_14039ca44) {

            fVar10 = fVar9;

          }

        }

        else {

          fVar10 = 0.0;

        }

        fVar9 = (float)thunk_FUN_1402e1d00(fVar10 * DAT_14030ec38);

        *(short *)param_1 = (short)(int)fVar9;

        if (0.0 <= param_8) {

          fVar9 = fVar11;

          if (param_8 <= fVar11) {

            fVar9 = param_8;

          }

        }

        else {

          fVar9 = 0.0;

        }

        fVar9 = (float)thunk_FUN_1402e1d00(fVar9 * fVar12);

        *(short *)((longlong)param_1 + 2) = (short)(int)fVar9;

        if (0.0 <= fVar14) {

          fVar9 = fVar11;

          if (fVar14 <= fVar11) {

            fVar9 = fVar14;

          }

        }

        else {

          fVar9 = 0.0;

        }

        fVar9 = (float)thunk_FUN_1402e1d00(fVar9 * fVar12);

        *(short *)(param_1 + 1) = (short)(int)fVar9;

        if (*(char *)((longlong)param_3 + 5) != '\b') {

          return;

        }

        fVar9 = 0.0;

        if ((0.0 <= param_9) && (fVar9 = fVar11, param_9 <= fVar11)) {

          fVar9 = param_9;

        }

        fVar9 = (float)thunk_FUN_1402e1d00(fVar9 * fVar12);

        uVar3 = (undefined2)(int)fVar9;

      }

      else {

        if (uVar4 != 10) {

          if (uVar4 != 0xb) {

            return;

          }

          *param_1 = fVar9;

          param_1[1] = param_8;

          param_1[2] = fVar14;

          if (*(char *)((longlong)param_3 + 5) != '\x10') {

            return;

          }

          param_1[3] = param_9;

          return;

        }

        uVar3 = FUN_1402a28f0();

        *(undefined2 *)param_1 = uVar3;

        uVar3 = FUN_1402a28f0(param_8);

        *(undefined2 *)((longlong)param_1 + 2) = uVar3;

        uVar3 = FUN_1402a28f0(fVar14);

        *(undefined2 *)(param_1 + 1) = uVar3;

        if (*(char *)((longlong)param_3 + 5) != '\b') {

          return;

        }

        uVar3 = FUN_1402a28f0(param_9);

      }

      *(undefined2 *)((longlong)param_1 + 6) = uVar3;

    }

  }

  return;

}




