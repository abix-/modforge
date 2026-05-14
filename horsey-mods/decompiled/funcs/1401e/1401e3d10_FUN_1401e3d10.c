// Address: 0x1401e3d10
// Ghidra name: FUN_1401e3d10
// ============ 0x1401e3d10 FUN_1401e3d10 (size=1291) ============


undefined8

FUN_1401e3d10(longlong param_1,longlong param_2,longlong *param_3,int param_4,longlong *param_5,

             int param_6,longlong *param_7,undefined8 *param_8)



{

  longlong lVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  bool bVar5;

  bool bVar6;

  char cVar7;

  int iVar8;

  uint uVar9;

  int iVar10;

  longlong lVar11;

  longlong *plVar12;

  longlong *plVar14;

  int *piVar15;

  longlong lVar16;

  undefined8 uVar17;

  longlong *plVar18;

  longlong **pplVar19;

  int iVar20;

  bool bVar21;

  char local_res8;

  longlong local_e0;

  longlong *local_d8;

  undefined8 local_d0;

  undefined8 local_c8;

  undefined4 local_c0;

  undefined8 local_bc;

  undefined4 local_b4;

  longlong local_a8 [14];

  ulonglong uVar13;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  if (param_8 == (undefined8 *)0x0) {

    param_8 = (undefined8 *)(lVar1 + 0x44c);

  }

  lVar16 = param_2;

  iVar20 = param_4;

  lVar11 = FUN_1401e22f0();

  iVar10 = *(int *)(lVar16 + 0x2c);

  plVar14 = (longlong *)0x0;

  bVar21 = false;

  plVar12 = plVar14;

  local_e0 = lVar11;

  iVar8 = FUN_1401e5cf0(param_3);

  bVar5 = false;

  bVar6 = false;

  plVar18 = (longlong *)((longlong)iVar8 * 0x78 + 0x220 + lVar1);

  if ((iVar20 != *(int *)(lVar1 + 0x400)) ||

     ((0 < iVar20 && (*param_5 != *(longlong *)(lVar1 + 0x408))))) {

    bVar5 = true;

    bVar6 = true;

  }

  local_res8 = (char)plVar12;

  if ((param_6 != *(int *)(lVar1 + 0x410)) ||

     ((0 < param_6 && (*param_7 != *(longlong *)(lVar1 + 0x418))))) {

    local_res8 = '\x01';

  }

  if (bVar5) {

    local_d8 = plVar12;

    (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x40))(*(longlong **)(lVar1 + 0x28),0,1,&local_d8);

    lVar11 = local_e0;

  }

  if (lVar11 != *(longlong *)(lVar1 + 0x200)) {

    (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x108))(*(longlong **)(lVar1 + 0x28),1,&local_e0,0)

    ;

    *(longlong *)(lVar1 + 0x200) = local_e0;

  }

  if (*(char *)(lVar1 + 0x448) != '\0') {

    cVar7 = FUN_1401e5390(param_1);

    bVar21 = cVar7 != '\0';

  }

  if (*(char *)(lVar1 + 0x420) != '\0') {

    if (*(char *)(lVar1 + 0x421) == '\0') {

      pplVar19 = (longlong **)0x0;

      uVar17 = 0;

    }

    else {

      cVar7 = FUN_1401e24b0(param_1,lVar1 + 0x424,&local_d8,1);

      if (cVar7 == '\0') {

        return 0;

      }

      pplVar19 = &local_d8;

      uVar17 = 1;

    }

    (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x168))

              (*(longlong **)(lVar1 + 0x28),uVar17,pplVar19);

    *(undefined1 *)(lVar1 + 0x420) = 0;

  }

  plVar12 = (longlong *)(lVar1 + 0x160);

  if (*(char *)(lVar1 + 0x421) != '\0') {

    plVar12 = (longlong *)(lVar1 + 0x168);

  }

  lVar16 = *plVar12;

  if (lVar16 != *(longlong *)(lVar1 + 0x208)) {

    (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x158))(*(longlong **)(lVar1 + 0x28),lVar16);

    *(longlong *)(lVar1 + 0x208) = lVar16;

  }

  uVar13 = 0;

  if (iVar10 != 0) {

    if (0 < *(int *)(lVar1 + 0x108)) {

      piVar15 = *(int **)(lVar1 + 0x110);

      do {

        if (iVar10 == *piVar15) {

          plVar14 = *(longlong **)(*(int **)(lVar1 + 0x110) + uVar13 * 4 + 2);

          if (plVar14 != (longlong *)0x0) goto LAB_1401e3f68;

          break;

        }

        uVar9 = (int)uVar13 + 1;

        uVar13 = (ulonglong)uVar9;

        piVar15 = piVar15 + 4;

      } while ((int)uVar9 < *(int *)(lVar1 + 0x108));

    }

    plVar14 = (longlong *)FUN_1401e0e10(param_1,iVar10);

    if (plVar14 == (longlong *)0x0) {

      return 0;

    }

  }

