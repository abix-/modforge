// Address: 0x14020cca0
// Ghidra name: FUN_14020cca0
// ============ 0x14020cca0 FUN_14020cca0 (size=252) ============


undefined8

FUN_14020cca0(longlong param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,uint param_5

             )



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  undefined8 uVar4;

  uint uVar5;

  undefined4 *puVar6;

  

  _guard_check_icall();

  if ((param_1 != 0) && (lVar2 = *(longlong *)(param_1 + 0x148), lVar2 != 0)) {

    if (*(int *)(lVar2 + 0xec) == *(int *)(lVar2 + 0xf0)) {

      iVar1 = *(int *)(lVar2 + 0xf0) + 1;

      lVar3 = FUN_140184230(*(undefined8 *)(lVar2 + 0xf8),(longlong)iVar1 << 5);

      if (lVar3 == 0) {

        return 0;

      }

      *(longlong *)(lVar2 + 0xf8) = lVar3;

      *(int *)(lVar2 + 0xf0) = iVar1;

    }

    puVar6 = (undefined4 *)((longlong)*(int *)(lVar2 + 0xec) * 0x20 + *(longlong *)(lVar2 + 0xf8));

    *(int *)(lVar2 + 0xec) = *(int *)(lVar2 + 0xec) + 1;

    *puVar6 = param_2;

    *(undefined8 *)(puVar6 + 2) = param_3;

    uVar5 = 3;

    if (param_5 < 3) {

      uVar5 = param_5;

    }

    puVar6[7] = uVar5;

    FUN_1402f8e20(puVar6 + 4,param_4,(longlong)(int)uVar5 << 2);

    return 1;

  }

  uVar4 = FUN_14012e850("Invalid joystick");

  return uVar4;

}




