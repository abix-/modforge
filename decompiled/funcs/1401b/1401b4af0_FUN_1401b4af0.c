// Address: 0x1401b4af0
// Ghidra name: FUN_1401b4af0
// ============ 0x1401b4af0 FUN_1401b4af0 (size=874) ============


undefined8

FUN_1401b4af0(longlong param_1,uint param_2,ulonglong *param_3,undefined8 param_4,char param_5,

             longlong param_6,longlong param_7,longlong *param_8)



{

  uint uVar1;

  ulonglong uVar2;

  longlong *plVar3;

  ulonglong uVar4;

  ulonglong *puVar5;

  char cVar6;

  int iVar7;

  longlong lVar8;

  ulonglong uVar9;

  longlong lVar10;

  longlong lVar11;

  longlong *plVar12;

  ulonglong *local_res18;

  undefined8 local_res20;

  

  uVar2 = *param_3;

  uVar1 = *(uint *)(param_1 + 0x5a4 + (ulonglong)param_2 * 8);

  lVar10 = *(longlong *)(param_1 + 0x598) + (ulonglong)param_2 * 0x28;

  local_res18 = param_3;

  local_res20 = param_4;

  if (param_6 == 0) {

    if (param_7 == 0) {

LAB_1401b4b80:

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"BindResourceMemory must be given either a VulkanBuffer or a VulkanTexture");

    }

  }

  else if (param_7 != 0) goto LAB_1401b4b80;

  FUN_140179b40(*(undefined8 *)(param_1 + 0x8c0));

  uVar9 = uVar2;

  if (param_5 == '\0') {

    iVar7 = *(int *)(lVar10 + 0x20) + -1;

    if (-1 < iVar7) {

      lVar11 = (longlong)iVar7;

      plVar12 = (longlong *)(*(longlong *)(lVar10 + 0x18) + lVar11 * 8);

      do {

        plVar3 = (longlong *)*plVar12;

        if (uVar2 < 0x200001) {

          if (*(longlong *)(*plVar3 + 0x10) == 0x1000000) {

LAB_1401b4bdd:

            uVar4 = param_3[1];

            lVar10 = plVar3[1];

            lVar8 = lVar10 + -1 + (uVar4 - (lVar10 + -1 + uVar4) % uVar4);

            uVar9 = lVar8 + uVar2;

            param_3 = local_res18;

            if (uVar9 <= (ulonglong)(plVar3[2] + lVar10)) {

              if (plVar3 != (longlong *)0x0) {

                local_res18 = (ulonglong *)*plVar3;

                lVar10 = FUN_1401bba40(param_1,local_res18,lVar10,uVar9 - lVar10,lVar8,local_res20,

                                       uVar4);

                *(bool *)(lVar10 + 0x30) = param_6 != 0;

                lVar11 = plVar3[1] + ((plVar3[2] - uVar2) - lVar8);

                FUN_1401bcb70(param_1,plVar3);

                if (lVar11 != 0) {

                  FUN_1401bb850(param_1,local_res18,uVar9,lVar11);

                }

                FUN_140179b60(*(undefined8 *)(param_1 + 0x8c0));

                if (param_6 == 0) {

                  if (param_7 == 0) goto LAB_1401b4d4b;

                  cVar6 = FUN_1401b46e0(param_1,lVar10,lVar8,param_7);

                }

                else {

                  cVar6 = FUN_1401b3710(param_1,lVar10,lVar8,param_6);

                }

                if (cVar6 == '\0') {

                  FUN_1401bcc70(param_1,lVar10);

                  return 0;

                }

LAB_1401b4d4b:

                *param_8 = lVar10;

                return 1;

              }

              break;

            }

          }

        }

        else if (*(longlong *)(*plVar3 + 0x10) != 0x1000000) goto LAB_1401b4bdd;

        plVar12 = plVar12 + -1;

        lVar11 = lVar11 + -1;

      } while (-1 < lVar11);

    }

    if ((*(int *)(param_1 + 0x930) == 0) && (*(char *)(param_1 + 0x920) == '\0')) {

      FUN_1401bb750(param_1);

    }

    uVar9 = 0x1000000;

    param_3 = local_res18;

    if (0x200000 < uVar2) {

      uVar9 = uVar2 + 0x3ffffff & 0xfffffffffc000000;

    }

  }

  cVar6 = FUN_1401b3470(param_1,param_2,uVar9,uVar1 >> 1 & 1,&local_res18);

  puVar5 = local_res18;

  if (cVar6 == '\0') {

    FUN_140179b60(*(undefined8 *)(param_1 + 0x8c0));

    return 2;

  }

  lVar8 = FUN_1401bba40(param_1,local_res18,0,uVar2,0,local_res20,param_3[1]);

  *(bool *)(lVar8 + 0x30) = param_6 != 0;

  lVar10 = *(longlong *)puVar5[5];

  lVar11 = *(longlong *)(lVar10 + 8);

  lVar10 = *(longlong *)(lVar10 + 0x10);

  FUN_1401bcb70(param_1);

  lVar10 = lVar10 - uVar2;

  if (lVar10 != 0) {

    FUN_1401bb850(param_1,puVar5,lVar11 + uVar2,lVar10);

  }

  FUN_140179b60(*(undefined8 *)(param_1 + 0x8c0));

  if (param_6 == 0) {

    if (param_7 == 0) goto LAB_1401b4e21;

    cVar6 = FUN_1401b46e0(param_1,lVar8,0,param_7);

  }

  else {

    cVar6 = FUN_1401b3710(param_1,lVar8,0,param_6);

  }

  if (cVar6 == '\0') {

    FUN_1401bcc70(param_1,lVar8);

    return 0;

  }

LAB_1401b4e21:

  *param_8 = lVar8;

  return 1;

}




