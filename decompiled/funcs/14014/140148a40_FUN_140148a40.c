// Address: 0x140148a40
// Ghidra name: FUN_140148a40
// ============ 0x140148a40 FUN_140148a40 (size=864) ============


ulonglong FUN_140148a40(byte *param_1,int param_2,int param_3,float param_4,float param_5,

                       float param_6,float param_7)



{

  uint uVar1;

  double dVar2;

  double dVar3;

  double dVar4;

  double dVar5;

  float fVar6;

  float fVar7;

  char cVar8;

  byte bVar9;

  ulonglong uVar10;

  uint uVar11;

  char *pcVar12;

  float *pfVar13;

  undefined8 uVar14;

  float fVar15;

  float local_58;

  float fStack_54;

  float fStack_50;

  float fStack_4c;

  

  cVar8 = FUN_1401489c0();

  fVar7 = DAT_14039ca44;

  fVar6 = DAT_14030a2d0;

  if (((cVar8 == '\0') || (uVar1 = *(uint *)(param_1 + 4), uVar1 == 0)) ||

     (*(longlong *)(param_1 + 0x18) == 0)) {

    pcVar12 = "surface";

  }

  else if ((param_2 < 0) || (*(int *)(param_1 + 8) <= param_2)) {

    pcVar12 = "x";

  }

  else {

    if ((-1 < param_3) && (param_3 < *(int *)(param_1 + 0xc))) {

      if ((uVar1 & 0xf0000000) == 0x10000000) {

        if ((byte)uVar1 < 5) {

          if (0.0 <= param_4) {

            fVar15 = DAT_14039ca44;

            if (param_4 <= DAT_14039ca44) {

              fVar15 = param_4;

            }

          }

          else {

            fVar15 = 0.0;

          }

          dVar2 = (double)thunk_FUN_1402e1d50(SUB84((double)(fVar15 * DAT_14030a2d0),0));

          if (0.0 <= param_5) {

            fVar15 = fVar7;

            if (param_5 <= fVar7) {

              fVar15 = param_5;

            }

          }

          else {

            fVar15 = 0.0;

          }

          dVar3 = (double)thunk_FUN_1402e1d50(SUB84((double)(fVar15 * fVar6),0));

          if (0.0 <= param_6) {

            fVar15 = fVar7;

            if (param_6 <= fVar7) {

              fVar15 = param_6;

            }

          }

          else {

            fVar15 = 0.0;

          }

          dVar4 = (double)thunk_FUN_1402e1d50(SUB84((double)(fVar15 * fVar6),0));

          fVar15 = 0.0;

          if ((0.0 <= param_7) && (fVar15 = fVar7, param_7 <= fVar7)) {

            fVar15 = param_7;

          }

          dVar5 = (double)thunk_FUN_1402e1d50(SUB84((double)(fVar15 * fVar6),0));

          cVar8 = FUN_140148da0(param_1,param_2,param_3,(int)dVar2 & 0xff,(int)dVar3 & 0xff,

                                (char)(int)dVar4,(int)dVar5 & 0xff);

          return (ulonglong)(cVar8 != '\0');

        }

        if (((*param_1 & 2) != 0) && (uVar10 = FUN_140146f20(param_1), (char)uVar10 == '\0')) {

          return uVar10;

        }

        uVar1 = *(uint *)(param_1 + 4);

        if ((uVar1 == 0) || ((uVar1 & 0xf0000000) == 0x10000000)) {

          uVar11 = uVar1 & 0xff;

        }

        else if ((((uVar1 == 0x32595559) || (uVar1 == 0x59565955)) || (uVar1 == 0x55595659)) ||

                (uVar1 == 0x30313050)) {

          uVar11 = 2;

        }

        else {

          uVar11 = 1;

        }

        fStack_54 = param_5;

        fStack_50 = param_6;

        pfVar13 = (float *)((longlong)(*(int *)(param_1 + 0x10) * param_3) +

                            (longlong)(int)(uVar11 * param_2) + *(longlong *)(param_1 + 0x18));

        fStack_4c = param_7;

        local_58 = param_4;

        if (uVar1 == 0x1b208010) {

          bVar9 = 1;

          *pfVar13 = param_4;

          pfVar13[1] = param_5;

          pfVar13[2] = param_6;

          pfVar13[3] = param_7;

        }

        else {

          uVar14 = 0x120005a0;

          if (*(int *)(param_1 + 0x40) == 0x12000500) {

            uVar14 = 0x12000500;

          }

          bVar9 = FUN_140144d60(1,1,0x1b208010,uVar14,0,&local_58,0x10,uVar1,

                                *(int *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x34),pfVar13,

                                *(int *)(param_1 + 0x10));

        }

        if ((*param_1 & 2) != 0) {

          FUN_1401489e0(param_1);

          return (ulonglong)bVar9;

        }

      }

      else {

        bVar9 = FUN_14012e850("That operation is not supported");

      }

      return (ulonglong)bVar9;

    }

    pcVar12 = "y";

  }

  uVar10 = FUN_14012e850("Parameter \'%s\' is invalid",pcVar12);

  return uVar10;

}




