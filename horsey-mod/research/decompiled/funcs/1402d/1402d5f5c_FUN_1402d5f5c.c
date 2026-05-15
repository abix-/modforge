// Address: 0x1402d5f5c
// Ghidra name: FUN_1402d5f5c
// ============ 0x1402d5f5c FUN_1402d5f5c (size=1532) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



undefined8 FUN_1402d5f5c(longlong param_1)



{

  int *piVar1;

  longlong *plVar2;

  bool bVar3;

  char cVar4;

  ushort uVar5;

  short sVar6;

  longlong lVar7;

  undefined8 uVar8;

  undefined2 uVar9;

  uint uVar10;

  int iVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  int iVar15;

  longlong lVar16;

  undefined1 auStack_88 [32];

  undefined8 local_68;

  undefined8 local_50;

  ulonglong local_48 [2];

  undefined4 local_38;

  undefined2 local_34;

  ulonglong local_30;

  ulonglong uVar11;

  

  local_48[1] = 0xfffffffffffffffe;

  local_30 = DAT_1403e8b00 ^ (ulonglong)auStack_88;

  uVar5 = *(ushort *)(param_1 + 0x3a);

  uVar9 = 0x78;

  if (uVar5 < 0x65) {

    if (uVar5 == 100) {

LAB_1402d6047:

      *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x10;

LAB_1402d604b:

      cVar4 = FUN_1402d2e70(param_1,0);

    }

    else if (uVar5 < 0x54) {

      if (uVar5 == 0x53) {

LAB_1402d608d:

        cVar4 = FUN_1402d7384(param_1);

      }

      else {

        if (uVar5 != 0x41) {

          if (uVar5 == 0x43) {

LAB_1402d6001:

            cVar4 = FUN_1402d716c(param_1,0);

            goto LAB_1402d60af;

          }

          if (((uVar5 != 0x45) && (uVar5 != 0x46)) && (uVar5 != 0x47)) {

            return 0;

          }

        }

LAB_1402d5fd8:

        cVar4 = FUN_1402d6e1c(param_1);

      }

    }

    else {

      if (uVar5 == 0x58) goto LAB_1402d60a5;

      if (uVar5 != 0x5a) {

        if (uVar5 != 0x61) {

          if (uVar5 != 99) {

            return 0;

          }

          goto LAB_1402d6001;

        }

        goto LAB_1402d5fd8;

      }

      cVar4 = FUN_1402d6b4c(param_1);

    }

  }

  else if (uVar5 < 0x70) {

    if (uVar5 == 0x6f) {

      if ((*(uint *)(param_1 + 0x28) >> 5 & 1) != 0) {

        *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x80;

      }

      cVar4 = FUN_1402d2a60(param_1,0);

    }

    else {

      if (((uVar5 == 0x65) || (uVar5 == 0x66)) || (uVar5 == 0x67)) goto LAB_1402d5fd8;

      if (uVar5 == 0x69) goto LAB_1402d6047;

      if (uVar5 != 0x6e) {

        return 0;

      }

      cVar4 = FUN_1402d7230(param_1);

    }

  }

  else {

    if (uVar5 == 0x70) {

      *(undefined4 *)(param_1 + 0x30) = 0x10;

      *(undefined4 *)(param_1 + 0x34) = 0xb;

LAB_1402d60a5:

      uVar8 = 1;

    }

    else {

      if (uVar5 == 0x73) goto LAB_1402d608d;

      if (uVar5 == 0x75) goto LAB_1402d604b;

      if (uVar5 != 0x78) {

        return 0;

      }

      uVar8 = 0;

    }

    cVar4 = FUN_1402d3280(param_1,uVar8);

  }

LAB_1402d60af:

  uVar14 = 0;

  if (cVar4 == '\0') {

    return 0;

  }

  if (*(char *)(param_1 + 0x38) != '\0') {

    return 1;

  }

  local_38 = 0;

  local_34 = 0;

  uVar10 = *(uint *)(param_1 + 0x28);

  uVar13 = uVar14;

  if ((uVar10 >> 4 & 1) != 0) {

    if ((uVar10 >> 6 & 1) == 0) {

      if ((*(byte *)(param_1 + 0x28) & 1) != 0) {

        uVar5 = 0x2b;

        goto LAB_1402d60f2;

      }

      if ((uVar10 >> 1 & 1) == 0) goto LAB_1402d6117;

      local_38 = 0x20;

    }

    else {

      uVar5 = 0x2d;

LAB_1402d60f2:

      local_38 = (uint)uVar5;

    }

    uVar13 = 1;

  }

LAB_1402d6117:

  sVar6 = *(short *)(param_1 + 0x3a);

  if (((sVar6 - 0x58U & 0xffdf) != 0) || (bVar3 = true, (uVar10 >> 5 & 1) == 0)) {

    bVar3 = false;

  }

  if ((bVar3) || ((sVar6 - 0x41U & 0xffdf) == 0)) {

    *(undefined2 *)((longlong)&local_38 + uVar13 * 2) = 0x30;

    if ((sVar6 == 0x58) || (sVar6 == 0x41)) {

      uVar9 = 0x58;

    }

    *(undefined2 *)((longlong)&local_38 + uVar13 * 2 + 2) = uVar9;

    uVar13 = uVar13 + 2;

  }

  iVar15 = (*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x48)) - (int)uVar13;

  if (((uVar10 & 0xc) == 0) && (uVar8 = *(undefined8 *)(param_1 + 8), uVar11 = uVar14, 0 < iVar15))

  {

    while ((((*(uint *)(*(longlong *)(param_1 + 0x460) + 0x14) >> 0xc & 1) != 0 &&

            (*(longlong *)(*(longlong *)(param_1 + 0x460) + 8) == 0)) ||

           (sVar6 = FUN_1402f0614(0x20,*(undefined8 *)(param_1 + 0x460),uVar8), sVar6 != -1))) {

      iVar12 = *(int *)(param_1 + 0x20);

      *(int *)(param_1 + 0x20) = iVar12 + 1;

      if ((iVar12 == -2) ||

         (uVar10 = (int)uVar11 + 1, uVar11 = (ulonglong)uVar10, iVar15 <= (int)uVar10))

      goto LAB_1402d61f4;

    }

    *(undefined4 *)(param_1 + 0x20) = 0xffffffff;

  }

