// Address: 0x1402d6e1c
// Ghidra name: FUN_1402d6e1c
// ============ 0x1402d6e1c FUN_1402d6e1c (size=634) ============


undefined8 FUN_1402d6e1c(undefined8 *param_1)



{

  byte bVar1;

  longlong *plVar2;

  char cVar3;

  int iVar4;

  undefined8 *puVar5;

  ulonglong uVar6;

  char *pcVar7;

  byte *pbVar8;

  longlong lVar9;

  byte bVar10;

  undefined8 *puVar11;

  byte *pbVar12;

  ulonglong uVar13;

  bool bVar14;

  undefined8 local_res8;

  

  *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) | 0x10;

  iVar4 = *(int *)(param_1 + 6);

  if (iVar4 < 0) {

    iVar4 = (-(uint)((*(short *)((longlong)param_1 + 0x3a) - 0x41U & 0xffdf) != 0) & 0xfffffff9) +

            0xd;

    *(int *)(param_1 + 6) = iVar4;

  }

  else if ((iVar4 == 0) &&

          ((*(short *)((longlong)param_1 + 0x3a) == 0x67 ||

           (*(short *)((longlong)param_1 + 0x3a) == 0x47)))) {

    *(undefined4 *)(param_1 + 6) = 1;

    iVar4 = 1;

  }

  cVar3 = FUN_1402d1ca8(param_1 + 10,(longlong)(iVar4 + 0x15d),param_1[1]);

  uVar13 = 0x200;

  if (cVar3 == '\0') {

    if (param_1[0x8b] == 0) {

      iVar4 = 0x200;

    }

    else {

      iVar4 = (int)((ulonglong)param_1[0x8a] >> 1);

    }

    iVar4 = iVar4 + -0x15d;

    *(int *)(param_1 + 6) = iVar4;

  }

  else {

    iVar4 = *(int *)(param_1 + 6);

  }

  puVar5 = (undefined8 *)param_1[0x8b];

  if ((undefined8 *)param_1[0x8b] == (undefined8 *)0x0) {

    puVar5 = param_1 + 10;

  }

  param_1[8] = puVar5;

  puVar11 = (undefined8 *)param_1[3];

  param_1[3] = puVar11 + 1;

  puVar5 = (undefined8 *)param_1[0x8b];

  local_res8 = *puVar11;

  if (puVar5 == (undefined8 *)0x0) {

    puVar11 = param_1 + 0x4a;

    puVar5 = param_1 + 10;

    uVar6 = 0x200;

  }

  else {

    puVar11 = (undefined8 *)(((ulonglong)param_1[0x8a] >> 1) + (longlong)puVar5);

    uVar6 = (ulonglong)param_1[0x8a] >> 1;

    uVar13 = (ulonglong)param_1[0x8a] >> 1;

  }

  FUN_1402efaac(&local_res8,puVar5,uVar13,puVar11,uVar6,(int)*(char *)((longlong)param_1 + 0x3a),

                iVar4,*param_1,1,param_1[1]);

  if (((*(uint *)(param_1 + 5) >> 5 & 1) != 0) && (*(int *)(param_1 + 6) == 0)) {

    lVar9 = param_1[1];

    if (*(char *)(lVar9 + 0x28) == '\0') {

      FUN_1402d74e0(lVar9);

    }

    pbVar12 = (byte *)param_1[8];

    plVar2 = *(longlong **)(lVar9 + 0x18);

    uVar13 = (ulonglong)*pbVar12;

    if (*(char *)(uVar13 + plVar2[0x22]) != 'e') {

      do {

        pbVar12 = pbVar12 + 1;

        uVar13 = (ulonglong)*pbVar12;

      } while ((*(byte *)(*plVar2 + uVar13 * 2) & 4) != 0);

    }

    bVar14 = *(char *)(uVar13 + plVar2[0x22]) == 'x';

    if (bVar14) {

      uVar13 = (ulonglong)pbVar12[2];

    }

    pbVar8 = pbVar12 + 2;

    if (!bVar14) {

      pbVar8 = pbVar12;

    }

    *pbVar8 = **(byte **)plVar2[0x1f];

    do {

      pbVar8 = pbVar8 + 1;

      bVar1 = *pbVar8;

      bVar10 = (byte)uVar13;

      *pbVar8 = bVar10;

      uVar13 = (ulonglong)bVar1;

    } while (bVar10 != 0);

  }

  if (((*(short *)((longlong)param_1 + 0x3a) - 0x47U & 0xffdf) == 0) &&

     ((*(uint *)(param_1 + 5) >> 5 & 1) == 0)) {

    if (*(char *)(param_1[1] + 0x28) == '\0') {

      FUN_1402d74e0(param_1[1]);

    }

    FUN_1402d3dd8(param_1[8]);

  }

  pcVar7 = (char *)param_1[8];

  cVar3 = *pcVar7;

  if (cVar3 == '-') {

    *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) | 0x40;

    pcVar7 = pcVar7 + 1;

    param_1[8] = pcVar7;

    cVar3 = *pcVar7;

  }

  if (((byte)(cVar3 + 0xb7U) < 0x26) &&

     ((0x2100000021U >> ((ulonglong)(byte)(cVar3 + 0xb7U) & 0x3f) & 1) != 0)) {

    *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) & 0xfffffff7;

    *(undefined2 *)((longlong)param_1 + 0x3a) = 0x73;

  }

  lVar9 = -1;

  do {

    lVar9 = lVar9 + 1;

  } while (pcVar7[lVar9] != '\0');

  *(int *)(param_1 + 9) = (int)lVar9;

  return 1;

}




