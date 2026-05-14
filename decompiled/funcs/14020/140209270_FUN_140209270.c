// Address: 0x140209270
// Ghidra name: FUN_140209270
// ============ 0x140209270 FUN_140209270 (size=1257) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



undefined8 FUN_140209270(longlong param_1,undefined4 param_2)



{

  longlong lVar1;

  longlong lVar2;

  longlong lVar3;

  ushort uVar4;

  char cVar5;

  uint uVar6;

  int iVar7;

  undefined4 uVar8;

  longlong lVar9;

  char *pcVar10;

  undefined8 uVar11;

  ulonglong uVar12;

  longlong lVar13;

  short *psVar14;

  short sVar15;

  ushort *puVar16;

  ulonglong uVar17;

  undefined1 *puVar18;

  int *piVar19;

  longlong lVar20;

  ulonglong uVar21;

  ulonglong uVar22;

  undefined8 uStack_90;

  undefined1 auStack_88 [32];

  short local_68 [6];

  char acStack_5c [34];

  ushort local_3a;

  ushort local_38 [4];

  short asStack_30 [4];

  

  uStack_90 = 0x14020929c;

  lVar9 = FUN_14020a140(param_2);

  uStack_90 = 0x1402092ae;

  pcVar10 = (char *)FUN_1401841a0(1,0x98);

  if (pcVar10 == (char *)0x0) {

    return 0;

  }

  *(char **)(param_1 + 0x148) = pcVar10;

  uStack_90 = 0x1402092c9;

  uVar11 = FUN_140209a50(lVar9);

  *(undefined8 *)(pcVar10 + 0x90) = uVar11;

  *(longlong *)(lVar9 + 0x48) = param_1;

  if (*(char *)(lVar9 + 0x2e) != '\0') {

    DAT_1403e4ec8 = 1;

    uStack_90 = 0x1402092ef;

    cVar5 = FUN_140142940("SDL_JOYSTICK_RAWINPUT_CORRELATE_XINPUT",1);

    pcVar10[0x50] = cVar5;

    if (cVar5 != '\0') {

      uStack_90 = 0x1402092fb;

      cVar5 = FUN_140284e70();

      if ((cVar5 == '\0') || (DAT_1403fdde8 == 0)) {

        pcVar10[0x50] = '\0';

      }

    }

    pcVar10[0x55] = -1;

    uStack_90 = 0x140209319;

    FUN_14020a730(pcVar10);

  }

  *pcVar10 = *(char *)(lVar9 + 0x2e);

  pcVar10[1] = *(char *)(lVar9 + 0x2f);

  pcVar10[0x40] = '\0';

  pcVar10[0x41] = '\0';

  pcVar10[0x42] = '\0';

  pcVar10[0x43] = '\0';

  pcVar10[0x44] = -0x78;

  pcVar10[0x45] = '\0';

  pcVar10[0x46] = '\0';

  pcVar10[0x47] = '\0';

  *(undefined8 *)(pcVar10 + 8) = *(undefined8 *)(lVar9 + 0x38);

  uStack_90 = 0x140209344;

  uVar6 = (*DAT_1403ffc10)(0);

  *(uint *)(pcVar10 + 0x10) = uVar6;

  uStack_90 = 0x140209352;

  lVar9 = FUN_1401841f0((ulonglong)uVar6 << 3);

  *(longlong *)(pcVar10 + 0x18) = lVar9;

  puVar18 = auStack_88;

  if (lVar9 == 0) {

LAB_140209732:

    *(undefined8 *)(puVar18 + -8) = 0x14020973a;

    FUN_140208e20(param_1);

    return 0;

  }

  uStack_90 = 0x14020936d;

  iVar7 = (*DAT_1403ffc28)(*(undefined8 *)(pcVar10 + 8),local_68);

  if (iVar7 != 0x110000) {

    uStack_90 = 0x14020937c;

    FUN_140208e20(param_1);

    uStack_90 = 0x140209388;

    uVar11 = FUN_14012e850("Couldn\'t get device capabilities");

    return uVar11;

  }

  uVar12 = (ulonglong)local_3a * 0x48 + 0xf;

  if (uVar12 <= (ulonglong)local_3a * 0x48) {

    uVar12 = 0xffffffffffffff0;

  }

  uStack_90 = 0x1402093b8;

  uVar11 = *(undefined8 *)(pcVar10 + 8);

  lVar2 = -(uVar12 & 0xfffffffffffffff0);

  lVar9 = (longlong)local_68 + lVar2;

  *(undefined8 *)(auStack_88 + lVar2 + -8) = 0x1402093d3;

  iVar7 = (*DAT_1403ffc20)(0,lVar9,&local_3a,uVar11);

  if (iVar7 != 0x110000) {

    *(undefined8 *)(auStack_88 + lVar2 + -8) = 0x1402093e2;

    FUN_140208e20(param_1);

    *(undefined8 *)(auStack_88 + lVar2 + -8) = 0x1402093ee;

    uVar11 = FUN_14012e850("Couldn\'t get device button capabilities");

    return uVar11;

  }

  uVar12 = (ulonglong)local_38[0] * 0x48 + 0xf;

  if (uVar12 <= (ulonglong)local_38[0] * 0x48) {

    uVar12 = 0xffffffffffffff0;

  }

  *(undefined8 *)(auStack_88 + lVar2 + -8) = 0x140209414;

  uVar11 = *(undefined8 *)(pcVar10 + 8);

  lVar3 = -(uVar12 & 0xfffffffffffffff0);

  lVar1 = (longlong)local_68 + lVar3 + lVar2;

  *(undefined8 *)(auStack_88 + lVar3 + lVar2 + -8) = 0x14020942f;

  iVar7 = (*DAT_1403ffc18)(0,lVar1,local_38,uVar11);

  uVar4 = local_38[0];

  if (iVar7 != 0x110000) {

    *(undefined8 *)(auStack_88 + lVar3 + lVar2 + -8) = 0x14020943e;

    FUN_140208e20(param_1);

    *(undefined8 *)(auStack_88 + lVar3 + lVar2 + -8) = 0x14020944a;

    uVar11 = FUN_14012e850("Couldn\'t get device value capabilities");

    return uVar11;

  }

  *(undefined8 *)(auStack_88 + lVar3 + lVar2 + -8) = 0x140209468;

  FUN_140190720(lVar1,uVar4,0x48,&LAB_14020acf0);

  if (local_3a != 0) {

    puVar16 = (ushort *)(&stack0xffffffffffffffde + lVar2);

    uVar12 = (ulonglong)local_3a;

    do {

      if (puVar16[-0x23] == 9) {

        if ((char)puVar16[-0x1d] == '\0') {

          *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;

        }

        else {

          *(int *)(param_1 + 0x70) =

               *(int *)(param_1 + 0x70) + ((uint)*puVar16 - (uint)puVar16[-1]) + 1;

        }

      }

      puVar16 = puVar16 + 0x24;

      uVar12 = uVar12 - 1;

    } while (uVar12 != 0);

  }

  iVar7 = *(int *)(param_1 + 0x70);

  uVar12 = 0;

  if (0 < iVar7) {

    *(undefined8 *)(auStack_88 + lVar3 + lVar2 + -8) = 0x1402094d2;

    lVar13 = FUN_1401841f0((longlong)iVar7 * 2);

    *(longlong *)(pcVar10 + 0x20) = lVar13;

    puVar18 = auStack_88 + lVar3 + lVar2;

    if (lVar13 == 0) goto LAB_140209732;

    uVar22 = uVar12;

    uVar21 = uVar12;

    if (local_3a != 0) {

      do {

        lVar13 = lVar9 + uVar21 * 0x48;

        if (*(short *)(lVar9 + uVar21 * 0x48) == 9) {

          if (*(char *)(lVar13 + 0xc) == '\0') {

            *(undefined2 *)(*(longlong *)(pcVar10 + 0x20) + uVar22 * 2) =

                 *(undefined2 *)(lVar13 + 0x44);

            uVar22 = uVar22 + 1;

          }

          else {

            iVar7 = ((uint)*(ushort *)(lVar13 + 0x46) - (uint)*(ushort *)(lVar13 + 0x44)) + 1;

            if (0 < iVar7) {

              uVar17 = uVar12;

              lVar20 = uVar22 * 2;

              do {

                sVar15 = (short)uVar17;

                uVar22 = uVar22 + 1;

                uVar6 = (int)uVar17 + 1;

                uVar17 = (ulonglong)uVar6;

                *(short *)(lVar20 + *(longlong *)(pcVar10 + 0x20)) =

                     sVar15 + *(short *)(lVar13 + 0x44);

                lVar20 = lVar20 + 2;

              } while ((int)uVar6 < iVar7);

            }

          }

        }

        uVar6 = (int)uVar21 + 1;

        uVar21 = (ulonglong)uVar6;

      } while (uVar6 < local_3a);

    }

  }

  piVar19 = (int *)(param_1 + 0x70);

  if ((*pcVar10 != '\0') && (*piVar19 == 10)) {

    pcVar10[0x38] = '\x01';

    *piVar19 = *piVar19 + 1;

  }

  if (local_38[0] != 0) {

    psVar14 = (short *)((longlong)asStack_30 + lVar3 + lVar2);

    uVar22 = (ulonglong)local_38[0];

    do {

      if (((char)psVar14[-0x16] == '\0') && ((pcVar10[0x39] == '\0' || (*psVar14 != 0x32)))) {

        if (*psVar14 == 0x39) {

          *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;

        }

        else if ((*pcVar10 == '\0') || (*psVar14 != 0x32)) {

          *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;

        }

      }

      psVar14 = psVar14 + 0x24;

      uVar22 = uVar22 - 1;

    } while (uVar22 != 0);

  }

  iVar7 = *(int *)(param_1 + 0x44);

  if (0 < iVar7) {

    *(undefined8 *)(auStack_88 + lVar3 + lVar2 + -8) = 0x1402095e4;

    lVar9 = FUN_1401841f0((longlong)iVar7 * 2);

    *(longlong *)(pcVar10 + 0x28) = lVar9;

    puVar18 = auStack_88 + lVar3 + lVar2;

    if (lVar9 == 0) goto LAB_140209732;

    uVar22 = uVar12;

    uVar21 = uVar12;

    if (local_38[0] != 0) {

      do {

        lVar9 = uVar22 * 0x48 + lVar1;

        if ((*(char *)(lVar9 + 0xc) == '\0') && (*(short *)(lVar9 + 0x38) != 0x39)) {

          if ((*pcVar10 == '\0') || (*(short *)(lVar9 + 0x38) != 0x32)) {

            *(undefined2 *)(uVar21 + *(longlong *)(pcVar10 + 0x28)) = *(undefined2 *)(lVar9 + 0x44);

            uVar21 = uVar21 + 2;

          }

          else {

            pcVar10[0x39] = '\x01';

            *(undefined2 *)(pcVar10 + 0x3a) = *(undefined2 *)(lVar9 + 0x44);

          }

        }

        uVar6 = (int)uVar22 + 1;

        uVar22 = (ulonglong)uVar6;

      } while (uVar6 < local_38[0]);

    }

  }

  if (pcVar10[0x39] != '\0') {

    *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 2;

  }

  iVar7 = *(int *)(param_1 + 0x60);

  if (0 < iVar7) {

    *(undefined8 *)(auStack_88 + lVar3 + lVar2 + -8) = 0x140209675;

    lVar9 = FUN_1401841f0((longlong)iVar7 * 2);

    *(longlong *)(pcVar10 + 0x30) = lVar9;

    puVar18 = auStack_88 + lVar3 + lVar2;

    if (lVar9 == 0) goto LAB_140209732;

    uVar22 = uVar12;

    if (local_38[0] != 0) {

      do {

        lVar9 = uVar22 * 0x48;

        if ((*(char *)(lVar9 + 0xc + lVar1) == '\0') && (*(short *)(lVar9 + 0x38 + lVar1) == 0x39))

        {

          *(undefined2 *)(uVar12 + *(longlong *)(pcVar10 + 0x30)) =

               *(undefined2 *)(lVar9 + 0x44 + lVar1);

          uVar12 = uVar12 + 2;

        }

        uVar6 = (int)uVar22 + 1;

        uVar22 = (ulonglong)uVar6;

      } while (uVar6 < local_38[0]);

    }

  }

  if (*pcVar10 != '\0') {

    *(undefined8 *)(auStack_88 + lVar3 + lVar2 + -8) = 0x1402096e0;

    uVar8 = FUN_140158c10(param_1);

    *(undefined8 *)(auStack_88 + lVar3 + lVar2 + -8) = 0x1402096f1;

    FUN_140175280(uVar8,"SDL.joystick.cap.rumble",1);

    if (*pcVar10 != '\0') {

      *(undefined8 *)(auStack_88 + lVar3 + lVar2 + -8) = 0x1402096fe;

      uVar8 = FUN_140158c10(param_1);

      *(undefined8 *)(auStack_88 + lVar3 + lVar2 + -8) = 0x14020970f;

      FUN_140175280(uVar8,"SDL.joystick.cap.rumble",1);

      if (pcVar10[1] != '\0') {

        *(undefined8 *)(auStack_88 + lVar3 + lVar2 + -8) = 0x14020971d;

        uVar8 = FUN_140158c10(param_1);

        *(undefined8 *)(auStack_88 + lVar3 + lVar2 + -8) = 0x14020972e;

        FUN_140175280(uVar8,"SDL.joystick.cap.trigger_rumble",1);

      }

    }

  }

  return 1;

}




