// Address: 0x14020d340
// Ghidra name: FUN_14020d340
// ============ 0x14020d340 FUN_14020d340 (size=195) ============


undefined8 FUN_14020d340(longlong *param_1,undefined8 param_2,undefined8 *param_3)



{

  int iVar1;

  undefined8 uVar2;

  

  if (param_3 == (undefined8 *)0x0) {

    return 0x80070057;

  }

  *param_3 = 0;

  iVar1 = FUN_1401a98e0(param_2,&DAT_140398d48);

  if (iVar1 == 0) {

    iVar1 = FUN_1401a98e0(param_2,&DAT_140398d68);

    if (iVar1 == 0) {

      iVar1 = FUN_1401a98e0(param_2,&DAT_140350558);

      if (iVar1 == 0) {

        iVar1 = FUN_1401a98e0(param_2,&DAT_140398d58);

        uVar2 = 0x80004002;

        if (iVar1 != 0) {

          uVar2 = 0x8007000e;

        }

        return uVar2;

      }

    }

  }

  *param_3 = param_1;

  (**(code **)(*param_1 + 8))(param_1);

  return 0;

}




