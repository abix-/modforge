// Address: 0x14018a730
// Ghidra name: FUN_14018a730
// ============ 0x14018a730 FUN_14018a730 (size=1569) ============


ulonglong FUN_14018a730(undefined8 param_1,int *param_2,undefined4 *param_3,undefined8 param_4,

                       undefined8 param_5)



{

  ushort uVar1;

  bool bVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  longlong lVar7;

  longlong lVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  ulonglong uVar11;

  int7 iVar12;

  char *pcVar13;

  int iVar14;

  ulonglong uVar15;

  int iVar16;

  int iVar17;

  int iVar18;

  int iVar19;

  int iVar20;

  int iVar21;

  int iVar22;

  int iVar23;

  int iVar24;

  int iVar25;

  int iVar26;

  int iVar27;

  int iVar28;

  int iVar29;

  int iVar30;

  int iVar31;

  undefined1 local_a8 [4];

  uint local_a4;

  uint local_a0 [2];

  ulonglong local_98;

  ulonglong local_90;

  undefined8 local_88;

  undefined8 uStack_80;

  

  uVar9 = 0;

  local_a4 = 0;

  lVar7 = FUN_14012be60();

  bVar2 = false;

  local_98 = 0;

  local_88 = 0;

  uStack_80 = 0;

  iVar20 = 0;

  iVar21 = 0;

  iVar22 = 0;

  iVar23 = 0;

  iVar24 = 0;

  iVar25 = 0;

  iVar26 = 0;

  iVar27 = 0;

  iVar16 = 0;

  iVar17 = 0;

  iVar18 = 0;

  iVar19 = 0;

  iVar28 = 0;

  iVar29 = 0;

  iVar30 = 0;

  iVar31 = 0;

  lVar8 = FUN_140142960("SDL_WAVE_CHUNK_LIMIT");

  uVar6 = 10000;

  if (lVar8 != 0) {

    iVar4 = FUN_14012ef30(lVar8,&DAT_1403396c8,local_a0);

    uVar6 = 10000;

    if (iVar4 == 1) {

      uVar6 = local_a0[0];

    }

  }

  local_90 = FUN_14012cba0(param_1);

  if ((longlong)local_90 < 0) {

    uVar9 = FUN_14012e850("Could not seek in file");

    return uVar9;

  }

  iVar4 = FUN_14018ade0(param_1,&local_98);

  if (iVar4 < 0) {

    uVar9 = FUN_14012e850("Could not read RIFF header");

    return uVar9;

  }

  if ((int)local_98 == 0x46464952) {

    cVar3 = FUN_14012c940(param_1,local_a0);

    if (cVar3 == '\0') {

      uVar9 = FUN_14012e850("Could not read RIFF form type");

      return uVar9;

    }

    if (local_a0[0] != 0x45564157) {

      uVar9 = FUN_14012e850("RIFF form type is not WAVE (not a Waveform file)");

      return uVar9;

    }

    uVar9 = local_90;

    uVar15 = local_98 >> 0x20;

  }

  else {

    uVar15 = uVar9;

    if ((int)local_98 != 0x45564157) {

      uVar9 = FUN_14012e850("Could not find RIFF or WAVE identifiers (not a Waveform file)");

      return uVar9;

    }

  }

  *(ulonglong *)(param_2 + 2) = uVar9 + 4;

  iVar4 = param_2[0x1a];

  if (iVar4 == 1) {

LAB_14018a8b5:

    bVar2 = true;

LAB_14018a8c0:

    uVar15 = uVar15 + uVar9;

  }

  else {

    if (iVar4 == 2) {

LAB_14018a8a8:

      if ((int)uVar15 != 0) goto LAB_14018a8b5;

LAB_14018a8ad:

      uVar15 = 0xffffffff;

      goto LAB_14018a8c0;

    }

    if (iVar4 == 3) goto LAB_14018a8ad;

    if (iVar4 != 4) goto LAB_14018a8a8;

    uVar15 = 0x7fffffffffffffff;

  }

  iVar4 = 0;

  iVar14 = 0;

  if ((ulonglong)(param_2[1] & 1) + (ulonglong)(uint)param_2[1] + uVar9 + 4 < uVar15) {

    while( true ) {

      if (uVar6 <= local_a4) {

        local_a4 = local_a4 + 1;

        uVar9 = FUN_14012e850("Chunk count in WAVE file exceeds limit of %u",uVar6);

        return uVar9;

      }

      local_a4 = local_a4 + 1;

      iVar5 = FUN_14018ade0(param_1,param_2);

      if (iVar5 < 0) break;

      iVar5 = *param_2;

      if (iVar5 == 0x20746d66) {

        if (iVar4 != 0x20746d66) {

          if (iVar14 == 0x61746164) {

            pcVar13 = "fmt chunk after data chunk in WAVE file";

            goto LAB_14018aa3a;

          }

          iVar20 = *param_2;

          iVar21 = param_2[1];

          iVar22 = param_2[2];

          iVar23 = param_2[3];

          iVar24 = param_2[4];

          iVar25 = param_2[5];

          iVar26 = param_2[6];

          iVar27 = param_2[7];

          iVar4 = iVar20;

        }

      }

      else if (iVar5 == 0x61746164) {

        if ((0 < lVar7) &&

           (lVar7 < (longlong)((ulonglong)(uint)param_2[1] + *(longlong *)(param_2 + 2)))) {

          param_2[1] = (int)lVar7 - (int)*(longlong *)(param_2 + 2);

        }

        if (iVar14 != 0x61746164) {

          iVar16 = *param_2;

          iVar17 = param_2[1];

          iVar18 = param_2[2];

          iVar19 = param_2[3];

          iVar28 = param_2[4];

          iVar29 = param_2[5];

          iVar30 = param_2[6];

          iVar31 = param_2[7];

          iVar14 = iVar16;

        }

      }

      else if ((iVar5 == 0x74636166) && (param_2[0x14] == 0)) {

        if (((uint)param_2[1] < 4) ||

           ((lVar8 = FUN_14012cb40(param_1,*(undefined8 *)(param_2 + 2),0),

            lVar8 != *(longlong *)(param_2 + 2) ||

            (cVar3 = FUN_14012c940(param_1,param_2 + 0x15), cVar3 == '\0')))) {

          param_2[0x14] = -1;

        }

        else {

          param_2[0x14] = 1;

        }

      }

      if (param_2[0x1b] == 1) {

        if (uVar15 < (ulonglong)(uint)param_2[1] + *(longlong *)(param_2 + 2)) goto LAB_14018aaf2;

      }

      else if (((iVar4 == 0x20746d66) && (iVar14 == 0x61746164)) &&

              ((param_2[0x14] == 1 || ((param_2[0x1c] == 4 || (param_2[0x1c] == 0))))))

      goto LAB_14018aa22;

      if (uVar15 <= (ulonglong)(param_2[1] & 1) + (ulonglong)(uint)param_2[1] +

                    *(longlong *)(param_2 + 2)) goto LAB_14018aa22;

    }

    if (param_2[0x1b] == 1) {

      pcVar13 = "Unexpected end of WAVE file";

      goto LAB_14018aa3a;

    }

  }

LAB_14018aa22:

  uVar9 = (ulonglong)(uint)param_2[1] + *(longlong *)(param_2 + 2);

  if (iVar4 != 0x20746d66) {

    pcVar13 = "Missing fmt chunk in WAVE file";

    goto LAB_14018aa3a;

  }

  if (iVar14 != 0x61746164) {

    pcVar13 = "Missing data chunk in WAVE file";

    goto LAB_14018aa3a;

  }

  if (((param_2[0x1b] == 1) && (*param_2 != 0x61746164)) && (param_2[1] != 0)) {

    uVar11 = uVar9 - 1;

    if ((0x7fffffffffffffff < uVar11) ||

       (uVar10 = FUN_14012cb40(param_1,uVar11,0), uVar10 != uVar11)) {

      pcVar13 = "Could not seek to WAVE chunk data";

      goto LAB_14018aa3a;

    }

    cVar3 = FUN_14012c840(param_1,local_a8);

    if (cVar3 == '\0') {

LAB_14018aaf2:

      pcVar13 = "RIFF size truncates chunk";

      goto LAB_14018aa3a;

    }

  }

  *param_2 = iVar20;

  param_2[1] = iVar21;

  param_2[2] = iVar22;

  param_2[3] = iVar23;

  param_2[4] = iVar24;

  param_2[5] = iVar25;

  param_2[6] = iVar26;

  param_2[7] = iVar27;

  iVar20 = FUN_14018b080(param_1,param_2,0x416);

  if (iVar20 < 0) {

LAB_14018ab40:

    pcVar13 = "Could not read data of WAVE fmt chunk";

    goto LAB_14018aa3a;

  }

  if ((uint)param_2[1] < 0xe) {

    pcVar13 = "Invalid WAVE fmt chunk length (too small)";

    goto LAB_14018aa3a;

  }

  if (*(ulonglong *)(param_2 + 6) < 0xe) goto LAB_14018ab40;

  uVar11 = FUN_14018aeb0(param_2);

  if (((char)uVar11 == '\0') || (uVar11 = FUN_14018a130(param_2,iVar17), (char)uVar11 == '\0'))

  goto LAB_14018ad39;

  FUN_14018a480(param_2);

  *param_2 = iVar16;

  param_2[1] = iVar17;

  param_2[2] = iVar18;

  param_2[3] = iVar19;

  param_2[4] = iVar28;

  param_2[5] = iVar29;

  param_2[6] = iVar30;

  param_2[7] = iVar31;

  if ((param_2[1] != 0) && (uVar11 = FUN_14018aea0(param_1,param_2), (int)uVar11 < 0))

  goto LAB_14018ad39;

  if (((ulonglong)(uint)param_2[1] != *(ulonglong *)(param_2 + 6)) &&

     ((param_2[0x1b] == 1 || (param_2[0x1b] == 2)))) {

    pcVar13 = "Could not read data of WAVE data chunk";

    goto LAB_14018aa3a;

  }

  switch(*(undefined2 *)((longlong)param_2 + 0x22)) {

  case 1:

  case 3:

    uVar11 = FUN_140189ca0(param_2,param_4,param_5);

    break;

  case 2:

    uVar11 = FUN_140189320(param_2,param_4,param_5);

    break;

  default:

    goto switchD_14018abe2_caseD_4;

  case 6:

  case 7:

    uVar11 = FUN_140188f70(param_2,param_4,param_5);

    break;

  case 0x11:

    uVar11 = FUN_140188750(param_2,param_4,param_5);

  }

  if ((char)uVar11 == '\0') {

LAB_14018ad39:

    return uVar11 & 0xffffffffffffff00;

  }

switchD_14018abe2_caseD_4:

  param_3[2] = param_2[10];

  param_3[1] = (uint)*(byte *)(param_2 + 9);

  *param_3 = 0;

  uVar6 = *(ushort *)((longlong)param_2 + 0x22) - 1;

  if (uVar6 < 0x11) {

    iVar12 = (int7)(int3)(uVar6 >> 8);

    switch(uVar6) {

    case 0:

      uVar1 = *(ushort *)((longlong)param_2 + 0x32);

      if (uVar1 == 8) {

        *param_3 = 8;

        if (bVar2) {

          uVar9 = uVar15;

        }

        *(ulonglong *)(param_2 + 2) = uVar9;

        return CONCAT71(iVar12,1);

      }

      if (uVar1 != 0x10) {

        if ((uVar1 - 0x18 & 0xfffffff7) != 0) {

          uVar9 = FUN_14012e850("Unexpected %u-bit PCM data format");

          return uVar9;

        }

        *param_3 = 0x8020;

        if (bVar2) {

          uVar9 = uVar15;

        }

        *(ulonglong *)(param_2 + 2) = uVar9;

        return CONCAT71((uint7)(uint3)(uVar1 - 0x18 >> 8),1);

      }

    case 1:

    case 5:

    case 6:

    case 0x10:

      *param_3 = 0x8010;

      if (bVar2) {

        uVar9 = uVar15;

      }

      *(ulonglong *)(param_2 + 2) = uVar9;

      return CONCAT71(iVar12,1);

    case 2:

      *param_3 = 0x8120;

      if (bVar2) {

        uVar9 = uVar15;

      }

      *(ulonglong *)(param_2 + 2) = uVar9;

      return CONCAT71(iVar12,1);

    }

  }

  pcVar13 = "Unexpected data format";

LAB_14018aa3a:

  uVar9 = FUN_14012e850(pcVar13);

  return uVar9;

}




