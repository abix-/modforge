// Address: 0x14020c720
// Ghidra name: FUN_14020c720
// ============ 0x14020c720 FUN_14020c720 (size=1301) ============


undefined4 FUN_14020c720(uint *param_1)



{

  ushort *puVar1;

  uint uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 *puVar5;

  int iVar6;

  undefined4 *puVar7;

  uint uVar8;

  undefined4 uVar9;

  undefined4 *puVar10;

  undefined8 uVar11;

  ulonglong uVar12;

  undefined4 *puVar13;

  longlong lVar14;

  uint uVar15;

  int iVar16;

  ulonglong uVar17;

  ushort uVar18;

  char *pcVar19;

  int iVar20;

  int iVar21;

  int iVar22;

  ulonglong uVar23;

  undefined1 local_38 [16];

  

  iVar21 = -1;

  _guard_check_icall();

  if (param_1 == (uint *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140350318);

    return 0;

  }

  if (*param_1 < 0x88) {

    FUN_14012e850("Invalid desc, should be initialized with SDL_INIT_INTERFACE()");

    return 0;

  }

  puVar10 = (undefined4 *)FUN_1401841a0(1,0x110);

  if (puVar10 == (undefined4 *)0x0) {

    FUN_14020d110(0);

    return 0;

  }

  uVar11 = *(undefined8 *)(param_1 + 2);

  *(undefined8 *)(puVar10 + 10) = *(undefined8 *)param_1;

  *(undefined8 *)(puVar10 + 0xc) = uVar11;

  uVar11 = *(undefined8 *)(param_1 + 6);

  uVar23 = 0;

  *(undefined8 *)(puVar10 + 0xe) = *(undefined8 *)(param_1 + 4);

  *(undefined8 *)(puVar10 + 0x10) = uVar11;

  uVar11 = *(undefined8 *)(param_1 + 10);

  *(undefined8 *)(puVar10 + 0x12) = *(undefined8 *)(param_1 + 8);

  *(undefined8 *)(puVar10 + 0x14) = uVar11;

  uVar11 = *(undefined8 *)(param_1 + 0xe);

  *(undefined8 *)(puVar10 + 0x16) = *(undefined8 *)(param_1 + 0xc);

  *(undefined8 *)(puVar10 + 0x18) = uVar11;

  uVar11 = *(undefined8 *)(param_1 + 0x12);

  *(undefined8 *)(puVar10 + 0x1a) = *(undefined8 *)(param_1 + 0x10);

  *(undefined8 *)(puVar10 + 0x1c) = uVar11;

  uVar11 = *(undefined8 *)(param_1 + 0x16);

  *(undefined8 *)(puVar10 + 0x1e) = *(undefined8 *)(param_1 + 0x14);

  *(undefined8 *)(puVar10 + 0x20) = uVar11;

  uVar11 = *(undefined8 *)(param_1 + 0x1a);

  *(undefined8 *)(puVar10 + 0x22) = *(undefined8 *)(param_1 + 0x18);

  *(undefined8 *)(puVar10 + 0x24) = uVar11;

  uVar8 = param_1[0x1d];

  uVar15 = param_1[0x1e];

  uVar2 = param_1[0x1f];

  puVar10[0x26] = param_1[0x1c];

  puVar10[0x27] = uVar8;

  puVar10[0x28] = uVar15;

  puVar10[0x29] = uVar2;

  *(undefined8 *)(puVar10 + 0x2a) = *(undefined8 *)(param_1 + 0x20);

  pcVar19 = *(char **)(puVar10 + 0x14);

  *(undefined8 *)(puVar10 + 0x16) = 0;

  *(undefined8 *)(puVar10 + 0x18) = 0;

  if (pcVar19 == (char *)0x0) {

    switch(*(undefined2 *)(puVar10 + 0xb)) {

    case 1:

      pcVar19 = "Virtual Controller";

      break;

    case 2:

      pcVar19 = "Virtual Wheel";

      break;

    case 3:

      pcVar19 = "Virtual Arcade Stick";

      break;

    case 4:

      pcVar19 = "Virtual Flight Stick";

      break;

    case 5:

      pcVar19 = "Virtual Dance Pad";

      break;

    case 6:

      pcVar19 = "Virtual Guitar";

      break;

    case 7:

      pcVar19 = "Virtual Drum Kit";

      break;

    case 8:

      pcVar19 = "Virtual Arcade Pad";

      break;

    case 9:

      pcVar19 = "Virtual Throttle";

      break;

    default:

      pcVar19 = "Virtual Joystick";

    }

  }

  uVar11 = FUN_14012f0d0(pcVar19);

  *(undefined8 *)(puVar10 + 2) = uVar11;

  iVar22 = -1;

  if (*(short *)(puVar10 + 0xb) == 1) {

    if ((puVar10[0x11] == 0) &&

       (uVar12 = uVar23, uVar17 = uVar23, *(ushort *)((longlong)puVar10 + 0x36) != 0)) {

      do {

        if (0x1f < (uint)uVar12) break;

        uVar15 = (uint)uVar12 + 1;

        uVar8 = 1 << ((byte)uVar12 & 0x1f) | (uint)uVar17;

        puVar10[0x11] = uVar8;

        uVar12 = (ulonglong)uVar15;

        uVar17 = (ulonglong)uVar8;

      } while ((int)uVar15 < (int)(uint)*(ushort *)((longlong)puVar10 + 0x36));

    }

    uVar8 = puVar10[0x12];

    if (uVar8 == 0) {

      uVar18 = *(ushort *)(puVar10 + 0xd);

      uVar8 = 0;

      if (1 < uVar18) {

        uVar8 = 3;

        puVar10[0x12] = 3;

      }

      if (3 < uVar18) {

        uVar8 = uVar8 | 0xc;

        puVar10[0x12] = uVar8;

      }

      if (5 < uVar18) {

        uVar8 = uVar8 | 0x30;

        puVar10[0x12] = uVar8;

      }

    }

    uVar12 = uVar23;

    uVar17 = uVar23;

    iVar22 = -1;

    iVar16 = -1;

    iVar6 = -1;

    if (*(ushort *)(puVar10 + 0xd) != 0) {

      do {

        iVar21 = iVar6;

        iVar22 = iVar16;

        iVar16 = (int)uVar17;

        uVar15 = (uint)uVar12;

        if (5 < (int)uVar15) break;

        iVar6 = iVar22;

        if ((uVar8 >> (uVar15 & 0x1f) & 1) != 0) {

          uVar17 = (ulonglong)(iVar16 + 1);

          iVar20 = iVar16;

          if (uVar15 != 4) {

            iVar20 = iVar21;

          }

          iVar6 = iVar16;

          iVar21 = iVar20;

          if (uVar15 != 5) {

            iVar6 = iVar22;

          }

        }

        iVar22 = iVar6;

        uVar12 = (ulonglong)(uVar15 + 1);

        iVar16 = iVar22;

        iVar6 = iVar21;

      } while ((int)uVar17 < (int)(uint)*(ushort *)(puVar10 + 0xd));

    }

  }

  uVar18 = 0;

  puVar13 = (undefined4 *)

            FUN_140157780(local_38,0xff,*(undefined2 *)(puVar10 + 0xc),

                          *(undefined2 *)((longlong)puVar10 + 0x32),0,0,pcVar19,0x76,

                          *(undefined1 *)(puVar10 + 0xb));

  uVar9 = puVar13[1];

  uVar3 = puVar13[2];

  uVar4 = puVar13[3];

  puVar10[5] = *puVar13;

  puVar10[6] = uVar9;

  puVar10[7] = uVar3;

  puVar10[8] = uVar4;

  if (*(short *)(puVar10 + 0xd) == 0) {

LAB_14020ca13:

    if (*(short *)((longlong)puVar10 + 0x36) != 0) {

      lVar14 = FUN_1401841a0(*(short *)((longlong)puVar10 + 0x36),1);

      *(longlong *)(puVar10 + 0x30) = lVar14;

      if (lVar14 == 0) goto LAB_14020cb6b;

    }

    if (*(short *)((longlong)puVar10 + 0x3a) != 0) {

      lVar14 = FUN_1401841a0(*(short *)((longlong)puVar10 + 0x3a),1);

      *(longlong *)(puVar10 + 0x32) = lVar14;

      if (lVar14 == 0) goto LAB_14020cb6b;

    }

    if (*(short *)(puVar10 + 0xe) != 0) {

      lVar14 = FUN_1401841a0(*(short *)(puVar10 + 0xe),8);

      *(longlong *)(puVar10 + 0x34) = lVar14;

      if (lVar14 == 0) goto LAB_14020cb6b;

    }

    if (*(short *)(puVar10 + 0xf) != 0) {

      if (*(longlong *)(param_1 + 0xc) == 0) {

        FUN_14020d110(puVar10);

        FUN_14012e850("desc missing touchpad descriptions");

        return 0;

      }

      lVar14 = FUN_1401841a0(*(short *)(puVar10 + 0xf),0x10);

      *(longlong *)(puVar10 + 0x36) = lVar14;

      if (lVar14 == 0) goto LAB_14020cb6b;

      if (*(short *)(puVar10 + 0xf) != 0) {

        do {

          uVar12 = (ulonglong)uVar18;

          puVar1 = (ushort *)(*(longlong *)(param_1 + 0xc) + uVar12 * 8);

          *(uint *)(lVar14 + uVar12 * 0x10) = (uint)*puVar1;

          lVar14 = *(longlong *)(puVar10 + 0x36);

          uVar11 = FUN_1401841a0(*puVar1,0x10);

          *(undefined8 *)(lVar14 + 8 + uVar12 * 0x10) = uVar11;

          lVar14 = *(longlong *)(puVar10 + 0x36);

          if (*(longlong *)(lVar14 + 8 + uVar12 * 0x10) == 0) goto LAB_14020cb6b;

          uVar18 = uVar18 + 1;

        } while (uVar18 < *(ushort *)(puVar10 + 0xf));

      }

    }

    if (*(short *)((longlong)puVar10 + 0x3e) != 0) {

      if (*(longlong *)(param_1 + 0xe) == 0) {

        FUN_14020d110(puVar10);

        FUN_14012e850("desc missing sensor descriptions");

        return 0;

      }

      lVar14 = FUN_1401841a0(*(short *)((longlong)puVar10 + 0x3e),0x18);

      *(longlong *)(puVar10 + 0x38) = lVar14;

      if (lVar14 == 0) goto LAB_14020cb6b;

      if (*(short *)((longlong)puVar10 + 0x3e) != 0) {

        do {

          lVar14 = *(longlong *)(param_1 + 0xe);

          uVar18 = (short)uVar23 + 1;

          *(undefined4 *)(*(longlong *)(puVar10 + 0x38) + uVar23 * 0x18) =

               *(undefined4 *)(lVar14 + uVar23 * 8);

          *(undefined4 *)(*(longlong *)(puVar10 + 0x38) + 8 + uVar23 * 0x18) =

               *(undefined4 *)(lVar14 + 4 + uVar23 * 8);

          uVar23 = (ulonglong)uVar18;

        } while (uVar18 < *(ushort *)((longlong)puVar10 + 0x3e));

      }

    }

    uVar9 = FUN_1401aa810();

    puVar13 = DAT_1403fd260;

    *puVar10 = uVar9;

    puVar7 = puVar10;

    if (puVar13 != (undefined4 *)0x0) {

      puVar7 = *(undefined4 **)(puVar13 + 0x42);

      while (puVar5 = puVar7, puVar5 != (undefined4 *)0x0) {

        puVar13 = puVar5;

        puVar7 = *(undefined4 **)(puVar5 + 0x42);

      }

      *(undefined4 **)(puVar13 + 0x42) = puVar10;

      puVar7 = DAT_1403fd260;

    }

    DAT_1403fd260 = puVar7;

    FUN_14015a2b0(*puVar10);

    uVar9 = *puVar10;

  }

  else {

    lVar14 = FUN_1401841a0(*(short *)(puVar10 + 0xd),2);

    *(longlong *)(puVar10 + 0x2e) = lVar14;

    if (lVar14 != 0) {

      if (-1 < iVar21) {

        *(undefined2 *)(lVar14 + (longlong)iVar21 * 2) = 0x8000;

      }

      if (-1 < iVar22) {

        *(undefined2 *)(*(longlong *)(puVar10 + 0x2e) + (longlong)iVar22 * 2) = 0x8000;

      }

      goto LAB_14020ca13;

    }

LAB_14020cb6b:

    FUN_14020d110(puVar10);

    uVar9 = 0;

  }

  return uVar9;

}




