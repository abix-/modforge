// Address: 0x1402045a0
// Ghidra name: FUN_1402045a0
// ============ 0x1402045a0 FUN_1402045a0 (size=868) ============


undefined1 FUN_1402045a0(longlong param_1,int *param_2,undefined8 param_3,undefined8 param_4)



{

  float fVar1;

  int iVar2;

  longlong lVar3;

  char cVar4;

  undefined1 uVar5;

  undefined4 uVar6;

  longlong lVar7;

  int *piVar8;

  int *piVar9;

  uint uVar10;

  int iVar11;

  undefined1 local_38 [8];

  float fStack_30;

  undefined4 uStack_2c;

  

  lVar3 = *(longlong *)(param_1 + 0x2e0);

  cVar4 = FUN_140205900(lVar3,param_3,param_4);

  if (cVar4 == '\0') {

    return 0;

  }

  *(undefined4 *)(lVar3 + 200) = 0;

  if (*(longlong *)(param_1 + 0x1f0) == 0) {

    lVar7 = *(longlong *)(lVar3 + 0x58);

  }

  else {

    lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x1f0) + 0x138) + 8);

  }

  *(longlong *)(lVar3 + 0xa8) = lVar7;

  if (lVar7 == 0) {

    uVar5 = FUN_14012e850("Render target texture is NULL");

    return uVar5;

  }

  do {

    if (param_2 == (int *)0x0) {

      if (*(int *)(lVar3 + 200) == 1) {

        FUN_1402057f0(lVar3);

      }

      if (*(longlong *)(lVar3 + 0x90) != 0) {

        FUN_1401367c0();

        *(undefined8 *)(lVar3 + 0x90) = 0;

      }

      return 1;

    }

    iVar2 = *param_2;

    switch(iVar2 + -1) {

    case 0:

      *(float *)(lVar3 + 0xe8) = (float)param_2[4];

      *(float *)(lVar3 + 0xec) = (float)param_2[5];

      *(float *)(lVar3 + 0xf0) = (float)param_2[6];

      *(float *)(lVar3 + 0xf4) = (float)param_2[7];

      break;

    case 1:

      *(int *)(lVar3 + 0x100) = (int)*(float *)(lVar3 + 0xe8) + param_2[3];

      *(int *)(lVar3 + 0x104) = (int)*(float *)(lVar3 + 0xec) + param_2[4];

      *(int *)(lVar3 + 0x108) = param_2[5];

      *(int *)(lVar3 + 0x10c) = param_2[6];

      *(char *)(lVar3 + 0x110) = (char)param_2[2];

      break;

    case 3:

      cVar4 = FUN_1401538c0(param_1);

      _local_38 = *(undefined1 (*) [16])(param_2 + 5);

      if (cVar4 != '\0') {

        FUN_14014bd40(local_38);

      }

      fVar1 = (float)param_2[4];

      *(undefined4 *)(lVar3 + 200) = 1;

      local_38._4_4_ = (float)local_38._4_4_ * fVar1;

      local_38._0_4_ = (float)local_38._0_4_ * fVar1;

      fStack_30 = fStack_30 * fVar1;

      *(undefined1 (*) [16])(lVar3 + 0xb8) = _local_38;

      break;

    case 4:

    case 9:

      iVar11 = param_2[4];

      piVar9 = param_2;

      for (piVar8 = *(int **)(param_2 + 0x14); piVar8 != (int *)0x0;

          piVar8 = *(int **)(piVar8 + 0x14)) {

        if (*piVar8 == iVar2) {

          if (((((*(longlong *)(piVar8 + 0xc) != *(longlong *)(param_2 + 0xc)) ||

                (piVar8[0xe] != param_2[0xe])) ||

               ((piVar8[0xf] != param_2[0xf] ||

                ((piVar8[0x10] != param_2[0x10] || (piVar8[0xb] != param_2[0xb])))))) ||

              ((float)piVar8[6] != (float)param_2[6])) ||

             (*(longlong *)(piVar8 + 0x12) != *(longlong *)(param_2 + 0x12))) break;

          iVar11 = iVar11 + piVar8[4];

          piVar9 = piVar8;

        }

        else if (*piVar8 != 3) break;

      }

      uVar6 = 0;

      if (iVar2 != 10) {

        uVar6 = 4;

      }

      FUN_140203060(lVar3,param_2,iVar11,param_2[2],uVar6);

      param_2 = piVar9;

      break;

    case 5:

      uVar10 = param_2[4];

      piVar8 = param_2;

      if (uVar10 < 3) {

        for (piVar9 = *(int **)(param_2 + 0x14); piVar9 != (int *)0x0;

            piVar9 = *(int **)(piVar9 + 0x14)) {

          if (*piVar9 == 6) {

            if ((((*(longlong *)(piVar9 + 4) != 2) || (piVar9[0xb] != param_2[0xb])) ||

                ((float)piVar9[6] != (float)param_2[6])) ||

               (*(longlong *)(piVar9 + 0x12) != *(longlong *)(param_2 + 0x12))) break;

            uVar10 = uVar10 + 2;

            piVar8 = piVar9;

          }

          else if (*piVar9 != 3) break;

        }

        uVar6 = 2;

      }

      else {

        uVar6 = 3;

      }

      FUN_140203060(lVar3,param_2,uVar10,param_2[2],uVar6);

      param_2 = piVar8;

    }

    param_2 = *(int **)(param_2 + 0x14);

  } while( true );

}




