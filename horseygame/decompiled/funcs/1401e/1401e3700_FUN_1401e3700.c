// Address: 0x1401e3700
// Ghidra name: FUN_1401e3700
// ============ 0x1401e3700 FUN_1401e3700 (size=1141) ============


undefined1 FUN_1401e3700(longlong param_1,int *param_2,longlong param_3,undefined8 param_4)



{

  longlong lVar1;

  float fVar2;

  longlong lVar3;

  ulonglong uVar4;

  int *piVar5;

  undefined8 uVar6;

  int *piVar7;

  undefined1 uVar8;

  char cVar9;

  int iVar10;

  undefined8 uVar11;

  float *pfVar12;

  int *piVar13;

  ulonglong uVar14;

  longlong *plVar15;

  float local_58;

  float fStack_54;

  float fStack_50;

  int iStack_4c;

  

  lVar3 = *(longlong *)(param_1 + 0x2e0);

  iVar10 = FUN_1401e2310();

  if (*(longlong *)(lVar3 + 0x20) == 0) {

    uVar8 = FUN_14012e850("Device lost and couldn\'t be recovered");

    return uVar8;

  }

  if (*(char *)(lVar3 + 0x15c) != '\0') {

    thunk_FUN_1401e1e80();

    *(undefined1 *)(lVar3 + 0x15c) = 0;

  }

  if (*(int *)(lVar3 + 0x444) != iVar10) {

    *(int *)(lVar3 + 0x444) = iVar10;

    *(undefined1 *)(lVar3 + 0x448) = 1;

  }

  cVar9 = FUN_1401e51e0(param_1,param_3,param_4);

  if (cVar9 == '\0') {

    return 0;

  }

  do {

    if (param_2 == (int *)0x0) {

      return 1;

    }

    iVar10 = *param_2;

    switch(iVar10 + -1) {

    case 0:

      iVar10 = memcmp((void *)(lVar3 + 0x434),param_2 + 4,0x10);

      if (iVar10 != 0) {

        uVar11 = *(undefined8 *)(param_2 + 6);

        *(undefined8 *)(lVar3 + 0x434) = *(undefined8 *)(param_2 + 4);

        *(undefined8 *)(lVar3 + 0x43c) = uVar11;

        *(undefined1 *)(lVar3 + 0x448) = 1;

        *(undefined1 *)(lVar3 + 0x420) = 1;

      }

      break;

    case 1:

      if (*(char *)(lVar3 + 0x421) != (char)param_2[2]) {

        *(char *)(lVar3 + 0x421) = (char)param_2[2];

        *(undefined1 *)(lVar3 + 0x420) = 1;

      }

      iVar10 = memcmp((void *)(lVar3 + 0x424),param_2 + 3,0x10);

      if (iVar10 != 0) {

        uVar11 = *(undefined8 *)(param_2 + 3);

        uVar6 = *(undefined8 *)(param_2 + 5);

        *(undefined1 *)(lVar3 + 0x420) = 1;

        *(undefined8 *)(lVar3 + 0x424) = uVar11;

        *(undefined8 *)(lVar3 + 0x42c) = uVar6;

      }

      break;

    case 3:

      cVar9 = FUN_1401538c0(param_1);

      local_58 = (float)param_2[5];

      fStack_54 = (float)param_2[6];

      fStack_50 = (float)param_2[7];

      iStack_4c = param_2[8];

      if (cVar9 != '\0') {

        FUN_14014bd40(&local_58);

      }

      fVar2 = (float)param_2[4];

      plVar15 = *(longlong **)(lVar3 + 0x28);

      local_58 = local_58 * fVar2;

      fStack_54 = fStack_54 * fVar2;

      fStack_50 = fStack_50 * fVar2;

      uVar11 = FUN_1401e22f0(param_1);

      (**(code **)(*plVar15 + 400))(plVar15,uVar11);

      break;

    case 4:

    case 9:

      piVar7 = param_2;

      for (piVar5 = *(int **)(param_2 + 0x14); piVar5 != (int *)0x0;

          piVar5 = *(int **)(piVar5 + 0x14)) {

        if (*piVar5 == iVar10) {

          if (((*(longlong *)(piVar5 + 0xc) != *(longlong *)(param_2 + 0xc)) ||

              (piVar5[0xe] != param_2[0xe])) ||

             ((piVar5[0xf] != param_2[0xf] ||

              (((piVar5[0x10] != param_2[0x10] || (piVar5[0xb] != param_2[0xb])) ||

               (piVar13 = piVar5, (float)piVar5[6] != (float)param_2[6])))))) break;

        }

        else {

          piVar13 = piVar7;

          if (*piVar5 != 3) break;

        }

        piVar7 = piVar13;

      }

      if (*(longlong *)(param_2 + 0xc) == 0) {

        FUN_1401e3d10(param_1,param_2,0,0,0,0,0,0);

      }

      else {

        FUN_1401e3ba0();

      }

      uVar11 = 4;

      if (iVar10 != 10) {

        uVar11 = 1;

      }

      FUN_1401e22a0(param_1,uVar11);

      param_2 = piVar7;

      break;

    case 5:

      uVar4 = *(ulonglong *)(param_2 + 2);

      uVar14 = *(ulonglong *)(param_2 + 4);

      pfVar12 = (float *)(param_3 + *(longlong *)(param_2 + 2));

      FUN_1401e3d10(param_1,param_2,0,0,0,0,0,0);

      lVar1 = uVar14 - 1;

      if ((*pfVar12 != pfVar12[lVar1 * 8]) || (pfVar12[1] != pfVar12[lVar1 * 8 + 1])) {

        FUN_1401e22a0(param_1,1,lVar1 + (uVar4 >> 5),1);

      }

      if (uVar14 < 3) {

        fVar2 = (float)param_2[6];

        iVar10 = param_2[0xb];

        for (piVar5 = *(int **)(param_2 + 0x14); piVar5 != (int *)0x0;

            piVar5 = *(int **)(piVar5 + 0x14)) {

          if (*piVar5 == 6) {

            if (((*(longlong *)(piVar5 + 4) != 2) || (piVar5[0xb] != iVar10)) ||

               ((float)piVar5[6] != fVar2)) break;

            lVar1 = uVar14 + 1;

            if ((pfVar12[uVar14 * 8] != pfVar12[lVar1 * 8]) ||

               (pfVar12[uVar14 * 8 + 1] != pfVar12[lVar1 * 8 + 1])) {

              FUN_1401e22a0(param_1,1,lVar1 + (uVar4 >> 5),1);

            }

            uVar14 = uVar14 + *(longlong *)(piVar5 + 4);

            param_2 = piVar5;

          }

          else if (*piVar5 != 3) break;

        }

        FUN_1401e22a0(param_1,2);

      }

      else {

        FUN_1401e22a0(param_1,3);

      }

    }

    param_2 = *(int **)(param_2 + 0x14);

  } while( true );

}




