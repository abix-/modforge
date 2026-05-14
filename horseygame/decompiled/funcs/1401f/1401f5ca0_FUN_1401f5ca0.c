// Address: 0x1401f5ca0
// Ghidra name: FUN_1401f5ca0
// ============ 0x1401f5ca0 FUN_1401f5ca0 (size=857) ============


undefined8

FUN_1401f5ca0(longlong param_1,undefined4 param_2,longlong param_3,undefined8 param_4,

             undefined8 param_5,int param_6,undefined8 *param_7,undefined4 param_8,longlong param_9)



{

  int *piVar1;

  longlong lVar2;

  undefined8 *puVar3;

  int iVar4;

  undefined8 **ppuVar5;

  longlong lVar6;

  undefined8 uVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  uint uVar10;

  longlong lVar11;

  undefined8 local_res8;

  longlong local_res18 [2];

  undefined4 local_168;

  undefined8 local_164;

  undefined4 local_15c;

  undefined8 local_158;

  undefined8 local_150;

  longlong *local_148;

  undefined8 local_140;

  undefined8 local_138;

  undefined8 local_130;

  undefined4 local_128;

  undefined8 local_124;

  undefined4 local_11c;

  undefined8 local_118;

  int local_110 [4];

  undefined8 *local_100 [25];

  

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  uVar10 = *(uint *)(lVar2 + 0x2850);

  local_158 = *(undefined8 *)

               (*(longlong *)

                 (*(longlong *)(lVar2 + 0x2840) + (ulonglong)*(uint *)(lVar2 + 0x690) * 8) +

               (ulonglong)uVar10 * 8);

  local_148 = local_res18;

  local_164 = 0;

  local_15c = 0;

  local_150 = 1;

  local_168 = 0x22;

  local_res8 = 0;

  local_res18[0] = param_3;

  if (*(uint *)(lVar2 + 0x2854) < 0x1000) {

    iVar4 = (*DAT_1403fcea8)(*(undefined8 *)(lVar2 + 0x660),&local_168,&local_res8);

  }

  else {

    iVar4 = -2;

  }

  if (iVar4 == 0) {

LAB_1401f5dc2:

    *(int *)(lVar2 + 0x2854) = *(int *)(lVar2 + 0x2854) + 1;

    uVar8 = 1;

    lVar11 = (longlong)param_6;

    local_138 = param_5;

    local_124 = 0;

    local_11c = 0;

    local_100[0] = (undefined8 *)0x0;

    local_100[0x12] = (undefined8 *)0x0;

    local_100[1] = &local_140;

    local_130 = 0x30;

    local_128 = 0x23;

    local_118 = local_res8;

    local_110[0] = 0;

    local_110[1] = 0;

    local_110[2] = 1;

    local_110[3] = 6;

    local_100[2] = (undefined8 *)0x0;

    local_100[3] = (undefined8 *)0x0;

    local_100[4] = (undefined8 *)0x0;

    local_100[5] = (undefined8 *)0x0;

    local_100[6] = (undefined8 *)0x0;

    local_100[7] = (undefined8 *)0x0;

    local_100[8] = (undefined8 *)0x0;

    local_100[9] = (undefined8 *)0x0;

    local_100[10] = (undefined8 *)0x0;

    local_100[0xb] = (undefined8 *)0x0;

    local_100[0xc] = (undefined8 *)0x0;

    local_100[0xd] = (undefined8 *)0x0;

    local_100[0xe] = (undefined8 *)0x0;

    local_100[0xf] = (undefined8 *)0x0;

    local_100[0x10] = (undefined8 *)0x0;

    local_100[0x11] = (undefined8 *)0x0;

    if (0 < lVar11) {

      ppuVar5 = local_100 + 0x13;

      iVar4 = 1;

      param_9 = param_9 - (longlong)param_7;

      uVar9 = uVar8;

      do {

        *ppuVar5 = (undefined8 *)0x0;

        ppuVar5[1] = (undefined8 *)0x0;

        ppuVar5[2] = (undefined8 *)0x0;

        if (local_res18[0] == *(longlong *)(lVar2 + 0x748)) {

          *ppuVar5 = *(undefined8 **)((longlong)param_7 + param_9);

        }

        puVar3 = (undefined8 *)*param_7;

        param_7 = param_7 + 1;

        ppuVar5[1] = puVar3;

        uVar8 = (ulonglong)((int)uVar9 + 1);

        *(undefined4 *)(ppuVar5 + 2) = 5;

        local_110[uVar9 * 0x10] = iVar4;

        iVar4 = iVar4 + 1;

        local_100[uVar9 * 8] = ppuVar5;

        ppuVar5 = ppuVar5 + 3;

        (&local_128)[uVar9 * 0x10] = 0x23;

        (&local_118)[uVar9 * 8] = local_res8;

        local_110[uVar9 * 0x10 + 1] = 0;

        local_110[uVar9 * 0x10 + 2] = 1;

        local_110[uVar9 * 0x10 + 3] = 1;

        lVar11 = lVar11 + -1;

        uVar9 = uVar8;

      } while (lVar11 != 0);

    }

    local_140 = param_4;

    (*DAT_1403fd0b8)(*(undefined8 *)(lVar2 + 0x660),uVar8,&local_128,0,0);

  }

  else {

    uVar10 = uVar10 + 1;

    if (uVar10 < *(uint *)(*(longlong *)(lVar2 + 0x2848) + (ulonglong)*(uint *)(lVar2 + 0x690) * 4))

    {

      local_158 = *(undefined8 *)

                   (*(longlong *)

                     (*(longlong *)(lVar2 + 0x2840) + (ulonglong)*(uint *)(lVar2 + 0x690) * 8) +

                   (ulonglong)uVar10 * 8);

      iVar4 = (*DAT_1403fcea8)(*(undefined8 *)(lVar2 + 0x660),&local_168,&local_res8);

      if (iVar4 == 0) {

        *(uint *)(lVar2 + 0x2850) = uVar10;

        *(undefined4 *)(lVar2 + 0x2854) = 0;

        goto LAB_1401f5dc2;

      }

      FUN_14012e850("Unable to allocate descriptor set");

    }

    else {

      lVar11 = FUN_1401f5bb0(lVar2);

      if (lVar11 != 0) {

        piVar1 = (int *)(*(longlong *)(lVar2 + 0x2848) + (ulonglong)*(uint *)(lVar2 + 0x690) * 4);

        *piVar1 = *piVar1 + 1;

        lVar6 = FUN_140184230(*(undefined8 *)

                               (*(longlong *)(lVar2 + 0x2840) +

                               (ulonglong)*(uint *)(lVar2 + 0x690) * 8),

                              (ulonglong)

                              *(uint *)(*(longlong *)(lVar2 + 0x2848) +

                                       (ulonglong)*(uint *)(lVar2 + 0x690) * 4) << 3);

        *(longlong *)

         (lVar6 + (ulonglong)

                  (*(int *)(*(longlong *)(lVar2 + 0x2848) + (ulonglong)*(uint *)(lVar2 + 0x690) * 4)

                  - 1) * 8) = lVar11;

        *(longlong *)(*(longlong *)(lVar2 + 0x2840) + (ulonglong)*(uint *)(lVar2 + 0x690) * 8) =

             lVar6;

        *(uint *)(lVar2 + 0x2850) = uVar10;

        *(undefined4 *)(lVar2 + 0x2854) = 0;

        uVar7 = FUN_1401f5ca0(param_1,param_2,local_res18[0],param_4,param_5,param_6,param_7,param_8

                              ,param_9);

        return uVar7;

      }

    }

    local_res8 = 0;

  }

  return local_res8;

}




