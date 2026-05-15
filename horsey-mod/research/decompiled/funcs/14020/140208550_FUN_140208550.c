// Address: 0x140208550
// Ghidra name: FUN_140208550
// ============ 0x140208550 FUN_140208550 (size=363) ============


void FUN_140208550(longlong param_1,undefined1 *param_2)



{

  undefined8 uVar1;

  char cVar2;

  longlong lVar3;

  undefined8 uVar4;

  int iVar5;

  longlong *plVar6;

  

  *param_2 = 0;

  if (*(longlong *)(param_1 + 0x68) == 0) {

    lVar3 = FUN_140207b60();

    if (lVar3 != 0) {

      if (*(int *)(param_1 + 0xa8) == 0) {

        FUN_1401492f0(10);

        lVar3 = FUN_140193730(*(undefined8 *)(param_1 + 0x18));

        if (lVar3 == 0) {

          uVar1 = *(undefined8 *)(param_1 + 0x18);

          uVar4 = FUN_14012e730();

          FUN_14012e080(7,"HIDAPI_SetupDeviceDriver() couldn\'t open %s: %s",uVar1,uVar4);

          return;

        }

        FUN_140193900(lVar3,1);

        *(longlong *)(param_1 + 0x80) = lVar3;

      }

      lVar3 = FUN_140207b60(param_1);

      *(longlong *)(param_1 + 0x68) = lVar3;

      if ((lVar3 != 0) && (cVar2 = (**(code **)(lVar3 + 0x30))(param_1), cVar2 == '\0')) {

        FUN_140207340(param_1);

      }

      if ((*(longlong *)(param_1 + 0x68) == 0) && (*(longlong *)(param_1 + 0x80) != 0)) {

        FUN_140192f70();

        *(undefined8 *)(param_1 + 0x80) = 0;

      }

    }

  }

  else {

    if ((*(short *)(param_1 + 0x20) != 0x57e) ||

       ((cVar2 = DAT_1403e4e10, *(short *)(param_1 + 0x22) != 0x2008 &&

        (*(short *)(param_1 + 0x22) != 0x2068)))) {

      cVar2 = *(char *)(*(longlong *)(param_1 + 0x68) + 8);

    }

    plVar6 = *(longlong **)(param_1 + 0xb0);

    if (plVar6 != (longlong *)0x0) {

      iVar5 = 0;

      if (0 < *(int *)(param_1 + 0xa8)) {

        do {

          if ((*(longlong *)(*plVar6 + 0x68) == 0) ||

             (*(char *)(*(longlong *)(*plVar6 + 0x68) + 8) == '\0')) goto LAB_1402085e7;

          iVar5 = iVar5 + 1;

          plVar6 = plVar6 + 1;

        } while (iVar5 < *(int *)(param_1 + 0xa8));

      }

    }

    if (cVar2 == '\0') {

LAB_1402085e7:

      FUN_140207340(param_1);

      return;

    }

  }

  return;

}




