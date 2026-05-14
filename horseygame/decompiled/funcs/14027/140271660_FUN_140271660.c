// Address: 0x140271660
// Ghidra name: FUN_140271660
// ============ 0x140271660 FUN_140271660 (size=1365) ============


ulonglong FUN_140271660(longlong param_1)



{

  longlong lVar1;

  short sVar2;

  short sVar3;

  short sVar4;

  int iVar5;

  ulonglong in_RAX;

  longlong lVar6;

  short sVar7;

  short sVar8;

  int iVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  char local_a8;

  short local_a7;

  undefined1 local_a5;

  undefined1 local_a4;

  undefined1 local_a3;

  undefined1 local_a2;

  short local_a1;

  short local_9f;

  short local_9d;

  short local_9b;

  short local_99;

  short local_97;

  byte local_95;

  byte local_94;

  byte local_93;

  byte local_92;

  short local_91;

  undefined1 local_8f;

  undefined1 local_8e;

  undefined1 local_8d;

  undefined1 local_8c;

  undefined1 local_8b;

  undefined1 local_8a;

  undefined1 local_89;

  undefined1 local_88;

  undefined1 local_87;

  undefined1 local_86;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  if (*(char *)(lVar1 + 0x12) != '\0') {

    iVar9 = 0;

    while( true ) {

      in_RAX = FUN_14026ffd0(*(undefined8 *)(param_1 + 0x80),2,&local_a8,0x40);

      if ((int)in_RAX < 0x23) break;

      if (*(char *)(param_1 + 0x54) != '\0') {

        in_RAX = FUN_14026ffd0(*(undefined8 *)(param_1 + 0x80),5,&local_a8,0x40);

        if ((int)in_RAX < 0x23) break;

      }

      lVar6 = 0;

      if ((in_RAX & 0xffffffff) != 0) {

        do {

          if ((&local_a8)[lVar6] != '\0') {

            sVar7 = CONCAT11(local_a4,local_a5);

            sVar8 = CONCAT11(local_a2,local_a3);

            sVar2 = local_9f;

            sVar3 = local_99;

            sVar4 = local_9d;

            if ((*(char *)(param_1 + 0x54) == '\0') && (*(char *)(lVar1 + 0x10) == '\0')) {

              sVar2 = local_9d;

              sVar3 = local_9b;

              sVar4 = local_99;

              local_9b = local_9f;

            }

            fVar12 = ((float)(int)(((int)(short)((ushort)local_94 << 8) | (uint)local_95) +

                                  ((int)(short)((ushort)local_92 << 8) | (uint)local_93)) *

                     (float)*(ushort *)(lVar1 + 0x6c)) / (float)*(ushort *)(lVar1 + 0x6a);

            iVar9 = FUN_140190050((int)local_9b - (int)local_a7);

            iVar5 = FUN_140190050((int)local_a1 - (int)local_a7);

            if ((float)(iVar5 + iVar9) != 0.0) {

              *(short *)(lVar1 + 0x28) = local_a7;

              *(float *)(lVar1 + 0x2c) = fVar12 / (float)(iVar5 + iVar9);

            }

            iVar9 = FUN_140190050((int)sVar3 - (int)sVar7);

            iVar5 = FUN_140190050((int)sVar2 - (int)sVar7);

            if ((float)(iVar5 + iVar9) != 0.0) {

              *(short *)(lVar1 + 0x30) = sVar7;

              *(float *)(lVar1 + 0x34) = fVar12 / (float)(iVar5 + iVar9);

            }

            iVar9 = FUN_140190050((int)local_97 - (int)sVar8);

            iVar5 = FUN_140190050((int)sVar4 - (int)sVar8);

            if ((float)(iVar5 + iVar9) != 0.0) {

              *(short *)(lVar1 + 0x38) = sVar8;

              *(float *)(lVar1 + 0x3c) = fVar12 / (float)(iVar5 + iVar9);

            }

            sVar2 = local_91 - CONCAT11(local_8e,local_8f);

            *(short *)(lVar1 + 0x40) = local_91 - sVar2 / 2;

            sVar3 = CONCAT11(local_8c,local_8d) - CONCAT11(local_8a,local_8b);

            fVar12 = ((float)*(ushort *)(lVar1 + 0x70) + (float)*(ushort *)(lVar1 + 0x70)) /

                     (float)*(ushort *)(lVar1 + 0x6e);

            *(short *)(lVar1 + 0x48) = CONCAT11(local_8c,local_8d) - sVar3 / 2;

            sVar4 = CONCAT11(local_88,local_89) - CONCAT11(local_86,local_87);

            *(float *)(lVar1 + 0x44) = fVar12 / (float)(int)sVar2;

            *(short *)(lVar1 + 0x50) = CONCAT11(local_88,local_89) - sVar4 / 2;

            *(float *)(lVar1 + 0x4c) = fVar12 / (float)(int)sVar3;

            *(float *)(lVar1 + 0x54) = fVar12 / (float)(int)sVar4;

            *(undefined1 *)(lVar1 + 0x27) = 1;

            iVar9 = FUN_140190050((int)*(short *)(lVar1 + 0x28));

            fVar11 = DAT_14039ca44;

            fVar12 = DAT_14039ca34;

            if ((0x400 < iVar9) ||

               (fVar10 = (float)FUN_140190250(DAT_14039ca44 - *(float *)(lVar1 + 0x2c)),

               fVar12 < fVar10)) {

              *(undefined1 *)(lVar1 + 0x27) = 0;

            }

            iVar9 = FUN_140190050((int)*(short *)(lVar1 + 0x30));

            if ((0x400 < iVar9) ||

               (fVar10 = (float)FUN_140190250(fVar11 - *(float *)(lVar1 + 0x34)), fVar12 < fVar10))

            {

              *(undefined1 *)(lVar1 + 0x27) = 0;

            }

            iVar9 = FUN_140190050((int)*(short *)(lVar1 + 0x38));

            if ((0x400 < iVar9) ||

               (fVar10 = (float)FUN_140190250(fVar11 - *(float *)(lVar1 + 0x3c)), fVar12 < fVar10))

            {

              *(undefined1 *)(lVar1 + 0x27) = 0;

            }

            iVar9 = FUN_140190050((int)*(short *)(lVar1 + 0x40));

            if ((0x400 < iVar9) ||

               (fVar10 = (float)FUN_140190250(fVar11 - *(float *)(lVar1 + 0x44)), fVar12 < fVar10))

            {

              *(undefined1 *)(lVar1 + 0x27) = 0;

            }

            iVar9 = FUN_140190050((int)*(short *)(lVar1 + 0x48));

            if ((0x400 < iVar9) ||

               (fVar11 = (float)FUN_140190250(fVar11 - *(float *)(lVar1 + 0x4c)), fVar12 < fVar11))

            {

              *(undefined1 *)(lVar1 + 0x27) = 0;

            }

            iVar9 = FUN_140190050((int)*(short *)(lVar1 + 0x50));

            if ((0x400 < iVar9) || (fVar11 = (float)FUN_140190250(), fVar12 < fVar11)) {

              *(undefined1 *)(lVar1 + 0x27) = 0;

            }

            return (ulonglong)*(byte *)(lVar1 + 0x27);

          }

          lVar6 = lVar6 + 1;

        } while (lVar6 < (longlong)(in_RAX & 0xffffffff));

      }

      FUN_1401492f0(2);

      iVar9 = iVar9 + 1;

      if (4 < iVar9) {

        return (ulonglong)*(byte *)(lVar1 + 0x27);

      }

    }

  }

  return in_RAX & 0xffffffffffffff00;

}




