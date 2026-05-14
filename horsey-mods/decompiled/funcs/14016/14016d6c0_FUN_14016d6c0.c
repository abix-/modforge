// Address: 0x14016d6c0
// Ghidra name: FUN_14016d6c0
// ============ 0x14016d6c0 FUN_14016d6c0 (size=188) ============


undefined8 FUN_14016d6c0(int param_1,undefined8 *param_2)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  longlong lVar4;

  undefined8 uVar5;

  

  lVar4 = FUN_14016dd00();

  if (lVar4 == 0) {

    return 0;

  }

  if (param_2 != (undefined8 *)0x0) {

    iVar3 = FUN_14016dba0();

    if ((param_1 == iVar3) && (iVar3 = FUN_140169e80(param_2), iVar3 != 0)) {

      return 1;

    }

    lVar1 = DAT_1403fc410;

    if (*(longlong *)(DAT_1403fc410 + 0x30) != 0) {

      *param_2 = 0;

      param_2[1] = 0;

      cVar2 = (**(code **)(lVar1 + 0x30))(lVar1,lVar4,param_2);

      if (cVar2 != '\0') {

        return 1;

      }

    }

    uVar5 = FUN_14016d280(param_1,param_2);

    return uVar5;

  }

  uVar5 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14030db68);

  return uVar5;

}




