// Address: 0x1401fded0
// Ghidra name: FUN_1401fded0
// ============ 0x1401fded0 FUN_1401fded0 (size=1612) ============


undefined8 FUN_1401fded0(longlong param_1,int *param_2,longlong param_3,undefined8 param_4)



{

  float fVar1;

  int *piVar2;

  undefined8 uVar3;

  bool bVar4;

  char cVar5;

  int iVar6;

  undefined8 uVar7;

  undefined4 uVar8;

  longlong lVar9;

  float *pfVar10;

  ulonglong uVar11;

  int *piVar12;

  longlong lVar13;

  ulonglong uVar14;

  undefined8 local_88;

  int *local_80;

  longlong local_78;

  float local_68;

  float fStack_64;

  float fStack_60;

  int iStack_5c;

  float local_58;

  float local_54;

  float local_50;

  int local_4c;

  

  lVar13 = *(longlong *)(param_1 + 0x2e0);

  local_78 = lVar13;

  iVar6 = FUN_1401fa5d0(lVar13);

  local_88 = 0;

  if (*(longlong *)(lVar13 + 0x660) == 0) {

    uVar7 = FUN_14012e850("Device lost and couldn\'t be recovered");

    return uVar7;

  }

  if (*(int *)(lVar13 + 0x2924) != iVar6) {

    *(int *)(lVar13 + 0x2924) = iVar6;

    *(undefined1 *)(lVar13 + 0x2928) = 1;

    *(undefined1 *)(lVar13 + 0x2900) = 1;

  }

  if (*(char *)(lVar13 + 0x6e8) != '\0') {

    iVar6 = FUN_1401ff300(param_1);

    if (iVar6 != 0) {

      return 0;

    }

    *(undefined1 *)(lVar13 + 0x6e8) = 0;

  }

  cVar5 = FUN_1401ffb70(param_1,param_3,param_4,&local_88);

  if (cVar5 == '\0') {

    return 0;

  }

  do {

    if (param_2 == (int *)0x0) {

      return 1;

    }

    uVar7 = 0;

    iVar6 = *param_2;

    piVar12 = param_2;

    switch(iVar6 + -1) {

    case 0:

      iVar6 = memcmp((void *)(lVar13 + 0x2914),param_2 + 4,0x10);

      if (iVar6 != 0) {

        uVar7 = *(undefined8 *)(param_2 + 6);

        *(undefined8 *)(lVar13 + 0x2914) = *(undefined8 *)(param_2 + 4);

        *(undefined8 *)(lVar13 + 0x291c) = uVar7;

        *(undefined1 *)(lVar13 + 0x2928) = 1;

        *(undefined1 *)(lVar13 + 0x2900) = 1;

      }

      break;

    case 1:

      if (*(char *)(lVar13 + 0x2901) != (char)param_2[2]) {

        *(char *)(lVar13 + 0x2901) = (char)param_2[2];

        *(undefined1 *)(lVar13 + 0x2900) = 1;

      }

      iVar6 = memcmp((void *)(lVar13 + 0x2904),param_2 + 3,0x10);

      if (iVar6 != 0) {

        uVar7 = *(undefined8 *)(param_2 + 3);

        uVar3 = *(undefined8 *)(param_2 + 5);

        *(undefined1 *)(lVar13 + 0x2900) = 1;

        *(undefined8 *)(lVar13 + 0x2904) = uVar7;

        *(undefined8 *)(lVar13 + 0x290c) = uVar3;

      }

      break;

    case 3:

      cVar5 = FUN_1401538c0(param_1);

      local_68 = (float)param_2[5];

      fStack_64 = (float)param_2[6];

      fStack_60 = (float)param_2[7];

      iStack_5c = param_2[8];

      if (cVar5 != '\0') {

        FUN_14014bd40(&local_68);

      }

      fVar1 = (float)param_2[4];

      fStack_60 = fStack_60 * fVar1;

      local_68 = local_68 * fVar1;

      fStack_64 = fStack_64 * fVar1;

      local_4c = iStack_5c;

      local_58 = local_68;

      local_54 = fStack_64;

      local_50 = fStack_60;

      FUN_1401f56c0(param_1,1,&local_58,&local_88);

      break;

    case 4:

    case 9:

      uVar11 = *(ulonglong *)(param_2 + 2);

      lVar9 = *(longlong *)(param_2 + 4);

      for (piVar2 = *(int **)(param_2 + 0x14); piVar2 != (int *)0x0;

          piVar2 = *(int **)(piVar2 + 0x14)) {

        if (*piVar2 == iVar6) {

          if (((*(longlong *)(piVar2 + 0xc) != *(longlong *)(param_2 + 0xc)) ||

              (piVar2[0xe] != param_2[0xe])) ||

             ((piVar2[0xf] != param_2[0xf] ||

              (((piVar2[0x10] != param_2[0x10] || (piVar2[0xb] != param_2[0xb])) ||

               ((float)piVar2[6] != (float)param_2[6])))))) break;

          lVar9 = lVar9 + *(longlong *)(piVar2 + 4);

          piVar12 = piVar2;

        }

        else if (*piVar2 != 3) break;

      }

      if (iVar6 == 10) {

        if (*(longlong *)(param_2 + 0xc) == 0) {

          FUN_1401fe7e0(param_1,param_2,*(undefined8 *)(lVar13 + 0x750),

                        *(undefined8 *)(lVar13 + 0x748),0,3,0,0,0,0,0,&local_88);

          uVar7 = 3;

        }

        else {

          FUN_1401fe550(param_1,param_2,0,&local_88);

          uVar7 = 3;

        }

      }

      else {

        FUN_1401fe7e0(param_1,param_2,*(undefined8 *)(lVar13 + 0x750),

                      *(undefined8 *)(lVar13 + 0x748),0,0,0,0,0,0,0,&local_88);

      }

      FUN_1401f9d80(param_1,uVar7,uVar11 >> 5,lVar9);

      break;

    case 5:

      pfVar10 = (float *)(param_3 + *(longlong *)(param_2 + 2));

      bVar4 = false;

      uVar11 = *(ulonglong *)(param_2 + 4);

      uVar14 = *(ulonglong *)(param_2 + 2) >> 5;

      lVar9 = uVar11 - 1;

      if ((*pfVar10 != pfVar10[lVar9 * 8]) || (pfVar10[1] != pfVar10[lVar9 * 8 + 1])) {

        FUN_1401fe7e0(param_1,param_2,*(undefined8 *)(lVar13 + 0x750),

                      *(undefined8 *)(lVar13 + 0x748),0,0,0,0,0,0,0,&local_88);

        FUN_1401f9d80(param_1,0,lVar9 + uVar14,1);

        bVar4 = true;

      }

      if (uVar11 < 3) {

        fVar1 = (float)param_2[6];

        iVar6 = param_2[0xb];

        lVar13 = local_78;

        for (piVar2 = *(int **)(param_2 + 0x14); local_80 = piVar12, local_78 = lVar13,

            piVar2 != (int *)0x0; piVar2 = *(int **)(piVar2 + 0x14)) {

          if (*piVar2 == 6) {

            if (((*(longlong *)(piVar2 + 4) != 2) || (piVar2[0xb] != iVar6)) ||

               ((float)piVar2[6] != fVar1)) break;

            lVar9 = uVar11 + 1;

            local_80 = piVar2;

            if ((pfVar10[uVar11 * 8] != pfVar10[lVar9 * 8]) ||

               (pfVar10[uVar11 * 8 + 1] != pfVar10[lVar9 * 8 + 1])) {

              if (!bVar4) {

                FUN_1401fe7e0(param_1,param_2,*(undefined8 *)(lVar13 + 0x750),

                              *(undefined8 *)(lVar13 + 0x748),0,0,0,0,0,0,0,&local_88);

                bVar4 = true;

              }

              FUN_1401f9d80(param_1,0,lVar9 + uVar14,1);

            }

            uVar11 = uVar11 + *(longlong *)(piVar2 + 4);

          }

          else if (*piVar2 != 3) break;

          piVar12 = local_80;

          lVar13 = local_78;

        }

        uVar8 = 1;

      }

      else {

        uVar8 = 2;

      }

      FUN_1401fe7e0(param_1,param_2,*(undefined8 *)(lVar13 + 0x750),*(undefined8 *)(lVar13 + 0x748),

                    0,uVar8,0,0,0,0,0,&local_88);

      FUN_1401f9d80(param_1,uVar8,uVar14,uVar11);

    }

    param_2 = *(int **)(piVar12 + 0x14);

  } while( true );

}