LAB_1401e3f68:

  if (plVar14 != *(longlong **)(lVar1 + 0x210)) {

    (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x118))

              (*(longlong **)(lVar1 + 0x28),plVar14,0,0xffffffff);

    *(longlong **)(lVar1 + 0x210) = plVar14;

  }

  if (param_3 == (longlong *)0x0) {

    FUN_1401e42a0(param_1,param_2,0,local_a8);

    param_3 = local_a8;

  }

  if ((*plVar18 == 0) || (iVar10 = memcmp(param_3,plVar18 + 1,0x70), iVar10 != 0)) {

    if ((longlong *)*plVar18 != (longlong *)0x0) {

      (**(code **)(*(longlong *)*plVar18 + 0x10))();

      *plVar18 = 0;

    }

    local_bc = 0;

    local_b4 = 0;

    local_c8 = 0x70;

    local_c0 = 4;

    local_d0 = 0;

    local_d8 = param_3;

    iVar10 = (**(code **)(**(longlong **)(lVar1 + 0x20) + 0x18))

                       (*(longlong **)(lVar1 + 0x20),&local_c8,&local_d8,plVar18);

    if (iVar10 < 0) {

      FUN_1401a9ef0("ID3D11Device::CreateBuffer [create shader constants]",iVar10);

      return 0;

    }

    lVar16 = param_3[1];

    plVar18[1] = *param_3;

    plVar18[2] = lVar16;

    lVar16 = param_3[3];

    plVar18[3] = param_3[2];

    plVar18[4] = lVar16;

    lVar16 = param_3[5];

    plVar18[5] = param_3[4];

    plVar18[6] = lVar16;

    lVar16 = param_3[7];

    plVar18[7] = param_3[6];

    plVar18[8] = lVar16;

    lVar16 = param_3[9];

    plVar18[9] = param_3[8];

    plVar18[10] = lVar16;

    lVar16 = param_3[0xb];

    plVar18[0xb] = param_3[10];

    plVar18[0xc] = lVar16;

    uVar2 = *(undefined4 *)((longlong)param_3 + 100);

    lVar16 = param_3[0xd];

    uVar3 = *(undefined4 *)((longlong)param_3 + 0x6c);

    *(int *)(plVar18 + 0xd) = (int)param_3[0xc];

    *(undefined4 *)((longlong)plVar18 + 0x6c) = uVar2;

    *(int *)(plVar18 + 0xe) = (int)lVar16;

    *(undefined4 *)((longlong)plVar18 + 0x74) = uVar3;

    *(undefined4 *)(lVar1 + 0x218) = 0;

  }

  if (iVar8 != *(int *)(lVar1 + 0x218)) {

    lVar16 = lVar1 + (longlong)iVar8 * 8;

    if ((*(longlong *)(lVar16 + 0xe8) == 0) &&

       (cVar7 = FUN_140240490(*(undefined8 *)(lVar1 + 0x20),iVar8,lVar16 + 0xe8), cVar7 == '\0')) {

      return 0;

    }

    (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x48))

              (*(longlong **)(lVar1 + 0x28),*(undefined8 *)(lVar16 + 0xe8),0,0);

    if (*plVar18 != 0) {

      (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x80))(*(longlong **)(lVar1 + 0x28),0,1,plVar18);

    }

    *(int *)(lVar1 + 0x218) = iVar8;

  }

  if (bVar6) {

    (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x40))

              (*(longlong **)(lVar1 + 0x28),0,param_4,param_5);

    *(int *)(lVar1 + 0x400) = param_4;

    if (0 < param_4) {

      *(longlong *)(lVar1 + 0x408) = *param_5;

    }

  }

  if (local_res8 != '\0') {

    (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x50))

              (*(longlong **)(lVar1 + 0x28),0,param_6,param_7);

    *(int *)(lVar1 + 0x410) = param_6;

    if (param_6 != 0) {

      *(longlong *)(lVar1 + 0x418) = *param_7;

    }

  }

  if ((bVar21) || (iVar10 = memcmp((void *)(lVar1 + 0x170),param_8,0x40), iVar10 != 0)) {

    uVar17 = param_8[1];

    *(undefined8 *)(lVar1 + 0x170) = *param_8;

    *(undefined8 *)(lVar1 + 0x178) = uVar17;

    uVar17 = param_8[3];

    *(undefined8 *)(lVar1 + 0x180) = param_8[2];

    *(undefined8 *)(lVar1 + 0x188) = uVar17;

    uVar2 = *(undefined4 *)((longlong)param_8 + 0x24);

    uVar3 = *(undefined4 *)(param_8 + 5);

    uVar4 = *(undefined4 *)((longlong)param_8 + 0x2c);

    *(undefined4 *)(lVar1 + 400) = *(undefined4 *)(param_8 + 4);

    *(undefined4 *)(lVar1 + 0x194) = uVar2;

    *(undefined4 *)(lVar1 + 0x198) = uVar3;

    *(undefined4 *)(lVar1 + 0x19c) = uVar4;

    uVar2 = *(undefined4 *)((longlong)param_8 + 0x34);

    uVar3 = *(undefined4 *)(param_8 + 7);

    uVar4 = *(undefined4 *)((longlong)param_8 + 0x3c);

    *(undefined4 *)(lVar1 + 0x1a0) = *(undefined4 *)(param_8 + 6);

    *(undefined4 *)(lVar1 + 0x1a4) = uVar2;

    *(undefined4 *)(lVar1 + 0x1a8) = uVar3;

    *(undefined4 *)(lVar1 + 0x1ac) = uVar4;

    (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x180))

              (*(longlong **)(lVar1 + 0x28),*(undefined8 *)(lVar1 + 0x1f0),0,0,

               (undefined8 *)(lVar1 + 0x170),0,0);

  }

  return 1;

}




