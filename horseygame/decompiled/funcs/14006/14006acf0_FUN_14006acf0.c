// Address: 0x14006acf0
// Ghidra name: FUN_14006acf0
// ============ 0x14006acf0 FUN_14006acf0 (size=368) ============


undefined8 FUN_14006acf0(longlong param_1,int param_2,int param_3)



{

  longlong lVar1;

  float fVar2;

  float *pfVar3;

  longlong lVar4;

  longlong lVar5;

  int iVar6;

  float fVar7;

  float local_res8;

  float local_resc;

  undefined1 local_res20 [8];

  

  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8);

  FUN_1400b4a10(lVar1,&local_res8);

  fVar2 = DAT_14030374c;

  if (((*(longlong *)(param_1 + 0x2d0) == 0) && (param_3 != 0)) &&

     (*(char *)(lVar1 + 0x204) != '\0')) {

    lVar4 = *(longlong *)(param_1 + 0x130);

    iVar6 = 0;

    if (*(longlong *)(param_1 + 0x138) - lVar4 >> 3 != 0) {

      lVar5 = 0;

      do {

        if (*(char *)(*(longlong *)(lVar5 + lVar4) + 0x204) == '\0') {

          pfVar3 = (float *)FUN_1400b4a10(*(longlong *)(lVar5 + lVar4),local_res20);

          fVar7 = (pfVar3[1] - local_resc) * (pfVar3[1] - local_resc) +

                  (*pfVar3 - local_res8) * (*pfVar3 - local_res8);

          if (fVar7 < 0.0) {

            fVar7 = (float)FUN_1402cdfa0(fVar7);

          }

          else {

            fVar7 = SQRT(fVar7);

          }

          if (fVar7 < fVar2) {

            *(undefined8 *)(param_1 + 0x2d0) =

                 *(undefined8 *)(*(longlong *)(param_1 + 0x130) + (longlong)iVar6 * 8);

            *(longlong *)(param_1 + 0x2d8) = lVar1;

            *(undefined4 *)(param_1 + 0x2e0) = 1;

            *(undefined4 *)(param_1 + 0x16c) = 0xffffffff;

            *(undefined4 *)(param_1 + 0x15c) = 0xffffffff;

            if (*(char *)(lVar1 + 0x1a) == '\0') {

              return 1;

            }

            *(undefined1 *)(lVar1 + 0x1a) = 0;

            FUN_1400b47e0(lVar1);

            FUN_1400cead0(param_1,lVar1);

            return 1;

          }

        }

        lVar4 = *(longlong *)(param_1 + 0x130);

        iVar6 = iVar6 + 1;

        lVar5 = lVar5 + 8;

        if ((ulonglong)(*(longlong *)(param_1 + 0x138) - lVar4 >> 3) <= (ulonglong)(longlong)iVar6)

        {

          return 1;

        }

      } while( true );

    }

  }

  return 1;

}




