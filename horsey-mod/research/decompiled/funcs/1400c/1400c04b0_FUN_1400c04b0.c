// Address: 0x1400c04b0
// Ghidra name: FUN_1400c04b0
// ============ 0x1400c04b0 FUN_1400c04b0 (size=414) ============


undefined8 FUN_1400c04b0(longlong param_1,int param_2)



{

  ulonglong *puVar1;

  char cVar2;

  char *pcVar3;

  ulonglong uVar4;

  char *pcVar5;

  longlong lVar6;

  int iVar7;

  ulonglong uVar9;

  float fVar10;

  float fVar11;

  undefined8 local_res8;

  ulonglong local_res20;

  ulonglong uVar8;

  

  fVar10 = DAT_1403ed970 / *(float *)(param_1 + 0x114) + *(float *)(param_1 + 0x10c);

  fVar11 = DAT_1403ed978 / *(float *)(param_1 + 0x114) + *(float *)(param_1 + 0x110);

  uVar4 = 0;

  lVar6 = *(longlong *)(param_1 + 0x130);

  uVar8 = uVar4;

  uVar9 = uVar4;

  if (*(longlong *)(param_1 + 0x138) - lVar6 >> 3 != 0) {

    do {

      iVar7 = (int)uVar8;

      if ((iVar7 != param_2) &&

         (cVar2 = FUN_1400b6fd0(*(undefined8 *)(lVar6 + uVar9 * 8),fVar10,fVar11,0), cVar2 != '\0'))

      {

        pcVar3 = (char *)FUN_1400b78d0(*(undefined8 *)

                                        (*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8),

                                       *(undefined8 *)

                                        (*(longlong *)(param_1 + 0x130) + (longlong)iVar7 * 8));

        pcVar5 = "Same!";

        if (pcVar3 != (char *)0x0) {

          pcVar5 = pcVar3;

        }

        FUN_1400c4320(pcVar5);

        fVar10 = fVar10 - DAT_14039ca44;

        fVar11 = fVar11 + DAT_14030338c;

        local_res8 = FUN_1402c704c(0x498);

        if (local_res8 != 0) {

          uVar4 = FUN_1400aac60(local_res8);

        }

        lVar6 = *(longlong *)(param_1 + 0x130);

        local_res20 = uVar4;

        FUN_1400b2e30(uVar4,*(undefined8 *)(lVar6 + (longlong)param_2 * 8),

                      *(undefined8 *)(lVar6 + uVar9 * 8));

        local_res8 = CONCAT44(fVar11,fVar10);

        FUN_1400b6610(uVar4,&local_res8);

        *(undefined4 *)(uVar4 + 0x1fc) = 1;

        FUN_1400cead0(param_1,uVar4);

        puVar1 = *(ulonglong **)(param_1 + 0x138);

        if (puVar1 != *(ulonglong **)(param_1 + 0x140)) {

          *puVar1 = uVar4;

          *(longlong *)(param_1 + 0x138) = *(longlong *)(param_1 + 0x138) + 8;

          return 1;

        }

        FUN_140030680((longlong *)(param_1 + 0x130),puVar1,&local_res20);

        return 1;

      }

      lVar6 = *(longlong *)(param_1 + 0x130);

      uVar8 = (ulonglong)(iVar7 + 1U);

      uVar9 = uVar9 + 1;

    } while ((ulonglong)(longlong)(int)(iVar7 + 1U) <

             (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar6 >> 3));

  }

  return 1;

}




