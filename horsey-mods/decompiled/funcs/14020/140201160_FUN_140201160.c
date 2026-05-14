// Address: 0x140201160
// Ghidra name: FUN_140201160
// ============ 0x140201160 FUN_140201160 (size=1626) ============


ulonglong FUN_140201160(undefined8 param_1,undefined8 param_2,longlong param_3,int *param_4,

                       int *param_5,undefined8 param_6,undefined8 param_7,uint param_8,

                       undefined4 param_9,undefined4 param_10,uint param_11)



{

  byte *pbVar1;

  char cVar2;

  uint uVar3;

  uint uVar4;

  ulonglong uVar5;

  longlong lVar6;

  longlong lVar7;

  longlong lVar8;

  longlong lVar9;

  byte bVar10;

  byte local_res18 [8];

  int *local_res20;

  undefined8 in_stack_ffffffffffffff08;

  undefined4 uVar13;

  undefined8 uVar11;

  int *piVar12;

  int *piVar14;

  undefined4 uVar16;

  undefined8 uVar15;

  undefined4 uVar18;

  undefined8 uVar17;

  byte local_c8;

  byte local_c7;

  byte local_c6 [2];

  uint local_c4;

  int local_c0;

  undefined4 uStack_bc;

  int local_b8;

  longlong local_b0;

  int local_a8;

  int iStack_a4;

  int iStack_a0;

  int iStack_9c;

  int local_98;

  int local_90;

  int local_8c;

  int local_88;

  int local_84;

  undefined8 local_80;

  int local_78;

  int iStack_74;

  int iStack_70;

  int iStack_6c;

  int local_68;

  int iStack_64;

  int iStack_60;

  int iStack_5c;

  

  uVar13 = (undefined4)((ulonglong)in_stack_ffffffffffffff08 >> 0x20);

  pbVar1 = *(byte **)(param_3 + 0x138);

  lVar8 = 0;

  local_b0 = 0;

  local_b8 = 0;

  local_c0 = 0;

  cVar2 = '\x01';

  local_98 = 0;

  local_res20 = param_4;

  uVar5 = FUN_1401489c0(param_2);

  if ((char)uVar5 == '\0') {

LAB_140201203:

    return uVar5 & 0xffffffffffffff00;

  }

  local_a8 = 0;

  iStack_a4 = 0;

  iStack_a0 = param_5[2];

  iStack_9c = param_5[3];

  if (((*pbVar1 & 2) != 0) && (uVar5 = FUN_140146f20(pbVar1), (char)uVar5 == '\0'))

  goto LAB_140201203;

  uVar11 = CONCAT44(uVar13,*(undefined4 *)(pbVar1 + 0x10));

  lVar6 = FUN_140145bc0(*(undefined4 *)(pbVar1 + 8),*(undefined4 *)(pbVar1 + 0xc),

                        *(undefined4 *)(pbVar1 + 4),*(undefined8 *)(pbVar1 + 0x18),uVar11);

  uVar13 = (undefined4)((ulonglong)uVar11 >> 0x20);

  if (lVar6 == 0) {

    uVar5 = 0;

    if ((*pbVar1 & 2) != 0) {

      uVar5 = FUN_1401489e0(pbVar1);

    }

    goto LAB_140201203;

  }

  if (*(longlong *)(pbVar1 + 0x48) != 0) {

    FUN_1401487f0(lVar6);

  }

  FUN_1401465d0(pbVar1,&local_c4);

  FUN_140146570(pbVar1,local_res18);

  FUN_1401467d0(pbVar1,local_c6,&local_c7,&local_c8);

  uVar4 = *(uint *)(pbVar1 + 4);

  if ((((uVar4 == 0) || ((uVar4 & 0xf0000000) != 0x10000000)) || ((uVar4 & 0xff00) != 0x2000)) ||

     ((uVar4 & 0xf0000) != 0x60000)) {

    local_c0 = 1;

  }

  if (((param_4[2] != param_5[2]) || (param_4[3] != param_5[3])) ||

     ((*param_4 != 0 || (param_4[1] != 0)))) {

    local_c0 = 1;

  }

  if (((param_4[2] != *(int *)(pbVar1 + 8)) || (param_4[3] != *(int *)(pbVar1 + 0xc))) ||

     ((*param_4 != 0 || (param_4[1] != 0)))) {

    local_c0 = 1;

  }

  if ((((local_c4 & 0xfffffff3) == 0) && (local_c4 != 0xc)) &&

     ((local_c6[0] & local_c7 & local_c8 & local_res18[0]) != 0xff)) {

    local_b8 = 1;

    FUN_1401483d0(lVar6,local_res18[0]);

    FUN_1401486f0(lVar6,local_c6[0],local_c7,local_c8);

  }

  lVar7 = lVar6;

  if (local_c4 == 0) {

    uVar4 = *(uint *)(pbVar1 + 4);

    if (uVar4 == 0) {

LAB_14020136f:

      if (((uVar4 & 0xf000000) + 0xfb000000 & 0xfeffffff) != 0) {

LAB_14020139e:

        if (uVar4 != 0) goto LAB_1402013a2;

        goto LAB_1402013b0;

      }

LAB_14020137b:

      uVar3 = uVar4 & 0xf00000;

      if (((uVar3 != 0x300000) && (uVar3 != 0x400000)) &&

         ((uVar3 != 0x700000 && (uVar3 != 0x800000)))) goto LAB_14020139e;

    }

    else {

      if ((uVar4 & 0xf0000000) == 0x10000000) {

        if ((uVar4 & 0xf000000) != 0x4000000) goto LAB_14020136f;

        goto LAB_14020137b;

      }

LAB_1402013a2:

      if ((uVar4 & 0xf0000000) == 0x10000000) {

LAB_1402013b0:

        uVar4 = *(uint *)(pbVar1 + 4) & 0xf000000;

        if (((uVar4 == 0x7000000) || ((uVar4 + 0xf8000000 & 0xfcffffff) == 0)) &&

           ((uVar4 = *(uint *)(pbVar1 + 4) & 0xf00000, uVar4 == 0x300000 ||

            (((uVar4 == 0x200000 || (uVar4 == 0x600000)) || (uVar4 == 0x500000))))))

        goto LAB_140201402;

      }

      if (local_res18[0] == 0xff) {

        local_98 = 1;

        goto LAB_140201446;

      }

    }

LAB_140201402:

    lVar9 = FUN_140145e60(param_5[2],param_5[3],0x16362004);

    local_b0 = lVar9;

    if (lVar9 == 0) {

      bVar10 = 0;

      FUN_140148450(lVar6,local_c4);

      goto LAB_140201782;

    }

    FUN_140148450(lVar9,4);

  }

LAB_140201446:

  if ((local_c0 != 0) || (local_b8 != 0)) {

    local_68 = local_a8;

    iStack_64 = iStack_a4;

    iStack_60 = iStack_a0;

    iStack_5c = iStack_9c;

    lVar7 = FUN_140145e60(param_5[2],param_5[3],0x16362004);

    if (lVar7 == 0) {

      bVar10 = 0;

      FUN_140148450(lVar6,local_c4);

      lVar9 = local_b0;

      lVar7 = lVar6;

      goto LAB_140201782;

    }

    FUN_140148450(lVar6,0);

    cVar2 = FUN_140143490(lVar6,local_res20,lVar7,&local_68,CONCAT44(uVar13,param_11));

    FUN_140146010(lVar6);

  }

  FUN_140148450(lVar7,local_c4);

  bVar10 = 0;

  lVar9 = local_b0;

  if (cVar2 != '\0') {

    piVar12 = &local_90;

    FUN_1401d3430(iStack_a0,iStack_9c,param_6,param_7,piVar12,&local_80,&local_c0);

    piVar14 = &local_90;

    uVar5 = CONCAT44((int)((ulonglong)piVar12 >> 0x20),param_8) & 0xffffffff00000002;

    uVar11 = local_80;

    lVar6 = FUN_1401d30e0(lVar7,param_6,(param_11 & 0xfffffffd) != 0,param_8 & 1,uVar5,piVar14,

                          local_80,CONCAT44(uStack_bc,local_c0),param_7);

    uVar13 = (undefined4)(uVar5 >> 0x20);

    uVar16 = (undefined4)((ulonglong)piVar14 >> 0x20);

    uVar18 = (undefined4)((ulonglong)uVar11 >> 0x20);

    if (lVar6 == 0) {

      bVar10 = 0;

      lVar9 = local_b0;

    }

    else {

      if (local_b0 != 0) {

        piVar12 = &local_90;

        uVar5 = uVar5 & 0xffffffff00000000;

        lVar8 = FUN_1401d30e0(local_b0,param_6,0,0,uVar5,piVar12,local_80,

                              CONCAT44(uStack_bc,local_c0),param_7);

        uVar13 = (undefined4)(uVar5 >> 0x20);

        uVar16 = (undefined4)((ulonglong)piVar12 >> 0x20);

        uVar18 = (undefined4)((ulonglong)local_80 >> 0x20);

        if (lVar8 == 0) {

          bVar10 = 0;

          lVar9 = local_b0;

          goto LAB_140201782;

        }

      }

      local_a8 = *param_5 + local_90;

      iStack_a4 = param_5[1] + local_8c;

      iStack_a0 = local_88;

      iStack_9c = local_84;

      if ((local_c4 == 0) && (local_98 == 0)) {

        iStack_70 = local_88;

        iStack_6c = local_84;

        local_78 = local_a8;

        iStack_74 = iStack_a4;

        FUN_140148450(lVar8,0);

        uVar17 = CONCAT44(uVar18,param_11);

        uVar15 = CONCAT44(uVar16,param_10);

        uVar11 = CONCAT44(uVar13,param_9);

        cVar2 = FUN_1402001c0(lVar8,0,param_2,&local_78,uVar11,uVar15,uVar17);

        uVar13 = (undefined4)((ulonglong)uVar11 >> 0x20);

        uVar16 = (undefined4)((ulonglong)uVar15 >> 0x20);

        uVar18 = (undefined4)((ulonglong)uVar17 >> 0x20);

        bVar10 = 0;

        if (cVar2 != '\0') {

          FUN_1401486f0(lVar6,0,0,0);

          uVar17 = CONCAT44(uVar18,param_11);

          uVar15 = CONCAT44(uVar16,param_10);

          local_78 = local_a8;

          iStack_74 = iStack_a4;

          iStack_70 = iStack_a0;

          iStack_6c = iStack_9c;

          uVar11 = CONCAT44(uVar13,param_9);

          cVar2 = FUN_1402001c0(lVar6,0,param_2,&local_78,uVar11,uVar15,uVar17);

          uVar13 = (undefined4)((ulonglong)uVar15 >> 0x20);

          uVar16 = (undefined4)((ulonglong)uVar17 >> 0x20);

          bVar10 = 0;

          if (cVar2 != '\0') {

            uVar11 = CONCAT44((int)((ulonglong)uVar11 >> 0x20),*(undefined4 *)(lVar6 + 0x10));

            lVar9 = FUN_140145bc0(*(undefined4 *)(lVar6 + 8),*(undefined4 *)(lVar6 + 0xc),

                                  *(undefined4 *)(lVar6 + 4),*(undefined8 *)(lVar6 + 0x18),uVar11);

            uVar18 = (undefined4)((ulonglong)uVar11 >> 0x20);

            if (lVar9 == 0) {

              bVar10 = 0;

            }

            else {

              FUN_140148450(lVar9,2);

              bVar10 = FUN_1402001c0(lVar9,0,param_2,&local_a8,CONCAT44(uVar18,param_9),

                                     CONCAT44(uVar13,param_10),CONCAT44(uVar16,param_11));

              FUN_140146010(lVar9);

            }

          }

        }

        FUN_140146010(lVar8);

      }

      else {

        if (local_b8 == 0) {

          FUN_1401483d0(lVar6,local_res18[0]);

          FUN_1401486f0(lVar6,local_c6[0],local_c7,local_c8);

        }

        bVar10 = FUN_1402001c0(lVar6,0,param_2,&local_a8,CONCAT44(uVar13,param_9),

                               CONCAT44(uVar16,param_10),CONCAT44(uVar18,param_11));

      }

      FUN_140146010(lVar6);

      lVar9 = local_b0;

    }

  }

LAB_140201782:

  if ((*pbVar1 & 2) != 0) {

    FUN_1401489e0(pbVar1);

  }

  if (lVar9 != 0) {

    FUN_140146010(lVar9);

  }

  if (lVar7 != 0) {

    FUN_140146010(lVar7);

  }

  return (ulonglong)bVar10;

}




