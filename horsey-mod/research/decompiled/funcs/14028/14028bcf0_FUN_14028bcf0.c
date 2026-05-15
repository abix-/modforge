// Address: 0x14028bcf0
// Ghidra name: FUN_14028bcf0
// ============ 0x14028bcf0 FUN_14028bcf0 (size=622) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_14028bcf0(ushort *param_1,ulonglong param_2)



{

  ushort uVar1;

  ushort uVar2;

  int iVar3;

  uint uVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  uint uVar7;

  uint uVar8;

  undefined8 uVar9;

  

  uVar1 = FUN_14028aed0();

  uVar6 = (ulonglong)*(uint *)(param_1 + 0x30);

  if ((*(uint *)(param_1 + 0x30) & 2) == 0) {

    uVar2 = FUN_14028af30(param_1);

    *(ulonglong *)(param_1 + 0x28) = (ulonglong)uVar2 + *(longlong *)(param_1 + 0x24);

    if ((uVar6 & 8) == 0) {

      *(ulonglong *)(param_1 + 0x38) = (ulonglong)uVar2 + *(longlong *)(param_1 + 0x24);

    }

    uVar9 = thunk_FUN_1402d0f80(((double)((int)((uint)uVar1 * 0x168) >> 0x10) * DAT_140333080) /

                                _DAT_140333088);

    *(undefined8 *)(param_1 + 0x44) = uVar9;

    uVar2 = *param_1;

    if ((uVar2 == 2) || ((uVar2 < 0x21 && ((0x100010110U >> ((ulonglong)uVar2 & 0x3f) & 1) != 0))))

    {

      *(uint *)(param_1 + 0x3e) = ((uint)param_1[0x12] * 0x168) / (uint)param_1[0xf];

    }

    iVar3 = FUN_14028af90(param_1);

    if (iVar3 != 0) {

      uVar4 = FUN_14028af90();

      *(ulonglong *)(param_1 + 0x2c) = (ulonglong)uVar4 + *(longlong *)(param_1 + 0x28);

    }

  }

  uVar4 = *(uint *)(param_1 + 0x30);

  *(uint *)(param_1 + 0x30) = uVar4 | 2;

  if ((uVar4 & 8) != 0) {

    *(uint *)(param_1 + 0x30) = uVar4 & 0xfffffffb | 2;

    uVar2 = FUN_14028af30(param_1);

    *(ulonglong *)(param_1 + 0x28) = (ulonglong)uVar2 + *(longlong *)(param_1 + 0x38);

    uVar9 = thunk_FUN_1402d0f80(((double)((int)((uint)uVar1 * 0x168) >> 0x10) * DAT_140333080) /

                                _DAT_140333088);

    *(undefined8 *)(param_1 + 0x44) = uVar9;

    iVar3 = FUN_14028af90(param_1);

    if (iVar3 != 0) {

      uVar4 = FUN_14028af90();

      *(ulonglong *)(param_1 + 0x2c) = (ulonglong)uVar4 + *(longlong *)(param_1 + 0x38);

    }

    uVar1 = *param_1;

    if ((uVar1 == 2) || ((uVar1 < 0x21 && ((0x100010110U >> ((ulonglong)uVar1 & 0x3f) & 1) != 0))))

    {

      *(undefined4 *)(param_1 + 0x3e) = *(undefined4 *)(param_1 + 0x3c);

    }

  }

  uVar4 = *(uint *)(param_1 + 0x30);

  uVar8 = uVar4 & 0xfffffff7;

  uVar6 = (ulonglong)uVar8;

  param_1[0x48] = 0;

  param_1[0x49] = 0;

  *(uint *)(param_1 + 0x30) = uVar8;

  uVar1 = *param_1;

  if (((uVar1 == 0x40) && (*(int *)(param_1 + 10) != 0)) &&

     (uVar7 = (*(int *)(param_1 + 10) - (uint)param_1[0x13]) - (uint)param_1[0x11], uVar7 != 0)) {

    *(uint *)(param_1 + 0x48) =

         (uint)((short)param_1[0x10] * 0x10000 + (short)param_1[0xf] * -0x10000) / uVar7;

  }

  uVar5 = (ulonglong)uVar8;

  if (((uVar4 & 4) == 0) && (*(ulonglong *)(param_1 + 0x28) <= param_2)) {

    iVar3 = FUN_14028af90(param_1);

    if ((iVar3 == 0) || (uVar5 = uVar6 & 0xffffffff, param_2 < *(ulonglong *)(param_1 + 0x2c))) {

      uVar4 = (uint)uVar6 | 4;

      uVar5 = (ulonglong)uVar4;

      *(uint *)(param_1 + 0x30) = uVar4;

    }

  }

  if ((uVar5 & 4) != 0) {

    *(ulonglong *)(param_1 + 0x34) = param_2 - *(longlong *)(param_1 + 0x28);

    if (uVar1 != 2) {

      uVar1 = *param_1;

      uVar6 = (ulonglong)uVar1;

      if (uVar1 != 8) {

        if (0x20 < uVar1) {

          return uVar6;

        }

        if ((0x100010010U >> (uVar6 & 0x3f) & 1) == 0) {

          return uVar6;

        }

      }

    }

    uVar5 = (ulonglong)*(uint *)(param_1 + 0x3e) * 0x6c16c16d & 0xffffffff;

    *(uint *)(param_1 + 0x3c) =

         (int)((((param_2 - *(longlong *)(param_1 + 0x38)) % (ulonglong)param_1[0xf]) * 0x168) /

              (ulonglong)param_1[0xf]) + *(uint *)(param_1 + 0x3e) % 0x168;

  }

  return uVar5;

}




