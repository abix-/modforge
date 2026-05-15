// Address: 0x14022d5a0
// Ghidra name: FUN_14022d5a0
// ============ 0x14022d5a0 FUN_14022d5a0 (size=122) ============


undefined8 FUN_14022d5a0(longlong param_1)



{

  longlong lVar1;

  char cVar2;

  uint uVar3;

  uint uVar4;

  

  lVar1 = *(longlong *)(param_1 + 0x680);

  uVar4 = (uint)(*(char *)(lVar1 + 0x128) != '\0');

  if (*(char *)(lVar1 + 0x129) != '\0') {

    uVar3 = 6;

    if (*(char *)(lVar1 + 0x12a) == '\0') {

      uVar3 = 2;

    }

    uVar4 = uVar4 | uVar3;

    if (*(char *)(lVar1 + 299) != '\0') {

      uVar4 = uVar4 | 8;

    }

  }

  if (uVar4 != *(uint *)(lVar1 + 0x130)) {

    cVar2 = FUN_14022d320(param_1,uVar4);

    if (cVar2 == '\0') {

      return 0;

    }

    *(uint *)(lVar1 + 0x130) = uVar4;

  }

  return 1;

}




