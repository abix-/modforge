// Address: 0x1401f9dc0
// Ghidra name: FUN_1401f9dc0
// ============ 0x1401f9dc0 FUN_1401f9dc0 (size=176) ============


void FUN_1401f9dc0(longlong param_1)



{

  longlong lVar1;

  undefined8 uVar2;

  ulonglong uVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  

  if (*(longlong *)(param_1 + 0x698) == 0) {

    *(undefined8 *)(param_1 + 0x698) =

         *(undefined8 *)(*(longlong *)(param_1 + 0x688) + (ulonglong)*(uint *)(param_1 + 0x690) * 8)

    ;

    FUN_1401fdd80();

    uVar3 = (ulonglong)*(uint *)(param_1 + 0x28c8);

    lVar1 = *(longlong *)(param_1 + 0x28a8);

    if (*(int *)(lVar1 + uVar3 * 4) == 0) {

      uVar5 = 1;

      uVar2 = *(undefined8 *)(*(longlong *)(param_1 + 0x2898) + uVar3 * 8);

      uVar4 = 0;

    }

    else {

      if (*(int *)(lVar1 + (ulonglong)*(uint *)(param_1 + 0x690) * 4) == 2) {

        return;

      }

      uVar5 = 0x400;

      uVar2 = *(undefined8 *)(*(longlong *)(param_1 + 0x2898) + uVar3 * 8);

      uVar4 = 0x80;

    }

    FUN_1401fd560(param_1,uVar4,0x180,uVar5,0x400,2,uVar2,lVar1 + uVar3 * 4);

  }

  return;

}




