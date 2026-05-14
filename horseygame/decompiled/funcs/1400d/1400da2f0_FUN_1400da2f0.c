// Address: 0x1400da2f0
// Ghidra name: FUN_1400da2f0
// ============ 0x1400da2f0 FUN_1400da2f0 (size=3290) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400da2f0(int param_1,float *param_2,longlong param_3)



{

  double dVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  int iVar7;

  int iVar8;

  uint uVar9;

  uint uVar10;

  uint uVar11;

  uint uVar12;

  int iVar13;

  undefined8 uVar14;

  int iVar15;

  longlong lVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  double dVar20;

  float fVar21;

  undefined2 local_res20 [4];

  int local_e8;

  

  fVar6 = DAT_14039ca50;

  fVar5 = DAT_14039ca44;

  fVar4 = DAT_14039ca34;

  fVar3 = DAT_14039ca24;

  fVar2 = DAT_14030b668;

  if (0 < param_1) {

    local_e8 = 0;

    fVar19 = DAT_1403f4b64;

    iVar13 = DAT_1403f3a20;

    iVar15 = DAT_1403f3ab4;

    dVar1 = DAT_1403f3a88;

    do {

      if (DAT_1403f3a59 == '\0') {

        return;

      }

      DAT_1403f4b88 = DAT_1403f4b88 + 1;

      if ((DAT_1403f4b8c != 0) && (DAT_1403f4b8c <= DAT_1403f4b88)) {

        DAT_1403f4b88 = 0;

        FUN_1400d98f0(CONCAT71((uint7)(uint3)((uint)DAT_1403f4b8c >> 8),1));

        fVar19 = DAT_1403f4b64;

        iVar15 = DAT_1403f3ab4;

        dVar1 = DAT_1403f3a88;

      }

      fVar21 = DAT_1403f4b84;

      uVar12 = DAT_1403f3ad8;

      DAT_1403f4b90 = DAT_1403f4b90 + 1;

      if ((DAT_1403f4b94 != 0) && (DAT_1403f4b94 <= DAT_1403f4b90)) {

        dVar1 = dVar1 * _DAT_1403f4b98;

        DAT_1403f4b94 = 0;

      }

      DAT_1403f3a98 = DAT_1403f3a98 + _DAT_1403f3aa0;

      DAT_1403f3a88 = dVar1 * DAT_1403f3a98;

      if ((DAT_1403f3a90 < DAT_1403f3a88) && (DAT_1403f3a88 = DAT_1403f3a90, 0.0 < DAT_1403f3a28)) {

        DAT_1403f3a59 = '\0';

      }

      dVar1 = DAT_1403f3a88;

      dVar20 = DAT_1403f3a88;

      if (0.0 < DAT_1403f4b84) {

        DAT_1403f4b7c = DAT_1403f4b7c + _DAT_1403f4b80;

        fVar17 = (float)FUN_1402cdc50();

        dVar20 = ((double)(fVar17 * fVar21) + DAT_140304b90) * dVar1;

      }

      _DAT_1403f3aa8 = (int)dVar20;

      if (_DAT_1403f3aa8 < 8) {

        _DAT_1403f3aa8 = 8;

      }

      iVar7 = _DAT_1403f3aa8;

      DAT_1403f3aac = DAT_1403f3ab0 + DAT_1403f3aac;

      if (0.0 <= DAT_1403f3aac) {

        if (fVar4 < DAT_1403f3aac) {

          DAT_1403f3aac = 0.5;

        }

      }

      else {

        DAT_1403f3aac = 0.0;

      }

      DAT_1403f3ab8 = DAT_1403f3ab8 + 1;

      if ((&DAT_1403f3ac0)[iVar15] < DAT_1403f3ab8) {

        iVar15 = iVar15 + 1;

        DAT_1403f3ab8 = 0;

        DAT_1403f3ab4 = iVar15;

        if (iVar15 == 3) {

          DAT_1403f3a59 = '\0';

        }

      }

      fVar21 = (float)DAT_1403f3ab8;

      if (iVar15 == 0) {

        _DAT_1403f3abc = fVar21 / (float)DAT_1403f3ac0;

      }

      if (iVar15 == 1) {

        fVar21 = (float)FUN_1402d8d60(fVar5 - fVar21 / (float)DAT_1403f3ac4,fVar5);

        _DAT_1403f3abc = (fVar21 + fVar21) * _DAT_1403f3a54 + fVar5;

      }

      else if (iVar15 == 2) {

        _DAT_1403f3abc = fVar5 - fVar21 / (float)DAT_1403f3ac8;

      }

      DAT_1403f3acc = DAT_1403f3acc + _DAT_1403f3ad0;

      _DAT_1403f3ad4 = -(int)DAT_1403f3acc;

      if (_DAT_1403f3ad4 < 0) {

        _DAT_1403f3ad4 = (int)DAT_1403f3acc;

      }

      if (0x3ff < _DAT_1403f3ad4) {

        _DAT_1403f3ad4 = 0x3ff;

      }

      iVar8 = _DAT_1403f3ad4;

      if (DAT_1403f4b78 != 0.0) {

        DAT_1403f4b74 = DAT_1403f4b74 * DAT_1403f4b78;

        if (DAT_14030ebe4 <= DAT_1403f4b74) {

          if (fVar3 < DAT_1403f4b74) {

            DAT_1403f4b74 = 0.1;

          }

        }

        else {

          DAT_1403f4b74 = 1e-05;

        }

      }

      lVar16 = 8;

      fVar21 = 0.0;

      do {

        DAT_1403f3a84 = DAT_1403f3a84 + 1;

        if ((iVar7 <= DAT_1403f3a84) && (DAT_1403f3a84 = DAT_1403f3a84 % iVar7, iVar13 == 3)) {

          uVar9 = DAT_1403f4bac * 0x343fd + 0x269ec3;

          uVar10 = uVar9 * 0x343fd + 0x269ec3;

          uVar11 = uVar10 * 0x343fd + 0x269ec3;

          _DAT_1403f4ae0 = (float)(uVar9 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar9 = uVar11 * 0x343fd + 0x269ec3;

          _DAT_1403f4ae4 = (float)(uVar10 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar10 = uVar9 * 0x343fd + 0x269ec3;

          _DAT_1403f4ae8 = (float)(uVar11 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar11 = uVar10 * 0x343fd + 0x269ec3;

          _DAT_1403f4aec = (float)(uVar9 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar9 = uVar11 * 0x343fd + 0x269ec3;

          _DAT_1403f4af0 = (float)(uVar10 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar10 = uVar9 * 0x343fd + 0x269ec3;

          _DAT_1403f4af4 = (float)(uVar11 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar11 = uVar10 * 0x343fd + 0x269ec3;

          _DAT_1403f4af8 = (float)(uVar9 >> 0x10) * DAT_14030ebe8 - fVar5;

          _DAT_1403f4afc = (float)(uVar10 >> 0x10) * DAT_14030ebe8 - fVar5;

          _DAT_1403f4b00 = (float)(uVar11 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar9 = uVar11 * 0x343fd + 0x269ec3;

          uVar10 = uVar9 * 0x343fd + 0x269ec3;

          uVar11 = uVar10 * 0x343fd + 0x269ec3;

          _DAT_1403f4b04 = (float)(uVar9 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar9 = uVar11 * 0x343fd + 0x269ec3;

          _DAT_1403f4b08 = (float)(uVar10 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar10 = uVar9 * 0x343fd + 0x269ec3;

          _DAT_1403f4b0c = (float)(uVar11 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar11 = uVar10 * 0x343fd + 0x269ec3;

          _DAT_1403f4b10 = (float)(uVar9 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar9 = uVar11 * 0x343fd + 0x269ec3;

          _DAT_1403f4b14 = (float)(uVar10 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar10 = uVar9 * 0x343fd + 0x269ec3;

          _DAT_1403f4b18 = (float)(uVar11 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar11 = uVar10 * 0x343fd + 0x269ec3;

          _DAT_1403f4b1c = (float)(uVar9 >> 0x10) * DAT_14030ebe8 - fVar5;

          _DAT_1403f4b20 = (float)(uVar10 >> 0x10) * DAT_14030ebe8 - fVar5;

          _DAT_1403f4b24 = (float)(uVar11 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar9 = uVar11 * 0x343fd + 0x269ec3;

          uVar10 = uVar9 * 0x343fd + 0x269ec3;

          uVar11 = uVar10 * 0x343fd + 0x269ec3;

          _DAT_1403f4b28 = (float)(uVar9 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar9 = uVar11 * 0x343fd + 0x269ec3;

          _DAT_1403f4b2c = (float)(uVar10 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar10 = uVar9 * 0x343fd + 0x269ec3;

          _DAT_1403f4b30 = (float)(uVar11 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar11 = uVar10 * 0x343fd + 0x269ec3;

          _DAT_1403f4b34 = (float)(uVar9 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar9 = uVar11 * 0x343fd + 0x269ec3;

          _DAT_1403f4b38 = (float)(uVar10 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar10 = uVar9 * 0x343fd + 0x269ec3;

          _DAT_1403f4b3c = (float)(uVar11 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar11 = uVar10 * 0x343fd + 0x269ec3;

          _DAT_1403f4b40 = (float)(uVar9 >> 0x10) * DAT_14030ebe8 - fVar5;

          _DAT_1403f4b44 = (float)(uVar10 >> 0x10) * DAT_14030ebe8 - fVar5;

          _DAT_1403f4b48 = (float)(uVar11 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar9 = uVar11 * 0x343fd + 0x269ec3;

          uVar10 = uVar9 * 0x343fd + 0x269ec3;

          uVar11 = uVar10 * 0x343fd + 0x269ec3;

          _DAT_1403f4b4c = (float)(uVar9 >> 0x10) * DAT_14030ebe8 - fVar5;

          uVar9 = uVar11 * 0x343fd + 0x269ec3;

          _DAT_1403f4b50 = (float)(uVar10 >> 0x10) * DAT_14030ebe8 - fVar5;

          _DAT_1403f4b54 = (float)(uVar11 >> 0x10) * DAT_14030ebe8 - fVar5;

          DAT_1403f4bac = uVar9 * 0x343fd + 0x269ec3;

          _DAT_1403f4b58 = (float)(uVar9 >> 0x10) * DAT_14030ebe8 - fVar5;

          _DAT_1403f4b5c = (float)(DAT_1403f4bac >> 0x10) * DAT_14030ebe8 - fVar5;

        }

        fVar17 = (float)DAT_1403f3a84 / (float)iVar7;

        if (iVar13 == 0) {

          fVar18 = fVar2;

          if (fVar17 < DAT_1403f3aac) {

            fVar18 = fVar4;

          }

        }

        else if (iVar13 == 1) {

          fVar18 = fVar5 - (fVar17 + fVar17);

        }

        else if (iVar13 == 2) {

          fVar18 = (float)FUN_1402cdc50(0,0,(fVar17 + fVar17) * fVar6);

        }

        else {

          fVar18 = 0.0;

          if (iVar13 == 3) {

            fVar18 = *(float *)(&DAT_1403f4ae0 + (longlong)((DAT_1403f3a84 << 5) / iVar7) * 4);

          }

        }

        DAT_1403f4b64 = fVar19 * _DAT_1403f4b68;

        if (DAT_1403f4b64 < 0.0) {

          DAT_1403f4b64 = 0.0;

        }

        if (fVar3 < DAT_1403f4b64) {

          DAT_1403f4b64 = fVar3;

        }

        fVar19 = DAT_1403f4b64;

        if (DAT_1403f3a60 == fVar5) {

          _DAT_1403f4b60 = 0.0;

        }

        else {

          _DAT_1403f4b60 = (fVar18 - DAT_1403f3adc) * DAT_1403f4b64 + _DAT_1403f4b60;

          _DAT_1403f4b60 = _DAT_1403f4b60 - _DAT_1403f4b60 * _DAT_1403f4b6c;

          fVar18 = DAT_1403f3adc;

        }

        _DAT_1403f4b70 = ((fVar18 + _DAT_1403f4b60) - DAT_1403f3adc) + _DAT_1403f4b70;

        _DAT_1403f4b70 = _DAT_1403f4b70 - _DAT_1403f4b70 * DAT_1403f4b74;

        DAT_1403f3adc = fVar18 + _DAT_1403f4b60;

        *(float *)(&DAT_1403f3ae0 + (ulonglong)(uVar12 & 0x3ff) * 4) = _DAT_1403f4b70;

        fVar17 = DAT_14039ca80;

        uVar9 = uVar12 - iVar8;

        uVar12 = uVar12 + 1 & 0x3ff;

        fVar21 = fVar21 + (_DAT_1403f4b70 +

                          *(float *)(&DAT_1403f3ae0 + (ulonglong)(uVar9 & 0x3ff) * 4)) *

                          _DAT_1403f3abc;

        lVar16 = lVar16 + -1;

      } while (lVar16 != 0);

      fVar21 = fVar21 * DAT_140303358 * _DAT_1403da908 * DAT_1403da90c * DAT_14030374c;

      DAT_1403f3ad8 = uVar12;

      if (param_2 != (float *)0x0) {

        fVar19 = fVar5;

        if (fVar21 <= fVar5) {

          fVar19 = fVar21;

        }

        fVar21 = DAT_14039ca80;

        if (DAT_14039ca80 <= fVar19) {

          fVar21 = fVar19;

        }

        *param_2 = fVar21;

        param_2 = param_2 + 1;

        fVar19 = DAT_1403f4b64;

        iVar13 = DAT_1403f3a20;

        iVar15 = DAT_1403f3ab4;

        dVar1 = DAT_1403f3a88;

      }

      if (param_3 != 0) {

        DAT_1403f4ba8 = DAT_1403f4ba8 + 1;

        fVar18 = fVar5;

        if (fVar21 * DAT_140303390 <= fVar5) {

          fVar18 = fVar21 * DAT_140303390;

        }

        if (fVar17 <= fVar18) {

          fVar17 = fVar18;

        }

        _DAT_1403f4ba4 = fVar17 + _DAT_1403f4ba4;

        if ((DAT_1403da914 == 0xac44) || (DAT_1403f4ba8 == 2)) {

          fVar19 = (float)DAT_1403f4ba8;

          DAT_1403f4ba8 = 0;

          _DAT_1403f4ba4 = _DAT_1403f4ba4 / fVar19;

          if (DAT_1403da910 == 0x10) {

            uVar14 = 2;

            local_res20[0] = (undefined2)(int)(_DAT_1403f4ba4 * _DAT_14030ec34);

          }

          else {

            uVar14 = 1;

            local_res20[0] =

                 CONCAT11(local_res20[0]._1_1_,

                          (char)(int)(_DAT_1403f4ba4 * DAT_140305658 + DAT_140304c28));

          }

          FUN_1402d185c(local_res20,1,uVar14,param_3);

          _DAT_1403f4ba4 = 0.0;

          fVar19 = DAT_1403f4b64;

          iVar13 = DAT_1403f3a20;

          iVar15 = DAT_1403f3ab4;

          dVar1 = DAT_1403f3a88;

        }

        DAT_1403f4ba0 = DAT_1403f4ba0 + 1;

      }

      local_e8 = local_e8 + 1;

    } while (local_e8 < param_1);

  }

  return;

}




