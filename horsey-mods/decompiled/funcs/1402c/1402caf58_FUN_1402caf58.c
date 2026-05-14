// Address: 0x1402caf58
// Ghidra name: FUN_1402caf58
// ============ 0x1402caf58 FUN_1402caf58 (size=773) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



void FUN_1402caf58(int *param_1,undefined8 param_2,undefined8 param_3,longlong param_4,

                  undefined8 param_5,int param_6,undefined4 param_7,undefined8 param_8)



{

  byte bVar1;

  char cVar2;

  uint uVar3;

  int iVar4;

  longlong lVar5;

  PVOID pvVar6;

  longlong lVar7;

  byte *pbVar8;

  byte *pbVar9;

  ulonglong uVar10;

  byte *pbVar11;

  undefined1 auStack_178 [32];

  undefined8 local_158;

  undefined1 *local_150;

  undefined8 local_148;

  undefined8 *local_140;

  undefined4 local_138;

  undefined8 local_130;

  undefined1 local_128;

  undefined1 local_120;

  uint local_118;

  undefined8 local_110;

  undefined8 local_108;

  undefined8 local_100;

  undefined8 uStack_f8;

  undefined8 local_f0;

  longlong local_e8;

  uint uStack_e0;

  uint local_d0;

  int local_c8 [2];

  undefined8 local_c0;

  undefined8 local_b8;

  undefined1 local_b0 [4];

  byte local_ac;

  int local_a8;

  int local_78 [10];

  ulonglong local_50;

  

  local_50 = DAT_1403e8b00 ^ (ulonglong)auStack_178;

  local_110 = param_8;

  if (*param_1 != -0x7ffffffd) {

    local_108 = param_3;

    local_f0 = param_2;

    lVar5 = FUN_1402c97f8();

    if (*(longlong *)(lVar5 + 0x10) != 0) {

      pvVar6 = EncodePointer((PVOID)0x0);

      lVar5 = FUN_1402c97f8();

      if (((*(PVOID *)(lVar5 + 0x10) != pvVar6) && (*param_1 != -0x1fbcb0b3)) &&

         (*param_1 != -0x1fbcbcae)) {

        local_140 = (undefined8 *)CONCAT44(local_140._4_4_,param_6);

        local_148 = local_110;

        local_150 = (undefined1 *)CONCAT44(local_150._4_4_,param_7);

        local_158 = param_5;

        iVar4 = FUN_1402c833c(param_1,param_2,local_108,param_4);

        if (iVar4 != 0) {

          return;

        }

      }

    }

    FUN_1402cba94(local_78,param_5,*(undefined8 *)(param_4 + 8));

    if (local_78[0] == 0) {

                    /* WARNING: Subroutine does not return */

      FUN_1402e1bf8();

    }

    local_150 = (undefined1 *)CONCAT44(local_150._4_4_,param_7);

    local_158 = param_5;

    FUN_1402c8830(&local_e8,local_78,param_6,param_4);

    local_118 = uStack_e0;

    if (uStack_e0 < local_d0) {

      do {

        local_100 = *(undefined8 *)(local_e8 + 0x18);

        uStack_f8 = *(undefined8 *)(local_e8 + 0x20);

        if ((*(int *)(local_e8 + 0x18) <= param_6) && (param_6 <= *(int *)(local_e8 + 0x1c))) {

          FUN_1402cba10(local_c8,&local_100,*(undefined8 *)(param_4 + 8),

                        **(undefined4 **)(param_4 + 0x10));

          local_c0 = local_b8;

          FH4::HandlerMap4::DecompHandler((HandlerMap4 *)local_c8);

          iVar4 = local_c8[0];

          local_c0 = local_b8;

          FH4::HandlerMap4::DecompHandler((HandlerMap4 *)local_c8);

          uVar10 = (ulonglong)(iVar4 - 1U);

          if (iVar4 - 1U != 0) {

            do {

              FH4::HandlerMap4::DecompHandler((HandlerMap4 *)local_c8);

              uVar10 = uVar10 - 1;

            } while (uVar10 != 0);

          }

          lVar5 = (longlong)local_a8;

          if ((local_a8 != 0) && (lVar7 = FUN_1402c8e50(), lVar7 + lVar5 != 0)) {

            lVar5 = (longlong)local_a8;

            if (local_a8 == 0) {

              lVar7 = 0;

            }

            else {

              lVar7 = FUN_1402c8e50();

              lVar7 = lVar7 + lVar5;

            }

            if (*(char *)(lVar7 + 0x10) != '\0') goto LAB_1402cb18c;

          }

          if ((local_ac & 0x40) == 0) {

            local_120 = 0;

            local_128 = 1;

            local_130 = local_110;

            local_140 = &local_100;

            local_138 = param_7;

            local_150 = local_b0;

            local_148 = 0;

            local_158 = param_5;

            FUN_1402ca1ec(param_1,local_f0,local_108,param_4);

          }

        }

LAB_1402cb18c:

        pbVar11 = *(byte **)(local_e8 + 8);

        lVar5 = (longlong)(char)(&DAT_1403872c0)[*pbVar11 & 0xf];

        bVar1 = (&DAT_1403872d0)[*pbVar11 & 0xf];

        pbVar8 = pbVar11 + -lVar5;

        uVar3 = *(uint *)(pbVar8 + -4);

        *(byte **)(local_e8 + 8) = pbVar8;

        *(uint *)(local_e8 + 0x18) = uVar3 >> (bVar1 & 0x1f);

        cVar2 = (&DAT_1403872c0)[*pbVar8 & 0xf];

        pbVar9 = pbVar11 + (-lVar5 - (longlong)cVar2);

        *(uint *)(local_e8 + 0x1c) =

             *(uint *)(pbVar9 + -4) >> ((&DAT_1403872d0)[*pbVar8 & 0xf] & 0x1f);

        *(byte **)(local_e8 + 8) = pbVar9;

        pbVar11 = pbVar11 + ((-(longlong)cVar2 - (longlong)(char)(&DAT_1403872c0)[*pbVar9 & 0xf]) -

                            lVar5);

        *(uint *)(local_e8 + 0x20) =

             *(uint *)(pbVar11 + -4) >> ((&DAT_1403872d0)[*pbVar9 & 0xf] & 0x1f);

        *(byte **)(local_e8 + 8) = pbVar11;

        *(undefined4 *)(local_e8 + 0x24) = *(undefined4 *)pbVar11;

        local_118 = local_118 + 1;

        *(byte **)(local_e8 + 8) = pbVar11 + 4;

      } while (local_118 < local_d0);

    }

  }

  return;

}