LAB_1402d61f4:

  plVar2 = (longlong *)(param_1 + 0x460);

  piVar1 = (int *)(param_1 + 0x20);

  if (((*(uint *)(*plVar2 + 0x14) >> 0xc & 1) == 0) || (*(longlong *)(*plVar2 + 8) != 0)) {

    local_68 = *(undefined8 *)(param_1 + 8);

    FUN_1402d7810(plVar2,&local_38,uVar13,piVar1);

  }

  else {

    *piVar1 = *piVar1 + (int)uVar13;

  }

  if ((((*(uint *)(param_1 + 0x28) >> 3 & 1) != 0) && ((*(uint *)(param_1 + 0x28) >> 2 & 1) == 0))

     && (uVar8 = *(undefined8 *)(param_1 + 8), uVar13 = uVar14, 0 < iVar15)) {

    while ((((*(uint *)(*plVar2 + 0x14) >> 0xc & 1) != 0 && (*(longlong *)(*plVar2 + 8) == 0)) ||

           (sVar6 = FUN_1402f0614(0x30,*plVar2,uVar8), sVar6 != -1))) {

      iVar12 = *piVar1;

      *piVar1 = iVar12 + 1;

      if ((iVar12 == -2) ||

         (uVar10 = (int)uVar13 + 1, uVar13 = (ulonglong)uVar10, iVar15 <= (int)uVar10))

      goto LAB_1402d62a5;

    }

    *piVar1 = -1;

  }

