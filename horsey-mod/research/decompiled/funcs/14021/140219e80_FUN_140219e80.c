// Address: 0x140219e80
// Ghidra name: FUN_140219e80
// ============ 0x140219e80 FUN_140219e80 (size=252) ============


undefined8 FUN_140219e80(longlong param_1,longlong param_2,longlong param_3)



{

  longlong lVar1;

  int iVar2;

  undefined4 uVar3;

  undefined8 uVar4;

  

  lVar1 = *(longlong *)(param_1 + 0x690);

  if (lVar1 != 0) {

    if (*(longlong *)(lVar1 + 0x90) == 0) {

      if ((param_2 != 0) || (param_3 != 0)) goto LAB_140219ebc;

    }

    else {

      if (*(code **)(lVar1 + 200) != (code *)0x0) {

        (**(code **)(lVar1 + 200))(*(undefined4 *)(lVar1 + 0x38));

      }

      if ((param_3 == 0) || ((param_2 == 0 && (*(char *)(param_1 + 0x558) == '\0')))) {

        (**(code **)(*(longlong *)(param_1 + 0x690) + 0x90))

                  (*(undefined8 *)(*(longlong *)(param_1 + 0x690) + 0x10),0,0,0);

      }

      else {

        iVar2 = (**(code **)(*(longlong *)(param_1 + 0x690) + 0x90))

                          (*(undefined8 *)(*(longlong *)(param_1 + 0x690) + 0x10),param_2,param_2,

                           param_3);

        if (iVar2 == 0) {

          uVar3 = (**(code **)(*(longlong *)(param_1 + 0x690) + 0xd0))();

          uVar4 = FUN_14021a490("Unable to make EGL context current","eglMakeCurrent",uVar3);

          return uVar4;

        }

      }

    }

    return 1;

  }

LAB_140219ebc:

  uVar4 = FUN_14012e850("EGL not initialized");

  return uVar4;

}




