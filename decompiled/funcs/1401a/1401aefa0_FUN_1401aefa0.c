// Address: 0x1401aefa0
// Ghidra name: FUN_1401aefa0
// ============ 0x1401aefa0 FUN_1401aefa0 (size=223) ============


void FUN_1401aefa0(longlong param_1,int param_2,longlong param_3,uint param_4)



{

  uint uVar1;

  longlong lVar2;

  longlong lVar3;

  uint *puVar4;

  uint uVar5;

  

  uVar5 = 0;

  if (param_4 != 0) {

    puVar4 = (uint *)(param_3 + 8);

    do {

      lVar3 = **(longlong **)(puVar4 + -2);

      uVar1 = uVar5 + param_2;

      lVar2 = param_1 + (ulonglong)uVar1 * 8;

      if ((*(longlong *)(lVar2 + 0x290) != *(longlong *)(lVar3 + 0x10)) ||

         (*(ulonglong *)(param_1 + 0x310 + (ulonglong)uVar1 * 8) != (ulonglong)*puVar4)) {

        FUN_1401bd730(param_1,lVar3);

        *(undefined8 *)(lVar2 + 0x290) = *(undefined8 *)(lVar3 + 0x10);

        *(ulonglong *)(param_1 + ((ulonglong)uVar1 + 0x62) * 8) = (ulonglong)*puVar4;

        *(undefined1 *)(param_1 + 0x394) = 1;

      }

      uVar5 = uVar5 + 1;

      puVar4 = puVar4 + 4;

    } while (uVar5 < param_4);

  }

  uVar5 = *(uint *)(param_1 + 0x390);

  if (*(uint *)(param_1 + 0x390) <= param_2 + param_4) {

    uVar5 = param_2 + param_4;

  }

  *(uint *)(param_1 + 0x390) = uVar5;

  return;

}