LAB_1402d62a5:

  if ((*(char *)(param_1 + 0x4c) == '\0') && (0 < *(int *)(param_1 + 0x48))) {

    lVar7 = *(longlong *)(param_1 + 8);

    if (*(char *)(lVar7 + 0x28) == '\0') {

      FUN_1402d74e0(lVar7);

    }

    if (*(int *)(*(longlong *)(lVar7 + 0x18) + 0xc) == 0xfde9) {

      local_48[0] = *(ulonglong *)(param_1 + 0x40);

      local_50 = 0;

      uVar13 = uVar14;

      if (*(int *)(param_1 + 0x48) != 0) {

        do {

          iVar12 = (int)uVar13;

          local_38 = 0;

          local_68 = *(undefined8 *)(param_1 + 8);

          lVar7 = FUN_1402f0444(&local_38,local_48,2,&local_50);

          if (lVar7 == -1) goto LAB_1402d63cf;

          if ((((*(uint *)(*(longlong *)(param_1 + 0x460) + 0x14) >> 0xc & 1) == 0) ||

              (*(longlong *)(*(longlong *)(param_1 + 0x460) + 8) != 0)) &&

             (sVar6 = FUN_1402f0614((undefined2)local_38,*(undefined8 *)(param_1 + 0x460),

                                    *(undefined8 *)(param_1 + 8)), sVar6 == -1)) {

            *(undefined4 *)(param_1 + 0x20) = 0xffffffff;

          }

          else {

            *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;

          }

          if (lVar7 == 2) {

            if ((((*(uint *)(*(longlong *)(param_1 + 0x460) + 0x14) >> 0xc & 1) == 0) ||

                (*(longlong *)(*(longlong *)(param_1 + 0x460) + 8) != 0)) &&

               (sVar6 = FUN_1402f0614(local_38._2_2_,*(undefined8 *)(param_1 + 0x460),

                                      *(undefined8 *)(param_1 + 8)), sVar6 == -1)) {

              *(undefined4 *)(param_1 + 0x20) = 0xffffffff;

            }

            else {

              *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;

            }

            iVar12 = iVar12 + 1;

          }

          uVar13 = (ulonglong)(iVar12 + 1U);

        } while (iVar12 + 1U != *(uint *)(param_1 + 0x48));

      }

    }

    else {

      lVar7 = *(longlong *)(param_1 + 8);

      if (*(char *)(lVar7 + 0x28) == '\0') {

        FUN_1402d74e0(lVar7);

      }

      lVar16 = *(longlong *)(param_1 + 0x40);

      uVar13 = uVar14;

      if (*(int *)(param_1 + 0x48) != 0) {

        do {

          local_38 = local_38 & 0xffff0000;

          iVar12 = FUN_1402eff44(&local_38,lVar16,

                                 (longlong)*(int *)(*(longlong *)(lVar7 + 0x18) + 8),

                                 *(undefined8 *)(param_1 + 8));

          if (iVar12 < 1) goto LAB_1402d63cf;

          if ((((*(uint *)(*(longlong *)(param_1 + 0x460) + 0x14) >> 0xc & 1) == 0) ||

              (*(longlong *)(*(longlong *)(param_1 + 0x460) + 8) != 0)) &&

             (sVar6 = FUN_1402f0614((undefined2)local_38,*(undefined8 *)(param_1 + 0x460),

                                    *(undefined8 *)(param_1 + 8)), sVar6 == -1)) {

            *(undefined4 *)(param_1 + 0x20) = 0xffffffff;

          }

          else {

            *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;

          }

          lVar16 = lVar16 + iVar12;

          uVar10 = (int)uVar13 + 1;

          uVar13 = (ulonglong)uVar10;

        } while (uVar10 != *(uint *)(param_1 + 0x48));

      }

    }

  }

  else {

    plVar2 = (longlong *)(param_1 + 0x460);

    if (((*(uint *)(*plVar2 + 0x14) >> 0xc & 1) == 0) || (*(longlong *)(*plVar2 + 8) != 0)) {

      local_68 = *(undefined8 *)(param_1 + 8);

      FUN_1402d7810(plVar2,*(undefined8 *)(param_1 + 0x40));

    }

    else {

      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x48);

    }

  }

LAB_1402d64b7:

  if (((-1 < *(int *)(param_1 + 0x20)) && ((*(uint *)(param_1 + 0x28) >> 2 & 1) != 0)) &&

     (uVar8 = *(undefined8 *)(param_1 + 8), 0 < iVar15)) {

    while ((((*(uint *)(*(longlong *)(param_1 + 0x460) + 0x14) >> 0xc & 1) != 0 &&

            (*(longlong *)(*(longlong *)(param_1 + 0x460) + 8) == 0)) ||

           (sVar6 = FUN_1402f0614(0x20,*(undefined8 *)(param_1 + 0x460),uVar8), sVar6 != -1))) {

      iVar12 = *(int *)(param_1 + 0x20);

      *(int *)(param_1 + 0x20) = iVar12 + 1;

      if (iVar12 == -2) {

        return 1;

      }

      uVar10 = (int)uVar14 + 1;

      uVar14 = (ulonglong)uVar10;

      if (iVar15 <= (int)uVar10) {

        return 1;

      }

    }

    *(undefined4 *)(param_1 + 0x20) = 0xffffffff;

  }

  return 1;

LAB_1402d63cf:

  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;

  goto LAB_1402d64b7;

}




