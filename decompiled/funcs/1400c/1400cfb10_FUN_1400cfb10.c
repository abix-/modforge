// Address: 0x1400cfb10
// Ghidra name: FUN_1400cfb10
// ============ 0x1400cfb10 FUN_1400cfb10 (size=642) ============


/* WARNING: Removing unreachable block (ram,0x0001400cfc2a) */



undefined8 FUN_1400cfb10(longlong param_1,longlong *param_2)



{

  ulonglong uVar1;

  longlong *plVar2;

  code *pcVar3;

  char cVar4;

  int iVar5;

  undefined8 *puVar6;

  undefined8 uVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  undefined8 *puVar10;

  longlong lVar11;

  undefined8 local_res8;

  longlong *local_res10;

  undefined8 *local_res18;

  undefined8 *local_58;

  undefined8 *puStack_50;

  undefined8 *local_48;

  

  local_58 = (undefined8 *)0x0;

  puStack_50 = (undefined8 *)0x0;

  local_48 = (undefined8 *)0x0;

  puVar10 = *(undefined8 **)(param_1 + 0x130);

  local_res18 = *(undefined8 **)(param_1 + 0x138);

  local_res10 = param_2;

  if (puVar10 != local_res18) {

    do {

      uVar7 = *puVar10;

      plVar2 = (longlong *)param_2[7];

      local_res8 = uVar7;

      if (plVar2 == (longlong *)0x0) {

        FUN_1402c5c1c();

        pcVar3 = (code *)swi(3);

        uVar7 = (*pcVar3)();

        return uVar7;

      }

      cVar4 = (**(code **)(*plVar2 + 0x10))(plVar2,&local_res8);

      if (cVar4 != '\0') {

        if (puStack_50 == local_48) {

          lVar11 = (longlong)puStack_50 - (longlong)local_58 >> 3;

          if (lVar11 == 0x1fffffffffffffff) {

                    /* WARNING: Subroutine does not return */

            FUN_14002f0d0();

          }

          uVar1 = lVar11 + 1;

          uVar8 = (longlong)local_48 - (longlong)local_58 >> 3;

          if (0x1fffffffffffffff - (uVar8 >> 1) < uVar8) {

            uVar9 = 0x1fffffffffffffff;

          }

          else {

            uVar8 = (uVar8 >> 1) + uVar8;

            uVar9 = uVar1;

            if (uVar1 <= uVar8) {

              uVar9 = uVar8;

            }

            if (0x1fffffffffffffff < uVar9) {

                    /* WARNING: Subroutine does not return */

              FUN_140024090();

            }

          }

          puVar6 = (undefined8 *)FUN_1400285e0(uVar9 * 8);

          puVar6[lVar11] = uVar7;

          FUN_1402f8e20(puVar6,local_58);

          if (local_58 != (undefined8 *)0x0) {

            if ((0xfff < ((longlong)local_48 - (longlong)local_58 & 0xfffffffffffffff8U)) &&

               (0x1f < (ulonglong)((longlong)local_58 + (-8 - local_58[-1])))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          puStack_50 = puVar6 + uVar1;

          local_48 = puVar6 + uVar9;

          param_2 = local_res10;

          local_58 = puVar6;

        }

        else {

          *puStack_50 = uVar7;

          puStack_50 = puStack_50 + 1;

        }

      }

      puVar10 = puVar10 + 1;

    } while (puVar10 != local_res18);

  }

  if (local_58 == puStack_50) {

    uVar7 = 0;

  }

  else {

    iVar5 = FUN_1400c6580((longlong)puStack_50 - (longlong)local_58 >> 3);

    uVar7 = local_58[iVar5];

  }

  if (local_58 != (undefined8 *)0x0) {

    puVar10 = local_58;

    if ((0xfff < ((longlong)local_48 - (longlong)local_58 & 0xfffffffffffffff8U)) &&

       (puVar10 = (undefined8 *)local_58[-1],

       0x1f < (ulonglong)((longlong)local_58 + (-8 - (longlong)puVar10)))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(puVar10);

  }

  plVar2 = (longlong *)param_2[7];

  if (plVar2 != (longlong *)0x0) {

    (**(code **)(*plVar2 + 0x20))(plVar2,plVar2 != param_2);

    param_2[7] = 0;

  }

  return uVar7;

}




