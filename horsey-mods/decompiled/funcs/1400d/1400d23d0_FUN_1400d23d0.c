// Address: 0x1400d23d0
// Ghidra name: FUN_1400d23d0
// ============ 0x1400d23d0 FUN_1400d23d0 (size=873) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400d23d0(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 *puVar3;

  bool bVar4;

  bool bVar5;

  char cVar6;

  undefined8 uVar7;

  longlong lVar8;

  longlong lVar9;

  undefined8 uVar10;

  longlong lVar11;

  int iVar12;

  int local_res18;

  ulonglong in_stack_ffffffffffffff68;

  longlong local_88;

  undefined1 local_80 [8];

  longlong local_78;

  undefined8 local_70;

  undefined8 uStack_68;

  undefined8 local_60;

  ulonglong uStack_58;

  

  bVar4 = false;

  bVar5 = false;

  local_res18 = 0;

  lVar8 = *(longlong *)(param_1 + 0xb8);

  if (*(longlong *)(param_1 + 0xc0) - lVar8 >> 3 != 0) {

    local_88 = 0;

    do {

      lVar1 = *(longlong *)(lVar8 + local_88);

      if (((*(int *)(lVar1 + 8) == 3) && (*(char *)(lVar1 + 0x10) != '\0')) &&

         ((*(int *)(lVar1 + 0xc) == 1 || (*(int *)(lVar1 + 0xc) == 7)))) {

        if (((ulonglong)(*(longlong *)(param_1 + 0x80) - *(longlong *)(param_1 + 0x78) >> 4) < 4) ||

           (cVar6 = FUN_1400c56f0(*(undefined4 *)(lVar1 + 0x28),lVar8,

                                  *(longlong *)(param_1 + 0x78) + 0x30,0), cVar6 == '\0')) {

          cVar6 = FUN_1400c56f0(*(undefined4 *)(lVar1 + 0x28));

          bVar4 = bVar5;

          if (cVar6 == '\0') goto LAB_1400d263f;

          lVar8 = 0;

        }

        else {

          lVar8 = 3;

        }

        uVar10 = 0;

        if (*(int *)(lVar1 + 0xc) == 7) {

          uVar10 = 0x32;

        }

        iVar12 = 0;

        lVar9 = *(longlong *)(param_1 + 0x130);

        if (*(longlong *)(param_1 + 0x138) - lVar9 >> 3 != 0) {

          lVar11 = 0;

          do {

            if (*(int *)(lVar1 + 0x44) < 1) break;

            lVar9 = *(longlong *)(lVar11 + lVar9);

            if (*(char *)(lVar9 + 0x205) != '\0') {

              lVar2 = *(longlong *)(param_1 + 0x78);

              uVar7 = FUN_1400b4a10(lVar9,local_80);

              cVar6 = FUN_1400c5740(uVar7,lVar2 + lVar8 * 0x10,0);

              bVar4 = bVar5;

              if ((cVar6 != '\0') && (cVar6 = FUN_1400b56d0(lVar9,uVar10), cVar6 != '\0')) {

                local_78 = FUN_1402c704c(0x80);

                uVar7 = 0;

                if (local_78 != 0) {

                  uVar7 = FUN_14005c9b0(local_78,uVar10);

                }

                FUN_1400b85b0(lVar9,uVar7);

                *(int *)(lVar1 + 0x44) = *(int *)(lVar1 + 0x44) + -10;

                bVar5 = true;

                bVar4 = true;

              }

            }

            iVar12 = iVar12 + 1;

            lVar11 = lVar11 + 8;

            lVar9 = *(longlong *)(param_1 + 0x130);

          } while ((ulonglong)(longlong)iVar12 <

                   (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar9 >> 3));

        }

        if (*(int *)(lVar1 + 0x44) < 1) {

          puVar3 = *(undefined8 **)(local_88 + *(longlong *)(param_1 + 0xb8));

          if (puVar3 != (undefined8 *)0x0) {

            (**(code **)*puVar3)(puVar3,1);

          }

          FUN_1402f8e20();

          *(longlong *)(param_1 + 0xc0) = *(longlong *)(param_1 + 0xc0) + -8;

          local_res18 = local_res18 + -1;

          local_88 = local_88 + -8;

        }

      }

LAB_1400d263f:

      local_res18 = local_res18 + 1;

      local_88 = local_88 + 8;

      lVar8 = *(longlong *)(param_1 + 0xb8);

    } while ((ulonglong)(longlong)local_res18 <

             (ulonglong)(*(longlong *)(param_1 + 0xc0) - lVar8 >> 3));

    if (bVar4) {

      uStack_68 = 0;

      local_60 = _DAT_140304080;

      uStack_58 = _UNK_140304088;

      local_70 = (ulonglong)CONCAT14(s_Chomp_14030ea2c[4],s_Chomp_14030ea2c._0_4_);

      FUN_140040ca0(&local_70,100,0,DAT_14039ca44,in_stack_ffffffffffffff68 & 0xffffffffffffff00);

      if (0xf < uStack_58) {

        if ((0xfff < uStack_58 + 1) && (0x1f < (local_70 - *(longlong *)(local_70 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

    }

  }

  return;

}




