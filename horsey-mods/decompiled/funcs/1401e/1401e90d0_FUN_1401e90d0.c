// Address: 0x1401e90d0
// Ghidra name: FUN_1401e90d0
// ============ 0x1401e90d0 FUN_1401e90d0 (size=1377) ============


undefined1 FUN_1401e90d0(longlong param_1,int *param_2,longlong param_3)



{

  float fVar1;

  longlong lVar2;

  int *piVar3;

  undefined8 uVar4;

  bool bVar5;

  undefined1 uVar6;

  char cVar7;

  char cVar8;

  int iVar9;

  undefined8 uVar10;

  longlong lVar11;

  float *pfVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  ulonglong in_stack_ffffffffffffff58;

  uint uVar15;

  int *local_88;

  float local_70;

  float fStack_6c;

  float fStack_68;

  int iStack_64;

  undefined8 local_60;

  undefined4 uStack_58;

  undefined4 uStack_54;

  

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  iVar9 = FUN_1401e7f20();

  if (*(longlong *)(lVar2 + 0x30) == 0) {

    uVar6 = FUN_14012e850("Device lost and couldn\'t be recovered");

    return uVar6;

  }

  if (*(char *)(lVar2 + 100) != '\0') {

    FUN_1401ea320();

    *(undefined1 *)(lVar2 + 100) = 0;

  }

  if (*(int *)(lVar2 + 0x42304) != iVar9) {

    *(int *)(lVar2 + 0x42304) = iVar9;

    *(undefined1 *)(lVar2 + 0x42308) = 1;

  }

  cVar7 = FUN_1401eacd0(param_1,param_3);

  if (cVar7 == '\0') {

    return 0;

  }

  do {

    if (param_2 == (int *)0x0) {

      return 1;

    }

    iVar9 = *param_2;

    uVar15 = (uint)(in_stack_ffffffffffffff58 >> 0x20);

    local_88 = param_2;

    switch(iVar9 + -1) {

    case 0:

      iVar9 = memcmp((void *)(lVar2 + 0x422f4),param_2 + 4,0x10);

      if (iVar9 != 0) {

        uVar10 = *(undefined8 *)(param_2 + 6);

        *(undefined8 *)(lVar2 + 0x422f4) = *(undefined8 *)(param_2 + 4);

        *(undefined8 *)(lVar2 + 0x422fc) = uVar10;

        *(undefined1 *)(lVar2 + 0x42308) = 1;

        *(undefined1 *)(lVar2 + 0x422e0) = 1;

      }

      break;

    case 1:

      cVar7 = (char)param_2[2];

      param_2 = param_2 + 3;

      cVar8 = *(char *)(lVar2 + 0x422e1);

      if (*(char *)(lVar2 + 0x422e1) != cVar7) {

        *(char *)(lVar2 + 0x422e1) = cVar7;

        *(undefined1 *)(lVar2 + 0x422e0) = 1;

        cVar8 = cVar7;

      }

      if (cVar8 == '\0') {

        uStack_58 = *(undefined4 *)(lVar2 + 0x422fc);

        param_2 = (int *)&local_60;

        uStack_54 = *(undefined4 *)(lVar2 + 0x42300);

        local_60 = 0;

      }

      iVar9 = memcmp((void *)(lVar2 + 0x422e4),param_2,0x10);

      if (iVar9 != 0) {

        uVar10 = *(undefined8 *)param_2;

        uVar4 = *(undefined8 *)(param_2 + 2);

        *(undefined1 *)(lVar2 + 0x422e0) = 1;

        *(undefined8 *)(lVar2 + 0x422e4) = uVar10;

        *(undefined8 *)(lVar2 + 0x422ec) = uVar4;

      }

      break;

    case 3:

      uVar10 = FUN_1401e7ec0(param_1);

      cVar7 = FUN_1401538c0(param_1);

      local_70 = (float)param_2[5];

      fStack_6c = (float)param_2[6];

      fStack_68 = (float)param_2[7];

      iStack_64 = param_2[8];

      if (cVar7 != '\0') {

        FUN_14014bd40(&local_70);

      }

      fVar1 = (float)param_2[4];

      local_70 = local_70 * fVar1;

      fStack_6c = fStack_6c * fVar1;

      fStack_68 = fStack_68 * fVar1;

      in_stack_ffffffffffffff58 = 0;

      (**(code **)(**(longlong **)(lVar2 + 0x48) + 0x180))

                (*(longlong **)(lVar2 + 0x48),uVar10,&local_70,0,0);

      break;

    case 4:

    case 9:

      uVar13 = *(ulonglong *)(param_2 + 2);

      lVar11 = *(longlong *)(param_2 + 4);

      for (piVar3 = *(int **)(param_2 + 0x14); piVar3 != (int *)0x0;

          piVar3 = *(int **)(piVar3 + 0x14)) {

        if (*piVar3 == iVar9) {

          if (((*(longlong *)(piVar3 + 0xc) != *(longlong *)(param_2 + 0xc)) ||

              (piVar3[0xe] != param_2[0xe])) ||

             ((piVar3[0xf] != param_2[0xf] ||

              (((piVar3[0x10] != param_2[0x10] || (piVar3[0xb] != param_2[0xb])) ||

               ((float)piVar3[6] != (float)param_2[6])))))) break;

          lVar11 = lVar11 + *(longlong *)(piVar3 + 4);

          local_88 = piVar3;

        }

        else if (*piVar3 != 3) break;

      }

      if (iVar9 == 10) {

        if (*(longlong *)(param_2 + 0xc) == 0) {

          in_stack_ffffffffffffff58 = (ulonglong)uVar15 << 0x20;

          FUN_1401e9870(param_1,param_2,0,3,in_stack_ffffffffffffff58,0,0,0);

          uVar10 = 4;

        }

        else {

          FUN_1401e9660();

          uVar10 = 4;

        }

      }

      else {

        in_stack_ffffffffffffff58 = (ulonglong)uVar15 << 0x20;

        FUN_1401e9870(param_1,param_2,0,1,in_stack_ffffffffffffff58,0,0,0);

        uVar10 = 1;

      }

      FUN_1401e7dd0(param_1,uVar10,uVar13 >> 5,lVar11);

      break;

    case 5:

      pfVar12 = (float *)(param_3 + *(longlong *)(param_2 + 2));

      bVar5 = false;

      uVar13 = *(ulonglong *)(param_2 + 4);

      uVar14 = *(ulonglong *)(param_2 + 2) >> 5;

      lVar11 = uVar13 - 1;

      if ((*pfVar12 != pfVar12[lVar11 * 8]) || (pfVar12[1] != pfVar12[lVar11 * 8 + 1])) {

        in_stack_ffffffffffffff58 = (ulonglong)uVar15 << 0x20;

        FUN_1401e9870(param_1,param_2,0,1,in_stack_ffffffffffffff58,0,0,0);

        FUN_1401e7dd0(param_1,1,lVar11 + uVar14,1);

        bVar5 = true;

      }

      if (uVar13 < 3) {

        fVar1 = (float)param_2[6];

        iVar9 = param_2[0xb];

        for (piVar3 = *(int **)(param_2 + 0x14); piVar3 != (int *)0x0;

            piVar3 = *(int **)(piVar3 + 0x14)) {

          if (*piVar3 == 6) {

            if (((*(longlong *)(piVar3 + 4) != 2) || (piVar3[0xb] != iVar9)) ||

               ((float)piVar3[6] != fVar1)) break;

            lVar11 = uVar13 + 1;

            if ((pfVar12[uVar13 * 8] != pfVar12[lVar11 * 8]) ||

               (pfVar12[uVar13 * 8 + 1] != pfVar12[lVar11 * 8 + 1])) {

              if (!bVar5) {

                in_stack_ffffffffffffff58 = in_stack_ffffffffffffff58 & 0xffffffff00000000;

                FUN_1401e9870(param_1,param_2,0,1,in_stack_ffffffffffffff58,0,0,0);

                bVar5 = true;

              }

              FUN_1401e7dd0(param_1,1,lVar11 + uVar14,1);

            }

            uVar13 = uVar13 + *(longlong *)(piVar3 + 4);

            local_88 = piVar3;

          }

          else if (*piVar3 != 3) break;

        }

        uVar10 = 2;

      }

      else {

        uVar10 = 3;

      }

      in_stack_ffffffffffffff58 = in_stack_ffffffffffffff58 & 0xffffffff00000000;

      FUN_1401e9870(param_1,param_2,0,2,in_stack_ffffffffffffff58,0,0,0);

      FUN_1401e7dd0(param_1,uVar10,uVar14,uVar13);

    }

    param_2 = *(int **)(local_88 + 0x14);

  } while( true );

}




