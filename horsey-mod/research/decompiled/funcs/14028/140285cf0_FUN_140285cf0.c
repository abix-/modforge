// Address: 0x140285cf0
// Ghidra name: FUN_140285cf0
// ============ 0x140285cf0 FUN_140285cf0 (size=1078) ============


undefined8 FUN_140285cf0(undefined8 *param_1,ulonglong *param_2)



{

  undefined4 uVar1;

  undefined4 uVar2;

  char *pcVar3;

  short sVar4;

  short sVar5;

  char *pcVar6;

  char cVar7;

  int iVar8;

  undefined4 uVar9;

  char *pcVar10;

  undefined4 *puVar11;

  longlong lVar12;

  undefined4 *puVar13;

  undefined8 *puVar14;

  undefined8 uVar15;

  undefined8 *puVar16;

  undefined8 *puVar17;

  char *_Str2;

  char *pcVar18;

  char *pcVar19;

  short local_res8 [4];

  ulonglong *local_res10;

  short local_res18 [4];

  longlong *local_res20;

  undefined8 uVar20;

  char *local_68;

  char *local_60 [2];

  undefined8 local_50 [2];

  

  pcVar10 = (char *)0x0;

  local_res18[0] = 0;

  local_res8[0] = 0;

  pcVar18 = (char *)0x0;

  local_60[0] = (char *)0x0;

  local_50[0] = 0;

  local_68 = (char *)0x0;

  local_res20 = (longlong *)0x0;

  _Str2 = pcVar10;

  pcVar19 = pcVar10;

  local_res10 = param_2;

  if ((((((*(uint *)((longlong)param_1 + 0x24) & 0x10000) != 0) &&

        (iVar8 = (**(code **)(*DAT_1403fde50 + 0x18))

                           (DAT_1403fde50,(longlong)param_1 + 4,&local_res20,0), _Str2 = (char *)0x0

        , pcVar19 = pcVar18, -1 < iVar8)) &&

       (cVar7 = FUN_1402863e0(local_res20,local_60), _Str2 = local_60[0], cVar7 != '\0')) &&

      ((cVar7 = FUN_140286260(local_res20,local_res18,local_res8), sVar5 = local_res18[0],

       sVar4 = local_res8[0], _Str2 = local_60[0], cVar7 != '\0' &&

       (cVar7 = FUN_1402862e0(local_res20,local_res18[0],local_res8[0],local_50,&local_68),

       _Str2 = local_60[0], pcVar19 = local_68, cVar7 != '\0')))) &&

     ((cVar7 = FUN_140286e50(sVar5,sVar4,local_60[0]), pcVar19 = local_68, cVar7 == '\0' &&

      ((cVar7 = FUN_14015ba80(sVar5,sVar4,0,local_68), cVar7 == '\0' &&

       (pcVar18 = pcVar19, cVar7 = FUN_1401599b0(&PTR_FUN_1403e50f0,sVar5,sVar4,0,pcVar19),

       cVar7 == '\0')))))) {

    pcVar6 = (char *)*param_2;

    while (pcVar3 = pcVar6, pcVar3 != (char *)0x0) {

      iVar8 = strcmp(pcVar3 + 0x470,_Str2);

      if (iVar8 == 0) {

        if (pcVar3 == (char *)*local_res10) {

          *local_res10 = *(ulonglong *)(pcVar3 + 0x578);

        }

        else if (pcVar10 != (char *)0x0) {

          *(undefined8 *)(pcVar10 + 0x578) = *(undefined8 *)(pcVar3 + 0x578);

        }

        lVar12 = 8;

        pcVar10 = pcVar3 + 0x24;

        do {

          puVar17 = param_1;

          pcVar18 = pcVar10;

          uVar20 = puVar17[1];

          *(undefined8 *)pcVar18 = *puVar17;

          *(undefined8 *)(pcVar18 + 8) = uVar20;

          uVar20 = puVar17[3];

          *(undefined8 *)(pcVar18 + 0x10) = puVar17[2];

          *(undefined8 *)(pcVar18 + 0x18) = uVar20;

          uVar20 = puVar17[5];

          *(undefined8 *)(pcVar18 + 0x20) = puVar17[4];

          *(undefined8 *)(pcVar18 + 0x28) = uVar20;

          uVar20 = puVar17[7];

          *(undefined8 *)(pcVar18 + 0x30) = puVar17[6];

          *(undefined8 *)(pcVar18 + 0x38) = uVar20;

          uVar20 = puVar17[9];

          *(undefined8 *)(pcVar18 + 0x40) = puVar17[8];

          *(undefined8 *)(pcVar18 + 0x48) = uVar20;

          uVar20 = puVar17[0xb];

          *(undefined8 *)(pcVar18 + 0x50) = puVar17[10];

          *(undefined8 *)(pcVar18 + 0x58) = uVar20;

          uVar20 = puVar17[0xd];

          *(undefined8 *)(pcVar18 + 0x60) = puVar17[0xc];

          *(undefined8 *)(pcVar18 + 0x68) = uVar20;

          uVar20 = puVar17[0xf];

          *(undefined8 *)(pcVar18 + 0x70) = puVar17[0xe];

          *(undefined8 *)(pcVar18 + 0x78) = uVar20;

          lVar12 = lVar12 + -1;

          pcVar10 = pcVar18 + 0x80;

          param_1 = puVar17 + 0x10;

        } while (lVar12 != 0);

        uVar20 = puVar17[0x11];

        *(undefined8 *)(pcVar18 + 0x80) = puVar17[0x10];

        *(undefined8 *)(pcVar18 + 0x88) = uVar20;

        uVar20 = puVar17[0x13];

        *(undefined8 *)(pcVar18 + 0x90) = puVar17[0x12];

        *(undefined8 *)(pcVar18 + 0x98) = uVar20;

        uVar9 = *(undefined4 *)((longlong)puVar17 + 0xa4);

        uVar1 = *(undefined4 *)(puVar17 + 0x15);

        uVar2 = *(undefined4 *)((longlong)puVar17 + 0xac);

        *(undefined4 *)(pcVar18 + 0xa0) = *(undefined4 *)(puVar17 + 0x14);

        *(undefined4 *)(pcVar18 + 0xa4) = uVar9;

        *(undefined4 *)(pcVar18 + 0xa8) = uVar1;

        *(undefined4 *)(pcVar18 + 0xac) = uVar2;

        uVar20 = puVar17[0x17];

        *(undefined8 *)(pcVar18 + 0xb0) = puVar17[0x16];

        *(undefined8 *)(pcVar18 + 0xb8) = uVar20;

        *(undefined8 *)(pcVar18 + 0xc0) = puVar17[0x18];

        *(undefined4 *)(pcVar18 + 200) = *(undefined4 *)(puVar17 + 0x19);

        *(char **)(pcVar3 + 0x578) = DAT_1403ffc48;

        DAT_1403ffc48 = pcVar3;

        goto LAB_1402860b7;

      }

      pcVar10 = pcVar3;

      pcVar6 = *(char **)(pcVar3 + 0x578);

    }

    puVar11 = (undefined4 *)FUN_1401841a0(1,0x580);

    if (puVar11 != (undefined4 *)0x0) {

      uVar9 = FUN_140286210(sVar5,sVar4,_Str2);

      puVar11[0x15d] = uVar9;

      FUN_14012f1a0(puVar11 + 0x11c,_Str2,0x104);

      uVar20 = local_50[0];

      lVar12 = 8;

      puVar17 = (undefined8 *)(puVar11 + 9);

      do {

        puVar16 = param_1;

        puVar14 = puVar17;

        uVar15 = puVar16[1];

        *puVar14 = *puVar16;

        puVar14[1] = uVar15;

        uVar15 = puVar16[3];

        puVar14[2] = puVar16[2];

        puVar14[3] = uVar15;

        uVar15 = puVar16[5];

        puVar14[4] = puVar16[4];

        puVar14[5] = uVar15;

        uVar15 = puVar16[7];

        puVar14[6] = puVar16[6];

        puVar14[7] = uVar15;

        uVar15 = puVar16[9];

        puVar14[8] = puVar16[8];

        puVar14[9] = uVar15;

        uVar15 = puVar16[0xb];

        puVar14[10] = puVar16[10];

        puVar14[0xb] = uVar15;

        uVar15 = puVar16[0xd];

        puVar14[0xc] = puVar16[0xc];

        puVar14[0xd] = uVar15;

        uVar15 = puVar16[0xf];

        puVar14[0xe] = puVar16[0xe];

        puVar14[0xf] = uVar15;

        lVar12 = lVar12 + -1;

        puVar17 = puVar14 + 0x10;

        param_1 = puVar16 + 0x10;

      } while (lVar12 != 0);

      uVar15 = puVar16[0x11];

      puVar14[0x10] = puVar16[0x10];

      puVar14[0x11] = uVar15;

      uVar15 = puVar16[0x13];

      puVar14[0x12] = puVar16[0x12];

      puVar14[0x13] = uVar15;

      uVar9 = *(undefined4 *)((longlong)puVar16 + 0xa4);

      uVar1 = *(undefined4 *)(puVar16 + 0x15);

      uVar2 = *(undefined4 *)((longlong)puVar16 + 0xac);

      *(undefined4 *)(puVar14 + 0x14) = *(undefined4 *)(puVar16 + 0x14);

      *(undefined4 *)((longlong)puVar14 + 0xa4) = uVar9;

      *(undefined4 *)(puVar14 + 0x15) = uVar1;

      *(undefined4 *)((longlong)puVar14 + 0xac) = uVar2;

      uVar9 = *(undefined4 *)((longlong)puVar16 + 0xb4);

      uVar1 = *(undefined4 *)(puVar16 + 0x17);

      uVar2 = *(undefined4 *)((longlong)puVar16 + 0xbc);

      *(undefined4 *)(puVar14 + 0x16) = *(undefined4 *)(puVar16 + 0x16);

      *(undefined4 *)((longlong)puVar14 + 0xb4) = uVar9;

      *(undefined4 *)(puVar14 + 0x17) = uVar1;

      *(undefined4 *)((longlong)puVar14 + 0xbc) = uVar2;

      puVar14[0x18] = puVar16[0x18];

      *(undefined4 *)(puVar14 + 0x19) = *(undefined4 *)(puVar16 + 0x19);

      lVar12 = FUN_1401578c0(sVar5,sVar4,local_50[0],pcVar19);

      *(longlong *)(puVar11 + 4) = lVar12;

      if (lVar12 == 0) {

        FUN_1401841e0(0);

        FUN_1401841e0(puVar11);

      }

      else {

        if ((sVar5 == 0) || (sVar4 == 0)) {

          uVar15 = 5;

          uVar20 = local_50[0];

        }

        else {

          uVar15 = 3;

        }

        puVar13 = (undefined4 *)

                  FUN_140157780(local_60,uVar15,sVar5,sVar4,(ulonglong)pcVar18 & 0xffffffffffff0000,

                                uVar20,pcVar19,0,0);

        uVar9 = puVar13[1];

        uVar1 = puVar13[2];

        uVar2 = puVar13[3];

        *puVar11 = *puVar13;

        puVar11[1] = uVar9;

        puVar11[2] = uVar1;

        puVar11[3] = uVar2;

        FUN_14020f660(puVar11);

      }

    }

  }

LAB_1402860b7:

  FUN_1401841e0(_Str2);

  FUN_1401841e0(local_50[0]);

  FUN_1401841e0(pcVar19);

  if (local_res20 != (longlong *)0x0) {

    (**(code **)(*local_res20 + 0x10))();

  }

  return 1;

}




