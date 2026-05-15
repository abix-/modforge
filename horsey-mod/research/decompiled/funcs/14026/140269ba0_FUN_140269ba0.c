// Address: 0x140269ba0
// Ghidra name: FUN_140269ba0
// ============ 0x140269ba0 FUN_140269ba0 (size=143) ============


undefined1 FUN_140269ba0(longlong param_1)



{

  uint uVar1;

  longlong lVar2;

  ulonglong uVar3;

  undefined1 uVar4;

  

  lVar2 = *(longlong *)(param_1 + 0x88);

  uVar3 = FUN_140149350();

  if (lVar2 + 0x1eU <= uVar3) {

    if (*(char *)(param_1 + 0x90) != '\0') {

      uVar1 = *(uint *)(param_1 + 0x94);

      *(undefined1 *)(param_1 + 0x90) = 0;

      *(undefined4 *)(param_1 + 0x94) = 0;

      uVar4 = FUN_140269ac0(param_1,uVar1 >> 0x10);

      return uVar4;

    }

    if (*(char *)(param_1 + 0x91) != '\0') {

      *(undefined1 *)(param_1 + 0x91) = 0;

      uVar4 = FUN_140269ac0(param_1,0,0);

      return uVar4;

    }

  }

  return 1;

}




