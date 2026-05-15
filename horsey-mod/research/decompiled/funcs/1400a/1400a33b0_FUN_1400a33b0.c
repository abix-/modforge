// Address: 0x1400a33b0
// Ghidra name: FUN_1400a33b0
// ============ 0x1400a33b0 FUN_1400a33b0 (size=501) ============


void FUN_1400a33b0(longlong param_1)



{

  char cVar1;

  ulonglong uVar2;

  longlong *plVar3;

  uint uVar4;

  char *pcVar5;

  undefined4 uVar6;

  longlong *plVar7;

  longlong *plVar8;

  longlong lVar9;

  size_t _Size;

  longlong *plVar10;

  ulonglong _Size_00;

  longlong lVar11;

  longlong lVar12;

  longlong lVar13;

  char local_38 [4];

  char local_34 [2];

  char local_32;

  undefined1 local_31;

  undefined8 local_30;

  undefined8 local_28;

  undefined8 local_20;

  

  plVar3 = DAT_1403f2fb0;

  local_30 = 0;

  local_20 = 0xf;

  local_28 = 7;

  plVar8 = (longlong *)DAT_1403f2fb0[1];

  local_31 = 0;

  cVar1 = *(char *)((longlong)plVar8 + 0x19);

  local_38 = (char  [4])s_scratch_14030cc28._0_4_;

  plVar10 = DAT_1403f2fb0;

  local_34 = (char  [2])s_scratch_14030cc28._4_2_;

  local_32 = s_scratch_14030cc28[6];

  while (cVar1 == '\0') {

    plVar7 = plVar8 + 4;

    if (0xf < (ulonglong)plVar8[7]) {

      plVar7 = (longlong *)*plVar7;

    }

    uVar2 = plVar8[6];

    _Size_00 = uVar2;

    if (7 < uVar2) {

      _Size_00 = 7;

    }

    uVar4 = memcmp(plVar7,local_38,_Size_00);

    if (uVar4 == 0) {

      if (uVar2 < 7) {

        uVar4 = 0xffffffff;

      }

      else {

        uVar4 = (uint)(7 < uVar2);

      }

    }

    plVar7 = plVar8;

    if ((int)uVar4 < 0) {

      plVar8 = plVar8 + 2;

      plVar7 = plVar10;

    }

    plVar8 = (longlong *)*plVar8;

    plVar10 = plVar7;

    cVar1 = *(char *)((longlong)plVar8 + 0x19);

  }

  if (*(char *)((longlong)plVar10 + 0x19) == '\0') {

    plVar8 = plVar10 + 4;

    if (0xf < (ulonglong)plVar10[7]) {

      plVar8 = (longlong *)plVar10[4];

    }

    uVar2 = plVar10[6];

    _Size = 7;

    if (uVar2 < 7) {

      _Size = uVar2;

    }

    uVar4 = memcmp(local_38,plVar8,_Size);

    if (uVar4 == 0) {

      if (uVar2 < 8) {

        uVar4 = (uint)(uVar2 < 7);

      }

      else {

        uVar4 = 0xffffffff;

      }

    }

    if (-1 < (int)uVar4) goto LAB_1400a34ce;

  }

  plVar10 = plVar3;

LAB_1400a34ce:

  if (plVar10 != plVar3) {

    lVar11 = 0;

    pcVar5 = (char *)(param_1 + 0xf0);

    lVar12 = 0xf0;

    lVar13 = (longlong)(int)plVar10[8] * 0x1018 + DAT_1403f2fc0;

    lVar9 = lVar13;

    do {

      if ((pcVar5[-0xf0] == '\0') || (*pcVar5 == '\0')) {

        uVar6 = 1;

      }

      else {

        uVar6 = 0;

      }

      *(undefined4 *)(lVar9 + 0x28) = uVar6;

      if ((pcVar5[-0xf0] == '\x01') || (*pcVar5 == '\x01')) {

        uVar6 = 1;

      }

      else {

        uVar6 = 0;

      }

      *(undefined4 *)(lVar13 + 0x2c + lVar11) = uVar6;

      if ((pcVar5[-0xf0] == '\x02') || (*pcVar5 == '\x02')) {

        uVar6 = 1;

      }

      else {

        uVar6 = 0;

      }

      *(undefined4 *)(lVar13 + 0x30 + lVar11) = uVar6;

      if ((pcVar5[-0xf0] == '\x03') || (*pcVar5 == '\x03')) {

        uVar6 = 1;

      }

      else {

        uVar6 = 0;

      }

      *(undefined4 *)(lVar13 + 0x34 + lVar11) = uVar6;

      lVar9 = lVar9 + 0x10;

      pcVar5[(lVar13 - param_1) + 0xe38] = '\0';

      lVar11 = lVar11 + 0x10;

      pcVar5 = pcVar5 + 1;

      lVar12 = lVar12 + -1;

    } while (lVar12 != 0);

  }

  return;

}




