// Address: 0x1401a63b0
// Ghidra name: FUN_1401a63b0
// ============ 0x1401a63b0 FUN_1401a63b0 (size=1912) ============


int FUN_1401a63b0(longlong *param_1,int param_2)



{

  uint *puVar1;

  longlong lVar2;

  int iVar3;

  bool bVar4;

  uint uVar5;

  int iVar6;

  longlong lVar7;

  undefined1 *puVar8;

  uint uVar9;

  uint uVar10;

  uint uVar11;

  undefined8 uVar12;

  ulonglong *puVar13;

  

  iVar6 = 0;

  if (((*(uint *)(param_1 + 2) & 0x80000) == 0) ||

     (*(uint *)((longlong)param_1 + 0x2c) <

      (uint)(*(int *)((longlong)param_1 + 0x24) - (int)param_1[0xb]))) {

    bVar4 = false;

  }

  else {

    bVar4 = true;

  }

  if ((*param_1 == 0) && (0x14ccb < (ulonglong)(*(longlong *)param_1[0x14] - param_1[0x18]))) {

    lVar7 = param_1[0x12] + param_1[0x18];

  }

  else {

    lVar7 = (longlong)param_1 + 0x392aa;

  }

  param_1[8] = lVar7;

  param_1[9] = lVar7 + 0x14cbc;

  param_1[0xe] = 0;

  *(byte *)param_1[7] = *(byte *)param_1[7] >> (*(byte *)(param_1 + 10) & 0x1f);

  param_1[6] = param_1[6] - (ulonglong)((int)param_1[10] == 8);

  if (((*(uint *)(param_1 + 2) & 0x1000) != 0) && (*(int *)((longlong)param_1 + 0x7c) == 0)) {

    uVar10 = 0x78 << ((byte)*(int *)((longlong)param_1 + 0x5c) & 0x1f) | *(uint *)(param_1 + 0xc);

    *(uint *)(param_1 + 0xc) = uVar10;

    uVar5 = *(int *)((longlong)param_1 + 0x5c) + 8;

    *(uint *)((longlong)param_1 + 0x5c) = uVar5;

    while (7 < uVar5) {

      if ((undefined1 *)param_1[8] < (undefined1 *)param_1[9]) {

        *(undefined1 *)param_1[8] = (char)uVar10;

        param_1[8] = param_1[8] + 1;

      }

      uVar10 = *(uint *)(param_1 + 0xc) >> 8;

      uVar5 = *(int *)((longlong)param_1 + 0x5c) - 8;

      *(uint *)(param_1 + 0xc) = uVar10;

      *(uint *)((longlong)param_1 + 0x5c) = uVar5;

    }

    uVar10 = uVar10 | 1 << (uVar5 & 0x1f);

    uVar5 = uVar5 + 8;

    *(uint *)(param_1 + 0xc) = uVar10;

    *(uint *)((longlong)param_1 + 0x5c) = uVar5;

    while (7 < uVar5) {

      if ((undefined1 *)param_1[8] < (undefined1 *)param_1[9]) {

        *(undefined1 *)param_1[8] = (char)uVar10;

        param_1[8] = param_1[8] + 1;

      }

      *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) >> 8;

      *(int *)((longlong)param_1 + 0x5c) = *(int *)((longlong)param_1 + 0x5c) + -8;

      uVar10 = (uint)*(byte *)(param_1 + 0xc);

      uVar5 = *(uint *)((longlong)param_1 + 0x5c);

    }

  }

  puVar13 = (ulonglong *)(param_1 + 8);

  uVar5 = *(int *)((longlong)param_1 + 0x5c) + 1;

  uVar10 = (uint)(param_2 == 4) << ((byte)*(int *)((longlong)param_1 + 0x5c) & 0x1f) |

           *(uint *)(param_1 + 0xc);

  *(uint *)(param_1 + 0xc) = uVar10;

  *(uint *)((longlong)param_1 + 0x5c) = uVar5;

  uVar11 = uVar10;

  while (7 < uVar5) {

    if ((undefined1 *)*puVar13 < (undefined1 *)param_1[9]) {

      *(undefined1 *)*puVar13 = (char)uVar11;

      *puVar13 = *puVar13 + 1;

    }

    uVar10 = *(uint *)(param_1 + 0xc) >> 8;

    uVar5 = *(int *)((longlong)param_1 + 0x5c) - 8;

    *(uint *)(param_1 + 0xc) = uVar10;

    uVar11 = uVar10 & 0xff;

    *(uint *)((longlong)param_1 + 0x5c) = uVar5;

  }

  puVar8 = (undefined1 *)param_1[8];

  if (bVar4) {

LAB_1401a65c0:

    puVar13 = (ulonglong *)(param_1 + 8);

    if ((uint)(*(int *)((longlong)param_1 + 0x24) - (int)param_1[0xb]) <=

        *(uint *)((longlong)param_1 + 0x2c)) {

      uVar5 = uVar5 + 2;

      *puVar13 = (ulonglong)puVar8;

      *(uint *)(param_1 + 0xc) = uVar10;

      *(uint *)((longlong)param_1 + 0x5c) = uVar5;

      while (7 < uVar5) {

        if (puVar8 < (undefined1 *)param_1[9]) {

          *puVar8 = (char)uVar10;

          *puVar13 = *puVar13 + 1;

          puVar8 = (undefined1 *)*puVar13;

        }

        uVar10 = *(uint *)(param_1 + 0xc) >> 8;

        uVar5 = *(int *)((longlong)param_1 + 0x5c) - 8;

        *(uint *)(param_1 + 0xc) = uVar10;

        *(uint *)((longlong)param_1 + 0x5c) = uVar5;

      }

      puVar13 = (ulonglong *)(param_1 + 8);

      uVar11 = 0;

      if (uVar5 != 0) {

        *(uint *)(param_1 + 0xc) = uVar10;

        *(undefined4 *)((longlong)param_1 + 0x5c) = 8;

        do {

          if (puVar8 < (undefined1 *)param_1[9]) {

            *puVar8 = (char)uVar10;

            *puVar13 = *puVar13 + 1;

            puVar8 = (undefined1 *)*puVar13;

          }

          uVar10 = *(uint *)(param_1 + 0xc) >> 8;

          uVar11 = *(int *)((longlong)param_1 + 0x5c) - 8;

          *(uint *)(param_1 + 0xc) = uVar10;

          *(uint *)((longlong)param_1 + 0x5c) = uVar11;

        } while (7 < uVar11);

      }

      puVar13 = (ulonglong *)(param_1 + 8);

      uVar5 = uVar11 + 0x10;

      uVar10 = (uint)*(ushort *)((longlong)param_1 + 0x54) << ((byte)uVar11 & 0x1f) | uVar10;

      *(uint *)((longlong)param_1 + 0x5c) = uVar5;

      *(uint *)(param_1 + 0xc) = uVar10;

      while (7 < uVar5) {

        if (puVar8 < (undefined1 *)param_1[9]) {

          *puVar8 = (char)uVar10;

          *puVar13 = *puVar13 + 1;

          puVar8 = (undefined1 *)*puVar13;

        }

        uVar10 = *(uint *)(param_1 + 0xc) >> 8;

        uVar5 = *(int *)((longlong)param_1 + 0x5c) - 8;

        *(uint *)(param_1 + 0xc) = uVar10;

        *(uint *)((longlong)param_1 + 0x5c) = uVar5;

      }

      puVar13 = (ulonglong *)(param_1 + 8);

      *(uint *)((longlong)param_1 + 0x54) = *(uint *)((longlong)param_1 + 0x54) ^ 0xffff;

      uVar11 = uVar5 + 0x10;

      uVar10 = (uint)*(ushort *)((longlong)param_1 + 0x54) << ((byte)uVar5 & 0x1f) | uVar10;

      *(uint *)((longlong)param_1 + 0x5c) = uVar11;

      *(uint *)(param_1 + 0xc) = uVar10;

      while (7 < uVar11) {

        if ((undefined1 *)*puVar13 < (undefined1 *)param_1[9]) {

          *(undefined1 *)*puVar13 = (char)uVar10;

          *puVar13 = *puVar13 + 1;

        }

        *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) >> 8;

        uVar10 = *(uint *)(param_1 + 0xc);

        *(int *)((longlong)param_1 + 0x5c) = *(int *)((longlong)param_1 + 0x5c) + -8;

        uVar11 = *(uint *)((longlong)param_1 + 0x5c);

      }

      puVar13 = (ulonglong *)(param_1 + 8);

      puVar1 = (uint *)((longlong)param_1 + 0x54);

      *puVar1 = *puVar1 ^ 0xffff;

      uVar5 = 0;

      if (*puVar1 != 0) {

        do {

          uVar10 = *(int *)((longlong)param_1 + 0x5c) + 8;

          uVar11 = (uint)*(byte *)((ulonglong)((int)param_1[0xb] + uVar5 & 0x7fff) + 200 +

                                  (longlong)param_1) <<

                   ((byte)*(int *)((longlong)param_1 + 0x5c) & 0x1f) | *(uint *)(param_1 + 0xc);

          *(uint *)(param_1 + 0xc) = uVar11;

          *(uint *)((longlong)param_1 + 0x5c) = uVar10;

          while (7 < uVar10) {

            if ((undefined1 *)*puVar13 < (undefined1 *)param_1[9]) {

              *(undefined1 *)*puVar13 = (char)uVar11;

              *puVar13 = *puVar13 + 1;

            }

            *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) >> 8;

            *(int *)((longlong)param_1 + 0x5c) = *(int *)((longlong)param_1 + 0x5c) + -8;

            uVar11 = (uint)*(byte *)(param_1 + 0xc);

            uVar10 = *(uint *)((longlong)param_1 + 0x5c);

          }

          uVar5 = uVar5 + 1;

        } while (uVar5 < *(uint *)((longlong)param_1 + 0x54));

      }

      goto LAB_1401a6776;

    }

  }

  else {

    if (((*(uint *)(param_1 + 2) & 0x40000) == 0) && (0x2f < *(uint *)((longlong)param_1 + 0x54))) {

      uVar12 = 0;

    }

    else {

      uVar12 = 1;

    }

    iVar6 = FUN_1401a5740(param_1,uVar12);

    uVar11 = *(uint *)((longlong)param_1 + 0x54);

    if ((uVar11 != 0) && ((longlong)(ulonglong)uVar11 <= (param_1[8] - (longlong)puVar8) + 1))

    goto LAB_1401a65c0;

  }

  if (iVar6 == 0) {

    param_1[8] = (longlong)puVar8;

    *(uint *)(param_1 + 0xc) = uVar10;

    *(uint *)((longlong)param_1 + 0x5c) = uVar5;

    FUN_1401a5740(param_1,1);

  }

