// Address: 0x1401e45b0
// Ghidra name: FUN_1401e45b0
// ============ 0x1401e45b0 FUN_1401e45b0 (size=290) ============


void FUN_1401e45b0(longlong param_1,uint *param_2)



{

  longlong lVar1;

  longlong lVar2;

  longlong *plVar3;

  uint uVar4;

  

  lVar1 = *(longlong *)(param_2 + 0x4e);

  if (lVar1 != 0) {

    if ((*(char *)(lVar1 + 0x38) != '\0') || (*(char *)(lVar1 + 0x60) != '\0')) {

      uVar4 = *param_2;

      if ((uVar4 == 0) || ((uVar4 & 0xf0000000) == 0x10000000)) {

        uVar4 = uVar4 & 0xff;

      }

      else if ((((uVar4 == 0x32595559) || (uVar4 == 0x59565955)) || (uVar4 == 0x55595659)) ||

              (uVar4 == 0x30313050)) {

        uVar4 = 2;

      }

      else {

        uVar4 = 1;

      }

      FUN_1401e47b0(param_1,param_2,(int *)(lVar1 + 0x7c),

                    (longlong)(*(int *)(lVar1 + 0x78) * *(int *)(lVar1 + 0x80)) +

                    (longlong)(int)(uVar4 * *(int *)(lVar1 + 0x7c)) + *(longlong *)(lVar1 + 0x70),

                    *(int *)(lVar1 + 0x78));

      return;

    }

    lVar2 = *(longlong *)(param_1 + 0x2e0);

    plVar3 = *(longlong **)(lVar2 + 0x28);

    (**(code **)(*plVar3 + 0x78))(plVar3,*(undefined8 *)(lVar1 + 0x20),0);

    plVar3 = *(longlong **)(lVar2 + 0x28);

    (**(code **)(*plVar3 + 0x170))

              (plVar3,*(undefined8 *)(lVar1 + 8),0,*(undefined4 *)(lVar1 + 0x28),

               *(undefined4 *)(lVar1 + 0x2c),0,*(undefined8 *)(lVar1 + 0x20),0,0);

    if (*(longlong **)(lVar1 + 0x20) != (longlong *)0x0) {

      (**(code **)(**(longlong **)(lVar1 + 0x20) + 0x10))();

      *(undefined8 *)(lVar1 + 0x20) = 0;

    }

  }

  return;

}




