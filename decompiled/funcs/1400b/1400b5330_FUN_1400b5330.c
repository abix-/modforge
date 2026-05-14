// Address: 0x1400b5330
// Ghidra name: FUN_1400b5330
// ============ 0x1400b5330 FUN_1400b5330 (size=360) ============


undefined8 FUN_1400b5330(longlong param_1,undefined8 param_2,float param_3,int *param_4)



{

  longlong lVar1;

  uint uVar2;

  longlong *plVar3;

  longlong lVar4;

  int iVar5;

  longlong lVar6;

  float extraout_XMM0_Da;

  float fVar7;

  float fVar8;

  float local_68;

  float fStack_64;

  

  uVar2 = DAT_14039cac0;

  if (*(int *)(param_1 + 0x24c) != 0) {

    iVar5 = 0;

    lVar6 = *(longlong *)(param_1 + 0x48) - *(longlong *)(param_1 + 0x40);

    lVar6 = lVar6 + SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar6),8);

    lVar4 = lVar6 >> 7;

    lVar6 = lVar6 >> 0x3f;

    if (lVar4 != lVar6) {

      fStack_64 = (float)((ulonglong)param_2 >> 0x20);

      plVar3 = (longlong *)(*(longlong *)(param_1 + 0x40) + 0x30);

      local_68 = (float)param_2;

      do {

        if (((int)plVar3[-5] == 7) && (lVar1 = *plVar3, lVar1 != 0)) {

          fVar8 = *(float *)(param_1 + 0x138);

          if (*(char *)(param_1 + 0x1a) != '\0') {

            fVar8 = (float)((uint)fVar8 ^ uVar2);

          }

          fVar7 = ((*(float *)(lVar1 + 0x18) * fVar8 -

                   *(float *)(lVar1 + 0x14) * *(float *)(param_1 + 0x13c)) + *(float *)(lVar1 + 0xc)

                  ) - local_68;

          fVar8 = (*(float *)(lVar1 + 0x14) * fVar8 +

                   *(float *)(lVar1 + 0x18) * *(float *)(param_1 + 0x13c) + *(float *)(lVar1 + 0x10)

                  ) - fStack_64;

          fVar8 = fVar8 * fVar8 + fVar7 * fVar7;

          if (fVar8 < 0.0) {

            FUN_1402cdfa0(fVar8);

            fVar8 = extraout_XMM0_Da;

          }

          else {

            fVar8 = SQRT(fVar8);

          }

          if (fVar8 < param_3) {

            *param_4 = iVar5;

            return 1;

          }

        }

        iVar5 = iVar5 + 1;

        plVar3 = plVar3 + 0x17;

      } while ((ulonglong)(longlong)iVar5 < (ulonglong)(lVar4 - lVar6));

    }

  }

  return 0;

}




