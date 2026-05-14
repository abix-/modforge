// Address: 0x1401029c0
// Ghidra name: FUN_1401029c0
// ============ 0x1401029c0 FUN_1401029c0 (size=376) ============


longlong FUN_1401029c0(longlong param_1,undefined8 param_2,float *param_3)



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float local_res18;

  float fStackX_1c;

  

  lVar3 = 0;

  iVar1 = 0;

  local_res18 = (float)param_2;

  fVar4 = local_res18 * DAT_140303fb4;

  fVar7 = *param_3 * DAT_140303fb4 + DAT_14039ca44;

  fStackX_1c = (float)((ulonglong)param_2 >> 0x20);

  fVar5 = fStackX_1c * DAT_140303fb4;

  do {

    lVar2 = *(longlong *)

             (*(longlong *)(param_1 + 0x270) + 0x10 +

             (longlong)

             (((&DAT_1403f4f38)[(longlong)iVar1 * 10] + (int)fVar5) * *(int *)(param_1 + 0x278) +

              (&DAT_1403f4f34)[(longlong)iVar1 * 10] + (int)fVar4) * 0x28);

    if (lVar2 != 0) {

      fVar9 = *param_3;

      do {

        fVar6 = local_res18 - *(float *)(lVar2 + 0x28);

        fVar8 = fStackX_1c - *(float *)(lVar2 + 0x2c);

        fVar6 = fVar8 * fVar8 + fVar6 * fVar6;

        if (fVar6 < 0.0) {

          fVar6 = (float)FUN_1402cdfa0(fVar6);

        }

        else {

          fVar6 = SQRT(fVar6);

        }

        if (fVar6 < fVar9) {

          *param_3 = fVar6;

          lVar3 = lVar2;

          fVar9 = fVar6;

        }

        lVar2 = *(longlong *)(lVar2 + 0x58);

      } while (lVar2 != 0);

    }

    iVar1 = FUN_140100a40(param_1,iVar1,(int)fVar4,(int)fVar5,(int)fVar7,0);

  } while (iVar1 != -1);

  return lVar3;

}




