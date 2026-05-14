// Address: 0x14006e480
// Ghidra name: FUN_14006e480
// ============ 0x14006e480 FUN_14006e480 (size=2439) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_14006e480(longlong *param_1,undefined4 param_2)



{

  undefined4 uVar1;

  longlong *plVar2;

  undefined1 auVar3 [16];

  char cVar4;

  int iVar5;

  undefined8 uVar6;

  ulonglong uVar7;

  undefined4 *puVar8;

  longlong lVar9;

  longlong lVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  uint uVar13;

  ulonglong uVar14;

  float fVar15;

  ulonglong local_res18;

  undefined1 local_res20 [8];

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  ulonglong uStack_60;

  longlong local_58 [3];

  ulonglong local_40;

  

  FUN_14008d760(local_58,"save%d.dat",param_2);

  uVar6 = FUN_1400c4df0();

  uVar6 = FUN_14006f590(&local_78,uVar6);

  cVar4 = FUN_1400753f0(0,uVar6);

  if (0xf < uStack_60) {

    uVar11 = local_78;

    if ((0xfff < uStack_60 + 1) &&

       (uVar11 = *(ulonglong *)(local_78 - 8), 0x1f < (local_78 - uVar11) - 8)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(uVar11);

  }

  local_68 = _DAT_14039caa0;

  uStack_60 = _UNK_14039caa8;

  local_78 = local_78 & 0xffffffffffffff00;

  if (0xf < local_40) {

    if ((0xfff < local_40 + 1) && (0x1f < (local_58[0] - *(longlong *)(local_58[0] + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  if (cVar4 == '\0') {

    return 0;

  }

  DAT_1403fb0e0 = FUN_140075da0();

  FUN_1400c8010();

  FUN_140075b80((longlong)param_1 + 0x254);

  FUN_140075b80((longlong)param_1 + 0x314);

  FUN_140075b80(param_1 + 0x4d);

  FUN_140075ed0((longlong)param_1 + 0x114);

  FUN_140075b80(param_1 + 99);

  FUN_140075b80(param_1 + 0x61);

  FUN_140075b80(param_1 + 0x88);

  FUN_140075e80((longlong)param_1 + 0x414);

  FUN_140075e80((longlong)param_1 + 0x415);

  FUN_140075b80((longlong)param_1 + 0x37c);

  local_res20[0] = 0;

  FUN_140075e80(local_res20);

  FUN_140075b80(param_1 + 0x83);

  FUN_140075e80((longlong)param_1 + 0x41c);

  FUN_140075f20(&local_res18,(longlong)param_1 + 0x39c);

  FUN_140075b80(param_1 + 0x82);

  lVar9 = (longlong)param_1 + 0x31c;

  lVar10 = 6;

  do {

    FUN_140075e80(lVar9 + 5);

    FUN_140075b80(lVar9);

    FUN_140075e80(lVar9 + 4);

    lVar9 = lVar9 + 8;

    lVar10 = lVar10 + -1;

  } while (lVar10 != 0);

  lVar9 = (longlong)param_1 + 0x2cc;

  lVar10 = 0xd;

  do {

    FUN_140075b80(lVar9 + -0x34);

    FUN_140075b80(lVar9);

    lVar9 = lVar9 + 4;

    lVar10 = lVar10 + -1;

  } while (lVar10 != 0);

  plVar2 = param_1 + 0x50;

  if (*plVar2 != param_1[0x51]) {

    param_1[0x51] = *plVar2;

  }

  iVar5 = FUN_140075da0();

  uVar12 = (ulonglong)iVar5;

  lVar9 = *plVar2;

  lVar10 = param_1[0x51] - lVar9;

  lVar10 = lVar10 / 0x12 + (lVar10 >> 0x3f);

  uVar11 = (lVar10 >> 1) - (lVar10 >> 0x3f);

  if (uVar12 < uVar11) {

    param_1[0x51] = lVar9 + uVar12 * 0x24;

  }

  else if (uVar11 < uVar12) {

    if ((ulonglong)((param_1[0x52] - lVar9) / 0x24) < uVar12) {

      FUN_14006fb70(plVar2,uVar12,&local_res18);

    }

    else {

      lVar9 = FUN_14006fd10(param_1[0x51],uVar12 - uVar11,plVar2);

      param_1[0x51] = lVar9;

    }

  }

  uVar7 = 0;

  lVar9 = *plVar2;

  uVar11 = uVar7;

  uVar12 = uVar7;

  if ((param_1[0x51] - lVar9) / 0x24 != 0) {

    do {

      FUN_140075cb0(lVar9 + 4 + uVar11 * 0x24);

      FUN_140075cb0(*plVar2 + 8 + uVar11 * 0x24);

      if (0xb < DAT_1403fb0e0) {

        FUN_140075cb0(*plVar2 + 0xc + uVar11 * 0x24);

      }

      FUN_140075cb0(*plVar2 + 0x10 + uVar11 * 0x24);

      uVar13 = (int)uVar12 + 1;

      lVar9 = *plVar2;

      uVar11 = (longlong)(int)uVar13;

      uVar12 = (ulonglong)uVar13;

    } while ((ulonglong)(longlong)(int)uVar13 < (ulonglong)((param_1[0x51] - lVar9) / 0x24));

  }

  FUN_140075b80(param_1 + 0x4f);

  FUN_140075b80((longlong)param_1 + 0x27c);

  lVar9 = *(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8);

  if ((*(int *)(lVar9 + 4) < DAT_1403eacc4) && (FUN_1402c7138(&DAT_1403eacc4), DAT_1403eacc4 == -1))

  {

    uStack_70 = 0;

    local_68 = 5;

    uStack_60 = 0xf;

    local_78._0_5_ = CONCAT14(s_Water_14030a274[4],s_Water_14030a274._0_4_);

    local_78 = (ulonglong)(uint5)local_78;

    DAT_1403eacc0 = FUN_14006fe60(&local_78);

    _Init_thread_footer(&DAT_1403eacc4);

  }

  if ((*(int *)(lVar9 + 4) < DAT_1403eaccc) && (FUN_1402c7138(&DAT_1403eaccc), DAT_1403eaccc == -1))

  {

    uStack_70 = 0;

    local_68 = 5;

    uStack_60 = 0xf;

    local_78._0_5_ = CONCAT14(s_Plain_14030a27c[4],s_Plain_14030a27c._0_4_);

    local_78 = (ulonglong)(uint5)local_78;

    _DAT_1403eacc8 = FUN_14006fe60(&local_78);

    _Init_thread_footer(&DAT_1403eaccc);

  }

  if ((*(int *)(lVar9 + 4) < DAT_1403eacd4) && (FUN_1402c7138(&DAT_1403eacd4), DAT_1403eacd4 == -1))

  {

    uStack_70 = 0;

    local_68 = 4;

    uStack_60 = 0xf;

    local_78 = 0x646e6f50;

    DAT_1403eacd0 = FUN_14006fe60(&local_78);

    _Init_thread_footer(&DAT_1403eacd4);

  }

  uVar11 = (ulonglong)(*(int *)((longlong)param_1 + 0x27c) * (int)param_1[0x4f]);

  auVar3._8_8_ = 0;

  auVar3._0_8_ = uVar11;

  uVar6 = SUB168(ZEXT816(0x28) * auVar3,0);

  if (SUB168(ZEXT816(0x28) * auVar3,8) != 0) {

    uVar6 = 0xffffffffffffffff;

  }

  local_res18 = uVar11;

  local_res18 = thunk_FUN_1402c704c(uVar6);

  uVar12 = uVar7;

  if ((local_res18 != 0) && (uVar12 = local_res18, uVar11 != 0)) {

    puVar8 = (undefined4 *)(local_res18 + 8);

    do {

      *(undefined8 *)(puVar8 + -2) = 0;

      *puVar8 = 0xffffffff;

      *(undefined2 *)(puVar8 + 1) = 0;

      *(undefined8 *)(puVar8 + 2) = 0;

      *(undefined8 *)(puVar8 + 4) = 0;

      *(undefined8 *)(puVar8 + 6) = 0;

      puVar8 = puVar8 + 10;

      uVar11 = uVar11 - 1;

    } while (uVar11 != 0);

  }

  param_1[0x4e] = uVar12;

  uVar11 = uVar7;

  uVar12 = uVar7;

  uVar14 = uVar7;

  if (0 < *(int *)((longlong)param_1 + 0x27c) * (int)param_1[0x4f]) {

    do {

      lVar9 = param_1[0x4e];

      if ((int)uVar14 < 1) {

        FUN_140075e30(&local_res18);

        if ((byte)local_res18 == 0x3f) {

          FUN_140075e30(&local_res18);

          uVar14 = (ulonglong)((byte)local_res18 - 1);

          *(undefined4 *)(uVar11 + lVar9) = 6;

          *(undefined4 *)(uVar11 + 8 + lVar9) = DAT_1403eacc0;

        }

        else if ((byte)((byte)local_res18 - 0x3b) < 4) {

          *(undefined4 *)(uVar11 + lVar9) = 0;

          *(uint *)(uVar11 + 8 + lVar9) = ((byte)local_res18 - 0x3b) + _DAT_1403eacc8;

        }

        else {

          *(uint *)(uVar11 + lVar9) = (byte)local_res18 & 0x3f;

          *(byte *)(uVar11 + 0xc + lVar9) = (byte)local_res18 >> 6 & 1;

          *(byte *)(uVar11 + 0xd + lVar9) = (byte)local_res18 >> 7;

          FUN_140075e30(&local_res18);

          *(uint *)(uVar11 + 8 + lVar9) = (uint)(byte)local_res18;

          if ((DAT_1403fb0e0 < 0xc) && ((byte)local_res18 == DAT_1403eacd0)) {

            *(undefined4 *)(uVar11 + lVar9) = 0x14;

          }

          iVar5 = FUN_140110750(*(undefined4 *)(uVar11 + lVar9));

          if (0 < iVar5) {

            FUN_140075e30(&local_res18);

            *(uint *)(uVar11 + 4 + lVar9) = (uint)(byte)local_res18;

          }

        }

      }

      else {

        *(undefined4 *)(uVar11 + lVar9) = 6;

        *(undefined4 *)(uVar11 + 8 + lVar9) = DAT_1403eacc0;

        uVar14 = (ulonglong)((int)uVar14 - 1);

      }

      uVar13 = (int)uVar12 + 1;

      uVar11 = uVar11 + 0x28;

      uVar12 = (ulonglong)uVar13;

    } while ((int)uVar13 < *(int *)((longlong)param_1 + 0x27c) * (int)param_1[0x4f]);

  }

  FUN_1401003e0(param_1,1);

  plVar2 = param_1 + 0x84;

  if (*plVar2 != param_1[0x85]) {

    param_1[0x85] = *plVar2;

  }

  iVar5 = FUN_140075da0();

  FUN_14006f9e0(plVar2,(longlong)iVar5,&local_res18);

  lVar9 = *plVar2;

  uVar11 = uVar7;

  uVar12 = uVar7;

  if (param_1[0x85] - lVar9 >> 3 != 0) {

    do {

      FUN_140075b80(lVar9 + uVar11 * 8);

      FUN_140075b80(*plVar2 + 4 + uVar11 * 8);

      uVar13 = (int)uVar12 + 1;

      lVar9 = *plVar2;

      uVar11 = (longlong)(int)uVar13;

      uVar12 = (ulonglong)uVar13;

    } while ((ulonglong)(longlong)(int)uVar13 < (ulonglong)(param_1[0x85] - lVar9 >> 3));

  }

  FUN_14006d790(param_1);

  lVar9 = param_1[0x17];

  uVar11 = uVar7;

  uVar12 = uVar7;

  if (param_1[0x18] - lVar9 >> 3 != 0) {

    do {

      if (*(int *)(*(longlong *)(lVar9 + uVar11) + 8) == 1) {

        param_1[0x60] = *(longlong *)(lVar9 + uVar11);

      }

      uVar13 = (int)uVar12 + 1;

      uVar11 = uVar11 + 8;

      uVar12 = (ulonglong)uVar13;

    } while ((ulonglong)(longlong)(int)uVar13 < (ulonglong)(param_1[0x18] - lVar9 >> 3));

  }

  lVar9 = 0x30;

  uVar11 = uVar7;

  uVar12 = uVar7;

  if (DAT_1403fb0e0 < 0xb) {

    lVar9 = 0x26;

  }

  do {

    FUN_140075e80(&local_res18);

    if ((byte)local_res18 != '\0') {

      uVar6 = FUN_1400fdee0(param_1,uVar12);

      *(undefined8 *)(param_1[0x87] + uVar11 * 8) = uVar6;

      FUN_14006d790(*(undefined8 *)(param_1[0x87] + uVar11 * 8));

      (**(code **)(**(longlong **)(param_1[0x87] + uVar11 * 8) + 0xb8))();

    }

    uVar11 = uVar11 + 1;

    uVar12 = (ulonglong)((int)uVar12 + 1);

  } while ((longlong)uVar11 < lVar9);

  if (DAT_1403fb0e0 < 0xb) {

    lVar9 = param_1[0x87];

    uVar6 = FUN_1400fdee0(param_1,0x25);

    *(undefined8 *)(lVar9 + 0x128) = uVar6;

    local_res18 = FUN_1402c704c(0x70);

    if (local_res18 != 0) {

      uVar7 = FUN_1400a8610(local_res18,2);

    }

    *(undefined4 *)(uVar7 + 0xc) = 0x25;

    puVar8 = (undefined4 *)FUN_1401012c0(param_1,&local_res18,0x84,0x7d);

    uVar1 = puVar8[1];

    lVar9 = *(longlong *)(param_1[0x87] + 0x128);

    *(undefined4 *)(lVar9 + 0xc) = *puVar8;

    *(undefined4 *)(lVar9 + 0x10) = uVar1;

    FUN_140100c90(param_1,uVar7,0x84,0x7d);

  }

  FUN_14006d790(DAT_1403f4e00);

  (**(code **)(*DAT_1403f4e00 + 0xb8))();

  FUN_140104370(param_1);

  if ((*(char *)(param_1[0x60] + 0xac) != '\0') &&

     (plVar2 = *(longlong **)(param_1[0x87] + 0x80), plVar2 != (longlong *)0x0)) {

    fVar15 = *(float *)(plVar2 + 2) + DAT_140305630;

    *(float *)((longlong)param_1 + 0x394) = *(float *)((longlong)plVar2 + 0xc) + DAT_140303398;

    *(float *)(param_1 + 0x73) = fVar15;

    cVar4 = (**(code **)(*plVar2 + 0x18))(plVar2);

    if (cVar4 != '\0') {

      *(undefined4 *)((longlong)param_1 + 0x25c) = 0x10;

      param_1 = plVar2;

      goto LAB_14006ec8c;

    }

    *(undefined4 *)(param_1[0x60] + 0x28) = *(undefined4 *)((longlong)param_1 + 0x394);

    *(int *)(param_1[0x60] + 0x2c) = (int)param_1[0x73];

    *(undefined1 *)(param_1[0x60] + 0xac) = 0;

  }

  FUN_1401041f0(param_1);

LAB_14006ec8c:

  FUN_14009c780(DAT_1403ee020,param_1);

  return 1;

}




