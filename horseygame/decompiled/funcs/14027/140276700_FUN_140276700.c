// Address: 0x140276700
// Ghidra name: FUN_140276700
// ============ 0x140276700 FUN_140276700 (size=604) ============


void FUN_140276700(undefined4 *param_1,undefined4 *param_2)



{

  undefined2 uVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  float fVar8;

  undefined4 uVar9;

  undefined4 uVar10;

  int local_res8 [2];

  int local_res10 [2];

  int local_res18 [2];

  int local_res20 [2];

  

  *(undefined8 *)(param_1 + 1) = 0;

  *(undefined8 *)(param_1 + 3) = 0;

  *(undefined8 *)(param_1 + 5) = 0;

  *(undefined8 *)(param_1 + 7) = 0;

  *(undefined8 *)(param_1 + 9) = 0;

  *(undefined8 *)(param_1 + 0xb) = 0;

  *(undefined8 *)(param_1 + 0xd) = 0;

  *(undefined8 *)(param_1 + 0xf) = 0;

  *(undefined2 *)(param_1 + 0x11) = 0;

  *param_1 = 2;

  param_1[1] = *param_2;

  uVar2 = *(ulonglong *)(param_2 + 1);

  uVar3 = uVar2 & 0xffffff0000ffffff;

  *(ulonglong *)(param_1 + 2) = uVar3;

  uVar1 = *(undefined2 *)(param_2 + 3);

  if (((uint)param_2[1] >> 0x13 & 1) == 0) {

    *(undefined2 *)(param_1 + 7) = uVar1;

    *(undefined2 *)(param_1 + 0x15) = uVar1;

    uVar1 = *(undefined2 *)((longlong)param_2 + 0xe);

    *(undefined2 *)((longlong)param_1 + 0x1e) = uVar1;

    *(undefined2 *)((longlong)param_1 + 0x56) = uVar1;

    if (((uint)param_2[1] >> 0x17 & 1) == 0) {

      param_1[0x14] = 0;

      if ((uVar3 >> 0x11 & 1) != 0) {

        uVar3 = uVar2 & 0xffffff0000fdffff | 0x400000;

        *(ulonglong *)(param_1 + 2) = uVar3;

      }

    }

    else {

      *(undefined2 *)(param_1 + 4) = *(undefined2 *)(param_1 + 0x14);

      *(undefined2 *)((longlong)param_1 + 0x12) = *(undefined2 *)((longlong)param_1 + 0x52);

    }

  }

  else {

    *(undefined2 *)(param_1 + 0x14) = uVar1;

    *(undefined2 *)(param_1 + 4) = uVar1;

    uVar1 = *(undefined2 *)((longlong)param_2 + 0xe);

    *(undefined2 *)((longlong)param_1 + 0x52) = uVar1;

    *(undefined2 *)((longlong)param_1 + 0x12) = uVar1;

    if (((uint)param_2[1] >> 0x17 & 1) == 0) {

      param_1[0x15] = 0;

    }

    else {

      *(undefined2 *)(param_1 + 7) = *(undefined2 *)(param_1 + 0x15);

      *(undefined2 *)((longlong)param_1 + 0x1e) = *(undefined2 *)((longlong)param_1 + 0x56);

    }

  }

  if (((uint)param_2[1] >> 0x17 & 1) != 0) {

    *(ulonglong *)(param_1 + 2) = uVar3 | 0x80000;

  }

  uVar10 = DAT_14037f690;

  local_res18[0] = (int)*(short *)(param_2 + 4);

  local_res8[0] = (int)*(short *)(param_1 + 4);

  *(short *)(param_1 + 5) = *(short *)(param_2 + 4);

  local_res20[0] = (int)*(short *)((longlong)param_2 + 0x12);

  local_res10[0] = (int)*(short *)((longlong)param_1 + 0x12);

  *(short *)((longlong)param_1 + 0x16) = *(short *)((longlong)param_2 + 0x12);

  FUN_140276f00(local_res8,local_res10,uVar10);

  FUN_140276f00(local_res18,local_res20,DAT_14037f680);

  uVar7 = -(uint)((*(ulonglong *)(param_1 + 2) & 0x80000) != 0) & 1000;

  iVar4 = local_res8[0] + uVar7;

  iVar6 = 0x7fff;

  if ((iVar4 < 0x8000) && (iVar6 = iVar4, iVar4 < -0x8000)) {

    iVar6 = -0x8000;

  }

  *(short *)(param_1 + 4) = (short)iVar6;

  iVar5 = local_res10[0] + uVar7;

  iVar4 = 0x7fff;

  iVar6 = iVar4;

  if ((iVar5 < 0x8000) && (iVar6 = iVar5, iVar5 < -0x8000)) {

    iVar6 = -0x8000;

  }

  *(short *)((longlong)param_1 + 0x12) = (short)iVar6;

  uVar7 = -(uint)((*(ulonglong *)(param_1 + 2) & 0x100000) != 0) & 1000;

  iVar6 = local_res18[0] + uVar7;

  if ((iVar6 < 0x8000) && (iVar4 = iVar6, iVar6 < -0x8000)) {

    iVar4 = -0x8000;

  }

  *(short *)(param_1 + 5) = (short)iVar4;

  uVar9 = DAT_14037f688;

  uVar10 = DAT_1403053f0;

  iVar4 = local_res20[0] + uVar7;

  iVar6 = 0x7fff;

  if ((iVar4 < 0x8000) && (iVar6 = iVar4, iVar4 < -0x8000)) {

    iVar6 = -0x8000;

  }

  *(short *)((longlong)param_1 + 0x16) = (short)iVar6;

  fVar8 = (float)FUN_140276c60((uint)*(byte *)((longlong)param_2 + 7) << 7 |

                               (uint)*(byte *)((longlong)param_2 + 7),0,uVar9,0,uVar10);

  *(short *)(param_1 + 9) = (short)(int)fVar8;

  fVar8 = (float)FUN_140276c60((uint)*(byte *)(param_2 + 2) << 7 | (uint)*(byte *)(param_2 + 2),0,

                               uVar9,0,uVar10);

  *(short *)((longlong)param_1 + 0x26) = (short)(int)fVar8;

  return;

}




