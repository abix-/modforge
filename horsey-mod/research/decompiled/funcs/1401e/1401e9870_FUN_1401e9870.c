// Address: 0x1401e9870
// Ghidra name: FUN_1401e9870
// ============ 0x1401e9870 FUN_1401e9870 (size=1203) ============


undefined8

FUN_1401e9870(longlong param_1,longlong param_2,undefined8 *param_3,int param_4,int param_5,

             longlong *param_6,int param_7,longlong *param_8)



{

  longlong lVar1;

  bool bVar2;

  bool bVar3;

  bool bVar4;

  char cVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  longlong lVar9;

  int *piVar10;

  undefined8 uVar11;

  undefined8 uVar12;

  uint uVar13;

  ulonglong uVar14;

  ulonglong in_stack_fffffffffffffee8;

  longlong local_108;

  undefined1 local_100 [24];

  undefined8 local_e8;

  undefined8 uStack_e0;

  undefined8 local_d8;

  undefined8 uStack_d0;

  undefined4 local_c8;

  undefined4 uStack_c4;

  undefined4 uStack_c0;

  undefined4 uStack_bc;

  undefined4 local_b8;

  undefined4 uStack_b4;

  undefined4 uStack_b0;

  undefined4 uStack_ac;

  undefined8 local_a8 [14];

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  lVar9 = FUN_1401e7ec0();

  uVar14 = (ulonglong)*(uint *)(param_2 + 0x2c);

  iVar8 = *(int *)(lVar1 + 0x60);

  bVar4 = false;

  piVar10 = *(int **)(lVar1 + 0x108);

  local_108 = lVar9;

  iVar6 = FUN_1401eb3f0(param_3);

  bVar2 = false;

  if ((param_5 != *(int *)(lVar1 + 0x422c0)) ||

     ((0 < param_5 && (*param_6 != *(longlong *)(lVar1 + 0x422c8))))) {

    bVar2 = true;

  }

  bVar3 = false;

  if ((param_7 != *(int *)(lVar1 + 0x422d0)) ||

     ((0 < param_7 && (*param_8 != *(longlong *)(lVar1 + 0x422d8))))) {

    bVar3 = true;

  }

  if (*(longlong *)(lVar1 + 0x422b0) != 0) {

    iVar8 = *(int *)(*(longlong *)(lVar1 + 0x422b0) + 0x30);

  }

  if ((((piVar10 == (int *)0x0) || (*piVar10 != iVar6)) || (piVar10[0x1d] != (int)uVar14)) ||

     ((piVar10[0x1e] != param_4 || (piVar10[0x1f] != iVar8)))) {

    iVar7 = 0;

    if (0 < *(int *)(lVar1 + 0xf8)) {

      piVar10 = *(int **)(lVar1 + 0x100);

      do {

        if (((*piVar10 == iVar6) && (piVar10[0x1d] == (int)uVar14)) &&

           ((piVar10[0x1e] == param_4 && (piVar10[0x1f] == iVar8)))) {

          if (piVar10 != (int *)0x0) goto LAB_1401e99c1;

          break;

        }

        iVar7 = iVar7 + 1;

        piVar10 = piVar10 + 0x22;

      } while (iVar7 < *(int *)(lVar1 + 0xf8));

    }

    in_stack_fffffffffffffee8 = CONCAT44((int)(in_stack_fffffffffffffee8 >> 0x20),iVar8);

    piVar10 = (int *)FUN_1401e6cf0(param_1,iVar6,uVar14 & 0xffffffff,param_4,

                                   in_stack_fffffffffffffee8);

    if (piVar10 == (int *)0x0) {

      return 0;

    }

LAB_1401e99c1:

    (**(code **)(**(longlong **)(lVar1 + 0x48) + 200))

              (*(longlong **)(lVar1 + 0x48),*(undefined8 *)(piVar10 + 0x20));

    iVar8 = FUN_140240650(*piVar10);

    (**(code **)(**(longlong **)(lVar1 + 0x48) + 0xf0))

              (*(longlong **)(lVar1 + 0x48),*(undefined8 *)(lVar1 + 0xe0 + (longlong)iVar8 * 8));

    bVar4 = true;

    *(int **)(lVar1 + 0x108) = piVar10;

    bVar2 = true;

    lVar9 = local_108;

    bVar3 = bVar2;

  }

  if (lVar9 != *(longlong *)(lVar1 + 0x422b8)) {

    in_stack_fffffffffffffee8 = 0;

    (**(code **)(**(longlong **)(lVar1 + 0x48) + 0x170))

              (*(longlong **)(lVar1 + 0x48),1,&local_108,0,0);

    *(longlong *)(lVar1 + 0x422b8) = local_108;

  }

  if ((*(char *)(lVar1 + 0x42308) != '\0') && (cVar5 = FUN_1401eae20(param_1), cVar5 != '\0')) {

    bVar4 = true;

  }

  if (*(char *)(lVar1 + 0x422e0) != '\0') {

    cVar5 = FUN_1401e80a0(param_1,lVar1 + 0x422e4,local_100,1);

    if (cVar5 == '\0') {

      return 0;

    }

    (**(code **)(**(longlong **)(lVar1 + 0x48) + 0xb0))(*(longlong **)(lVar1 + 0x48),1,local_100);

    *(undefined1 *)(lVar1 + 0x422e0) = 0;

  }

  if (bVar2) {

    uVar14 = 0;

    if (param_5 < 1) {

      *(int *)(lVar1 + 0x422c0) = param_5;

    }

    else {

      do {

        uVar11 = FUN_1401e60b0(*(undefined8 *)(lVar1 + 0x80),param_6[uVar14]);

        (**(code **)(**(longlong **)(lVar1 + 0x48) + 0x100))

                  (*(longlong **)(lVar1 + 0x48),(int)uVar14 + 2,uVar11);

        uVar13 = (int)uVar14 + 1;

        uVar14 = (ulonglong)uVar13;

      } while ((int)uVar13 < param_5);

      *(int *)(lVar1 + 0x422c0) = param_5;

      *(longlong *)(lVar1 + 0x422c8) = *param_6;

    }

  }

  if (!bVar3) goto LAB_1401e9bfd;

  if (param_7 < 1) {

LAB_1401e9be8:

    *(int *)(lVar1 + 0x422d0) = param_7;

    if (param_7 < 1) goto LAB_1401e9bfd;

  }

  else {

    uVar11 = FUN_1401e60b0(*(undefined8 *)(lVar1 + 0x90),*param_8);

    if (iVar6 == 1) {

      uVar12 = 3;

    }

    else {

      if (iVar6 != 2) {

        uVar11 = FUN_14012e850(

                              "[direct3d12] Trying to set a sampler for a shader which doesn\'t have one"

                              );

        return uVar11;

      }

      uVar12 = 5;

    }

    (**(code **)(**(longlong **)(lVar1 + 0x48) + 0x100))(*(longlong **)(lVar1 + 0x48),uVar12,uVar11)

    ;

    if (param_7 < 2) goto LAB_1401e9be8;

    uVar11 = FUN_1401e60b0(*(undefined8 *)(lVar1 + 0x90),param_8[1]);

    (**(code **)(**(longlong **)(lVar1 + 0x48) + 0x100))(*(longlong **)(lVar1 + 0x48),6,uVar11);

    *(int *)(lVar1 + 0x422d0) = param_7;

  }

  *(longlong *)(lVar1 + 0x422d8) = *param_8;

LAB_1401e9bfd:

  if (bVar4) {

    local_e8 = *(undefined8 *)(lVar1 + 0x42268);

    uStack_e0 = *(undefined8 *)(lVar1 + 0x42270);

    local_d8 = *(undefined8 *)(lVar1 + 0x42278);

    uStack_d0 = *(undefined8 *)(lVar1 + 0x42280);

    local_c8 = *(undefined4 *)(lVar1 + 0x42288);

    uStack_c4 = *(undefined4 *)(lVar1 + 0x4228c);

    uStack_c0 = *(undefined4 *)(lVar1 + 0x42290);

    uStack_bc = *(undefined4 *)(lVar1 + 0x42294);

    in_stack_fffffffffffffee8 = in_stack_fffffffffffffee8 & 0xffffffff00000000;

    local_b8 = *(undefined4 *)(lVar1 + 0x42298);

    uStack_b4 = *(undefined4 *)(lVar1 + 0x4229c);

    uStack_b0 = *(undefined4 *)(lVar1 + 0x422a0);

    uStack_ac = *(undefined4 *)(lVar1 + 0x422a4);

    (**(code **)(**(longlong **)(lVar1 + 0x48) + 0x120))

              (*(longlong **)(lVar1 + 0x48),0,0x10,&local_e8,in_stack_fffffffffffffee8);

  }

  if (param_3 == (undefined8 *)0x0) {

    FUN_1401e9e20(param_1,param_2,0,local_a8);

    param_3 = local_a8;

  }

  if ((bVar4) || (iVar8 = memcmp(param_3,piVar10 + 1,0x70), iVar8 != 0)) {

    (**(code **)(**(longlong **)(lVar1 + 0x48) + 0x120))

              (*(longlong **)(lVar1 + 0x48),1,0x1c,param_3,

               in_stack_fffffffffffffee8 & 0xffffffff00000000);

    uVar11 = param_3[1];

    *(undefined8 *)(piVar10 + 1) = *param_3;

    *(undefined8 *)(piVar10 + 3) = uVar11;

    uVar11 = param_3[3];

    *(undefined8 *)(piVar10 + 5) = param_3[2];

    *(undefined8 *)(piVar10 + 7) = uVar11;

    uVar11 = param_3[5];

    *(undefined8 *)(piVar10 + 9) = param_3[4];

    *(undefined8 *)(piVar10 + 0xb) = uVar11;

    uVar11 = param_3[7];

    *(undefined8 *)(piVar10 + 0xd) = param_3[6];

    *(undefined8 *)(piVar10 + 0xf) = uVar11;

    uVar11 = param_3[9];

    *(undefined8 *)(piVar10 + 0x11) = param_3[8];

    *(undefined8 *)(piVar10 + 0x13) = uVar11;

    uVar11 = param_3[0xb];

    *(undefined8 *)(piVar10 + 0x15) = param_3[10];

    *(undefined8 *)(piVar10 + 0x17) = uVar11;

    uVar11 = param_3[0xd];

    *(undefined8 *)(piVar10 + 0x19) = param_3[0xc];

    *(undefined8 *)(piVar10 + 0x1b) = uVar11;

  }

  return 1;

}




