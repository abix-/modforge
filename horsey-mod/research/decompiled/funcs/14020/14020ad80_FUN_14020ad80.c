// Address: 0x14020ad80
// Ghidra name: FUN_14020ad80
// ============ 0x14020ad80 FUN_14020ad80 (size=1420) ============


void FUN_14020ad80(longlong param_1)



{

  uint uVar1;

  undefined1 uVar2;

  longlong lVar3;

  longlong lVar4;

  bool bVar5;

  char cVar6;

  byte bVar7;

  ulonglong uVar8;

  undefined8 uVar9;

  char cVar10;

  undefined8 uVar11;

  uint uVar12;

  byte local_res8 [8];

  ulonglong local_res10;

  int local_res18;

  uint local_res20;

  undefined1 local_68 [40];

  

  lVar3 = *(longlong *)(param_1 + 0x148);

  bVar5 = false;

  uVar1 = *(int *)(param_1 + 0x44) - 2;

  uVar12 = *(int *)(param_1 + 0x70) - 1;

  local_res18 = *(int *)(param_1 + 0x44) + -1;

  local_res20 = uVar1;

  FUN_140209f90(local_68,*(undefined8 *)(lVar3 + 0x40));

  uVar2 = *(undefined1 *)(lVar3 + 0x51);

  FUN_14020b310();

  if ((((*(char *)(lVar3 + 0x56) != '\0') && (*(short *)(param_1 + 0xa0) == 0)) &&

      (*(short *)(param_1 + 0xa2) == 0)) &&

     ((*(short *)(param_1 + 0xb8) == 0 && (*(short *)(param_1 + 0xba) == 0)))) {

    uVar11 = *(undefined8 *)(lVar3 + 0x60);

    cVar6 = FUN_14020b8a0(local_68,uVar11,uVar2);

    if (cVar6 == '\0') {

      bVar7 = *(char *)(lVar3 + 0x59) + 1;

      *(byte *)(lVar3 + 0x59) = bVar7;

      if (4 < bVar7) {

        FUN_14020a890(uVar11);

        *(undefined1 *)(lVar3 + 0x56) = 0;

        *(undefined1 *)(lVar3 + 0x58) = 0;

        if (*(char *)(lVar3 + 0x38) != '\0') {

          FUN_14015ad00(0,param_1,uVar12 & 0xff,0);

        }

      }

    }

    else {

      *(undefined1 *)(lVar3 + 0x59) = 0;

    }

  }

  uVar11 = 0;

  if (*(char *)(lVar3 + 0x56) == '\0') {

    cVar10 = '\0';

    cVar6 = FUN_14020a8f0();

    if (cVar6 != '\0') {

      local_res8[0] = 0;

      local_res10 = 0;

      cVar6 = FUN_14020a160(local_68,local_res8,&local_res10,uVar2);

      if (cVar6 != '\0') {

        bVar7 = local_res8[0];

        if ((*(char *)(lVar3 + 0x58) == '\0') || (*(ulonglong *)(lVar3 + 0x60) != local_res10)) {

          *(ulonglong *)(lVar3 + 0x60) = local_res10;

LAB_14020af2c:

          cVar10 = '\x01';

        }

        else {

          if (*(byte *)(lVar3 + 0x57) + 1 != (uint)local_res8[0]) goto LAB_14020af2c;

          cVar10 = *(char *)(lVar3 + 0x58) + '\x01';

          if (cVar10 == '\x02') {

            *(undefined1 *)(lVar3 + 0x56) = 1;

            bVar5 = true;

            FUN_14020a8a0(*(ulonglong *)(lVar3 + 0x60),lVar3);

            if (DAT_1403fd1c0 == param_1) {

              DAT_1403fd1c0 = 0;

            }

            if (DAT_1403fd1c8 == param_1) {

              DAT_1403fd1c8 = 0;

              *(byte *)(lVar3 + 0x57) = bVar7;

              *(undefined1 *)(lVar3 + 0x58) = 2;

              goto LAB_14020af3c;

            }

          }

        }

        *(byte *)(lVar3 + 0x57) = bVar7;

      }

    }

    *(char *)(lVar3 + 0x58) = cVar10;

  }

  else {

    bVar5 = true;

  }

LAB_14020af3c:

  if (*(char *)(lVar3 + 0x50) != '\0') {

    FUN_14020b5a0();

    if (*(char *)(lVar3 + 0x51) == '\0') {

LAB_14020afbf:

      cVar10 = '\0';

      cVar6 = FUN_14020a920();

      if (cVar6 != '\0') {

        local_res8[0] = 0;

        local_res10 = local_res10 & 0xffffffffffffff00;

        cVar6 = FUN_14020a290(local_68,local_res8,&local_res10);

        if (cVar6 != '\0') {

          bVar7 = local_res8[0];

          if ((*(char *)(lVar3 + 0x53) == '\0') || (*(char *)(lVar3 + 0x55) != (char)local_res10)) {

            *(char *)(lVar3 + 0x55) = (char)local_res10;

LAB_14020b06c:

            cVar10 = '\x01';

          }

          else {

            if (*(byte *)(lVar3 + 0x52) + 1 != (uint)local_res8[0]) goto LAB_14020b06c;

            cVar10 = *(char *)(lVar3 + 0x53) + '\x01';

            if (cVar10 == '\x02') {

              *(undefined1 *)(lVar3 + 0x51) = 1;

              bVar5 = true;

              FUN_14020a8d0();

              if (DAT_1403fd1c0 == param_1) {

                DAT_1403fd1c0 = 0;

              }

              if (DAT_1403fd1c8 == param_1) {

                DAT_1403fd1c8 = 0;

                *(byte *)(lVar3 + 0x52) = bVar7;

                *(undefined1 *)(lVar3 + 0x53) = 2;

                goto LAB_14020b07c;

              }

            }

          }

          *(byte *)(lVar3 + 0x52) = bVar7;

        }

      }

      *(char *)(lVar3 + 0x53) = cVar10;

    }

    else {

      if ((*(short *)(param_1 + 0xa0) == 0) && (*(short *)(param_1 + 0xa2) == 0)) {

        uVar8 = (ulonglong)*(byte *)(lVar3 + 0x55);

        cVar6 = FUN_14020b9f0(local_68,uVar8);

        if (cVar6 == '\0') {

          bVar7 = *(char *)(lVar3 + 0x54) + 1;

          *(byte *)(lVar3 + 0x54) = bVar7;

          if (4 < bVar7) {

            FUN_14020a8b0(uVar8 & 0xff);

            *(undefined1 *)(lVar3 + 0x51) = 0;

            *(undefined1 *)(lVar3 + 0x53) = 0;

            if (*(char *)(lVar3 + 0x38) != '\0') {

              FUN_14015ad00(0,param_1,uVar12 & 0xff,0);

            }

          }

        }

        else {

          *(undefined1 *)(lVar3 + 0x54) = 0;

        }

      }

      if (*(char *)(lVar3 + 0x51) == '\0') goto LAB_14020afbf;

      bVar5 = true;

    }

LAB_14020b07c:

    if ((*(char *)(lVar3 + 0x50) != '\0') && (*(char *)(lVar3 + 0x51) != '\0')) {

      FUN_14020b5a0();

      uVar8 = (ulonglong)*(byte *)(lVar3 + 0x55);

      if ((&DAT_1403fd1e2)[uVar8 * 0x18] != '\0') {

        if ((*(char *)(lVar3 + 0x38) != '\0') || (uVar9 = uVar11, *(char *)(lVar3 + 0x39) != '\0'))

        {

          uVar9 = FUN_140149300();

        }

        if (*(char *)(lVar3 + 0x38) != '\0') {

          FUN_14015ad00(uVar9,param_1,uVar12 & 0xff,

                        (byte)((ushort)(&DAT_1403fd1d4)[(ulonglong)*(byte *)(lVar3 + 0x55) * 0xc] >>

                              10) & 1);

        }

        if (*(char *)(lVar3 + 0x39) != '\0') {

          FUN_14015aab0(uVar9,param_1,(undefined1)local_res20,

                        (ushort)(byte)(&DAT_1403fd1d6)[(ulonglong)*(byte *)(lVar3 + 0x55) * 0x18] *

                        0x101 + -0x8000);

          FUN_14015aab0(uVar9,param_1,(undefined1)local_res18,

                        (ushort)(byte)(&DAT_1403fd1d7)[(ulonglong)*(byte *)(lVar3 + 0x55) * 0x18] *

                        0x101 + -0x8000);

        }

        cVar6 = (&DAT_1403fd1e0)[uVar8 * 0x18];

        if (cVar6 != '\0') {

          if (cVar6 == '\x01') {

            uVar11 = 3;

          }

          else if (cVar6 != -1) {

            uVar11 = 1;

          }

        }

        cVar6 = (&DAT_1403fd1e1)[uVar8 * 0x18];

        if (cVar6 == '\0') {

          FUN_14015af40(param_1,uVar11,10);

        }

        else if (cVar6 == '\x01') {

          FUN_14015af40(param_1,uVar11,0x28);

        }

        else if (cVar6 == '\x02') {

          FUN_14015af40(param_1,uVar11,0x46);

        }

        else {

          FUN_14015af40(param_1,uVar11,100);

        }

        goto LAB_14020b2ac;

      }

    }

  }

  if ((*(char *)(lVar3 + 0x56) != '\0') && (FUN_14020b310(), *(char *)(lVar3 + 0x56) != '\0')) {

    lVar4 = *(longlong *)(lVar3 + 0x60);

    if ((*(char *)(lVar3 + 0x38) != '\0') || (*(char *)(lVar3 + 0x39) != '\0')) {

      uVar11 = FUN_140149300();

    }

    if (*(char *)(lVar3 + 0x38) != '\0') {

      FUN_14015ad00(uVar11,param_1,uVar12 & 0xff,*(uint *)(lVar4 + 0x10) >> 0x1e & 0xffffff01);

    }

    if (*(char *)(lVar3 + 0x39) != '\0') {

      FUN_14015aab0(uVar11,param_1,uVar1 & 0xff,

                    CONCAT22(0xffff,-0x8000 - (short)(int)(*(double *)(lVar4 + 0x18) * DAT_140350300

                                                          )));

      FUN_14015aab0(uVar11,param_1,(undefined1)local_res18,

                    -0x8000 - (short)(int)(*(double *)(lVar4 + 0x20) * DAT_140350300));

    }

  }

LAB_14020b2ac:

  if ((!bVar5) &&

     ((DAT_1403fd1c0 == 0 ||

      ((*(ulonglong *)(lVar3 + 0x48) != 0 &&

       ((DAT_1403fd1b8 == 0 || (DAT_1403fd1b8 <= *(ulonglong *)(lVar3 + 0x48))))))))) {

    DAT_1403fd1b8 = *(ulonglong *)(lVar3 + 0x48);

    DAT_1403fd1c0 = param_1;

  }

  return;

}