LAB_1401a6776:

  if (param_2 != 0) {

    if (param_2 == 4) {

      uVar5 = 0;

      if (*(int *)((longlong)param_1 + 0x5c) != 0) {

        uVar10 = (uint)*(byte *)(param_1 + 0xc);

        *(undefined4 *)((longlong)param_1 + 0x5c) = 8;

        do {

          if ((undefined1 *)param_1[8] < (undefined1 *)param_1[9]) {

            *(undefined1 *)param_1[8] = (char)uVar10;

            param_1[8] = param_1[8] + 1;

          }

          *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) >> 8;

          uVar5 = *(int *)((longlong)param_1 + 0x5c) - 8;

          uVar10 = *(uint *)(param_1 + 0xc);

          *(uint *)((longlong)param_1 + 0x5c) = uVar5;

        } while (7 < uVar5);

      }

      if ((*(uint *)(param_1 + 2) & 0x1000) != 0) {

        uVar10 = *(uint *)(param_1 + 4);

        uVar11 = uVar5 + 8;

        uVar5 = (uVar10 >> 0x18) << ((byte)uVar5 & 0x1f) | *(uint *)(param_1 + 0xc);

        *(uint *)(param_1 + 0xc) = uVar5;

        *(uint *)((longlong)param_1 + 0x5c) = uVar11;

        while (7 < uVar11) {

          if ((undefined1 *)param_1[8] < (undefined1 *)param_1[9]) {

            *(undefined1 *)param_1[8] = (char)uVar5;

            param_1[8] = param_1[8] + 1;

          }

          uVar5 = *(uint *)(param_1 + 0xc) >> 8;

          uVar11 = *(int *)((longlong)param_1 + 0x5c) - 8;

          *(uint *)(param_1 + 0xc) = uVar5;

          *(uint *)((longlong)param_1 + 0x5c) = uVar11;

        }

        uVar9 = uVar11 + 8;

        uVar5 = (uVar10 >> 0x10 & 0xff) << ((byte)uVar11 & 0x1f) | uVar5;

        *(uint *)((longlong)param_1 + 0x5c) = uVar9;

        *(uint *)(param_1 + 0xc) = uVar5;

        while (7 < uVar9) {

          if ((undefined1 *)param_1[8] < (undefined1 *)param_1[9]) {

            *(undefined1 *)param_1[8] = (char)uVar5;

            param_1[8] = param_1[8] + 1;

          }

          uVar5 = *(uint *)(param_1 + 0xc) >> 8;

          *(uint *)(param_1 + 0xc) = uVar5;

          uVar9 = *(int *)((longlong)param_1 + 0x5c) - 8;

          *(uint *)((longlong)param_1 + 0x5c) = uVar9;

        }

        uVar11 = uVar9 + 8;

        uVar5 = ((uVar10 & 0xffff) >> 8) << ((byte)uVar9 & 0x1f) | uVar5;

        *(uint *)(param_1 + 0xc) = uVar5;

        *(uint *)((longlong)param_1 + 0x5c) = uVar11;

        while (7 < uVar11) {

          if ((undefined1 *)param_1[8] < (undefined1 *)param_1[9]) {

            *(undefined1 *)param_1[8] = (char)uVar5;

            param_1[8] = param_1[8] + 1;

          }

          uVar5 = *(uint *)(param_1 + 0xc) >> 8;

          *(uint *)(param_1 + 0xc) = uVar5;

          uVar11 = *(int *)((longlong)param_1 + 0x5c) - 8;

          *(uint *)((longlong)param_1 + 0x5c) = uVar11;

        }

        uVar9 = uVar11 + 8;

        uVar5 = (uVar10 & 0xff) << ((byte)uVar11 & 0x1f) | uVar5;

        *(uint *)(param_1 + 0xc) = uVar5;

        *(uint *)((longlong)param_1 + 0x5c) = uVar9;

        while (7 < uVar9) {

          if ((undefined1 *)param_1[8] < (undefined1 *)param_1[9]) {

            *(undefined1 *)param_1[8] = (char)uVar5;

            param_1[8] = param_1[8] + 1;

          }

          *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) >> 8;

          uVar5 = *(uint *)(param_1 + 0xc);

          *(int *)((longlong)param_1 + 0x5c) = *(int *)((longlong)param_1 + 0x5c) + -8;

          uVar9 = *(uint *)((longlong)param_1 + 0x5c);

        }

      }

    }

    else {

      uVar5 = *(uint *)(param_1 + 0xc);

      uVar10 = *(int *)((longlong)param_1 + 0x5c) + 3;

      *(uint *)((longlong)param_1 + 0x5c) = uVar10;

      while (7 < uVar10) {

        if ((undefined1 *)param_1[8] < (undefined1 *)param_1[9]) {

          *(undefined1 *)param_1[8] = (char)uVar5;

          param_1[8] = param_1[8] + 1;

        }

        uVar5 = *(uint *)(param_1 + 0xc) >> 8;

        uVar10 = *(int *)((longlong)param_1 + 0x5c) - 8;

        *(uint *)(param_1 + 0xc) = uVar5;

        *(uint *)((longlong)param_1 + 0x5c) = uVar10;

      }

      uVar11 = 0;

      if (uVar10 != 0) {

        *(uint *)(param_1 + 0xc) = uVar5;

        *(undefined4 *)((longlong)param_1 + 0x5c) = 8;

        do {

          if ((undefined1 *)param_1[8] < (undefined1 *)param_1[9]) {

            *(undefined1 *)param_1[8] = (char)uVar5;

            param_1[8] = param_1[8] + 1;

          }

          uVar5 = *(uint *)(param_1 + 0xc) >> 8;

          uVar11 = *(int *)((longlong)param_1 + 0x5c) - 8;

          *(uint *)(param_1 + 0xc) = uVar5;

          *(uint *)((longlong)param_1 + 0x5c) = uVar11;

        } while (7 < uVar11);

      }

      uVar11 = uVar11 + 0x10;

      *(uint *)(param_1 + 0xc) = uVar5;

      *(uint *)((longlong)param_1 + 0x5c) = uVar11;

      while (7 < uVar11) {

        if ((undefined1 *)param_1[8] < (undefined1 *)param_1[9]) {

          *(undefined1 *)param_1[8] = (char)uVar5;

          param_1[8] = param_1[8] + 1;

        }

        uVar5 = *(uint *)(param_1 + 0xc) >> 8;

        uVar11 = *(int *)((longlong)param_1 + 0x5c) - 8;

        *(uint *)(param_1 + 0xc) = uVar5;

        *(uint *)((longlong)param_1 + 0x5c) = uVar11;

      }

      uVar10 = uVar11 + 0x10;

      uVar5 = 0xffff << ((byte)uVar11 & 0x1f) | uVar5;

      *(uint *)((longlong)param_1 + 0x5c) = uVar10;

      *(uint *)(param_1 + 0xc) = uVar5;

      while (7 < uVar10) {

        if ((undefined1 *)param_1[8] < (undefined1 *)param_1[9]) {

          *(undefined1 *)param_1[8] = (char)uVar5;

          param_1[8] = param_1[8] + 1;

        }

        *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) >> 8;

        uVar5 = *(uint *)(param_1 + 0xc);

        *(int *)((longlong)param_1 + 0x5c) = *(int *)((longlong)param_1 + 0x5c) + -8;

        uVar10 = *(uint *)((longlong)param_1 + 0x5c);

      }

    }

  }

  FUN_1402f94c0((longlong)param_1 + 0x81ca,0,0x240);

  *(undefined8 *)((longlong)param_1 + 0x840a) = 0;

  *(undefined8 *)((longlong)param_1 + 0x8412) = 0;

  *(undefined8 *)((longlong)param_1 + 0x841a) = 0;

  *(undefined8 *)((longlong)param_1 + 0x8422) = 0;

  *(undefined8 *)((longlong)param_1 + 0x842a) = 0;

  *(undefined8 *)((longlong)param_1 + 0x8432) = 0;

  *(undefined8 *)((longlong)param_1 + 0x843a) = 0;

  *(undefined8 *)((longlong)param_1 + 0x8442) = 0;

  *(int *)((longlong)param_1 + 0x7c) = *(int *)((longlong)param_1 + 0x7c) + 1;

  param_1[6] = (longlong)param_1 + 0x92ab;

  param_1[7] = (longlong)param_1 + 0x92aa;

  *(int *)(param_1 + 0xb) = (int)param_1[0xb] + *(int *)((longlong)param_1 + 0x54);

  iVar6 = (int)param_1[8] - (int)lVar7;

  *(undefined4 *)(param_1 + 10) = 8;

  *(undefined4 *)((longlong)param_1 + 0x54) = 0;

  if (iVar6 != 0) {

    if (*param_1 == 0) {

      lVar2 = param_1[0x18];

      if (lVar7 == (longlong)param_1 + 0x392aa) {

        iVar3 = (int)*(longlong *)param_1[0x14] - (int)lVar2;

        if ((ulonglong)(longlong)iVar6 < (ulonglong)(*(longlong *)param_1[0x14] - lVar2)) {

          iVar3 = iVar6;

        }

        FUN_1402f8e20(lVar2 + param_1[0x12],(longlong)param_1 + 0x392aa,(longlong)iVar3);

        param_1[0x18] = param_1[0x18] + (longlong)iVar3;

        iVar6 = iVar6 - iVar3;

        if (iVar6 != 0) {

          *(int *)(param_1 + 0xe) = iVar3;

          *(int *)((longlong)param_1 + 0x74) = iVar6;

          return iVar6;

        }

      }

      else {

        param_1[0x18] = iVar6 + lVar2;

      }

    }

    else {

      *(longlong *)param_1[0x13] = param_1[0x16] - param_1[0x11];

      iVar6 = (*(code *)*param_1)((longlong)param_1 + 0x392aa,iVar6,param_1[1]);

      if (iVar6 == 0) {

        *(undefined4 *)((longlong)param_1 + 0x84) = 0xffffffff;

        return -1;

      }

    }

  }

  return *(int *)((longlong)param_1 + 0x74);

}




