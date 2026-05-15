// Address: 0x1402cacf4
// Ghidra name: FUN_1402cacf4
// ============ 0x1402cacf4 FUN_1402cacf4 (size=608) ============


void FUN_1402cacf4(int *param_1,undefined8 param_2,undefined8 param_3,longlong param_4,

                  longlong param_5,int param_6,undefined4 param_7,undefined8 param_8)



{

  int iVar1;

  uint uVar2;

  longlong lVar3;

  PVOID pvVar4;

  byte *pbVar5;

  undefined8 in_stack_ffffffffffffff30;

  undefined8 uVar6;

  undefined4 uVar7;

  undefined8 in_stack_ffffffffffffff40;

  undefined4 uVar8;

  longlong local_98;

  undefined8 local_90;

  longlong *local_88;

  undefined8 uStack_80;

  undefined1 local_78 [16];

  int local_68;

  longlong *local_60;

  undefined8 uStack_58;

  uint local_48;

  

  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffff30 >> 0x20);

  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffff40 >> 0x20);

  if (*param_1 != -0x7ffffffd) {

    lVar3 = FUN_1402c97f8();

    if (*(longlong *)(lVar3 + 0x10) != 0) {

      pvVar4 = EncodePointer((PVOID)0x0);

      lVar3 = FUN_1402c97f8();

      if (((*(PVOID *)(lVar3 + 0x10) != pvVar4) && (*param_1 != -0x1fbcb0b3)) &&

         (*param_1 != -0x1fbcbcae)) {

        uVar6 = CONCAT44(uVar7,param_7);

        iVar1 = FUN_1402c82e8(param_1,param_2,param_3,param_4,param_5,uVar6,param_8,

                              CONCAT44(uVar8,param_6));

        uVar7 = (undefined4)((ulonglong)uVar6 >> 0x20);

        if (iVar1 != 0) {

          return;

        }

      }

    }

    local_90 = *(undefined8 *)(param_4 + 8);

    local_98 = param_5;

    if (*(int *)(param_5 + 0xc) == 0) {

                    /* WARNING: Subroutine does not return */

      FUN_1402e1bf8();

    }

    FUN_1402c86f8(&local_60,&local_98,param_6,param_4,param_5,CONCAT44(uVar7,param_7));

    uVar2 = (uint)uStack_58;

    local_88 = local_60;

    uStack_80 = uStack_58;

    if (uVar2 < local_48) {

      do {

        lVar3 = (longlong)*(int *)(*local_88 + 0x10) + (ulonglong)uVar2 * 0x14;

        local_78 = *(undefined1 (*) [16])(lVar3 + local_60[1]);

        local_68 = *(int *)(lVar3 + 0x10 + local_60[1]);

        if ((local_78._0_4_ <= param_6) && (param_6 <= local_78._4_4_)) {

          pbVar5 = (byte *)(*(longlong *)(param_4 + 8) + -0x14 +

                           (longlong)local_68 + (local_78._8_8_ >> 0x20) * 0x14);

          iVar1 = *(int *)(pbVar5 + 4);

          if ((iVar1 != 0) && (lVar3 = FUN_1402c8e50(), lVar3 + iVar1 != 0)) {

            iVar1 = *(int *)(pbVar5 + 4);

            if (iVar1 == 0) {

              lVar3 = 0;

            }

            else {

              lVar3 = FUN_1402c8e50();

              lVar3 = lVar3 + iVar1;

            }

            if (*(char *)(lVar3 + 0x10) != '\0') goto LAB_1402caf1d;

          }

          if ((*pbVar5 & 0x40) == 0) {

            FUN_1402ca114(param_1,param_2,param_3,param_4,param_5,pbVar5,0,local_78,param_7,param_8,

                          1,0);

          }

        }

LAB_1402caf1d:

        uVar2 = uVar2 + 1;

      } while (uVar2 < local_48);

    }

  }

  return;

}




