// Address: 0x14002adc0
// Ghidra name: FUN_14002adc0
// ============ 0x14002adc0 FUN_14002adc0 (size=362) ============


void FUN_14002adc0(longlong *param_1,longlong *param_2,undefined8 *param_3)



{

  ulonglong uVar1;

  code *pcVar2;

  undefined *puVar3;

  int iVar4;

  undefined8 *puVar5;

  longlong lVar6;

  longlong lVar7;

  

  iVar4 = *(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2);

  do {

    if (iVar4 != 0) {

      return;

    }

    iVar4 = FUN_14002cac0(param_2);

    if (iVar4 < 1) {

      while( true ) {

        if (param_1 == (longlong *)0x0) {

          return;

        }

        lVar6 = (**(code **)(*param_1 + 0x20))(param_1);

        if (lVar6 != 0) break;

        param_1 = (longlong *)param_1[3];

      }

      lVar6 = (**(code **)(*param_1 + 0x20))(param_1);

      puVar3 = PTR_s_Error_null__0__or_unexpected_EOF_14039a418;

      if (lVar6 == 0) {

        return;

      }

      if (*(char *)(lVar6 + 0x68) != '\0') {

        return;

      }

      lVar7 = -1;

      *(undefined1 *)(lVar6 + 0x68) = 1;

      *(undefined4 *)(lVar6 + 0x6c) = 0xd;

      do {

        lVar7 = lVar7 + 1;

      } while (puVar3[lVar7] != '\0');

      FUN_140027f50(lVar6 + 0x70);

      *(undefined8 *)(lVar6 + 0x94) = 0xffffffffffffffff;

      return;

    }

    uVar1 = param_3[2];

    if (uVar1 < (ulonglong)param_3[3]) {

      param_3[2] = uVar1 + 1;

      puVar5 = param_3;

      if (0xf < (ulonglong)param_3[3]) {

        puVar5 = (undefined8 *)*param_3;

      }

      *(char *)((longlong)puVar5 + uVar1) = (char)iVar4;

      *(undefined1 *)((longlong)puVar5 + uVar1 + 1) = 0;

    }

    else {

      FUN_1400280d0(param_3);

    }

    if (iVar4 == 0x3e) {

      uVar1 = param_3[2];

      if (uVar1 <= uVar1 - 2) {

LAB_14002af24:

        FUN_14002cca0();

        pcVar2 = (code *)swi(3);

        (*pcVar2)();

        return;

      }

      puVar5 = param_3;

      if (0xf < (ulonglong)param_3[3]) {

        puVar5 = (undefined8 *)*param_3;

      }

      if (*(char *)((longlong)puVar5 + (uVar1 - 2)) == '-') {

        if (uVar1 <= uVar1 - 3) goto LAB_14002af24;

        puVar5 = param_3;

        if (0xf < (ulonglong)param_3[3]) {

          puVar5 = (undefined8 *)*param_3;

        }

        if (*(char *)((longlong)puVar5 + (uVar1 - 3)) == '-') {

          return;

        }

      }

    }

    iVar4 = *(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2);

  } while( true );

}




