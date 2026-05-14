// Address: 0x140081d10
// Ghidra name: FUN_140081d10
// ============ 0x140081d10 FUN_140081d10 (size=638) ============


void FUN_140081d10(longlong param_1,float param_2,float param_3,float param_4)



{

  uint uVar1;

  longlong lVar2;

  bool bVar3;

  float fVar4;

  char cVar5;

  int iVar6;

  float fVar7;

  float fVar8;

  

  uVar1 = *(uint *)(param_1 + 0x70);

  if ((uVar1 != 0xd) &&

     (((0xc < uVar1 || ((0x1210U >> (uVar1 & 0x1f) & 1) == 0)) &&

      (cVar5 = FUN_140080a70(param_1), cVar5 != '\0')))) {

    if (((*(float *)(*(longlong *)(param_1 + 0x80) + 0x150) != 0.0) &&

        ((*(uint *)(*(longlong *)(param_1 + 0x80) + 600) & 0x400000) == 0)) &&

       ((param_4 != DAT_14030ad54 || (cVar5 = FUN_1400b7720(), cVar5 == '\0')))) {

      fVar4 = DAT_14039ca44;

      if (*(int *)(param_1 + 0x70) == 0xb) {

        param_4 = param_4 * DAT_14030335c;

      }

      fVar7 = (float)FUN_1400c6940(DAT_14039ca44);

      lVar2 = *(longlong *)(param_1 + 0x80);

      fVar7 = fVar7 * param_4;

      if (*(int *)(lVar2 + 0x24c) == 2) {

        fVar8 = 0.0;

        if ((*(uint *)(lVar2 + 600) & 0x800000) != 0) {

          fVar8 = fVar4;

        }

        bVar3 = *(float *)(lVar2 + 0x158) + *(float *)(lVar2 + 0x158) +

                *(float *)(lVar2 + 0x148) + *(float *)(lVar2 + 0x148) + fVar8 <

                fVar7 * DAT_14039ca34;

      }

      else {

        if (*(int *)(lVar2 + 0x24c) != 1) {

          fVar7 = fVar7 * DAT_14039ca38;

        }

        bVar3 = *(float *)(lVar2 + 0x158) <= fVar7;

      }

      if (bVar3) {

        param_2 = *(float *)(param_1 + 0x28) - param_2;

        param_3 = *(float *)(param_1 + 0x2c) - param_3;

        fVar7 = param_3 * param_3 + param_2 * param_2;

        if (fVar7 < 0.0) {

          fVar7 = (float)FUN_1402cdfa0(fVar7);

        }

        else {

          fVar7 = SQRT(fVar7);

        }

        if (DAT_14039c9f0 <= fVar7) {

          if (fVar4 < fVar7) {

            iVar6 = FUN_1400c6580(3);

            FUN_140080cc0(param_1,9,0);

            fVar8 = (float)((iVar6 + 1) * 0x20);

            FUN_1400a8890(param_1,fVar8 * (fVar4 / fVar7) * param_2 + *(float *)(param_1 + 0x28),

                          fVar8 * (fVar4 / fVar7) * param_3 + *(float *)(param_1 + 0x2c),

                          *(float *)(param_1 + 0xa8) + *(float *)(param_1 + 0xa8),DAT_140303750);

            iVar6 = FUN_1400c6580(4);

            if (iVar6 == 0) {

              FUN_140082550(param_1);

            }

            FUN_140102b40(DAT_1403fb0d8,param_1,0x23,0);

          }

        }

      }

    }

  }

  return;

}




