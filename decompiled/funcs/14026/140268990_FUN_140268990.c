// Address: 0x140268990
// Ghidra name: FUN_140268990
// ============ 0x140268990 FUN_140268990 (size=279) ============


undefined1 FUN_140268990(longlong param_1,undefined8 param_2,short param_3,short param_4)



{

  longlong lVar1;

  longlong lVar2;

  undefined1 uVar3;

  char cVar4;

  ulonglong uVar5;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  if (*(char *)(lVar1 + 0x10) != '\0') {

    uVar3 = FUN_14012e850("That operation is not supported");

    return uVar3;

  }

  if (*(longlong *)(param_1 + 0xa0) != 0) {

    if (*(int *)(lVar1 + 0x20) == 1) {

      param_4 = 0;

    }

    else if (*(int *)(lVar1 + 0x20) == 2) {

      param_3 = 0;

    }

  }

  if (*(char *)(lVar1 + 0x90) != '\0') {

    cVar4 = FUN_140269ba0(lVar1);

    if (cVar4 == '\0') {

      return 0;

    }

  }

  lVar2 = *(longlong *)(lVar1 + 0x88);

  uVar5 = FUN_140149350();

  if (uVar5 < lVar2 + 0x1eU) {

    if ((param_3 == 0) && (param_4 == 0)) {

      *(undefined1 *)(lVar1 + 0x91) = 1;

      return 1;

    }

    if (*(uint *)(lVar1 + 0x94) < CONCAT22(param_3,param_4)) {

      *(uint *)(lVar1 + 0x94) = CONCAT22(param_3,param_4);

    }

    *(undefined1 *)(lVar1 + 0x90) = 1;

    *(undefined1 *)(lVar1 + 0x91) = 0;

    return 1;

  }

  uVar3 = FUN_140269ac0(lVar1,param_3,param_4);

  return uVar3;

}




